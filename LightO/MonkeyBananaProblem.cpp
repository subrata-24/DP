//URL:   https://lightoj.com/problem/monkey-banana-problem
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

int calc(int x, int y, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (x < 0 || y < 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    return dp[x][y] = max((v[x][y] + calc(x - 1, y, v, dp)), v[x][y] + calc(x, y - 1, v, dp));
}
signed main()
{
    TheAnt;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n), dp(n, vector<int>(n, -1));

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x = cnt;
            for (int j = 0; j <= i; j++)
            {
                int a;
                cin >> a;
                v[x].pb(a);
                x--;
            }
            cnt++;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            int x = n - 1;
            for (int j = 1; j <= i; j++)
            {
                int a;
                cin >> a;
                v[x].pb(a);
                x--;
            }
        }

        int ans = calc(n - 1, n - 1, v, dp);
        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
