#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 13;

map<char, int> mp;
string cards = "23456789XJQKA";

struct Pos {
  int idx, cnt;
  Pos(int idx) : idx(idx) { cnt = 0; }
  void add() { cnt++; }
};

bool comp (Pos a, Pos b) {
  if (a.cnt == b.cnt) {
    return a.idx < b.idx;
  }
  return a.cnt > b.cnt;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string deal, act;
  cin >> deal >> act;

  vector<int> cnt(M);
  vector<bool> udah(M), must(M), nope(M);

  vector<Pos> ve;
  for(int i = 0; i < M; i++) {
    ve.push_back(Pos(i));
  }

  for (int i = 0; i < n; i++) {
    if (act[i] == 'y') {
      //i udah pernah keluar atau punya kartunya
      if (!udah[mp[deal[i]]]) {
        must[mp[deal[i]]] = 1;
      }
    }  else if (act[i] == 'n') {
      //belum pernah keluar dan tidak punya kartunya
      nope[mp[deal[i]]] = 1;
      if (udah[mp[deal[i]]] || must[mp[deal[i]]]) {
        cout << "impossible" << '\n';
        return;
      }
    }
    udah[mp[deal[i]]] = 1;
    cnt[mp[deal[i]]]++;
    ve[mp[deal[i]]].add();
  }

  for (int i = 0; i < M; i++) {
    if (must[i] && nope[i]) {
      cout << "impossible" << '\n';
      return;
    }
  }

  int temp = 0;
  for (int i = 0; i < M; i++) {
    temp += must[i];
  }
  if (temp > k) {
    cout << "impossible" << '\n';
    return;
  }

  // for(auto i : ve) {
  //   cerr << i.idx << ' ' << i.pos.size() << '\n';
  // }

  sort(ve.begin(), ve.end(), comp);

  // for(auto i : ve) {
  //   cerr << i.idx << ' ' << i.pos.size() << '\n';
  // }

  int slot = k;
  vector<char> hand;
  for (int i = 0; i < M; i++) {
    if (must[i]) {
      slot--;
      cnt[i]++;
      hand.push_back(i);
    }
  }

  // cerr << "slot: " << slot << '\n';

  for (int i = 0; i < M; i++) {
    if (nope[ve[i].idx]) continue;
    int sisa = 4 - cnt[ve[i].idx];
    // cerr << "sisa: " << sisa << '\n';
    // cerr << "tes";
    while((slot > 0) && (sisa > 0)) {
      hand.push_back(ve[i].idx);
      slot--;
      sisa--;
      // cerr << slot << ' ' << sisa << '\n';
    }
    if (slot == 0)
      break;
  }

  if (slot > 0) {
    cout << "impossible" << '\n';
    return;
  }

  assert ((int)hand.size() == k);
  sort(hand.begin(), hand.end());

  string ans = "";
  for(auto& e : hand) {
    ans += cards[e];
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int j = 0;
  for(auto& c : cards) {
    mp[c] = j++;
  }

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}