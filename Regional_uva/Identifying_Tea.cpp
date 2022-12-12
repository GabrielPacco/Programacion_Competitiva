#include<cstdio>

int main()
{
    int tea,i,ans=0,n;
    while(scanf("%d",&tea)!=EOF){
    for(i=0; i<5; i++)
    {
        scanf("%d",&n);
        if(n==tea)ans++;
    }
    printf("%d\n",ans);
    ans=0;
    }
    return 0;
}