#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 256;

vector<int> sortCyclicShifts(string const& s) {
    int n = s.length();
    int charSize = N;

    vector<int> p(n), c(n), cnt(max(charSize, n), 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < charSize; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int numClass = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            numClass++;
        c[p[i]] = numClass - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + numClass, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < numClass; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        numClass = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = make_pair(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]);
            if (cur != prev)
                numClass++;
            cn[p[i]] = numClass - 1;
        }
        c.swap(cn);
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    s += '$';
    vector<int> suf = sortCyclicShifts(s);
    int len = (int)suf.size();

    int q;
    cin >> q;
    while (q--) {
        string que;
        cin >> que;
        int queLen = (int)que.length();
        int le, ri, ans1 = -1, ans2 = -1;
        le = 1, ri = len - 1;
        while (le <= ri) {
            int mid = (le + ri) >> 1;
            int pos = suf[mid];
            string temp = "";
            int cnt = 0, idx = 0;
            while (cnt < queLen) {
                if (s[(pos + idx) % len] != '$') {
                    temp += s[(pos + idx) % len];
                    cnt++;
                } else {
                    break;
                }
                idx++;
            }
            if (temp < que) {
                le = mid + 1;
            } else if (temp > que) {
                ri = mid - 1;
            } else if (temp == que) {
                ans1 = mid;
                ri = mid - 1;
            }
        }
        le = 1, ri = len - 1;
        while (le <= ri) {
            int mid = (le + ri) >> 1;
            int pos = suf[mid];
            string temp = "";
            int cnt = 0, idx = 0;
            while (cnt < queLen) {
                if (s[(pos + idx) % len] != '$') {
                    temp += s[(pos + idx) % len];
                    cnt++;
                } else {
                    break;
                }
                idx++;
            }
            if (temp < que) {
                le = mid + 1;
            } else if (temp > que) {
                ri = mid - 1;
            } else if (temp == que) {
                ans2 = mid;
                le = mid + 1;
            }
        }
        if (ans1 == -1 || ans2 == -1) {
            cout << 0;
        } else {
            cout << ans2 - ans1 + 1;
        }
        cout << '\n';
    }

    return 0;
}
