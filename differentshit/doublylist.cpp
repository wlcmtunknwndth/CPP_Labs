#include <iostream>
using namespace std;
#define fck counter
 
class Node 
{
public:
    int value; //данные 
    Node* next; //указатель на следующий узел
    Node* prev; //указатель на предыдущий
    int Num; //counter
};
 
class List
{
public:
    Node* head;
    Node* tail;
    List()  
    {
        this->head=nullptr;
        this->tail=nullptr;
    }
    //Function below
    void push(int value) //Last In-First Out
    { 
        int fck;
        Node *node = new Node;
        node->value=value;
        if(head==nullptr) 
        {
            node->next=tail;
            head=node;
            node->prev=nullptr;
            fck=0;
            node->Num=fck;
            fck++;
        }
        else
        {
            node->next=tail->next;    
            node->prev=tail;
            tail->next=node;
            node->Num=fck;
            fck++;
        }
        tail=node;
    }
    //Function below
    void printAll()
    {
        if(head!=nullptr)
        { //пока не закончатся элементы
            Node* node=head;
            while (node!=nullptr)
            {
                cout<<node->value<<"-"<<node->Num<<" "<<endl;
                node=node->next;
            }
        } 
    }
    void moveonbro() //aye i mean get the next one elem bro hold on
    {
        cout << endl << "moveonbro: " << endl;
        int cunter=0;// i got no great ideas therefore you gain tha worst idea i came to
        Node* node=head;    
        cout << node->value << " "<< endl;
        node=head->next;
    }
    void get_prev() //The proof that there are no elems behind the header, just switch in str 56 tail to head and backwards 
    {
        cout << endl << "get_prev: " << endl;
        Node* node=tail;
        node=node->prev;
        cout << node->value;
    }
    void get_AllPrevious()
    {
        cout << endl << "get_AllPrevious: " << endl;
        if (head!=nullptr)
        {
            Node* node=tail;
            while (node!=nullptr)
            {   
            cout<<node->value<<" ";
            node=node->prev;
            }
        }
    }
    void find_element(double elem)
    {
        cout << endl << "find_element:" << endl;
        Node* node=tail; 
        while(elem!=node->value)
        {
            if(node->prev!=nullptr)
            {
                // cout << node->value << " and " << elem << endl;
                node=node->prev; 
            }
            else
            {
                cout << "for your num " << elem << " no matches";
                return void();
            }
        }
        cout << "for your num " << elem << " we have a match under the serial number " << node->Num << endl;
        cout << node->value << " and " << elem << endl; 
    }
    void Take(int SerialNum)
    {
        cout << endl << "Take:" << endl;
        Node* node=head; 
        while(SerialNum!=node->Num)
        {
            node=node->next;
            if(SerialNum>tail->Num)
            {
                cout << "There is no an element with such serial number";
                return void();
            }
        }
        cout << node->value << " is under the selected serial number";
    }
};

int main()
{
    List* lst = new List();
    lst->push(12);
    lst->push(260);
    lst->push(120);
    lst->printAll();
    lst->get_AllPrevious();
    cout << endl; 
    // lst->get_prev();
    lst->find_element(12);
    lst->find_element(15);
    cout << endl;
    lst->moveonbro();
    lst->Take(2);
    return 0;
}