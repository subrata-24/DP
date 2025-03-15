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

string s;
const int N = 110;
int dp[110][110];
int calc(int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s[i] != s[j])
        ans += 1 + min(calc(i + 1, j), calc(i, j - 1));
    else
        ans += calc(i + 1, j - 1);
    return dp[i][j] = ans;
}
signed main()
{
    TheAnt;
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        int ans = calc(0, s.size() - 1);

        cout << "Case " << tt << ": " << ans << '\n';
    }
    return 0;
}
