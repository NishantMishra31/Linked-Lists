#include <bits/stdc++.h>
using namespace std;

// deleting the first node of the DLL, aka head

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

node* DLL_deleteHead(node* head){
    if (head == nullptr) return nullptr;
    node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

int main() {
    int n;
    cin  >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    node* head = convert2LL(arr);

    printLL(head);

    head = DLL_deleteHead(head);
    cout << endl;

    printLL(head);
    return 0;
}
