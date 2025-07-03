#include <bits/stdc++.h>
using namespace std;

// inserting at the node by value of the node in the DLL

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

node* DLL_insertVal(node* head, int val, int k){
    if (head->data == k){
        node* temp = new node(val, head);
        if (head) head->prev = temp;
        return temp;
    }

    node* temp = head;
    int cnt = 1;

    while (temp && temp->data != k){
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr){
        return head;
    }

    node* prev = temp->prev;
    node* newNode = new node(val, temp, prev);
    if (prev) prev->next = newNode;
    temp->prev = newNode;

    return head;
}


int main(){
    int n;
    cin  >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    node* head = convert2LL(arr);

    printLL(head);

    int k, val;
    cin >> k >> val;

    head = DLL_insertVal(head, val, k);
    cout << endl;

    printLL(head);
    return 0;
}
