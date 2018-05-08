#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i=1;i<=t;i++){
    int n;
    bool isSym = true;
    cin.ignore(5);
    cin >> n;
    // cout << "The matrix is " << n << "x" << n << " matrix.\n";
    long long int mtr[n][n];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        cin >> mtr[i][j];
        if(mtr[i][j]<0)
          isSym = false;
      }
    if(isSym){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(mtr[i][j]!=mtr[n-1-i][n-1-j]){
            isSym = false;
            break;
          }
        }
        if(!isSym)
          break;
      }
    }
    if(isSym)
      cout << "Test #" << i << ": Symmetric.\n";
    else
      cout << "Test #" << i << ": Non-symmetric.\n";
  }
}
