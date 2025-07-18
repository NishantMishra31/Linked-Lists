#include<bits/stdc++.h>
using namespace std;

// tortoise and hare algorithm to calculate thee length of loop in LL
// no extra space and most optimal soln

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

int lengthLoop(node* head){
    if(!head || !head->next) return 0;
    node* temp = head;
    node* slow = head;
    node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            fast = fast->next;
            while(fast != slow){
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // call
    node* head = convert2LL(arr);

    // test this code with loops in the LL
    cout << lengthLoop(head);
    return 0;
}