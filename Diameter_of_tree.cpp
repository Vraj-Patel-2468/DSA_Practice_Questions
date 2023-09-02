class Solution {
  private:
    int height(Node* root, int &num) {
        if(root==nullptr) return 0;
        else {
            int l = height(root->left, num);
            int r = height(root->right, num);
            num = max(l+r,num);
            return 1 + max(l,r);
        }
    }
  public:
    int diameter(Node* root) {
        if(root==nullptr) return 0;
        else {
            int num = INT_MIN;
            height(root, num);
            return num;
        }
    }
};