from idaapi import *

here = idc.here()
funcStart	= 0x00415710 
funcEnd 	= 0x004159A3

i = funcStart
while i <= funcEnd:
