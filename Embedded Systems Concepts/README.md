# Embedded Systems Concepts

## Overview of Computing Systems
- *Components*:
  - *Processor*
  - *Memory*
  - *I/O (Input/Output)*
- *Types of Systems*:
  - *General Purpose*
  - *Special Purpose*

## Embedded Systems Challenges
- *Key Factors*:
  - *Power Consumption*
  - *Cost*
  - *Size*
  - *Speed*

### ES Challenge Breakdown
- *Size*:
  - *Size Reduction* (s.r) can be represented as a fraction.
- *Cost*:
  - *Cost Efficiency* can be represented as a fraction.
- *Power Consumption*:
  - *Power Consumption Reduction* can be represented as a fraction.
- *Configurability*:
  - Embedded systems should be configurable.

## Microprocessor Units (MPUs)
- *Components*:
  - *Processor*
  - *Microprocessor*
  - *CPU (Central Processing Unit)*

## Microcontroller Units (MCUs)
- *Definition*: An MCU contains an MPU.
- *Components*:
  - *If an MCU has a GPU/DSP, they are called secondary processors and it's referred to as MCU high performance (SoC)*.

## Types of Applications
- *Baremetal Software*
- *OS Applications*:
  - Example: Raspberry Pi

## Microcontroller Components
- *Any microcontroller contains*:
  - *CPU*
  - *Memory*
  - *I/O (Input/Output)*

### CPU Components
- *Arithmetic Logic Unit (ALU)*
- *Control Unit*
- *Registers File*

## Instruction Life Cycle
1. *Fetch*: The code is stored in RAM and the program counter points to the next instruction.
2. *Decode*: The control unit fetches the code from RAM and stores it in the IR register.
3. *Execute*: The instruction decoder in the control unit decodes the code. After decoding, the arithmetic operation is done by the ALU. The code is stored in general purpose registers.

## Understanding Instructions
- *Hardwarp*:
  - *SD (Storage Device)*
- *Software*:
  - *Compiler*

## Instruction Set Architecture (ISA)

### Types of ISA
- *RISC (Reduced Instruction Set Computer)*
  - Characteristics:
    - Executes low commands quickly.
    - Uses a smaller set of simpler instructions.
    - Faster performance due to simpler instructions.
    - Example: ARM architecture commonly used in embedded systems.

- *CISC (Complex Instruction Set Computer)*
  - Characteristics:
    - Executes high-level commands directly.
    - Uses a larger set of complex instructions.
    - Can take longer to execute due to more complex instructions.
    - Example: x86 architecture used in most personal computers.

## Instruction Decoder

- *Hard-wired Decoder*
  - Faster execution.
  - Best for RISC architectures with simpler instruction sets.
  - Relies on logic gates for operation.

- *Memory-mapped Decoder*
  - Searches in memory for instruction decoding.
  - Suitable for CISC architectures with more complex instruction sets.

## Comparison of RISC vs CISC

| Feature                | RISC                               | CISC                              |
|------------------------|------------------------------------|-----------------------------------|
| *Instruction Size*   | Smaller                            | Larger                            |
| *Execution Speed*    | Faster due to simple instructions  | Slower due to complex instructions|
| *Cost*               | Lower silicon cost                 | Higher silicon cost               |
| *Power Consumption*  | Lower                              | Higher                            |
| *Typical Use Cases*  | Embedded systems                   | General-purpose computing         |

---

## Register Files

Registers are special storage locations within the CPU used to quickly access data and instructions.

- *General Purpose Registers (GPR)*
  - Used for common data storage and operations.

- *Specific Purpose Registers (SPR)*
  - Includes important registers like:
    - *PC (Program Counter)*: Holds the address of the next instruction to execute.
    - *SP (Stack Pointer)*: Points to the top of the stack.
    - *ACC (Accumulator)*: Stores intermediate results from arithmetic and logic operations.
    - *IR (Instruction Register)*: Holds the current instruction being executed.
    - *PSW (Process Status Word)*: Contains status flags and control bits.

---

## Memory Types

Memory in computer systems can be categorized based on its volatility and usage.

### Volatile Memory

- *RAM (Random Access Memory)*
  - *SRAM (Static RAM)*
    - Based on flip-flop transistors.
    - *Advantages*: Faster access times.
    - *Disadvantages*: Higher cost.
    - Commonly used as cache memory due to its speed.
  
  - *DRAM (Dynamic RAM)*
    - Based on capacitors and requires periodic refreshing.
    - *Advantages*: Simple design, lower cost, and higher density.
    - *Disadvantages*: Slower access compared to SRAM.
    - Used as the main memory in most computer systems.

### Non-Volatile Memory

- *ROM (Read-Only Memory)*
  - Retains data even when powered off.
  - Used to store firmware and critical startup instructions.

### Hybrid Memory

- Combines features of both volatile and non-volatile memory for specific applications.

---

## Memory Comparison: SRAM vs DRAM

| Feature                | SRAM                                 | DRAM                                 |
|------------------------|--------------------------------------|--------------------------------------|
| *Size*               | Smaller capacity                     | Larger capacity                      |
| *Cost*               | Higher cost                          | Lower cost                           |
| *Performance*        | Faster access times                  | Slower access times                  |
| *Power Consumption*  | Lower                                | Higher due to refreshing needs       |

---

### Note:
- *SRAM* is ideal for use as cache memory due to its fast access times.
- *DRAM* is used for main system memory where larger capacity and cost efficiency are important.

---