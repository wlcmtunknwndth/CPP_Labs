#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

struct Thing
{
    string name;
    float price;
    int amount;
    Thing *next;
};

struct List
{
    Thing* head=nullptr;

    void pushtohead(Thing* node)
    {
        if(head==nullptr)
        {
            head=node;
            head->next=nullptr;
        }
        else
        {
        Thing* tmp=new Thing;
        tmp=head;
        head->next=tmp;
        tmp->next=nullptr;
        head=node;
        }
    }

    int LookThrough()
    {
        cout << setiosflags(ios::left) << setw(10) << "Name" << setw(10) << "Price" << setw(10) << "Amount" << endl;
        Thing* TMP=new Thing;
        TMP=head;
        while(TMP != nullptr)
        {
        cout << setiosflags(ios::left) << setw(10) << head->name << setw(10) << head->price << setw(10) << head->amount << endl;
        TMP->next;
        }
        return 0;
    }

    Thing* createNode()
    {   
        cout << "--------------------------------------------------";
        cout << "\nVvedite Nazvanie novogo tovara: ";
        string nazvanie;
        cin >> nazvanie;

        cout << "\nVvedite tseny: ";
        float tsena;
        cin >> tsena;

        cout << "\nVvedite kolichestvo: ";
        int kolichestvo;
        cin >> kolichestvo;
        
        Thing* node=new Thing;
        node->name=nazvanie;
        node->amount=kolichestvo;
        node->price=tsena;
        return node;
    }

};

int main()
{
    List* lst=new List;
    lst->pushtohead(lst->createNode());
    lst->pushtohead(lst->createNode());
    // lst->createNode();

    lst->LookThrough();
    delete lst;
}
