# Take a sentence and try to find the most occurring words. (hint: convert sentence into a list)

sentans = "This is a sentence wiht some of a occusring model"
list = sentans.split(" ")

word_count = {}

for word in list:
    if word in word_count:
        word_count[word] += 1
    else:
        word_count[word] = 1


max_count = max(word_count.values())
most_occuring_words = [word for word, count in word_count.items() if count == max_count]

print("Most occurring words:", word_count)