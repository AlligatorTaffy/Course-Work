; Homework Assignment #3 Problem 3
; Handle Exception Errors
; Assembly for Motorola 68000

BUSERR     EQU         $08
ADDERR     EQU         $0C
ILLERR     EQU         $10
DIVERR     EQU         $14

           ORG         $900             ; Start location of program
           MOVEA.B     $7000,A7         ; Assign user stack
           MOVE.L      #BUSERRp,BUSERR  ; Set Exception subroutine
           MOVE.L      #ADDERRp,ADDERR  ; Set Exceptoin subroutine
           MOVE.L      #ILLERRp,ILLERR  ; Set Exception subroutine
           MOVE.L      #DIVERRp,DIVERR  ; Set Exception subroutine
           CLR.L       D0               ; Clear D0
           CLR.L       D1               ; Clear D1

BUS        MOVE.B      ($FFFFF),D0     ; Bus error reaching outside of memory
ADD        MOVE.W      D0,($6003)      ; Address error moving word to odd address
ILL        DC.W        $4AFC           ; Illegal Instruction
DIV        CLR.L       D0
           CLR.L       D1
           DIVU        D0,D1           ; Divide by zero error

           TRAP        #15
           DC.W        0


BUSERRp    LEA         MSG1,A0         ; Move address bus error message to A0
           TRAP        #15             ; Call TRAP
           DC.W        7               ; Display message
           RTE

ADDERRp    LEA         MSG2,A0         ; Move address of address error message to A0
           TRAP        #15             ; Call TRAP
           DC.W        7               ; Display message
           RTE

ILLERRp    LEA         MSG3,A0         ; Move address illegal instruction to A0
           TRAP        #15             ; Call TRAP
           DC.W        7               ; Display message
           RTE

DIVERRp    LEA         MSG4,A0         ; Move address divide error message to A0
           TRAP        #15             ; Call TRAP
           DC.W        7               ; Display message
           RTE

MSG1       DC.B        'BUS ERROR!',0  ; Message for bus error
MSG2       DC.B        'ADDRESS ERROR!',0   ; Message for address error
MSG3       DC.B        'ILLEGAL INSTRUCTION',0   ; Message for illegal instruction
MSG4       DC.B        'DIVIDE BY ZERO!',0   ; Message for dividing by zero