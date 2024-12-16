# **Multiple Fork Calls**

*Objective:* Understand the process hierarchy when multiple sequential `fork` syscalls are invoked.

*Write a program that:*
* Calls multiple `fork` syscalls one after another. Check what the process tree looks like.
* Pay attention to the hierarchy of processes, how many parents and children are created.

*Sample code:*
```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    return 0;
}