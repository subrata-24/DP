//URL: https://cses.fi/problemset/task/1633
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

const int N = 1e6 + 10;
vector<int> dp(N, -1);
int calc(int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans = (calc(sum - i) + ans) % mod;
    }
    return dp[sum] = ans;
}
signed main()
{
    TheAnt;
    int n;
    cin >> n;
    int ans = calc(n);

    cout << ans << '\n';
    return 0;
}
