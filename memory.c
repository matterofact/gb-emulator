// The Gameboy has 8kb of work RAM, and 8kb of Video RAM.
// The Gameboy allows for the use of 65536 address spaces for memory, but not of all of these are available as memory
// This is because the Gameboy uses Memory Mapped Input/Ouput to talk to its various components, which means they appear to the
// CPU as if they were memory.
//  
