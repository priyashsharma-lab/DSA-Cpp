/*Leetcode: 88. Merge Sorted Arrays
Link: https://leetcode.com/problems/merge-sorted-array/

Approach 1: Brute force
Time: O(n^2)
Space:O(n)

Approach 2: Two Pointer
Time: O(n)
Space: O(1)


---------------Approach 1: Brute Force---------------*/
/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> x;
        int ptr1=0;
        int ptr2=0;
        while (ptr1<m && ptr2<n)
        {
            if (nums1[ptr1]>nums2[ptr2])
            {
                x.push_back(nums2[ptr2]);
                ptr2++;
            }
            else
            {
                x.push_back(nums1[ptr1]);
                ptr1++;
            }
        }
        while (ptr1<m)
        {
            x.push_back(nums1[ptr1]);
            ptr1++;
        }
        while (ptr2<n)
        {
            x.push_back(nums2[ptr2]);
            ptr2++;
        }
        nums1.clear();
        x.swap(nums1);
    }
};*/

// ---------------Approach 2: Two Pointer (Used)---------------
#include <bits/stdc++.h>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int ans=nums1.size()-1;
        int i=m-1;
        int j=n-1;
        while (j>=0)
        {
            if (i>=0 && nums1[i]>nums2[j])
            {
                nums1[ans]=nums1[i];
                i--;
                ans--;
            }
            else
            {
                nums1[ans]=nums2[j];
                j--;
                ans--;
            }
        }

    }
};