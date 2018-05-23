#include <iostream>
#include "vm.h"


/*
 - op1 = op1 + op2
 - mov result to op1
 - op1 must be a Register
 - op2 can be a Register or 1byte data
*/
void Custom_CPU::_add(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax += reg.eax;
		else if (op2 == EBX)
			reg.eax += reg.ebx;
		else if (op2 == ECX)
			reg.eax += reg.ecx;
		else if (op2 == EDX)
			reg.eax += reg.edx;
		else if (op2 == SP)
			reg.eax += (GR)reg.sp;
		else if (op2 == PC)
			reg.eax += (GR)reg.pc;
		else
			reg.eax += op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx += reg.eax;
		else if (op2 == EBX)
			reg.ebx += reg.ebx;
		else if (op2 == ECX)
			reg.ebx += reg.ecx;
		else if (op2 == EDX)
			reg.ebx += reg.edx;
		else if (op2 == SP)
			reg.ebx += (GR)reg.sp;
		else if (op2 == PC)
			reg.ebx += (GR)reg.pc;
		else
			reg.ebx += op2;
		break;
	case ECX:
		if (op2 == EAX)
			reg.ecx += reg.eax;
		else if (op2 == EBX)
			reg.ecx += reg.ebx;
		else if (op2 == ECX)
			reg.ecx += reg.ecx;
		else if (op2 == EDX)
			reg.ecx += reg.edx;
		else if (op2 == SP)
			reg.ecx += (GR)reg.sp;
		else if (op2 == PC)
			reg.ecx += (GR)reg.pc;
		else
			reg.ecx += op2;
		break;
	case EDX:
		if (op2 == EAX)
			reg.edx += reg.eax;
		else if (op2 == EBX)
			reg.edx += reg.ebx;
		else if (op2 == ECX)
			reg.edx += reg.ecx;
		else if (op2 == EDX)
			reg.edx += reg.edx;
		else if (op2 == SP)
			reg.edx += (GR)reg.sp;
		else if (op2 == PC)
			reg.edx += (GR)reg.pc;
		else
			reg.edx += op2;
		break;
	case SP:
		if (op2 == EAX)
			reg.sp += reg.eax;
		else if (op2 == EBX)
			reg.sp += reg.ebx;
		else if (op2 == ECX)
			reg.sp += reg.ecx;
		else if (op2 == EDX)
			reg.sp += reg.edx;
		else if (op2 == SP)
			reg.sp += (GR)reg.sp;
		else if (op2 == PC)
			reg.sp += (GR)reg.pc;
		else
			reg.sp += op2;
		break;
	case PC:
		if (op2 == EAX)
			reg.pc += reg.eax;
		else if (op2 == EBX)
			reg.pc += reg.ebx;
		else if (op2 == ECX)
			reg.pc += reg.ecx;
		else if (op2 == EDX)
			reg.pc += reg.edx;
		else if (op2 == SP)
			reg.pc += (GR)reg.sp;
		else if (op2 == PC)
			reg.pc += (GR)reg.pc;
		else
			reg.pc += op2;
		break;
	default:
		//printf("Something Wrong in _add\n");
		break;
	}
}


