#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const string ans[] = {"Ashishgup", "FastestFinger"};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    if(n == 1)
      cout << ans[1];
    else if(n > 1) {
      if(n & 1)
        cout << ans[0];
      else if(n % 4 == 0) {
        if((n & (n - 1)) == 0) {
          cout << ans[1];
        } else {
          cout << ans[0];
        }
      } else {
        n /= 2;
        assert(n & 1);
        int pr = 0;
        for(int i = 3; i * i <= n; i += 2) {
          while(n % i == 0) {
            n /= i;
            pr++;
          }
        }
        if(n > 1) {
          // assert(pr == 0);
          pr += 1;
        }
        if(pr == 0) {
          cout << ans[0];
        } else if(pr == 1) {
          cout << ans[1];
        } else {
          cout << ans[0];
        }
      }
    } 
    cout << '\n';
  }

  return 0;
}
