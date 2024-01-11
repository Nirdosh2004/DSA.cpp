//Doubly linked list ;

#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* previous;
    node* next;
    node(string d){
        this->data= d;
        this->previous = NULL;
        this->next = NULL;
    }
};

void print(node* &head ){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|      ";
        temp = temp->next;
    }
}

void insertat_head(node* &head , string data){
    node* temp = new node(data);
    temp->next = head;
    head->previous = temp;
    head = temp;
}

void insertat_tail(node* &tail , string data ){
    node* temp = new node(data);
    tail->next = temp;
   temp->previous = tail;
    tail = tail->next;
    
}

 void insertat_position(node* &tail , node* &head , int position , string data ){
     if(position==1){
         insertat_head(head , data);
         return;
     }
    node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertat_tail(tail , data);
        return ;
    }
    node* temp2 = new node(data);
    temp2->next = temp ->next;
    temp->next->previous=  temp2;
    temp->next = temp2;
   
}
int getLength(node* &head , node* &tail){
    int count = 1;
    node* temp = head;
    while(temp!=NULL){
       count++;
        temp = temp->next;
    }
    return count;
}

int main(){
  
  node* obj = new node("Object")  ;
  
  node* head = obj;
  node* tail = obj;
  
  insertat_head(head , "HeadOne");
   insertat_head(head , "HeadTwo");
  insertat_tail(tail, " TailOne");
  insertat_tail(tail, " TailTwo");
 
  
    print(head);
    cout<<endl<<endl;
     insertat_position(tail , head , 3 , "3rd Position");
     print(head);
      cout<<endl<<endl;
     insertat_position(tail , head , 1 , "1st Position");
     print(head);
      cout<<endl<<endl;
     insertat_position(tail , head , 7 , "7th Position");
     print(head);
      cout<<endl<<endl;
     insertat_position(tail , head , 9, "9th Position");
     print(head);
     cout<<endl<<endl;
    
    
    // cout<<endl<<"Length of Node is : "<<getLength<<endl;
    
    return 0;
}
