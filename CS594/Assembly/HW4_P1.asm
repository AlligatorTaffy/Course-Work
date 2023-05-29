; Homework Assignment #4 Problem 1
; Program that handles level-3 and level-5 interrupts
; Assembly for Motorola 68000
;
; Making the assumption that the problem wants to have interrupt 3 read from $E003
; and interrupt 5 to read from $E005, write b0 and b7 back to $E003

           ORG         $900            ; Start location of program
           LEA         $7000,A7        ; Start location of USP
           MOVE.W      #$2200,SR       ; Set SR to allow interrupts 3-7
           BSR         INIT            ; Initialization Subroutine
           BRA         *               ; Infinite Program Loop

INIT       MOVE.L      #INT3,$06C      ; Move address of INT3 into address of Level-3
           MOVE.L      #INT5,$074      ; Move address of INT5 into address of Level-5
           MOVE.B      #$94,$E005      ; Move arbitrary hex number into $E005
           MOVE.B      #$6F,$E003      ; Move arbitrary hex number into $E003
           CLR.L       D0              ; Clear D0
           CLR.L       D1              ; Clear D1
           RTS                         ; Return from Subroutine


INT3       MOVE.B      $E003,D0        ; Read a byte from $E003 into D0
           RTE                         ; Return from Interrupt

INT5       MOVE.B      $E005,D1        ; Read a byte from $E005 to D1
           ANDI.B      #$81,D1         ; AND compare b0 and b7
           MOVE.B      D1,$E003        ; Move AND result to #E003
           RTE                         ; Return from Interrupt