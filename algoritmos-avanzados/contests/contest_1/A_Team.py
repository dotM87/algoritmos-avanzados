n = int(input())
res = 0
 
def leer(m):
    aux = 0
    if ((int(m[0]) + int(m[2]) + int(m[4])) > 1):
        return True
    return False
 
for i in range(n):
    m = str(input())
    if leer(m):
        res+=1
 
print (res)