#include <iostream>
#include "tree.h"

using namespace std;

void print2DUtil(Tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = 10; i < space; i++)
        cout<<" ";
    cout<<root->key<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(Tree *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main() {
    std::cout << "Search test:\n";
    auto tree = new Tree {5};

    tree->insert(5);
    tree->insert(4);
    tree->insert(7);
    tree->insert(10);
    tree->insert(12);

    print2DUtil(tree, 5);
    return 0;
}
