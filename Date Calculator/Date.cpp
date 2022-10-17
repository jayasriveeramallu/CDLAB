#include "Date.hh"
#include<iostream>
using namespace std;

Date::Date(){}
Date::Date(short int d, short int m, short int y){
         day=d;
         month=m;
         year=y;
}

Date::Date(const Date &d){
        day=d.day;
        month=d.month;
        year=d.year;
}

Date Date::operator-(int num){

      Date d1;
                int t;
                d1.day=day-num;
                if(d1.day<1)
                {
                        t=abs(d1.day/30);
                        d1.day=30-abs(d1.day%30);
                        d1.month=month-t;
                        if(d1.month<1)
                        {
                                t=abs(d1.month/12) +1;
                                d1.month=12-abs(d1.month%12);

                                d1.year=year-t;

                        }
                        else
                                d1.year=year;
                }
                else
                {
                        d1.month=month;
                        d1.year=year;


                }

                return d1;
   
}

Date Date::operator+(int num){
        Date d1;
                   int t;
                   d1.day=day+num;
                   if(d1.day>30)
                   {
                            t=d1.day/30;
                           d1.day=d1.day%30;
                           d1.month=month+t;
                           if(d1.month>12)
                           {
                                 t=d1.month/12;
                                 d1.month=d1.month%12;
                                 d1.year=year+t;
                           }
                           else
                                   d1.year=year;
                   }

                   return d1;

 
}

int Date::operator-(Date d){
 Date d3;
                d3.year=year-d.year;
                d3.month=month-d.month;
                d3.day=day-d.day;
                cout<<abs(d3.day+d3.month*30+d3.year*360)<<endl;
               
        
}

bool Date::isItValid(){
        return true;
}

void Date::print(){
       cout<<day<<"/"<<month<<"/"<<year<<endl;
}
