
# Hardware and Protocols Overview

## Power Consumption
- **Observation:** When frequency increases, power consumption increases.

## Hardware Ports and Protocols
- **Hardware Port:**
  - Master
  - Slave

- **Protocol Types:**
  - AXI
  - AHB
  - APB

- **Roles:**
  - **Master:** Initiates transaction (write data, write address, read data, read address)
  - **DMA:** Controls the bus to access memory; has master and slave roles

- **AMBA:** Standard for protocols

## MCU Clocks
- Every CPU and bus has a maximum rate.
- Almost all preph clocks are locked by default; they need to be enabled manually.

- **Clock Preph:** Has master and slave roles

- **Clock Types:**
  - Internal (RC)
    - Example: RC/chip with one pin
  - External
    - Example: Crystal with two pins

## Volatile Keyword
- The `volatile` keyword is used to ensure the compiler checks for the value of a variable during optimization.

- **Best Practice for Assigning Register Address:**
  ```c
  *(volatile uint8_t*)0xFF
  ```

- **Register Address:** Calculated as `base + offset`

## Reference Materials
- **Reference Manual:** General for all families
- **Data Sheet:** Specific for one family
