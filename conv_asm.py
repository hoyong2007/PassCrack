import sys

reg = {'pc':'\xFF', 'sp':'\xFE', 'eax':'\xFA', 'ebx':'\xFB', 'ecx':'\xFC', 'edx':'\xFD', 'dl':'\xFD'}

filename = sys.argv[1]

f = open(filename, 'r')

conv = ''
while True:
   line = f.readline()
   if not line: break
   tmp = line
   line = line.strip().split()
   print line
   if line == []:
      continue
   if line[0].strip()[0:3] == 'mov' and line[1][0:4] == '[ebp':
      # mov [ebp+var_xxx], xxx
      if line[1].split('+')[1][0:3] == 'var':
         if line[2].strip() == 'eax':
             r = 'ecx'
         else:
             r = 'eax'
         conv += 'mov '+r+', sp\n'
         conv += 'xor ebx, ebx\n'
         off = int(line[1].split('+')[1].split('_')[1].replace('],',''), 16)
         while True:
            if off < 0xe0:
               conv += ('add ebx, ' + hex(off) + '\n')
               break
            conv += 'add ebx, 0xe0\n'
            off -= 0xe0
         conv += 'sub '+r+', ebx\n'
      # mov [ebp+reg+var_xxx], xxx
      elif line[1].split('+')[2][0:3] == 'var':
         conv += 'mov ebx, sp\n'
         off = int(line[1].split('_')[1].replace('],',''), 16)
         while True:
            if off < 0xe0:
               conv += ('sub ebx, ' + hex(off) + '\n')
               break
            conv += 'sub ebx, 0xe0\n'
            off -= 0xe0
         conv += 'add ebx, ' + line[1].split('+')[1] + '\n'
      if line[2] not in reg:
         if line[2].find(']'):
            conv += 'stor '+r+', ' + line[2] + '\n'
         else:
            conv += ('stor '+r+', ' + hex(int(line[2].replace('h',''), 16)) + '\n')
      else:
         conv += 'stor '+r+', ' + line[2] + '\n'
   # mov reg, ?
   elif line[0].strip()[0:3] == 'mov' and line[1][:-1] in reg and line[2][0]=='[':
      # mov reg, [ebp+var_xxx]
      if line[2][0:4] == '[ebp' and line[2].split('+')[1][0:3] == 'var':
         conv += 'mov eax, sp\n'
         conv += 'xor ebx, ebx\n'
         off = int(line[2].split('_')[1][:-1], 16)
         while True:
            if off < 0xe0:
               conv += ('add ebx, ' + hex(off) + '\n')
               break
            conv += 'add ebx, 0xe0\n'
            off -= 0xe0
         conv += 'sub eax, ebx\n'
         conv += 'load eax, eax\n'
         conv += 'mov ' + line[1].replace(',','') + ', eax\n'
      # mov reg, [ebp+reg+var_xxx]
      elif line[2][0:4] == '[ebp' and line[2].split('+')[1] in reg and line[2].split('+')[2][0:3] == 'var':
         if line[2].split('+')[1] == 'eax':
             r = 'ecx'
         else:
             r = 'eax'
         conv += 'mov '+r+', sp\n'
         conv += 'xor ebx, ebx\n'
         off = int(line[2].split('_')[1][:-1], 16)
         while True:
            if off < 0xe0:
               conv += ('add ebx, ' + hex(off) + '\n')
               break
            conv += 'add ebx, 0xe0\n'
            off -= 0xe0
         conv += 'sub '+r+', ebx\n'
         conv += 'add '+r+', ' + line[2].split('+')[1] + '\n'
         conv += 'load '+r+', '+r+'\n'
         conv += 'mov ' + line[1].replace(',','') + ', '+r+'\n'
   # cmp [ebc+var_xxx], xxx
   elif line[0].strip() == 'cmp' and line[1][0:4] == '[ebp' and line[2].find('h'):
      conv += 'mov eax, sp\n'
      conv += 'xor ebx, ebx\n'
      off = int(line[1].split('_')[1][:-2], 16)
      while True:
         if off < 0xe0:
            conv += ('add ebx, ' + hex(off) + '\n')
            break
         conv += 'add ebx, 0xe0\n'
         off -= 0xe0
      conv += 'sub eax, ebx\n'
      conv += 'load eax, eax\n'
      conv += 'cmp eax, ' + hex(int(line[2].replace('h',''), 16)) + '\n'
   else:
      #print tmp
      conv += tmp.strip() + '\n'

f.close()

f = open('result_asm','w')
f.write(conv)
f.close()
print 'done'