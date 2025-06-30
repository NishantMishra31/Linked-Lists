#include <bits/stdc++.h>
using namespace std;

// inserting at the last node of the LL, aka tail

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

node* insertTail(node* head, int k){
    node* newNode = new node(k);
    if (head == nullptr) return newNode;
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
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
    head = insertTail(head, k);
    cout << endl;

    printLL(head);
    return 0;
}
