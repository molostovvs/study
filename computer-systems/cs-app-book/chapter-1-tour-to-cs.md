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
