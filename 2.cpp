#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int val[n+1][n+1];

    int dp[n+1][n+1];

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[i][j]=j-i+1;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        val[i][i] = a;
        //cout<<a<<endl;
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j+i-1<=n;j++)
        {
            int r=j+i-1;
            for(int k=j;k<r;k++){
                dp[j][r] = min(dp[j][r], dp[j][k]+dp[k+1][r]);
                if( dp[j][k] == 1 && dp[k+1][r] == 1 && val[j][k] == val[k+1][r] )
                    dp[j][r] = 1,val[j][r] = val[j][k] + 1;
            }
        }
    }
    
    cout<<dp[1][n]<<endl;
}