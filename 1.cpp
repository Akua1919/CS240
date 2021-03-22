#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void recursion(int i,int n,int balance[],int acc, int &num)
{
    if (acc >= num)
    {
        return;
    }
    while (i < n && balance[i] == 0)
    {
        i++;
    }
    if (i == n)
    {
        num = min(num,acc);
        return;
    }
    for (int j = i+1; j < n; j++)
    {
        if (balance[j]*balance[i] < 0)
        {
            balance[j] += balance[i];
            recursion(i+1,n,balance,acc+1,num);
            balance[j] -= balance[i]; 
        }
    }
}

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

    int num = 9999;
    recursion(0,n,balance,0,num);

    cout<<num<<endl;

}