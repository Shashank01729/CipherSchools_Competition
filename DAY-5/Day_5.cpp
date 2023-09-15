#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void insert(Node*& head,int d){
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
    }temp->next=newNode;
}

Node* create_LL(){
    int n;
    cin >> n;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insert(head,data);
    }
    return head;
}

Node* Merge(vector<Node*>& v){
    vector<Node*> nodes;
    for(auto head : v){
        Node* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp);
            temp=temp->next;
        }
    }

    if(nodes.empty()){
        return NULL;
    }

    sort(nodes.begin(),nodes.end(),[](Node* a,Node* b){
        return a->data < b->data;
    });

    for(int i=0;i<nodes.size()-1;i++){
        nodes[i]->next=nodes[i+1];
    }
    nodes[nodes.size()-1]->next=NULL;
    return nodes[0];
}

void print(Node* head) {
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }cout << endl;
}

int main(){
    int n;
    cin >> n;

    vector<Node*> v;
    for(int i=0;i<n;i++){
        Node* head=create_LL();
        v.push_back(head);
    }

    Node* merged=Merge(v);
    print(merged);
}
