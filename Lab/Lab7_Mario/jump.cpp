#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    int n;
    int up=0, down=0;
    cin >> n;
    int arr[n];
    for(int j=0; j<n; j++)
      cin >> arr[j];
    for(int j=0; j<n-1; j++){
      if(arr[j] < arr[j+1])
        up++;
      else if(arr[j] > arr[j+1])
        down++;
    }
    cout << "Case " << i << ": " << up << " " << down << endl;
  }
}
