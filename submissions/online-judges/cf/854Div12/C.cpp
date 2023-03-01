#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    string ret(n, '*');
    int l = 0, r = n - 1;

    const auto to_char = [&](int x) {
        return (char)(x + 'a');
    };

    for (int i = 0; i < 26; i++) {
        int move = cnt[i] / 2;
        for (int j = l; j <= l + move - 1; j++) {
            ret[j] = to_char(i);
        }
        l = l + move;
        for (int j = r; j >= r - move + 1; j--) {
            ret[j] = to_char(i);
        }
        r = r - move;
        if (cnt[i] % 2 == 1) {
            int huruf_sisa = 0;
            int hehe = -1;
            bool lmao = false;
            for (int j = i + 1; j < 26; j++) {
                huruf_sisa += (cnt[j] > 0);
                if (cnt[j] > 0) hehe = j;
            }
            if (huruf_sisa == 1) lmao = true;
            if (lmao) {
                int need = cnt[hehe] / 2;
                for (int j = l; j <= l + need - 1; j++) {
                    ret[j] = to_char(hehe);
                }
                for (int j = r; j >= r - need + 1; j--) {
                    ret[j] = to_char(hehe);
                }
                ret[r - need] = to_char(i);
                if (cnt[hehe] & 1) ret[l + need] = to_char(hehe);
                break;
            } else {
                vector<char> bruh;
                bruh.emplace_back(to_char(i));
                for (int j = i + 1; j < 26; j++) {
                    for (int k = 0; k < cnt[j]; k++) bruh.emplace_back(to_char(j));
                }
                ret[r] = bruh[0];
                for (int j = l; j < r; j++) {
                    ret[j] = bruh[j - l + 1];
                }
                break;
            }
        }
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}