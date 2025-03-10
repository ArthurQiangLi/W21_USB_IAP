# W21_USB_IAP

This project demonstrates how to use a USB drive to flash firmware onto an STM32F4-Discovery board. Additionally, you can modify it to suit your application as a reference for updating firmware and/or configuration when **OTA** updates are not possible.

## Test Environment

| Hardware       | stm32f4-discovery |
|---------------|------------------|
| MDK          | 5.23.0.0         |
| MDK_F4_DFP   | 2.11.0           |
| CubeMX       | 4.23.0           |
| CubeMX_F4    | 1.18.0           |

## How it works

| Phase | Process                                      | Red LED | Blue LED |
|-------|----------------------------------------------|---------|----------|
| IAP   | USB detected and flashing in progress       | 5Hz     | 0        |
|       | Flashing completed                          | 1Hz     | 0        |
|       | USB detected, but `.bin` file is missing or IAP failed | 1Hz | 1 |
| APP   | The flashed application is running          | x       | x        |

