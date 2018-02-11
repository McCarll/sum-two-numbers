	;INCLUDE	BIBLML.INC	;библиотека общих макросов
	;INCLUDE	consfs.INC		;константы опред.работу программы
	include		macrosi.inc


m9	macro	m91				; вывод сообщения 
		mov 	ah,9 			 
		mov 	dx,offset m91		
	int 	21h 
endM
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
data1	segment	para public "data1"	;сегмент данных
WARE	dw	0
data1	ends
;*****************
data	segment	para public "data"	;сегмент данных

Message1	db	'GIVE NUMBER one:',0dh,0ah,'$'
Message2	db	'GIVE NUMBER two:',0dh,0ah,'$'

prop	db	0dh,0ah,'$'	

temp1	dw	0
temp2	dw	0
BUFPR	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?
num1	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?
num2	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?
num2pub	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?
BUFpr1	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?
BUFpr2	db	5
	db	0
	db	?
	db	?
	db	?
	db	?
	db	?

vivod	db	?

cmul	db	1
	db	0Ah
	db	064h

sum	dw	0
num10	dw	0
num20	dw	0

adrmis	dw	0
data	ends
;*****************
stk	segment	stack
		db	256 dup ("?")	;сегмент стека
stk	ends
;**************************************************************************
code	segment	para public "code"	;начало сегмента кода 
main	proc				;начало процедуры main
	assume cs:code, ds:data,es:data1,ss:stk

	macroSetReg
	
	macroVvod	Message1,num10

	macroVvod	Message2,num20

	macroSum	num10,num20,sum,BUFpr1
vyvod:
	macroVivod	BUFpr1,vivod

	macroExit

main	endp				;конец процедуры main
code	ends				;конец сегмента  код 
end	main				;конец программы с точкой входа  main



