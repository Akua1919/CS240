#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int point[201][201],black_x[40001],black_y[40001],indicate[40001],edge_black[40001];

bool find_match(int i,int n)
{
    int k = 0;
    if (black_x[i]+1 >=1 && black_y[i]+2 >= 1 && black_x[i]+1 <= n && black_y[i]+2 <= n && point[black_x[i]+1][black_y[i]+2] !=-1)
    {
        k=point[black_x[i]+1][black_y[i]+2];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]+1 >=1 && black_y[i]-2 >= 1 && black_x[i]+1 <= n && black_y[i]-2 <= n && point[black_x[i]+1][black_y[i]-2] !=-1)
    {
        k=point[black_x[i]+1][black_y[i]-2];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]-1 >=1 && black_y[i]+2 >= 1 && black_x[i]-1 <= n && black_y[i]+2 <= n && point[black_x[i]-1][black_y[i]+2] !=-1)
    {
        k=point[black_x[i]-1][black_y[i]+2];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]-1 >=1 && black_y[i]-2 >= 1 && black_x[i]-1 <= n && black_y[i]-2 <= n && point[black_x[i]-1][black_y[i]-2] !=-1)
    {
        k=point[black_x[i]-1][black_y[i]-2];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]+2 >=1 && black_y[i]+1 >= 1 && black_x[i]+2 <= n && black_y[i]+1 <= n && point[black_x[i]+2][black_y[i]+1] !=-1)
    {
        k=point[black_x[i]+2][black_y[i]+1];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]+2 >=1 && black_y[i]-1 >= 1 && black_x[i]+2 <= n && black_y[i]-1 <= n && point[black_x[i]+2][black_y[i]-1] !=-1)
    {
        k=point[black_x[i]+2][black_y[i]-1];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]-2 >=1 && black_y[i]+1 >= 1 && black_x[i]-2 <= n && black_y[i]+1 <= n && point[black_x[i]-2][black_y[i]+1] !=-1)
    {
        k=point[black_x[i]-2][black_y[i]+1];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    if (black_x[i]-2 >=1 && black_y[i]-1 >= 1 && black_x[i]-2 <= n && black_y[i]-1 <= n && point[black_x[i]-2][black_y[i]-1] !=-1)
    {
        k=point[black_x[i]-2][black_y[i]-1];
        if ( !indicate[k])
        {
            int bp=edge_black[k];
            edge_black[k]=i;
            indicate[k]=1;
            if (!bp || find_match(bp,n)) 
            {
                return true;
            }
            edge_black[k]=bp;
        }
    }
    return false;
}

int main()
{
    //cout<<point[0][0]<<endl;
    int m,n;
    scanf("%d %d",&n,&m);

    for (int k = 1; k <= m; k++)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        point[i][j] = -1;
    }

    int black_index = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (point[i][j] != -1)
            {
                point[i][j] = (i-1)*n+j;
                if ((i+j)%2 == 0)
                {
                    black_x[black_index] = i;
                    black_y[black_index] = j;
                    black_index ++;
                }
            }
        }
    }

    int match = 0;
    for (int i = 1; i < black_index; i++)
    {
        if (find_match(i,n))
        {
            memset(indicate,0,sizeof(indicate));
            match++;
        }
    }
    //cout<< match <<endl;
    cout<< n*n-m-match <<endl;
}