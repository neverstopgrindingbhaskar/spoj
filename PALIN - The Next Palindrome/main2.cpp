// TOOK ME 4 FUCKING DAYS 
#include<bits/stdc++.h> 
using namespace std;
void findAns(string str)
{
string ans,rev,tail;
int mid=str.size()/2;
for(int i=0;i<mid;i++)
{
rev+=str[i];
ans+=str[i];
}
reverse(rev.begin(),rev.end());
// IF THE STRING IS OF EVEN LENGTH
if(str.size()%2==0)
{
for(int i=mid;i<str.size();i++)
tail+=str[i];
if(rev>tail)
{
cout<<ans;
cout<<rev<<endl;
}
else
{
for(int j=mid-1;j>=0;j--)
ans.push_back(ans[j]);
ans[str.size()]='\0';
int low=mid-1;
int high=mid;
while(low>=0 && high<str.size())
{
if(ans[low]=='9')
{
ans[low]=48;
ans[high]=48;
low--;
high++;
}
else if(ans[low]=='0')
{
ans[low]=ans[low]+1;
ans[high]=ans[low];
break;
}
if(ans[low]!='9')
{
ans[low]=ans[low]+1;
ans[high]=ans[low];
break;
}
}
if(low<0 && high>=str.size())
{
cout<<1;
for(int i=0;i<str.size()-1;i++)
cout<<0;
cout<<1<<endl;
}
else
cout<<ans<<endl;
}
}
// IF THE LENGTH IS OF ODD LENGTH
else
{
for(int i=mid+1;i<str.size();i++)
tail+=str[i];
if(rev>tail)
{
cout<<ans;
cout<<str[mid];
cout<<rev<<endl;
}
else
{
int i=0;
ans.push_back(str[mid]);
for(int j=mid-1;j>=0;j--)
ans.push_back(ans[j]);
if(ans[mid]=='9')
{
ans[mid]=48;
int low=mid-1;
int high=mid+1;
while(low>=0 && high<str.size())
{
if(ans[low]=='9')
{
ans[low]=48;
ans[high]=48;
low--;
high++;
}
else if(ans[low]=='0')
{
ans[low]=ans[low]+1;
ans[high]=ans[low];
break;
}
if(ans[low]!='9')
{
ans[low]=ans[low]+1;
ans[high]=ans[low];
break;
}
}
ans[str.size()]='\0';
if(low<0 && high>=str.size())
{
cout<<1;
for(int i=0;i<str.size()-1;i++)
cout<<0;
cout<<1<<endl;
}
else
cout<<ans<<endl;
}
else
{
ans[mid]=ans[mid]+1;
cout<<ans<<endl;
}
}
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
if(str=="9")
cout<<"11"<<endl;
else
findAns(str);
}
return 0;
}
