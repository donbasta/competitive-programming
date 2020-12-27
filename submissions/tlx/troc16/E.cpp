#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ll = long long;
using ld = long double;

const int N = 1e5;
const ll mod = 1e9 + 7;

int n;
int gpf[N + 5];
map<int, vector<pair<int, int>>> mp;

void sieve() {
  memset(gpf, -1, sizeof(gpf));
  for (int i = 2; i <= N; i++) {
    if (gpf[i] != -1) continue;
    for (int j = i; j <= N; j += i) {
      gpf[j] = i;
    }
  }
}

ll fpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void process(int x, int pos) {
  while(x > 1) {
    int pr = gpf[x];
    int pw = 0;
    while(x % pr == 0) {
      pw++;
      x /= pr;
    }
    mp[pr].emplace_back(pw, pos);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    process(x, i);
  }
  ll ans = 1;
  for (auto i : mp) {

    int pr = i.first;
    cerr << pr << '\n';
    vector<pair<int, int>> lol = i.second;
    int sz = (int)lol.size();
    cerr << sz << '\n';
    vector<pair<int, int>> bat(sz);
    stack<pair<int, int>> st;

    bat[0].fi = 1;
    st.emplace(lol[0].fi, 0);
    for (int i = 1; i < sz; i++) {
      assert(!st.empty());
      if (st.top().fi > lol[i].fi) {
        bat[i].fi = lol[st.top().se].se + 1;
        st.emplace(lol[i].fi, i);
      } else {
        while (!st.empty() && st.top().fi <= lol[i].fi) {
          st.pop();
        }
        if (st.empty()) {
          bat[i].fi = 1;
        } else {
          bat[i].fi = lol[st.top().se].se + 1;
        }
        st.emplace(lol[i].fi, i);
      }
    }

    while(!st.empty()) st.pop();

    bat[sz - 1].se = n;
    st.emplace(lol[sz - 1].fi, sz - 1);
    for (int i = sz - 2; i >= 0; i--) {
      assert(!st.empty());
      if (st.top().fi > lol[i].fi) {
        bat[i].se = lol[st.top().se].se - 1;
        st.emplace(lol[i].fi, i);
      } else {
        while (!st.empty() && st.top().fi <= lol[i].fi) {
          st.pop();
        }
        if (st.empty()) {
          bat[i].se = n;
        } else {
          bat[i].se = lol[st.top().se].se - 1;
        }
        st.emplace(lol[i].fi, i);
      }
    }

    ll que = 0;
    map<pair<int, int>, vector<pair<int, int>>> mpp;
    // set<pair<pair<int, int>, int>> se;
    for (int i = 0; i < sz; i++) {
      // se.emplace(bat[i], lol[i].fi);
      // cerr << i << ' ' << bat[i].fi << ' ' << bat[i].se << '\n';
      // int pos = lol[i].se;
      // int A = pos - bat[i].fi + 1;
      // int B = bat[i].se - pos + 1;
      // cerr << A << ' ' << B << '\n';
      // ll temp = 1LL * A * B % mod;
      // que = (que + 1LL * temp * lol[i].fi) % mod;
      mp[bat[i]].push_back(lol[i]);
    }
    // if (que < 0) que += mod;
    // for (auto i : se) {
    //   auto A = i.first;
    //   int B = i.second; 
    //   que += 1LL * (A.se - A.fi + 1) * B;
    // }
    for (auto i : mpp) {
      for (int j = 0; j < i.se.size; j++) {
        ans -= C()
      }
      if (i.se.size() == 1) {
        int A = i.se[0].se - i.fi.fi + 1;
        int B = i.fi.se - i.se[0].se + 1;
        ll temp = 1LL * A * B % mod;
        que = (que + 1LL * temp * i.se[0].fi) % mod;
      } else {
        int tot = i.fi.s
      }
    }
    ans = ans * fpow(pr, que) % mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  sieve();

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}