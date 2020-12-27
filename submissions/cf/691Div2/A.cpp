#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  // vector<int> r(10), b(10);
  string R, B;
  cin >> R >> B;
  int cek = 0;
  for (int i = 0; i < n; i++) {
    int x = (int) R[i] - '0';
    int y = (int) B[i] - '0';
    if (x > y) cek++;
    else if (x < y) cek--;
  }
  if (cek > 0) {
    cout << "RED";
  } else if (cek < 0) {
    cout << "BLUE";
  } else {
    cout << "EQUAL";
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