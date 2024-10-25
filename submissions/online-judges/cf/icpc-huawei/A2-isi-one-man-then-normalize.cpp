#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int N, K, T, R;
ld s0[10][100][1000][10];
ld d[100][10][100][10];
ld p[10][100][1000][10];
ld c[10][1000];
const ld EPS = 1e-9;

const ld W = 192;

int J;
ll cnt[100];
ll ID[5000], TBS[5000], userID[5000], t0[5000], td[5000], t1[5000];
vector<vector<ll>> users[100];

bool lt(ld x, ld y) {
    return x < y;
}

bool ge(ld x, ld y) {
    return x >= y;
}

bool gt(ld x, ld y) {
    return x > y;
}

// check_frame(n, x[0], x[1], x[2]);
bool check_frame_one_user(int user_idx, ld tbs, int start, int end) {
    tbs /= (W * R);
    ld tmp = 0;
    for (int k = 0; k < K; k++) {
        for (int t = start; t <= end; t++) {
            tmp += log2(1 + c[k][t]);
            if (ge(tmp, tbs)) {
                return true;
            }
        }
    }
    return false;
}

void reset_p() {
    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            c[k][t] = 0;
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] = 0;
                }
            }
        }
    }
}

void normalize_p() {
    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            ld x = 0;
            for (int r = 0; r < R; r++) {
                ld y = 0;
                for (int n = 0; n < N; n++) {
                    y += p[r][n][t][k];
                }
                ld coef = min(ld(1), ld(4) / y);
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] *= coef;
                }
                y *= coef;
                x += y;
            }
            ld coeff = min(ld(1), ld(R) / x);
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] *= coeff;
                }
            }
        }
    }
}

bool check_all_conditions() {
    for (int r = 0; r < R; r++) {
        for (int t = 0; t < T; t++) {
            for (int k = 0; k < K; k++) {
                ld tmp = 0;
                for (int n = 0; n < N; n++) {
                    tmp += p[r][n][t][k];
                }
                if (lt(4, tmp)) return false;
            }
        }
    }
    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            ld tmp = 0;
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    tmp += p[r][n][t][k];
                }
            }
            if (lt(R, tmp)) return false;
        }
    }
    return true;
}

void solve_equalize_p() {
    ld c = ld(1) / N;
    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] = c;
                }
            }
        }
    }
}

void solve_one_user(int idx) {
    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            ld c_kt = 1e18;
            for (int r = 0; r < R; r++) {
                c_kt = min(c_kt, s0[r][idx][t][k] * 4);
            }
            ld harmonic_sum = 0;
            for (int r = 0; r < R; r++) {
                harmonic_sum += ld(1) / s0[r][idx][t][k];
            }
            c_kt = min(c_kt, ld(R) / harmonic_sum);
            for (int r = 0; r < R; r++) {
                p[r][idx][t][k] = c_kt / s0[r][idx][t][k];
            }
            c[k][t] = c_kt;
        }
    }
}

void el_psy_congroo() {
    cin >> N >> K >> T >> R;

    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    cin >> s0[r][n][t][k];
                }
            }
        }
    }

    for (int k = 0; k < K; k++) {
        for (int r = 0; r < R; r++) {
            for (int m = 0; m < N; m++) {
                for (int n = 0; n < N; n++) {
                    cin >> d[m][r][n][k];
                    if (m == n) d[m][r][n][k] = 0;
                }
            }
        }
    }

    cin >> J;
    for (int j = 0; j < J; j++) {
        cin >> ID[j] >> TBS[j] >> userID[j] >> t0[j] >> td[j];
        t1[j] = t0[j] + td[j] - 1;
        users[userID[j]].push_back(vector<ll>{TBS[j], t0[j], t1[j]});
    }

    int idx = -1, cur_mx = -1;
    for (int n = 0; n < N; n++) {
        solve_one_user(n);
    }

    normalize_p();
    bool ok = check_all_conditions();
    assert(ok);

    for (int t = 0; t < T; t++) {
        for (int k = 0; k < K; k++) {
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    cout << fixed << setprecision(12) << p[r][n][t][k] << ' ';
                }
                cout << '\n';
            }
        }
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