row_delta = [-1, -1, -1, 0, 0, 1, 1, 1]
col_delta = [-1, 0, 1, -1, 1, -1, 0, 1]


def is_valid(row, col, prev_row, prev_col, n, path):
    temp_path = "(" + str(row) + ", " + str(col) + ")"
    return (row >= 0) and (row < n) and (col >= 0) and \
           (col < n) and not (row == prev_row and col == prev_col) and temp_path not in path


def solve(chars, row, col, prev_row, prev_col, word, path, index, n):
    if index > len(word) - 1 or chars[row][col] != word[index]:
        return
    if index == 0:
        path += "(" + str(row) + ", " + str(col) + ")"
    else:
        path += ",(" + str(row) + ", " + str(col) + ")"
    if index == len(word) - 1:
        print(path)
        return
    for k in range(8):
        if is_valid(row + row_delta[k], col + col_delta[k], prev_row, prev_col, n, path):
            solve(chars, row + row_delta[k], col + col_delta[k], row, col, word, path, index + 1, n)


def find_word(chars, word, n):
    for i in range(n):
        for j in range(n):
            if chars[i][j] == word[0]:
                solve(chars, i, j, -1, -1, word, "", 0, n)


n, word = input().split(',')
n = int(n)
chars = []
for _ in range(n):
    chars.append(input().split(','))
find_word(chars, word, n)
