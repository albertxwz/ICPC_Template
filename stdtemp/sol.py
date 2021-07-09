for T in range(0,int(input())): #T组数据
    N=int(input())
    n,m=map(int,input().split())
    s=input()
    s=[int(x) for x in input().split()] #一行输入的数组
    a[1:]=[int(x) for x in input().split()] #从下标1开始读入一行
    for i in range(0,len(s)):
        a,b=map(int,input().split())

while True: #未知多组数据
	try:
		#n,m=map(int,input().split())
		#print(n+m,end="\n")
	except EOFError: #捕获到异常
		break
    