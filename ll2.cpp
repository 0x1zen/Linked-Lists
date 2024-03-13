#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getLength(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    } 
    else{
        Node* newNode=new Node(data);
        head->prev=newNode->next;
        newNode->next=head;
        head=newNode;
    }
    
}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node* newNode=new Node(data);
        tail=newNode;
        head=newNode; 
    }
    else{
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail->next;
        tail=temp;
    }
}
void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    int length=getLength(head);
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else if(position==1){
        Node* newNode=new Node(data);
        head->prev=newNode->next;
        newNode->next=head;
        head=newNode;
        tail=newNode;
    }
    else if(position==length+1){
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail->next;
        tail=newNode;
    }
    else{
        Node* temp=new Node(data);
        Node* currentNode=head;
        Node* prevNode=NULL;
        while(position!=1){
            prevNode=currentNode;
            currentNode=currentNode->next;
            position--;
        }
        prevNode->next=temp;
        temp->prev=prevNode;
        temp->next=currentNode;
        currentNode->prev=temp;
    }

}
void deleteAtPosition(Node* &head,Node* &tail,int position){
    int length=getLength(head);
    if(head==NULL){
        cout<<"LL is Empty"<<endl;
        return;
    }
    else if(head==tail){
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    else if(position==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }
    else if(position==length){
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
    }
    else{
        
        Node* currNode=head;
        Node* prevNode=NULL;
        
        while(position!=1){
            prevNode=currNode;
            currNode=currNode->next;
            position--;
        }
        Node* nextNode=currNode->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        currNode->prev=NULL;
        currNode->next=NULL;
        
        delete currNode;
    }
}
int main()
{
// Node* head=new Node(10);
Node* head=NULL;
Node* tail=NULL;
insertAtHead(head,tail,10);
insertAtTail(head,tail,230);
insertAtTail(head,tail,30);
// insertAtPosition(head,tail,50,4);

// printLL(head);
cout<<endl;
deleteAtPosition(head,tail,3);
printLL(head);
cout<<endl;
 return 0;
}