#include<iostream>
using namespace std;
class myclass{
int set[10],size=0;
public :
void insert();
void display();
void search();
void remove();
void Union_set(myclass &s2);
void Intersection_set(myclass &s2);
bool isSubset(myclass& s2);
};

void myclass::insert()
{	
	cout<<"\nEnter an element which you want to insert: ";
	cin>>set[size++];
}
	
void myclass::display()
{
	cout<<"\nDisplaying elements: ";
	for(int i=0;i<size;i++)
	{
	cout<<set[i]<<" ";
	}
}
	
void myclass::search()
{	
    int key;
	cout<<"\nEnter search element ";
	cin>>key;
	for(int i=0;i<10;i++)
	{
		if(set[i]==key)
		{
			cout<<"Element "<<key<<" present at position "<<i+1;
		}
	}
}

void myclass::remove()
{
	int del,result=-1;
	cout<<"Enter an element which you want to remove: ";
	cin>>del;
	for(int i=0;i<10;i++)
	{
	if(set[i]==del)
	{
	     result=i;
	     break;
	}
	}
	if(result!=-1)
	{
		for(int i=result;i<10;i++)
		{
			set[i]=set[i+1];
		}size--;
	}
	else
	{
		cout<<"Element not found";
	}
}

void myclass::Union_set(myclass& s2) 
{
    cout<<"Union of sets: ";
    
    for(int i=0;i<size;i++) 
	{
        cout<<set[i]<<" ";
    }

    for(int j=0;j<s2.size;j++) 
	{
        bool isCommon=false;
        for(int i=0;i<size;i++) 
		{
            if(s2.set[j]==set[i])
			{
                isCommon=true;
                break;
            }
        }
        if(!isCommon) 
		{
            cout<<s2.set[j]<<" ";
        }
    }
}

void myclass::Intersection_set(myclass& s2)
{
    cout<<"Intersection of sets: ";
    for(int i=0;i<size;i++) 
	{
        for(int j=0;j<s2.size;j++) 
		{
            if(set[i]==s2.set[j]) 
			{
                cout<<set[i]<<" ";
                break;
            }
        }
    }
}

bool myclass::isSubset(myclass& s2) 
{
	  for(int i=0; i<s2.size; i++) 
	  {
	    bool found = false;
	    for (int j=0; j<size; j++) {
	      if (s2.set[i] == set[j]) 
		  {
	        found = true;
	        break; 
	      }
	    }
	    if (!found)
		{
	      return false;
	    }
	  }
	  return true;
}

int main(){
myclass m1,m2;
int ch;
bool result;
do
{
	cout<<"\n\n1.Insert an element"<<"\n2.Display elements"<<"\n3.Search an element"<<"\n4.Remove an element"<<"\n5.Union of set"<<"\n6.Intersection of set"<<"\n7.Subset";
	cout<<"\n\nEnter your choice: ";
	cin>>ch;
	switch(ch){
	case 1:cout<<"\nInsert SET 1 Element: ";
		   m1.insert();
		   cout<<"\nInsert SET 2 Element: ";
	       m2.insert();
	       break;
	case 2:cout<<"\nSET 1 Elements: ";
	       m1.display();
	       cout<<"\nSET 2 Elements: ";
	       m2.display();
		   break;
	case 3:m1.search();
		   break;
	case 4:m1.remove();	
	       break;
	case 5:m1.Union_set(m2);
           break;
	case 6:m1.Intersection_set(m2);	
           break;
	case 7:result=m1.isSubset(m2);	
		   if(result)
		   {
		   	cout<<"\nSET 2 is subset of SET 1";
		   }
		   else
		   {
		   	cout<<"\nSET 2 is not a subset of SET 1";
		   }
           break;
	default:cout<<"\nWrong choice entered!";
	}
}while(ch!=8);
return 0;
}

