#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* previous;
    node* next;
    node(string d){
        this-> data = d;
        this -> previous = NULL;
        this-> next = NULL;
    }
};

void insertatHead(node* &head , string d){
    node* temp = new node(d);
    temp->next = head;
    head->previous = temp;
    head = temp;
}

void insertatTail(node* &tail , string d ){
    node* temp = new node(d);
    tail->next = temp;
    temp->previous = tail ;
    tail = temp;
}

void print(node* &head){
    node*  temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|      ";
        temp = temp -> next;
    }
}

void insertatDesiredPosition(node* &tail , node* &head , int position , string s){
    if(position == 1){
        insertatHead(head , s);
        return ;
    }
    node* temp = head;
    int count = 1;
    while(count<position-1){
        count++;
        temp = temp->next;
    }

    if(temp->next == NULL){
        insertatTail(tail , s);
        return ;
    }

    node* temp2 = new node(s);
    temp2->next = temp->next;
    temp->next = temp2;
    temp2->previous = temp;

}

int main(){

    node* instance = new node("Instance");

    node* head = instance;
    node* tail = instance;

    insertatHead(head , "HeadOne");
    print(head);
    cout<<endl;
    insertatTail(tail , "TailOne");
    print(head);
    cout<<endl;
    insertatDesiredPosition(tail , head , 2 , "At desired Position ");
    print(head);
     cout<<endl;
    insertatDesiredPosition(tail , head , 1 , "At desired Position ");
    print(head);
     cout<<endl;
    insertatDesiredPosition(tail , head , 6 , "At desired Position ");
    print(head);



    return 0;
}
