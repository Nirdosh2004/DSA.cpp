//Creating node and inserting head and tail node 

#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node* link;
    node(int info){
        this->info=info;
        this->link = NULL;
    }
};

//creating a head inseting fn
void insertAtHead(node* &head, int d){
    node* temp = new node(d);
    temp->link = head;
    head = temp;
}

//creating a tail inserting fn
void insertAtTail(node* &tail , int a){
    node* temp = new node(a);
    tail->link = temp;
    tail = temp;
}

//for printing output 
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp = temp-> link;
    }
}

int main(){
  
  node* object = new node(13)  ;

    node* head = object;
    node* tail = object;
    insertAtHead(head , 32); //head fun.
   
    insertAtTail(tail , 67);  //tail fun.
    
    print(head);
    cout<<endl;
    cout<<head->info<< "  "<<head->link<<endl;
    cout<<object->info<<" "<<object->link<<endl;
    cout<<tail->info<< " "<<tail->link;
    
    
    
    return 0;
}
