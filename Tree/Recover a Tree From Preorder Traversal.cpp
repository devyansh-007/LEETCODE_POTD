class Solution {
public:
    int n;
    TreeNode* f(string& traversal,int& i,int depth){
        if(i>=n) return NULL;
        int j = i;
        while(j<n && traversal[j] == '-'){
            j++;
        }
        int dash = j - i;

        if(dash != depth) return NULL;

        i += dash;

        int val = 0;
        
        while(i<n && isdigit(traversal[i])){
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(val);

        root->left = f(traversal,i,depth+1);
        root->right = f(traversal,i,depth+1);

        return root;


    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0;
        return f(traversal,i,0);
    }
};
