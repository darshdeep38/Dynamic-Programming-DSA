#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        // Start from the second-to-last row and move upwards
        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                // Update the current cell with the minimum sum of the two possible paths
                triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        // The top element will hold the minimum path sum after the above steps
        return triangle[0][0];
    }
};
