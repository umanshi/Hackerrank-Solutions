/*
Interviewbit
You are given an Integer N.

You have to find how many different strings of length N can be made using Vowels (a, e, i, o, u) only and by following given rules :

‘a’ can only be followed by ‘e’ and ‘i’.

‘e’ can only be followed by ‘i’.

‘i’ can only be followed by ‘a’, ‘e’, ‘o’, and ‘u’.

‘o’ can only be followed by ‘a’ and ‘u’.

‘u’ can only be followed by ‘o’ and ‘e’.*/

int Solution::solve(int A) {
    
    if(A==1) return 5;
    if(A==2) return 11;
    
    unsigned long int dp[A+1][5];
    unsigned long int i;
    for( i=0;i<5;i++)
        {dp[1][i] = 1;}
    
    for(i=2; i<A+1;i++)
    {
        dp[i][0] = dp[i-1][2]%1000000007+dp[i-1][3]%1000000007;
        dp[i][1] = dp[i-1][0]%1000000007+dp[i-1][2]%1000000007+dp[i-1][4]%1000000007;
        dp[i][2] = dp[i-1][0]%1000000007+dp[i-1][1]%1000000007;
        dp[i][3] = dp[i-1][2]%1000000007+dp[i-1][4]%1000000007;
        dp[i][4] = dp[i-1][2]%1000000007+dp[i-1][3]%1000000007;
    }
    unsigned long int sum = 0;
    for( i=0; i<5; i++)
        {
            sum+=dp[A][i]%(1000000007);
        }
    return (sum%(1000000007));
}
