#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
typedef pair<string, vector<ll>> LM;
 
bool cek(LM lm, int l) {
  return (1LL * 10080 * (lm.second)[1] * (lm.second)[2] >= 1LL * l * ((lm.second)[2] + (lm.second)[3]));
}
 
LM parse(string s) {
  LM ret;
   int cur = 0;
   string temp = "";
   while(s[cur] != ',') {
     temp += s[cur];
     cur++;
   }
   ret.first = temp;
   temp = "";
   cur++;
   vector<ll> ve;
   for(int i = cur; i < (int)s.length(); i++) {
     if(s[i] == ',') {
       ve.push_back((ll) stoi(temp));
       temp = "";
     } else {
       temp += s[i];
     }
   }
   ve.push_back(stoi(temp));
   ret.second = ve;
  return ret;
}
 
void solve() {
  int l, m;
  cin >> l >> m;
  vector<pair<int, pair<int, string>>> ok;
  string S;
  cin.ignore();
  for(int i = 0; i < m; i++) {
    getline(cin, S);
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
  for(int i = 1; i <= TC; i++) {
    solve();
  }
 
  return 0;
}