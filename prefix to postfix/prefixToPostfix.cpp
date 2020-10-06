// Program for prefix to postfix conversion
#include <iostream> 
#include <stack> 
using namespace std; 
  
bool isOperator(char x) { 
  switch (x) { 
  case '+': 
  case '-': 
  case '/': 
  case '*': 
    return true; 
  } 
  return false; 
} 
  
string preToPost(string preExpression) { 
  
  stack<string> s;
  int length = preExpression.size(); 
  
  for (int i = length - 1; i >= 0; i--) { 

    if (isOperator(preExpression[i])) { 

      string op1 = s.top(); s.pop(); 
      string op2 = s.top(); s.pop(); 
      string temp = op1 + op2 + preExpression[i]; 
      s.push(temp); 
    } 
  
    else s.push(string(1, preExpression[i])); 
  } 
  
  return s.top(); 
} 
int main() { 
  string preExpression;
  cin>>preExpression; 
  cout << "Postfix expression is: " << preToPost(preExpression)<<endl; 
  return 0; 
} 
