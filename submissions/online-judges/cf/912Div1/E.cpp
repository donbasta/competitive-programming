#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;
    int st = (sx + sy) & 1;
    vector<int> cnt(2), par(n + 1);
    vector<set<int>> se(2);
    set<int> avail;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[(x + y) & 1]++;
        se[(x + y) & 1].insert(i + 1);
        par[i + 1] = ((x + y) & 1);
        avail.insert(i + 1);
    }

    auto opp_move = [&]() -> void {
        int opp;
        cin >> opp;
        se[par[opp]].erase(opp);
        avail.erase(opp);
    };

    auto my_move = [&](int parity) -> void {
        if (!se[parity].empty()) {
            int my = *se[parity].begin();
            cout << my << endl;
            avail.erase(my);
            se[parity].erase(my);
        } else {
            int my = *se[parity ^ 1].begin();
            cout << my << endl;
            avail.erase(my);
            se[parity ^ 1].erase(my);
        }
    };

    if (cnt[0] == cnt[1]) {
        cout << "First" << endl;
        for (int i = 0; i < (n / 2); i++) {
            my_move(st ^ 1);
            opp_move();
        }
    } else if (cnt[0] < cnt[1]) {
        int my_turn;
        if (st == 0) {
            cout << "Second" << endl;
            my_turn = 0;
        } else {
            cout << "First" << endl;
            my_turn = 1;
        }
        while (!avail.empty()) {
            if (my_turn) {
                my_move(0);
            } else {
                opp_move();
            }
            my_turn ^= 1;
        }
    } else if (cnt[0] > cnt[1]) {
        int my_turn;
        if (st == 0) {
            cout << "First" << endl;
            my_turn = 1;
        } else if (st == 1) {
            cout << "Second" << endl;
            my_turn = 0;
        }
        while (!avail.empty()) {
            if (my_turn) {
                my_move(1);
            } else {
                opp_move();
            }
            my_turn ^= 1;
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}