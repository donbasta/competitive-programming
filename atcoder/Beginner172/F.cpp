#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll a[2];
ll cur;
int n;
vector<int> vec[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    if(i <= 2) {
      cin >> a[i - 1];
    } else {
      ll x;
      cin >> x;
      cur ^= x;
    }
  }

  if(abs(a[0] + a[1] + cur) % 2 != 0) {
    cout << -1 << '\n';
    return 0;
  }

  for(int i = 0; i < 41; i++) {
    vec[0].push_back((a[0] >> i) & 1);
    vec[1].push_back((a[1] >> i) & 1);
    vec[2].push_back((cur >> i) & 1);
  }
  for(int i = 0; i < 3; i++) {
    reverse(vec[i].begin(), vec[i].end());
  }
    // for(int i = 0; i < 3; i++) {
    //   for(int j = 0; j < 41; j++) {
    //     cout << vec[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "-------";
  bool belom = true;
  for(int i = 0; i < 41; i++) {
    if((vec[0][i] ^ vec[1][i]) == vec[2][i]){
      // cout << i << " orz " << vec[0][i] << ' ' << vec[1][i] << '\n';
      if((!belom) && (vec[0][i] == 0) && (vec[1][i] == 1)) {
        // cout << i << " :D";
        swap(vec[0][i], vec[1][i]);
      }
      continue;
    }
    if(belom && (vec[0][i] == 0) && (vec[1][i] == 1)) {
      cout << -1 << '\n';
      return 0;
    }
    belom = false;
    if(vec[0][i] == 1 && vec[1][i] == 1) {
      // cout << i << ' ';
      vec[0][i] = 0;
      int tot = 2;
      for(int j = i + 1; j < 41; j++) {
        if(vec[0][j] == 0 && vec[1][j] == 0){
          // cout << i << " :(";
          if(tot == 2) {
            vec[0][j] = vec[1][j] = 1;
          } else if(tot == 1) {
            vec[0][j] = 1;
          }
          tot = 0;
          break;
        } else if(vec[0][j] == 1 && vec[1][j] == 0) {
          vec[1][j] = 1;
          tot--;
        } else if(vec[0][j] == 0 && vec[1][j] == 1) {
          vec[0][j] = 1;
          tot--;
        } else {
          // cout << j << ":D";
          cout << -1 << '\n';
          return 0;
        }
      }
      if(tot > 0) {
        cout << -1 << '\n';
        return 0;
      }
    } else if(vec[0][i] == 1 && vec[1][i] == 0) {
      vec[0][i] = 0;

      int tot = 2;
      for(int j = i + 1; j < 41; j++) {
        if(vec[0][j] == 0 && vec[1][j] == 0){
          if(tot == 2) {
            vec[0][j] = vec[1][j] = 1;
          } else if(tot == 1) {
            vec[0][j] = 1;
          }
          tot = 0;
          break;
        } else if(vec[0][j] == 1 && vec[1][j] == 0) {
          vec[1][j] = 1;
          tot--;
        } else if(vec[0][j] == 0 && vec[1][j] == 1) {
          vec[0][j] = 1;
          tot--;
        } else {
          cout << -1 << '\n';
          return 0;
        }
      }
      if(tot > 0) {
        cout << -1 << '\n';
        return 0;
      }
    } else if (vec[0][i] == 0 && vec[1][i] == 0) {
      bool ok = false;
      int tot = 2;
      for(int j = i + 1; j < 41; j++) {
        if(vec[0][j] == 1 && vec[1][j] == 1){
          if(tot == 2) {
            vec[0][j] = vec[1][j] = 0;
          } else if(tot == 1) {
            vec[1][j] = 0;
          }
          tot = 0;
          ok = true;
          break;
        } else if(vec[0][j] == 1 && vec[1][j] == 0) {
          vec[0][j] = 0;
          tot--;
        } else if(vec[0][j] == 0 && vec[1][j] == 1) {
          vec[1][j] = 0;
          tot--;
        } else {
          cout << -1 << '\n';
          return 0;
        }
      }
      if(ok) {
        vec[1][i] = 1;
      } else {
        cout << -1 << '\n';
        return 0;
      }
    } else {
      bool ok = false;
      int tot = 2;
      for(int j = i + 1; j < 41; j++) {
        if(vec[0][j] == 1 && vec[1][j] == 1){
          if(tot == 2) {
            vec[0][j] = vec[1][j] = 0;
          } else if(tot == 1) {
            vec[1][j] = 0;
          }
          tot = 0;
          ok = true;
          break;
        } else if(vec[0][j] == 1 && vec[1][j] == 0) {
          vec[0][j] = 0;
          tot--;
        } else if(vec[0][j] == 0 && vec[1][j] == 1) {
          vec[1][j] = 0;
          tot--;
        } else {
          cout << -1 << '\n';
          return 0;
        }
      }
      if(ok) {
        vec[0][i] = 1;
      } else {
        cout << -1 << '\n';
        return 0;
      }
    }

    // cout << i << '\n';
    // for(int i = 0; i < 3; i++) {
    //   for(int j = 0; j < 41; j++) {
    //     cout << vec[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "-------";

  }
  ll lol = 0;
  for(int i = 40; i >= 0; i--) {
    lol += (1LL << (40 - i)) * 1LL * vec[0][i];
  }
  ll ANS = a[0] - lol;
  if(ANS >= a[0] || ANS < 0) {
    cout << -1 << '\n';
  } else {
    cout << ANS << '\n';
  }

  return 0;
}
