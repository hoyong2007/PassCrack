#include <iostream>
#include <malloc.h>
#include "vm.h"

extern char passwd_txt[128];
extern char passwd_enc[128];
extern char random_str[128];

/* 
Constructor
  - allocate mem for Custom stack & register
  - after allocation, initialize reg
  - Custom stack's bottom == buffer
*/
Custom_CPU::Custom_CPU() {
	stack_top = (void*)_aligned_malloc(0x2000, 4);	
	stack_bot = (PR)((GR)stack_top + 0x2000);
	if (stack_top == NULL) {
		printf("Buffer allocate Error!\n");
		exit(1);
	}
	// Init register
	reg.pc = 0;
	reg.sp = (PR)stack_bot;
	reg.eax = 0;
	reg.ebx = 0;
	reg.ecx = 0;
	reg.edx = 0;
}



/*
execute()
 - execute instruction that pointed by reg.PC
 - every inst & operand is 1byte each
 - terminate when reg.PC reaches to RET instruction
*/
int Custom_CPU::execute(void *pe)
{
	OPCODE inst;
	OPERAND arg1 = 0, arg2 = 0;

	if (pe == NULL) {
		printf("Need Bytecode\n");
		return 0;
	}

	reg.pc = (PR)pe;
	reg.sp = (PR)stack_bot;

	memcpy((char*)stack_bot - 128, passwd_txt, 128);
	reg.sp -= 128;
	memcpy((char*)stack_bot - 128 * 2, passwd_enc, 128);
	reg.sp -= 128;
	memcpy((char*)stack_bot - 128 * 1, random_str, 128);
	reg.sp -= 128;

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
			arg2 = *(reg.pc++);
			Custom_CPU::_jmp(arg1, arg2);
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


/*
 - return result value
 - result will be stored in EAX
 - Validate	-> return 1 or 2
 - Change	-> return 0 if false || return ptr to enc_passwd
*/
GR Custom_CPU::get_result()
{
	return reg.eax;
}


/*
Destructor
- free allocated memory (stack)
*/
Custom_CPU::~Custom_CPU() {
	_aligned_free(stack_top);
	stack_top = NULL;
}