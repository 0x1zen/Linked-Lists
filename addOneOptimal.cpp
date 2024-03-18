#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        // cout<<"COnstructor called";
        this->next=NULL;
    }
    Node(int data){
        //  cout<<"COnstructor  para called";
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        cout<<"Destructor called for "<<this->data<<endl;
    }

};
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        // case for empty linked list
        // create new node
        Node* newNode=new Node(data);
        // update head
        head=newNode;
    }
    else{// Create new node
    Node* newNode=new Node(data);
    // attach new node to head node
    newNode->next=head;
    // update head
    head=newNode;}
}
Node* reverse(Node* &head){
    Node* prev=NULL;
    Node* current=head;
    while(current!=NULL){
        Node* nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    return prev;
}
int helper(Node* &temp){
    if(temp==NULL){
        return 1;
    }
    int carry;
    carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
void addOne(Node* & head){
    int carry;
    Node* temp=head;
    carry=helper(temp);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        head=newNode;
    }
}
// Total Time Complexity=O(N)
// Total Space Complexity=O(N)
// Pros:No tampering of data.Does in place addition
// Cons:Takes extra space
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    insertAtHead(head,tail,9);
    addOne(head);
    printLL(head);
 return 0;
}