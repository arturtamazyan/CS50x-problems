# Height
h = 0
while (h < 1 or h > 8):
    try:
        h = int(input("Height: "))
    except:
         if not isinstance(h, int):
            continue
n = 1
for i in range(h):
    for j in range(h - n):
        print(" ", end='')
    for k in range(n):
        print('#', end='')
    print("  ", end='')
    for k in range(n):
        print('#', end='')
    n += 1
    print()
