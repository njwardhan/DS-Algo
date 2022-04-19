// Problem Link: https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=0
// O(logN) average time, O(N) worst time and O(N) space

/*
    Following is the Binary Tree node structure:

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
*/
void Traversal(BinaryTreeNode<int> *root, int x, bool& flag)
{
	if(root == NULL)
		return;
	
	if(root->data == x)
		flag = true;
	else if(root->data < x)
		Traversal(root->right, x, flag);
	else
		Traversal(root->left, x, flag);
}

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    bool flag = false;
	Traversal(root, x, flag);
	return flag;
}