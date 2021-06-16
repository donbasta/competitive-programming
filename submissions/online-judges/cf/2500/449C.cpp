#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MX = 1e5;
int n;

bool pr[MX + 5];
int pre[MX + 5];
int Ans;
vector<int> primes;

void sieve() {
    for (int i = 0; i <= MX; i++) pr[i] = 1;
    pr[0] = pr[1] = 0;
    for (int i = 2; i <= MX; i++) {
        if (!pr[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= MX; j += i) {
            pr[j] = 0;
        }
    }
    for (int i = 1; i <= MX; i++) {
        pre[i] = pre[i - 1] + pr[i];
    }
}

void jawab() {
    vector<pair<int, int>> ans;
    vector<bool> udah(n + 5);
    for (int i = n; i > 2; i--) {
        if (!pr[i]) continue;
        vector<int> tmp;
        for (int j = i; j <= n; j += i) {
            if (udah[j]) continue;
            tmp.emplace_back(j);
        }
        int j = 0;
        if ((int)tmp.size() & 1) {
            vector<int> lol;
            while (j < (int)tmp.size()) {
                if (tmp[j] == i * 2) {
                    j++;
                    continue;
                } else {
                    lol.emplace_back(tmp[j]);
                    j++;
                }
                if ((int)lol.size() == 2) {
                    ans.emplace_back(lol[0], lol[1]);
                    udah[lol[0]] = udah[lol[1]] = 1;
                    lol.clear();
                }
            }
        } else {
            for (j = 0; j + 1 < (int)tmp.size(); j += 2) {
                ans.emplace_back(tmp[j], tmp[j + 1]);
                udah[tmp[j]] = udah[tmp[j + 1]] = 1;
            }
        }
    }
    vector<int> lol;
    for (int i = 2; i <= n; i += 2) {
        if (!udah[i]) lol.emplace_back(i);
        if ((int)lol.size() == 2) {
            ans.emplace_back(lol[0], lol[1]);
            lol.clear();
        }
    }
    for (auto& e : ans) {
        cout << e.first << ' ' << e.second << '\n';
    }
    assert ((int)ans.size() == Ans);
}

void solve() {
    cin >> n;
    sieve();
    int cannot = pre[n] - pre[n / 2];
    Ans = (n - 1 - cannot) / 2;
    cout << Ans << '\n';
    jawab();
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