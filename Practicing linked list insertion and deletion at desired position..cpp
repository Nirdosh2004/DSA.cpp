//02|11|2023`

#include<iostream>
using namespace std;

class node{
    public:
    string data;
    node* next;
    node(string data){
        this->data = data;
        this->next = NULL;
    }
};

void insertat_head(node* &head , string data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertat_tail(node* &tail , string data){
    node* temp = new node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertat_position( node* &tail ,node* &head , int position , string data ){
    
    if(position == 1){
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
    temp2->next = temp->next;
    temp->next = temp2;
    
}

void delete_node(node* &head , int position){
    node* temp = head ;
    int count =1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    node* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

void print(node* &head ){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<< "|    ";
        temp = temp->next;
    }
}

int main(){
    
  node* obj = new node("object")  ;
    
    node* head = obj;
    node* tail = obj;
    
    insertat_head(head , "HeadTwo");
    insertat_head(head , "HeadOne");
    insertat_tail(tail , "TailOne");
    insertat_tail(tail , "TailTwo");
    insertat_position( tail , head , 3 , "3rd Position ");
     insertat_position(tail ,head , 5 , "5th Position ");
      insertat_position(tail ,head , 1 , "1st Position ");
       insertat_position(tail ,head , 9 , "9th Position ");
        insertat_position(tail ,head ,10 , "10th Position ");
         print(head);
         cout<<endl;
        delete_node(head,3);
    

    print(head);
    
    
    return 0;
}
