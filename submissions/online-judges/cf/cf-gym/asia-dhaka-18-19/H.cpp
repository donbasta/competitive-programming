#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 78294349;
const int M = 40000;
int gpf[M + 5];
bool is_prime[M + 5];

int fpow(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = (1ll * ret * a) % mod;
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return ret;
}

void init() {
    fill(is_prime + 1, is_prime + M, true);
    for (int i = 2; i <= M; i++) {
        if (!is_prime[i]) continue;
        gpf[i] = i;
        for (int j = i + i; j <= M; j += i) {
            is_prime[j] = false;
            gpf[j] = i;
        }
    }
}

vector<vector<int>> up(const vector<vector<int>>& X) {
    int r = X.size(), c = X[0].size();
    vector<vector<int>> ret(r, vector<int>(c, -1));
    for (int i = 0; i < c; i++) {
        int cur = 0;
        for (int j = 0; j < r; j++) {
            if (X[j][i] != -1) ret[cur++][i] = X[j][i];
        }
    }
    return ret;
}

vector<vector<int>> down(const vector<vector<int>>& X) {
    int r = X.size(), c = X[0].size();
    vector<vector<int>> ret(r, vector<int>(c, -1));
    for (int i = 0; i < c; i++) {
        int cur = r - 1;
        for (int j = r - 1; j >= 0; j--) {
            if (X[j][i] != -1) ret[cur--][i] = X[j][i];
        }
    }
    return ret;
}

vector<vector<int>> right(const vector<vector<int>>& X) {
    int r = X.size(), c = X[0].size();
    vector<vector<int>> ret(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++) {
        int cur = c - 1;
        for (int j = c - 1; j >= 0; j--) {
            if (X[i][j] != -1) ret[i][cur--] = X[i][j];
        }
    }
    return ret;
}

vector<vector<int>> left(const vector<vector<int>>& X) {
    int r = X.size(), c = X[0].size();
    vector<vector<int>> ret(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++) {
        int cur = 0;
        for (int j = 0; j < c; j++) {
            if (X[i][j] != -1) ret[i][cur++] = X[i][j];
        }
    }
    return ret;
}

void el_psy_congroo() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> B(r, vector<int>(c, -1));
    int T = 0;
    vector<int> pos(r * c);
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) {
            if (row[j] == '#') {
                pos[T] = i * c + j;
                B[i][j] = T;
                T++;
            }
        }
    }
    vector<vector<int>> b1 = B;
    vector<int> pos1(r * c);
    b1 = B;
    b1 = up(b1);
    b1 = right(b1);
    b1 = down(b1);
    b1 = left(b1);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b1[i][j] == -1) continue;
            pos1[b1[i][j]] = i * c + j;
        }
    }
    vector<bool> vis(r * c);
    vector<int> cyc;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (B[i][j] == -1) continue;
            int cur = B[i][j];
            if (vis[cur]) continue;
            int len = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                len++;
                cur = B[pos1[cur] / c][pos1[cur] % c];
            }
            assert(cur == B[i][j]);
            cyc.emplace_back(len);
        }
    }
    unordered_map<int, int> fp;
    for (auto e : cyc) {
        int cur = e;
        while (cur > 1) {
            int p = gpf[cur];
            int pw = 0;
            while (cur % p == 0) {
                pw++, cur /= p;
            }
            fp[p] = max(fp[p], pw);
        }
    }
    int ans = 1;
    for (auto e : fp) {
        ans = (1ll * ans * fpow(e.first, e.second, MOD)) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case " << i << ": ";
        el_psy_congroo();
    }

    return 0;
}
