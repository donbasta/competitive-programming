#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool lol1(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.first > b.first.first;
}

bool lol2(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.first < b.first.first;
}

int n;
vector<pair<pair<int, int>, int>> ve1, ve2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if(a > b) {
      ve1.emplace_back(make_pair(a, b), i);
    } else if(a < b) {
      ve2.emplace_back(make_pair(a, b), i);
    }
  }

  sort(ve1.begin(), ve1.end(), lol2);
  sort(ve2.begin(), ve2.end(), lol1);
  int sz1 = (int) ve1.size(), sz2 = (int) ve2.size();
  if(sz1 >= sz2) {
    cout << sz1 << '\n';
    for(auto i : ve1) {
      cout << i.second << ' ';
    }
  } else {
    cout << sz2 << '\n';
    for(auto i : ve2) {
      cout << i.second << ' ';
    }
  }
  cout << '\n';
  return 0;
}
