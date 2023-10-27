#include <iostream>
using namespace std;

string stuffing(string a)
{
string b;
int i=0,cnt=0,j=0;
for(i=0;i<a.size();i++)
{
if(a[i]=='1'){
cnt++;
b.push_back(a[i]);
}
else
{
cnt=0;
b.push_back(a[i]);
}if(cnt==5)
{
cnt=0;
b.push_back('0');
}
}
return b;
}

string destuffing(string a)
{
int i=0,cnt=0;
string b;
for(int i=0;i<a.size();i++)
{
if(a[i]=='1')
{
cnt++;
b.push_back(a[i]);
}
else
{
cnt=0;
b.push_back(a[i]);
}
if(cnt==5)
{
cnt=0;
if(a[i]=='0'){
b.push_back(a[i]);
}
i++;
}
}
return b;
}

int main() {
string a;
cout<<"Enter the data ";
cin>>a;
string b=stuffing(a);
cout<<"Data after stuffing "<<b<<endl;
cout<<"Data after destuffing ";
cout<<destuffing(b)<<endl;
return 0;
}


/* 
Input = 1111111111111111
Data after stuffing 1111101111101111101
Data after destuffing 1111111111111111
*/

