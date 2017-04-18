/*..................................
.....@ Vivek Ranjan ................
..................................*/

//singly linked list all operations
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head;
node *current;
node *current1;
node *temp1;
void insert_at_beg(int num);
void insert_at_end(int num);
void insert_at_pos();
void deletion();
void reverse();
void revrec(struct node *current2);
void prtrev(node *current0);
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
        insert_at_end(x);
        //insert_at_beg(x);
        print();
    }
    cout << "---Insertion at nth position---" << endl;
    insert_at_pos();
    cout << "Printing by iterative method" << endl;
    print();
    cout << "Printing by recursive method" << endl;
    current1 = head;
    Print();
    cout << "---Deletion of an element---" << endl;
    deletion();
    print();
    cout << "---Reversed list by iterative method---" << endl;
    reverse();
    print();
    cout << "---Reversed list by recursive method---" << endl;
    current1 = head;
    revrec(current1);
    print();
    cout << "---Printing of list in reversed order(not actually reversed)---" << endl;
    current1 = head;
    prtrev(current1);
    cout << endl;
    return 0;
}


//insertion at beginning
void insert_at_beg(int num){
    node *temp = new node();
    temp->data = num;
    temp->next = head;
    head = temp;
}


//insertion at end
void insert_at_end(int num){
    node *temp = new node();
    temp->data = num;
    if(head==NULL){
        temp->next = head;
        head = temp;
        temp1 = temp;
    }
    else{
        temp1->next = temp;
        temp->next = NULL;
        temp1 = temp;
    }
}


//insertion at nth position
void insert_at_pos(){
    int num,pos;
    cout << "Enter the position of insertion" << endl;
    cin >> pos;
    cout << "Enter the number to insert" << endl;
    cin >> num;
    node *temp = new node();
    node *current = head;
    temp->data = num;
    for(int i=1;i<pos-1;i++){
        current = current->next;
    }
    if(pos==1){
        temp->next = head;
        head = temp;
    }
    else{
        temp->next = current->next;
        current->next = temp;
    }
}


//deletion function
void deletion(){
    cout << "Enter the position you want to delete" << endl;
    int pos;
    cin >> pos;
    node *current2 = head;
    node *temp2;
    if(pos==1){
        head = head->next;
    }
    else{
        for(int i=1;i<pos-1;i++){
            current2 = current2->next;
        }
        temp2 = current2;
        current2 = current2->next;
        temp2->next = current2->next;
    }
}


//reverse by iteration method
void reverse(){
    node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;    
}


//reverse by recursion
void revrec(struct node *current2){
    if(current2->next==NULL)
    {
        head=current2;
        return ;
    }
    revrec(current2->next);
    node *temp=current2->next;
    temp->next=current2;
    current2->next=NULL;
}


//reverse print function
void prtrev(node *current0){
    if(current0==NULL){
        return ;
    }
    prtrev(current0->next);
    cout << current0->data << " ";
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


//print function using recursion
void Print(){
    if(current1==NULL){
        cout << endl;
        return ;
    }
    cout << current1->data << " ";
    current1 = current1->next; 
    Print();
}