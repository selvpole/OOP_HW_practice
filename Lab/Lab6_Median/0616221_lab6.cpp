#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::cin;
using std::cout;
using std::endl;

int main(){
  vector<int> v;
  int num;
  while(cin >> num){
    v.push_back(num);
    sort(v.begin(), v.end());
    if(v.size()&1)
      cout << v[(int)v.size()/2] << endl;
    else{
      int a = v[(int)v.size()/2-1];
      int b = v[(int)v.size()/2];
      cout << (a+b)/2 << endl;
    }
  }
}
