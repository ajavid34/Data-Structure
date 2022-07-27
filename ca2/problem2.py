word = input()
key = []
for i in range(len(word)):
    if len(key) == 0 or key[-1] != word[i]:
        key.append(word[i])
    elif key[-1] == word[i]:
        key.pop()

print(''.join(key))



