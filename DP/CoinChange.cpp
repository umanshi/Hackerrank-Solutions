/*6 April 2018
Author : Umanshi Bakshi
3rd Year, 6th Sem
*/
#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
    long coinTill; long including, excluding;
    vector<vector<long>>arr(c.size(), vector<long>(n+1));  // Initializing a 2D Vector, yayyy! :D
    for (long i = 0; i<c.size(); i++)
        arr[i][0] = 1;  // To make amount 0, we have 1 way for each coinTill value
    
    // arr[coinTill][sum]  -> This is the format 
    for (long sum = 1; sum<=n; sum++)
    {   for (coinTill=0; coinTill<c.size(); coinTill++)
           {
            //including new coinTill -> new coin
            if(sum < c[coinTill] )
                including = 0;
            else
                including = arr[coinTill][sum-c[coinTill]];
            //excluding new coinTill -> new coin
            if(coinTill==0)
                excluding = 0;
            else 
                excluding = arr[coinTill-1][sum];
           
             arr[coinTill][sum] = including + excluding;
            }     
    }
    return arr[c.size()-1][n];
    
}

int main() {
    int n;  // amount
    int m;  // number of coins
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout<<ways;
    return 0;
}
