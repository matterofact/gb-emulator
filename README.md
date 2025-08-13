# gb-emulator
Gameboy emulator written in C

### Platform - Desktop

### Requirements
* Need instruction logger
* Step debugger
* Memory viewer

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
