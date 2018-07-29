a,b = input().split(' ')
a = int(a)
b = int(b)

# print("a:",a,"   b:",b)
ac = a
bc = b
val = 0

while bc>0 :
    bc-=1
    # print(2**bc)
    val += 2**bc

# print("val",val)

lis = []
ok=0

while ac>0 :
    t = input()
    lis.append(int(t,2))
    ac-=1

i = 0
j = 0

while i<a :
    t = 0
    j = 0

    while (j<a):
        if(j==i):
            j+=1
            continue
        # print("i:" , t)
        t = t^lis[j]
        j+=1
    # print(t)
    if (t==val):
        ok = 1
        break

    i+=1

if(ok==1):
    print("YES")
else:
    print("NO")
