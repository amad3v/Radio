# Radio

Handles all operations related to the nRF24L01(+) and its network.

[nRF24L01P datasheet](https://www.farnell.com/datasheets/2577975.pdf) or [here](https://www.farnell.com/datasheets/2577975.pdf),

Used libraries:

- [nRF24](https://github.com/nRF24/RF24) Library
- [nRF24 Network](https://github.com/nRF24/RF24Network) Library.

## Class Radio

### Constructor:

```c++
Radio(
        // Chip Enable pin.
        uint16_t ce = DEFAULT_CE_PIN,
        // Chip Select pin.
        uint16_t cs = DEFAULT_CS_PIN,
        // Address of the radio in the network.
        uint16_t addr = NETWORK_ADDR::NA_LOCAL,
        // Address of the target radio
        uint16_t targetAddr = NETWORK_ADDR::NA_REMOTE,
        // Speed used to communicate via SPI
        uint32_t spiSpeed = SPI_CHIP_SPEED
    );
```

### Member functions:

Begin operation of the SPI, nRF24L01(+)

```c++
void begin(uint8_t networkChannel = DEFAULT_NETWORK_CHANNEL);
```

Receive data sent from nodes.

```c++
void receive(void* payload, uint16_t szPayload);
```

Sends payload through the network.

```c++
bool send(const void *payload, uint16_t szPayload);
```

Set the Target's address.

```c++
bool setTargetAddr(uint16_t addr);
```
