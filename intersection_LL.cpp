#include<bits/stdc++.h>
using namespace std;

// uses hashmaps to get the intersection node
// uses extra space to store and remember the nodes

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
}

node* getIntersectionNode(node *head1, node *head2) {
    map <node*, int> mp;
    node* temp = head1;
    while(temp){
        mp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        if(mp.find(temp) != mp.end()) return temp;
        temp = temp->next;
    }
    return nullptr;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> arr1(n);
    vector <int> arr2(m);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];
    // call
    node* head1 = convert2LL(arr1);
    node* head2 = convert2LL(arr2);
    printLL(head1);
    cout << endl;
    printLL(head2);

    // test this code with overlapping LLs
    node* intersect = getIntersectionNode(head1, head2);
    cout << endl;
    if (intersect) cout << intersect->data;
    else cout << "No intersection";
    return 0;
}