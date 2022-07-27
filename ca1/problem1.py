

def calc_point(x):
    point = 0
    for i in range(len(x)):
        if x[i] > 1:
            point += x[i] * (x[i] - 1) * 0.5
    return int(point)


def count_in_map(base_list, key):
    n = len(base_list)
    row_cnt = [0] * n
    column_cnt = [0] * n
    for i in range(n):
        for j in range(n):
            if base_list[i][j] == key:
                row_cnt[i] += 1
            if base_list[j][i] == key:
                column_cnt[i] += 1
    return row_cnt, column_cnt


num = int(input())
city_map = [''] * num
for i in range(num):
    city_map[i] = input()
blue_in_row, blue_in_column = count_in_map(city_map, 'B')
total_point = calc_point(blue_in_row) + calc_point(blue_in_column)
print(total_point)
