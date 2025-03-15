//URL: https://atcoder.jp/contests/dp/tasks/dp_d
//Solution  by: Subrata Biswas

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define Wrong                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll N = 110;
vector<ll> w(N), val(N);
vector<vector<ll>> dp(N, vector<ll>(1e5 + 5, -1));
ll calc(ll i, ll limt)
{
    if (i < 0 || limt <= 0)
        return 0;

    if (dp[i][limt] != -1)
        return dp[i][limt];

    ll skip = calc(i - 1, limt);
    ll pick = 0;

    if (limt >= w[i])
        pick = calc(i - 1, limt - w[i]) + val[i];

    return dp[i][limt] = max(skip, pick);
}

int main()
{
    Wrong;
    ll n, limt;
    cin >> n >> limt;

    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
        cin >> val[i];
    }

    ll ans = calc(n - 1, limt);
    cout << ans << '\n';
    return 0;
}
