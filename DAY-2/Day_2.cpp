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

void Convert(Node* &head){
    if (head==NULL || head->next==NULL) {
        return; 
    }

    Node* odd=head;
    Node* even=head->next;
    Node* e_head=even; 

    while(even && even->next){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }odd->next=e_head; 
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

int main(){
    int n,data;
    Node* head=NULL;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> data;
        insert(head,data);
    }

    Convert(head);
    print(head);
}
