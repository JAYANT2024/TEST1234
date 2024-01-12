#include<iostream>
using namespace std;

class node
{
    public:

    int value;
    node *next;
    node *prev;

    node()
    {
        next = prev = NULL;
    }
};

class DLL
{
    node *head , *last;

    public :
        DLL()
        {
            head = NULL;
            last = NULL;
        }

        void insert_at_beg(int x)
        {
            node *temp = new node();
            temp->value = x;

            if(head == NULL)
            {
                head = temp;
                last = temp;
                temp->prev = temp;
                temp->next = temp;
            }
            else
            {
                last->next = temp;
                temp->next = head;
                head->prev = temp;
                temp->prev = last;
                head = temp;
            }
        }

        void insert_at_End(int x)
        {
            node *temp = new node();
            temp->value = x;

            if(head == NULL)
            {
                head = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                temp->prev = last;
                temp->next = head;
                head->prev = temp;
                last = temp;
            }
        }

        void insert_at_Middle(int x , int index)
        {
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
                node *temp = new node();
                temp->value = x;

            if(index == 0)
            {
                head->prev = temp;
                temp->next = head;
                temp->prev = last;
                last->next = temp;
                head = temp;
            }
            else
            {
                node *ptr = head;
                while(index > 1)
                {
                    ptr = ptr->next;
                    index--;
                }

                if(ptr == last)
                {
                    last->next = temp;
                    temp->prev = last;
                    temp->next = head;
                    head->prev = temp;
                    last = temp;
                }
                else{
                     temp->next = ptr->next;
                     temp->next->prev = temp;
                     ptr->next = temp;
                     temp->prev = ptr;
                }
            }
        }


       // Need to update
        void deletion_from_beg()
        {
            if(head == NULL)
            {
                cout<<"List is empty";
            }
            else
            {
                cout<<"Deleted element = "<<head->value<<endl;
                node *temp = head;
                head  = temp->next;
                head->prev = NULL;
                delete(temp);
            }
        }

        // Need to update
        void deletion_at_end()
        {
            if(head == NULL)
            {
                cout<<"List is Empty"<<endl;
            }
            else if(head->next == NULL)
            {
                delete (head);
                head = NULL;
            }
            else
            {
                node *ptr = head;

                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }

                ptr->prev->next = NULL;
                delete(ptr);
            }
        }

        // need to update
        void deletion_at_middle(int index)
        {
            if(head == NULL)
            {
                cout<<"List is Empty"<<endl;
            }
            else if(index == 0)
            {
                delete (head);
                head = NULL;
            }
            else
            {
                node *ptr = head;
                while(index > 0)
                {
                    if(ptr->next == NULL)
                        break;

                    ptr = ptr->next;
                    index--;
                }
                ptr->prev->next = ptr->next;

                if(ptr->next  != NULL)
                    ptr->next->prev = ptr->prev;

                delete (ptr);
            }
        }


        void display()
            {
                if(head == NULL)
                {
                    cout<<"Linked List is Empty"<<endl;
                }
                else{

                        node *temp = head;

                        // need to check
                        while( temp->next != head)
                        {
                            cout<<temp->value<<" <-> ";
                            temp = temp->next;
                        }
                        cout<<endl;
                }
            }
};

int main()
{
    DLL l1;
    int x = 1;

    while(x == 1)
    {
    cout<<"1) Insertion at the beginning"<<endl;
    cout<<"2) Insertion in the middle"<<endl;
    cout<<"3) Insertion at the end"<<endl;
    cout<<"4) Deletion at the beginning"<<endl;
    cout<<"5) Deletion in the middle"<<endl;
    cout<<"6) Deletion at the end"<<endl;
    cout<<"7) Display all the element"<<endl;

    int choice;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    int value,index;

    switch(choice)
    {
        case 1 : cout<<"Enter the element"<<endl;
                 cin>>value;
                 l1.insert_at_beg(value);
                 break;

        case 2 : cout<<"Enter the element"<<endl;
                 cin>>value;
                 cout<<"Enter the index"<<endl;
                 cin>>index;
                 l1.insert_at_Middle(value, index);
                 break;

        case 3 : cout<<"Enter the element"<<endl;
                 cin>>value;
                 l1.insert_at_End(value);
                 break;

        case 4 :
                l1.deletion_from_beg();
                break;

        case 5 : cout<<"Enter the index"<<endl;
                 cin>>index;
                 l1.deletion_at_middle(index);
                 break;

        case 6 : l1.deletion_at_end();
                 break;

        case 7 : l1.display();
                 break;

        default :
                 cout<<"Invalid choice"<<endl;

    }

        cout<<"Do you want to continue (yes = 1) and (No = 0)"<<endl;
        cin>>x;
    }

    return 0;
}
