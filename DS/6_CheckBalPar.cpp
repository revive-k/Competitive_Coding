/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Checking balanced parentheses
#include <bits/stdc++.h>
using namespace std;
bool check(string x);

int main(){
	cout << "Enter the string to check" << endl;
	string s;
	cin >> s;
	bool ans = check(s);
	if(ans==true)
		cout << "Parentheses is balanced" << endl;
	else
		cout << "Parentheses is not balanced" << endl;
	return 0;
}


//check function
bool check(string x){
	stack <char> st;
	for(int i=0;i<x.length();i++){
		if(x[i]=='(' || x[i]=='{' || x[i]=='['){
			st.push(x[i]);
		}
		else if(x[i]==')' || x[i]=='}' || x[i]==']'){
			if(st.empty()){
				return false;
			}
			else{
				if(x[i]==')'){
					if(st.top()!='(')
						return false;
					else
						st.pop();
				}
				if(x[i]=='}'){
					if(st.top()!='{')
						return false;
					else
						st.pop();
				}
				if(x[i]==']'){
					if(st.top()!='[')
						return false;
					else
						st.pop();
				}
			}
		}
	}
	if(st.empty())
		return true;
}