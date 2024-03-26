#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    public:
    node( int data1 , node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    vector<int> arr = {2,5,3,7};
    node* y = new node(arr[2] , nullptr);
    node* x = new node(arr[0] , nullptr);
    cout<<x<<endl;
    cout<<y->data;
    
    
    return 0;
}
