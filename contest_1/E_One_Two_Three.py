n = int(input())

def verificar(x):
    if len(x) == 5:
        return 3
    if x[0] == 'o' and x[1] == 'n' or x[0] == 'o' and x[2] == 'e' or x[1] == 'n' and x[2] == 'e':
        return 1
    return 2

for _ in range(n):
    x  = input()
    print(verificar(x))