
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
