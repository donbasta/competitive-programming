#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string ask(int x) {
  string ret;
  cout << x << endl;
  getline(cin, ret);
  return ret;
}

void solve() {
  int q;
  cin >> q;
  cin.ignore();
  int lo = 1, hi = 1000;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    string s = ask(mid);
    if(s == "LEBIH KECIL") {
      hi = mid - 1;
    } else if(s == "LEBIH BESAR") {
      lo = mid + 1;
    } else {
      assert(s == "BENAR");
      exit(0);
    }
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