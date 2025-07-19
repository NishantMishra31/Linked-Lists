#include<bits/stdc++.h>
using namespace std;

// naive approach to print the odd-even nodes of the LL
// takes up extra space and time to execute

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

node* oddevenLL(node* head){
    if (!head || !head->next) return head;
    vector <int> arr;
    node* temp = head;
    while(temp){
        arr.push_back(temp->data);
        if(temp->next) temp = temp->next->next;
        else break;
    }
    temp = head->next;
    while(temp){
        arr.push_back(temp->data);
        if(temp->next) temp = temp->next->next;
        else break;
    }
    temp = head;
    for(int i = 0; i < arr.size(); i++){
        temp->data = arr[i];
        temp =  temp->next;
    }
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
    node* newHead = oddevenLL(head);
    cout << endl;
    printLL(newHead);
    return 0;
}