# stdlib-c
C standard library remade

## Iteration 1
Wrote a function in assembly, called it in C, examined with GDB what is sent in which register
Implemented system calls from that

## Iteration 2

Architecture

stdlib/ root directory
├── Character/ ??
├── String/ string functions
└── System/ non-portable code
    └── OS/ - OS specificities
        └── bits/ - bits specifities
            ├── asm - assembly functions
            ├── stdlib - stdlib implementation for that system
            └── system - system calls functions