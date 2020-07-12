#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int n, idx = -1;
    cin >> n;
    vector<int> ar(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for(int i = 2; i < n; i++) {
      if(ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
        idx = i;
        break;
      }
    }
    if(idx == -1) {
      cout << "NO";
    } else {
      cout << "YES" << '\n';
      cout << idx - 1 << ' ' << idx << ' ' << idx + 1;
    }
    cout << '\n';
  }
  
  return 0;
}