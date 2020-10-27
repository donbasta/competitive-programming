#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 50;
int n;
int ar[N + 5];

void solve() {
  cin >> n;
  int sum = 0, zero = 0;
  vector<int> pos, neg;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    sum += ar[i];
    if(ar[i] > 0) pos.push_back(ar[i]);
    if(ar[i] < 0) neg.push_back(ar[i]);
    if(ar[i] == 0) zero++;
  }
  if(sum == 0) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  if(sum > 0) {
    for(auto i : pos) {
      cout << i << ' ';
    }
    for(auto i : neg) {
      cout << i << ' ';
    }
    for(int i = 0; i < zero; i++) {
      cout << 0 << ' ';
    }
  } else {
    for(auto i : neg) {
      cout << i << ' ';
    }
    for(auto i : pos) {
      cout << i << ' ';
    }
    for(int i = 0; i < zero; i++) {
      cout << 0 << ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}