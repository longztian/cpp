/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string s(1, '[');
        mySerialize(root, s);
        s.back() = ']';
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() < 3 || data == "[N]") return nullptr;

        TreeNode dummy(0);
        std::vector<TreeNode*> stack(1, &dummy);

        const auto PE = data.data() + data.size() - 1;
        auto pb = data.data() + 1, pe = pb;
        TreeNode* p = nullptr;
        bool left = true;
        while (pb < PE) {
            if (*pb != 'N') {
                pe = std::find(pb, PE, ' ');
                p = new TreeNode(std::stoi(string(pb, pe)));

                if (left) {
                    stack.back()->left = p;
                } else {
                    stack.back()->right = p;
                    stack.pop_back();
                    if (stack.empty()) throw runtime_error("input error");
                    left = true;
                }
                stack.push_back(p);

                pb = pe + 1;
            } else {
                if (left) {
                    left = false;
                } else {
                    stack.pop_back();
                    if (stack.empty()) throw runtime_error("input error");
                }
                pb += 2;
            }
        }

        return dummy.left;
    }

private:
    void mySerialize(TreeNode* root, std::string& s) {
        if (root != nullptr) {
            s.append(std::to_string(root->val) + ' ');
            mySerialize(root->left, s);
            mySerialize(root->right, s);
        } else {
            s.append("N ");
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
