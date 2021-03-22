#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

char graph[51][51];
int dp[51][51][51][51];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",graph[i]+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (graph[i][j] == '#')
            {
                dp[i][j][i][j] = 1;
            }
            else
            {
                dp[i][j][i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j+i-1<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l+k-1<=n;l++){
                    if (i !=1 || k != 1)
                    {
                        dp[j][l][j+i-1][l+k-1]=max(i,k);
                    }  
                    for(int m=j;m<j+i-1;m++)
                    {
                        dp[j][l][j+i-1][l+k-1]=min(dp[j][l][j+i-1][l+k-1],dp[j][l][m][l+k-1]+dp[m+1][l][j+i-1][l+k-1]);
                    }
                    for(int m=l;m<l+k-1;m++)
                    {
                        dp[j][l][j+i-1][l+k-1]=min(dp[j][l][j+i-1][l+k-1],dp[j][l][j+i-1][m]+dp[j][m+1][j+i-1][l+k-1]);
                    }
                }
            }
        }
    }
    
    cout<< dp[1][1][n][n]<<endl;
    return 0;
}
