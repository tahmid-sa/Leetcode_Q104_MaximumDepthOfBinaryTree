#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepthHelper(TreeNode* root, int& max, int& currMax) {
    if (root != nullptr) {
        currMax++;

        maxDepthHelper(root->left, max, currMax);

        if (max < currMax) {
            max = currMax;
        }

        maxDepthHelper(root->right, max, currMax);
        currMax--;
    }

    return max;
}

int maxDepth(TreeNode* root) {
    int max = 0, currMax = 0;

    return maxDepthHelper(root, max, currMax);
}

int main()
{
    TreeNode n5(5, nullptr, nullptr);
    TreeNode n15(15, &n5, nullptr);
    TreeNode n7(7, nullptr, nullptr);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9, nullptr, nullptr);
    TreeNode n3(3, &n9, &n20);

    cout << maxDepth(&n3);

    return 0;
}
