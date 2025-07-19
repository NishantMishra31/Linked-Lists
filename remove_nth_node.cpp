#include<bits/stdc++.h>
using namespace std;

// optimal approach to print the odd-even nodes of the LL
// does modification in place and takes up no extra space and time to execute

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

node* removeNthFromEnd(node* head, int n) {
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }
    if(n > count) return head;
    if(n==count) return head->next;
    int k = count - n - 1;
    temp = head;
    while(k--){
        temp = temp -> next;
    }
    temp -> next = temp->next->next;
    return head;
    }

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);
    printLL(head);
    int x;
    cin >> x;
    node* newHead = removeNthFromEnd(head, x);
    cout << endl;
    printLL(newHead);
    return 0;
}