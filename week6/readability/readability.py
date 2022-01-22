import cs50

text = cs50.get_string("Text: ")
sentence_end = ['.', '!', '?']

n_word = 0
n_letter = 0
n_sentence = 0

for s in text:
    if s.isalpha():
        n_letter += 1
    elif s == ' ':
        n_word += 1
    elif s in sentence_end:
        n_sentence += 1

n_word += 1

l = 100 * n_letter/n_word
s = 100 * n_sentence/n_word

score = round(0.0588 * l - 0.296 * s - 15.8)
index = 'Before Grade 1' if score < 1 else 'Grade 16+' if score > 16 else f"Grade {score}"

print(index)