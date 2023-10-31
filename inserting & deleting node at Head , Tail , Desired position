//inserting node at Head , Tail , Desired position in Linked List in C++ 

#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* link;
    node(string data){
        this->data = data;
        this->link = NULL;
    }
};
//for inserting node at head 
void pushAtHead(node* &head , string a){
    node* temp = new node(a);
    temp->link = head ;
    head = temp;
}
//function for inseting last node 
void pushAtEnd(node* &end , string b){
    node* temp = new node(b);
    end->link = temp;
    end = end->link;
}
//function for inserting node at desired position 
void pushatposition( node* &end , node* &head , int position , string p){
    node* temp = head;
    //if position is first 
    if(position==1){
        pushAtHead(head , p);
        return ;
    }
    
    int count = 1;
    while(count<position-1){
        temp = temp->link;
        count++;
        
    }
    //if position is greater than nodes 
    if(temp->link==NULL){
        pushAtEnd(end , p);
        return ;
    }
    
    node* newPositionNode = new node(p);
    newPositionNode ->link = temp->link;
    temp->link=  newPositionNode;
}

void deleteNode(node* &head , int pos){
   
    if(pos==1){
         node* temp = head;
        head = head->link;
        free(temp);
    }
    else{
        node* current = head ;
         node* previous = NULL ;
         int count = 1;
         while(count<=pos-1){
             previous = current ;
             current = current->link;
             count++;
         }
         previous ->link = current->link;
         free(current);
    }
    
}

//for printing output
void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"|     |";
        temp = temp->link;
    }
}

int main(){
    
    node *obj = new node("object");
    
    node* head = obj;
    node* end = obj;
  
     pushAtHead(head , "banana");
    pushAtHead(head , "Apple");
    
    pushAtEnd ( end , "secondLast");
     pushAtEnd ( end , "last");
  
     pushatposition( end , head , 6, "position wala ");
    print(head); 
    cout<<endl;
    deleteNode(head , 6) ;
    print(head);  
    
    
    return 0;
}
