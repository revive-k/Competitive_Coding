/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of stack using linked list
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *top;
node *current;
void push();
void pop();
void Top();
void IsEmpty();
void Size();
void print();

int main(){
	top = NULL;
	int x;
	for(;;){
		cout << "Enter your choice" << endl;
		cout << "1.Push\n2.Pop\n3.Top\n4.IsEmpty\n5.Size\n6.Exit" << endl;
		cin >> x;
		switch(x){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:Top();
			break;
			case 4:IsEmpty();
			break;
			case 5:Size();
			break;
			case 6:return 0;
			default:cout << "Enter correct choice" << endl;
		}
		if(top!=NULL && (x==1 || x==2)){
			cout << "---Stack is---" << endl;
			print();
		}
	}
	return 0;
}


//push function
void push(){
	cout << "Enter the element" << endl;
	int x;
	cin >> x;
	node *temp = new node();
	temp->data = x;
	temp->next = top;
	top = temp;
}


//pop function
void pop(){
	if(top==NULL){
		cout << "No element in stack" << endl;
	}
	else 
		top = top->next;
}


//Top function
void Top(){
	if(top==NULL){
		cout << "No element in stack" << endl;
	}
	else
		cout << "Element at the top is :" << top->data << endl;
}


//IsEmpty function
void IsEmpty(){
	if(top==NULL){
		cout << "Stack is empty" << endl;
	}
	else{
		cout << "Stack is not empty" << endl;
	}
}


//Size function
void Size(){
	current = top;
	int count=0;
	while(current!=NULL){
		current = current->next;
		count++;
	}
	cout << "Size of the stack is :" << count << endl;
}


//print function
void print(){
	current = top;
	while(current!=NULL){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << endl;
}