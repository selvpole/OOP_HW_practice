#include <iostream>
#include <stdio.h>
#include "0616221_Date.h"

// Driver Program to check your implementation
int main()
{
    Date date1(3, 8, 2018);
    Date date2 = date1.DateAfter(13);
    Date date3 = date1.DateBefore(25);

    date1.setDay(25);
    date2.setMonth(12);
    date3.setYear(2015);

    cout << date1.daysOfMonth(date1.getMonth()) << endl;
    // 31
    cout << date2.dayOfWeek() << endl;
    // Sunday
    date3.printMonthCalendar();
    /*
    --------------July---------------
    Sun  Mon  Tue  Wed  Thu  Fri  Sat
                     1    2    3    4
      5    6    7    8    9   10   11
     12   13   14   15   16   17   18
     19   20   21   22   23   24   25
     26   27   28   29   30   31
     */
     Date date5(3, 2, 2018);
     Date date6 = date5.DateAfter(200);
     Date date7 = date5.DateBefore(200);

     cout << date5.daysOfMonth(date5.getMonth()) << endl;
     cout << date6.dayOfWeek() << endl;
     date7.printMonthCalendar();

    return 0;
}
