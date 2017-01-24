.MODEL SMALL
.STACK 100H

.DATA
VAR1 DB 5   
VAR2 DB ?   ;UNINITIALIZED VARIABLE

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
                                   
    MOV AH,1    ;INPUT FUNCTION
    INT 21H
    MOV VAR2,AL                                   
                                   
    MOV AH,2
    MOV DL,VAR1 
    ADD DL,48
    INT 21H
    
    MOV DL,VAR2
    INT 21H
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN