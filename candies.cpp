#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int candies(int n, int arr_size, int* arr) {
    long int count = 0;
    long int candies[n]; 
     if(n==1)
        return 1;
    if(n==2 && (arr[0]!=arr[1]))
        return 3;
    for (long int i=0; i<n; i++)
        candies[i]=1;
    
    for (long int i=1; i<n; i++) //checking left side // Am I bigger than the element to my left side?
    {
        if(arr[i]>arr[i-1])  
        {
            candies[i]=candies[i-1]+1;
        }
    }
    for (long int i=n-2; i>=0; i--)   //checking right side // Am I bigger than the element to my right side?
    {
        if(arr[i]>arr[i+1] && candies[i+1]>=candies[i])
        {
            candies[i] = candies[i+1]+1;
           // count++;
        }
    }
    for(long int i=0; i<n; i++)
    {
        count+= candies[i];
    }
    return count;
}

int main() {
    long int n; 
    scanf("%ld", &n);
    int *arr = malloc(sizeof(int) * n);
    for (long int arr_i = 0; arr_i < n; arr_i++) {
       scanf("%ld",&arr[arr_i]);
    }
   
    long int result = candies(n, n, arr);
    printf("%ld\n", result);
    return 0;
}
