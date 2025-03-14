#include <iostream>
#include <string>

using namespace std;

// Node Tree
struct TreeNode {
    int index;
    string name;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int idx, string nm) : index(idx), name(nm), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->index == root2->index && root1->name == root2->name)
        return areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
    else
        return false;
}

int main() {
    TreeNode* tree1 = new TreeNode(1, "Chapter 1");
    tree1->left = new TreeNode(2, "Section 1.1");
    tree1->right = new TreeNode(3, "Section 1.2");
    
    TreeNode* tree2 = new TreeNode(1, "Chapter 1");
    tree2->left = new TreeNode(2, "Section 1.1");
    tree2->right = new TreeNode(3, "Section 1.2");

    if (areIdentical(tree1, tree2))
        cout << "Hai cay nhi phan copy cua nhau" << endl;
    else
        cout << "Hai cay nhi phan khong giong nhau" << endl;

    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
