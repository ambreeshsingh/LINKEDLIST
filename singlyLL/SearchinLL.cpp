#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;

    }
};

class List{
    public:
    Node* temp;
    Node*head;
    Node*tail;

    List(){
        head=tail=NULL;
    }
   void push_front(int value){
    Node* newnode=new Node(value);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;

    }

   }
//    linear serch
 int ls(int key){
    temp=head;
    int idx=0;
    while(temp!=NULL){
        if(temp->data==key){
            return idx;
        }
        idx++;
        temp=temp->next;
    }
return -1;


 }

 int findmiddle() {
    Node* temp = head;
    int size = 0;

    while (temp != NULL) {   // size = 1
        size++;
        temp = temp->next;
    }

    int mid = size / 2;      // mid = 1 / 2 = 0
    temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;   // loop won’t run
    }

    if (temp != NULL)
        return temp->data;   // returns 10 ✅
    return -1;
}

   


   void print(){
   temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ->";
        temp=temp->next;
    }

   }

};


int main(){
    List ll;
    ll.push_front(2);
      ll.push_front(3);
        ll.push_front(4);
          ll.push_front(6);
        //  cout<< ll.ls(4);
        cout<< ll.findmiddle();
          


}