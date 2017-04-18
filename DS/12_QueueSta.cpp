/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of queue using two stacks
#include <bits/stdc++.h>
using namespace std;
stack <int> s1;
stack <int> s2;
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
		if(x==1 or x==2){
			if(s1.empty() and s2.empty())
				cout << "No element in queue" << endl;
			else{
				print();
			}
		}
	}
	return 0;
}


//enqueue function
void enqueue(){
	cout << "Enter the number" << endl;
	int num;
	cin >> num;
	s1.push(num);
}


//dequeue function
void dequeue(){
	if(!s2.empty()){
		s2.pop();
	}
	else if(!s1.empty()){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
	}
}


//Front function
void Front(){
	if(s1.empty() and s2.empty())
		cout << "No element in queue" << endl;
	else if(!s2.empty()){
		cout << "Front element is : " << s2.top() << endl;
	}
	else{
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		cout << "Front element is : " << s2.top() << endl;
	}
}


//IsEmpty function
void IsEmpty(){
	if(s1.empty() and s2.empty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;
}


//Size function
void Size(){
	cout << "Size of queue is : "; 
	cout << s1.size() + s2.size() << endl;
}


//print function
void print(){
	cout << "Queue is : ";
	stack <int> s3;
	while(!s2.empty()){
		cout << s2.top() << " ";
		s3.push(s2.top());
		s2.pop();
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		cout << s2.top() << " ";
		s3.push(s2.top());
		s2.pop();
	}
	while(!s3.empty()){
		s2.push(s3.top());
		s3.pop();
	}
	cout << endl;
}