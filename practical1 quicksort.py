def quickSort(a):

    if len(a) <= 1:
        return a

    pivot = a[0]

    left = []
    right = []

    for i in range(1, len(a)):

        if a[i] <= pivot:
            left.append(a[i])
        else:
            right.append(a[i])

    return quickSort(left) + [pivot] + quickSort(right)


a = [45, 12, 78, 34, 23]

a = quickSort(a)

print(a)