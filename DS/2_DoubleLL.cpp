/*..................................
.....@ Vivek Ranjan ................
..................................*/

//doubly linked list all operations
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *prev;
	node *next;
};
node *head;
node *temp1;
node *current;
void insert_at_beg(int num);
void insert_at_end(int num);
void insert_at_pos();
void deletion();
void reverse();
void print();
void Print();

int main(){
	head = NULL;
	cout << "Enter the number of elements which you want to insert" << endl;
	int n;
	cin >> n;
	cout << "Enter the elements with spaces between them" << endl;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		//insert_at_beg(x);
		insert_at_end(x);
		print();
	}
	cout << "---Insertion at nth position---" << endl;
	insert_at_pos();
	cout << "---Reversed list---" << endl;
	reverse();
	cout << "Printing by iterative method" << endl;
	print();
	cout << "Printing by recursive method" << endl;
	current = head;
	Print();
	cout << "---Deletion of an element---" << endl;
	deletion();
	print();
	return 0;
}


//insertion at beginning
void insert_at_beg(int num){
	node *temp = new node();
	temp->data = num;
	temp->prev = NULL;
	temp->next = head;
	if(head!=NULL)
		head->prev = temp;
	head = temp;
}


//insertion at end
void insert_at_end(int num){
	node *temp = new node();
	temp->data = num;
	if(head==NULL){
		temp1 = temp;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
	}
	else{
		temp->next = NULL;
		temp->prev = temp1;
		temp1->next = temp;
		temp1 = temp;
	}
}


//insertion at nth position
void insert_at_pos(){
	cout << "Enter the position of insertion" << endl;
	int pos;
	cin >> pos;
	cout << "Enter the number to insert" << endl;
	int num;
	cin >> num;
	node *temp = new node();
	temp->data = num;
	current = head;
	for(int i=1;i<pos-1;i++){
		current = current->next;
	}
	if(pos==1){
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
	}
	else{
		temp->prev = current;
		temp->next = current->next;
		current->next = temp;
		current = temp->next;
		current->prev = temp;
	}
}


//deletion function
void deletion(){
	cout << "Enter the position of deletion" << endl;
	int pos;
	cin >> pos;
	current = head;
	for(int i=1;i<pos-1;i++){
		current = current->next;
	}
	if(pos==1){
		head = head->next;
	}
	else{
		temp1 = current;
		current = current->next;
		temp1->next = current->next;
		if(temp1->next!=NULL){
			current = current->next;
			current->prev = temp1;
		}
	}
}


//reverse function
void reverse(){
	current = head;
	while(current->next!=NULL){
		current = current->next;
	}
	while(current!=NULL){
		cout << current->data << " ";
		current = current->prev;
	}
	cout << endl;
}


//print function using recursion
void Print(){
	if(current==NULL){
		cout << endl;
		return ;
	}
	cout << current->data << " ";
	current = current->next;
	Print();
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
