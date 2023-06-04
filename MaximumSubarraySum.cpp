#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maximum = LONG_MIN;
    long long sum= 0;

    for(int i=0; i<n; i++){
        sum+= arr[i];

        if(sum<0){
            sum = 0;
        }

        if(sum>maximum){
            maximum = sum;

        }

        
    }
    return maximum;
}
