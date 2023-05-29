; Homework Assignment #2
; Counting and Moving Values
; Assembly for Motorola 68000

		ORG 	$2000       ;Place the origin at $2000

		MOVE.L	#101,$A00	; Move the initial n value 100 > n > 127 
		CLR.L	D0			; Clear D0
		CLR.L	D1			; Clear	D1
		CLR.L	D2			; Clear D2
		MOVE.L	#25,D2		; Copy #25 into D2 as a counter
		MOVE.L	$A00,D0		; Copy value at $A00 to D0
LOOP	ADD.L	D0,D1		; Add contents of D0 to D1
		ADD.L	#1,D0		; Add #1 to contents of D0
		SUB.L	#1,D2		; Subtract #1 from our D2 counter
		BNE		LOOP		; Compare value of D2 to 0 to test loop
		MOVE.L	D1,$B00		; Copy results from D1 to memory located at $B00
		TRAP 	#15
		DC.W	0