/* O(N^2) solution for findng the length of Longest Increasing Subsequence 
 * A better solution with O(NlogN) also exists.
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int longestIncreasingSubsequence(vector <int> arr) {
        vector<int> count(arr.size(), 1);
        for(int i=0; i<arr.size(); i++)
            {
                for(int j=0; j<i; j++)
                   {
                       if(arr[j]<arr[i])
                       {   if(count[j]+1>count[i])
                               count[i] = count[j]+1;
                       }
                   }
            }    
        int max = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(count[i]>max)
                max = count[i];
        }
        return max;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {   int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        if(n==0)  cout<<"0\n";
        else if(n==1) cout<<"1\n";
        else 
            {
            int result = longestIncreasingSubsequence(arr);
            cout <<result<<endl;
            }
    }
    return 0;
}
