#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void randomize(vector<vector<int>>& T) {
    int n = T.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = (rng() & 1);
        }
    }
}

string ask(const vector<vector<int>>& T) {
    int n = T.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << T[i][j];
        }
        cout << endl;
    }
    string ans;
    cin >> ans;
    return ans;
}

void el_psy_congroo() {
    for (int i = 0; i < 333; i++) {
        int n;
        cin >> n;
        vector<vector<int>> que(n, vector<int>(n));
        if (n == 3) {
            while (true) {
                randomize(que);
                string verdict = ask(que);
                if (verdict == "CORRECT")
                    break;
                else {
                    int buf;
                    cin >> buf;
                }
            }
        } else {
            que[2][2] = 1;
            string verdict = ask(que);
            que[2][2] = 0;
            if (verdict == "CORRECT")
                continue;
            else {
                vector<string> feedback(n - 2);
                for (int i = 0; i < n - 2; i++) {
                    cin >> feedback[i];
                }
                vector<vector<int>> secret(3, vector<int>(3));
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        secret[i][j] = (feedback[2 - i][2 - j] - '0');
                    }
                }
                cerr << "SECRET\n";
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cerr << secret[i][j];
                    }
                    cerr << '\n';
                }
                vector<vector<bool>> fixed(n, vector<bool>(n));
                for (int i = 0; i < n - 2; i++) {
                    for (int j = 0; j < n - 2; j++) {
                        int cnt = 0;
                        int cur = 0;
                        vector<pair<int, int>> isi;
                        for (int x = i; x <= i + 2; x++) {
                            for (int y = j; y <= j + 2; y++) {
                                if (secret[x - i][y - j] && !fixed[x][y]) {
                                    cnt++;
                                    fixed[x][y] = true;
                                    isi.emplace_back(x, y);
                                } else if (secret[x - i][y - j] && fixed[x][y]) {
                                    cur ^= que[x][y];
                                }
                            }
                        }
                        assert(cnt > 0);
                        que[isi[0].first][isi[0].second] = cur ^ 1;
                    }
                }
                verdict = ask(que);
                assert(verdict == "CORRECT");
            }
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}