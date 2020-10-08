#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

inline void solve() {
  cin >> n;
  if(n % 2 == 0) {
    cout << "First" << endl;
    for(int i = 0; i < 2; i++) {
      for(int j = 1; j <= n; j++) {
        cout << j << ' ';
      }
    }
    cout << endl;
  } else {
    cout << "Second" << endl;
    
  }
}

int main() {

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}