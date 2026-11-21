key = eval(input("Enter a number: "))

found = False

for i in range(len(a)):
    if a[i] == key:
        print("Element found at index", i)
        found = True
        break

if found == False:
    print("Element not found")