/*
- op1 = op1 - op2
- mov result to op1
- op1 must be a Register
- op2 can be a Register or 1byte data
*/
void Custom_CPU::_sub(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax -= reg.eax;
		else if (op2 == EBX)
			reg.eax -= reg.ebx;
		else if (op2 == ECX)
			reg.eax -= reg.ecx;
		else if (op2 == EDX)
			reg.eax -= reg.edx;
		else if (op2 == SP)
			reg.eax -= (GR)reg.sp;
		else if (op2 == PC)
			reg.eax -= (GR)reg.pc;
		else
			reg.eax -= op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx -= reg.eax;
		else if (op2 == EBX)
			reg.ebx -= reg.ebx;
		else if (op2 == ECX)
			reg.ebx -= reg.ecx;
		else if (op2 == EDX)
			reg.ebx -= reg.edx;
		else if (op2 == SP)
			reg.ebx -= (GR)reg.sp;
		else if (op2 == PC)
			reg.ebx -= (GR)reg.pc;
		else
			reg.ebx -= op2;
		break;
	case ECX:
		if (op2 == EAX)
			reg.ecx -= reg.eax;
		else if (op2 == EBX)
			reg.ecx -= reg.ebx;
		else if (op2 == ECX)
			reg.ecx -= reg.ecx;
		else if (op2 == EDX)
			reg.ecx -= reg.edx;
		else if (op2 == SP)
			reg.ecx -= (GR)reg.sp;
		else if (op2 == PC)
			reg.ecx -= (GR)reg.pc;
		else
			reg.ecx -= op2;
		break;
	case EDX:
		if (op2 == EAX)
			reg.edx -= reg.eax;
		else if (op2 == EBX)
			reg.edx -= reg.ebx;
		else if (op2 == ECX)
			reg.edx -= reg.ecx;
		else if (op2 == EDX)
			reg.edx -= reg.edx;
		else if (op2 == SP)
			reg.edx -= (GR)reg.sp;
		else if (op2 == PC)
			reg.edx -= (GR)reg.pc;
		else
			reg.edx -= op2;
		break;
	case SP:
		if (op2 == EAX)
			reg.sp -= reg.eax;
		else if (op2 == EBX)
			reg.sp -= reg.ebx;
		else if (op2 == ECX)
			reg.sp -= reg.ecx;
		else if (op2 == EDX)
			reg.sp -= reg.edx;
		else if (op2 == SP)
			reg.sp -= (GR)reg.sp;
		else if (op2 == PC)
			reg.sp -= (GR)reg.pc;
		else
			reg.sp -= op2;
		break;
	case PC:
		if (op2 == EAX)
			reg.pc -= reg.eax;
		else if (op2 == EBX)
			reg.pc -= reg.ebx;
		else if (op2 == ECX)
			reg.pc -= reg.ecx;
		else if (op2 == EDX)
			reg.pc -= reg.edx;
		else if (op2 == SP)
			reg.pc -= (GR)reg.sp;
		else if (op2 == PC)
			reg.pc -= (GR)reg.pc;
		else
			reg.pc -= op2;
		break;
	default:
		//printf("Something Wrong in _sub\n");
		break;
	}
}


/*
- op1 = op1 ^ op2
- mov result to op1
- op1 must be EAX or EBX
- op2 can be a Register or 1byte data
*/
void Custom_CPU::_xor(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax ^= reg.eax;
		else if (op2 == EBX)
			reg.eax ^= reg.ebx;
		else if (op2 == ECX)
			reg.eax ^= reg.ecx;
		else if (op2 == EDX)
			reg.eax ^= reg.edx;
		else if (op2 == SP)
			reg.eax ^= (GR)reg.sp;
		else if (op2 == PC)
			reg.eax ^= (GR)reg.pc;
		else
			reg.eax ^= op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx ^= reg.eax;
		else if (op2 == EBX)
			reg.ebx ^= reg.ebx;
		else if (op2 == ECX)
			reg.ebx ^= reg.ecx;
		else if (op2 == EDX)
			reg.ebx ^= reg.edx;
		else if (op2 == SP)
			reg.ebx ^= (GR)reg.sp;
		else if (op2 == PC)
			reg.ebx ^= (GR)reg.pc;
		else
			reg.ebx ^= op2;
		break;
	case ECX:
		if (op2 == EAX)
			reg.ecx ^= reg.eax;
		else if (op2 == EBX)
			reg.ecx ^= reg.ebx;
		else if (op2 == ECX)
			reg.ecx ^= reg.ecx;
		else if (op2 == EDX)
			reg.ecx ^= reg.edx;
		else if (op2 == SP)
			reg.ecx ^= (GR)reg.sp;
		else if (op2 == PC)
			reg.ecx ^= (GR)reg.pc;
		else
			reg.ecx ^= op2;
		break;
	case EDX:
		if (op2 == EAX)
			reg.edx ^= reg.eax;
		else if (op2 == EBX)
			reg.edx ^= reg.ebx;
		else if (op2 == ECX)
			reg.edx ^= reg.ecx;
		else if (op2 == EDX)
			reg.edx ^= reg.edx;
		else if (op2 == SP)
			reg.edx ^= (GR)reg.sp;
		else if (op2 == PC)
			reg.edx ^= (GR)reg.pc;
		else
			reg.edx ^= op2;
		break;
	default:
		//printf("Something Wrong in _xor\n");
		break;
	}
}


