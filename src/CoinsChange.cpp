#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getNoOfWays(int* a,int n,int sum,int** dp)
{
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    else
    if(sum < 0 )// negative sum or no coins
        return 0;
    else if( sum>=1 && n <=0 )
        return 0;
    else if(sum==0) // 0 sum. No coins. 1 solution.
        return 1;
     else
    {
        dp[n][sum] = getNoOfWays(a,n,sum-a[n-1],dp)+getNoOfWays(a,n-1,sum,dp);
        return dp[n][sum];
    }
}

int getNoOfWays(int* a,int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            dp[i][j] = -1;
    }
    return getNoOfWays(a,n,sum,dp);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int C;
    cin >> N;
    cin >> C;
    int* coinsArr = new int[C];
    for(int i=0;i<C;i++)
        cin >> coinsArr[i];
    
    cout << getNoOfWays(coinsArr,C,N);
    
    return 0;
}

