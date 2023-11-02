#include<iostream>
using namespace  std;

class node{
    public:
    string data;
    node* previous;
    node* next;
    node(string d){
        this->data = d;
        this->previous = NULL;
        this->next = NULL;
    }
};

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<< "|   ";
        temp = temp->next;
    }
}

void insertatHead(node* &head , string data){
    node* temp = new node(data);
    temp->next = head;
    head->previous = temp;
    head = temp;
}

void insertat_tail(node* &tail , string data){
    node* temp = new node(data);
    tail->next = temp;
    temp->previous = tail;
    tail = temp;
}

void insertat_desired_position(node* &tail , node* &head , int position , string d){
    if(position==1){
        insertatHead(head , d);
        return ;
    }
    node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertat_tail(tail , d);
        return ;
    }
    node* temp2 = new node(d);
    temp2->next  = temp->next;
    temp->next->previous= temp2;
    temp->next = temp2;

}

void delete_node(node* &head , int pos){
     
      
     if(pos==1){
        node* temp = head;
        temp->next->previous = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
     }
     else{
        int count = 1;
        node* temp = head;
        node* previous  = NULL;
        while(count<pos){
            count++;
            previous = temp;
            temp = temp ->next;
        }
        previous->next = temp->next;
        delete temp;
        
     }   
}

int main(){
    node* obj = new node("Object");
    
    node* head = obj;
    node* tail = obj;
    insertatHead(head , "HeadOne");
    print(head);
    cout<<endl;
    insertat_tail(tail , "TailOne");
    print(head);
    cout<<endl;
    insertat_desired_position(tail , head , 2 , "at Desired Position");
    print(head);
     cout<<endl;
    delete_node(head , 1);
     print(head);
    cout<<endl;
    delete_node(head , 3);
     print(head);
    cout<<endl;
    
    cout<<endl;
}