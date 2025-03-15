//URL: https://atcoder.jp/contests/dp/tasks/dp_c
//Solution  by: Subrata Biswas

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

int calc(int x, int y, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (x < 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    return dp[x][y] = max((v[x][y] + calc(x - 1, (y + 1) % 3, v, dp)), (v[x][y] + calc(x - 1, (y + 2) % 3, v, dp)));
}
signed main()
{
    TheAnt;
    int n;
    cin >> n;
    vector<vector<int>> vp(n), dp(n, vector<int>(3, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            vp[i].pb(a);
        }
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans = max(ans, calc(n - 1, i, vp, dp));

    cout << ans << '\n';
    return 0;
}
