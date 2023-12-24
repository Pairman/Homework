from io import StringIO, TextIOWrapper

class BoyerMoore:
	def __init__(self, pattern):
		self.__badchar, self.__pattern = [-1 for i in range(256)], pattern
		for i in range(len(pattern)):
			self.__badchar[ord(pattern[i])] = i

	def find(self, text):
		pos = 0
		while(pos <= len(text) - len(self.__pattern)):
			j = len(self.__pattern) - 1
			while j >= 0 and self.__pattern[j] == text[pos + j]:
				j -= 1
			if j < 0:
				pos += len(self.__pattern) - self.__badchar[ord(text[pos + len(self.__pattern)])] if pos + len(self.__pattern) < len(text) else 1
				return pos
			else:
				pos += max(1, j - self.__badchar[ord(text[pos + j])])
		return -1

	def findall(self, text):
		pos = 0
		matches = []
		while(pos <= len(text) - len(self.__pattern)):
			j = len(self.__pattern) - 1
			while j >= 0 and self.__pattern[j] == text[pos + j]:
				j -= 1
			if j < 0:
				pos += len(self.__pattern) - self.__badchar[ord(text[pos + len(self.__pattern)])] if pos + len(self.__pattern) < len(text) else 1
				matches.append(pos)
			else:
				pos += max(1, j - self.__badchar[ord(text[pos + j])])
		return matches

	def count(self, text, endpos, offset = 0):
		return sum(c in (" ", "\t", "\n") for c in text[offset: endpos])

	def countall(self, text, endposes):
		if not endposes:
			return []
		cnts = [self.count(text, endposes[0])]
		for i in range(1, len(endposes)):
			cnts.append(cnts[i - 1] + self.count(text, endposes[i], endposes[i - 1]))
		return cnts

def test(file_corpus: TextIOWrapper | StringIO, file_query: TextIOWrapper | StringIO = None, verbose = True):
	text = file_corpus.read()
	while (pattern := file_query.readline()[: -1]):
		print("?%s" % pattern)
		B = BoyerMoore(pattern)
		matches = B.findall(text)
		print("    count: %d" % len(matches))
		if verbose and matches:
			print("    pchar: " + ", ".join(map(str, matches)))
			print("    pword: " + ", ".join(map(str, B.countall(text, matches))))

# file_corpus_eg = StringIO("it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief it was the epoch of incredulity it was the season of light it was the season of darkness it was the spring of hope it was the winter of despair")
# file_query_eg = StringIO("wisdom\nseason\nage of foolishness\nage of fools")
# test(file_corpus_eg, file_query_eg)

file_corpus = open("4/plrabn12.txt", "r")
file_query = StringIO("God\nFather\nSatan\nI \nfree will\nthese shining orbs\nEarth\nParadise\nChaos\nOver the vexed abyss\nHeaven\nEve\nAdam\nAngel\nbless\nSpirit\ndespair\nhis love\nfor ever\nwith thee\n")
test(file_corpus, file_query, verbose = True)