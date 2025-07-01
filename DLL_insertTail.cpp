#include <bits/stdc++.h>
using namespace std;

// inserting at the last node of the DLL, aka tail

class node {
    public:
    node* prev;
    int data;
    node* next;
    public:
    node(int data1, node* next1 = nullptr, node* prev1 = nullptr) {
        prev = prev1;
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector<int> &arr){
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

node* DLL_insertTail(node* head, int k){
    if (head == nullptr){
        head = new node(k, nullptr);
        return head;
    }
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    node* tail = new node(k, nullptr);
    tail->prev = temp;
    temp->next = tail;

    return head;
}

int main() {
    int n;
    cin  >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    node* head = convert2LL(arr);

    printLL(head);

    int k;
    cin >> k;

    head = DLL_insertTail(head, k);
    cout << endl;

    printLL(head);
    return 0;
}
