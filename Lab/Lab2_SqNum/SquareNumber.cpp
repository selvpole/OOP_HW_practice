#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int num1,num2;
  int sqnum1,sqnum2;

  while(cin >> num1 >> num2){
    if(num1==0 && num2==0) break;

    sqnum1 = sqrt(num1);
    sqnum2 = sqrt(num2);

    if(num1 > pow(sqnum1,2))  sqnum1++;

    cout << sqnum2-sqnum1+1 <<endl;
  }
  return 0;
}
