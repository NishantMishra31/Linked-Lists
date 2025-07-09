#include<bits/stdc++.h>
using namespace std;

// this is a naive approach that calculates the total
// number of nodes and returns the entire node

class node{
    public:
    int data;
    node* next;

    public:
    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
};

node* convert2LL(vector <int> arr){
    int n = arr.size();
    node* head = new node(arr[0], nullptr);
    node* mover = head;
    for(int i = 1; i < n; i++){
        node* temp = new node(arr[i], nullptr);
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

node* middleofLL(node* head){
    node* temp = head;
    long long cnt  = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    temp = head;
    long long n = 0;
    while(temp){
        if (n == cnt / 2) break;
        n++;
        temp = temp->next;
    }
    return temp;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);
    printLL(head);

    cout << endl << middleofLL(head);
    return 0;
}