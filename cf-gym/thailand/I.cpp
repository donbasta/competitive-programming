#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

bool pr[N + 5];

void sieve() {
  for(int i = 1; i <= N; i++) { pr[i] = 1; }
  pr[1] = 0;
  for(int i = 2; i <= N; i++) {
    if(!pr[i]) continue;
    for(int j = i + i; j <= N; j += i) {
      pr[j] = 0;
    }
  }
}

void solve() {

  sieve();

  string s;
  while(cin >> s) {
    if(s == "0") break;
    int len = (int)s.length();
    int mx = -1;
    for(int i = 5; i >= 1; i--) {
      int temp_mx = -1;
      for(int t = 0; t + i <= len; t++) {
        string temp = s.substr(t, i);
        int temp_int = stoi(temp);
        if(pr[temp_int]) {
          temp_mx = max(temp_mx, temp_int);
        }
      }
      mx = max(mx, temp_mx);
    }
    cout << mx << '\n';
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