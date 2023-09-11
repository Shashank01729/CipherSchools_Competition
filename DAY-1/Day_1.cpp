#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void insert(Node* &head, int d){
    Node* newNode=new Node();
    newNode->data=d;
    newNode->next=NULL;
    
    if(head==NULL){
        head=newNode;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

int TwinSum(Node* &head){
    vector<int> v;
    Node* temp=head;
    
    while(temp!=nullptr){
        v.push_back(temp->data);
        temp=temp->next;
    }
    
    int s=0,e=v.size()-1,ans=0;
    while(s<e){
        ans=max(ans,v[s]+v[e]);
        s++;e--;
    }
    return ans;
}

int main(){
    int n,data;
    Node* head=NULL;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        insert(head,data);
    }
    cout << TwinSum(head) << endl;
}