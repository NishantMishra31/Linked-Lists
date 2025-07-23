#include<bits/stdc++.h>
using namespace std;

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
    cout << endl;
}

node* reverseLL(node* head){
    node* temp = head;
    node* prev = nullptr;
    node* front;
    while(temp){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

node* getkthNode(node* temp, int k){
    node* currNode = temp;
    int n = 0;
    while(currNode){
        n++;
        if(n == k) return currNode;
        currNode = currNode->next;
    }
    return nullptr;
}

node* reverseKGroup(node* head, int k){
    node* temp = head;
    node* nextNode;
    node* prevNode;
    while(temp){
        node* kthNode = getkthNode(temp, k);
        if(!kthNode){
            if (prevNode) prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head) head = kthNode;
        else prevNode->next = kthNode;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // call
    node* head = convert2LL(arr);
    printLL(head);
    int k;
    cin >> k;
    node* newHead = reverseKGroup(head, k);
    printLL(newHead);
    return 0;
}