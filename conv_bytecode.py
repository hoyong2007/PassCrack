import sys

filename = sys.argv[1]

opcode = {'add':'\x01', 'ADD':'\x01', 'sub':'\x02', 'xor':'\x03', 'cmp':'\x04', 'mov':'\x05', 'MOV':'\x05', 'jmp':'\x06','JMP':'\x06', 'load':'\x07', 'stor':'\x08', 'pop':'\x09', 'push':'\x0A', 'ret':'\xff'}
reg = {'pc':'\xFF', 'sp':'\xFE', 'esp':'\xFE', 'eax':'\xFA', 'al':'\xFA', 'ebx':'\xFB', 'ecx':'\xFC', 'cl':'\xFC', 'edx':'\xFD', 'dl':'\xFD'}
flag = {'BIG':'\x01', 'EQL':'\x02', 'SML':'\x04', 'ANW':'\x08', 'JBE':'\x03', 'JSE':'\x06'}

f = open(filename, 'r')

bytecode = ''
while True:
	line = f.readline()
	if not line: break
	line = line.split()
	#print line
	if line[0].strip() == 'jmp' or line[0].strip() == 'JMP':
		print line
		bytecode += opcode[line[0]]
		print hex(ord(flag[line[1].strip().replace(',','')]))
		bytecode += flag[line[1].strip().replace(',','')]
		print hex(ord(reg[line[2]]))
		bytecode += reg[line[2]]
	elif line[0].strip() == 'ret':
		bytecode += '\xFF'
		break
	else:
		bytecode += opcode[line[0]]
		if line[1].strip().replace(',','') in reg:	
			bytecode += reg[line[1].strip().replace(',','')]
		else:
			bytecode += chr(int(line[1].strip().replace(',','').replace('h',''), 16))
		if line[2].strip().replace(',','') in reg:
			bytecode += reg[line[2].strip().replace(',','')]
		else:
			bytecode += chr(int(line[2].strip().replace(',','').replace('h',''), 16))

f.close()

f = open('result','w')
f.write(bytecode)
f.close()
#print bytecode