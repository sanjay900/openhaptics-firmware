# OpenHaptics Firmware

This project intended to let people build their own DIY haptic-feedback devices. Integrates to all existing games, that work with bHaptics

[![Discord](https://img.shields.io/discord/966090258104062023?label=Discord&logo=discord)](https://discord.gg/YUtRKAqty2)
[![Developer's Twitter](https://img.shields.io/twitter/follow/leon0399?color=%231DA1F2&label=Developer%27s%20Twitter&logo=twitter)](https://twitter.com/leon0399)

[![GPL-3.0](https://img.shields.io/github/license/openhaptics/openhaptics-firmware)](/LICENSE)
[![GitHub contributors](https://img.shields.io/github/contributors/openhaptics/openhaptics-firmware)](https://github.com/openhaptics/openhaptics-firmware/graphs/contributors)

## Configuration, flashing and connecting

* [Firmware Documentation](/docs)
* [Hardware Documentation](https://github.com/openhaptics/openhaptics-hardware)

Please note, that documentation is still work-in-progress

## Supported Hardware

### MCU

| Board                | Status       |
| :------------------- | :----------: |
| ESP32-WROOM-32       | ✅            |
| ESP32-WROVER         | ✅            |
| ESP32-C3             | ❌            |
| ESP32-S3             | ❌            |

### PWM Drivers

| Board                | Status       | Max outputs per board |
| :------------------- | :----------: | ---------------------: |
| Internal PWM         | ✅            |                    16 |
| PCA9685              | ✅            |                    16 |
| PCA9634              | 🚧            |                     8 |
| PCA9531              | 🚧            |                     8 |
| PCA9635              | 🚧            |                    16 |
| SN3218               | 🚧            |                    18 |
| MP3326               | 🚧            |                    16 |
| TLC59108F            | 🚧            |                     8 |
| LP50xx               | 🚧            |             9 _or_ 12 |

### Battery controllers

| Board                | Status       |
| :------------------- | :----------: |
| Internal ADC         | 🚧            |
| MAX1704x             | 🚧            |
| MCP3021              | 🚧            |

## Supported Protocols

| Protocol             | Status                                                              |
| :------------------- | :-----------------------------------------------------------------: |
| bHaptics Bluetooth   | ✅ (Android/Windows/Quest)                                           |
| OpenHaptics          | [RFC](https://github.com/openhaptics/openhaptics-firmware/issues/9) |

## Supported devices

| Device              | Retail price | Required Pins                                                                                          |
| :------------------ | -----------: | :------------------------------------------------------------------------------------------------------|
| Tactal              |  US $149     | PWM on pins `32`, `33`, `25`, `26`, `27`, `14`                                                         |
| TactGlove (L and R) | (?) US $299  | PWM on pins `32`, `33`, `25`, `26`, `27`, `14`                                                         |
| Tactosy for arms    | US $249      | PWM on pins `32`, `33`, `25`, `26`, `27`, `14`                                                         |
| Tactosy for hands   | US $249      | PWM on pins `32`, `33`, `25`                                                                           |
| Tactosy for feet    | US $249      | PWM on pins `32`, `33`, `25`                                                                           |
| X16 Haptic Vest     | US $299      | See [Hardware Reference](https://github.com/openhaptics/openhaptics-hardware#x16-haptic-vest)          |
| X40 Haptic Vest     | US $499      | 2x PCA9685 (on address `0x40` and `0x41`) + PWM on pins `32`, `33`, `25`, `26`, `27`, `14`, `12`, `13` |
