#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
  int t;
  char s[100];
  cin >> t;
  while(t--){
    cin >> s;
    long long max[100], min[100], tmp=0;
    int idx1 = 0, idx2 = 0;
    char op = '+';
    for(int i=0; i<strlen(s); i++){
      if(s[i] >= '0' && s[i] <= '9'){
        tmp = tmp*10 + s[i] - '0';
      }
      else{
        if(op == '+'){
          if(idx1 == 0)
            max[idx1++] = tmp;
          else
            max[idx1-1] += tmp;
          min[idx2++] = tmp;
        }
        else {
          if(idx2 == 0)
            min[idx2++] = tmp;
          else
            min[idx2-1] *= tmp;
          max[idx1++] = tmp;
        }
        op = s[i], tmp = 0;
      }
    }
    long long amax = 1, amin = 0;
    for(int i=0; i<idx1; i++){
      amax *= max[i];
    }
    for(int i=0; i<idx2; i++){
      amin += min[i];
    }
    cout << "The maximum and minimum are " << amax <<  " and "
      << amin << "." << endl;
  }
}
