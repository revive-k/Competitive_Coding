/*..................................
.....@ Vivek Ranjan ................
..................................*/

//creation of stack using two queues
#include <bits/stdc++.h>
using namespace std;
queue <int> q1;
queue <int> q2;
int ans;
void push();
void pop();
void Top();
void IsEmpty();
void Size();
void print();

int main(){
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
		if(x==1 || x==2){
			if(q1.empty() and q2.empty())
				cout << "No element in the stack" << endl;
			else
				print();
		}
	}
	return 0;
}


//push function
void push(){
	int num;
	cin >> num;
	ans = num;
	if(!q1.empty()){
		q1.push(num);
	}
	else{
		q2.push(num);
	}
}


//pop function
void pop(){
	if(!q1.empty()){
		while(q1.size()>1){
			q2.push(q1.front());
			ans = q1.front();
			q1.pop();
		}
		q1.pop();
	}
	else if(!q2.empty()){
		while(q2.size()>1){
			q1.push(q2.front());
			ans = q2.front();
			q2.pop();
		}
		q2.pop();
	}
}


//Top function
void Top(){
	if(q1.empty() and q2.empty()){
		cout << "No element in the stack" << endl;
	}
	else{
		cout << "The top element is :" << ans << endl;
	}
}


//IsEmpty function
void IsEmpty(){
	if(q1.empty() and q2.empty()){
		cout << "The stack is empty" << endl;
	}
	else
		cout << "The stack is not empty" << endl;
}


//Size function
void Size(){
	cout << "The size is :";
	if(!q1.empty())
		cout << q1.size() << endl;
	else
		cout << q2.size() << endl;
}


//print function
void print(){
	cout << "The stack is :";
	if(!q1.empty()){
		while(!q1.empty()){
			cout << q1.front() << " ";
			q2.push(q1.front());
			q1.pop();
		}
	}
	else{
		while(!q2.empty()){
			cout << q2.front() << " ";
			q1.push(q2.front());
			q2.pop();
		}
	}
	cout << endl;
}