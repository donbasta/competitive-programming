#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main() {
  int n;
  cin >> n;
  vector<ll> ar(n + 1);
  ll curSum = 0, mn = 1e18, sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
  }
  for(int i = 0; i < n / 2; i++) {
    int pos = (i * 2) % n;
    curSum += ar[pos]; 
  }
  mn = curSum;
  // cerr << curSum << " :D\n";
  for(int i = n / 2; i < n + (n / 2); i++) {
    int delPos = i - (n / 2);
    int idxDel = (2 * delPos) % n;
    int idxAdd = (2 * i) % n; 
    curSum -= ar[idxDel];
    curSum += ar[idxAdd];
    // cerr << curSum << '\n';
    mn = min(mn, curSum);
  }
  cout << sum - mn << '\n';
  return 0;
}