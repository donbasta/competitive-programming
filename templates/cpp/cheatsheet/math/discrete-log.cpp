#include <bits/stdc++.h>

using namespace std;

/**
Baby Step - Giant Step Algorithm
cp algorithm
**/

int discrete_log(int a, int b, int m)
{
    int n = (int)sqrt(m + .0) + 1;
    int an = 1;
    for (int i = 1; i <= n; i++)
    {
        an = (1LL * an * a) % m;
    }

    map<int, int> val;
    for (int i = 1, p = an; i <= m / n + 1; i++, p = (1LL * p * an) % m)
    {
        val[p] = i;
    }

    for (int i = 0, q = b; i <= n; i++, q = (1LL * q * a) % m)
    {
        if (val.count(q))
        {
            return n * val[q] - i;
        }
    }

    return -1;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << discrete_log(a, b, m);
}
