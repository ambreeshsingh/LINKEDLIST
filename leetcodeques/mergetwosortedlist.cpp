#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    public:
    Node*head;
    List(){
        head=NULL;
    }
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;

        }

    }

};

 void print(Node* head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
           
        }
         cout<<"NULL"<<endl;


    }
    Node *mergetwosortedlist(Node* head1,Node* head2){
         Node * first=NULL;
         Node* second=NULL;
        if(head1->data<=head2->data){
              first=head1;
              second=head2;

        }else{
             first=head2;
             second=head1;
        }

        if(first==NULL)return second;
        if(second==NULL)return first;

        Node*temp1=first;
        Node*temp2=second;
        Node*next1=first->next;
        Node*next2=second->next;

        while (next1!=NULL&&temp2!=NULL)
        {
            if(temp1->data<=temp2->data &&temp2->data<=next1->data){
                temp2->next=NULL;
                temp1->next=temp2;
                temp2->next=next1;

                ///updation
                temp1=temp1->next;
                temp2=next2;
                if(next2!=NULL){
                    next2=next2->next;
                }

            }
            else{
                //only updation needed
                temp1=next1;
                next1=temp1->next;

            }
        }
        if(temp2==NULL){
            return first;
        }
        temp1->next=temp2;
        return second;
        
        
    }




int main(){
    List l1,l2;
    //list1=9->8->7->6->5->NULL
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(1);

    //list2=5->4->3->2->1->NULL
    l2.push_front(6);   
    l2.push_front(3);   
    l2.push_front(2);   


    cout<<"List1"<<endl;
    print(l1.head);

    cout<<"List2"<<endl;
    print(l2.head);

    Node *merged=mergetwosortedlist(l1.head,l2.head);

    cout<<"mergedlist"<<endl;
    print(merged);




 

    return 0;
}