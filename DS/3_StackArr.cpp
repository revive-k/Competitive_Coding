/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of stack using array
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int top=-1;
void push(int num);
void pop();
void Top();
void isEmpty();
void Size();
void print();

int main(){
	cout << "Enter the number of elements which you want to push" << endl;
	int n;
	cin >> n;
	cout << "Enter the elements with spaces between them" << endl;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		push(x);
		print();
	}
	cout << "---Stack after Pop---" << endl;
	pop();
	print();
	cout << "---Element at top of stack---" << endl;
	Top();
	cout << "---IsEmpty---" << endl;
	isEmpty();
	cout << "---Size---" << endl;
	Size();
	return 0;
}


//push function
void push(int num){
	top++;
	a[top] = num;
}


//pop function
void pop(){
	top--;
}


//Top function
void Top(){
	cout << a[top] << endl;
}


//Size function
void Size(){
	cout << top+1 << endl;
}


//IsEmpty function
void isEmpty(){
	if(top==-1){
		cout << "Stack is empty" << endl;
	}
	else{
		cout << "Stack is not empty" << endl;
	}
}


//print function
void print(){
	for(int i=0;i<=top;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}