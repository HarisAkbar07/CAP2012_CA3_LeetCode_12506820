class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        // The four walls of the area we have NOT visited yet
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        // Keep peeling the matrix layer by layer while some area is left
        while (top <= bottom && left <= right) {

            // 1) Walk LEFT -> RIGHT along the top row
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;                       // top row is done, so the top wall moves down

            // 2) Walk TOP -> BOTTOM along the right column
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;                     // right column is done, so the right wall moves left

            // 3) Walk RIGHT -> LEFT along the bottom row
            // Only do this if a row still exists. Otherwise we would
            // visit the same row twice (happens with a single row).
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;                // bottom row is done, so the bottom wall moves up
            }

            // 4) Walk BOTTOM -> TOP along the left column
            // Only do this if a column still exists. Otherwise we would
            // visit the same column twice (happens with a single column).
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;                  // left column is done, so the left wall moves right
            }
        }
        return result;
    }
};
