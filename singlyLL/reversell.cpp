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
class List{
    public:
    Node*head;
    Node*tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node*newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;


        }
        else{
            newnode->next=head;
            head=newnode;
        }



    }
    void reverse(){
        Node*prev=NULL;
        Node*curr=head;
        Node*nexttt=NULL;
        while(curr!=NULL){
            nexttt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexttt;
        }
        head=prev;


    }



        
    void printList() { // ✅ helper to check output
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


};

int main(){
    List ll;
    ll.push_front(65);
        ll.push_front(5);
            ll.push_front(6);
            ll.printList();
            cout<<endl;
            ll.reverse();
             ll.printList();
             


    return 0;
}