#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int balance[n];

    memset(balance,0,sizeof(balance));

    for (int k = 0; k < m; k++)
    {
        int i,j,t;
        scanf("%d %d %d", &i, &j,&t);
        balance[i] += t;
        balance[j] -= t;
    }

    int amounts[n];
    int N =1;
    for (int i = 0; i < n; i++)
    {
        if (balance[i] !=0)
        {
            amounts[N] = balance[i];
            N++;
        }
    }
    cout<<N<<endl;

    int dp[1<<N];
    int sum[1<<N];
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));

    for (int i = 0; i < 1<<N; i++)
    {
        int set_bit =1;
        for (int j = 0; j < N; j++)
        {
            if (i && set_bit ==0)
            {
                int nxt = i | set_bit;
                cout<< nxt<<endl;
                sum[nxt] = sum[i] + amounts[j];
                if (sum[nxt] == 0)
                {
                   dp[nxt] = max(dp[nxt],dp[i]+1);
                }
                else
                {
                    dp[nxt] = max(dp[nxt],dp[i]);
                }
            }
            set_bit <<= 1;
        }
    }

    cout<< N-dp[1<<N -1]<<endl;
}