#include <iostream>
#include <malloc.h>
#include "vm.h"

/* 
Constructor
  - allocate mem for Custom stack & register
  - after allocation, initialize reg
  - Custom stack's bottom == buffer
*/
Custom_CPU::Custom_CPU(int *pe) {
	stack = (void*)_aligned_malloc(0x2000, 4);	
	if (stack == NULL) {
		printf("Buffer allocate Error!\n");
		exit(1);
	}
	// Init register
	reg.pc = (char*)pe;
	reg.sp = (char*)stack;
	reg.eax = 0;
	reg.ebx = 0;
}

/*
Destructor
 - free allocated memory (stack)
*/
Custom_CPU::~Custom_CPU() {
	_aligned_free(stack);
	stack = NULL;
}


/*
execute()
 - execute instruction that pointed by reg.PC
 - every inst & operand is 1byte each
 - terminate when reg.PC reaches to RET instruction
*/
int Custom_CPU::execute()
{
	OPCODE inst = *(reg.pc++);
	OPERAND arg1 = 0, arg2 = 0;

	while (1) {
		inst = *(reg.pc++);

		switch (inst) {
		case ADD:
			arg1 = *(reg.pc++);
			arg2 = *(reg.pc++);
			Custom_CPU::_add(arg1, arg2);
			break;
		case SUB:
			arg1 = *(reg.pc++);
			arg2 = *(reg.pc++);
			Custom_CPU::_sub(arg1, arg2);
			break;
		case XOR:
			arg1 = *(reg.pc++);
			arg2 = *(reg.pc++);
			Custom_CPU::_xor(arg1, arg2);
			break;
		case CMP:
			arg1 = *(reg.pc++);
			arg2 = *(reg.pc++);
			Custom_CPU::_cmp(arg1, arg2);
			break;
		case MOV:
			arg1 = *(reg.pc++);
			arg2 = *(reg.pc++);
			Custom_CPU::_mov(arg1, arg2);
			break;
		case JMP:
			arg1 = *(reg.pc++);
			Custom_CPU::_jmp(arg1);
			break;
		case POP:
			arg1 = *(reg.pc++);
			Custom_CPU::_pop(arg1);
			break;
		case PUSH:
			arg1 = *(reg.pc++);
			Custom_CPU::_push(arg1);
			break;
		case RET:
			return 1;
			break;
		default:
			printf("Something Wrong :(\n");
			return 0;
			break;
		}
	}
}