#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        --b[i];
    }
    const function<void(vector<int>&, vector<int>&, int)> operate = [&](vector<int>& T, vector<int>& P, int pivot) {
        int sz = T.size();
        vector<int> tmp(sz);
        for (int i = pivot + 1; i < sz; i++) {
            tmp[i - pivot - 1] = T[i];
        }
        tmp[sz - pivot - 1] = T[pivot];
        for (int i = 0; i < pivot; i++) {
            tmp[sz - pivot + i] = T[i];
        }
        T = tmp;
        for (int i = 0; i < sz; i++) {
            P[T[i]] = i;
        }
    };
    const function<vector<int>(vector<int>)> solve = [&](vector<int> T) -> vector<int> {
        int sz = T.size();
        vector<int> ret;
        for (int i = 0; i < sz - 1; i++) {
            vector<int> tmp = T;
            vector<int> pos(sz);
            for (int j = 0; j < sz; j++) {
                pos[T[j]] = j;
            }
            int mv;
            if (pos[i + 1] < pos[i]) {
                mv = pos[i] + 1;
                if (pos[i] < sz - 1) {
                    ret.push_back(mv);
                    operate(tmp, pos, mv);
                }
                mv = pos[i + 1];
                ret.push_back(mv);
                operate(tmp, pos, mv);
            } else if (pos[i + 1] > pos[i] + 1) {
                mv = pos[i] + 1;
                ret.push_back(mv);
                operate(tmp, pos, mv);
                mv = pos[i + 1];
                ret.push_back(mv);
                operate(tmp, pos, mv);
            }
            T = tmp;
        }
        return ret;
    };
    vector<int> A = solve(a);
    vector<int> B = solve(b);
    int sza = A.size(), szb = B.size();
    if ((sza % 2) != (szb % 2)) {
        if ((n % 2 == 0) && (m % 2 == 0)) {
            cout << -1 << '\n';
            return;
        } else if (n % 2 == 1) {
            for (int i = n - 1; i >= 0; i--) {
                A.push_back(0);
            }
        } else if (m % 2 == 1) {
            for (int i = m - 1; i >= 0; i--) {
                B.push_back(0);
            }
        }
    }
    sza = A.size(), szb = B.size();
    assert((sza % 2) == (szb % 2));
    while (A.size() < B.size()) {
        A.push_back(0);
        A.push_back(n - 1);
    }
    while (B.size() < A.size()) {
        B.push_back(0);
        B.push_back(m - 1);
    }
    int sz = A.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << A[i] + 1 << ' ' << B[i] + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}