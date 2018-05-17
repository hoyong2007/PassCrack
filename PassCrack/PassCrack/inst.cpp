#include <iostream>
#include "vm.h"

void Custom_CPU::_add(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax += reg.eax;
		else if (op2 == EBX)
			reg.eax += reg.ebx;
		else
			reg.eax += op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx += reg.eax;
		else if (op2 == EBX)
			reg.ebx += reg.ebx;
		else
			reg.ebx += op2;
		break;
	default:
		printf("Something Wrong in _add\n");
	}
}


void Custom_CPU::_sub(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax -= reg.eax;
		else if (op2 == EBX)
			reg.eax -= reg.ebx;
		else
			reg.eax -= op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx -= reg.eax;
		else if (op2 == EBX)
			reg.ebx -= reg.ebx;
		else
			reg.ebx -= op2;
		break;
	default:
		printf("Something Wrong in _sub\n");
	}
}


void Custom_CPU::_xor(OPERAND op1, OPERAND op2)
{
	switch (op1) {
	case EAX:
		if (op2 == EAX)
			reg.eax ^= reg.eax;
		else if (op2 == EBX)
			reg.eax ^= reg.ebx;
		else
			reg.eax ^= op2;
		break;
	case EBX:
		if (op2 == EAX)
			reg.ebx ^= reg.eax;
		else if (op2 == EBX)
			reg.ebx ^= reg.ebx;
		else
			reg.ebx ^= op2;
		break;
	default:
		printf("Something Wrong in _xor\n");
	}
}

void Custom_CPU::_mov(OPERAND op1, OPERAND op2)
{
	printf("h");
}

void Custom_CPU::_cmp(OPERAND op1, OPERAND op2)
{
	printf("h");
}
void Custom_CPU::_jmp(OPERAND op1)
{
	printf("h");
}
void Custom_CPU::_push(OPERAND op1)
{
	printf("h");
}
void Custom_CPU::_pop(OPERAND op1)
{
	printf("h");
}