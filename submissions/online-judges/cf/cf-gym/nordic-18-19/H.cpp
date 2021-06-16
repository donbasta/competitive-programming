#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

typedef pair<string, vector<ll>> LM;

bool cek(LM lm, int l) {
  return (1LL * 10080 * (lm.second)[1] * (lm.second)[2] >= 1LL * l * ((lm.second)[2] + (lm.second)[3]));
}

LM parse(string s) {
  cerr << s << '\n';
  LM ret;
  // int cur = 0;
  // string temp = "";
  // while(s[cur] != ',') {
  //   // cerr << s[cur] << '\n';
  //   // cerr << cur << '\n';
  //   temp += s[cur];
  //   cur++;
  // }
  // ret.first = temp;
  // temp = "";
  // cur++;
  // cerr << cur << ":D\n";
  // vector<ll> ve;
  // for(int i = cur; i < (int)s.length(); i++) {
  //   if(s[i] == ',') {
  //     cerr << temp << '\n';
  //     // cerr << (ll) stoi(temp) << '\n';
  //     ve.push_back((ll) stoi(temp));
  //     temp = "";
  //   } else {
  //     temp += s[i];
  //   }
  // }
  // ve.push_back(stoi(temp));
  // ret.second = ve;
  // for(auto i : ve) {cerr << i << ' ';}
  return ret;
}

void solve() {
  int l, m;
  cin >> l >> m;
  vector<pair<int, pair<int, string>>> ok;
  string S;
  for(int i = 0; i < m; i++) {
    // cerr << "lol\n";
    getline(cin, S);
    // cerr << S;
    LM now = parse(S);
    if(cek(now, l)) {
      ok.emplace_back((now.second)[0], make_pair(i, now.first));
    }
  }
  if(ok.empty()) {
    cout << "no such mower" << '\n';
    return;
  }
  sort(ok.begin(), ok.end());
  int mn = ok[0].first;
  for(int i = 0; i < (int)ok.size(); i++) {
    if(ok[i].first == mn) {
      cout << ok[i].second.second << '\n';
      continue;
    }
    break;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}