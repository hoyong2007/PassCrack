#define ADD 0x1
#define SUB 0x2
#define XOR 0x3
#define CMP 0x4
#define MOV 0x5
#define JMP 0x6
#define POP 0x7
#define PUSH 0x8
#define RET 0xff

#define EAX 0xff
#define EBX 0xfe

typedef unsigned int UINT;
typedef unsigned int OPERAND;
typedef char OPCODE;
typedef struct reg {
	char *pc;
	char *sp;
	UINT eax;
	UINT ebx;
} REG;


class Custom_CPU {
private:
	void *stack;
	REG reg;

	void _add(OPERAND op1, OPERAND op2);
	void _sub(OPERAND op1, OPERAND op2);
	void _mov(OPERAND op1, OPERAND op2);
	void _xor(OPERAND op1, OPERAND op2);
	void _cmp(OPERAND op1, OPERAND op2);
	void _jmp(OPERAND op1);
	void _pop(OPERAND op1);
	void _push(OPERAND op1);

public:
	Custom_CPU(int *pe);
	~Custom_CPU();
	int execute();

};