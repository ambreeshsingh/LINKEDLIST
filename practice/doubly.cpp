#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int value;

    Node(int data){
        next=NULL;
        prev=NULL;
        value=data;

    }

};

class List{
    public:
    Node* head;
    Node* tail;
    
    List(){
        head=NULL;
        tail=NULL;
    }

    void pushfront(int data){

        if(head==NULL){
             Node* newnode=new Node(data);
             head=newnode;
             tail=newnode;

        }
         Node* newnode=new Node(data);
         newnode->next=head;
         head->prev=newnode;
         head=newnode;

    }
    void pushback(int data){
        if(head==NULL){
            pushfront(data);
        }
         Node* newnode=new Node(data);
         newnode->prev=tail;
         tail->next=newnode;
         tail=newnode;

    }

    void popback(){
        if(head==NULL){
            cout<<"Linked List is empty";
        }
        else{
         Node*temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;

        }
       
    }
    void popfront(){
        if(head==NULL){
            cout<<"Linked List is alredy empty";
        }
        else{
         Node*temp=head;
         head=head->next;
         head->prev=NULL;
         temp->next=NULL;
         delete temp;

        }
    }


};


int main(){
    List ll;
    ll.pushback(2);
    ll.pushfront(4);
      ll.pushfront(5);
        ll.pushfront(6);
        ll.popback();
        ll.popfront();

    return 0;

}