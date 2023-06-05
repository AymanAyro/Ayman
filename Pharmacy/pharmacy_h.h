// Ayman Saber Gad // Mohamed Fathi Mohamed Mohamed Ali //Fourth Level
#include<iostream>
#include<string>
using namespace std;

class Drugs
{
public:
    string drug; //drug's name
    double price; //drug's price
    int id; //drug's id number
    int qt; //quantity of drug needed
    Drugs() //default constructor for initialization
    {
        drug="";
        price=0.0;
        id=0;
        qt=0;
    }
};
class Node
{
public:
    Drugs drg; //making object of the Drugs class including the info needed for each drug
    Node* next;
    Node* prev;

};
class Pharmacy_DoubleList
{
public:
    Node* h; //head of node
    Node* t; //tail of node
    Pharmacy_DoubleList() //Initializing my head and tail as NULL
    {
        h=NULL;
        t=NULL;
    }
    bool Is_Empty() //function for knowing if the list is empty
    {
        if(h==NULL && t==NULL)
            return true;
        else
            return false;
    }
    void Insert(int ID,string n, double p, int Q) //1.Inserting item to the list (Name,Price,ID,Quantity)
    {
        Node* NewNode=new Node; //Creating new node and giving it info
        NewNode->drg.drug=n;
        NewNode->drg.price=p;
        NewNode->drg.id=ID;
        NewNode->drg.qt=Q;
        if (h==NULL) //If list is empty
        {
            h=NewNode;
            t=NewNode;
        }
        else
        {
            //Inserting the node in the end of the list
            NewNode->prev=t;
            t->next=NewNode;
            t=NewNode;
        }

    }
    void Remove(int ID) //2.Remove an Item using its id
    {
        Node* q=h; //making a temporary node "q" to traverse the list
        if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
        else 
        {   
            while (q!=t->next)
            {
                if (q->drg.id==ID)
                {
                    if (q == h && q == t) // If the node to be deleted is the only node in the list
                    {
                        h = NULL;
                        t = NULL;
                    }
                    else if (q == h) // If the node to be deleted is the head node
                    {
                        h = q->next;
                        if (h!=NULL)
                        {
                            h->prev = NULL;
                        }
                    }
                    else if (q == t) // If the node to be deleted is the tail node
                    {
                        t = q->prev;
                        t->next = NULL;
                    }
                    else // If the node to be deleted is a node in the middle of the list
                    {
                        q->prev->next = q->next;
                        q->next->prev = q->prev;
                    }

                    delete q; //deleting the node
                    cout<<"Drug removed ! \n";
                    return;
                }
                q=q->next;
            }
            cout<<"Invalid ID \n";
        }
    }
    void Modify(int ID,string n, double p, int Q) //3.Modifying the name,price and quantity of a drug using its ID
    {
        Node* q=h;
        if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
        else
        {
            while (q!=t->next)
            {
                if (q->drg.id==ID)
                {
                    q->drg.drug=n;
                    q->drg.price=p;
                    q->drg.qt=Q;
                    cout<<"Drug modified!\n";
                    return;
                }
                q=q->next;
            }
            
            cout<<"Invalid ID \n";
            
            
        } 
    }
    void AutoCheck() //4.AutoCheck for going through the list and checking the stock
    {
    Node* q=h;
    if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
    else
    {
        while (q!=t->next)
        {
            cout<<q->drg.drug<<": "<<q->drg.qt<<"\n";
            q=q->next;
        }
        return;
    } 
    }
    void Location(int ID) //5.Location for locating the place of a certain drug using its ID
    {
        Node* q=h;
        int l=1;
        if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
        else
        {
            while (q!=t->next)
            {
                if (q->drg.id==ID)
                {
                cout<<"The drug's location is: "<<l<<"\n";
                return;
                }
                q=q->next;
                l++;
            }
            cout<<"Invalid ID \n";
        }
        
        

    }
    void GenerateBill(int ID, int Q) //6.GenerateBill for generating bill according to the ID of drug and the quantity
    {
        Node* q=h;
        double T=0; //for total price of the drug
        if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
        else
        {
            while (q!=t->next)
            {
                if (q->drg.id==ID)
                {
                    if (q->drg.qt>=Q)
                    {
                        int c=Q; //counter
                        while (c>0)
                        {
                            T+=q->drg.price; //Total=Total + price of the drug 
                            q->drg.qt--; //reduce the stock
                            c--;
                        }
                        cout<<"\t\t"<<"(Pharmacy Bill) \n\n";
                        cout<<"Drug"<<"\t\t"<<"Quantity"<<"\t"<<"Unit Price"<<"\n";
                        cout<<q->drg.drug<<"\t"<<Q<<"\t\t"<<q->drg.price<<"$\n";
                        cout<<"Total: "<<T<<"$\n";
                        return;
                    }
                    else
                    {
                        cout<<"Not enough quantity in stock \n";
                        return;
                    }
                }
                q=q->next;
            }
            cout<<"Invalid ID \n";
            
        }
     
    }
    void Display() //function for displaying the elements of the list
    {
        Node* q=h;
        if (Is_Empty())
        {
            cout<<"The list is empty \n";
        }
        else
        {
            cout<<"ID"<<"\t\t"<<"Drug"<<"\t\t\t\t"<<"Quantity"<<"\t"<<"Unit Price"<<"\n";
            
            while (q!=t->next)
            {
                cout<<q->drg.id<<"\t\t"<<q->drg.drug<<"\t\t\t"<<q->drg.qt<<"\t\t"<<q->drg.price<<"$\n";
                q=q->next;
            }
            return;
        }
    }
};


