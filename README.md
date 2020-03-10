# stdlib-c
C standard library remade

## Iteration 1
Wrote a function in assembly, called it in C, examined with GDB what is sent in which register
Implemented system calls from that

## Iteration 2
Used strace to check what malloc does, implemented brk system call


### Architecture
```
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
```

### Coming features
```
standard/System/linux/x64/stdlib
├──> malloc: 
│	   ├──> track allocated blocks and store them
│	   ├──> allocate heap in pages, to reduce system calls count
│	   ├──> check if some place is available in the blocks list before allocating again
│ 	   └──> if size is over a page, allocate virtual memory (mmap)
└──> free
	   └──> set new breakpoint if whole page can be freed 
```