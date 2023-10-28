#include <bits/stdc++.h>
using namespace std;

bool check(string d, string c, int i) {
int a=1;
bool b;
for(int j=i+2;j<=(i+c.size());j++) {
if(d[j]==c[a++]&&d[j]>=65&&d[j]<=90)
b=true;
else
b=false;
}
return b;
}

string Destuffing (string data, string cchar) {
string tdata="";
int s=data.size();
for (int i=0;i<(s-1);i++) {
tdata+=data[i];
if(data[i]==' '&&(data[i+1]==cchar[0])) {
if(check(data,cchar,i))
i+=1+cchar.size();
}
}
tdata+=data[s-cchar.size()-1];
return tdata;
}

string Stuffing(string data, string cchar) {
string tdata="";
int s=data.size();
int j;
for (int i=0;i<(s-1);i++) {
tdata+=data[i];
if (data[i]==' '&&(data[i+1]==cchar[0])) {
int a=1;
bool c;
for (j=i+2;j<=(i+cchar.size());j++) {
if (data[j]==cchar[a++]&&(data[i]>=65&&data[j]<=90))
c=true;
else
c=false;
}
if (check(data,cchar,i))
tdata+=cchar+' ';


}
}
tdata+=data[j-1];
tdata += " " + cchar;
return tdata;
}

int main() {
string data, cchar;
cout<<"Enter input data: ";
getline(cin, data);
cout<<"Enter control character: ";
cin>>cchar;
cout<<"CHARACTER STUFFING"<<endl;
cout<<"Data before character stuffing: "<<data<<endl;
string s=Stuffing(data,cchar);
cout<<"Data after character stuffing: "<<s<<endl;
string t=Destuffing(s,cchar);
cout<<endl<<"CHARACTER DESTUFFING"<<endl;
cout<<"Data before character De-stuffing: "<<s<<endl;
cout<<"Data after Destuffing: "<<t<<endl;
return 0;
}

/*
Enter input data: We are performing character stuff and de stuff
Enter control character: stuff
CHARACTER STUFFING
Data before character stuffing: We are performing character stuff and de stuff
Data after character stuffing: We are performing character stuff and de stuff stuff

CHARACTER DESTUFFING
Data before character De-stuffing: We are performing character stuff and de stuff stuff
Data after Destuffing: We are performing character stuff and de stuff stuf
*/
