#include<bits/stdc++.h>
using namespace std;

// this code uses tortoise and hare approach, also called Floyd's loop detection algirithm 
// basic implementation of two pointers in LLs

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

bool hasLoops(node* head){
    if (!head || head->next == nullptr) return false;
    node* slow = head;
    node* fast = head->next->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);

    // test this code with loops in the LL
    cout << endl << (hasLoops(head) ? "true" : "false");
    return 0;
}