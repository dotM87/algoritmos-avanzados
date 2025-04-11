numeros = list(map(int, input().split()))
res  = 4 - len(set(numeros))
print(res)
