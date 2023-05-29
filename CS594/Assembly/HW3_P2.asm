; Homework Assignment #3 Problem 2
; Reverse order of bytes in memory
; Assembly for Motorola 68000

           ORG         $1000           ; Start location of program
           BSR         INIT            ; Initialize program parameters
LOOP       MOVE.B      (A0),(A1)       ; Copy contents of A0 to A1
           ADDA.B      #1,A0           ; Increase address by 1 in A0
           SUBA.B      #1,A1           ; Decrease address by 1 in A1
           SUB.B       #1,D0           ; Subtract 1 from our counter
           BNE         LOOP            ; If not equal, branch to LOOP
           TRAP        #15
           DC.W        0


INIT       LEA         $900,A0         ; Set starting address to A0
           LEA         $918,A1         ; Set end address to A1
           MOVE.L      #$00112233,(A0) ; Assign bytes into first longword
           MOVE.L      #$FFEEDDCC, ($900+4)  ; Assign bytes into second longword
           MOVE.B      #$BB,($900+8)   ; Assign byte to last byte
           CLR.L       D0              ; Clear D0
           MOVE.B      #9,D0           ; Main counter
           RTS