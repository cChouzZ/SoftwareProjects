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

main:

                                ; while(1)
                                ; {

        mov     r0, #7d      	 ;     r0 has the decimal value of 7
        mov 	r1, #8d          ;     r1 has the decimal value of 8

        nop

        AND r2, r0,r1            ;     uses bit wise operation AND on r0 and r1 to a new resigter named r2

        bl my_test_subroutine    ;     branches to my_test_subroutine if the AND operation is a set, 1

        nop

        cbz r2, my_other_test_subroutine ; branches to my_other_test_subroutine if the AND operation is a clear, 0

		nop

        B       main            ; } // end while(1)


; ------------------------------------------------------------

my_test_subroutine:

		mov r0, #0ffffh ; Assigned value for r0 if bit 3 is set, 1


		bx lr          ; THIS is how you return from a
				       ; subroutine in assembly code

; ------------------------------------------------------------

my_other_test_subroutine:

		mov r0, #0 ; Assigned value for r0 if bit 3 is clear, 0


        B     main     				; THIS is how you return from a
                          		    ; subroutine in assembly code

; ------------------------------------------------------------
; ------------------------------------------------------------
; Final catch-all at the end of our code, just in case

hang_forever:
        nop
      B   hang_forever

; ------------------------------

	.end

; ------------------------------------------------------------
; ------------------------------------------------------------
