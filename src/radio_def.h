/**
 * @file radio_def.h
 * @date 28.12.21
 * @author amad3v (amad3v@gmail.com)
 * @version 0.0.1
 *
 * @brief Constants and data structures for the Radio class.
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __NRF24__RADIO_DEF_H__
#define __NRF24__RADIO_DEF_H__

#include <Arduino.h>

/**
 * @brief Use 4MHz instead of default 10MHz  due to
 * faulty SPI connection on the BLE.
 * @see Issue #189 [Nano 33 family not working
 * properly](https://github.com/nRF24/RF24Network/issues/189).
 */
const uint32_t SPI_CHIP_SPEED = 4000000;

/**
 * @brief Network channel to communicate, must be the same on all nodes.
 */
const uint8_t DEFAULT_NETWORK_CHANNEL = 0x64;

/**
 * @brief Default Chip Enable pin connected to the nRF24L01.
 */
const uint16_t DEFAULT_CE_PIN = 0x09;

/**
 * @brief Default Chip Select pin connected to the nRF24L01.
 */
const uint16_t DEFAULT_CS_PIN = 0x0A;

/**
 * @brief Network addresses.
 */
enum NETWORK_ADDR : uint16_t {
    /**
     * @brief Address of the local node in Octal format (acts as receiver).
     */
    NA_LOCAL = 000,
    /**
     * @brief Address of the remote node in Octal format (acts as transmitter).
     */
    NA_REMOTE = 001,
};

#endif /* __NRF24__RADIO_DEF_H__ */
