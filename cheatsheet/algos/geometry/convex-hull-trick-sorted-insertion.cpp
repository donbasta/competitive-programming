
using ll = long long;

struct line {
	long long m, c; //y = mx + c
  line(long long _m, long long _c) : m(_m), c(_c) {}
  long long calc(long long x) {
    return m * x + c;
  }
  long double intersectX(const line& l) {
    return (long double) (c - l.c) / (l.m - m);
  }
}

deque<line> dq;
vector<int> ints(n);
iota(ints.begin(), ints.end(), 0);
auto cmp = [&dq](int idx, int x) {
	return dq[idx].meetX(dq[idx + 1]) < x;
};
dq.emplace_front(0, 0);
ll ans = 0;

for(int i = 1; i <= n; i++) {
	int idx = *lower_bound(ints.begin(), ints.begin() + dq.size() - 1, a[i].q, cmp);
	ll f = dq[idx].calc(...) //current value in dp
	line cur = line(...) //new line to be added
	while((int)dq.size() >= 2 && cur.meetX(dq[0]) >= dq[0].meetX(dq[1])) {
		dq.pop_front();
	}
	dq.push_front(cur);
}