/*
 - op1 = op2
 - mov op2 to op1
 - op1 must be a Register
 - op2 can be a Register or 1byte data
*/
void Custom_CPU::_mov(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax = reg.eax;
		else if (op2 == EBX)
			reg.eax = reg.ebx;
		else if (op2 == ECX)
			reg.eax = reg.ecx;
		else if (op2 == EDX)
			reg.eax = reg.edx;
		else if (op2 == SP)
			reg.eax = (GR)reg.sp;
		else if (op2 == PC)
			reg.eax = 0;//(GR)reg.pc;
		else
			reg.eax = op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx = reg.eax;
		else if (op2 == EBX)
			reg.ebx = reg.ebx;
		else if (op2 == ECX)
			reg.ebx = reg.ecx;
		else if (op2 == EDX)
			reg.ebx = reg.edx;
		else if (op2 == SP)
			reg.ebx = (GR)reg.sp;
		else if (op2 == PC)
			reg.ebx = (GR)reg.pc;
		else
			reg.ebx = op2;
		break;
	case ECX:
		if (op2 == EAX)
			reg.ecx = reg.eax;
		else if (op2 == EBX)
			reg.ecx = reg.ebx;
		else if (op2 == ECX)
			reg.ecx = reg.ecx;
		else if (op2 == EDX)
			reg.ecx = reg.edx;
		else if (op2 == SP)
			reg.ecx = (GR)reg.sp;
		else if (op2 == PC)
			reg.ecx = (GR)reg.pc;
		else
			reg.ecx = op2;
		break;
	case EDX:
		if (op2 == EAX)
			reg.edx = reg.eax;
		else if (op2 == EBX)
			reg.edx = reg.ebx;
		else if (op2 == ECX)
			reg.edx = reg.ecx;
		else if (op2 == EDX)
			reg.edx = reg.edx;
		else if (op2 == SP)
			reg.edx = (GR)reg.sp;
		else if (op2 == PC)
			reg.edx = (GR)reg.pc;
		else
			reg.edx = op2;
		break;
	case SP:
		if (op2 == EAX)
			reg.sp = (PR)reg.eax;
		else if (op2 == EBX)
			reg.sp = (PR)reg.ebx;
		else if (op2 == ECX)
			reg.sp = (PR)reg.ecx;
		else if (op2 == EDX)
			reg.sp = (PR)reg.edx;
		else if (op2 == SP)
			reg.sp = reg.sp;
		else if (op2 == PC)
			reg.sp = reg.pc;
		else
			reg.sp = (PR)op2;
		break;
	case PC:
		if (op2 == EAX)
			reg.pc = (PR)reg.eax;
		else if (op2 == EBX)
			reg.pc = (PR)reg.ebx;
		else if (op2 == ECX)
			reg.pc = (PR)reg.ecx;
		else if (op2 == EDX)
			reg.pc = (PR)reg.edx;
		else if (op2 == SP)
			reg.pc = reg.sp;
		else if (op2 == PC)
			reg.pc = reg.pc;
		else
			reg.pc = (PR)op2;
		break;
	default:
		//printf("Something Wrong in _mov\n");
		break;
	}
}


