#include <bits/stdc++.h>
#define NooN int
using namespace std;
int a[10001];
int f[10001];
int main()
{
    int n;
    int len =0;
    memset(f,0x3f,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int pos = lower_bound(f+1, f+1+len,a[i]) - f;
        if(pos==len+1) 
        {
            len++;
        }
        f[len]=min(f[len],a[i]);
    }
    cout<<len;
    return 0;
}