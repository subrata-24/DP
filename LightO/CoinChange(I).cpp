//URL:   https://lightoj.com/problem/coin-change-i
//Solution by: Subrata Biswas

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / __gcd(a, b) * b
#define mod 100000007
#define TheAnt                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dp[1010][60][30];
vector<int> v, c;

long long calc(int limit, int idx, int j)
{
    if (limit == 0)
        return 1;
    if (limit < 0 || idx < 0)
        return 0;

    if (dp[limit][idx][j] != -1)
        return dp[limit][idx][j];

    long long ans = 0;
    if (j < c[idx])
        ans = (ans + calc(limit - v[idx], idx, j + 1)) % mod;

    ans = (ans + calc(limit, idx - 1, 0)) % mod;

    return dp[limit][idx][j] = ans % mod;
}

signed main()
{
    TheAnt;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n, k, x = 25;
        cin >> n >> k;
        v.assign(n, 0);
        c.assign(n, 0);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 0; i < n; i++)
            cin >> c[i];

        int ans = calc(k, n - 1, 0);

        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
