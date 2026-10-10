/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    private:
        TreeNode *root;
        queue<TreeNode *>q;

    public:
        CBTInserter(TreeNode* root) {
            this->root=root;
            q.push(root);

            while(!q.empty()){
                TreeNode *temp = q.front();

                if (temp->left != nullptr){
                    q.push(temp->left);
                }

                if (temp->right != nullptr){
                    q.push(temp->right);
                
                }

                if (temp->left == nullptr || temp->right == nullptr){
                    break;
                }

                q.pop();

            }
        }
        
        int insert(int val) {

            TreeNode *temp=q.front();
            TreeNode *newNode=new TreeNode(val);

            if(temp->left==nullptr){
                temp->left=newNode;
            }
            else{
                temp->right=newNode;
                q.pop();
            }

            q.push(newNode);

            return temp->val;
            
        }
        
        TreeNode* get_root() {
            return root;
        }
    };

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */