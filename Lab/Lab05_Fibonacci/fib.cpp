#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void addNum(int a[], int b[]);

void print(int a[]);

void copy(int a[], int b[]);

int main(){
  int fib_num;
  while(cin >> fib_num){
    int n1[13000],n2[13000];
    memset(n1,0,sizeof(n1));
    memset(n2,0,sizeof(n2));
    n1[0] = 0;
    n2[0] = 1;
    if(fib_num == 0)
      cout << "The Fibonacci number for 0 is 0\n";
    else if(fib_num == 1)
      cout << "The Fibonacci number for 1 is 1\n";
    else{
      int t = fib_num-1;
      int tmp[13000];
      while(t--)
      {
        copy(tmp,n2); // tmp = n2
        addNum(n1,n2);  // n2 = n1 + n2
        copy(n1,tmp);  // n1 = tmp
      }
      cout << "The Fibonacci number for " << fib_num << " is ";
      print(n2);
      cout << endl;
    }
  }
}

void addNum(int a[], int b[]){
  int carry = 0;
  for(int i=0;i < 13000;i++){
    b[i] += a[i] + carry;
    if(b[i]<10)
      carry = 0;
    if(b[i]>=10){
      b[i] %= 10;
      carry=1;
    }
  }
}

void print(int a[]){
  bool start = false;
  for(int i=12999;i>=0;i--){
    if(a[i] != 0 && !start)
      start = true;
    if(start)
      cout << a[i];
  }
}

void copy(int a[], int b[]){
  for(int i=0;i<13000;i++){
    a[i] = b[i];
  }
}
