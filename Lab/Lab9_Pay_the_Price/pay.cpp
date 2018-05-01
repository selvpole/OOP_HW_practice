#include <iostream>
#include <string.h>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

const int maxPrice = 300;
long long ways[maxPrice+1][maxPrice+1];

int main(){
  // make the table
  for(int i=0; i<=maxPrice; i++)
    ways[i][0] = 0;
  for(int j=0; j<=maxPrice; j++)
    ways[0][j] = 1;
  for(int j=1; j<=maxPrice; j++)
    for(int i=j; i<=maxPrice; i++){
      if(i-j < j)
        ways[i][j] = ways[i-j][i-j] + ways[i][j-1];
      else
        ways[i][j] = ways[i-j][j] + ways[i][j-1];
    }

  // start
  string s;
  while(getline(cin, s)){
    istringstream ss(s);
    int n, l1 = -1, l2 = -1;
    ss >> n;
    ss >> l1;
    ss >> l2;
    if(l2 >= 0)
      cout << ways[n][l2] - ways[n][l1-1] << endl;
    else if(l1 >= 0)
      cout << ways[n][l1] << endl;
    else
      cout << ways[n][n] << endl;
  }
}
