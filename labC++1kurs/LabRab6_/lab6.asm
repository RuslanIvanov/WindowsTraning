	.586p
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "lab6.cpp"
	?debug	T "lab6.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BTYPES	segment byte public use32 'DEBTYP'
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
$$BNAMES	ends
$$BROWSE	segment byte public use32 'DEBSYM'
$$BROWSE	ends
$$BROWFILE	segment byte public use32 'DEBSYM'
$$BROWFILE	ends
DGROUP	group	_BSS,_DATA
_DATA	segment dword public use32 'DATA'
	align	4
$ikpieaia	label	dword
	dd	s@
	dd	s@+6
	dd	s@+25
	dd	s@+43
	dd	s@+61
	dd	s@+87
	dd	s@+115
	dd	s@+123
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_main	proc	near
?live1@0:
	?debug L 16
	push      ebp
	mov       ebp,esp
	add       esp,-48
	push      ebx
	push      esi
	push      edi
	?debug L 26
@1:
	mov       esi,offset $ikpieaia
	lea       edi,dword ptr [ebp-32]
	mov       ecx,8
	rep   movsd
	?debug L 36
	mov       byte ptr [ebp-33],0
	?debug L 39
	mov       dword ptr [ebp-44],2
	?debug L 40
	mov       dword ptr [ebp-40],2
	?debug L 41
	xor       esi,esi
	?debug L 43
?live1@96: ; ESI = n_record_mem
	imul      eax,dword ptr [ebp-44],76
	push      eax
	call      @$bnwa$qui
	pop       ecx
	mov       ebx,eax
	?debug L 44
?live1@112: ; EBX = pb, ESI = n_record_mem
	mov       eax,dword ptr [ebp-44]
	shl       eax,2
	push      eax
	call      @$bnwa$qui
	pop       ecx
	mov       dword ptr [ebp-48],eax
	?debug L 45
@2:
	xor       eax,eax
	jmp       short @4
	?debug L 47
?live1@144: ; EAX = i, EBX = pb, ESI = n_record_mem
@3:
	mov       edx,eax
	imul      edx,dword ptr [ebp-44]
	imul      ecx,edx,76
	add       ecx,ebx
	mov       edx,dword ptr [ebp-48]
	mov       dword ptr [edx+4*eax],ecx
	?debug L 45
@5:
@6:
	inc       eax
@4:
	mov       ecx,dword ptr [ebp-44]
	cmp       eax,ecx
	jl        short @3
	?debug L 49
?live1@176: ; ESI = n_record_mem
	push      offset s@+145
	call      _printf
	pop       ecx
	jmp       @8
	?debug L 53
@7:
	push      8
	lea       eax,dword ptr [ebp-32]
	push      eax
	call      @PrintMENU$qppxcxi
	add       esp,8
	?debug L 54
	push      dword ptr [__streams]
	call      _fflush
	pop       ecx
	?debug L 55
	lea       eax,dword ptr [ebp-33]
	push      eax
	push      offset s@+168
	call      _scanf
	add       esp,8
	?debug L 56
	movsx     edx,byte ptr [ebp-33]
	add       edx,-49
	cmp       edx,8
	ja        @9
	jmp       dword ptr [@17+4*edx]
@17:
	dd        @16
	dd        @15
	dd        @14
	dd        @13
	dd        @12
	dd        @9
	dd        @9
	dd        @9
	dd        @11
	?debug L 59
@16:
	push      offset s@+171
	call      _printf
	pop       ecx
	?debug L 60
	push      esi
	push      dword ptr [ebp-48]
	call      @PrintfStruct$qpp4BOOKi
	add       esp,8
	?debug L 62
	jmp       short @18
	?debug L 64
?live1@304: ; 
@15:
	push      offset s@+185
	call      _printf
	pop       ecx
	?debug L 66
	lea       ecx,dword ptr [ebp-48]
	push      ecx
	call      @EnterBook$qp4KART
	pop       ecx
	mov       esi,eax
	?debug L 68
?live1@336: ; ESI = n_record_mem
	jmp       short @18
	?debug L 70
@14:
	push      offset s@+202
	call      _printf
	pop       ecx
	?debug L 72
	jmp       short @18
	?debug L 74
