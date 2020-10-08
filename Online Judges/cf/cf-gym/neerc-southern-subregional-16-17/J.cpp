#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

bool comp(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second) return a.first > b.first;
  return a.second > b.second;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> ve(n);
  int water = 0;
  for(int i = 0; i < n; i++) {
    cin >> ve[i].first;
    water += ve[i].first;
  }
  for(int i = 0; i < n; i++) {
    cin >> ve[i].second;
  }
  sort(ve.begin(), ve.end(), comp);
  int mnBot = 0, cur = 0, fix = 0;
  for(int i = 0; i < n; i++) {
    if(cur + ve[i].second > water) {
      fix = i; mnBot = i + 1;
      break;
    } else {
      cur += ve[i].second;
    }
  }
  int mnTime = 0;
  for(int i = 0; i <= fix; i++) {
    mnTime += (b[i] - a[i]);
  }
  int mn = INF;
  for(int i = fix + 1; i < n; i++) {
    if(cur + ve[i].second < water) break;
    if(a[i] > 0)
  }


  cout << mnBot << ' ' << mnTime << '\n';
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