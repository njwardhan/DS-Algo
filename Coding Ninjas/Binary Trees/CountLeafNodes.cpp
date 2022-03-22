// Question Link: https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTab=1
// O(N) time and constant space solution, where N = number of nodes in the Binary Tree

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void Traversal(int& count, BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return;
    
    if(root->right == NULL and root->left == NULL)
        count++;

    Traversal(count,root->left);
    Traversal(count,root->right);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0;
    Traversal(count, root);
    return count;
}