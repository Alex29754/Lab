# s=open('24_8510.txt').readline()
s=s.replace('N','*').replace('O','*').replace('P','*')

while '**' in s:
    s=s.replace('**','* *')
print(max(len(c) for c in s.split()))
# s=[]
# print('Введите колличество  элементов в массиве')
# for i in range(int(input())):
#     s.append(int(input()))
# for i in s:
#     if str(i)[0]=='1':
#         print(sorted(s))