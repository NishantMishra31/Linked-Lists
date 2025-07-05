#include<bits/stdc++.h>
using namespace std;

// this code reverses a DLL with stack operations
// in two passes and o(N) extra space

class node {
    public:
    node* prev;
    int data;
    node* next;

    public:
    node(int data1, node* next1, node* prev1){
        prev = prev1;
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    int n = arr.size();
    node* head = new node(arr[0], nullptr, nullptr);
    node* prev = head;
    for(int i = 1; i < n; i++){
        node* temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

node* reverse_DLL(node* head){
    node* temp = head;
    stack <int> stk;
    while(temp){
        stk.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        temp->data = stk.top();
        stk.pop();
        temp = temp->next;
    }
    return head;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);
    printLL(head);

    cout << endl;

    head = reverse_DLL(head);
    printLL(head);
    return 0;
}