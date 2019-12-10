#include <iostream>

using namespace std;

class Node{
public:
        int info;
        Node *next;
};

class List{
private:
    Node *head;
    Node *tail;
public:
    List();
    //~List();
    bool isEmpty();
    void addToHead(int data);
    void add(int data,Node* &predecessor);
    void addToTail(int data);
    void removeFromHead();
    bool Remove(int data);
    bool Search(int data);
    void traverse();
    bool retrieve(int data, Node* &outputptr);
};

List::List(){
    head=NULL;
    tail=NULL;
}

bool List::isEmpty(){
    if (head==NULL){
        return true;
    }
    else{
        return false;
    }
}

void List::addToHead(int data){
    Node *newNode;
    newNode->info=data;
    newNode->next=head;
    head=newNode;
    if (tail==NULL){
        tail=head;
    }
}

void List::addToTail(int data){
    Node *newNode;
    newNode->info=data;
    newNode->next=NULL;
    tail->next=newNode;
    tail=newNode;

}

void List::add(int data,Node* &predecessor){
    Node *newNode;
    newNode->info=data;
    newNode->next = predecessor->next;
    predecessor->next=newNode;
}

void List::removeFromHead(){
    Node *NodeToDelete=head;
    head=head->next;
    delete NodeToDelete;
}

bool List::Remove(int data){
    if (isEmpty()==true){
        cout<<"list is empty";
        return false;
    }
    if (head->info==data){
        removeFromHead();
        if (head==NULL){
            tail=NULL;
        }
    }
    else {
        Node *temp;
        Node *prev;
        temp=head->next;
        prev=head;
        while(temp!=NULL){
            if (temp->info==data){
                prev->next=temp->next;
                delete temp;
                if (prev->next==NULL){
                    tail=prev;
                }
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }

        }
    }
}
bool List::Search(int data){
    if (isEmpty()==true){
        cout<<"list is empty";
        return false;
    }
    Node *temp=head;
    while (temp!=NULL){
        if (temp->info==data){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}

void List::traverse(){
    if (isEmpty()==true){
        cout<<"list is empty";
    }
    else{
        Node *temp=head;
        while (temp!=NULL){
            cout<<temp->info<<endl;
            temp=temp->next;
        }
    }
}

bool List::retrieve(int data, Node* &outputptr){
    Node*p=head;
    while(p!=NULL && p->info!=data){
        p=p->next;
    }
    if (p==NULL){
        return false;
    }
    else{
        outputptr=p;
        return true;
    }
}




int main()
{
    List LL;
    LL.addToHead(5);
    LL.addToTail(8);
    Node *tempptr;
    LL.add(7,tempptr);
    LL.addToTail(1);
    LL.traverse();
    LL.removeFromHead();
    LL.Remove(5);
    LL.Remove(1);
    Node *outputptr;
    LL.retrieve(5,outputptr);
    LL.traverse();
    return 0;
}
