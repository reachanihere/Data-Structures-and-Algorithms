import sys
import os
import pandas as pd
from datetime import datetime
if(len(sys.argv)==1):
    raise  Exception("Filename should be given")
for i in sys.argv[1:]:
    ext = os.path.splitext(i)[-1].lower()
    if(ext!='.csv'):
        raise Exception("Wrong file or file path")
for i in sys.argv[1:]:
    try:
        s=open(i)
    except FileNotFoundError:
        raise Exception("File doesn't exist")
for i in sys.argv[1:]:
    file=pd.read_csv(i)
    a=file.shape[-1]
    if(a!=2):
        raise Exception("File with only two column is valid")
a=[]
for i in sys.argv[1:]:
    a.append(i)
result = pd.DataFrame()
log=[]
l=set(pd.read_csv(a[0]).iloc[:,0])
for i in a[1:]:
    l1=set(pd.read_csv(i).iloc[:0])
    l.union(l1)
l1=list(l)
result['Roll No']=l1
for i in a:
    df1 = pd.read_csv(i).fillna(0)
    list1 = []
    num1 = list(df1.iloc[:, 1])
    num2=list(df1.iloc[:,0])
    for j in range(len(num1)):
        try:
            k = int(num1[j])
        except:
            log.append([i,num2[j],num1[j]])
            list1.append(j)
    df1.drop(index=list1, inplace=True)
    df1 = df1.drop_duplicates(subset=[df1.columns[0]], keep='last')
    s1 = pd.Series(list(df1.iloc[:, 1]), list(df1.iloc[:, 0]))
    b=[]
    for j in l1:
        try:
            c=s1[j]
            b.append(c)
        except:
            b.append(0)
    c=i.split(".")
    result[c[0]]=b
flnm=str(datetime.now().strftime('%Y%m%d'))
result.to_csv('result'+flnm+'.csv',index=False)
log1=pd.DataFrame(log)
log1.to_csv('log'+flnm+'.csv',index=False,header=['Filename','Roll No.','Marks'])