#include<iostream>
using namespace std;

int main(){
  int n,m;
  int t=1;
  while(cin >> n >> m){
    if(n==0 && m==0)
      break;
    // intialize the field_val
    else{
      char field[n][m];
      int field_val[n][m];
      if(t>1)
        cout <<endl;
      for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
          field_val[i][j] = 0;

      for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
          cin >> field[i][j];
          if(field[i][j] == '*'){
            field_val[i][j] = -100;
            if(i>0)
              field_val[i-1][j]++;
            if(i<n-1)
              field_val[i+1][j]++;
            if(j>0)
              field_val[i][j-1]++;
            if(j<m-1)
              field_val[i][j+1]++;
            if(i<n-1 && j>0)
              field_val[i+1][j-1]++;
            if(i<n-1 && j<m-1)
              field_val[i+1][j+1]++;
            if(i>0 && j>0)
              field_val[i-1][j-1]++;
            if(i>0 && j<m-1)
              field_val[i-1][j+1]++;
          }
        }

      //print answer
      cout << "Field #" << t << ":" <<endl;
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(field_val[i][j]<0)
            cout << "*";
          else
            cout << field_val[i][j];
          }
          cout << endl;
      }
      t++;
    }
  }
  return 0;
}
