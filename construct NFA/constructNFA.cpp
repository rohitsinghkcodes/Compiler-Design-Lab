#include<bits/stdc++.h>
using namespace std;

int main()
{
  char s[10];
  int n,init=0,fin=1;
  cout<<"enter R.E\n";
  cin>>s;
  n=strlen(s);
  for(int i=0;i<n;i++)
  {
    if(s[i]=='*')
    fin+=2;
    if(s[i]=='.')
    fin+=1;
    if(s[i]=='/')
    fin+=4;
   }

  char c=238;
  int i=0;
  int ch;
  if(s[0]>=97&&s[0]<=122)
  ch=1;
  if(s[0]=='('&&s[4]==')')
  ch=2;
  switch(ch)
  {
   case 1:
   if(s[i+1]=='/')
    {
     if(s[i+2]>=97 && s[i+2]<=122)
      {
        cout<<"\n"<<init+2<<"--"<<s[i]<<"-->"<<init+3;
        cout<<"\n"<<init+4<<"--"<<s[i+2]<<"-->"<<init+5;
        goto pt1;
      }
     }

   case 2:
   if(s[i+1]>=97 && s[i+1]<=122)
   if(s[i+2]=='/')
  {
    if(s[i+3]>=97 && s[i+3]<=122)
    {
       cout<<"\n"<<init+2<<"--"<<s[i+1]<<"-->"<<init+3;
       cout<<"\n"<<init+4<<"--"<<s[i+3]<<"-->"<<init+5;

       if(s[i+5]=='*')
        {
          goto pt;
        }
     else
     goto pt1;
     }
  }
 }

 pt:
 cout<<"\n"<<init<<"--"<<c<<"-->"<<init+1; 
 cout<<"\n"<<init<<"--"<<c<<"-->"<<fin;

 pt1:
 cout<<"\n"<<init+1<<"--"<<c<<"-->"<<init+2; 
 cout<<"\n"<<init+1<<"--"<<c<<"-->"<<init+4;
 cout<<"\n"<<init+3<<"--"<<c<<"-->"<<init+6;
 cout<<"\n"<<init+5<<"--"<<c<<"-->"<<init+6;
 cout<<"\n"<<init+6<<"--"<<c<<"-->"<<init+1;
 cout<<"\n"<<init+6<<"--"<<c<<"-->"<<fin;
 return 0;
}
