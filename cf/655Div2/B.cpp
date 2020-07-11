#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    if(n % 2 == 0) {
      cout << n / 2 << ' ' << n / 2;
    } else {
      int temp = n, idx = -1;
      for(int i = 2; i * i <= temp; i++) {
        if(temp % i == 0) {
          idx = i;
          break;
        }
      }
      if(idx == -1) {
        cout << 1 << ' ' << n - 1;
      } else {
        cout << n / idx << ' ' << n - n / idx;
      }
    }
    cout << '\n';
  }
  
  return 0;
}