/*
 - cmp op1 and op2
 - zf += BIG if op1 is bigger than op2 
 - zf += EQL if op1 is equal to op2
 - zf += SML if op1 is smaller than op2
 - op1 and op2 can be a Register or 1byte data
*/
void Custom_CPU::_cmp(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.zf = ((reg.eax>reg.eax)<<0) + ((reg.eax==reg.eax)<<1) + ((reg.eax<reg.eax)<<2);
		else if (op2 == EBX)
			reg.zf = ((reg.eax>reg.ebx) << 0) + ((reg.eax == reg.ebx) << 1) + ((reg.eax<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = ((reg.eax>reg.ecx) << 0) + ((reg.eax == reg.ecx) << 1) + ((reg.eax<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = ((reg.eax>reg.edx) << 0) + ((reg.eax == reg.edx) << 1) + ((reg.eax<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = ((reg.eax>(GR)reg.sp) << 0) + ((reg.eax == (GR)reg.sp) << 1) + ((reg.eax<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = ((reg.eax>(GR)reg.pc) << 0) + ((reg.eax == (GR)reg.pc) << 1) + ((reg.eax<(GR)reg.pc) << 2);
		else
			reg.zf = ((reg.eax>op2) << 0) + ((reg.eax == op2) << 1) + ((reg.eax<op2) << 2);
		break;
	case EBX:
		if (op2 == EAX)
			reg.zf = ((reg.ebx>reg.eax) << 0) + ((reg.ebx == reg.eax) << 1) + ((reg.ebx<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = ((reg.ebx>reg.ebx) << 0) + ((reg.ebx == reg.ebx) << 1) + ((reg.ebx<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = ((reg.ebx>reg.ecx) << 0) + ((reg.ebx == reg.ecx) << 1) + ((reg.ebx<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = ((reg.ebx>reg.edx) << 0) + ((reg.ebx == reg.edx) << 1) + ((reg.ebx<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = ((reg.ebx>(GR)reg.sp) << 0) + ((reg.ebx == (GR)reg.sp) << 1) + ((reg.ebx<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = ((reg.ebx>(GR)reg.pc) << 0) + ((reg.ebx == (GR)reg.pc) << 1) + ((reg.ebx<(GR)reg.pc) << 2);
		else
			reg.zf = ((reg.ebx>op2) << 0) + ((reg.ebx == op2) << 1) + ((reg.ebx<op2) << 2);
		break;
	case ECX:
		if (op2 == EAX)
			reg.zf = ((reg.ecx>reg.eax) << 0) + ((reg.ecx == reg.eax) << 1) + ((reg.ecx<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = ((reg.ecx>reg.ebx) << 0) + ((reg.ecx == reg.ebx) << 1) + ((reg.ecx<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = ((reg.ecx>reg.ecx) << 0) + ((reg.ecx == reg.ecx) << 1) + ((reg.ecx<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = ((reg.ecx>reg.edx) << 0) + ((reg.ecx == reg.edx) << 1) + ((reg.ecx<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = ((reg.ecx>(GR)reg.sp) << 0) + ((reg.ecx == (GR)reg.sp) << 1) + ((reg.ecx<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = ((reg.ecx>(GR)reg.pc) << 0) + ((reg.ecx == (GR)reg.pc) << 1) + ((reg.ecx<(GR)reg.pc) << 2);
		else
			reg.zf = ((reg.ecx>op2) << 0) + ((reg.ecx == op2) << 1) + ((reg.ecx<op2) << 2);
		break;
	case EDX:
		if (op2 == EAX)
			reg.zf = ((reg.edx>reg.eax) << 0) + ((reg.edx == reg.eax) << 1) + ((reg.edx<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = ((reg.edx>reg.ebx) << 0) + ((reg.edx == reg.ebx) << 1) + ((reg.edx<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = ((reg.edx>reg.ecx) << 0) + ((reg.edx == reg.ecx) << 1) + ((reg.edx<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = ((reg.edx>reg.edx) << 0) + ((reg.edx == reg.edx) << 1) + ((reg.edx<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = ((reg.edx>(GR)reg.sp) << 0) + ((reg.edx == (GR)reg.sp) << 1) + ((reg.edx<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = ((reg.edx>(GR)reg.pc) << 0) + ((reg.edx == (GR)reg.pc) << 1) + ((reg.edx<(GR)reg.pc) << 2);
		else
			reg.zf = ((reg.edx>op2) << 0) + ((reg.edx == op2) << 1) + ((reg.edx<op2) << 2);
		break;
	case SP:
		if (op2 == EAX)
			reg.zf = (((GR)reg.sp>reg.eax) << 0) + (((GR)reg.sp == reg.eax) << 1) + (((GR)reg.sp<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = (((GR)reg.sp>reg.ebx) << 0) + (((GR)reg.sp == reg.ebx) << 1) + (((GR)reg.sp<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = (((GR)reg.sp>reg.ecx) << 0) + (((GR)reg.sp == reg.ecx) << 1) + (((GR)reg.sp<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = (((GR)reg.sp>reg.edx) << 0) + (((GR)reg.sp == reg.edx) << 1) + (((GR)reg.sp<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = (((GR)reg.sp>(GR)reg.sp) << 0) + (((GR)reg.sp == (GR)reg.sp) << 1) + (((GR)reg.sp<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = (((GR)reg.sp>(GR)reg.pc) << 0) + (((GR)reg.sp == (GR)reg.pc) << 1) + (((GR)reg.sp<(GR)reg.pc) << 2);
		else
			reg.zf = (((GR)reg.sp>op2) << 0) + (((GR)reg.sp == op2) << 1) + (((GR)reg.sp<op2) << 2);
		break;
	case PC:
		if (op2 == EAX)
			reg.zf = (((GR)reg.pc>reg.eax) << 0) + (((GR)reg.pc == reg.eax) << 1) + (((GR)reg.pc<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = (((GR)reg.pc>reg.ebx) << 0) + (((GR)reg.pc == reg.ebx) << 1) + (((GR)reg.pc<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = (((GR)reg.pc>reg.ecx) << 0) + (((GR)reg.pc == reg.ecx) << 1) + (((GR)reg.pc<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = (((GR)reg.pc>reg.edx) << 0) + (((GR)reg.pc == reg.edx) << 1) + (((GR)reg.pc<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = (((GR)reg.pc>(GR)reg.sp) << 0) + (((GR)reg.pc == (GR)reg.sp) << 1) + (((GR)reg.pc<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = (((GR)reg.pc>(GR)reg.pc) << 0) + (((GR)reg.pc == (GR)reg.pc) << 1) + (((GR)reg.pc<(GR)reg.pc) << 2);
		else
			reg.zf = (((GR)reg.pc>op2) << 0) + (((GR)reg.pc == op2) << 1) + (((GR)reg.pc<op2) << 2);
		break;
	default:
		if (op2 == EAX)
			reg.zf = ((op1>reg.eax) << 0) + ((op1 == reg.eax) << 1) + ((op1<reg.eax) << 2);
		else if (op2 == EBX)
			reg.zf = ((op1>reg.ebx) << 0) + ((op1 == reg.ebx) << 1) + ((op1<reg.ebx) << 2);
		else if (op2 == ECX)
			reg.zf = ((op1>reg.ecx) << 0) + ((op1 == reg.ecx) << 1) + ((op1<reg.ecx) << 2);
		else if (op2 == EDX)
			reg.zf = ((op1>reg.edx) << 0) + ((op1 == reg.edx) << 1) + ((op1<reg.edx) << 2);
		else if (op2 == SP)
			reg.zf = ((op1>(GR)reg.sp) << 0) + ((op1 == (GR)reg.sp) << 1) + ((op1<(GR)reg.sp) << 2);
		else if (op2 == PC)
			reg.zf = ((op1>(GR)reg.pc) << 0) + ((op1 == (GR)reg.pc) << 1) + ((op1<(GR)reg.pc) << 2);
		else
			reg.zf = ((op1>op2) << 0) + ((op1 == op2) << 1) + ((op1<op2) << 2);
		break;
	}
}


/*
- jmp to op2 when Z_FLAG is $(op1)
- jmp to op2 when op1 is ANW (Anyway)
- PC = op2
- op1 must be a Z-Flag value (BIG, EQL, SML, JBE, JSE, ANW)
- op2 must be a Register
*/
void Custom_CPU::_jmp(OPERAND op1, OPERAND op2)
{
	if (op2 == NULL) {
		//printf("Adress cannot be NULL\n");
		return;
	}

	switch (op1) {
	case BIG:
		if (reg.zf == BIG) {
			if (op2 == EAX)
				reg.pc = reg.pe + reg.eax;
			else if (op2 == EBX)
				reg.pc = reg.pe + reg.ebx;
			else if (op2 == ECX)
				reg.pc = reg.pe + reg.ecx;
			else if (op2 == EDX)
				reg.pc = reg.pe + reg.edx;
			else if (op2 == SP)
				reg.pc = reg.pe + (GR)reg.sp;
			else if (op2 == PC)
				reg.pc = reg.pe + (GR)reg.pc;
		}
		break;
	case EQL:
		if (reg.zf == EQL) {
			if (op2 == EAX)
				reg.pc = reg.pe + reg.eax;
			else if (op2 == EBX)
				reg.pc = reg.pe + reg.ebx;
			else if (op2 == ECX)
				reg.pc = reg.pe + reg.ecx;
			else if (op2 == EDX)
				reg.pc = reg.pe + reg.edx;
			else if (op2 == SP)
				reg.pc = reg.pe + (GR)reg.sp;
			else if (op2 == PC)
				reg.pc = reg.pe + (GR)reg.pc;
		}
		break;
	case SML:
		if (reg.zf == SML) {
			if (op2 == EAX)
				reg.pc = reg.pe + reg.eax;
			else if (op2 == EBX)
				reg.pc = reg.pe + reg.ebx;
			else if (op2 == ECX)
				reg.pc = reg.pe + reg.ecx;
			else if (op2 == EDX)
				reg.pc = reg.pe + reg.edx;
			else if (op2 == SP)
				reg.pc = reg.pe + (GR)reg.sp;
			else if (op2 == PC)
				reg.pc = reg.pe + (GR)reg.pc;
		}
		break;
	case JBE:
		if (reg.zf == JBE) {
			if (op2 == EAX)
				reg.pc = reg.pe + reg.eax;
			else if (op2 == EBX)
				reg.pc = reg.pe + reg.ebx;
			else if (op2 == ECX)
				reg.pc = reg.pe + reg.ecx;
			else if (op2 == EDX)
				reg.pc = reg.pe + reg.edx;
			else if (op2 == SP)
				reg.pc = reg.pe + (GR)reg.sp;
			else if (op2 == PC)
				reg.pc = reg.pe + (GR)reg.pc;
		}
		break;
	case JSE:
		if (reg.zf == JSE) {
			if (op2 == EAX)
				reg.pc = reg.pe + reg.eax;
			else if (op2 == EBX)
				reg.pc = reg.pe + reg.ebx;
			else if (op2 == ECX)
				reg.pc = reg.pe + reg.ecx;
			else if (op2 == EDX)
				reg.pc = reg.pe + reg.edx;
			else if (op2 == SP)
				reg.pc = reg.pe + (GR)reg.sp;
			else if (op2 == PC)
				reg.pc = reg.pe + (GR)reg.pc;
		}
		break;
	case ANW:
		if (op2 == EAX)
			reg.pc = reg.pe + reg.eax;
		else if (op2 == EBX)
			reg.pc = reg.pe + reg.ebx;
		else if (op2 == ECX)
			reg.pc = reg.pe + reg.ecx;
		else if (op2 == EDX)
			reg.pc = reg.pe + reg.edx;
		else if (op2 == SP)
			reg.pc = reg.pe + (GR)reg.sp;
		else if (op2 == PC)
			reg.pc = reg.pe + (GR)reg.pc;
		break;
	default :
		//printf("Something Wrong in _jmp\n");
		break;
	}
}


/*
 - op1 = *(char*)op2
 - load only 1byte per execution
 - load data that pointed by op2
 - op1 must be EAX or EBX
 - op2 must be a Register
*/
void Custom_CPU::_load(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax = *(char*)reg.eax;
		else if (op2 == EBX)
			reg.eax = *(char*)reg.ebx;
		else if (op2 == ECX)
			reg.eax = *(char*)reg.ecx;
		else if (op2 == EDX)
			reg.eax = *(char*)reg.edx;
		else if (op2 == SP)
			reg.eax = *(char*)reg.sp;
		else if (op2 == PC)
			reg.eax = *(char*)reg.pc;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx = *(char*)reg.eax;
		else if (op2 == EBX)
			reg.ebx = *(char*)reg.ebx;
		else if (op2 == ECX)
			reg.ebx = *(char*)reg.ecx;
		else if (op2 == EDX)
			reg.ebx = *(char*)reg.edx;
		else if (op2 == SP)
			reg.ebx = *(char*)reg.sp;
		else if (op2 == PC)
			reg.ebx = *(char*)reg.pc;
		break;
	case ECX:
		if (op2 == EAX)
			reg.ecx = *(char*)reg.eax;
		else if (op2 == EBX)
			reg.ecx = *(char*)reg.ebx;
		else if (op2 == ECX)
			reg.ecx = *(char*)reg.ecx;
		else if (op2 == EDX)
			reg.ecx = *(char*)reg.edx;
		else if (op2 == SP)
			reg.ecx = *(char*)reg.sp;
		else if (op2 == PC)
			reg.ecx = *(char*)reg.pc;
		break;
	case EDX:
		if (op2 == EAX)
			reg.edx = *(char*)reg.eax;
		else if (op2 == EBX)
			reg.edx = *(char*)reg.ebx;
		else if (op2 == ECX)
			reg.edx = *(char*)reg.ecx;
		else if (op2 == EDX)
			reg.edx = *(char*)reg.edx;
		else if (op2 == SP)
			reg.edx = *(char*)reg.sp;
		else if (op2 == PC)
			reg.edx = *(char*)reg.pc;
		break;
	default:
		//printf("Something Wrong in _load\n");
		break;
	}
}


/*
 - *(char*)op1 = op2
 - store only 1 byte per execution
 - store op2 to *op1
 - op1 must be EAX or EBX or SP
 - op2 can be a Register(it would store Reg&0xff) or 1byte data
*/
void Custom_CPU::_stor(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			*(char*)reg.eax = (char)reg.eax;
		else if (op2 == EBX)
			*(char*)reg.eax = (char)reg.ebx;
		else if (op2 == ECX)
			*(char*)reg.eax = (char)reg.ecx;
		else if (op2 == EDX)
			*(char*)reg.eax = (char)reg.edx;
		else if (op2 == SP)
			*(char*)reg.eax = (char)reg.sp;
		else if (op2 == PC)
			*(char*)reg.eax = (char)reg.pc;
		else
			*(char*)reg.eax = (char)op2;
		break;
	case EBX:
		if (op2 == EAX)
			*(char*)reg.ebx = (char)reg.eax;
		else if (op2 == EBX)
			*(char*)reg.ebx = (char)reg.ebx;
		else if (op2 == ECX)
			*(char*)reg.ebx = (char)reg.ecx;
		else if (op2 == EDX)
			*(char*)reg.ebx = (char)reg.edx;
		else if (op2 == SP)
			*(char*)reg.ebx = (char)reg.sp;
		else if (op2 == PC)
			*(char*)reg.ebx = (char)reg.pc;
		else
			*(char*)reg.ebx = (char)op2;
		break;
	case ECX:
		if (op2 == EAX)
			*(char*)reg.ecx = (char)reg.eax;
		else if (op2 == EBX)
			*(char*)reg.ecx = (char)reg.ebx;
		else if (op2 == ECX)
			*(char*)reg.ecx = (char)reg.ecx;
		else if (op2 == EDX)
			*(char*)reg.ecx = (char)reg.edx;
		else if (op2 == SP)
			*(char*)reg.ecx = (char)reg.sp;
		else if (op2 == PC)
			*(char*)reg.ecx = (char)reg.pc;
		else
			*(char*)reg.ecx = (char)op2;
		break;
	case EDX:
		if (op2 == EAX)
			*(char*)reg.edx = (char)reg.eax;
		else if (op2 == EBX)
			*(char*)reg.edx = (char)reg.ebx;
		else if (op2 == ECX)
			*(char*)reg.edx = (char)reg.ecx;
		else if (op2 == EDX)
			*(char*)reg.edx = (char)reg.edx;
		else if (op2 == SP)
			*(char*)reg.edx = (char)reg.sp;
		else if (op2 == PC)
			*(char*)reg.edx = (char)reg.pc;
		else
			*(char*)reg.edx = (char)op2;
		break;
	case SP:
		if (op2 == EAX)
			*(char*)reg.sp = (char)reg.eax;
		else if (op2 == EBX)
			*(char*)reg.sp = (char)reg.ebx;
		else if (op2 == ECX)
			*(char*)reg.sp = (char)reg.ecx;
		else if (op2 == EDX)
			*(char*)reg.sp = (char)reg.edx;
		else if (op2 == SP)
			*(char*)reg.sp = (char)reg.sp;
		else if (op2 == PC)
			*(char*)reg.sp = (char)reg.pc;
		else
			*(char*)reg.sp = (char)op2;
		break;
	default:
		//printf("Something Wrong in _stor\n");
		break;
	}
}



/*
 - push op1 to stack
 - op1 can be a Register or 1byte data
*/
void Custom_CPU::_push(OPERAND op1)
{
	GR tmp;
	switch (op1) {
	case EAX:
		reg.sp -= 1;
		*reg.sp = reg.eax;
		break;
	case EBX:
		reg.sp -= 1;
		*reg.sp = reg.eax;
		break;
	case SP:
		tmp = (GR)reg.sp;
		reg.sp -= 1;
		*reg.sp = tmp;
		break;
	case PC:
		reg.sp -= 1;
		*reg.sp = (GR)reg.pc;
	default:
		//printf("Something Wrong in _push\n");
		break;
	}
}


/*
- pop stack to op1
*/
void Custom_CPU::_pop(OPERAND op1)
{
	switch (op1) {
	case EAX:
		reg.eax = *reg.sp;
		reg.sp -= 4;
		break;
	case EBX:
		reg.ebx = *reg.sp;
		reg.sp -= 4;
		break;
	case SP:
		reg.sp = (char*)*reg.sp;
		reg.sp -= 4;
		break;
	case PC:
		reg.pc = (char*)*reg.sp;
		reg.sp -= 4;
	default:
		//printf("Something Wrong in _pop\n");
		break;
	}
}
