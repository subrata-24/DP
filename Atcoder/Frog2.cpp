//URL: https://atcoder.jp/contests/dp/tasks/dp_b
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

const int N = 1e5 + 10;
vector<int> v(N);
vector<int> dp(N, -1);

int calc(int idx, int k)
{
    if (idx == 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int ways = INT_MAX;
    for (int i = 1; i <= k; i++)
        if (idx - i >= 0)
            ways = min(ways, calc(idx - i, k) + abs(v[idx] - v[idx - i]));

    return dp[idx] = ways;
}
signed main()
{
    TheAnt;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = calc(n - 1, k);

    cout << ans << '\n';
    return 0;
}
