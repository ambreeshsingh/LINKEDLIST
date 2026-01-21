#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        value=data;
        Node*next=NULL;

    }

};
class List{
    public:
    Node*head;
    Node*tail;
    List(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
          head=tail=newNode;
          return;

    }
    else{
        newNode->next=head;
        head=newNode;
    }
  



    }
      void print(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
        
    }

};


int main(){
    List ll;
   ll.push_front(4);
   ll.print();

    return 0;
}