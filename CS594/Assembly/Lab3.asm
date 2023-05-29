; Lab Assignment #3
; Test the functionality of Interrupts 5-7
; Assembly for Motorola 68000

INT5       EQU         $74             ; Define name to address
INT6       EQU         $78             ; Define name to address
INT7       EQU         $7C             ; Define name to address
LEDS       EQU         $E003           ; Define name to address
BAR        EQU         $E007           ; Define name to address
SOUND      EQU         $E031           ; Define name to address
SLIDER     EQU         $E005           ; Define name to address



           ORG         $900            ; Start location of program
           CLR.L       D0
           CLR.L       D1
           MOVE.L      #INT5P,INT5     ; Copy address to interrupt address
           MOVE.L      #INT6P,INT6     ; Copy address to interrupt address
           MOVE.L      #INT7P,INT7     ; Copy address to interrupt address
           MOVE.L      #INT2P,$0014    ; Copy address to interrupt address
           MOVE.W      #$2400,SR       ; Set SR to allow interrupts 5-7
           DIVU        D0,D1           ; Test the Divide by Zero exception
           BRA         *

INT5P      ADD.B       #1,LEDS         ; Write a 1 to the hardware LEDs address
           RTE

INT6P      MOVE.B      SLIDER,BAR      ; Write the contents from Slider to Bar display address
           RTE

INT7P      MOVE.B      #1,SOUND        ; Write a 1 to the Sound playing address
           RTE

INT2P      LEA         MSG,A0          ; Copies the Msg address into A0
           TRAP        #15
           DC.W        7               ; Displays Msg to console
           RTE
MSG        DC.B        'DIVIDED BY ZERO!'
