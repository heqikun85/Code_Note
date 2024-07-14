
#include <iostream>
using namespace std;

class DayOfYear {
   public:
      void output();
      int month;
      int day;
}; // 这个分号必不可少， 是类定义的一部分

int main() {
   DayOfYear today, birthday;//使用类声明了两个对象
   cout << "Enter today's date: \n";
   cout << "Enter month as a number: ";
   cin >> today.month; //之所以可以使用dot operator直接存取成员变量是因为该变量是public
   cout << "Enter the day of the month: ";
   cin >> today.day;
   cout << "Enter your birthday:\n";
   cout << "Enter month as a number: ";
   cin >> birthday.month;
   cout << "Enter the day of the month: ";
   cin >> birthday.day;

   cout << "Today's date is ";
   today.output();
   cout << endl;
   cout << "your birthday is ";
   birthday.output();
   cout << endl;

   if (today.month == birthday.month && today.day == birthday.day)
      cout << "Happy Birthday! \n";
   else
      cout << "Happy Unbirthday! \n";
   return 0;
}

void DayOfYear::output() {
   switch (month) { //根据month， month是成员变量，成员函数可以直接存取（access）
      case 1:
         cout << "January "; break;
      case 2:
         cout << "February "; break;
      case 3:
         cout << "March "; break;
      case 4:
         cout << "April "; break;
      case 5:
         cout << "May "; break;
      case 6:
         cout <<  "June "; break;
      case 7:
         cout << "July "; break;
      case 8:
         cout << "August "; break;
      case 9:
         cout << "September "; break;
      case 10:
         cout << "October "; break;
      case 11:
         cout << "November "; break;
      case 12:
         cout << "December "; break;
      default:
         cout << "Error!";
   }

   cout << day; // 成员变量， 可以直接存取
}
