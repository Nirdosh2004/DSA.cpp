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

void insertHead(node* &head , string d){
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}
 
 //fn for printing at tail or end 
void insertTail(node* &tail , string s){
    node* temp  = new node(s);
    tail->next = temp;
    tail = temp;
}


void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|     ";
        temp = temp->next;
    }
}
//fn for printing at desired position
void insertPosition(node* &tail , node* &head , int pos , string d){
    if(pos==1){
        insertHead(head,d);
        return ;
    }
    node* temp = head;
    int count =1;
    while(count!=pos-1){
        count++;
        temp = temp->next;
    }
    if(temp->next==NULL){
        insertTail(tail , d);
        return ;
    }
    node* temp2 = new node(d);
    temp2->next = temp->next;
    temp->next = temp2;

}

//fn to delete node at desired position 
void deleteatposition(node* &head , int pos){
   
    if(pos==1){
        node* temp = head;
        head = head->next;
        free(temp);
    }
    node* current = head ;
    node* previous = NULL ;
    int count = 1;
    while(count<=pos-1){
        previous = current ;
        current = current->next;
        count++;
    }
    previous->next = current->next;
    free(current);
}


int main(){

    node* object = new node("Object");

    node* head = object;
    node* tail = object;

    insertHead( head , " at head");
    print(head);
    cout<<endl;
    insertTail(tail , "at tail ");
    print(head);
     cout<<endl;

    insertPosition(tail , head , 2 , "at position 2 ");
    print(head);
    cout<<endl;
     deleteatposition(head , 2);
    print(head);
    return 0;
}