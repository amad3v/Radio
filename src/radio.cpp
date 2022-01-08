#include "radio.h"

Radio::Radio(
    uint16_t ce,
    uint16_t cs,
    uint16_t addr,
    uint16_t targetAddr,
    uint32_t spiSpeed) :
    nrf24(ce, cs, spiSpeed),
    network(nrf24),
    address(addr),
    target(targetAddr) {}

void Radio::begin(uint8_t networkChannel) {
    if (!nrf24.begin()) {
        Serial.println(("Radio hardware not responding!"));
        while (true) {
            /* hold in infinite loop */
        }
    }
    network.begin(/*channel*/ networkChannel, /*node address*/ address);
}

void Radio::receive(void* payload, uint16_t szPayload) {
    // Check the network regularly
    network.update();

    // TODO: try if instead of while and see if it works
    // Is there anything ready for us?
    if (network.available()) {
        RF24NetworkHeader header;
        // If so, grab it and assign it
        network.read(header, payload, szPayload);
    }
}

// bool Radio::receive(Payload& payload, uint16_t szPayload) {
//     uint16_t received {};
//     // Check the network regularly
//     network.update();

//     // TODO: try if instead of while and see if it works
//     // Is there anything ready for us?
//     while (network.available()) {
//         RF24NetworkHeader header;
//         // If so, grab it and assign it
//         received = network.read(header, &payload, szPayload);
//     }

//     return received == szPayload;
// }

bool Radio::send(const Payload& payload, uint16_t szPayload) {
    // Check the network regularly
    network.update();

    RF24NetworkHeader header(/*to node*/ target);

    return network.write(header, &payload, szPayload);
}

bool Radio::setTargetAddr(uint16_t address_) {
    if (address_ != address) {
        target = address_;
        return true;
    }

    return false;
}