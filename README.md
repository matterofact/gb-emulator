# gb-emulator
Gameboy emulator written in C

### Platform - Desktop

### Requirements
* Need instruction logger
* Step debugger
* Memory viewer

## Specs

### CPU

- Sharp LR35902 (8-bit), a mix between Z80 and Intel 8080

### Memory

- 64KB address space (RAM, ROM, I/O registers, VRAM etc.)

### GPU

- Tile-based, 160x144 resolution, 4 shades of grey

### Audio

- 4 channels: 2 square waves, 1 wave channel, 1 noise channel

### Input

- D-pad + 4 buttons

### Timers

- DIV, TIMA, TMA, TAC

### Interrupts

- V-Blank, LCD STAT, Timer, Serial, Joypad

## To Do

* Skeleton
    - Create basic main loop
    - stub CPU, memory, GPU and input interfaces

* CPU Core
    - Implement registers and flag bits (Z, N, H, C)
    - Implement instruction fetch/decode/execute cycle
    - start with no timing accuracy, just correctness

* Memory & Mappers
    - Emulate memory map:


    0000-3FFF: ROM Bank 0
    4000-7FFF: Switchable ROM Bank
    8000-9FFF: VRAM
    A000-BFFF: External RAM
    C000-DFFF: WRAM
    FE00-FE9F: OAM
    FF00-FF7F: I/O Registers
    FF80-FFFE: HRAM
    FFFF: Interrupt Enable


    - Implement MBC0, MBC1, MBC3, MBC5
