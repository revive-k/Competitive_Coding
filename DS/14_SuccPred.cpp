/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Inorder successor and predecessor in a BST
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* root = NULL;
node* Getnewnode(int num);
void insert(node* current,int data);
void inorder(node* current);
int InorderSuccessor(int data);
int findmin(node* current);
node* search(node*current,int data);
int InorderPredecessor(int data);
int findmax(node* current);

int main(){
	cout << "Enter the number of elements to insert" << endl;
	int n;
	cin >> n;
	cout << "Enter the elements" << endl;
	while(n){
		int data;
		cin >> data;
		insert(root,data);
		n--;
	}
	cout << "The tree is : ";
	inorder(root);
	cout << endl;
	cout << "Enter the element to find successor and predecesssor" << endl;
	int num;
	cin >> num;
	int x = InorderSuccessor(num);
	if(x==0)
		cout << "No successor" << endl;
	else
		cout << "Successor is : " << x << endl;
	int y = InorderPredecessor(num);
	if(y==0)
		cout << "No predecessor" << endl;
	else
		cout << "Predecessor is : " << y << endl;
	return 0;
}


//function to create new node
node* Getnewnode(int num){
	node* temp = new node;
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


//function to insert(iterative approach)
void insert(node* current,int data){
	if(current==NULL)
		root = Getnewnode(data);
	else{
		while(1){
			if(data <= current->data){
				if(current->left==NULL){
					node* mark = Getnewnode(data);
					current->left = mark;
					break;
				}
				else
					current = current->left;
			}
			else{
				if(current->right==NULL){
					node* mark = Getnewnode(data);
					current->right = mark;
					break;
				}
				else
					current = current->right;
			}
		}
	}
}


//inorder traversal(print)
void inorder(node* current){
	if(current==NULL)
		return ;
	inorder(current->left);
	cout << current->data << " ";
	inorder(current->right);
}


//function to search address of data(used in InorderSuccessor function and InorderPredecessor function)
node* search(node* current,int data){
	if(current==NULL) return NULL;
	if(current->data == data) return current;
	if(data <= current->data)
		search(current->left,data);
	else
		search(current->right,data);
}


//function to find minimum element(used in InorderSuccessor function)
int findmin(node* current){
	while(current->left!=NULL)
		current = current->left;
	return (current->data);
}


//function to find Inorder Successor
int InorderSuccessor(int data){
	node* temp = search(root,data);
	if(temp==NULL) return 0;
	if(temp->right!=NULL)
		return findmin(temp->right);
	else{
		node* successor = NULL;
		node* ancestor = root;
		while(ancestor != temp){
			if(data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		if(successor!=NULL)
			return (successor->data);
		else
			return 0;
	}
}


//function to find maximum element(used in InorderPredecessor function)
int findmax(node* current){
	while(current->right!=NULL)
		current = current->right;
	return (current->data);
}


//function to find Inorder Predecessor
int InorderPredecessor(int data){
	node* temp = search(root,data);
	if(temp==NULL) return 0;
	if(temp->left!=NULL)
		return findmax(temp->left);
	else{
		node* predecessor = NULL;
		node* ancestor = root;
		while(ancestor != temp){
			if(data > ancestor->data){
				predecessor = ancestor;
				ancestor = ancestor->right;
			}
			else
				ancestor = ancestor->left;
		}
		if(predecessor!=NULL)
			return (predecessor->data);
		else
			return 0;
	}
}