#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    int cnt = 2 * n * (n - 1);
    set<tuple<int, int, int, int>> se;
    int cur = 0;
    string game;
    vector<int> score(2);
    for (int i = 1; i <= cnt; i++) {
        bool again = false;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            if (b > d) swap(b, d);
            if (a > 1) {
                bool ok1 = se.count(make_tuple(a - 1, d, a, d));
                bool ok2 = se.count(make_tuple(a - 1, b, a - 1, d));
                bool ok3 = se.count(make_tuple(a - 1, b, a, b));
                if (ok1 && ok2 && ok3) {
                    score[cur]++;
                    again = true;
                }
            }
            if (a < n) {
                bool ok1 = se.count(make_tuple(a, b, a + 1, b));
                bool ok2 = se.count(make_tuple(a, d, a + 1, d));
                bool ok3 = se.count(make_tuple(a + 1, b, a + 1, d));
                if (ok1 && ok2 && ok3) {
                    score[cur]++;
                    again = true;
                }
            }
        } else if (b == d) {
            if (a > c) swap(a, c);
            if (b > 1) {
                bool ok1 = se.count(make_tuple(a, b - 1, a, b));
                bool ok2 = se.count(make_tuple(c, b - 1, c, b));
                bool ok3 = se.count(make_tuple(a, b - 1, c, b - 1));
                if (ok1 && ok2 && ok3) {
                    score[cur]++;
                    again = true;
                }
            }
            if (b < n) {
                bool ok1 = se.count(make_tuple(a, b, a, b + 1));
                bool ok2 = se.count(make_tuple(c, b, c, b + 1));
                bool ok3 = se.count(make_tuple(a, b + 1, c, b + 1));
                if (ok1 && ok2 && ok3) {
                    score[cur]++;
                    again = true;
                }
            }
        }
        se.emplace(a, b, c, d);
        game.push_back((char) (cur + 'A'));
        if (!again) {
            cur = 1 - cur;
        }
    }
    cout << game << '\n';
    cout << score[0] << ' ' << score[1] << '\n';
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