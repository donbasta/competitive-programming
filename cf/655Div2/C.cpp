#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n, same = 0, no_same = 0;
    cin >> n;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
      if(ar[i] == i)
        same++;
      else
        no_same++;
    }
    int ujung = 0;
    for(int i = 1; i <= n; i++) {
      if(ar[i] == i)
        ujung++;
      else
        break;
    }
    for(int i = n; i >= 1; i--) {
      if(ar[i] == i)
        ujung++;
      else
        break;
    }
    bool ok = (ujung == same);
    if(same == n) {
      cout << 0;
    } else if((same == 0) || ok) {
      cout << 1;
    } else {
      cout << 2;
    }
    cout << '\n';
  }
  
  return 0;
}