#include<iostream>
#include <string.h>
using namespace std;

int main()
{
    char gramm[20][20], c;
    int i, n, j = 2, setFlag = 0;

    cout<<"Enter the no of productions: ";
    cin>>n;
    cout<<"Enter the productions: "<<endl;
    for (i = 0; i < n; i++)
        cin>>gramm[i];

    for (i = 0; i < n; i++)
    {
        c = gramm[i][2];

        while (c != '\0')
        {
            if (gramm[i][3] == '+' or gramm[i][3] == '-' or gramm[i][3] == '*' or gramm[i][3] == '/') setFlag = 1;
            else
            {
                setFlag = 0;
                cout<<"It is not operator precedence grammar"<<endl;
                exit(0);
            }
            if (c == '$')
            {
                setFlag = 0;
                cout<<"It is not operator precedence grammar"<<endl;
                exit(0);
            }
            c = gramm[i][++j];
        }
    }

    if (setFlag == 1) cout<<"It is operator precedence grammar"<<endl;
    return 0;
}