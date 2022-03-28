#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[10010];
int dp[10010][110];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            num[i]=abs(num[i]);
        }
        dp[1][num[1]%m]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(dp[i-1][j]){
                    dp[i][(j+num[i])%m]=1;
                    dp[i][((j-num[i]+m)%m+m)%m]=1;
                }
            }
        }
        if((dp[n][0]==1)){
            printf("Divisible\n");
        }
        else{
            printf("Not divisible\n");
        }
    }
    return 0;
}