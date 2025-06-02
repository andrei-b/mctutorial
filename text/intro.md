![](img/arduino-led-to-blink.jpg) (c) [orlybooks.com](https://orlybooks.com/)
# Intro

I've always found programming with Arduino in its default form rather uninspiring. The environment encourages a narrow and overly simplified programming model with which not many good things can be made. As such, I wouldn’t recommend Arduino as a platform for someone looking to learn the fundamentals of programming .
However, under the hood lies a family of real microcontrollers — complete with timers, interrupts, general-purpose I/O, communication peripherals, and other low-level features that reflect the real workings of embedded systems.
From this viewpoint, Arduino and similar microcontroller boards become excellent platforms for exploring the inner workings of computing. They offer a practical gateway into understanding how operating systems manage hardware, how real-time programs work, and how computers interact with the physical world through interfaces and protocols. For those interested in low-level system design, embedded development, or even writing their own OS kernels, these boards offer an accessible and hands-on foundation.
And of course Arduinos are good for any one wishing to learn the  real life microcontroller development. As I have said, they  _are_ real life microcontrollers, They  are also supported by a vast ecosystem of documentation, tutorials, and community examples.
In this tutorial, we will explore microcontroller programming through bare-metal development on Arduino — bypassing the standard Arduino libraries to work directly with the hardware. Starting with simple examples such as blinking LEDs, we will gradually build up our knowledge and skills to develop a minimal yet functional operating system from scratch.
The final stages of the tutorial will introduce more advanced concepts, leading to the integration of established real-time operating systems like FreeRTOS.

## What you should know before you start
I assume that you already know some things about the computer programming: 
 - The C programming language and its toolchain. We are doing bare-metal coding here, so you should know how to write, compile, and link C programs. Deep knowledge of assembly is not required, but you should be able to read and understand basic assembly code.
 - A general understanding of CPU architecture. I will be using terms such as registers, interrupts, memory addresses, and IRQ handlers without explaining them in detail.
## The hardware
I am using the Arduino Uno R3. It is the *minimum minimorum* of Arduino boards, based on an 8-bit ATmega328P processor with only 2 kilobytes of RAM. Yet, in bare-metal mode, it is capable of running many interesting applications.
You can also use any earlier version of the Uno (prior to R3), but not the Uno R4 — that is a completely different system. The Arduino Mega is also a suitable alternative.
To upload bare-metal code to the Arduino Uno R3 (or any other AVR-based board), you need a hardware programmer. There are several options available, ranging from simple to professional.
I am using the USBasp, a low-cost open-source programmer that works well with AVRDUDE. It connects via USB and uses the standard 6-pin or 10-pin ISP header (you will need the 6-pin header adapter to program the Arduino boards). It is widely supported and reliable for most development needs.
Another option is the AVRISP mkII, originally produced by Atmel. It is officially supported by Atmel Studio and provides stable communication with a wide range of AVR chips. However, it requires some driver adjustments under modern operating systems.
For more advanced use, you can consider the Atmel-ICE, a professional-grade (and higher price) programmer and debugger. Among other things it supports real-time debugging on many AVR chips, including the ATmega328P. With other programmers, we are limited to "printf debugging".
Finally, in a pinch, you can even use another Arduino as a programmer. The Arduino as ISP sketch lets you turn a regular Uno into a basic ISP programmer — useful and educational, though not as reliable for frequent use.
It is also good to have a couple of LEDs and resistors.
