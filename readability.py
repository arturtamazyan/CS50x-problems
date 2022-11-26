text = ''
while text == '':
    text = input('Text: ')


# words count will be one more than spaces. "My name is Bob." 3 space , 4 words

words = 1
letters = 0
sentences = 0

for i in text:
    if (ord(i) > 64 and ord(i) < 91) or (ord(i) > 96 and ord(i) < 123):
        letters += 1
    elif i == ' ':
        words += 1
    elif i == '?' or i == '.' or i == '!':
        sentences += 1

# We need average letters and sentences per 100 words, respectively L and S

# 'words / 100' is for founding how many 100s we have in our text, then devide our 'letters/words count' to that 100word chunks to find the average


L = letters / (words / 100)

S = sentences / (words / 100)

index = 0.0588 * L - 0.296 * S - 15.8


# If its too low or too high
if index < 1:
    print('"Before Grade 1')
elif index > 16:
    print('Grade 16+')

# Else round value, because we need nearest integer
index = round(index)

print(f"Grade {index}")
