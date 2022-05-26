#include <iomanip>
#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace std;

struct Thing
{
	string name;
	float price;
	int amount;
	Thing* next;	
};

struct List
{
	Thing* head=NULL;
	
	Thing* createNode()
	{
		cout<< "---------------------------------------" << endl;
		cout << "\nVvedite nazvanie novogo producta: ";
		string nazvanie;
		cin >> nazvanie;
		
		cout << "\nVvedite tsenu novogo producta: ";
		float tsena;
		cin >> tsena;
		
		cout << "\nVvedite kolichestvo novogo tovara: ";
		int kolichestvo;
		cin >> kolichestvo;
		
		Thing *tovar=new Thing;
		tovar->amount=kolichestvo;
		tovar->name=nazvanie;
		tovar->price=tsena;
		tovar->next=NULL;
		return tovar;
	}
	
	void PushToHead(Thing* node)
	{
			Thing* TMP=new Thing;
			TMP=head;
			if(head==NULL)
			{
				head=node;
				head->next=NULL;
			}
			else
			{
				head=node;
				head->next=TMP;
			}
	}
	
	void PushToTail(Thing* node)
	{
		if(head==NULL)
		{
			head=node;
			node->next=NULL;
		}
		else if (head->next == NULL)
		{
			head->next=node;
			node->next=NULL;
		}
		else
		{
			Thing* tmp3=head;
			while (tmp3->next != NULL)
			{
				tmp3=tmp3->next;
			}
			tmp3->next=node;
		}
		
	}
	
	void printAll()
	{
		Thing* tmp=new Thing;
		tmp=head;
		unsigned int counter=0;
		cout << setiosflags(ios::left) << setw(5) << "Num" << setw(10) << "Name" << setw(10) << "Price" << setw(10) << "Amount" << endl;
		while(tmp != NULL)
		{
			cout << setiosflags(ios::left) << setw(5) << counter << setw(10) << tmp->name << setw(10) << tmp->price << setw(10) << tmp->amount << endl;
			tmp=tmp->next;
			counter++;
		}
		delete tmp;
	}

	int deleteNode()
	{
		cout << "\nVvedite nazvanie tovara, kotoriy nado udalit': ";
		string imya;
		cin >> imya;

		Thing* prev=new Thing;
		prev=NULL;
		Thing* tmp3=new Thing;
		tmp3=head;

		if (tmp3->name == imya)
		{
			delete tmp3;
			head=head->next;
			return 0;  
		}
		
		while (tmp3->name != imya)
		{
			prev=tmp3;
			if (tmp3 == NULL)
			{
				cout << "\nNet takogo elementa";
				return 0;
			}
			tmp3=tmp3->next;	
		}
		tmp3=tmp3->next;
		prev->next=tmp3;
		return 0;
	}

	int AddBefore(Thing* node, unsigned int BeforeWhatElem)
	{
		Thing* tmp4=new Thing;
		Thing* prev=new Thing;
		prev = NULL;
		tmp4=head;
		unsigned int counter1=0;

		if (BeforeWhatElem == 0)
		{
			head=node;
			head->next=tmp4;
			return 0;
		}
		
		while (counter1 != BeforeWhatElem)
		{
			if (tmp4 == NULL)
			{
				cout << "no such elem";
				return 0;
			}
			prev=tmp4;
			tmp4=tmp4->next;
			counter1++;	
		}
		prev->next=node;
		node->next=tmp4;
		return 0;
	}

	int AddAfter(Thing* node, int AddAfterWhat)
	{
		// Thing* NextTmp=new Thing;
		// NextTmp=NULL;
		// Thing* tmp=new Thing;
		// tmp=head;
		// unsigned int counter=0;

		// while (counter != AddAfterWhat)
		// {
		// 	counter++;
		// 	if(tmp == NULL)
		// 	{
		// 		cout << "\nfor Adding elem after found no such elem//no serial number exists\n";
		// 		return 0;
		// 	}
		// 	tmp=tmp->next;
		// }

		// if (tmp->next=NULL)
		// {
		// 	tmp->next=node;
		// 	node->next=NULL;
		// 	return 0;
		// }
		
		// node->next=tmp->next;
		// tmp->next=node;

		// return 0;
		Thing* tmp5=new Thing;
		Thing* prev1=new Thing;
		prev1 = NULL;
		tmp5=head;
		unsigned int counter1=0;

		if (AddAfterWhat == 0)
		{
			node->next=head->next;
			head->next=node;
			return 0;
		}
		
		while (counter1 <= AddAfterWhat)
		{
			if (tmp5 == NULL)
			{
				cout << "no such elem";
				return 0;
			}
			prev1=tmp5;
			tmp5=tmp5->next;
			counter1++;	
		}
		prev1->next=node;
		node->next=tmp5;
		return 0;
	}
	
	int ViborFunktsii()
	{
		cout << "Spisok funktsiy:\n" << "1. Create & Push to head\n" << "2. Create & Push to tail\n" << "3. Print all\n" << "4. Delete node\n" << "5. Create & push after smth\n" << "6. Create & push before smth\n" << "7. quit\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			PushToHead(createNode());
			cout << "\nContinue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 2:
			PushToTail(createNode());
			cout << "Continue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 3:
			printAll();
			cout << "Continue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 4:
			deleteNode();
			cout << "Continue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 5:
			cout << "Vvedite poryadkoviy nomer:";
			int a;
			cin >> a;
			AddAfter(createNode(), a);
			cout << "Continue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 6:
			cout << "Vvedite poryadkoviy nomer:";
			int b;
			cin >> b;
			AddBefore(createNode(), b);
			cout << "Continue?(y/n):";
			if (getch() == 'y')
			{
				ViborFunktsii();
				break;
			}
			else
			{
				break; 
			}
		case 7:
			break;
		default:    
			cout << "Net takogo varianta!!!";
			ViborFunktsii();
			break;
		}
	}
};

int main()
{
	// List* lst=new List;
	// lst->PushToHead(lst->createNode());
	// lst->PushToHead(lst->createNode());
	// lst->PushToTail(lst->createNode());
	
	// lst->printAll();
	// lst->deleteNode();
	// lst->AddBefore(lst->createNode(), 0);
	// lst->printAll();
	// lst->AddAfter(lst->createNode(), 1);
	// lst->printAll();
	// getch();
	// delete lst;
	// return 0;

	//scha budet tvorchestvo mne indifferentno idk nah e by ecco2k is fire af

	cout << "\nDvusvyazniy spisok by Petrov Artem\n";
	List* lst=new List;
	lst->ViborFunktsii();
	getch();
	delete lst;
	return 0;
}