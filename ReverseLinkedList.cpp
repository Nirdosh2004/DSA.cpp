#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* next;
    node(string d){
        this->data = d;
        this->next = NULL;
    }
};

void insertat_head(node* &head , string data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void reverseLinkedList(node* &head ){
    node* previous = NULL;
    node* current = head;
    node* forward = NULL;
    if(head==NULL || head->next==NULL){
        return ;
    }
    while(current!=NULL){
        forward= current;
         current->next = previous ;
         previous = current;
         current = forward ;

    }
       
}

void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|     ";
        temp = temp->next;
    }
}

int main(){

    node* obj = new node("Object One");

    node* head = obj;

    insertat_head(head , "Head four");
    insertat_head(head , "Head three ");
    insertat_head(head , "Head two ");
    insertat_head(head , "Head One ");
    
   
    print(head);
     reverseLinkedList(head);
      print(head);



    return 0;
}