@13:
	push      offset s@+213
	call      _printf
	pop       ecx
	?debug L 75
	jmp       short @18
	?debug L 77
@12:
	push      offset s@+222
	call      _printf
	pop       ecx
	?debug L 80
	jmp       short @18
	?debug L 82
@11:
	push      offset s@+231
	call      _printf
	pop       ecx
	?debug L 83
	jmp       short @18
	?debug L 84
@9:
	push      offset s@+243
	call      _printf
	pop       ecx
	?debug L 51
@10:
@18:
@8:
	movsx     eax,byte ptr [ebp-33]
	cmp       eax,57
	jne       @7
	?debug L 90
?live1@512: ; 
 	nop	
	?debug L 137
@19:
	pop       edi
	pop       esi
	pop       ebx
	mov       esp,ebp
	pop       ebp
	ret 
	?debug L 0
_main	endp
_TEXT	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	db	1
	db	0
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	db	2
	db	0
	db	0
	db	0
	dw	52
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch1
	dd	?patch2
	dd	?patch3
	df	_main
	dw	0
	dw	4096
	dw	0
	dw	1
	dw	0
	dd	?patch4
	db	5
	db	95
	db	109
	db	97
	db	105
	db	110
	dw	16
	dw	2
	dw	4098
	dw	0
	dw	20
	dw	12
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	43
	db	1
	db	47
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	4
	dw	0
	dw	?patch5
	dw	529
	dw	?patch6
	dd	?live1@112-_main
	dd	?live1@176-?live1@112
	dw	20
?patch6	equ	1
?patch5	equ	14
	dw	16
	dw	2
	dw	116
	dw	0
	dw	23
	dw	13
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	41
	db	1
	db	60
	db	6
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	17
	dw	0
	dw	?patch7
	dw	529
	dw	?patch8
	dd	?live1@96-_main
	dd	?live1@304-?live1@96
	dw	23
	dd	?live1@336-_main
	dd	?live1@512-?live1@336
	dw	23
?patch8	equ	2
?patch7	equ	24
	dw	18
	dw	512
	dw	65488
	dw	65535
	dw	4103
	dw	0
	dw	14
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	38
	db	1
	db	39
	db	1
	db	3
	db	1
	db	1
	db	2
	db	13
	db	6
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	31
	dw	0
	dw	16
	dw	2
	dw	112
	dw	0
	dw	1
	dw	15
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	37
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	51
	dw	0
	dw	18
	dw	512
	dw	65503
	dw	65535
	dw	112
	dw	0
	dw	16
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	36
	db	1
	db	51
	db	4
	db	1
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	61
	dw	0
	dw	16
	dw	2
	dw	4106
	dw	0
	dw	17
	dw	17
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	35
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	76
	dw	0
	dw	18
	dw	512
	dw	65504
	dw	65535
	dw	4107
	dw	0
	dw	18
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	26
	db	1
	db	35
	db	18
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	86
	dw	0
	dw	24
	dw	519
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch9
	df	@2
	dw	0
	dw	0
	dw	16
	dw	2
	dw	116
	dw	0
	dw	17
	dw	19
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	45
	db	1
	db	45
	db	2
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	100
	dw	0
	dw	?patch10
	dw	529
	dw	?patch11
	dd	?live1@144-_main
	dd	?live1@176-?live1@144
	dw	17
?patch11	equ	1
?patch10	equ	14
?patch9	equ	@5-@2
	dw	2
	dw	6
?patch1	equ	@19-_main+7
?patch2	equ	0
?patch3	equ	@19-_main
	dw	2
	dw	6
	dw	8
	dw	531
	dw	7
	dw	65476
	dw	65535
