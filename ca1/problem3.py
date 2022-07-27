def find_most_valuable(l, r):
    current_num = l
    while current_num < r:
        new_num = (current_num + 1) | current_num
        if new_num <= r:
            current_num = new_num
        else:
            break
    return current_num


n = int(input())
for _ in range(n):
    stow_pair = list(map(int, input().split()))
    print(find_most_valuable(stow_pair[0], stow_pair[1]))
