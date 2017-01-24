.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC
    MOV AH,1
    
    INT 21H
    MOV BL,AL         ;first input, but in ascii value
    
    INT 21H
    MOV CL,AL         ;second input, also in ascii value
                       
    ADD BL,CL         ;addintion, but output in ascii
    SUB BL,48         ;convering in int
    
    MOV AH,2 
    MOV DL,BL
    INT 21H
    

   MOV AH,4CH
   INT 21H
   MAIN ENDP
END MAIN
    