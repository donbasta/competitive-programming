#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 100;

//op, own, explosion
ld dp[3 * M][3 * M][M + 5];
vector<int> ve;
map<int, int> mp;

int get(const vector<int>& ve) {
  int ret = 0;
  for(int i = (int)ve.size(); i >= 1; i--) {
    ret += ve[i]; 
    ret *= 10;
  }
  return ret;
}

int cnt(int x) {
  int ret = 0;
  while(x > 0) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

vector<int> get(int x) {
  vector<int> ret;
  while(x > 0) {
    ret.push_back(x % 10);
    x /= 10;
  }
  ret.resize(6);
  return ret;
}

void init() {
  for(int i1 = 0; i1 <= 5; i1++) {
    for(int i2 = 0; i1 + i2 <= 5; i2++) {
      for(int i3 = 0; i1 + i2 + i3 <= 5; i3++) {
        for(int i4 = 0; i1 + i2 + i3 + i4 <= 5; i4++) {
          for(int i5 = 0; i1 + i2 + i3 + i4 + i5 <= 5; i5++) {
            for(int i6 = 0; i1 + i2 + i3 + i4 + i5 + i6 <= 5; i6++) {
              ve.push_back(get({i1, i2, i3, i4, i5, i6}));
            } 
          }
        }
      }
    }
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  for(auto i : ve) {
    mp[i] = cnt++;
  }
}

void solve() {
  cin >> n >> m >> d;
  vector<int> ar(7), br(7);
  int sum = 0, sum1 = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    ar[x]++;
  }
  int A = get(ar);
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    sum1 += x;
    sum += x;
    br[x]++;
  }
  int B = get(br);
  if(sum <= d) {
    cout << 1 << '\n';
    return;
  }
  if(d < sum1) {
    cout << 0 << '\n';
    return;
  }
  for(int i = 0; i < (int)ve.size(); i++) {
    for(int j = 0; j <= d; j++) {
      dp[0][i][j] = 1;
    }
  }
  for(int i = 1; i < (int)ve.size(); i++) {
    for(int j = 0; j < (int)ve.size(); j++) {
      int ii = cnt(ve[i]), jj = cnt(ve[j]);
      vector<int> vi = get(ve[i]), vj = get(ve[j]);
      for(int k = 1; k < d; k++) {
        for(int l = 1; l <= 6; l++) {
          dp[i][j][k] += get(ve[i], l) / (ii + jj) * dp[shift(i, l)][j][k - 1];
          dp[i][j][k] += get(ve[j], l) / (ii + jj) * dp[i][shift(j, l)][k - 1];
        }
      }
    }
  }
  ld ans = dp[][][d];
  cout << fixed << setprecision(12) << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  init();

  int TC = 1;
  // cin >> TC;
  for(int i = 1; i <= TC; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}