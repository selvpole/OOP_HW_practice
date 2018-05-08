#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    int die[3] = {1,2,3};
    if(n==0)
      break;
    while(n--){
      string s;
      int tmp = die[0];

      cin >> s;
      if(s == "north"){
        die[0] = 7-die[1];
        die[1] = tmp;
      }
      else if(s == "south"){
        die[0] = die[1];
        die[1] = 7-tmp;
      }
      else if(s == "east"){
        die[0] = die[2];
        die[2] = 7-tmp;
      }
      else if(s == "west"){
        die[0] = 7-die[2];
        die[2] = tmp;
      }
    }
    cout << die[0] << endl;
  }
}
