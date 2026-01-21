#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;

    }
    
};
 class CircularList{
    Node*head;
    Node*tail;
    public:
    CircularList(){
        head=NULL;
        tail=NULL;
    }

    void inserAthead(int val){
// *** AGR   HEAD USE KIYA TO    ***//
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        
        }
        else{
            Node* newnode=new Node(val);
            newnode->next=head;
            head=newnode;
            // NEW
           tail->next=newnode;

        }


// *** AGR   HEAD USE   NAHI KIYA TO    ***//
//  Node* newnode=new Node(val);
//  if(tail==NULL){
//     tail=newnode;
//  }
//  else{
//  Node* newnode=new Node(val);
// newnode->next=tail->next;
// tail->next=newnode;
    
//  }

    }

    //BY USING ONLY TAIL NODE

    // void insertAtTail(int val){
    //      Node* newnode=new Node(val);
    //      if(tail==NULL){
    //         tail=newnode;
    //         tail->next=tail;

    //      }
    //      else{
    //           Node* newnode=new Node(val);
    //           newnode->next=tail->next;
    //           tail->next=newnode;
    //           tail=newnode;



    //      }

    // }

    void insertAtTail(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            tail->next=head;
        }
        else{
             Node* newnode=new Node(val);
             tail->next=newnode;
             tail=newnode;
             tail->next=head;
             
        }

    }
    // DELETE at TAIL
    void deleteAtHead(){
        Node* temp=head;
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=temp=NULL;

        }
        else{
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }

    }
    // DELETE AT TAIL
    void deleteAtTail(){
         Node* temp=tail;
        if(head==NULL) return;
        else if(head==tail){
            delete tail;
            head=tail=temp=NULL;

        }
        else{
             Node* prev=tail;
             while(prev->next!=tail){
                prev=prev->next;
             }
             tail=prev;
             tail->next=head;
             temp->next=NULL;
             delete temp;
            
        }
        

    }
    void print(){
       if(head==NULL){
        return;
       }
       cout<<head->data<<"->";
       Node*temp=head->next;
       while(temp!=head){
        cout<<temp->data<<"->";
        temp=temp->next;

       }
       cout<<"continue"<<endl;

    }

 };



int main(){
  CircularList ll;
  ll.inserAthead(3);
    ll.inserAthead(2);
      ll.inserAthead(1);
      ll.print();

      
      ll.insertAtTail(4);
      ll.insertAtTail(5);
      ll.insertAtTail(6);
      ll.print();

      ll.deleteAtHead();
      ll.print();

      ll.deleteAtTail();
      ll.print();

    return 0;
}
