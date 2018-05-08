#include <bits/stdc++.h>
using namespace std;

long long Max(vector<long long> num, vector<char> chr){
  vector<long long> newVec;
  newVec.push_back(num[0]);
  for(int i=0; i<chr.size(); i++){
    if(chr[i] == '+'){
      int tmp=newVec.back();
      newVec.pop_back();
      newVec.push_back(tmp+num[i+1]);
    }
    if(chr[i] == '*')
      newVec.push_back(num[i+1]);
  }
  // for(auto &i : newVec){
  //     cout << i << " ";
  // }
  // cout << endl;
  if(chr.size()==0)
    return num.back();
  long long total=1;
  for(int i=0; i<newVec.size(); i++){
    total *= newVec[i];
  }
  return total;
}

long long Min(vector<long long> num, vector<char> chr){
  vector<long long> newVec;
  newVec.push_back(num[0]);
  for(int i=0; i<chr.size(); i++){
    if(chr[i] == '*'){
      long long tmp=newVec.back();
      newVec.pop_back();
      newVec.push_back(tmp*num[i+1]);
    }
    if(chr[i] == '+')
      newVec.push_back(num[i+1]);
  }
  // for(auto &i : newVec){
  //     cout << i << " ";
  // }
  // cout << endl;
  if(chr.size()==0)
    return num.back();
  long long total=0;
  for(int i=0; i<newVec.size(); i++){
    total += newVec[i];
  }
  return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
      string str;
      cin >> str;
      vector<long long> num;
      vector<char> chr;
      long long tmp=0;
      for(int i=0; i<str.length(); i++){
        if(str[i] == '*' || str[i] == '+'){
          if(str[i] == '*')
            chr.push_back('*');
          else
            chr.push_back('+');
          num.push_back(tmp);
          tmp = 0;
        }
        else if(str[i] >= 48 && str[i] <= 57){
          if(tmp > 0)
            tmp *= 10;
          tmp += str[i] - 48;
        }
      }
      num.push_back(tmp);

      // // Max + > *
      // cout << "Max:\n";
      // Max(num, chr);

      // // Min * > +
      // cout << "Min:\n";
      // Min(num, chr);

      cout << "The maximum and minimum are " << Max(num, chr) <<  " and "
        << Min(num, chr) << endl;

    }
}
