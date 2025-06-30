#include <bits/stdc++.h>
using namespace std;

// insert a node at its relative valition 

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

node* insertVal(node* head, int k, int val){
    if (head == nullptr) return nullptr;
    if (head->data == val){
        node* temp = new node(k, head);
        return temp;
    }
    node* temp = head;
    while(temp->next != nullptr){
        if (temp->next->data == val){
            node* newNode = new node(k, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    int n;
    cin  >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    node* head = convert2LL(arr);

    printLL(head);
    int k, val;
    cin >> k >> val;
    head = insertVal(head, k, val);
    cout << endl;

    printLL(head);
    return 0;
}