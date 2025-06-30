#include <bits/stdc++.h>
using namespace std;

// insert a node at its relative position 

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

node* insertPos(node* head, int k, int pos){
    if (pos <= 0) return head;
    if (pos == 1){
        return new node(k, head);
    }
    node* temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr){
        return head;
    }
    node* newNode = new node(k, temp->next);
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
    int k, pos;
    cin >> k >> pos;
    head = insertPos(head, k, pos);
    cout << endl;

    printLL(head);
    return 0;
}