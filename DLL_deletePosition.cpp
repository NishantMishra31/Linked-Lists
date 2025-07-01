#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;

    public:
    node(int data1, node* next1 = nullptr, node* prev1 = nullptr){
        prev = prev1;
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    node* head = new node(arr[0]);
    node* prev = head;
    for(int i = 1; i < arr.size(); i++){
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

node* DLL_deletePos(node* head, int k){
    if (head == nullptr) return nullptr;
    if (k == 1) {
        node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        return head;
    }

    node* temp = head;
    int cnt = 1;
    while(temp && cnt < k){
        temp = temp->next;
        cnt++;
    }
    
    if(!temp) return head;

    node* prev = temp->prev;
    node* next = temp->next;

    if (prev) prev->next = next;
    if (next) next->prev = prev;

    delete temp;
    return head;
}

int main(){
    int n;
    cin >> n;
    vector <int>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);
    printLL(head);
    cout << endl;

    int k;
    cin >> k;
    head = DLL_deletePos(head, k);
    printLL(head);
    return 0;
}