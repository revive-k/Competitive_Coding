/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Infix to Postfix using stack
#include <bits/stdc++.h>
using namespace std;
string ans;
stack <char> s;
void postfix(string a);
int precedence(char x);

int main(){
	cout << "Enter the infix expression" << endl;
	string S;
	cin >> S;
	postfix(S);
	cout << "The required postfix expression is : ";
	cout << ans << endl;
	return 0;
}


//infix to postfix solve function
void postfix(string a){
	for(int i=0;i<a.length();i++){
		if(isdigit(a[i])){
			ans = ans + a[i];
		}
		else if(a[i]=='('){
			s.push(a[i]);
		}
		else if(a[i]==')'){
			while(s.top()!='('){
				ans = ans + s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty() && precedence(a[i]) && s.top()!='('){
				ans = ans + s.top();
				s.pop();
			}
			s.push(a[i]);
		}
	}
	while(!s.empty()){
		ans = ans + s.top();
		s.pop();
	}
}


//precedence function
int precedence(char x){
	if(s.top()=='%'){
		return 1;
	}
	else if((s.top()=='*' || s.top()=='/') && x!='%'){
		return 1;
	}
	else if((s.top()=='+' || s.top()=='-') && (x!='*' && x!='/' && x!='%')){
		return 1;
	}
	else{
		return 0;
	}
}