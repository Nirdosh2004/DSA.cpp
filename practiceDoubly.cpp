#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* previous ;
    node* next;
    node(string d){
        this->data = d;
        this->previous = NULL;
        this->next =  NULL;
    }
};

//fn to print at head 
void insertatHead(node* &head , string d){
    node* temp = new node(d);
    temp->next = head ;
    head->previous = temp;
    head = temp;
}

//fn to print at end or tail
void insertatTail(node* &tail , string a){
    node* temp = new node(a);
    tail->next = temp;
    temp->previous = tail ;
    tail = temp;
}

//fn for inserting node at desired position 
void insertatPosition(node* &tail , node* &head , int pos , string d){
    if(pos==1){
        insertatHead(head , d);
        return ;
    }
    node* temp = head;
    int count = 1;
    while(count<pos-1){
        count++;
        temp = temp->next;
    }
    if(temp->next==NULL){
        insertatTail(tail , d);
        return ;
    }
    node* temp2 = new node(d);
    temp2->next = temp->next;
    temp->next->previous = temp2;
    temp->next = temp2;
}

void print(node* &head){
    node* temp = head ;
    while(temp!=NULL){
        cout<<temp->data<< "|     ";
        temp = temp->next;
    }
}
//fn for deleting node at desired position 
void deleteatPosition(node* &head , int pos){
    if(pos==1){
        node* temp = head ;
        temp->next->previous = NULL;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    node* temp = head;
    node* previous=  NULL;
    int count =0;
    while(count<pos-1){
        count++;
        previous = temp ;
        temp = temp->next;
    }
    previous->next  = temp->next;
    free(temp);

}

int main(){

    node* object = new node("object");

    node* head = object;
    node* tail = object;

    insertatHead(head , "at head ");
    print(head);
    cout<<endl;
    insertatTail(tail , "at tail");
    print(head);
    cout<<endl;
    insertatPosition(tail , head , 2 , "at position");
    print(head);
     cout<<endl;
    deleteatPosition(head , 3);
    print(head);
   


    return 0;
}