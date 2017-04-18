/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of queue using LL
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *front = NULL;
node *rear = NULL;
void enqueue();
void dequeue();
void Front();
void IsEmpty();
void Size();
void print();

int main(){
	for(;;){
	cout << "1.Enqueue\n2.Dequeue\n3.Front\n4.IsEmpty\n5.Size\n6.Exit" << endl;
	cout << "Enter your choice" << endl;
	int x;
	cin >> x;
	switch(x){
		case 1:enqueue();
		break;
		case 2:dequeue();
		break;
		case 3:Front();
		break;
		case 4:IsEmpty();
		break;
		case 5:Size();
		break;
		case 6:return 0;
		default:cout << "Enter correct choice" << endl;
		}
		if(rear!=NULL and (x==1 or x==2)){
			print();
		}
	}
	return 0;
}


//enqueue function
void enqueue(){
	cout << "Enter the number" << endl;
	int num;
	cin >> num;
	node *temp = new node;
	temp->data = num;
	temp->next = NULL;
	if(front == NULL and rear == NULL){
		front = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
}


//dequeue function
void dequeue(){
	if(front == NULL){
		cout << "Queue is empty" << endl;
	}
	else if(front == rear){
		front = NULL;
		rear = NULL;
	}
	else{
		front = front->next;
	}
}


//Front function
void Front(){
	if(front == NULL and rear == NULL){
		cout << "No element in the queue" << endl;
	}
	else{
		cout << "The front element is :" << front->data << endl;
	}
}


//IsEmpty function
void IsEmpty(){
	if(front == NULL and rear == NULL){
		cout << "Queue is empty" << endl;
	}
	else{
		cout << "Queue is not empty" << endl;
	}
}


//Size function
void Size(){
	node *current = front;
	int count=0;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	cout << "Size of queue is :" << count << endl;
}


//print function
void print(){
	cout << "Queue is : ";
	node *current = front;
	while(current!=NULL){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}