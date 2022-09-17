### CSE4001 OS/161 Code Reading

#### Description

The goal of this assignment is to introduce you to the OS/161 code. You are already a bit familiar with OS/161 after setting up your virtual machine and learning how to configure and build OS/161 kernels. OS/161 is a simplified skeleton of a modern operating system. It comes with a configurable build system, code for some useful user-level utilities that can be run from within OS/161, and of course code for the operating system itself.

Some of the assignments in CSE4001 will be related to OS/161. To complete these OS/161-related assignments, you will need to get your hands deep in the guts of the OS/161 codebase, and the sooner you become familiar with it, the better. To that end, you should look through the files and begin to learn how the code is structured, what goes where, and how things work. This applies both to the build system and the codebase itself.

To guide you in this process, please write up and hand in answers to the questions found below.

Note: in these questions, and throughout the course of the semester, we will refer to the terms "trap", "interrupt", "exception", and "system call". Although these terms might take on different meanings in different classes, in OS/161, they mean the following:

- We use "trap" as a generic term of transferring control into the kernel.
- We use "exception" for events that are synchronous with respect to user processes and cause a trap into the kernel: these include things like divide-by-0 or NULL pointer dereference exceptions and the trap caused by the syscall instruction in MIPS.
- We use "interrupt" for asynchronous events that cause a trap into the kernel: this includes things like interrupts from the serial console hardware, the timer hardware, etc.
- We use "system call" for synchronous requests user processes make to request service from the OS: system calls are invoked using traps -- specifically using the syscall instruction on MIPS.


#### Question 1
**How does OS/161 uses the struct trapframe?**

In OS/161, the trapframe struct is used to hold what is saved on to stack during entry to exception handler. This is used to transfer control to the kernel with the exception handling functions of the OS.

#### Question 2
**In which directory is the trapframe defined (i.e., where is the header file that defines the trapframe)?**

The trapframe is defined at the path `kern/arch/mips/include/trapframe.h`.

#### Question 3
**What do the fields of the trapframe represent?**

The fields of the trapframe represent the different registers that are being saved with the struct.

#### Question 4

**What information is stored in the following fields of the trapframe?**
```c
uint32_t tf_v0;
uint32_t tf_a0;
uint32_t tf_a1;
uint32_t tf_a2;
uint32_t tf_a3;
```

Saved registers are stored in these data fields. The names of each register are at the end of each name of the different fields.

#### Quesition 5
**Where is the OS/161's trapframe first filled in *when the trap handler (mips_trap) is called*?**

**Write the name of the file (program) and the code extract of the part of the program that stores the trapframe.**

The first call of the trap handler is in `kern/arch/mips/locore/trap.c`. The header of the function that stores the trapframe is: `void mips_trap(struct trapframe *tf)`.


#### Question 6

**Traps and interrupts are mechanisms used to transfer control between user-level processes and the operating system. Tell us where we can find the first C-language function of OS/161 that is executed when a trap occurs. Then, tell us where control gets transferred to from that point (i.e., what function services the trap). Be sure to describe the control flow for each type of trap that may occur (e.g., system calls, VM faults, and hardware interrupts).**

The first function that is called when a trap occurs is in `trap.c`, under the function `static void kill_currthread(vaddr_t epc, unsigned code, vaddr_t vaddr)`. Then, the exception handling is handled with the `mips_trap` function, and finally control is transferred with `mainbus_interrupt(tf);` and the interrupts are turned off.

#### Question 7
**Each OS/161 exception has its own code. What are the exception codes for the exceptions: interrupt, system call, and arithmetic overflow?**

The exception codes are:
- interrupt <-> 0
- systemcall <-> 8
- arithmetic overflow <-> 12

#### Question 8
**What is the name of the c-language function that plays the role of the system-call handler in OS/161? In which directory is this function implementation located?**

The function that acts like a system call handler is named `void syscall(struct trapframe *tf);`. It is located in `kern/arch/mips/syscall/syscall.c`.

#### Question 9
**In the system-call handler of OS/161, Lines 108 and 109 implement the call for the system call sys___time. What is the meaning of the arguments  tf->tf_a0 and tf->tf_a1 in that implementation?**

>```c
> 108 		err = sys___time((userptr_t)tf->tf_a0,
> 109				 (userptr_t)tf->tf_a1);
>```

The arguments are getting the values of the registers `a0` and `a1` from the trapframe and passing them into the `sys___time` function.

#### Question 10
**In which file is the system call int sys___time implemented?**

The system call `int sys___time(userptr_t user_seconds_ptr, userptr_t user_nanoseconds_ptr)` is located in `kern/syscall/time_syscalls.c`.

#### Question 11
**Why does the function  int sys___time returns zero upon its completion? What happens if the function returns a non-zero value?**

The zero return is a default, and the only times the result would be non-zero is if the `copyout` and therefore `copycheck` functions from `kern/vm/copyinout.c` were to find that the block of memory is in the userspace region. If it is outside of those bounds, then it returns an EFAULT. So, the only time there is a non-zero return is if there is a problem with the block of memory that is trying to be used.
