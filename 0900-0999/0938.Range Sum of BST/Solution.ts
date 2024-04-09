/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    const dfs = (root: TreeNode | null): number => {
        if (!root) {
            return 0;
        }
        const { val, left, right } = root;
        let ans = low <= val && val <= high ? val : 0;
        if (val > low) {
            ans += dfs(left);
        }
        if (val < high) {
            ans += dfs(right);
        }
        return ans;
    };
    return dfs(root);
}
