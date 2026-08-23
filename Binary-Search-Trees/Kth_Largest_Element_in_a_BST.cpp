// Approach:
// Reverse inorder traversal (Right -> Root -> Left)
// visits BST nodes in descending order.
// Therefore, the kth visited node is the kth largest element.
//
// Time Complexity: O(n)
// Space Complexity: O(h)

// Code :-

class Solution {
public:
    int ans;

    void reverseinorder(Node* root, int& k) {
        if (root == NULL) return;

        reverseinorder(root->right, k);

        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }

        reverseinorder(root->left, k);
    }

    int kthLargest(Node* root, int k) {
        reverseinorder(root, k);
        return ans;
    }
};