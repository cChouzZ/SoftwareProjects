// ------------------------------------------------------------
// Name: ee337_lab7_c.c
// Vers: Nov 19, 2021, zc, original
//
// Auth: Zachary Chou, UAB Dept of Electrical Engineering
//
// Desc: C Source Code for EE 337 Lab 7
// Interrupts
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
#define S2 BIT5

#define BLUE BIT6

#define TIMER_PERIOD 12000000

// ------------------------------------------------------------

// Initialize function
void SysTick_Handler(void);

void main(void)
{

// Init
    // essentials for the hardware    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

            // Input
            P5->DIR &= ~S1;          // Setting P5 as the input based on the bit the pin is at, which is bit 1 for switch one on the booster pack.
                                     // Points the pin what it is being addressed to, switch one on the booster pack
            P5->REN |= S1;           // Enable pull-up/down resistor for P5 bit 1 which is switch 1
            P5->OUT |= S1;           // Pull-up/down resistor is set as pull-up

            // Input
            P3->DIR &= ~S2;         // Setting P3 as the input based on the bit the pin is at, which is bit 5 for switch two on the booster pack.
                                    // Points the pin what it is being addressed to, switch two on the booster pack
            P3->REN |= S2;          // Enable pull-up/down resistor for P3's bit of 5, switch two on the booster pack
            P3->OUT |= S2;          // Pull-up/down resistor set to pull-up

            // Output
            P1->DIR |= LED1;         // Set specific pin to be the output, the output for P1 would be LED1 bit 0
            P1->OUT &= ~LED1;        // Turns off LED1

            // Output
            P5->DIR |= BLUE;         // Set specific pin to be the output, the output for P5 would be RGB Blue bit 6
            P5->OUT &= ~BLUE;        // Turns off the Blue light from the RGB LED on the booster pack

            // Output
            P2->DIR |= LED2;         // Set specific pin to be the output, the output for P2 would be LED2 bit 0
            P2->OUT &= ~LED2;        // Turns off LED2

        while (PCM->CTL1 & PCM_CTL1_PMR_BUSY);              // PCM = power control module to manage active and low power modes of operations for the launchpad
                                                            // When PDM is assigned to CTL1, it checks the power mode changing process
                                                           // PMR_BUSY but is the busy flag for power mode request. Bit is set when active or lower power
                                                           // mode request of processed and reset when the transition is done
                                                           // For every time the to conditions are true, the program will go to line line 56
            PCM->CTL0 = PCM_CTL0_KEY_VAL | PCM_CTL0_AMR_1; // PCM being assigned to CTL0 changes active power mode or check current power mode
                                                           // PCM KEY can change the power mode with KEY VAL being the desired power mode to be selected
                                                           // when hexadecimal 0x695A is written to bits
                                                           // AMR_1 makes an AM request, active mode
                while (PCM->CTL1 & PCM_CTL1_PMR_BUSY);     // PCM = power control module to manage active and low power modes of operations for the launchpad
                                                           // When PDM is assigned to CTL1, it checks the power mode changing process
                                                           // PMR_BUSY but is the busy flag for power mode request. Bit is set when active or lower power
                                                           // mode request of processed and reset when the transition is done
                                                           // For every time the to conditions are true, the program will go to line line 56

                    FLCTL->BANK0_RDCTL = (FLCTL->BANK0_RDCTL & ~(
                    FLCTL_BANK0_RDCTL_WAIT_MASK)) | FLCTL_BANK0_RDCTL_WAIT_1;
                    FLCTL->BANK1_RDCTL = (FLCTL->BANK0_RDCTL & ~(
                    FLCTL_BANK1_RDCTL_WAIT_MASK)) | FLCTL_BANK1_RDCTL_WAIT_1;

                    CS->KEY = CS_KEY_VAL;               // All CS registers can be configured
                    CS->CTL0 |= CS_CTL0_DCORSEL_5;      // Allow clock to have a set DCO frequency
                    CS->KEY = 0;                        // Allow or prevent CS modules to configure

                    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;  // CLKSOURCE sources SysTick from MCLK. ENABLE enables SysTick
                    SysTick->LOAD = TIMER_PERIOD;                                           // SysTick will load the timer period interval defined above for the interrupt
                    SysTick->VAL = 0;                                                       // Gets the values for the SysTick
                    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;                              // Enables the SysTick interrupt

                    __enable_irq();                                                         // Enable interrupts

// code for turning on Red LED 1 when Switch1 is held and Red LED 2 when Switch2 is held on the booster pack
// while(1) keeps the while loop going
        while(1) {
            if((P5->IN & S1) == 0x00)        // Activate low input. Assign what pin will receive input from the microcontroller, input for P5 is set to S1 which will be
                                             // on when pressed
                P1->OUT |= LED1;             // Turn on LED 1 when S1 is pressed
            else
                P1->OUT &= ~LED1;           // Turn off LED1 when S1 is released
            if((P3->IN & S2) == 0x00)       // Activate low input. Assign what pin will receive input from the microcontroller, input for P3 is set to S2 which will be
                                            // on when pressed
                       P2->OUT |= LED2;     // Turn on LED 2 when S2 is pressed
                   else
                       P2->OUT &= ~LED2; // Turn off LED 2 when S2 is released
        }
}

// Function that allows the timer to continuously output the BLUE light from the interrupt
void SysTick_Handler(void) {
        P5->OUT ^= BLUE;
}







