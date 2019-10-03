// ANSWER IS CORRECT BUT I DONT LIKE INDENTING MY CODE :)
#include<iostream>
using namespace std;
// FOR ADDING TWO STRINGS
string adder(string str1,string str2)
{
string aux;
int carry,rem;
carry=0;
if(str1.size()<str2.size())
{
int j=str1.size()-1;
int i;
for(i=str2.size()-1;i>=0 && j>=0;i--,j--)
{
rem=(str1[j]-'0'+str2[i]-'0'+carry)%10;
aux.insert(aux.begin(),rem+'0');
carry=(str1[j]-'0'+str2[i]-'0'+carry)/10;
}
while(carry && i>=0)
{
rem=(str2[i]-'0'+carry)%10;
aux.insert(aux.begin(),rem+'0');
carry=(str2[i]-'0'+carry)/10;
i--;
}
while(i>=0)
{
aux.insert(aux.begin(),str2[i]);
i--;
}
if(carry)
aux.insert(aux.begin(),carry+'0');
}
else
{
int j=str2.size()-1;
int i=str1.size()-1;
carry=0;
while(i>=0 && j>=0)
{
rem=(str1[i]-'0'+str2[j]-'0'+carry)%10;
aux.insert(aux.begin(),rem+'0');
carry=(str1[i]-'0'+str2[j]-'0'+carry)/10;
i--;
j--;
}
while(carry && i>=0)
{
rem=(str1[i]-'0'+carry)%10;
aux.insert(aux.begin(),rem+'0');
carry=(str1[i]-'0'+carry)/10;
i--;
}
while(i>=0)
{
aux.insert(aux.begin(),str1[i]);
i--;
}
if(carry)
aux.insert(aux.begin(),carry+'0');
}
return aux;
}
// FOR SUBTRACTING TWO STRINGS
void suber(string str1,string str2)
{
string aux;
int borrow=0;
int j=str2.size()-1;
int i;
for(i=str1.size()-1;i>=0 && j>=0;i--,j--)
{
if(str1[i]-'0'>=str2[j]-'0')
aux.insert(aux.begin(),(str1[i]-'0')-(str2[j]-'0')+'0');
else
{
for(int k=i-1;k>=0;k--)
{
if(str1[k]=='0')
str1[k]=57;
else
{
str1[k]=str1[k]-1;
break;
}
}
int num1=str1[i]-48;
num1+=10;
int num2=str2[j]-48;
int num3=num1-num2;
aux.insert(aux.begin(),num3+'0');
}
}
while(i>=0)
{
aux.insert(aux.begin(),str1[i]);
i--;
}
cout<<" "<<aux<<endl;
}
// FOR MULTIPLYING TWO NUMBERS
void muller(string str1,string str2)
{
string ans;
for(int i=0;i<=10;i++)
ans[i]='0';
string aux;
int count=0;
int rem;
int carry=0;
for(int j=str2.size()-1;j>=0;j--)
{
aux="";
for(int k=0;k<count;k++)
aux.insert(aux.begin(),'0');
carry=0;
int num1=str2[j]-48;
for(int i=str1.size()-1;i>=0;i--)
{
int num2=str1[i]-48;
rem=((num1*num2)+carry)%10;
aux.insert(aux.begin(),rem+'0');
carry=((num1*num2)+carry)/10;
}
if(carry)
aux.insert(aux.begin(),carry+'0');
cout<<aux<<endl;
count++;
ans=adder(aux,ans);
cout<<ans<<endl;
}
cout<<ans<<endl;
}
void findAns(string str)
{
int add=0;
int sub=0;
int mul=0;
for(int i=0;i<str.size();i++)
{
if(str[i]=='+')
{
add=1;
break;
}
else if(str[i]=='-')
{
sub=1;
break;
}
else if(str[i]=='*')
{
mul=1;
break;
}
}
string number1,number2;
int flag=0;
for(int i=0;i<str.size();i++)
{
if(str[i]=='+'||str[i]=='-'||str[i]=='*')
flag=1;
if(flag==0)
number1+=str[i];
else if(flag==1 && isdigit(str[i]))
number2+=str[i];
}
if(add==1)
{
if(number1.size()==number2.size())
{
cout<<" "<<number1<<endl;
cout<<"+"<<number2<<endl;
}
for(int i=0;i<=number2.size();i++)
cout<<"-";
cout<<endl;
string ans=adder(number1,number2);
cout<<" "<<ans<<endl;
}
else if(sub==1)
{
if(number1.size()==number2.size())
{
cout<<" "<<number1<<endl;
cout<<"-"<<number2<<endl;
}
for(int i=0;i<=number2.size();i++)
cout<<"-";
cout<<endl;
suber(number1,number2);
}
else if(mul==1)
{
cout<<number1<<endl;
cout<<number2<<endl;
for(int i=0;i<=number2.size();i++)
cout<<"-";
cout<<endl;
muller(number1,number2);
}
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
cout<<endl;
}
return 0;
}
