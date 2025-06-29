#include <bits/stdc++.h>
using namespace std;

// deleting a node with respect to its relative position 

class node {
    public:
    int data;
    node* next;
    public:
    node(int data1, node* next1 = nullptr){
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

node* deletePos(node* head, int k){
    if (head == nullptr) return nullptr;
    if(k == 1){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node* temp = head;
    node* prev = nullptr;
    int cnt = 1;
    while(temp != nullptr && cnt < k){
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) return head;
    prev->next = temp->next;
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
    int k;
    cin >> k;
    head = deletePos(head, k);
    cout << endl;

    printLL(head);
    return 0;
}