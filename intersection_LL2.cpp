#include<bits/stdc++.h>
using namespace std;

// better approach to get the intersection node
// counts the number of extra nodes on the larger LL and brings both LLs together

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
    int n1 = 0, n2 = 0;
    node* temp1 = head1;
    while(temp1){
        n1++;
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2){
        n2++;
        temp2 = temp2->next;
    }
    int n = 0;
    temp1 = head1;
    temp2 = head2;
    if (n1 > n2){
        n = n1 - n2;
        
        while(n--){
            temp1 = temp1->next;
        }
    }
    if (n2 > n1){
        n = n2 - n1;
        while(n--) temp2 = temp2->next;
    }
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1) return temp1;
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