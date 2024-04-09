# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestNodes(
        self, root: Optional[TreeNode], queries: List[int]
    ) -> List[List[int]]:
        def dfs(root: Optional[TreeNode]):
            if root is None:
                return
            dfs(root.left)
            nums.append(root.val)
            dfs(root.right)

        nums = []
        dfs(root)
        ans = []
        for x in queries:
            i = bisect_left(nums, x + 1) - 1
            j = bisect_left(nums, x)
            mi = nums[i] if 0 <= i < len(nums) else -1
            mx = nums[j] if 0 <= j < len(nums) else -1
            ans.append([mi, mx])
        return ans
