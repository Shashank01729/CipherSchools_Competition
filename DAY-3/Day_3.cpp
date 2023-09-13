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

void Rotate(Node* &head,int n,int shift){
    if(head==NULL){
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }temp->next=head;
    
    shift%=n;
    shift=n-shift;

    while(shift!=0){
        temp=temp->next;
        shift--;
    }
    head=temp->next;
    temp->next=NULL;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

int main(){
    int n,data,k;
    Node* head=NULL;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> data;
        insert(head,data);
    }cin >> k;
    
    Rotate(head,n,k);
    print(head);
}
