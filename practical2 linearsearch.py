a = [12, 45, 23, 67, 34]
key = int(input("Enter number to search: "))

found = False

for i in range(len(a)):
    if a[i] == key:
        print("Element found at index", i)
        found = True
        break

if found == False:
    print("Element not found")