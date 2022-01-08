/**
 * @file radio.h
 * @date 28.12.21
 * @author amad3v (amad3v@gmail.com)
 * @version 1.0.0
 *
 * @brief Class to configure and control nRF24L01(+)
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __RADIO_NRF24__
#define __RADIO_NRF24__

#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include "radio_def.h"

/**
 * @class Radio
 * @brief Handle all operations related to the nRF24L01(+) and its network.
 * @see [nRF24L01P](https://www.farnell.com/datasheets/2577975.pdf) or
 * [nRF24L01P](https://www.farnell.com/datasheets/2577975.pdf),
 * [nRF24](https://github.com/nRF24/RF24) Library, [nRF24
 * Network](https://github.com/nRF24/RF24Network) Library.
 */
class Radio {
  public:
    /**
     * @brief Construct a new Radio object.
     *
     * @param ce Chip Enable pin, defaults to #CE_PIN
     * @param cs Chip Select pin, defaults to #CS_PIN
     * @param addr Address of the radio in the network, defaults to
     * #NETWORK_ADDR::NA_LOCAL
     * @param targetAddr Address of the target radion in the network,
     * defaults to #NETWORK_ADDR::NA_REMOTE
     * @param spiSpeed Speed used to communicate with SPI.
     */
    Radio(
        uint16_t ce = DEFAULT_CE_PIN,
        uint16_t cs = DEFAULT_CS_PIN,
        uint16_t addr = NETWORK_ADDR::NA_LOCAL,
        uint16_t targetAddr = NETWORK_ADDR::NA_REMOTE,
        uint32_t spiSpeed = SPI_CHIP_SPEED);

    /**
     * @brief Begin operation of the SPI, nRF24L01(+)
     * and bring up the network on a specific radio frequency/channel.
     */
    void begin(uint8_t networkChannel = DEFAULT_NETWORK_CHANNEL);

    /**
     * @brief Receive data sent from nodes.
     *
     * @param payload Pointer to where the data will be stored.
     * @param szPayload Size of the @p payload.
     */
    void receive(void* payload, uint16_t szPayload);

    /**
     * @brief Sends payload through the network
     *
     * @param payload Data to send.
     * @param szPayload Size of the data.
     * @return Whether the message was successfully received
     */
    bool send(const void *payload, uint16_t szPayload);

    /**
     * @brief Set the Target's address.
     *
     * @param addr New address.
     * @return true if address is valid
     * @return false if address is invalid
     */
    bool setTargetAddr(uint16_t addr);

  private:
    /**
     * @brief nRF24L01(+) driver.
     */
    RF24 nrf24;

    /**
     * @brief nRF24L01(+) network driver.
     */
    RF24Network network;

    /**
     * @brief Holds the node's address.
     */
    uint16_t address {};

    /**
     * @brief Target address.
     */
    uint16_t target {};
};

#endif /* __RADIO_NRF24__ */
