#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int B = 300;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int n_blocks = ((n + B - 1) / B);
    vector<deque<int>> de(n_blocks);
    vector<vector<int>> cnt(n_blocks, vector<int>(n + 1));
    for (int i = 0; i < n_blocks; i++) {
        int LB = i * B, RB = min(n - 1, LB + B - 1);
        for (int j = LB; j <= RB; j++) {
            de[i].push_back(ar[j]);
            cnt[i][ar[j]]++;
        }
    }
    int q;
    cin >> q;
    int lastans = 0;

    for (int iii = 0; iii < q; iii++) {
        int tp, l, r, k;
        cin >> tp >> l >> r;
        if (tp == 2) cin >> k;
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        --l, --r;
        if (l > r) swap(l, r);
        int l_id = l / B, r_id = r / B;
        if (tp == 1) {
            int kiki = (r_id ? de[r_id - 1].back() : -1);
            if (r_id >= l_id + 2) {
                for (int i = r_id - 1; i >= l_id + 1; i--) {
                    cnt[i][de[i].back()]--;
                    de[i].pop_back();
                    de[i].push_front(de[i - 1].back());
                    cnt[i][de[i].front()]++;
                }
            }
            if (l_id == r_id) {
                int LB = B * l_id;
                int ka = de[l_id][r - LB];
                for (int i = r; i >= l + 1; i--) de[l_id][i - LB] = de[l_id][i - LB - 1];
                de[l_id][l - LB] = ka;
            } else {
                int LB = B * r_id;
                int ka = de[r_id][r - LB];
                cnt[r_id][ka]--;
                for (int i = r; i > LB; i--) {
                    de[r_id][i - LB] = de[r_id][i - LB - 1];
                }
                de[r_id][0] = kiki;
                cnt[r_id][kiki]++;
                LB = B * l_id;
                cnt[l_id][de[l_id].back()]--;
                for (int i = LB + B - 1; i >= l + 1; i--) {
                    de[l_id][i - LB] = de[l_id][i - LB - 1];
                }
                de[l_id][l - LB] = ka;
                cnt[l_id][ka]++;
            }
        } else {
            k = (k + lastans - 1) % n + 1;
            int ret = 0;
            if (r_id >= l_id + 2) {
                for (int i = l_id + 1; i <= r_id - 1; i++) ret += cnt[i][k];
            }
            if (l_id == r_id) {
                int LB = B * l_id;
                for (int i = l; i <= r; i++) {
                    ret += de[l_id][i - LB] == k;
                }
            } else {
                int LB = B * l_id;
                for (int i = l; i <= min(n - 1, LB + B - 1); i++) ret += de[l_id][i - LB] == k;
                LB = B * r_id;
                for (int i = LB; i <= r; i++) ret += de[r_id][i - LB] == k;
            }
            cout << ret << '\n';
            lastans = ret;
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