/*Leetcode: 121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

Approach 1:  Brute force
Time: O(n^2)
Space:O(1)

Approach 2: Without Hashmap
Time: O(n)
Space: O(1)

*/

// ---------------Approach 1: Brute Force---------------

/*class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0;
        int maxProfit=0;
        int size=prices.size();
        for (int i=0;i<size-1;i++)
        {
            for (int j=i+1;j<size;j++)
            {
                profit=prices[j]-prices[i];
                if (profit>maxProfit)
                {
                    maxProfit=profit;
                }
            }
        }
        return maxProfit;
    }
};*/

// ---------------Approach 2: Two Pointer---------------
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int l=0;
        int r=1;
        int profit=0;
        int maxProfit=0;
        while (r<prices.size())
        {
            profit=prices[r]-prices[l];
            if (profit>maxProfit)
            {
                maxProfit=profit;
            }
            if (prices[l]>prices[r])
            {
                l=r;
                // l++;
                // continue; this l++ and continue can be used but its a waste of time so just do l=r (i made like this when concept building then later reliased so ya)
            }
            r++;
        }
        return maxProfit;
    }
};

// main idea is start pointers from same side ie left and increment r everytime but increment l only when prices[l]>prices[r] and keep incrementing l until prices[l]<prices[r] 

