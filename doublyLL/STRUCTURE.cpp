#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;

    }
};
class DoublyList{
    Node*head;
    Node*tail;//can be implemented without this
  public:
  DoublyList(){
    head = NULL;
    tail = NULL;

  }
   void push_front(int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=tail=newNode;
    }
    else{//ll already exist
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
   }
//    PUSH BACK

    void push_back(int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=tail=newNode;
    }
    else{//ll already exist
       newNode->prev=tail;
       tail->next=newNode;
       tail=newNode;
    }
   }

//  pop_front
 void pop_front(){
    Node* temp=head;
    if(head==NULL){
        cout<<"dobly is empty"<<endl;
    }
    head=temp->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    temp->next=NULL;
    delete temp;
 }

 //pop back

 void pop_back(){
    Node* temp=head;
    if(head==NULL){
        cout<<"doublu ll is empty"<<endl;
    }
    tail=tail->prev;
    if(tail!=NULL){
        tail->next=NULL;
    }
    temp->prev=NULL;
 }



   void print(){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
   }
    



};
int main(){
    DoublyList dll;

    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.print();

    // dll.push_back(4);
    // dll.push_back(5);
    // dll.push_back(6);
    // dll.print();

    // dll.pop_front();
    //  dll.print();

    dll.pop_back();
    dll.print();

            return 0;

}