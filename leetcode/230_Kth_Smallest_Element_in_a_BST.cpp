 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        auto i = 0, v = 0;
        myInOrder(root, k, i, v);
        return v;
    }

private:
    void myInOrder(const TreeNode* root, const int k, int& i, int& v) {
        if (root == nullptr || i == k) return;
        myInOrder(root->left, k, i, v);
        ++i;
        if (i == k) {
            v = root->val;
            return;
        }
        myInOrder(root->right, k, i, v);
    }
};

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/*
    int getTreeSize( TreeNode* root )
    {
        // check if precalculated
        auto it = treeSizeMap.find(root);
        if( it != treeSizeMap.end() ) return it->second;

        // calculate
        int size = 1
                 + ( root->left ? getTreeSize( root->left ) : 0 )
                 + ( root->right ? getTreeSize( root->right ) : 0 );

        // save to cache
        treeSizeMap.emplace( root, size );

        return size;
    }

    int kthSmallest(TreeNode* root, int k) {

        // count left
        int count = root->left ? getTreeSize( root->left ) : 0;

        // is root
        if( count == k - 1 ) return root->val;

        // on the left
        if( count >= k ) return kthSmallest( root->left, k );
        // on the right
        if( count < k ) return kthSmallest( root->right, k - 1 - count );

    }

private:
    unordered_map<TreeNode*, int> treeSizeMap;
*/

/**
 * dfs in-order traverse: recursive
 */
 /*
    TreeNode* kth = nullptr;
    int count = 0;

    void dfs( TreeNode* root, int k )
    {
        // found
        if( kth ) return;

        // search left;
        if( root->left ) dfs( root->left, k );

        ++count;

        // found kth
        if( count == k )
        {
            kth = root;
        }

        // search right;
        if( root->right ) dfs( root->right, k );
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs( root, k );
        return kth->val;
    }
    */

    /**
     * dfs in-order traverse: iterator
     */

     int kthSmallest(TreeNode* root, int k) {
         stack<TreeNode*> s;

         int count = 0;
         while( true )
         {
             if( root == nullptr ) break;

             // cache left branch
             while( root->left )
             {
                 s.push( root );
                 root = root->left;
             }

            // process current root (left leaf)
            ++count;
            if( count == k ) return root->val;

            // process current's right
            if( root->right )
            {
                root = root->right;
            }
            else
            {
                // process parent root
                root = nullptr;
                while( root == nullptr && ( ! s.empty() ) )
                {
                    // process root
                    ++count;
                    if( count == k ) return s.top()->val;

                    // process right
                    root = s.top()->right;
                    s.pop();
                }
            }
         }

         return 0;
     }
};