$$BSYMS	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	;	s@+0:
	db	"MENU:",0
	;	s@+6:
	db	"[1]Print kartoteka",0
	;	s@+25:
	db	"[2]Enter new book",0
	;	s@+43:
	db	"[3]Delete book(s)",0
	;	s@+61:
	db	"[4]Save kartoteka to file",0
	;	s@+87:
	db	"[5]Read kartoteka from file",0
	;	s@+115:
	db	"[9]Exit",0
	;	s@+123:
	db	"Please enter number: ",0,10
	;	s@+146:
	db	"***Kartoteka knig***",10,0
	;	s@+168:
	db	"%c",0,10
	;	s@+172:
	db	"Print BOOKs:",0,10
	;	s@+186:
	db	"Enter new book:",0,10
	;	s@+203:
	db	"DELETE...",0,10
	;	s@+214:
	db	"SAVE...",0,10
	;	s@+223:
	db	"READ...",0,10
	;	s@+232:
	db	"***Exit***",0,10
	;	s@+244:
	db	"Error number",0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
	?debug	C FB04095F5F73747265616D7301000000
	?debug	C FB04075F7072696E746602000000
	?debug	C FB04075F66666C75736802000000
	?debug	C FB04065F7363616E6602000000
	extrn	__streams:dword
	public	_main
	extrn	@$bnwa$qui:near
	extrn	_printf:near
	extrn	@PrintMENU$qppxcxi:near
	extrn	_fflush:near
	extrn	_scanf:near
	extrn	@PrintfStruct$qpp4BOOKi:near
	extrn	@EnterBook$qp4KART:near
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	16
	dw	4
	dw	116
	dw	0
	dw	0
	dw	30
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	3
	dw	42
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	114
	dw	0
	dw	16
	dw	4
	dw	117
	dw	0
	dw	0
	dw	31
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	3
	dw	48
	db	6
	db	63
	db	6
	db	2
	db	1
	db	1
	db	5
	db	3
	db	4
	db	1
	db	5
	db	3
	db	2
	db	2
	db	1
	db	4
	db	2
	db	2
	db	2
	db	2
	db	1
	db	13
	db	2
	db	7
	db	1
	db	10
	db	1
	db	2
	db	1
	db	25
	db	2
	db	2
	db	1
	db	8
	db	2
	db	2
	db	2
	db	1
	db	102
	db	3
	db	2
	db	6
	db	3
	db	2
	db	255
	db	2
	dw	524
	db	48
	db	1
	db	255
	db	8
	dw	322
	db	11
	db	34
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	124
	dw	0
	dw	16
	dw	4
	dw	113
	dw	0
	dw	0
	dw	32
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	3
	dw	62
	db	8
	db	254
	dw	310
	db	9
	db	61
	db	25
	db	2
	db	2
	db	2
	db	9
	db	2
	db	20
	db	2
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	191
	dw	0
	dw	16
	dw	4
	dw	112
	dw	0
	dw	0
	dw	33
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	38
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	216
	dw	0
	dw	16
	dw	4
	dw	16
	dw	0
	dw	0
	dw	34
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	39
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	226
	dw	0
	dw	16
	dw	4
	dw	32
	dw	0
	dw	0
	dw	35
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	40
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	236
	dw	0
	dw	16
	dw	4
	dw	112
	dw	0
	dw	0
	dw	36
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	41
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	246
	dw	0
	dw	16
	dw	4
	dw	116
	dw	0
	dw	0
	dw	37
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	42
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	256
	dw	0
	dw	16
	dw	4
	dw	18
	dw	0
	dw	0
	dw	38
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	7
	dw	69
	db	7
	db	254
	dw	287
	db	2
	db	254
	dw	430
	db	2
	db	254
	dw	608
	db	2
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	266
	dw	0
	dw	16
	dw	4
	dw	18
	dw	0
	dw	0
	dw	39
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	7
	dw	70
	db	7
	db	254
	dw	287
	db	254
	dw	431
	db	254
	dw	609
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	290
	dw	0
	dw	16
	dw	4
	dw	18
	dw	0
	dw	0
	dw	40
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	63
	db	8
	db	254
	dw	311
	db	20
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	311
	dw	0
	dw	16
	dw	4
	dw	4112
	dw	0
	dw	1
	dw	41
	dw	0
	dw	0
	dw	0
	dw	16
	dw	4
	dw	4112
	dw	0
	dw	0
	dw	42
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	269
	db	8
	db	254
	dw	284
	db	13
	db	9
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	2
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	1
	db	2
	db	5
	db	7
	db	3
	db	13
	db	3
	db	1
	db	10
	db	3
	db	1
	db	1
	db	2
	db	8
	db	2
	db	11
	db	1
	db	5
	db	1
	db	1
	db	1
	db	1
	db	3
	db	1
	db	5
	db	1
	db	10
	db	1
	db	6
	db	1
	db	1
	db	1
	db	4
	db	3
	db	5
	db	1
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	327
	dw	0
	dw	16
	dw	4
	dw	4099
	dw	0
	dw	1
	dw	43
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	1
	db	10
	db	9
	db	7
	db	2
	db	255
	db	1
	dw	43
	db	1
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	404
	dw	0
	dw	16
	dw	4
	dw	4103
	dw	0
	dw	1
	dw	44
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	8
	db	10
	db	17
	db	255
	db	1
	dw	38
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	424
	dw	0
	dw	?patch12
	dw	1
	db	2
	db	1
	db	8
	db	24
	db	6
	db	66
	db	67
	db	52
	db	46
	db	48
	db	48
