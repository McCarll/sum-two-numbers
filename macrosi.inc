	
macroSetReg	macro			;��������� ������� ���������
		mov	ax,data
		mov	ds,ax
		mov	ax,data1
		mov	es,ax
		mov	ax,3
		int	10h

endM

macroVvod	macro	mes,chislo		; ���������������� ��� ����� ����� 
	local	vvu,perehod,ccc,next,hhh1,

		mov 	ah,9 		;mes - ��������� ��������� �� �����, num - ���� ��������� �����, prop- ������� �� ����� ������	 
		mov 	dx,offset mes		
	int 	21h 

		mov	dx,offset num1		
		mov	ah,0Ah		
		mov	al,0dh
	int	21h
	
	IFB	<prop>
		
	else
		mov	ah,9
		mov	dx,offset prop	
	int	21h	
		mov	si,0
	ENDIF
		mov     al,num1+2(si); �������� ����� �� ���? num2 - � ����� ������� ��������
		cmp	al,30h
	jge	vvu	
	jmp	perehod
	
	vvu:
		cmp	num1+2,39h
	jle	next
	
perehod:
		exit			; exit - ���������������� ����������� ��������� ������ 

next:
		mov	cl,num1+1
		mov	num2+1,cl

				; num1 - ������ ����� ����� num2- ���� ������� ����� 
	ccc:						
		mov	al,num1+2(si)		
		mov	bl,num1+2(si)
		xor	bl,030h
		mov	num2+2(si),bl
		inc	si
	loop	ccc

						;num1 - ������ ����� ����� chislo - ���� ��� ������� 
		mov	cl,num2+1		; ���������������� ����� 
		mov	CH,0
		mov	DI,CX
		dec	DI
		mov	si,0
		mov	ah,0



	hhh1:		mov	al,num2+2(si)		; ������� 
		mul	cmul(DI)
		add	chislo,ax
		inc	si
		dec	DI
	loop	hhh1
	
endM

exit	macro
	local	metka
metka:
		mov	ax,offset metka
		mov	adrmis,ax
		mov	ah,04ch
		int	21h
endm	

	
macroSum	macro	num1,num2,summa,save	; �������� 
		mov	ax,num1		; num1-������ ������� ,num2-������ ������� ,summa-����� ����� ,save-���� ������� ��������� 
		add	summa,ax
		mov	ax,num2
		add	summa,ax


		mov	ax,summa
	
		mov	si,0

	
lll:		mov	dx,0			; ������ � ������ �������� 
		mov	cx,0Ah
		div	cx
		add	dl,030h			
	
		mov	save(si),dl
		inc	si
	
		cmp	ax,0h
	je	vyvod
	jmp	lll1


lll1:		mov	dx,0			; ������ �� ������  �������� 
		mov	cx,0Ah
		div	cx
		add	dl,030h

	
		mov	save(si),dl
		inc	si
	
		cmp	ax,0h
	je	vyvod
	jmp	lll2


lll2:		mov	dx,0			; ������ � ������� �������� 
		mov	cx,0Ah
		div	cx
		add	dl,030h

	
		mov	save(si),dl
		inc	si
	
		cmp	ax,0h
	je	vyvod
	jmp	lll
endM



macroVivod	macro	num1,num2				; ����� ���������� �� �����

		mov	cx,si
		mov	di,0
		dec	si



	xxx:	mov	al,num1(si)
		mov	num2(di),al
		inc	di
		dec	si
	loop	xxx

		

		mov	al,0dh 
		mov	num2(di),al

		inc 	di
		mov	al,0ah
		mov	num2(di),al

		inc	di
		mov	al,"$"
		mov	num2(di),al

		mov	ah,9		
		mov	dx,offset num2
		int	21h	

endM	


macroExit	macro
	mov 	ah,1
	int 	21h
	mov 	ah,04ch
	int 	21h
endM