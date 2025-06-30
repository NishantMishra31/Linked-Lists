#include <bits/stdc++.h>
using namespace std;

// this code implements basics of linked lists meant only for explanation
// such as creation, traversal, length, search

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

int lengthofLL(node* head){
    int cnt = 0;
    node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void print(node* head){
    node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int search(node* head, int val){
    node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector <int> arr = {2, 3, 4, 7, 9};
    node* head = convert2LL(arr);
    print(head);
    cout << endl << "length of LL: " << lengthofLL(head);
    int val;
    cin >> val;
    cout << endl << (search(head, val) ? "element found" : "not found");
    return 0;
}
