//doubly linked list -> insertion , deletion at desired position ; 

#include<iostream>
using namespace std;

class node{
    public:
    string data ;
    node* previous ;
    node* next;
    node(string d){
        this -> data = d ;
        this -> previous = NULL;
        this -> next = NULL ;
    }
};

inline void insertAtHead(node* &head , string p){
    node* temp = new node(p);
    temp -> next = head ;
    head -> previous  = temp;
    head = temp;
}

inline void insertAtTail(node* &tail , string a){
    node* temp = new node(a);
    tail -> next =  temp ;
    temp -> previous = tail ;
    tail = temp;
}

inline void insertAtDesiredPosition(node* &head , node* &tail , int position , string d){
    if(position == 1){
       insertAtHead(head , d);
       return ;
    }
    int count = 1;
    node* temp = head ;
    while(count < position - 1){
        count++ ;
        temp = temp -> next ;
    }
    if(temp -> next == NULL){
        insertAtTail(tail , d);
        return ;
    }
    node* temp2 = new node(d);
    temp2 -> next = temp -> next ;
    temp -> next -> previous = temp2;
    temp -> next = temp2;
}

inline void deleteAtDesiredPosition(node* &head , int position){
    if(position == 1){
        node* temp = head ;
        temp -> next -> previous = NULL;
        head = head -> next ;
        temp -> next = NULL;
        free(temp);
    }
    int  count = 1;
    node* current = head ;
    node* previous = NULL;
    while(count <= position - 1 ){
        count++;
        previous = current;
        current = current -> next;
    }
    previous -> next  = current -> next ;
    free(current);
}

inline void print(node* &head ){
    node* temp = head ;
    while(temp != NULL ){
        cout<< temp -> data <<"|      ";
        temp = temp -> next ;
    }
}

int main(){
    
  node* object = new node("At Object ")  ;
  
  node* head = object ;
  node* tail = object ;
  
  insertAtHead(head , "At Head ");
  print(head);
  cout<<endl;
  
  insertAtTail(tail , "At Tail ");
   print(head);
  cout<<endl;
  
  insertAtDesiredPosition(head , tail  , 3 , "At Desired Position ");
   print(head);
     cout<<endl;
    
    deleteAtDesiredPosition(head , 3);
     print(head);
    cout<<endl;
    
    
    return 0;
}
