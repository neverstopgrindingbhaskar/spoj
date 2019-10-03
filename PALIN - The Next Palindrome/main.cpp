#include<iostream>
using namespace std;
bool ispalin(long long  num)
{
string aux=to_string(num);
int i=0;
int j=aux.size()-1;
while(i<j)
{
if(aux[i]==aux[j])
{
i++;
j--;
}
else
return false;
}
return true;
}
void findAns(long long  num)
{
num++;
while(!ispalin(num))
num++;
printf("%lld\n",num);
}
int main()
{
int n=1000000;
int testcases;
scanf("%d",&testcases);
long long num;
bool palin[n];
for(int i=1;i<=n;i++)
palin[i]=true;
for(int i=1;i<=n;i++)
{
bool yes=ispalin(i);
if(yes);
else
palin[i]=false;
}
for(int i=0;i<testcases;i++)
{
scanf("%lld",&num);
if(num<n)
{
for(int j=num+1;j<=n;j++)
{
if(palin[j])
{
printf("%d\n",j);
break;
}
}
}
else
findAns(num);
}
return 0;
}
