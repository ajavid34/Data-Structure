def check_list(circle_list):
    for i in range(len(circle_list)):
        if i == len(circle_list) - 1:
            if circle_list[i] == 0.5 * (circle_list[i - 1] + circle_list[0]):
                return i
        elif circle_list[i] == 0.5 * (circle_list[i - 1] + circle_list[i + 1]):
            return i
    return -1


def swap(list, pos1, pos2):
    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list


n = int(input())
stow_list = list(map(int, input().split()))
bad_element_index = check_list(stow_list)
while bad_element_index != -1:
    stow_list = swap(stow_list, bad_element_index, bad_element_index + 1)
    bad_element_index = check_list(stow_list)
print(*stow_list)
