//URL: https://atcoder.jp/contests/dp/tasks/dp_a
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

const int N = 1e3 + 10;
vector<string> vs(N);
int dp[N][N];

int calc(int i, int j)
{
    if (vs[i][j] == '*')
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (i - 1 >= 0)
        ans = (ans + calc(i - 1, j)) % mod;
    if (j - 1 >= 0)
        ans = (ans + calc(i, j - 1)) % mod;

    return dp[i][j] = ans;
}
signed main()
{
    TheAnt;
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        cin >> vs[i];
    int ans = calc(n - 1, n - 1);

    cout << ans << '\n';
    return 0;
}
