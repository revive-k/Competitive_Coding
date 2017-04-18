/*..................................
.....@ Vivek Ranjan ................
..................................*/

//reversal of LL using stack
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
node *current;
void insert_at_beg(int num);
void reverse();
void print();

int main(){
	cout << "First LL will be created to be reversed" << endl;
	cout << "Enter the number of elements which you want to insert" << endl;
	int n;
	cin >> n;
	cout << "Enter the elements with space" << endl;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		insert_at_beg(x);
	}
	cout << "---LL created is---" << endl;
	print();
	reverse();
	cout << "---LL after getting reversed by using stack---" << endl;
	print();
	return 0;
}


//reverse function 
void reverse(){
	current = head;
	stack <node*> s;
	node *temp = new node();
	while(current!=NULL){
		s.push(current);
		current = current->next;
	}
	head = s.top();
	temp = head;
	s.pop();
	while(!s.empty()){
		temp->next = s.top();
		s.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}


//function to insert at beginning
void insert_at_beg(int num){
	node *temp = new node();
	temp->data = num;
	temp->next = head;
	head = temp;
}


//print function
void print(){
	current = head;
	while(current!=NULL){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}