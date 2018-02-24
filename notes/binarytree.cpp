/*
BINARY TREES
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
- empty binary tree
- left pointer points to a binary tree
- right pointer points to a binary tree.
upside down tree basically
Roots are on top
leaves are bottom most part of the tree
branches are inbetween root and leaves
very last nodes(leaves at bottom of tree) point to NULL;

root            0
              /  \
             0    0        one side of the binary tree can be bigger than the
           /  \  / \       then the other side and branch on it own.
leaves    0   0 0  0      left and right pointer would point to null
        / \    NULL
       0  0
       NULL
*/
struct binTreeNode
{
        int data
        binTreeNode * left
        binTreeNode * right
};
/*
                    8
                  /   \
                 3     7
               /  \   /  \
             9    4  1    NULL
 */
 void preporder(binTreeNode * r)
 {
     if(r!= NULL)
     {
         cout << r->data << endl;
         preorder(r->left);
         preorder(r->right);
     }
 }
//first         8
//second      3
//third      9
// r now = null and returns;
//then prints out 4
//next r  = 8 node and goes right.
// prints  7
// prints 1
// r then points to NULL
// end print

//n -ary tree means 3 or more branches on a binary tree
// binary tree means 2 branches on a binary tree

//recursive ways to traverse binary trees
// pre order  - binary tree
// post order - n-ary TREES
// inorder  -- binary tree

// not recursive - uses a queue binary or n-ary tree
//level order
