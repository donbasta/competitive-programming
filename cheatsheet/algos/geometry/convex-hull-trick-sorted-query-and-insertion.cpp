
//queries are in descending order
//slope are inserted in descending order also

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
dq.push_front(make_pair(0, 0));
long long ans = 0;
for(int i = 1; i <= n; i++) {
  long long cur; //current query to be processed
  while((int)dq.size() >= 2 && dq.back().calc(cur) <= dq[dq.size() - 2].calc(cur)) {
    dq.pop_back();
  }
  long long f = dq.back().calc(cur) + //another function outside the line
  ans = max(ans, f) //updating the dp value
  line next = line( ) //insert create new line's parameter here
  while((int)dq.size() >= 2 && next.intersectX(dq[0]) >= dq[0].intersectX(dq[1])) {
    dq.pop_front();
  }
  dq.push_front(next);
}

noice;