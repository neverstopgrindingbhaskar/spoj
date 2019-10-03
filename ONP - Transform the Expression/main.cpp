#include<iostream>
#include<string>
#include<stack>
using namespace std;
void findAns(string str)
{
string aux;
stack<char>s1;
for(int i=0;i<str.size();i++)
{
if(str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]=='^')
s1.push(str[i]);
else if(str[i]==')')
{
while(s1.top()!='(')
{
aux+=s1.top();
s1.pop();
}
s1.pop();
}
else
aux+=str[i];
}
cout<<aux<<endl;
}
int main()
{
int testcases;
cin>>testcases;
string str;
for(int i=0;i<testcases;i++)
{
cin>>str;
findAns(str);
}
return 0;
}
