#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string buf;
    getline(cin, buf);
    auto conv = [&](char c) -> int {
        if (c >= '2' && c <= '9') return (c - '0');
        if (c == 'T') return 10;
        if (c == 'J') return 11;
        if (c == 'Q') return 12;
        if (c == 'K') return 13;
        assert(c == 'A');
        return 14;
    };
    for (int i = 0; i < n; i++) {
        deque<int> deck[2];
        for (int j = 0; j < 2; j++) {
            getline(cin, buf);
            for (auto c : buf) {
                if (c == ' ' || c == '\n') continue;
                deck[j].push_back(conv(c));
            }
        }
        string winner;
        int dr = 0;
        while (true) {
            if (deck[0].empty()) {
                winner = "player 2";
                break;
            } else if (deck[1].empty()) {
                winner = "player 1";
                break;
            } else {
                int x = deck[0].front(), y = deck[1].front();
                deck[0].pop_front(), deck[1].pop_front();
                if (x < y) {
                    deck[1].push_back(x);
                    dr = 0;
                } else if (x > y) {
                    deck[0].push_back(y);
                    dr = 0;
                } else {
                    deck[0].push_back(x), deck[1].push_back(y);
                    dr++;
                    int a = deck[0].size(), b = deck[1].size();
                    int kpk = a * b / __gcd(a, b);
                    if (dr == kpk) {
                        winner = "draw";
                        break;
                    }
                }
            }
        }
        cout << winner << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}