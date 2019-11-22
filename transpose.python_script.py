matrix = []
f = open('ofile.csv', 'r')
for line in f.readlines():
	matrix.append(line.split(","))
f.close()

f = open('ofile.csv', 'w')
for i in range(0, len(matrix[0])):
	for j in range(0, len(matrix)):
		f.write("{}, ".format(matrix[j][i]))
	f.write("\n")
f.close()
