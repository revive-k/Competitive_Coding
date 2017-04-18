/*..................................
.....@ Vivek Ranjan ................
..................................*/

//BST tree and its all operations(using LL)
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
node* Getnewnode(int num);
node* insert(node* root,int data);
bool search(node* root,int data);
void Findmin(node* current);
void Findmax(node* current);
int Height(node* current);
void levelord(node* root);
void preord(node* root);
void inord(node* root);
void postord(node* root);
node* Delete(node* root,int data);
node* findmin(node* current);

int main(){
	node* root = NULL;
	int data;
	for(;;){
		cout << "1.Insert\n2.Search\n3.Find Minimum element\n4.Find Maximum element\n5.Height\n6.Level Order Traversal\n7.Pre-Order Traversal\n8.In-Order Traversal\n9.Post-Order Traversal\n10.Delete\n11.Exit"  << endl;
		cout << "Enter your choice" << endl;
		int x;
		cin >> x;
		switch(x){
			case 1:cout << "Enter the number of elements" << endl;
			int n;
			cin >> n;
			cout << "Enter all elements" << endl;
			while(n){
				cin >> data;
				root = insert(root,data);
				n--;
			}
			break;
			case 2:cout << "Enter the data to search" << endl;
			cin >> data;
			if(search(root,data)) cout << "FOUND" << endl;
			else cout << "NOT FOUND" << endl;
			break;
			case 3:Findmin(root);
			break;
			case 4:Findmax(root);
			break;
			case 5:cout << "Height of the tree is : " << Height(root) << endl;
			break;
			case 6:cout << "The tree is : "; 
			levelord(root);
			break;
			case 7:cout << "The tree is : ";
			preord(root);cout << endl;
			break;
			case 8:cout << "The tree is : ";
			inord(root);cout << endl;
			break;
			case 9:cout << "The tree is : ";
			postord(root);cout << endl;
			break;
			case 10:cout << "Enter the data to delete" << endl;
			cin >> data; 
			root = Delete(root,data);
			break;
			case 11:return 0;
			default:cout << "Enter correct choice" << endl;
		}
	}
	return 0;
}


//function to create a new node
node* Getnewnode(int num){
	node* temp = new node;
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


//insert function
node* insert(node* root,int data){
	if(root==NULL){
		root = Getnewnode(data);
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}


//search function
bool search(node* root,int data){
	if(root==NULL)
		return false;
	else if(data==root->data)
		return true;
	else if(data<=root->data)
   	    search(root->left,data);
	else
		search(root->right,data);
}


//Function to find minimum element
void Findmin(node* current){
	if(current==NULL){
		cout << "No element in the tree" << endl;
	}
	while(current->left != NULL){
		current = current->left;
	}
	cout << "Minimum element is : " << current->data << endl;
}


//function to find maximum element
void Findmax(node* current){
	if(current==NULL){
		cout << "No element in the tree" << endl;
	}
	while(current->right != NULL){
		current = current->right;
	}
	cout << "Maximum element is : " << current->data << endl;
}


//function to find height of tree
int Height(node* current){
	if(current==NULL)
		return -1;
	int leftheight = Height(current->left);
	int rightheight = Height(current->right);
	return (max(leftheight,rightheight)+1);
}


//level order traversal function
void levelord(node* root){
	if(root==NULL){
		cout << "No element in the tree" << endl;
		return ;
	}
	queue <node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node* current = Q.front();
		cout << current->data << " ";
		if(current->left!=NULL)
			Q.push(current->left);
		if(current->right!=NULL)
			Q.push(current->right);
		Q.pop();
	}
	cout << endl;
}


//pre-order traversal function
void preord(node* root){
	if(root==NULL)
		return ;
	cout << root->data << " ";
	preord(root->left);
	preord(root->right);
}


//in-order traversal function
void inord(node* root){
	if(root==NULL)
		return ;
	inord(root->left);
	cout << root->data << " ";
	inord(root->right);
}


//post-order traversal function
void postord(node* root){
	if(root==NULL)
		return ;
	postord(root->left);
	postord(root->right);
	cout << root->data << " ";
}


//deletion function
node* Delete(node* root,int data){
	if(root==NULL) return NULL;
	else if(data < root->data)
		root->left = Delete(root->left,data);
	else if(data > root->data)
		root->right = Delete(root->right,data);
	else if(data == root->data){
		if(root->left==NULL and root->right==NULL){
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left==NULL and root->right!=NULL){
			node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->left!=NULL and root->right==NULL){
			node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else{
			node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
			return root;
		}
	}
	return root;
}


//function to return minimum element(used in deletion function)
node* findmin(node* current){
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}