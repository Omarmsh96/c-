
/**
Aufgabe Nr./Task No.: H4
Nachname/Last,Family Name:Hassan
Vorname/First,Given Name: Omar
Matrikelnummer/Matriculation number: 3071001
Uni-Email: hassan.omar@stud.uni-due.de
Studiengang/Course of Studies: ISE software engineering
*************************************************/


#include <iostream>
#include <string>
using namespace std;

class Time
{
private :
    int minuteofDay ;
public :

Time(unsigned int minute =0 ){
    minuteofDay=minute%1440;
   }
Time(int hour=23 , int minute=59 ){

   minuteofDay=hour*60 +minute ;
   }
void set_Time(int Hour,int Minute)
  {
  if(Hour>=24||Minute>=60){
    cout<< "Error Hour must less than 24"
        <<"Error Minute must less than 60 \n"<<endl;
    minuteofDay=0 ;
    }

    minuteofDay=Hour*60+Minute ;

  }
int get_hour(){
return minuteofDay/60;
}
int get_minute(){
return minuteofDay%60 ;
}

int get_minuteofDay(){
return minuteofDay ;
}

Time operator+(unsigned int c)
{
    return minuteofDay=((minuteofDay + c)%1440);

}
};
istream& operator>>(istream& in, Time& t){
int h,m;

in>>h>>m;
t.set_Time(h,m) ;

return in ;
}
 ostream& operator<<(ostream & out , Time& t){

return out <<"hh"<<t.get_hour() <<":"<<"mm "<<t.get_minute() <<endl;

}

class Train {
private:
string no ,to ,over  ;
public :

    Train(string n ,string t,string v);
    ~Train();
    string get_no();
    string get_to();
    string get_over();
};
Train::Train(string n, string t, string v)
{
    no=n ;
    to =t ;
    over=v;
}
Train::~Train(){

cout<<no <<" "<<over <<to <<endl;
}
string Train::get_no()
{
    return no ;
}
string Train::get_to()
{
    return to ;
}
string Train::get_over()
{
    return over ;
}

class Station {
private:
    const string station ;
    static const unsigned int platforms =15;
    Train* schedule [24*60][platforms];

public:

Station(string name):station(name)
{
  for(int i; i<(24*60) ; ++i){
    for(int j; j<platforms; ++j){
      schedule[i][j]=nullptr;
        }
      }
}

~Station(){

        for(int i=0 ; i<(24*60);i++){
         for(int n =15 ; n<platforms; n++){
            Time ti(i) ;
            cout << ti <<" "<<"platform "<<n <<endl ;
            delete[] schedule[i][n] ;
            }
		cout<< " Main Train station deleted" <<station<<endl;
        }
}
void addDeparture(Time ti,unsigned int pl ,Train* t)
{
    schedule[ti.get_minuteofDay()][pl]= t ;
}
Time showDepartures(Time time ,unsigned int next )
{
    Time t=time+next ;
    cout<<"Main Train station " <<station <<endl;
    cout<<"DEPARTURE"<<time <<" - " <<next<<endl;

    for(int i=time.get_minuteofDay(); i<t.get_minuteofDay() ; i++)
    {
        for(int a=0 ; a<platforms ; a++)
       cout<<"Time " <<schedule[i][a]<<"   "<<"Train"<<schedule[i][a]->get_no()
           << " over " <<schedule[i][a]->get_over()  <<" to " <<schedule[i][a]->get_to() <<" platform "<<schedule[i][a]<<endl;
    }
}
};
int main()
{
    Station Duisburg ("DUISBURG");
    string name,to,over ;
    Train *train;
    Time time=0  ;
    int p ;
    unsigned int minute ;
    int choice ;

    for( int k=7 ; k<1440 ;k+=20)
    {
      train=new Train("s1", "Dortmound HBF", "Mülheim(Ruhr)styrum - Mülheim(Ruhr) - Essen ");

          Duisburg.addDeparture(Time(k),9,train) ;
    }
    for(int k =15 ; k<1440; k+=20)
    {
     train=new Train("s1","Solingen HBf","Duisburg-schlenk - Düsseldorf Flughafen" );

           Duisburg.addDeparture(Time(k),5,train) ;
    }
    for(int k=35; k<1440; k+=60)
    {
       train=new Train("s2","Dortmund HBF", "oberhausen - Gelsenkirchen-Wanne-Eikel");

         Duisburg.addDeparture(Time(k),2,train);
    }
    for(int k=22; k<1440; k+=60)
    {
        train=new Train("RE1","Aachen HBF ","Düsseldorf Flughafen -Düsseldorf - Köln");

          Duisburg.addDeparture(Time(k),4,train);
    }
     for(int k=24;k<1440;k+=60)
    {
        train=new Train("RE2","Münster HBF","Mühlheim(Ruhr - Essen - Gelsenkirchen ");

          Duisburg.addDeparture(Time(k),10,train);
    }

    while(1){
      cout<< "0 end \n " << " 1 schedule train \n" << "show schedule " <<endl;
          cin>>choice ;
        switch(choice)
        {
          case 0:

              return 0;
          case 1:
                   train=new Train(name,to ,over) ;
                   Duisburg.addDeparture(time,p,train);

                   cout<<"time of departure? "<<endl;
                   cin>>time;
                   cout<<"platform?\n";
                   cin>>p;
                   cout<<"train?\n"<<endl;
                   cin>>name ;
                   cout<<"to?\n ";
                   cin>>to ;
                   cout<<"over?\n" <<endl;
                   cin>>over ;


              break ;
          case 2:
                  Duisburg.showDepartures(time, minute);
                  cout<<"show Departure starting at? "<<endl;
                  cin>>time ;
                  cout<< "for how many next minutes?\n " <<endl;
                  cin>>minute ;


            break;
          default:
            cout<<"Error"<<endl;
            break;
        }
    }

    return 0;
}
