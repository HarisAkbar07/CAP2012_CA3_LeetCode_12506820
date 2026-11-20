class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1); // search the smaller array

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;

        while (lo <= hi) {
            int i = (lo + hi) / 2;             // how many elements nums1 gives to the left half
            int j = (m + n + 1) / 2 - i;       // how many nums2 gives to the left half

            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];   // last element of left part
            int R1 = (i == m) ? INT_MAX : nums1[i];       // first element of right part
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int R2 = (j == n) ? INT_MAX : nums2[j];

            if (L1 <= R2 && L2 <= R1) {        // valid split found
                if ((m + n) % 2) return max(L1, L2);
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
            if (L1 > R2) hi = i - 1;           // took too many from nums1
            else lo = i + 1;                   // took too few from nums1
        }
        return 0.0;
    }
};
