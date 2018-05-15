#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Date
{
  public:
    Date(int , int , int );
    ~Date();

    void testRun();

    /*Get function for accessing private member*/
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}

    /*Set function for updating private member*/
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    /*A Function that returns the date after a given date
        For e.g-

        today is 8/3/2018 (Day/Month/Year)
        DateAfter(3) should return a date of 11/3/2018 */
    Date DateAfter(int); // day

    /*A Function that returns the date after a given date
        For e.g-

        today is 8/3/2018 (Day/Month/Year)
        DateBefore(3) should return a date of 5/3/2018 */
    Date DateBefore(int); // day

    int weekDay();
    /*A Function that returns the day of a date
        For e.g-

        if the date is 8/3/2018, then the day() function
        should return "Thursday"
    */
    string dayOfWeek();

    /* A Function to return the number of days in
        Current Month.

        Month Number     Name        Number of Days
        0                January     31
        1                February    28 (non-leap) / 29 (leap)
        2                March       31
        3                April       30
        4                May         31
        5                June        30
        6                July        31
        7                August      31
        8                September   30
        9                October     31
        10               November    30
        11               December    31*/
    int daysOfMonth(int m);

    /* Function to print a calendar of the current month.
    Just like what you see on a calendar. An example is like

   --------------March--------------
   Sun  Mon  Tue  Wed  Thu  Fri  Sat
                        1    2    3
    4    5    6    7    8    9   10
   11   12   13   14   15   16   17
   18   19   20   21   22   23   24
   25   26   27   28   29   30   31

   */
    void printMonthCalendar();

  private:
    /*Current Date*/
    int day;
    int month;
    int year;
};

///////////////////////////////////////////
///////////////////////////////////////////

Date::Date(int d, int m, int y): month(0),day(0),year(0){
  setMonth(m);
  setDay(d);
  setYear(y);
  if(day*month*year==0)
    cout << "Invalid Date\n";
}

Date::~Date(){}

void Date::testRun(){
  cout << year << "/" << month << "/" << day;
}

void Date::setDay(int d){day = (d>0 && d<=daysOfMonth(month)) ? d : 0;}
void Date::setMonth(int m){month = (m>0 && m<=12) ? m : 0;}
void Date::setYear(int y){year = (y>0) ? y : 0;}

Date Date::DateAfter(int d){
  int tmpD=day+d, tmpM=month, tmpY=year;

  while(tmpD > daysOfMonth(tmpM)){
    tmpD -= daysOfMonth(tmpM);
    tmpM++;

    if(tmpM > 12){
      tmpY += tmpM/12;
      tmpM %= 12;
    }
  }
  return Date(tmpD, tmpM, tmpY);
}

Date Date::DateBefore(int d){
  int tmpD=day-d, tmpM=month, tmpY=year;

  while(tmpD <= 0){
    tmpM--;
    tmpD += daysOfMonth(tmpM);

    while(tmpM <= 0){
      tmpY--;
      tmpM+=12;
    }
  }

  return Date(tmpD, tmpM, tmpY);
}

int Date::daysOfMonth(int m){
  int monthDay[13] = {0, 31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31};

  if(year%400==0 || (year%100!=0 && year%4==0)) // check leap year
    monthDay[2] = 29;

  return monthDay[m];
}

// calculate the day of week
int Date::weekDay(){
  int wd = (year-1) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400);
  for(int i=1; i<month ;i++){
    wd += daysOfMonth(i);
  }
  wd += day;
  wd %= 7;

  return wd;
}

// change weekday to string
string Date::dayOfWeek(){
  string dayName[] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday",
  "Friday", "Saturday"};

  return dayName[weekDay()];
}


void Date::printMonthCalendar(){
  string Months[12] = {"January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December" };

  int halfLen=(Months[month-1].size()/2);
  for(int i=0;i<16-halfLen;i++)
    cout << "-";
  cout << setfill('-') << setw(17+halfLen) << left << Months[month-1] << endl;
  cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

  // print the space before the first day of month
  int j=(weekDay()-(day%7)+8)%7;
  for(int i=0;i<j;i++){
    cout << "     ";
  }
  for(int i=1; i<=daysOfMonth(month); i++){
    cout << setfill(' ') << setw(3) << right << i;
    if(j==6){
      cout << endl;
      j=0;
    }
    else{
      cout << "  ";
      j++;
    }
  }
  cout << endl;
}
