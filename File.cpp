#include<iostream> 
#include<fstream> 
#include<string.h> 
using namespace std; 

struct stud 
{ 
    int roll; 
    char name[10]; 
    char div; 
    char add[10]; 
}rec; 


class student 
{ 
    public:      
    void create(); 
    void display(); 
    void search(); 
}; 

void student::create() 
 { 
    char ans; 
    ofstream fout; 
    fout.open("stud.dat",ios::out); 
    do 
    { 
        cout<<"\n\tEnter Roll No of Student : "; 
        cin>>rec.roll; 
        cout<<"\n\tEnter a Name of Student : "; 
        cin>>rec.name; 
        cout<<"\n\tEnter a Division of Student : "; 
        cin>>rec.div; 
        cout<<"\n\tEnter a Address of Student : "; 
        cin>>rec.add; 
        fout.write((char *)&rec,sizeof(stud))<<flush; 
        cout<<"\n\tDo You Want to Add More Records: "; 
        cin>>ans; 
    }while(ans=='y'||ans=='Y'); 
    fout.close(); 
} 

void student::display() 
{ 
    ifstream fin;
    fin.open("stud.dat",ios::in); 
    fin.seekg(0,ios::beg); 
    cout<<"\n\tThe Content of File are:\n"; 
    cout<<"\n\tRoll\tName\tDiv\tAddress"; 
    while(fin.read((char *)&rec,sizeof(stud))) 
    { 
        if(rec.roll!=-1) 
        cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;  
        
    } 
        fin.close(); 
} 

void student::search() 
{ 
    int r;
    ifstream fin; 
    fin.open("stud.dat",ios::in|ios::binary); 
    fin.seekg(0,ios::beg); 
    cout<<"\n\tEnter a Roll No: "; 
    cin>>r; 
    
    while(fin.read((char *)&rec,sizeof(stud))) 
    { 
        if(rec.roll==r) 
        { 
            cout<<"\n\tRecord Found...\n"; 
            cout<<"\n\tRoll\tName\tDiv\tAddress"; 
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add; 
        }  
    } 
    fin.close();  
} 

 
int main() 
{ 
       student obj; 
       int ch,key; 
       char ans; 
       do 
       { 
              cout<<"\n\t***** Student Information *****"; 
              cout<<"\n\t1. Create\n\t2. Display\n\t3. Search\n\t4. Exit"; 
              cout<<"\n\t..... Enter Your Choice: "; 
              cin>>ch; 
              switch(ch) 
              { 
              case 1: obj.create(); 
              break; 
              case 2: obj.display(); 
              break; 
              case 3: obj.search(); 
              break; 
			  default: cout<<"Enter valid choice";
              } 
       }while(ch!=4); 
 
return 1; 
 } 


