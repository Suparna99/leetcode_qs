# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def nextElem(self,root):
        ptr = root
        while ptr and ptr.left:
            ptr = ptr.left
        return ptr
    
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:        
        if root is None:
            return root
        if root.val > key:
            root.left = self.deleteNode(root.left,key)
            return root
        if root.val < key:
            root.right = self.deleteNode(root.right,key)
            return root
        
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        nextEl = self.nextElem(root.right)
        root.val = nextEl.val
        root.right = self.deleteNode(root.right, nextEl.val)
        return root
