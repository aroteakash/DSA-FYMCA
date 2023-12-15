// 03. Write a menu driven program to perform operations on doubly linked list 
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
node *head=NULL;
class DLL_new
{
    public:
    //Insertion at the Beginning
    void insertbeg()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
        nn->next=head;
        nn->prev=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
        }
        else
        {
            cin>>nn->data;  
            head->prev=nn;
            head=nn;
        }
    }
    //Insertion at the END
    void insertend()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
            nn->next=NULL;
            nn->prev=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
        }
        else
        {
            cin>>nn->data;
            node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->prev=temp;
        }
    }
    //Insertion at Specific Location
    void insertloc()
    {
        int loc;
        node *nn=new node;
        nn->next=NULL;
        nn->prev=NULL;
        cout<<"Enter the Location :"<<endl;
        cin>>loc;
        cout<<"Enter the data :"<<endl;
        if(loc<1)
        {
            cout<<"Location should be greater than 1.\n";
        }
        else if(loc==1)
        {
            cin>>nn->data;
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
        else
        {
            node *temp=head;
            for(int i=1; i<loc-1; i++)
            {
                if(temp!=NULL)
                {
                    temp=temp->next;
                }
            }
            if(temp!=NULL)
            {
                cin>>nn->data;
                nn->next=temp->next;
                nn->prev=temp;
                temp->next=nn;
            }
            if(nn->next!=NULL)
            {
                nn->next->prev=nn;
            }
            else
            {
                cout<<"The previous node is null.\n";
            }
        }  
    }    
    void display()
    {
        node *temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void deletebeg()
    {
        node *temp;
        if(head==NULL)
        {
            cout<<"Please insert a node first..!";
        }
        else
        {
            temp=head;
            head->prev=NULL;
            head=head->next;
            delete temp;
        }
    }
    void deleteend()
    {
        if(head==NULL)
        {
            cout<<"Node is Empty.\n";
        }
        else
        {
            if (head->next==NULL)
            {
                head=NULL;
            }
            else
            {
                node *temp=head;
                while (temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                node *ln=temp->next;
                temp->next=NULL;
                delete ln;
            }
            
        }
    }
    void deleteloc()
    {
        if(head==NULL)
        {
            cout<<"The node is Empty\n";
        }
        else
        {
            int pos;
            cout<<"Enter the Position :"<<endl;
            cin>>pos;
            if(pos < 1) 
            {
                cout<<"\nPosition should be >= 1."<<endl;
            }
            else if (pos == 1 && head != NULL) 
            {
                node *del_node = head;
                head = head->next;
                delete del_node;
                if(head != NULL)
                {
                    head->prev = NULL;
                }
            } 
            else 
            {
                node *temp = head;
                for(int i = 1; i < pos-1; i++) 
                {
                    if(temp != NULL) 
                    {
                        temp = temp->next;
                    }
                } 
                if(temp != NULL && temp->next != NULL) 
                {
                    node *del_node = temp->next;
                    temp->next = temp->next->next;
                    if(temp->next->next != NULL)
                    {
                        temp->next->next->prev = temp->next;  
                    } 
                    delete del_node;
                } 
                else 
                {
                    cout<<"\nThe node is already null."<<endl;
                }       
            }   
        }
    } 
};
int main()
{
    DLL_new obj;
    int ch;
    while(1)
    {
        cout<<"1.Insert | 2.Delete | 3.Exit"<<endl;
        cout<<"Enter the choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1: int b;
                cout<<"1.Insert at Beginning|2.Insert at Specific Location|3.Insert at End "<<endl;
                cout<<"Enter the choice : ";
                cin>>b;
                    switch(b)
                    {
                        case 1: obj.insertbeg();
                                obj.display();
                                break;

                        case 2: obj.insertloc();
                                obj.display();
                                break;

                        case 3: obj.insertend();
                                obj.display();
                                break;
                      
                        default: cout<<"Invalid Choice :-(\n";
                                break;
                    }
                    break;
                    
    case 2: int d;
                cout<<"1.Delete at Beginning|2.Delete at Specific Location|3.Delete at End "<<endl;
                cout<<"Enter the choice : ";
                cin>>d;
                    switch(d)
                    {
                        case 1: obj.deletebeg();
                                obj.display();
                                break;


                        case 2: obj.deleteloc();
                                obj.display();
                                break;
                     
                        case 3: obj.deleteend();
                                obj.display();
                                break;
                        default: cout<<"Invalid Choice :-(\n";
                                break;
                    }
                    break;
     
        case 3: exit(0);

        default: cout<<"Invalid Choice :-(\n";
                break;
        }
        
    }
    return 0;
}

