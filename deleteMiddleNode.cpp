#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1, node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    int n = arr.size();
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < n; i++){
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

node* deleteMiddle(node* head){
    int cnt = 0;
    if (!head || !head->next) return nullptr;
    node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    if (cnt == 2){
        delete(head->next);
        head->next = nullptr;
        return head;
    }
    temp = head;
    int mid = cnt / 2;
    for(int i = 0; i < mid - 1; i++){
        temp = temp->next;
    }
    node* midNode = temp->next;
    temp->next = temp->next->next;
    delete(midNode);
    return head;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    node* head = convert2LL(arr);
    printLL(head);
    // call
    cout << endl;
    node* newHead = deleteMiddle(head);
    printLL(newHead);
    return 0;
}