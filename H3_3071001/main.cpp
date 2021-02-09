/*
Aufgabe Nr./Task No.: H3
Nachname/Last,Family Name:Hassan
Vorname/First,Given Name: Omar
Matrikelnummer/Matriculation number: 3071001
Uni-Email: hassan.omar@stud.uni-due.de
Studiengang/Course of Studies: ISE software engineering
*************************************************/
#include<iostream>
#include <fstream>>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

struct element {
 string   code ;
 string diagnosis ;
 element *next ;

}; element *head =nullptr ;


element *readlist(){
//ifstream ip("Section111ValidICD10-2018.csv" );
string file ="Section111ValidICD10-2018.csv" ;
ifstream ip;
string line ;
string z ;
ip.open(file);

if (!ip.is_open()) {cout<< "error file  " <<endl; }

getline(ip,z);

    while(!ip.eof()){

    if(head==0)
        {
        element *newelem = new element ;
        newelem->code = line;
        getline(ip,line);
        newelem->diagnosis = line ;
        getline(ip,line,';' );
        newelem->next=nullptr ;
        head=newelem ;
        }
         else {
            element *temp =head ;
             while(temp->next!=nullptr){
                temp=temp->next ;
             }
               element *newelem = new element ;
               newelem->code = line;
               getline(ip,line,';');
               newelem->diagnosis = line ;
               getline(ip,line,';');
               newelem->next=nullptr ;
               temp->next=newelem ;
               return head ;

             }
}
ip.close() ;
}

/*
void searchelem (element* newelem,string ICD,bool p){
 element *cr=head ;
 cr->code=ICD;
 cr->diagnosis=ICD;
 cr->next=nullptr;

    while(cr!=nullptr)
       {
        if(p==true){
        if(strcmp(cr->code,cr->next->code)==0){
            cout<<"ICD code :" <<endl;}
        }
        if(p==false){
        if(strcmp(cr->diagnosis,cr->next->diagnosis)==0)
        {
                ICD[0]=toupper(ICD[0]);
            cout<<"ICD diagnosis"<<endl;
        }
       }
       else {
        cout<<"element not found " << endl ;}
       }
}
*/
void searchelem (element* newelem,string ICD,bool p){
 int i =1 ;
 element *cr=head ;
 cr->code=ICD;
 cr->diagnosis=ICD;
 cr->next=nullptr;

    while(cr!=nullptr)
     {
        if(p==true){
        if(cr->code==ICD){
            cout<<"ICD code :" <<endl;}
            break;
            }

        if(p==false){
        if(cr->diagnosis==ICD){
         ICD[0]=toupper(ICD[0]);
           cout<<"ICD diagnosis"<< endl;
           break ;}
        else {
        i++;
        cr=cr->next;
         }

        }
     }
}

int main()
{
    int choice ;
    string s;

    cout<<"World Health Institution (WHO)\n "
        <<"International Classification of Diseases (ICD)" <<endl;

    while(1){
          cout << "0 end \n" << "1 search for ICD code(s)(e.g. G4453)\n "
               << "2 search for diagnosis(s)(e.g. agnia, Ebola,horse,Malaria,wheelchair) " <<endl;
          cin>>choice ;
          switch(choice){
          case 0:
            return 0 ;
          case 1:
               searchelem(head,s,true);
            break ;
          case 2:
               searchelem(head,s,false);
               cout<< "seraching for ICD diagnosis : " ;
               cin>>s ;
            break;
          default:
              break;
    }

    return 0;
}
}
