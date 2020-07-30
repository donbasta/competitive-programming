#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
set<pair<pair<int, int>, int>> se;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) {
      se.emplace(make_pair(x, y), i);
    } else if(t == 2) {
      
    }
  }
  
  return 0;
}