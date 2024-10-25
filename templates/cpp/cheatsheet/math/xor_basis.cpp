#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

template <typename T>
struct XORBasis {
    int DIM, RANK;
    vector<T> BASE;
    XORBasis(int _DIM) : DIM(_DIM), BASE(DIM + 1, -1), RANK(0) {}
    void insert(T x) {
        for (int i = DIM; i >= 0; i--) {
            if (!((x >> i) & 1)) continue;
            if (BASE[i] == -1) {
                BASE[i] = x;
                RANK++;
                return;
            }
            x ^= BASE[i];
        }
    }
    bool span(T x) {
        for (int i = DIM; i >= 0; i--) {
            if (!((x >> i) & 1)) continue;
            if (BASE[i] == -1) return false;
            x ^= BASE[i];
        }
        return true;
    }
};

void el_psy_congroo() {
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}