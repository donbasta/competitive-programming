#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<char> COL;

pair<int, int> nxt(pair<int, int> cur, int sz) {
  int x = cur.first, y = cur.second;
  if(y % 2 == 0) {
    if(x == sz - 1)
      y++;
    else
      x++;
  } else {
    if(x == 1)
      y++;
    else
      x--;
  }
  return make_pair(x, y);
}

pair<int, int> nxto(pair<int, int> cur, int sz) {
  int x = cur.first, y = cur.second;
  if(y <= sz/2) {
    return nxt(cur, sz);
  } else {
    if(y % 2 == 0) {
      if(x == sz - 1)
        y--;
      else
        x++;
    } else {
      if(x == 1)
        y--;
      else
        x--;
    }
  }
  return make_pair(x, y);
}

void solve() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << "impossible" << '\n';
    return;
  }
  if (n == 5) {
    cout << "XXXTr\nXTTTr\nXTErr\nmmEEr\nmmmEE";
    cout << '\n';
    return;
  }
  vector<vector<char>> ans(n, vector<char>(n,'a'));
  vector<vector<bool>> vis(n, vector<bool>(n,0));
  if(n % 2 == 0) {
    int idx = 1;
    int cnt = 0;
    int cur = n;
    pair<int, int> pos = make_pair(1,0);
    while(cur < n*n) {
      if(cnt == n) {
        cnt = 0, idx++;
      }
      ans[pos.first][pos.second] = COL[idx];
      cnt++;
      cur++;
      if(cur == n*n) break;
      pos = nxt(pos, n);
    }
  } else if(n % 2 == 1) {
    bool balik = 0;
    int idx = 1;
    int cnt = 0;
    int cur = n;
    pair<int, int> pos = make_pair(1,0);
    while(cur < n*n) {
      if(cnt == n) {
        cnt = 0, idx++;
      }
      if(balik && pos.second == n/2) {
        for(int i = 1; i < n; i++) {
          if(!vis[i][n/2]) {
            ans[i][n/2] = COL[idx];
          }
        }
        break;
      }
      ans[pos.first][pos.second] = COL[idx];
      vis[pos.first][pos.second] = 1;
      cnt++;
      cur++;
      if(cur == n*n) break;
      if(cnt == n && pos.second == n/2) {
        balik = 1;
        pos = make_pair(1, n-1);
        continue;
      }
      pos = nxto(pos, n);
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for(char i = 'a'; i <= 'z'; i++) {
    COL.push_back(i);
  }
  for(char i = 'A'; i <= 'Z'; i++) {
    COL.push_back(i);
  }
  for(char i = '0'; i <= '9'; i++) {
    COL.push_back(i);
  }

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}