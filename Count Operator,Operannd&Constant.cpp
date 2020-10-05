#include<bits/stdc++.h>
using namespace std;
int main(){
	string s; getline(cin, s);
	int n=s.size();
	unordered_set<int> op;
	op.insert(43);  //+
	op.insert(45);  //-
	op.insert(42);  //*
	op.insert(47);  // /
	op.insert(61);  //=
	
	//char 65 to 90 and 97 to 122
	// const 48 to 57
	int oper=0;
	int con=0;
	int var=0;
	int i=0;
	while(i<n){
		if (int(s[i])>=48 && int(s[i])<=57){
			con++;
			while(i<n && int(s[i])>=48 && int(s[i])<=57)
				i++;
		}

		else if ((int(s[i])>=65 && int(s[i])<=90) || (int(s[i])>=97 && int(s[i])<=122)){
			var++;
			while(i<n && ((int(s[i])>=65 && int(s[i])<=90) || (int(s[i])>=97 && int(s[i])<=122) || (int(s[i])>=48 && int(s[i])<=57))){
				i++;
			}
		}

		else if(op.find(int(s[i]))!=op.end()){
			oper++;
			i++;
		}
		else if (int(s[i])==32){

			i++;
		}	

	}
	cout<<"Operator "<<oper<<endl;
	cout<<"Constant "<<con<<endl;
	cout<<"Variable "<<var<<endl;

}
