; Lab Assignment #4
; Test the functionality of using switches
; Assembly for Motorola 68000


SWTH       EQU         $E001           ; Assigning name to Address
LEDS       EQU         $E003           ; Assigning name to Address
SOUND      EQU         $E031           ; Assigning name to Address

           ORG         $900            ; Location to start program
           LEA         $7000,A7        ; Set user stack pointer
TEST       MOVE.B      SWTH,D1         ; Move a byte from SWTH to D1
           MOVE.B      D1,LEDS         ; Write D1 to LEDS to display


LOOP       MOVE.B      SWTH,D1         ; Move a byte from SWTH to D1

CHKB7      BTST.B      #7,D1           ; Test bit 7 of D1 if equal to 0
           BEQ         B52ON           ; If equal, branch to B52ON


CHKB6      BTST.B      #6,D1           ; Test bit 6 of D1 if equal to 0
           BEQ         RRGHT           ; If equal, branch to RRGHT
           BNE         RLEFT           ; If not equal, branch to RLEFT

CHKB5      BTST.B      #5,D1           ; Test bit 5 of D1 if equal to 0
           BEQ         DLY2            ; If equal, branch to DLY2
           BNE         DLY1            ; If not equal, branch to DLY1

CHKB4      BTST.B      #4,D1           ; Test bit 4 of D1 if equal to 0
           BNE         ALLON           ; If not equal, branch to ALLON


           BRA         LOOP            ; Branch back to LOOP

B52ON
           MOVE.B      #$3C,D0         ; Sets all bits in a byte to HIGH in D0
           MOVE.B      D0,LEDS         ; Write D0 to LEDS
           BRA         LOOP            ; Branch back to LOOP

RRGHT      ROR.B       #1,D0           ; Rotate a HIGH bit to the right in D0
           MOVE.B      D0,LEDS         ; Write D0 to LEDS
           BRA         CHKB5           ; Branch to CHKB5

RLEFT      ROL.B       #1,D0           ; Rotate a HIGH bit to the left in D0
           MOVE.B      D0,LEDS         ; Write D0 to LEDS
           BRA         CHKB5           ; Branch back to CHKB5

DLY1       MOVE.L      #25,D5          ; Write 25 into D5 for initial counter
DEL1       BSR         DELAY           ; Branch Subroutine DELAY
           SUB.B       #1,D5           ; Subract 1 from D5
           BNE         DEL1            ; If not equal, branch to DEL1
           BRA         CHKB4           ; Branch to CHKB4

DLY2       MOVE.L      #$100,D5        ; Write 100 into D5 for initial counter
DEL2       BSR         DELAY           ; Branch Subroutine DELAY
           SUB.B       #1,D5           ; Subtract 1 from D5
           BNE         DEL2            ; If not equal, branch to DEL2
           BRA         CHKB4           ; Branch to CHKB4

DELAY      CLR.L       D4
           MOVE.L      #$7FFFFFFF,D4   ; Write largest longword to D4
DLAY1      SUBQ        #1,D4           ; Subtract 1 from D4
           BNE         DLAY1           ; If not equal, branch to DLAY1
           RTS

ALLON      MOVE.B      #$FF,D0         ; Writes a byte of all 1's to D0
           MOVE.B      D0,LEDS         ; Writes D0 to LEDS
           BRA         LOOP            ; Branch to LOOP