#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int ar[N + 5];
bool ada[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    ada[ar[i]] = 1;
    while(ada[cur]) {
      cur++;
    }
    cout << cur << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}