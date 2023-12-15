// 04. CSLL

#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head=NULL;
class SLL_Insert
{
    public:
    //Insert at the Beginning
    void insertbeg()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
        nn->next=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
            nn->next=head;
        }
        else
        {
            cin>>nn->data;
            node *temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->next=head;
            head=nn;
        }
    }
    //Insert at the Specific Location
    void insertloc()
    {
        int loc;
        node *nn=new node;
        nn->next=NULL;
        node *temp=head;
        cout<<"Enter the Location :"<<endl;
        cin>>loc;
        cout<<"Enter the data :"<<endl;
        if(loc<1)
        {
            cout<<"Location should be greater than 1.\n";
        }
        else if(loc==1)
        {
            if(head==NULL)
            {
                cin>>nn->data;
                head=nn;
                head->next=head;
            }
            else
            {
                cin>>nn->data;
                temp=head;
                while (temp->next!=head)
                {
                    temp=temp->next;
                }
                nn->next=head;
                head=nn;
                temp->next=head;
            }
        }
        else
        {
            temp=head;
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
                temp->next=nn;
            }
            else
            {
                cout<<"The previoud node is NULL\n";   
            }
        }
    }
    //Insert at the END
    void insertend()
    {
        cout<<"Enter the data :"<<endl;
        node *nn=new node;
        nn->next=NULL;
        if(head==NULL)
        {
            cin>>nn->data;
            head=nn;
            nn->next=head;
        }
        else
        {
            cin>>nn->data;
            node *temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->next=head;
        }
    }
    
    void deletebin()
    {
        if(head==NULL)
    {
        cout<<"List is Empty please Insert a Node First\n"<<endl;
    }
    if(head!=NULL)
    {
        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            node *temp=head;
            node *fn=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            head=head->next;
            temp->next=head;
            delete fn;
        }
    }
        
   }
   void deleteend()
   {
    if(head==NULL)
    {
        cout<<"List is Empty please Insert a Node First\n"<<endl;
    }
    if(head!=NULL)
    {
        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            node *temp=head;
            while(temp->next->next!=head)
            {
                temp=temp->next;
            }
            node *ln=temp->next;
            temp->next=head;
            delete ln;
        }
    }
   }
    void deleteran()
    {
    node *temp=head;
    node *del_node=head;
    int pos;
        cout<<"Enter the Position :"<<endl;
        cin>>pos;
        if(pos < 1) 
        {
            cout<<"\nPosition should be >= 1."<<endl;
    } 
    else if (pos == 1) 
    {
        if(head->next==head)
        {
                head=NULL;
            }
            else
            {
            while(temp->next->next!=head)
            {
                temp=temp->next;
            }
            head=head->next;
            temp->next=head;
            delete del_node;
        }
    }
    else
    {
        temp=head;
        for(int i=1; i<pos-1; i++)
        {
            temp=temp->next;
        }
        del_node=temp->next;
        temp->next=temp->next->next;
        delete del_node;
    }
    }
    void display()
    
    {
        node *temp=head;
        if(temp!=NULL)
        {
            cout<<"Start";
            while (1)
            {
                cout<<"->"<<temp->data;
                temp=temp->next;
                if(temp==head)
                break;
            }
            cout<<"->(Start) i.e. ->"<<temp->data<<endl;
        }
        else
        {
            cout<<"Node is Empty\n";
        }
    }
};
int main()
{
    SLL_Insert s_ins;
    int ch;
    while(1)
    {
        cout<<"1.Insert | 2. Delete | 3.Exit"<<endl;
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
                        case 1: s_ins.insertbeg();
                                s_ins.display();
                                break;

                        case 2: s_ins.insertloc();
                                s_ins.display();
                                break;

                      
                        case 3: s_ins.insertend();
                                s_ins.display();
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
                        case 1: s_ins.deletebin();
                                s_ins.display();
                                break;

                        case 2: s_ins.deleteran();
                                s_ins.display();
                                break;

                      
                        case 3: s_ins.deleteend();
                                s_ins.display();
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