; Lab Assignment #5
; Test the priority of Interrupts
; Assembly for Motorola 68000

INTT       EQU         $0040           ; Assign Variable to Address
INT3       EQU         $006C           ; Assign Variable to Address
INT4       EQU         $0070           ; Assign Variable to Address
INT5       EQU         $0074           ; Assign Variable to Address
INT6       EQU         $0078           ; Assign Variable to Address
INT7       EQU         $007C           ; Assign Variable to Address
LEDS       EQU         $E003           ; Assign Variable to Address
BAR        EQU         $E007           ; Assign Variable to Address
SOUND      EQU         $E031           ; Assign Variable to Address

           ORG         $900            ; Location to start program
           LEA         $7000,A7        ; Set user stack pointer
           MOVE.L      #INTTP,INTT     ; Copy address of Subroutine to Interrupt Address
           MOVE.L      #INT5P,INT5     ; Copy address of Subroutine to Interrupt Address
           MOVE.L      #INT4P,INT4     ; Copy address of Subroutine to Interrupt Address
           MOVE.L      #INT7P,INT7     ; Copy address of Subroutine to Interrupt Address
           MOVE.L      #INT3P,INT3     ; Copy address of Subroutine to Interrupt Address
           MOVE.W      #$2300,SR       ; Set SR to allow interrupts 4-7
           CLR.L       D0
           CLR.L       D1
           CLR.L       D2
           CLR.L       D3
           CLR.L       D4
           BRA         *               ; Infinite Loop

INT3P      MOVE.B      #0,SOUND        ; Set a 0 to sound player
           BRA         *               ; Infinite Loop
           RTE

INT4P      MOVE.B      #0,SOUND        ; Set a 1 to sound player
           BRA         *               ; Infinite Loop
           RTE

INT5P      MOVE.B      #1,SOUND        ; Set a 1 to sound player
           BRA         *               ; Infinite Loop
           RTE

INT6P      MOVE.B      #0,SOUND        ; Set a 0 to sound player
           BRA         *               ; Infinite Loop
           RTE

INT7P      MOVE.B      #1,SOUND        ; Set a 1 to sound player
           BRA         *               ; Infinite Loop
           RTE

INTTP      ADD.B       #1,D1           ; Add a 1 to D1
           CMP.B       #11,D1          ; Check if D1 is equal to 11
           BNE         GOBK            ; If not equal, branch to GOBK
           CLR.L       D1
           ADD.L       #$8,D0          ; Add Hex 8 to D0
           MOVE.B      D0,BAR          ; Write D0 to Bar display
GOBK       RTE

