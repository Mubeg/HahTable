import tqdm
file_ = open("poem.txt", "r")
text = file_.read().split("\n")
f = open("itext.txt", "w")
file_.close()
dictionary = []
for line in tqdm.tqdm(text):
	for word in line.split(" "):
		if not (word in dictionary or word == ""):
			f.write("{}\n".format(word))
			dictionary.append(word)
	
f.close()
