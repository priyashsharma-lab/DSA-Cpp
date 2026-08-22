/*Leetcode: 4. Median of Two Sorted Arrays
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/  */

//Brute Force
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int i=0;
        int j=0;
        List<Integer> a=new ArrayList<>();
        while (i<nums1.length && j<nums2.length)
        {
            if (nums1[i]<=nums2[j])
            {
                a.add(nums1[i]);
                i++;
            }
            else
            {
                a.add(nums2[j]);
                j++;
            }
        }    
        while (i<nums1.length)
        {
            a.add(nums1[i]);
            i++;
        }
        while (j<nums2.length)
        {
            a.add(nums2[j]);
            j++;
        }
        double median=-1;
        if (a.size()%2!=0)
        {
            median=(double)a.get(a.size()/2);
        }
        else
        {
            median=((double)(a.get(a.size()/2))+((double)(a.get(a.size()/2-1))))/2;
        }
        return median;
    }
}

// Better approach than brute force
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int i1 = (n + m) / 2;
        int i2 = (n + m) / 2 - 1;
        int eleAti1 = 0;
        int eleAti2 = 0;
        int i = 0;
        int j = 0;
        int count = -1;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                count++;
                if (count == i2) {
                    eleAti2 = nums1[i];
                }
                if (count == i1) {
                    eleAti1 = nums1[i];
                }
                i++;
            } else {
                count++;
                if (count == i2) {
                    eleAti2 = nums2[j];
                }
                if (count == i1) {
                    eleAti1 = nums2[j];
                }
                j++;
            }
        }
        while (i < n) {
            count++;
            if (count == i2) {
                eleAti2 = nums1[i];
            }
            if (count == i1) {
                eleAti1 = nums1[i];
            }
            i++;
        }
        while (j < m) {
            count++;
            if (count == i2) {
                eleAti2 = nums2[j];
            }
            if (count == i1) {
                eleAti1 = nums2[j];
            }
            j++;
        }
        double median=-1;
        if ((m+n)%2!=0)
        {
            median=(double)eleAti1;
        }
        else
        {
            median=((double)eleAti1+(double)eleAti2)/2;
        }
        return median;
    }
}

//Binary Search approach
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        // Always apply binary search on the smaller array
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.length;
        int n2 = nums2.length;

        int low = 0;
        int high = n1;

        int left = (n1 + n2 + 1) / 2;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = left - cut1;

            int l1 = (cut1 == 0)
                    ? Integer.MIN_VALUE
                    : nums1[cut1 - 1];

            int l2 = (cut2 == 0)
                    ? Integer.MIN_VALUE
                    : nums2[cut2 - 1];

            int r1 = (cut1 == n1)
                    ? Integer.MAX_VALUE
                    : nums1[cut1];

            int r2 = (cut2 == n2)
                    ? Integer.MAX_VALUE
                    : nums2[cut2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Total length is even
                if ((n1 + n2) % 2 == 0) {
                    return (Math.max(l1, l2) +
                            Math.min(r1, r2)) / 2.0;
                }

                // Total length is odd
                else {
                    return Math.max(l1, l2);
                }
            }

            // We need to move cut1 to the left
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // We need to move cut1 to the right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
}