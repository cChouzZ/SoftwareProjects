// ------------------------------------------------------------
// Name: ee337_lab5_c.c
// Vers: Oct 22, 2021, zc, original
//
// Auth: Zachary Chou, UAB Dept of Electrical Engineering
//
// Desc: C Source Code for EE 337 Lab 5
// Using Gator Hole to turn on various LED's
//
// ------------------------------------------------------------
// Include files:

#include "msp.h"
#include <stdio.h>

// ------------------------------------------------------------
// ------------------------------------------------------------
// Define files:

#define Gatorhole BIT3

#define RGB BIT6

#define LED2 BIT0

#define LED1 BIT0

#define BIGDELAY 3000

// ------------------------------------------------------------

void main(void)
{

// Init
    // essentials for the hardware
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

        // inputs
        P2->DIR &= ~Gatorhole;         // Setting P2 as input for gator hole which is bit 3
        P2->REN = Gatorhole;           // Enable pull-up/down resistor for P2 bit 3
        P2->OUT |= Gatorhole;          // Pull-up/down resistor is set as pull-up

        // outputs
        P2->DIR |= RGB;               // Setting P2 to RGB based on bit 6 for the output, turns on LED
        P2->DIR |= LED2;              // Setting P2 to LED 2 based on bit 0 for the output, turns on LED
        P1->DIR |= LED1;              // Setting P1 to LED 1 based on bit 0 for the output, turns on LED

        P2->OUT &= ~RGB;       // Output of P2 bit 6 will be RGB, turns off RGB
        P2->OUT &= ~LED2;      // Output of P2 bit 0 will be LED2, turn off LED2
        P1->OUT &= ~LED1;      // Output of P1 bit 0 will be LED 1, turn off LED1

// Code for applying debouncing and which LED's will turn on and off for each count
// while(1) keeps the while loop going
    while(1) {
        int count = 0; // initialize count to 0
        int i = 0; // initialize int to 0
        if ((P2->IN & Gatorhole)  == 0) {       // Created a nested if loop condition for the input, gator hole, given every scenario on which LED's will turn off or on based on the count which will go up incrementally until 7 for which it will go back to 0
          //for ( i  = 0; i < BIGDELAY; i++) {} // Delay for debouncing
          if ((P2->IN & Gatorhole)  == 0) {
            if (count == 0) {
                P2->OUT &= ~RGB;    // P2.6 is off
                P2->OUT &= ~LED2;   // P2.0 is off
                P1->OUT &= ~LED1;   // P1.0 is off

               for ( i  = 0; i < BIGDELAY; i++) {}
                count++;
                while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 1 && (P2->IN & Gatorhole) == 0) {
                P2->OUT |= RGB;     // P2.6 is on
                P2->OUT &= ~LED2;   // P2.0 is off
                P1->OUT &= ~LED1;   // P1.0 is off

               for ( i  = 0; i < BIGDELAY; i++) {}

               count++;
               while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 2 && (P2->IN & Gatorhole) == 0) {
                P2->OUT &= ~RGB;    // P2.6 is off
                P2->OUT |= LED2;    // P2.0 is on
                P1->OUT &= ~LED1;   // P1.0 is off

              for ( i  = 0; i < BIGDELAY; i++) {}

              count++;
              while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 3 && (P2->IN & Gatorhole) == 0) {
                P2->OUT |= RGB;     // P2.6 is on
                P2->OUT |= LED2;    // P2.0 is on
                P1->OUT &= ~LED1;   // P1.0 is off

                for ( i  = 0; i < BIGDELAY; i++) {}

                count++;
                while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 4 && (P2->IN & Gatorhole) == 0) {
                P2->OUT &= ~RGB;    // P2.6 is off
                P2->OUT &= ~LED2;   // P2.0 is off
                P1->OUT |= LED1;    // P1.0 is off

              for ( i  = 0; i < BIGDELAY; i++) {}

              count++;
              while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 5 && (P2->IN & Gatorhole) == 0) {
                P2->OUT |= RGB;     // P2.6 is on
                P2->OUT &= ~LED2;   // P2.0 is off
                P1->OUT |= LED1;    // P1.0 is off

               for ( i  = 0; i < BIGDELAY; i++) {}

               count++;
               while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 6 && (P2->IN & Gatorhole) == 0) {
                P2->OUT &= ~RGB;    // P2.6 is off
                P2->OUT |= LED2;    // P2.0 is on
                P1->OUT |= LED1;    // P1.0 is off

              for ( i  = 0; i < BIGDELAY; i++) {}

              count++;
              while ((P2->IN & Gatorhole)  == 0){}

            } if (count == 7 && (P2->IN & Gatorhole) == 0) {
                P2->OUT |= RGB;     // P2.6 is on
                P2->OUT |= LED2;    // P2.0 is on
                P1->OUT |= LED1;    // P1.0 is off

               for ( i  = 0; i < BIGDELAY; i++) {}

               count = 0;
               while ((P2->IN & Gatorhole)  == 0){}
            }
          }
        }
      }
    }


















