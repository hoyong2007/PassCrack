#define ADD  0x1
#define SUB  0x2
#define XOR  0x3
#define CMP  0x4
#define MOV  0x5
#define JMP  0x6
#define LOAD 0x7
#define STOR 0x8
#define POP  0x9
#define PUSH 0xA
#define RET  -1


#define PC  0xFF
#define SP  0xFE
#define EAX 0xFA
#define EBX 0xFB
#define ECX 0xFC
#define EDX 0xFD

#define BIG 0x1
#define EQL 0x2
#define SML 0X4
#define ANW 0x8

#define JBE BIG+EQL
#define JSE SML+EQL

typedef unsigned int GR;	// General Register
typedef char* PR;
typedef char FR;			// Flag Register
typedef unsigned char OPERAND;
typedef char OPCODE;

typedef struct reg {
	PR pe;
	PR pc;
	PR sp;
	GR eax;
	GR ebx;
	GR ecx;
	GR edx;
	FR zf;
} REG;

/*
extern char passwd_txt[128];
extern char passwd_enc[128];
extern char random_str[128];
*/

class Custom_CPU {
private:
	void *stack_top;
	void *stack_bot;
	REG reg;

	void _add(OPERAND op1, OPERAND op2);
	void _sub(OPERAND op1, OPERAND op2);
	void _mov(OPERAND op1, OPERAND op2);
	void _xor(OPERAND op1, OPERAND op2);
	void _cmp(OPERAND op1, OPERAND op2);
	void _jmp(OPERAND op1, OPERAND op2);
	void _load(OPERAND op1, OPERAND op2);
	void _stor(OPERAND op1, OPERAND op2);
	void _pop(OPERAND op1);
	void _push(OPERAND op1);
			
public:
	Custom_CPU();
	~Custom_CPU();
	int execute(void *pe);
	GR get_result();
};