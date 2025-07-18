#include<bits/stdc++.h>
using namespace std;

// naive approach to check the palindromic nature of the LL
// takes up extra space and time to execute

class node{
    public:
    int data;
    node* next;

    public:
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

bool palindromeLL(node* head){
    node* temp = head;
    stack <int> stk;
    while(temp){
        stk.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if (temp->data != stk.top()) return false;
        temp = temp->next;
        stk.pop();
    }
    return true;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);
    printLL(head);
    cout << endl << (palindromeLL(head) ? "True" : "False");
    return 0;
}