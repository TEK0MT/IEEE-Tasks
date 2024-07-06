
# Memory Types

## Hybrid Memory
```
            |          |          |
         EEPROM      Flash      NVRAM
```

### EEPROM
- Can be reprogrammed by electricity.
- Has endurance of 100,000 times.
- Accessible byte by byte.
- Expensive.
- Can be internal or external.

### Flash
- Access sector by sector (block access).
- Has endurance of 10,000.
- Low cost.

### NVRAM
- Combination of SRAM and Battery or SRAM, EEPROM, and Battery.

## Non-Volatile Memory

### ROM (Read-Only Memory)
- Used to store code.
- The access time of ROM is longer than RAM.
- Based on FGM (Floating Gate MOSFET): When the floating gate has a negative charge, it's often in a programming state; a positive charge is called the erasing state.

#### Types of ROM
```
                  ROM
                  |
    -------------------------------
    |                |             |
Mask Prog ROM      PROM          EPROM
```

1. **Mask Prog ROM**:
    - Programmed once only.
    - Called OTP (One Time Programmable).
    - Used for toys because it's cheap.
    - Usually programmed by factories.

2. **PROM**:
    - Programmable ROM.
    - Also OTP, user programs it.

3. **EPROM**:
    - Erasable Programmable ROM.
    - Can be reprogrammed by ultraviolet light.
    - Stores data for a long time.
    - Affected by noise or radiation.
# Computer Architecture Notes

## I/O Connectivity

I/O can be connected in two ways:

1. *Memory Mapped I/O*:
    - Diagram:
    
    RAM -- MP -- ROM
      \       /
       I/O
    
    - Uses the same address space for both memory and I/O devices.
    - Accessed using standard memory instructions (load/store).
    - Example: C language load/store.

2. *Port Mapped I/O*:
    - Diagram:
    
    RAM -- MP -- ROM
             \     
             I/O
    
    - Uses separate address space for I/O devices.
    - Accessed using special instructions (in/out).

## Pipeline

Pipeline stages: F | D | G | E

- *Von Neumann Architecture*: Can't support pipelining.
- *Harvard Architecture*: Can support pipelining.
- *RISC*: Can support pipelining.
- *CISC*: Can't support pipelining.

## Cache Memory

- Every cache has cache coherence which ensures every core knows if changes happened on cached data.
- Cache is a SRAM memory.
- *Hit Ratio*: hits / total
- *Components*:
    - *FPU*: Floating Point Unit.
    - *MPU*: Memory Protection Unit, placed between cache and RAM.
    - *MMU*: Memory Management Unit.

## Architectures

1. *Von Neumann Architecture*:
    - MPU connects to RAM, cache, ROM with the same data bus.
    - Diagram:
    
    RAM -- MPU -- ROM
     |        |
    cache
    

2. *Harvard Architecture*:
    - MPU connects to every memory with different data buses.
    - Diagram:
    
    RAM -- MPU -- ROM
     |        |
    cache
    

- *Software Usage*:
    - *RAM*: Load/store using C language.
    - *ROM*: Read/write using Assembly language.

## Clock Cycle and Systems

- *Clock Cycle*: Square wave
    - Diagram:
    
    ___    ___
    |  |  |  |
    |  |  |  |
    

- *Clock Systems*:
    - *Electrical*: RC-oscillator
    - *Mechanical*: Matched current, ceramic, crystal

### Comparison of Clock Systems

| Feature   | RC-oscillator | Ceramic | Crystal |
|-----------|---------------|---------|---------|
| Cost      | ✓             |         |         |
| Accuracy  |               | between | ✓       |
| Settling  |               |         |         |
| Time      |               |         | ✓       |
| Noise     |               |         |         |
| Temp      |               |         | ✓       |
| EMI       |               |         |         |
| Vibration | ✓             |         | ✓       |