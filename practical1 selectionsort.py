a = [45, 12, 78, 34, 23]

for i in range(len(a)):
    pos = i

    for j in range(i + 1, len(a)):
        if a[j] < a[pos]:
            pos = j

    temp = a[i]
    a[i] = a[pos]
    a[pos] = temp

print(a)