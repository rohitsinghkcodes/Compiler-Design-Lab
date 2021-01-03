#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;

struct production
{
            char l;
            char r[10];
            int rear;
};
struct production prod[20],pr_new[20];        

int p=0,b=0,d,f,q,n,flag=0;
char terminal[20],nonterm[20],alpha[10];
char x,epsilon='^';

int main()
{

       cout<<"Enter the number of terminals: ";
    cin>>d;
    cout<<"Enter the terminal symbols for your production: ";
    for(int k=0;k<d;k++)
    {
      cin>>terminal[k];
    }

  
    cout<<"\nEnter the number of non-terminals: ";
    cin>>f;
    cout<<"Enter the non-terminal symbols for your production: ";
    for(int k=0;k<f;k++)
    {
      cin>>nonterm[k];
    }

 
    cout<<"\nEnter the number of Special characters(except non-terminals): ";
    cin>>q;
    cout<<"Enter the special characters for your production: ";
    for(int k=0;k<q;k++)
    {
      cin>>alpha[k];
    }

  
    cout<<"\nEnter the number of productions: ";
    cin>>n;
    for(int k=0;k<=n-1;k++)
    {
      cout<<"Enter the "<< k+1<<" production: ";
      cin>>prod[k].l;
      cout<<"->";
      cin>>prod[k].r;
      prod[k].rear=strlen(prod[k].r);
    }

 
    for(int m=0;m<f;m++)
    {
      x=nonterm[m];
      for(int j=0;j<n;j++)
      {
               if((prod[j].l==x)&&(prod[j].r[0]==prod[j].l))
                  flag=1;
      }
      for(int i=0;i<n;i++)
      {
               if((prod[i].l==x)&&(prod[i].r[0]!=x)&&(flag==1))
               {
                 int c;
                           pr_new[b].l=x;
                           for(c=0;c<prod[i].rear;c++)
                           pr_new[b].r[c]=prod[i].r[c];
                           pr_new[b++].r[c]=alpha[p];
               }
               else if((prod[i].l==x)&&(prod[i].r[0]==x)&&(flag==1))
               {
                 int a;
                          pr_new[b].l=alpha[p];
                          for(a=0;a<=prod[i].rear-2;a++)
                           pr_new[b].r[a]=prod[i].r[a+1];
                          pr_new[b++].r[a]=alpha[p];
                          pr_new[b].l=alpha[p];
                          pr_new[b++].r[0]=epsilon;
                }
                else if((prod[i].l==x)&&(prod[i].r[0]!=x)&&(flag==0))
                {
                           pr_new[b].l=prod[i].l;
                           strcpy(pr_new[b].r,prod[i].r);
                           b++;
                }
            }
            flag=0;
            p++;
  }

 
    cout<<"\n\n******* AFTER REMOVING LEFT RECURSION *******"<<endl;
    for(int s=0;s<=b-1;s++)
            {
                        cout<<"Production "<<s+1<<" is: ";
                        cout<<pr_new[s].l;
                        cout<<"->";
                        cout<<pr_new[s].r;
                        cout<<endl;
            }

    return 0;
}
