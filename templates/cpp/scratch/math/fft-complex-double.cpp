
using ld = long double;
using cd = complex<long double>;
const long double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i++) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (auto x : a) {
            x /= n;
        }
    }
}

vector<int> mul(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + b.size()) {
        n <<= 1;
    }
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = round(fa[i].real());
    }
    return res;
}

vector<int> fastexpo(const vector<int>& a, int b) {
    if (b == 0) return {1};
    if (b == 1) return a;
    vector<int> temp = fastexpo(a, b / 2);
    temp = mul(temp, temp);
    if (b & 1)
        temp = mul(temp, a);
    return temp;
}