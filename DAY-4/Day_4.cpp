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

int length(Node* temp){
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

Node* reverse(Node* &head,int n) {
    if(length(head)<n){
        return head;
    }

    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    for(int i=0;i<n;i++){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=reverse(curr,n);
    return prev;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }cout << endl;
}

int main(){
    int n,data,k;
    Node* head=NULL;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        insert(head,data);
    }
    cin >> k;

    head=reverse(head,k);
    print(head);
}
