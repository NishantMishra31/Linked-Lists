#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data1, node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector<int> &arr){
    if (arr.empty()) return nullptr;
    node* head = new node(arr[0]);
    node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new node(arr[i]);
        mover = mover->next;
    }
    return head;
}

void printLL(node* head){
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

node* merge(node* l1, node* l2){
    node dummy(0);
    node* tail = &dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    else tail->next = l2;
    return dummy.next;
}

node* getMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* sort_LL(node* head){
    if (!head || !head->next) return head;
    node* mid = getMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = nullptr;
    left = sort_LL(left);
    right = sort_LL(right);
    return merge(left, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    node* head = convert2LL(arr);
    printLL(head);
    cout << endl;
    // call
    node* newHead = sort_LL(head);
    printLL(newHead);
    return 0;
}
