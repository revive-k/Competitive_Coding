/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Evaluation of Prefix and Postfix expressions using stack
#include <bits/stdc++.h>
using namespace std;
int solve(int p,int q,char c);
void prefix();
void postfix();

int main(){
	for(;;){
		cout << "1.Prefix Calculation\n2.Postfix Calculation\n3.Exit" << endl;
		cout << "Enter your choice" << endl;
		int x;
		cin >> x;
		switch(x){
			case 1:prefix();
			break;
			case 2:postfix();
			break;
			case 3:return 0;
			default:cout << "Enter correct choice" << endl;
		}
	}
	return 0;
}


//solve function
int solve(int p,int q,char c){
	if(c=='+')
		return (p+q);
	if(c=='-')
		return (p-q);
	if(c=='*')
		return (p*q);
	if(c=='/')
		return (p/q);
	if(c=='%')
		return (p%q);
}


//function to evaluate prefix
void prefix(){
	cout << "Enter the expression to evaluate" << endl;
	string s;
	cin >> s;
	stack <int> st;
	for(int i=s.length()-1;i>=0;i--){
		if(isdigit(s[i])){
			int z = s[i]-'0';
			st.push(z);
		}
		else{
			int p = st.top();
			st.pop();
			int q = st.top();
			st.pop();
			int r = solve(p,q,s[i]);
			st.push(r);
		}
	}
	cout << "Value is :" << st.top() << endl;
}


//function to evaluate postfix
void postfix(){
	cout << "Enter the expression to evaluate" << endl;
	string s;
	cin >> s;
	stack <int> st;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			int z = s[i]-'0';
			st.push(z);
		}
		else{
			int q = st.top();
			st.pop();
			int p = st.top();
			st.pop();
			int r = solve(p,q,s[i]);
			st.push(r);
		}
	}
	cout << "Value is :" << st.top() << endl;
}