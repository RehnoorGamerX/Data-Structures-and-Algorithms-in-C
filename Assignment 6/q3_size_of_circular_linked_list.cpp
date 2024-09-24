#include<iostream>
using namespace std;

//Definition of Circular Linked List, you can see main function for the solution 
class Node
{
    public:
    int val;
    Node *next;
    Node()
    {
        val=0;
        next=NULL;
    }
    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

class CircularLinkedList
{
    public:
    Node *start;
    int size;
    CircularLinkedList()
    {
        start=NULL;
        size=0;
    }
    void insertAtBeginning(int data)
    {
        Node *nnode=new Node(data);
        if(start==NULL)
        {
            start=nnode;
            nnode->next=start;
        }
        else
        {
            nnode->next=start;
            Node *temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=nnode;
            start=nnode;
            cout<<data<<" inserted Successfully at Beginning"<<endl;
        }
        size++;
        
    }
    void insertAtEnd(int data)
    {
        Node *nnode=new Node(data);
        if(start==NULL)
        {
            start=nnode;
            nnode->next=start;
        }
        else
        {
            Node *temp=start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next=nnode;
            nnode->next=start;
            cout<<data<<" inserted Successfully at End"<<endl;
        }
        size++;
        
    }
    void insertInBetween(int data, int pos)
    {
        //Insert the data before the pos value
        Node *temp=start;
        while(temp->next->val!=pos)
        {
            temp=temp->next;
        }
        Node *nnode=new Node(data);
        Node *t=temp->next;
        temp->next=nnode;
        nnode->next=t;
        cout<<data<<" inserted before "<<pos<<endl;
        size++;
    }
    void deleteNode(int data)
    {
        //Delete the node with data, it may be in the beginning or end or in between
        //We will manage this using edge cases
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        //Delete from beginning
        if(start->val==data)
        {
            Node *temp=start;
            //temp will be used to assign the last pointer to start
            Node *t=start;
            //It will be used to delete t
            start=start->next;
            temp=temp->next;
            while(temp->next!=t)
            {
                temp=temp->next;
            }
            temp->next=start;
            cout<<data<<" deleted successfully from the list"<<endl;
            delete(t);
            return;
            
        }
        //Delete from Middle
        Node *prev=start;
        Node *temp=start->next;
        while(temp->next!=start)
        {
            if(temp->val==data)
            {
                prev->next=temp->next;
                delete(temp);
                cout<<data<<" deleted successfully from the list"<<endl;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        if(temp->val==data)
        {
            prev->next=start;
            delete(temp);
            cout<<data<<" deleted successfully from the list"<<endl;
            return;
        }
        cout<<data<<" Not Found!!!"<<endl;

    }
    void search(int data)
    {
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        do
        {
            if(temp->val==data)
            {
                cout<<data<<" found in the list"<<endl;
                return;
            }
            temp=temp->next;
        }while(temp!=start);
        cout<<data<<" Not Found!!!"<<endl;
    }
    void display()
    {
        if(start==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
            return;
        }
        Node *temp=start;
        cout<<"-------------Printing Circular Linked List---------------"<<endl;
        cout<<"start-->";
        do
        {
            cout<<temp->val<<"-->";
            temp=temp->next;
        } while (temp!=start);
        cout<<"start"<<endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);
    cll.insertAtEnd(60);
    cll.insertAtEnd(70);
    cll.insertAtEnd(80);
    cll.insertAtEnd(90);
    cll.insertAtEnd(100);
    int size=0;
    Node *temp=cll.start;
    if(temp==NULL)
    {
        cout<<"Size of Linked List is "<<size<<endl;
        return 0;
    }
    while(temp->next!=cll.start)
    {
        size++;
        temp=temp->next;
    }
    //Add one for the last node
    size++;
    cout<<"Size of Linked List is "<<size<<endl;    

}