?patch12	equ	13
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	2
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	3
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	4
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	5
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	6
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	9
	db	1
	db	44
	db	3
	db	13
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	10
	db	1
	db	39
	db	4
	db	1
	db	1
	db	2
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	10
	dw	11
	db	1
	db	40
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	260
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	261
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	262
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	263
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	264
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	265
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	266
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	267
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	8
	dw	268
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	16
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
?patch4	equ	626
$$BSYMS	ends
$$BROWFILE	segment byte public use32 'DEBSYM'
	dw	45
	dw	0
	dw	46
	dw	0
	dw	47
	dw	0
	dw	48
	dw	0
	dw	49
	dw	0
	dw	50
	dw	0
	dw	51
	dw	0
	dw	52
	dw	0
	dw	53
	dw	0
	dw	54
	dw	0
$$BROWFILE	ends
$$BTYPES	segment byte public use32 'DEBTYP'
	db        2,0,0,0,14,0,8,0,3,0,0,0,0,0,0,0
	db        1,16,0,0,4,0,1,2,0,0,8,0,2,0,10,0
	db        3,16,0,0,28,0,5,0,5,0,6,16,0,0,0,0
	db        0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0
	db        76,0,18,0,3,0,112,0,0,0,17,0,0,0,0,0
	db        0,0,30,0,30,0,18,0,3,0,112,0,0,0,17,0
	db        0,0,0,0,0,0,30,0,30,0,100,0,4,2,6,4
	db        4,16,0,0,3,0,3,0,0,0,185,1,0,0,0,0
	db        242,241,6,4,5,16,0,0,3,0,4,0,0,0,195,1
	db        0,0,30,0,242,241,6,4,116,0,0,0,3,0,5,0
	db        0,0,205,1,0,0,60,0,242,241,6,4,116,0,0,0
	db        3,0,6,0,0,0,215,1,0,0,64,0,242,241,6,4
	db        65,0,0,0,3,0,7,0,0,0,225,1,0,0,68,0
	db        28,0,5,0,3,0,9,16,0,0,0,0,0,0,0,0
	db        0,0,0,0,0,0,0,0,8,0,0,0,12,0,8,0
	db        2,0,10,0,2,16,0,0,60,0,4,2,6,4,8,16
	db        0,0,3,0,9,0,0,0,235,1,0,0,0,0,242,241
	db        6,4,116,0,0,0,3,0,10,0,0,0,250,1,0,0
	db        4,0,242,241,6,4,116,0,0,0,3,0,11,0,0,0
	db        11,2,0,0,8,0,8,0,1,0,1,0,116,0,0,0
	db        18,0,3,0,12,16,0,0,17,0,0,0,0,0,0,0
	db        32,0,8,0,8,0,2,0,10,0,13,16,0,0,8,0
	db        1,0,1,0,112,0,0,0,8,0,2,0,10,0,15,16
	db        0,0,18,0,3,0,16,16,0,0,17,0,0,0,0,0
	db        0,0,0,0,0,0,28,0,5,0,9,0,17,16,0,0
	db        0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0
	db        0,0,24,0,180,0,4,2,6,4,32,4,0,0,3,0
	db        21,0,0,0,24,2,0,0,0,0,242,241,6,4,32,4
	db        0,0,3,0,22,0,0,0,34,2,0,0,4,0,242,241
	db        6,4,116,0,0,0,3,0,23,0,0,0,44,2,0,0
	db        8,0,242,241,6,4,116,0,0,0,3,0,24,0,0,0
	db        54,2,0,0,12,0,242,241,6,4,33,0,0,0,3,0
	db        25,0,0,0,64,2,0,0,16,0,242,241,6,4,33,0
	db        0,0,3,0,26,0,0,0,74,2,0,0,18,0,242,241
	db        6,4,113,0,0,0,3,0,27,0,0,0,84,2,0,0
	db        20,0,242,241,6,4,112,0,0,0,3,0,28,0,0,0
	db        94,2,0,0,22,0,242,241,6,4,32,0,0,0,3,0
	db        29,0,0,0,104,2,0,0,23,0,14,0,8,0,3,4
	db        0,0,0,0,1,0,19,16,0,0,8,0,1,2,1,0
	db        117,0,0,0,14,0,8,0,116,0,0,0,64,0,2,0
	db        21,16,0,0,12,0,1,2,2,0,12,16,0,0,0,0
	db        0,0,14,0,8,0,3,0,0,0,0,0,2,0,24,16
	db        0,0,8,0,2,0,10,0,12,16,0,0,12,0,1,2
	db        2,0,23,16,0,0,10,16,0,0,14,0,8,0,116,0
	db        0,0,0,0,1,0,27,16,0,0,8,0,2,0,10,0
	db        16,16,0,0,8,0,1,2,1,0,26,16,0,0,14,0
	db        8,0,116,0,0,0,64,0,2,0,29,16,0,0,12,0
	db        1,2,2,0,12,16,0,0,0,0,0,0,14,0,8,0
	db        3,0,0,0,0,0,2,0,31,16,0,0,12,0,1,2
	db        2,0,8,16,0,0,116,0,0,0,14,0,8,0,116,0
	db        0,0,0,0,1,0,34,16,0,0,8,0,2,0,10,0
	db        7,16,0,0,8,0,1,2,1,0,33,16,0,0
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
	db	4,'main'
	db	4,'BOOK'
	db	4,'Name'
	db	8,'NameBook'
	db	4,'Year'
	db	3,'kat'
	db	4,'cena'
	db	4,'KART'
	db	7,'pMasAdr'
	db	8,'n_record'
	db	3,'rez'
	db	2,'pb'
	db	12,'n_record_mem'
	db	4,'kart'
	db	5,'ch_sw'
	db	2,'ch'
	db	4,'Nstr'
	db	6,'ArMenu'
	db	1,'i'
	db	4,'FILE'
	db	4,'curp'
	db	6,'buffer'
	db	5,'level'
	db	5,'bsize'
	db	6,'istemp'
	db	5,'flags'
	db	4,'hold'
	db	2,'fd'
	db	5,'token'
	db	9,'ptrdiff_t'
	db	6,'size_t'
	db	6,'wint_t'
	db	6,'_TCHAR'
	db	7,'_TSCHAR'
	db	7,'_TUCHAR'
	db	7,'_TXCHAR'
	db	5,'_TINT'
	db	9,'streampos'
	db	9,'streamoff'
	db	6,'fpos_t'
	db	4,'__CA'
	db	4,'FILE'
	db	4,'BOOK'
	db	4,'KART'
	db	8,'lab6.cpp'
	db	22,'C:\BC5\INCLUDE\TCHAR.H'
	db	23,'C:\BC5\INCLUDE\stddef.h'
	db	22,'C:\BC5\INCLUDE\_defs.h'
	db	22,'C:\BC5\INCLUDE\_null.h'
	db	23,'C:\BC5\INCLUDE\string.h'
	db	25,'C:\BC5\INCLUDE\IOSTREAM.h'
	db	22,'C:\BC5\INCLUDE\STDIO.H'
	db	23,'C:\BC5\INCLUDE\_nfile.h'
	db	6,'BOOK.H'
$$BNAMES	ends
	?debug	D "BOOK.H" 14033 6255
	?debug	D "C:\BC5\INCLUDE\_nfile.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\STDIO.H" 8825 10304
	?debug	D "C:\BC5\INCLUDE\IOSTREAM.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\string.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\_null.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\_defs.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\stddef.h" 8825 10304
	?debug	D "C:\BC5\INCLUDE\TCHAR.H" 8825 10304
	?debug	D "lab6.cpp" 14034 19123
	end
