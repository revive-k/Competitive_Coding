/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of queue using array
#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int front = -1;
int rear = -1;
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
		if(rear!=-1 and (x==1 or x==2)){
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
	if(front==-1 and rear==-1){
		front++;
		rear++;
	}
	else{
		rear++;
	}
	a[rear] = num;
}


//dequeue function
void dequeue(){
	if(front==-1 and rear==-1){
		cout << "Queue is empty" << endl;
	}
	else{
		front++;
	}
	if(front>rear){
		front = -1;
		rear = -1;
	}
}


//Front function
void Front(){
	if(front==-1 and rear==-1){
		cout << "No element in the queue" << endl;
	}
	else{
		cout << "The front element is :" << a[front] << endl;
	}
}


//IsEmpty function
void IsEmpty(){
	if(front==-1 and rear==-1){
		cout << "Queue is empty" << endl;
	}
	else{
		cout << "Queue is not empty" << endl;
	}
}


//Size function
void Size(){
	if(front==-1 and rear==-1){
		cout << "Size of queue is :" << 0 << endl;
	}
	else{
		cout << "Size of queue is :" << rear-front+1 << endl;
	}
}


//print function
void print(){
	cout << "Queue is : ";
	for(int i=front;i<=rear;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}