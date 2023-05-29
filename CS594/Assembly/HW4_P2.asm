; Homework Assignment #4 Problem 2
; Program that handles level-1 and level-2 interrupts
; Assembly for Motorola 68000
;
; Homework instructions were very vague and unclear with what is being
; wanted in the assignment.  The interrupt levels from the devices are
; Device-1 = Level 1
; Device-2 = Level 2
; Device-1 can be designed by hardware with a manual interrupt to control
; b1 of the LED array and Device-2 can be tied to a CLK signal and driven
; that way to control b3 of the LED array.
;
; In this assignment, I made the Shared Device a subroutine that gets
; called to handle every Level-1 and Level-2 interrupt.
;
; Each time Shared Device is called, it adds a 1 to $A00 to count how
; many times it is called.  I feel that the software is capable of running
; given the theoretical hardware connections.
;
; Again, too many assumptions had to be made for this assignment.

           ORG         $900            ; Start location of program
           LEA         $7000,A7        ; Start location of USP
           MOVE.W      #$2000,SR       ; Set SR to allow interrupts 3-7
           BSR         INIT            ; Initialization Subroutine
           BRA         *               ; Infinite Program Loop

INIT       MOVE.L      #INT1,$064      ; Move address of INT1 into address of Level-1
           MOVE.L      #INT2,$068      ; Move address of INT2 into address of Level-2
           MOVE.B      #0,($8101)      ; Clear LED Location
           MOVE.B      #0,($A00)       ; Clear Shared Counter
           CLR.L       D0              ; Clear D0
           CLR.L       D1              ; Clear D1
           CLR.L       D2              ; Clear D2
           RTS                         ; Return from Subroutine


SHARE      ADD.B       #1,$A00         ; Add 1 to the counter
           CMP.B       D2,D1           ; Compare LED bits to determine activity
           BEQ         SUB             ; Branch to SUB subroutine
           ADD.B       D2,D0           ; Add value from D2 to LED byte
           MOVE.B      D0,$8101        ; Move new LED byte to $8101
           RTS


INT1       MOVE.B      $8101,D0        ; Read a byte from $8101 into D0
           MOVE.B      D0,D1           ; Move LED contents from D0 to D1
           ANDI.B      #$1,D1          ; Compare b1 to see if HIGH/LOW
           MOVE.B      #$1,D2          ; Move bit position indicator to D2
           BSR         SHARE           ; Branch to SHARED Device
           RTE                         ; Return from Interrupt

INT2       MOVE.B      $8101,D0        ; Read a byte from $8101 into D0
           MOVE.B      D0,D1           ; Move LED contents from D0 to D1
           ANDI.B      #$4,D1          ; Compare b3 to see if HIGH/LOW
           MOVE.B      #$4,D2          ; Move bit position indicator to D2
           BSR         SHARE           ; Branch to SHARED Device
           RTE                         ; Return from Interrupt

SUB        SUB.B       D2,D0           ; Subtract bit value from D2 from LED byte
           MOVE.B      D0,$8101        ; Write LED byte
           RTS                         ; Return from Subroutine