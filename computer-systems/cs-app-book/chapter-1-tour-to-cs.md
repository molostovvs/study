---
id: chapter-1-tour-to-cs
aliases: []
tags: []
---

# A Tour of Computer Systems

Simple C program can be compiled as:

```sh
gcc hello.c -o hello,
```

where hello.c - file with source text, hello - compiled program.
A compiled program can be run using the `./hello`.

Hello world example (see file `hello.c`):

```c
#include <stdio.h>

int main(){
    printf("Hello, world!\n");
    return 0;
}
```

Compilation is done in 4 stages, as described on the picture:

![compilation-system.png](study/assets/imgs/compilation-system.png)

To deal with the processor-memory gap, system designers include smaller,
faster storage devices called cache memories (or simply caches) that serve
as temporary staging areas for information that the processor is likely
to need in the near future.

L1 cache faster than L2 cache 5-10 times, but L2 still faster than DRAM 10 times.

Memory hierarchy (in terms of speed and size) is presented in the picture below:

![memory-hierarchy.png](study/assets/imgs/memory-hierarchy.png)

- L0:Regs - cpu registers hold words retrieved from cache memory (L1)
- L1-L3:SRAM - cache holds cache lines retrieved from previous level of memory.
- L4:DRAM - main memory holds disk blocks retrieved from local disks.
- L5:local disks - hold files retrieved from diss on remote network server
- L6:distributed file systems, web servers - remote secondary storage

## Operating system manages hardware

The operating system has two primary purposes:

1. to protect the hardware from misuse by runaway applications
2. to provide applications with simple and uniform mechanisms for manipulating
complicated and often wildly different low-level hardware devices.

Both goals are achieved via the following abstractions:

- processes
- virtual memory
- files

### Processes

When a program runs on a modern system, the OS provides the illusion
that the program is the only one running on the system. But multiple
processes can run concurrently on the same system, and each process appears
to have exclusive use of the hardware.

Even single core cpu can run multiple programs, thanks to the OS
context switching. The OS keeps track of all the state information that the process
needs in order to run (current values of the PC, the register file, and the contents
of main memory).
When the operating system decides to transfer control from the current process
to some new process, it performs a context switch by saving the context
of the current process, restoring the context of the new process, and
then passing control to the new process.
The new process picks up exactly where it left off.

![process-context-switching.png](study/assets/imgs/process-context-switching.png)

The transition from one process to another is managed by the operating system kernel.

In modern systems a process can actually consist of multiple execution units,
called threads, each running in the context of the process
and sharing the same code and global data.

### Virtual memory

Virtual memory is an abstraction that provides each process with the illusion
that it has exclusive use of the main memory. Each process has the same
uniform view of memory, which is known as its virtual address space.

The basic idea is to store the contents of a process's virtual memory on disk
and then use the main memory as a cache for the disk.

### Files

A file is a sequence of bytes, nothing more and nothing less.
Every I/O device, including disks, keyboards, displays, and even networks,
is modeled as a file. All input and output in the system is performed
by reading and writing files, using a small set of system calls known as Unix I/O.

## Important themes

A system is more than just hardware.
It is a collection of intertwined hardware and systems software that
must cooperate in order to achieve the ultimate goal of running application programs.
