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

function levelOrder(root: TreeNode | null): number[][] {
    const ans: number[][] = [];
    if (!root) {
        return ans;
    }
    const q: TreeNode[] = [root];
    while (q.length) {
        const t: number[] = [];
        const qq: TreeNode[] = [];
        for (const { val, left, right } of q) {
            t.push(val);
            left && qq.push(left);
            right && qq.push(right);
        }
        ans.push(t);
        q.splice(0, q.length, ...qq);
    }
    return ans;
}
