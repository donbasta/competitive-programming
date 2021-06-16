#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b, c;
vector<vector<int>> ans;
vector<pair<int, int>> veve;
vector<int> ve;

bool eq(int p, int q, int r) {
  return (ve[0] == p && ve[1] == q && ve[2] == r);
}

void transform() {
  if(eq(0, 1, 2)) {
    for(auto& i : ans) {
      i = {i[0], i[1], i[2]};
    }
  } else if(eq(0, 2, 1)) {
    for(auto& i : ans) {
      i = {i[1], i[0], i[2]};
    }
  } else if(eq(1, 0, 2)) {
    for(auto& i : ans) {
      i = {i[0], i[2], i[1]};
    }
  } else if(eq(1, 2, 0)) {
    for(auto& i : ans) {
      i = {i[1], i[2], i[0]};
    }
  } else if(eq(2, 0, 1)) {
    for(auto& i : ans) {
      i = {i[2], i[0], i[1]};
    }
  } else if(eq(2, 1, 0)) {
    for(auto& i : ans) {
      i = {i[2], i[1], i[0]};
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    veve.emplace_back(x, i);
  }
  sort(veve.begin(), veve.end());
  for(int i = 0; i < 3; i++) {
    ve.push_back(veve[i].second);
  }
  int a = veve[0].first, b = veve[1].first, c = veve[2].first;
  if(a * b < c) {
    cout << -1 << '\n';
    return 0;
  }
  for(int i = 0; i < a; i++) {
    ans.push_back({0, i, i});
  }
  for(int i = 0; i < b - a; i++) {
    ans.push_back({0, a - 1, a + i});
  }
  int sisa = c - b;
  bool ok = false;
  for(int i = 0; i < a; i++) {
    for(int j = 0; j < b; j++) {
      if(i == j)
        continue;
      if(sisa > 0) {
        ans.push_back({0, i, j});
        sisa--;
      }
      if(sisa == 0) {
        ok = true; break;
      }
    }
    if(ok) { break; }
  }

  transform();
  cout << (int)ans.size() << '\n';
  for(auto i : ans) {
    for(auto j : i) {
      cout << j << ' ';
    }
    cout << '\n';
  }
  return 0;
}