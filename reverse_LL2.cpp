#include<bits/stdc++.h>
using namespace std;

// reversing a linked list- iterative method
// this approach iterates through the LL and changes the pointers

class node{
    public:
    int data;
    node* next;
    node(int data1, node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    int n = arr.size();
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < n; i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(node* head){
    node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node* reverseLL(node* head){
    node* temp = head;
    node* prev = nullptr;
    node* front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // call
    node* head = convert2LL(arr);
    printLL(head);

    // call
    cout << endl;
    head = reverseLL(head);
    printLL(head);
    return 0;
}