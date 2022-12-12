#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[31][31], fact[31];
ll ncr(ll n, ll k)
{
    if(k==1)
        return n;
    if(n==k)
        return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    if(k==0)
        return dp[n][n];

    return dp[n][k] = ncr(n-1, k-1) + ncr(n-1, k);
}
int main()
{
    ll i, j, k, t, n;
    scanf("%lld", &t);
    memset(dp, -1, sizeof(dp));
    fact[0] = 1;
    for(i=1;i<=30;i++)
        fact[i] = fact[i-1]*i;
    for(i=1;i<=t;i++){
        scanf("%lld%lld", &n, &k);
        if(k>n){
            printf("Case %lld: 0\n", i);
            continue;
        }
        ll ans = ncr(n, k) * ncr(n, k) * fact[k];

        printf("Case %lld: %lld\n", i, ans);

    }
    return 0;
}