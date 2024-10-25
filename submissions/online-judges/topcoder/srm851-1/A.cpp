#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1000047;

class NextGuess {
   public:
    int guess(vector<int> guesses, string answers) {
        int n = guesses.size();
        int l = -INF, r = INF;
        for (int i = 0; i < n; i++) {
            int cur = guesses[i];
            char c = answers[i];
            if (c == '<') {
                r = min(r, cur - 1);
            } else if (c == '>') {
                l = max(l, cur + 1);
            }
            assert(l <= r);
        }
        return l;
    }
};

void el_psy_congroo() {
    NextGuess N;
    int n;
    cin >> n;
    vector<int> g;
    string a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g.push_back(x);
    }
    cin >> a;
    cout << N.guess(g, a);
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