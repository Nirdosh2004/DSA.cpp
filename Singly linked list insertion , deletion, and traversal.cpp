//2.Singly linked list insertion , deletion, and traversal 

#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* next;
    node(string d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(node* &head , string d){
    node* temp = new node(d);
    temp -> next = head ;
    head = temp;
}

void insertAtTail(node* &tail , string d){
    node* temp = new node(d);
    tail -> next = temp ;
    tail = temp;
}

void insertAtDesiredPosition(node* &head , node* &tail , int position , string data){
    if( position == 1){
        insertAtHead(head , data);
        return;
    }
    int count = 1;
    node* temp = head ;
   
    while ( count < position - 1){
        count++;
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        insertAtTail(tail , data);
        return ;
    }
    node* temp2 = new node(data);
    temp2 -> next = temp -> next;
   temp -> next = temp2;
    temp = temp2;
}

void deleteAtdesiredPosition(node* &head ,  int position ){
    if( position == 1){
        node* temp = head ;
        head = head -> next;
       free(temp);
    }
    int count = 1;
    node* temp = head ;
    node* previous = NULL;
    while ( count <= position - 1){
        previous = temp;
        temp = temp -> next;
        count++;
    }
    previous -> next = temp -> next ;
    free(temp);
}

void print(node* &head ){
    node* temp = head ;
    while ( temp != NULL){
        cout<< temp -> data <<"    ";
        temp = temp -> next;
    }
}

int main(){
    node* obj = new node("object");
    node* head = obj;
    node* tail = obj;
    
    insertAtHead(head , "At head ");
    print(head);
    cout<<endl;
    insertAtTail(tail ,"At tail ");
     print(head);
    cout<<endl;
    insertAtDesiredPosition(head , tail , 2 , " At Desired Position");
     print(head);
    cout<<endl;
    deleteAtdesiredPosition(head , 2);
     print(head);
    cout<<endl;
    
    
    return 0;
}




















