#include<bits/stdc++.h>
using namespace std;

// this approach stores the nodes in a map and checks if they reappear to detect cycles
// it takes extra space and time

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

bool hasLoops(node* head){
    map <node*, int> mp;
    node* temp = head;
    while(temp){
        if(mp.find(temp) != mp.end()) return true;
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);

    // test this code with loops in the LL
    cout << endl << (hasLoops(head) ? "true" : "false");
    return 0;
}