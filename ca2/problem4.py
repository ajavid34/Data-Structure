all_num = input().split(',')
selected_num = input().split(',')
num_gp = 0
state = False
for i in range(len(all_num)):
    if not state and all_num[i] not in selected_num:
        continue
    elif all_num[i] not in selected_num:
        state = False
        num_gp += 1
    else:
        state = True
if state:
    num_gp += 1
print(num_gp)
