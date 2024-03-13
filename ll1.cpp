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
void insertAtTail(Node* &tail, Node* &head, int data) {
    if (head == NULL) {
        // Empty LL case
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

// void createTail(Node* &head,Node* &tail){
//     Node* temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     tail=temp;
// }

int getLength(Node* &head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    // cout<<length;
    return length;
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    // if(position<1){
    //     cout<<"Enter a valid position";
    // }
    int length=getLength(head);
    // cout<<length<<endl;
    // if(position>length){
    //     cout<<"Enter a valid position";
    // }
    if(position==1){
        insertAtHead(head,tail,data);
    }
    else if(position==length+1){
        insertAtTail(tail,head,data);
    }
    else{
        // Insert at middle of linked list
        Node* temp=new Node(data);
        Node* prev=NULL;
        Node* current=head; 
        while(position!=1){
            prev=current;
            current=current->next;
            position--;
        }
        prev->next=temp;
        temp->next=current;
    }
}

void deleteAtPosition(Node* &head,Node* &tail,int position){
    int length=getLength(head);
    if(head==NULL){
        cout<<"LL is empty";
        return;
    }
    if(head==tail){
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    // Delete from head
    if(position==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    // Delete from tail
    else if(position==length){
    Node* prev=head;
    while(prev->next!=tail){
        prev=prev->next;
    }
    Node* temp=tail;
    prev->next=NULL;
    tail=prev;
    delete temp; // Corrected this line
}

    // Delete at position
    else{
        Node*temp=head;
        Node* prev=NULL;
        while(position!=1){
            prev=temp;
            temp=temp->next;
            position--;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
    }


}

int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    // insertAtHead(head,tail,10);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,30);
    // insertAtHead(head,tail,50);

    insertAtTail(tail,head,10);
    // insertAtTail(tail,head,20);
    // insertAtTail(tail,head,30);
    // insertAtTail(tail,head,50);

    // insertAtPosition(head,tail,1000,5);
    printLL(head);
    cout<<endl;
    cout<<"Value of head before"<<head->data<<endl;
    deleteAtPosition(head,tail,1);
    // cout<<"Value of head after"<<head->data;
    printLL(head);


    
    // Node* first=new Node(10);
    // Node* second=new Node(20);
    // Node* third=new Node(30);
    // Node* fourth=new Node(40);
    // Node* fifth=new Node(50);

    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;

    // Node* head=first;
    // Node* tail=fifth;
    // int count=0;
    // // printLL(head,count);
    // insertAtHead(head,500);
    // // printLL(head,count);
    //  insertAtTail(tail,head,1000);
    //     printLL(head,count);
 return 0;
}