#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, x, y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> x >> y;
    vector<int> ans(n + 5);
    // vector<int> cnt(n + 5, 0);
    vector<int> pos[n + 5];
    for(int i = 1; i <= n; i++) {
      int B;
      cin >> B;
      pos[B].push_back(i);
    }
    int lol = -1, mx = -1, idx = 0;
    for(int i = 1; i <= n + 1; i++) {
      if(pos[i].empty()) lol = i;
      if((int)pos[i].size() > mx) {
        mx = (int)pos[i].size();
        idx = i;
      }
    }
    cerr << lol << ":D\n";
    // assert(lol > 0);
    if(mx >= x + (n - x) / 2) {
      cerr << "asu";
      cerr << idx << ":(\n";
      int cur = 0;
      while(cur < x && !pos[idx].empty()) {
        cur++;
        // cnt[idx]--;
        ans[pos[idx].back()] = idx;
        pos[idx].pop_back();
      }
      for(int i = 1; i <= n; i++) {
        cerr << ans[i] << ' ';
      }
      mx = -1, idx = 0;
      for(int i = 1; i <= n + 1; i++) {
        if((int)pos[i].size() > mx)
          mx = (int)pos[i].size();
      }
      int gabisa = 2 * mx - (n - x);
      if(n - gabisa < y) {
        cout << "NO" << '\n';
        continue;
      }

      vector<pair<int, int>> wow;
      for(int i = 1; i <= n + 1; i++) {
        if(pos[i].empty()) continue;
        for(auto j : pos[i]) {
          wow.emplace_back(j, i);
        }
      }
      int cur1 = 0, cur2 = -1;
      for(int i = 1; i < (int)wow.size(); i++) {
        if(wow[i].second != wow[i - 1].second){
          cur2 = i;
          break;
        }
      }
      if(cur2 == -1 && y > x) {
        cout << "NO" << '\n';
        continue;
      }
      if(cur2 == -1 && y == x) {
        cerr << "njing\n";
        for(auto i : wow) {
          ans[i.first] = lol;
        }
      } else {
        int now = 0;
        for(int i = 0; i < (int)wow.size(); i++) {
          if(now < y - x){
            ans[wow[cur2].first] = wow[cur1].second;
            now++;
          } else {
            ans[wow[cur2].first] = lol;
          }
          cur1++; cur2++;
          if(cur1 == (int)wow.size()) cur1 = 0;
          if(cur2 == (int)wow.size()) cur2 = 0;
        }
      }

    } else {
      int cur = 0;
      for(int i = 1; i <= n + 1; i++) {
        while(cur < x && (int)pos[i].size() > (n - x) / 2) {
          cur++;
          // cnt[i]--;
          ans[pos[i].back()] = i;
          pos[i].pop_back();
        }
        if(cur == x)
          break;
      }
      if(cur < x) {
        for(int i = 1; i <= n + 1; i++) {
          while(cur < x && (int)pos[i].size() > 0) {
            cur++;
            // cnt[i]--;
            ans[pos[i].back()] = i;
            pos[i].pop_back();
          }
          if(cur >= x) break;
        }
      }
      for(int i = 1; i <= n; i++) {
        cerr << "pret\n";
        cerr << ans[i] << ' ';
      }
      int sisa = y - x;
      vector<pair<int, int>> wow;
      for(int i = 1; i <= n + 1; i++) {
        if(pos[i].empty()) continue;
        for(auto j : pos[i]) {
          wow.emplace_back(j, i);
        }
      }
      int cur1 = 0, cur2 = -1;
      for(int i = 1; i < (int)wow.size(); i++) {
        if(wow[i].second != wow[i - 1].second){
          cur2 = i;
          break;
        }
      }
      if(cur2 == -1 && y > x) {
        cout << "NO" << '\n';
        continue;
      }
      if(cur2 == -1 && y == x) {
        cerr << "njing\n";
        for(auto i : wow) {
          ans[i.first] = lol;
        }
      } else {
        int now = 0;
        for(int i = 0; i < (int)wow.size(); i++) {
          if(now < y - x){
            ans[wow[cur2].first] = wow[cur1].second;
            now++;
          } else {
            ans[wow[cur2].first] = lol;
          }
          cur1++; cur2++;
          if(cur1 >= (int)wow.size()) cur1 = 0;
          if(cur2 >= (int)wow.size()) cur2 = 0;
        }
      }
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}