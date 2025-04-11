n = int(input())
sum = 0
numeros = list(map(int, input().split()))
for p in numeros:
    sum += p

res= "{:.12f}".format(sum/n)
print(res)