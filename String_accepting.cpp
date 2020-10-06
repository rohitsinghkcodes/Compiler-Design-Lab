#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    int n,i;
    cout<<"Enter the string: ";
    cin>>a;
    n = a.length();
    if((a[0]=='a')or (a[n-1]=='b') and (a[n-2]=='c'));
    {
        for(i=1;i<n-2;i++)
        {
            if(a[i]!='b')
            {
                printf("string is not accepted");
                exit(0);  
            }
        }
    }cout<<"accepted"<<endl;

    return 0;
}