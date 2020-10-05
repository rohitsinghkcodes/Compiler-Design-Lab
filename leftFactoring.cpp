#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<set>
#include<cmath>
#include<numeric>
#define LL long long
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    vector<char> v(n);
    vector<string> v2;
    for(char &it:v) cin>>it;
    string first;
    string s="";
    for(char &it:v)
    {
        if(it=='>')
        {
            s+=it;
            first = s;
            s.clear();
        }
        
        else if(it=='|')
        {
            v2.push_back(s);
            s.clear();
        }
        else
        {
            s+=it;
        }
        
    }
    v2.push_back(s);
    for(string &it:v2) cout<<it<<endl;

int maxlen = 0;
    for(string &i:v2)
    {
        if(i.length()>maxlen)
        {
            maxlen = i.size();
        }
    }


    vector<char> sub;
    for(int i=0;i<maxlen;i++)
    {
        if(v2.at(0)[i] ==v2.at(1)[i])
        {
            sub.push_back(v2.at(0)[i]);
        }
    }

    return 0;
}