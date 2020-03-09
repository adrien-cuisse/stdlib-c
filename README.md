# stdlib-c
C standard library remade

## Iteration 1
Wrote a function in assembly, called it in C, examined with GDB what is sent in which register
Implemented system calls from that

## Iteration 2

Architecture

stdlib/
├── Character/ ??
├── stdio/ - global stdlio.h functions
├── stdlib/ - global stdlib.h functions
├── String/ - string functions 
└── System/ - system dependant code
    ├── linux/ - linux specifics
    │   └── x64/ - 64 bits specifics
    │       ├── asm/ - assembly functions
    │       ├── stdio/ - linux64 stdio specifics
    │       ├── stdlib/ - linux64 stdlib specifics
    │       └── system/ - linux64 system calls
    └── System.h
