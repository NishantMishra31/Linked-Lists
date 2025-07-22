#include<bits/stdc++.h>
using namespace std;

// add two numbers given in two LLs in reverse order
// return in reversed order in a new LL

class node{
    public:
    int data;
    node* next;
    node(int data1, node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    if (arr.empty()) return nullptr;
    int n = arr.size();
    node* head = new node(arr[0]);
    node* mover = head;
    node* temp;
    for(int i = 1; i < n; i++){
        temp = new node(arr[i]);
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
    cout << endl;
}

node* add_LL(node* head1, node* head2){
    node* dummyNode = new node(-1);
    node* curr = dummyNode;
    node* temp1 = head1;
    node* temp2 = head2;
    int carry = 0;
    int sum = 0;
    node* newNode;
    while(temp1 || temp2){
        sum = carry;
        if(temp1) sum = sum + temp1->data;
        if(temp2) sum = sum + temp2->data;
        newNode = new node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        newNode = new node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> arr1(n), arr2(m);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];
    // call
    node* head1 = convert2LL(arr1);
    printLL(head1);
    node* head2 = convert2LL(arr2);
    printLL(head2);
    node* sumHead = add_LL(head1, head2);
    printLL(sumHead);
    return 0;
}