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
ld dpang[10][100][10];
const ld EPS = 1e-9;

const ld W = 192;

int J;
ll cnt[100];
ll ID[5000], TBS[5000], userID[5000], t0[5000], td[5000], t1[5000];
bool processed_time_frame[1000];
vector<vector<ll>> frames_per_user[100], all_frames;

bool le(ld x, ld y) { return x <= y; }
bool lt(ld x, ld y) { return x < y; }
bool ge(ld x, ld y) { return x >= y; }
bool gt(ld x, ld y) { return x > y; }

struct SegmentTree {
    vector<bool> lz;
    vector<int> tree;
    int n;
    SegmentTree(int n) : n(n), lz(4 * n + 5), tree(4 * n + 5) {}
    void push(int v, int s, int e) {
        if (!lz[v]) return;
        lz[v << 1] = lz[v << 1 | 1] = true;
        int mid = (s + e) >> 1;
        tree[v << 1] = mid - s + 1;
        tree[v << 1 | 1] = e - mid;
        lz[v] = false;
    }
    void upd(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            lz[v] = true;
            tree[v] = (e - s + 1);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            upd(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            upd(v << 1 | 1, mid + 1, e, l, r);
        else {
            upd(v << 1, s, mid, l, mid);
            upd(v << 1 | 1, mid + 1, e, mid + 1, r);
        }
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }
    int get(int v, int s, int e, int l, int r) {
        if (s == l && e == r) {
            return tree[v];
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        if (r <= mid)
            return get(v << 1, s, mid, l, r);
        else if (l >= mid + 1)
            return get(v << 1 | 1, mid + 1, e, l, r);
        return get(v << 1, s, mid, l, mid) + get(v << 1 | 1, mid + 1, e, mid + 1, r);
    }
    void mark_range(int l, int r) {
        upd(1, 0, n - 1, l, r);
    }
    int get_processed_tti(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

void solve_one_frame(int j) {
    int t0 = all_frames[j][0];
    int t1 = all_frames[j][1];
    int tbs = all_frames[j][2];
    int user_id = all_frames[j][3];
    for (int t = t0; t <= t1; t++) {
        if (processed_time_frame[t]) continue;
        for (int k = 0; k < K; k++) {
            // ld c_kt = 1e18;
            // for (int r = 0; r < R; r++) {
            //     c_kt = min(c_kt, exp(dpang[r][user_id][k]) * s0[r][user_id][t][k] * 4);
            // }
            // ld harmonic_sum = 0;
            // for (int r = 0; r < R; r++) {
            //     harmonic_sum += ld(1) / (s0[r][user_id][t][k] * exp(dpang[r][user_id][k]));
            // }
            // c_kt = min(c_kt, ld(R) / harmonic_sum);
            // for (int r = 0; r < R; r++) {
            //     p[r][user_id][t][k] = c_kt / (s0[r][user_id][t][k] * exp(dpang[r][user_id][k]));
            // }
            for (int r = 0; r < R; r++) {
                p[r][user_id][t][k] = 4;
            }
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    if (n == user_id) continue;
                    p[r][n][t][k] = 1e-6;
                }
            }
        }
        processed_time_frame[t] = true;
    }
}

void normalize_p_on_ttis(int t0, int t1) {
    for (int t = t0; t <= t1; t++) {
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
            ld coeff = ld(R) / x;
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] *= coeff;
                }
            }
        }
    }
}

void reset_p_on_ttis(int t0, int t1) {
    for (int t = t0; t <= t1; t++) {
        processed_time_frame[t] = false;
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

bool can_send_one_frame(int j) {
    solve_one_frame(j);
    normalize_p_on_ttis(all_frames[j][0], all_frames[j][1]);
    return check_frame_one_user(all_frames[j][3], all_frames[j][2], all_frames[j][0], all_frames[j][1]);
}

bool validate_all_conditions() {
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
                    // if (m == n) d[m][r][n][k] = 0;
                    if (m != n) dpang[r][m][k] += d[m][r][n][k];
                }
            }
        }
    }

    cin >> J;
    for (int j = 0; j < J; j++) {
        cin >> ID[j] >> TBS[j] >> userID[j] >> t0[j] >> td[j];
        t1[j] = t0[j] + td[j] - 1;
        // users[userID[j]].push_back(vector<ll>{t0[j], t1[j], TBS[j], userID[j]});
        all_frames.push_back(vector<ll>{t0[j], t1[j], TBS[j], userID[j], j});
    }

    // sort(all_frames.begin(), all_frames.end(), [&](const vector<ll>& f1, const vector<ll>& f2) -> bool {
    //     if (f1[1] == f2[1]) return f1[2] < f2[2];
    //     return f1[1] < f2[1];
    // });

    vector<ll> prioritized_frames_indices;
    for (int j = 0; j < J; j++) {
        if (can_send_one_frame(j)) {
            prioritized_frames_indices.push_back(j);
        }
        reset_p_on_ttis(all_frames[j][0], all_frames[j][1]);
    }

    SegmentTree segment_tree_tti(J);

    // int cur_right_bound = all_frames[0][1];
    // prioritized_frames_indices.push_back(0);
    vector<bool> used(J);
    // for (int j = 1; j < J; j++) {
    //     if (all_frames[j][0] <= cur_right_bound) {
    //         if (all_frames[j][3] == all_frames[prioritized_frames_indices.back()][3]) {
    //             prioritized_frames_indices.push_back(j);
    //             cur_right_bound = all_frames[j][1];
    //             used[j] = true;
    //             segment_tree_tti.mark_range(all_frames[j][0], all_frames[j][1]);
    //         }
    //     } else {
    //         prioritized_frames_indices.push_back(j);
    //         cur_right_bound = all_frames[j][1];
    //         used[j] = true;
    //         segment_tree_tti.mark_range(all_frames[j][0], all_frames[j][1]);
    //     }
    // }

    while (prioritized_frames_indices.size() < J) {
        int cur_num = 0, cur_den = 1, cur_idx = -1, cur_tbs = 1e9;
        for (int jj = 0; jj < J; jj++) {
            if (used[jj]) continue;
            int t0 = all_frames[jj][0];
            int t1 = all_frames[jj][1];
            int tti_length = t1 - t0 + 1;
            int tbs = all_frames[jj][2];
            int unprocessed_tti = tti_length - segment_tree_tti.get_processed_tti(t0, t1);
            if (unprocessed_tti * cur_den > tti_length * cur_num) {
                cur_num = unprocessed_tti;
                cur_den = tti_length;
                cur_idx = jj;
                cur_tbs = tbs;
            } else if (unprocessed_tti * cur_den == tti_length * cur_num && cur_tbs >= tbs) {
                cur_num = unprocessed_tti;
                cur_den = tti_length;
                cur_idx = jj;
                cur_tbs = tbs;
            }
        }
        assert(cur_idx != -1);
        prioritized_frames_indices.push_back(cur_idx);
        segment_tree_tti.mark_range(all_frames[cur_idx][0], all_frames[cur_idx][1]);
    }

    for (auto j : prioritized_frames_indices) {
        solve_one_frame(j);
    }

    normalize_p_on_ttis(0, T - 1);

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
                // cerr << r << ' ' << t << ' ' << k << ' ' << y << '\n';
                x += y;
            }
            ld coeff = min(ld(1), ld(R) / x);
            for (int r = 0; r < R; r++) {
                for (int n = 0; n < N; n++) {
                    p[r][n][t][k] *= coeff;
                }
            }
            x *= coeff;
            // cerr << t << ' ' << k << ' ' << x << '\n';
        }
    }

    bool ok = validate_all_conditions();
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