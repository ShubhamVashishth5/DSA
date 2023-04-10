/*
Given Array of size n and a number k, find all elements that appear more than n/k times
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int question[]= {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4, n=8;

// First approach using hashmaps
// SPACE COMPLEXITY: O(N)
// TIME COMPLEXITY: O(N)
    unordered_map<int, int> mp;
    for(int i =0; i <n; i++)
    {
        mp[question[i]]++;
    }
    for(auto i:mp)
    {
        if(i.second> n/k)cout<<i.first;
    }


// Second approach using MOORE's voting algorithm
// SPACE COMPLEXITY: O(K)
// TIME COMPLEXITY: O(N*K)
    int arr[1000];
    int arr2[1000];
    for(int i=0; i<k; i++)
    {
        arr2[i]=0;
        arr[i]=0;
    }

    int j;

    for(int i=0; i<n; i++)
    {

        for(j=0; j<k; j++)
        {

            if(arr2[j]==0)
            {
                arr[j]=question[i];
                arr2[j]++;
                break;
            }

            if(arr[j]==question[i])
            {
                arr2[j]++;
                break;
            }
        }

        if(j==k)
        {
            for(j=0; j<k; j++)
            {
                arr2[j]--;
            }
        }


    }


    for(int i=0; i<k; i++)
    {
        int count =0;
        for(int j=0; j<n; j++)
        {
            if(question[j]==arr[i])count++;
        }
        if(count> (n/k))cout<<arr[i];
    }

    return 0;
}
