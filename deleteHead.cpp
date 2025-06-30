#include <bits/stdc++.h>
using namespace std;

// deleting the first node of the LL, aka head

class node {
    public:
    int data;
    node* next;
    public:
    node(int data1, node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
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

node* deleteHead(node* head){
    if (head == nullptr) return nullptr;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    int n;
    cin  >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    node* head = convert2LL(arr);

    printLL(head);

    head = deleteHead(head);
    cout << endl;

    printLL(head);
    return 0;
}
