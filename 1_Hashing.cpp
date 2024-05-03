#include<iostream>
using namespace std;

class HashTable  //Creating Hash Table 
{
public:
	int key;
	long int TelNo;
};

class Hashing //Class For Hash Table Initialization and Operations 
{
public:
	HashTable t[10];
	int i;
	Hashing()
	{
    	for(i = 0; i<10; i++)
     	{ 
        	t[i].key = i;
        	t[i].TelNo = -1;
    	}
	}

	void Display() //Displaying Hash Table
 	{
    	cout<<"Key\t\tTelephone Number\n";
    	for(int i = 0; i<10; i++)
    	{
        	cout<<t[i].key << "\t\t" << t[i].TelNo<<"\n";
     	}
	}

	void Insert() //Inserting TelNo into Hash Table
	{
    	int hashval,num,ch;
   	 
    	cout<<"Enter the Telephone Number: ";
    	cin>>num;
    	hashval=num % 10;
    	if(t[hashval].TelNo == -1)
    	{
        	t[hashval].TelNo = num;
        	cout<<"\nElement inserted in Hash Table.";
    	}
     	else
     	{
     		cout<<"\n1]linear Probing\n2]Quadratic Probing";
     		cout<<"\nPlease Select Method to Resolve Collision: ";
     		cin>>ch;
     		if(ch==1)
     		{
				for(int i=1; i<10; i++)
				{
				    if(t[hashval+i].TelNo == -1)
				    {
						t[hashval+i].TelNo = num;
						cout<<"\nElement inserted in Hash Table.";
						return;
					}
				}
			}
			else if(ch==2)
			{
				for(int i=1; i<10; i++)
				{
				    if(t[hashval+(i*i)].TelNo == -1)
				    {
						t[hashval+(i*i)].TelNo = num;
						cout<<"\nElement inserted in Hash Table.";
						return;
					}
				}
			}
			cout<<"\nHash table is full. Unable to insert.\n";
    	}
	}
	
	void Delete() //Removing TelNo From Hash Table
	{
		long int num;
		cout<<"\nEnter the Telephone Number: ";
		cin>>num;
		for(int i=0; i<10; i++)
		{
			if(t[i].TelNo == num)
			{
				t[i].TelNo = -1;
				cout<<"\nTelephone Number Deleted Successfully.";
				return;
			}
		}
	}
};


int main()
{
	Hashing h;
	int choice;
	do
	{
    	cout<<"\n\nMENU:\n";
    	cout<<"1]Insert Telephone Number\n";
    	cout<<"2]Display Hash Table\n";
    	cout<<"3]Delete Telephone Number\n";
    	cout<<"4]Exit\n";
    	cout<<"Enter your choice: ";
    	cin>>choice;

    	switch(choice)
     	{
        	case 1:
            	h.Insert();
            	break;
        	case 2:
            	h.Display();
            	break;
            case 3:
            	h.Delete();
            	break;
        	case 4:
            	cout<<"Terminating Program....\n";
            	break;
        	default:
            	cout<<"Invalid choice!! Please try again.\n";
    	}
	}while(choice != 0);
	return 0;
}
