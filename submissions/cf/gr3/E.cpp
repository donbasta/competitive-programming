#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n;
set<pair<int, int>> curpos;
multiset<int> target;
vector<pair<pair<int, int>, int>> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;

  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    curpos.emplace(s, i);
  }
  for(int i = 1; i <= n; i++) {
    int s;
    cin >> s;
    target.insert(s);
  }

  while((int)curpos.size() > 1) {
    pair<int, int> aw = *curpos.begin();
    pair<int, int> ak = *curpos.rbegin();
    int taw = *target.begin();
    int tak = *target.rbegin();
    // if(aw.first > taw || ak.first < tak) {
    //   cout << "NO" << '\n';
    //   return 0;
    // }
    int d1 = taw - aw.first;
    int d2 = ak.first - tak;
    if(d1 < 0 || d2 < 0) {
      cout << "NO" << '\n';
      break;
    }
    if(d1 > d2) {
      ans.emplace_back(make_pair(aw.second, ak.second), d2);
      curpos.erase(aw);
      curpos.erase(ak);
      curpos.emplace(aw.first + d2, aw.second);
      target.erase(target.find(tak));
    } else if(d1 < d2) {
      ans.emplace_back(make_pair(aw.second, ak.second), d1);
      curpos.erase(aw);
      curpos.erase(ak);
      curpos.emplace(ak.first - d1, ak.second);
      target.erase(target.find(taw));
    } else if(d1 == d2) {
      ans.emplace_back(make_pair(aw.second, ak.second), d1);
      curpos.erase(aw);
      curpos.erase(ak);
      target.erase(target.find(taw));
      target.erase(target.find(tak));
    }
  }
  if((int)curpos.size() == 1) {
    if((*curpos.begin()).first != *target.begin()) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  cout << (int) ans.size() << '\n';
  for(auto i : ans) {
    cout << i.first.first << ' ' << i.first.second << ' ' << i.second;
    cout << '\n';
  }
  return 0;
}
