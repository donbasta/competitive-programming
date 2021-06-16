#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
using PII = pair<int, int>;

const LL mod = 1000000007;
 
int s[10], cnt[21];
 
int compare (const vector<int>& x, const vector<int>& y) {
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        if (x[i] == y[i]) { ++a; }
    }
    for (int i = 0; i < 4; ++i) {
        ++s[x[i]];
    }
    for (int i = 0; i < 4; ++i) {
        if (s[y[i]]) { ++b; }
    }
    for (int i = 0; i < 4; ++i) {
        --s[x[i]];
    }
    return a * 5 + (b - a);
}
 
int main() {
    vector<vector<int>> candidates;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {
                        candidates.push_back({i, j, k, l});
                    }
                }
            }
        }
    }
 
    for (int _ = 1; _ <= 7; ++_) {
        vector<int> optimal;
        int optimal_min = INT_MAX;
        if (_ == 1) {
            optimal = {0, 1, 2, 3};
        } else {
            for (const vector<int>& select: candidates) {
                memset(cnt, 0, sizeof(cnt));
                for (const vector<int>& candidate: candidates) {
                    ++cnt[compare(select, candidate)];
                }
                int select_min = *max_element(cnt, cnt + 21);
                if (select_min < optimal_min) {
                    optimal = select;
                    optimal_min = select_min;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            cout << optimal[i];
            if (i < 3) cout << ' ';
        }
        cout << endl;
        
        int a, b, tmp;
        cin >> a >> b;
        if (a == 4 && b == 4) {
            return 0;
        }
        tmp = a;
        a = b;
        b = tmp - b;
        vector<vector<int>> nxt_candidates;
        for (const vector<int>& candidate: candidates) {
            if (compare(optimal, candidate) == a * 5 + b) {
                nxt_candidates.emplace_back(candidate);
            }
        }
        candidates = nxt_candidates;
    }
    return 0;
}