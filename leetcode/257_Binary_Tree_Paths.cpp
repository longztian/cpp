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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> curr;
        vector<string> all;

        if (root) {
            curr.push_back(root->val);
            myPreOrder(root, curr, all);
        }

        return all;
    }

private:
    void myPreOrder(TreeNode* root, vector<int>& curr, vector<string>& all) {
        if (!root->left && !root->right) {
            if (!curr.empty()) {
                stringstream ss;
                auto it = curr.begin();
                ss << *it++;
                for (auto ite = curr.end(); it != ite; ++it) {
                    ss << "->" << *it;
                }
                all.push_back(ss.str());
            }
        }

        if (root->left) {
            curr.push_back(root->left->val);
            myPreOrder(root->left, curr, all);
            curr.pop_back();
        }

        if (root->right) {
            curr.push_back(root->right->val);
            myPreOrder(root->right, curr, all);
            curr.pop_back();
        }
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

    vector<vector<int>> dfs( TreeNode* root )
    {
        vector<vector<int>> path, subpaths;
        if( root->left == nullptr && root->right == nullptr ) return vector<vector<int>>( root->val );

        if( root->left )
        {
            subpaths = dfs( root->left );
            path.insert( path.end(), subpaths.begin(), subpaths.end() );
        }
        if( root->right )
        {
            subpaths = dfs( root->right );
            path.insert( path.end(), subpaths.begin(), subpaths.end() );
        }

        for( auto p = path.data(), e = p + path.size(); p < e; ++p )
        {
            p->push_back( root->val );
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if ( root == nullptr ) return vector<string>();

        vector<vector<int>> paths = dfs( root );

        vector<string> ret;
        stringstream ss;
        for( auto p = paths.data(), e = p + paths.size(); p < e; ++p )
        {
            ss << p->back();
            for( auto pV = p->data() + p->size() - 2, pVE = p->data() - 1; pV > pVE; --pV )
            {
                ss << "->" << *pV;
            }

            ret.push_back( ss.str() );

            // clear ss
            ss.str("");
            ss.clear();
        }

        return ret;
    }
};
