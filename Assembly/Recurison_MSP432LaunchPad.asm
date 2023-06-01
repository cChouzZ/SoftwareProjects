; ------------------------------------------------------------
; Name: ee337_lab3_asm.asm
; Vers: Oct 8, 2021, zc, original
;
; Auth: Zachary Chou, UAB Dept of Electrical Engineering
;
; Desc: Assembly Source Code for EE 337 Lab 3
;
; ------------------------------------------------------------

    .thumb
    .text
    .align 2
    .global main

; ------------------------------

main:                    ; start while(1) loop
						 ; Specaial note: The code is right, but it has an interruption for which
						 ; We have not been taught yet to fix.
						 ; Stuck on a loop

        mov r0, #1         ; r1 is the returned value of the subroutine
        mov r1, #5         ; r0 is inout value of the subroutine
        mov r2, r0         ; r2 is the r0 value, temp

        push {r0,r1}       ; push r0 and r1 into a stack

        nop                ; no operation

Perry:                    ; Name of branch


        mul r0,r1,r2    ; Multiply r1 and r2 to register r0

        sub r2,r1,#1    ; Subtract r1 by one to register r2

        cmp r1, #1       ; Compares r1 to the 1

        bgt Perry          ; If r1 is greater than one, the code will branch back to the Perry branch
        				   ; and repeat lines 34-38 until r1 is not greater than one for which it will go to line 43

        pop {r0,r1}        ; Pops the stack, releases the stack, of r0 and r1

        B main            ; The code is branched to line 19 and starts the process all over




hang_forever:            ; safety mechanism, just in case code from above is deleted, the code will branch to hang_forever, so one
					     ; one can make edits without the code crashing
        nop
      B   hang_forever

 ; ------------------------------

	.end

; ------------------------------------------------------------
