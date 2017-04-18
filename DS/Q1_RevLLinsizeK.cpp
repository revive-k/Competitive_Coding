//Reverse a Linked List in groups of given size 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
node* head = NULL;
void insert(int num);
node* reverse(node* Head,int z);
void print();

int main(){
	cout << "Enter the number of elements" << endl;
	int n;
	cin >> n;
	cout << "Enter the elements" << endl;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		insert(x);
	}
	print();
	cout << "Enter the group size" << endl;
	int size;
	cin >> size;
	head = reverse(head,size);
	print();
	return 0;
}

void insert(int num){
	node* temp = new node;
	temp->data = num;
	temp->next = head;
	head = temp;
}

void print(){
	cout << "The list is : ";
	node* current = head;
	while(current!=NULL){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

node* reverse(node* Head,int k){
	node* current = Head;
	node* prev = NULL;
	node* next = NULL;
	int count=0;
	while(current!=NULL and count<k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next!=NULL)
		Head->next = reverse(next,k);
	return prev;
}