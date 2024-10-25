#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

class ChangeReport {
   public:
    vector<string> produceReport(vector<string> names, vector<int> lastYearSales, vector<int> thisYearSales) {
        int n = names.size();
        vector<pair<int, string>> A, B;
        for (int i = 0; i < n; i++) {
            int score = thisYearSales[i] - lastYearSales[i];
            if (score != 0) {
                A.emplace_back(score, names[i]);
            } else {
                B.emplace_back(0, names[i]);
            }
        }
        sort(A.begin(), A.end(), [&](const pair<int, string>& x, const pair<int, string>& y) -> bool {
            if (x.first == y.first) return x.second < y.second;
            return x.first > y.first;
        });
        sort(B.begin(), B.end());
        vector<string> ret;
        for (auto e : A) {
            ret.push_back(to_string(e.first) + " " + e.second);
        }
        for (auto e : B) {
            ret.push_back("0 " + e.second);
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<int> lastYearSales(n), thisYearSales(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> lastYearSales[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> thisYearSales[i];
    }
    ChangeReport C;
    vector<string> res = C.produceReport(names, lastYearSales, thisYearSales);
    for (auto e : res) {
        cout << e << '\n';
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