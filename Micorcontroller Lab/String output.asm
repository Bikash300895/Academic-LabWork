.MODEL SMALL 
.STACK 100H

.DATA
MSG1 DB 'BIKASH $'
MSG2 DB 'ROY $'

.CODE
MAIN PROC
    MOV AX,@DATA                 ;initializing data segment
    MOV DS,AX
    
    LEA DX,MSG1                  ;Load effective address
    MOV AH,9
    INT 21H
    
    MOV AH,2
    MOV DL,13
    INT 21H
    MOV DL,10
    INT 21H
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    

   MOV DX, 4CH
   INT 21H
   MAIN ENDP
END MAIN