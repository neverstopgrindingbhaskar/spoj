#include<iostream>
#include<cmath>
using namespace std;
bool isprime(long long num)
{
for(int i=2;i<=sqrt(num);i++)
{
if(num%i==0)
return false;
}
return true;
}
void findAns(long long m,long long n)
{
for(long long i=m;i<=n;i++)
{
bool yes=isprime(i);
if(yes && i>1)
cout<<i<<endl;
}
cout<<endl;
}
int main()
{
int testcases;
long long n,m;
cin>>testcases;
for(int i=0;i<testcases;i++)
{
scanf("%lld %lld",&m,&n);
findAns(m,n);
}
return 0;
}
