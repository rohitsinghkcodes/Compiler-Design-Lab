#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int main(){
	string s; 
	getline(cin, s);
	int n=s.size();
	unordered_set<int> st;
	// For +
	st.insert(43); 
	//For - 
	st.insert(45); 
	//For *
	st.insert(42); 
	//For /
	st.insert(47);
	//For =
	st.insert(61);  //=
	
	//Initialisation
	int opr=0, cons=0, var=0, i=0;

	while(i<n){
		if (int(s[i])>=48 && int(s[i])<=57){
			cons++;
			while(i<n && int(s[i])>=48 && int(s[i])<=57)
				i++;
		}

		else if ((int(s[i])>=65 && int(s[i])<=90) || (int(s[i])>=97 && int(s[i])<=122)){
			var++;
			while(i<n && ((int(s[i])>=65 && int(s[i])<=90) || (int(s[i])>=97 && int(s[i])<=122) || (int(s[i])>=48 && int(s[i])<=57))){
				i++;
			}
		}

		else if(st.find(int(s[i]))!=st.end()){
			opr++;
			i++;
		}
		else if (int(s[i])==32){

			i++;
		}	

	}
	cout<<"There are "<<endl<<opr<<" operators, "<<endl<<cons<<" Constants"<<endl<<var<<" Variables"<<endl;

}
