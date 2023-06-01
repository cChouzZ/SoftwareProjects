// ------------------------------------------------------------
// Name: ee337_lab4_c.c
// Vers: Oct 22, 2021, zc, original
//
// Auth: Zachary Chou, UAB Dept of Electrical Engineering
//
// Desc: C Source Code for EE 337 Lab 4
// Turning on Red LED 1 using switch 1 and Red LED 2 using switch 2
//
// ------------------------------------------------------------
// Include files:

#include "msp.h"
#include "stdio.h"

// ------------------------------------------------------------
// ------------------------------------------------------------
// Define files:

#define LED1 BIT0
#define S1 BIT1

#define LED2 BIT0
#define S2 BIT4

// ------------------------------------------------------------

void main(void)
{

// Init
    // essentials for the hardware    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    P1->DIR = LED1;         // Setting P1 to input and out put based on the bits. 0 is the LED1 which is the output. 1 is the S1 which is the input
    P1->REN = S1;           // Enable pull-up/down resistor for P1 bit one which is switch 1
    P1->OUT = S1;           // Pull-up/down resistor is set as pull-up

    P1->DIR &= ~(S1|S2);    // Setting P1 as inputs based on the bits.bit 1 is for switch one and bit 4 is switch two
    P1->REN = S1|S2;        // Enable pull-up/down resistor for P1's bits of 1 and 4, switches
    P1->OUT = S1|S2;        // Pull-up/down resistor set to pull-up

    P2->DIR = LED1|LED2;    // Set P2 to outputs based on the bits. 0 is for LED1 and 1 is for S1
    P2->OUT = 0x00;         // Turn off LED2

// code for turning on Red LED 1 when Switch1 is held and Red LED 2 when Switch2 is held
// while(1) keeps the while loop going
    while(1) {
        if((P1->IN & S1) == 0x00)        // Activate low input
            P1->OUT |= LED1;             // Turn on LED 1
        else
            P1->OUT &= ~LED1;           // Turn off LED1
        if((P1->IN & S2) == 0x00)       // Activate low input
                   P2->OUT |= LED2;     // Turn on LED 2
               else
                   P2->OUT &= ~LED2; // Turn on LED 2
    }
}


