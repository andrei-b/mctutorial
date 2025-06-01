![](img/arduino-led-to-blink.jpg)
# Intro

I've always found programming with Arduino in its default form rather uninspiring. The environment encourages a narrow and overly simplified programming model with which not many good things can be made. As such, I wouldn’t recommend Arduino as a platform for someone looking to learn the fundamentals of programming .
However, under the hood lies a family of real microcontrollers — complete with timers, interrupts, general-purpose I/O, communication peripherals, and other low-level features that reflect the real workings of embedded systems.
From this viewpoint, Arduino and similar microcontroller boards become excellent platforms for exploring the inner workings of computing. They offer a practical gateway into understanding how operating systems manage hardware, how real-time programs work, and how computers interact with the physical world through interfaces and protocols. For those interested in low-level system design, embedded development, or even writing their own OS kernels, these boards offer an accessible and hands-on foundation.
And of course Arduinos are good for any one wishing to learn the  real life microcontroller development. As I have said, they  _are_ real life microcontrollers, They  are also supported by a vast ecosystem of documentation, tutorials, and community examples.
In this tutorial, we will explore microcontroller programming through bare-metal development on Arduino — bypassing the standard Arduino libraries to work directly with the hardware. Starting with simple examples such as blinking LEDs, we will gradually build up our knowledge and skills to develop a minimal yet functional operating system from scratch.
The final stages of the tutorial will introduce more advanced concepts, leading to the integration of established real-time operating systems like FreeRTOS.

## What You Should Know Before You Start
I assume that you already know some things about the computer programming: 
 - The C programming language and its toolchain. We are doing bare-metal coding here, so you should know how to write, compile, and link C programs. Deep knowledge of assembly is not required, but you should be able to read and understand basic assembly code.
 - A general understanding of CPU architecture. I will be using terms such as registers, interrupts, memory addresses, and IRQ handlers without explaining them in detail.
