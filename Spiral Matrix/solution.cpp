#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    void rotate(int vec[2])
    {
        int tmp;
        tmp = 1 * vec[1];
        vec[1] = -1 * vec[0];
        vec[0] = tmp;
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> output;
        int currentDistance, nextDistance;
        int velocity[2] = {0, 1};
        int offset[2] = {1, -1};
        int position[2] = {0, 0};
        bool flag;
        nextDistance = matrix.size();
        if (nextDistance == 0)
        {
            return output;
        }
        currentDistance = matrix[0].size();
        while (nextDistance > 0)
        {
            for (int i = 0; i < currentDistance; ++i)
            {
                output.push_back(matrix[position[0]][position[1]]);
                position[0] += velocity[0];
                position[1] += velocity[1];
            }
            // printf("before rotation:position=(%d,%d)\n", position[0], position[1]);
            // printf("before rotation:velocity=(%d,%d)\n", velocity[0], velocity[1]);
            // printf("before rotation:offset=(%d,%d)\n", offset[0], offset[1]);
            // printf("before rotation:(currentDistance, nextDistance)=(%d,%d)\n", currentDistance, nextDistance);
            position[0] += offset[0];
            position[1] += offset[1];
            rotate(velocity);
            rotate(offset);
            nextDistance--;
            int tmp = currentDistance;
            currentDistance = nextDistance;
            nextDistance = tmp;
            // printf("after rotation:position=(%d,%d)\n", position[0], position[1]);
            // printf("after rotation:velocity=(%d,%d)\n", velocity[0], velocity[1]);
            // printf("after rotation:offset=(%d,%d)\n", offset[0], offset[1]);
            // printf("after rotation:(currentDistance, nextDistance)=(%d,%d)\n", currentDistance, nextDistance);
        }
        return output;
    }
};
