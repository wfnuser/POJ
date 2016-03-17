import os
import filecmp

os.system('g++ gen.cpp -o gen')
os.system('g++ new.cpp -o matrix -O2')
os.system('g++ force.cpp -o force -O2')

while(True):
	os.system('./gen > matrix.in')
	os.system('./matrix < matrix.in > matrix.out')
	os.system('./force < matrix.in > std.out')
	if filecmp.cmp('matrix.out', 'std.out') == True:
		print 'Ac'
	else:
		print 'Wa'
		break
