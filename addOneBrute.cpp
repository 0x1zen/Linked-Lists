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
void addOne(Node* & head){
    head=reverse(head);
    Node* temp=head;
    int carry=1;
    while(temp!=NULL){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newNode=new Node(1);
        head=reverse(head);
        newNode->next=head;
        head=newNode;
    }
    head=reverse(head);
}
// Total Time Complexity=O(3N)
// Total Space Complexity=O(1)
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,8);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,1);
    addOne(head);
    printLL(head);
 return 0;
}