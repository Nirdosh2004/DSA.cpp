#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;
    public:
    node( int data1){
        data = data1;
        next = NULL;
    }
};

int main(){
    vector<int> arr = {2,5,3,7};
    node* y = new node(arr[2]);
    node* x = new node(arr[0]);
    cout<<x<<endl;
    cout<<y;
    
    
    return 0;
}
