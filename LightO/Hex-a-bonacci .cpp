//URL:   https://lightoj.com/problem/generating-palindromes
//Solution by: Subrata Biswas

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / __gcd(a, b) * b
#define mod 1000000007
#define TheAnt                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> dp;
int a, b, c, d, e, f;
int fn(int n)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6)) % 10000007;
}

signed main()
{
    TheAnt;
    int n, cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        cin >> a >> b >> c >> d >> e >> f >> n;
        dp.assign(n + 10, -1);
        cout << "Case " << caseno << ": " << fn(n) % 10000007 << '\n';
    }
    return 0;
}
