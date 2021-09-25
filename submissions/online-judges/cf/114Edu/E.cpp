#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int N = 1e6;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

set<int> row[N + 1][2][2], col[N + 1][2][2];
set<int> isiRow, isiCol, cantRow, cantCol;
map<pair<int, int>, int> mp; 
int n, m, k;
int cnt[2];
int cntCatur[2][2];

void clear(int x, int y) {
    int val = mp[make_pair(x, y)];
    cnt[val]--;
    cntCatur[(x + y) & 1][val]--;
    row[x][val][y & 1].erase(y);
    col[y][val][x & 1].erase(x);
    mp.erase(make_pair(x, y));
    if (row[x][0][0].empty() && row[x][0][1].empty() && row[x][1][0].empty() && row[x][1][1].empty()) {
        isiRow.erase(x);
    }
    if (col[y][0][0].empty() && col[y][0][1].empty() && col[y][1][0].empty() && col[y][1][1].empty()) {
        isiCol.erase(y);
    }
}

void add(int x, int y, int val) {
    row[x][val][y & 1].insert(y);
    col[y][val][x & 1].insert(x);
    mp[make_pair(x, y)] = val;
    isiRow.insert(x);
    isiCol.insert(y);
    cnt[val]++;
    cntCatur[(x + y) & 1][val]++;
}

bool catur() {
    bool ok1 = (cntCatur[0][1] == cnt[1]) && (cntCatur[1][0] == cnt[0]);
    bool ok2 = (cntCatur[0][0] == cnt[0]) && (cntCatur[1][1] == cnt[1]);
    return (ok1 || ok2);
}

void solve() {
    cin >> n >> m >> k;
    while (k--) {
        int x, y, q;
        cin >> x >> y >> q;
        if (q == -1) {
            if (mp.find(make_pair(x, y)) != mp.end()) {
                clear(x, y);
            }
        } else if (q == 0) {
            if (mp.find(make_pair(x, y)) != mp.end()) {
                clear(x, y);
            }
            add(x, y, 0);
        } else if (q == 1) {
            if (mp.find(make_pair(x, y)) != mp.end()) {
                clear(x, y);
            }
            add(x, y, 1);
        }
        bool vr1 = ((!row[x][0][0].empty()) && (!row[x][0][1].empty()));
        bool vr2 = ((!row[x][1][0].empty()) && (!row[x][1][1].empty()));
        bool vr3 = ((!row[x][0][0].empty()) && (!row[x][1][0].empty()));
        bool vr4 = ((!row[x][0][1].empty()) && (!row[x][1][1].empty()));
        bool vc1 = ((!col[y][0][0].empty()) && (!col[y][0][1].empty()));
        bool vc2 = ((!col[y][1][0].empty()) && (!col[y][1][1].empty()));
        bool vc3 = ((!col[y][0][0].empty()) && (!col[y][1][0].empty()));
        bool vc4 = ((!col[y][0][1].empty()) && (!col[y][1][1].empty()));
        if (vr1 || vr2 || vr3 || vr4) {
            cantRow.insert(x);
        } else {
            cantRow.erase(x);
        }
        if (vc1 || vc2 || vc3 || vc4) {
            cantCol.insert(y);
        } else {
            cantCol.erase(y);
        }
        ll ret = 0;
        if (cantRow.empty()) {
            ret = (ret + fpow(2LL, n - isiRow.size())) % MOD;
        }
        if (cantCol.empty()) {
            ret = (ret + fpow(2LL, m - isiCol.size())) % MOD;
        }
        if (catur()) {
            ret = (ret - 1) % MOD;
            if ((cnt[0] == 0) && (cnt[1] == 0)) {
                ret = (ret - 1) % MOD;
            }
        }
        if (ret < 0) ret += MOD;
        cout << ret << '\n';
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