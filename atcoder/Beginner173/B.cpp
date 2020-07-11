#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const string ss[] = {"AC", "WA", "TLE", "RE"};
map<string, int> mp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }

  for(int i = 0; i < 4; i++) {
    int k = mp[ss[i]];
    cout << ss[i] << " x " << k << '\n'; 
  }

  return 0;
}
