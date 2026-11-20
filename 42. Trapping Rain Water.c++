class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (l < r) {
            if (height[l] < height[r]) {              // left side is the weaker wall
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];         // water sitting on bar l
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];        // water sitting on bar r
                r--;
            }
        }
        return water;
    }
};
