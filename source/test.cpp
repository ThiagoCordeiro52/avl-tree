#include <iostream>
#include "tree.h"

int main() {
    std::cout << "Search test:\n";
    auto tree = new Tree {5};
    tree = tree->search(5);

    std::cout << "5 = " << tree->key << '\n';
    std::cout << "0 = " << tree->left_nodes << '\n';
    std::cout << "0 = " << tree->right_nodes << '\n';
    std::cout << "1 = " << tree->height << '\n';

    std::cout << "\nInsert test:\n";

    tree->insert(4);
    tree->insert(2);
    tree->insert(3);
    tree->insert(7);
    tree->insert(8);
    tree->insert(1);
    tree->insert(6);

    std::cout << "4 = " << tree->left_nodes << '\n';
    std::cout << "3 = " << tree->right_nodes << '\n';
    std::cout << "4 = " << tree->height << '\n';
    std::cout << "4 = " << tree->left->key << '\n';
    std::cout << "3 = " << tree->left->height << '\n';
    std::cout << "2 = " << tree->left->left->key << '\n';
    std::cout << "2 = " << tree->left->left->height << '\n';
    std::cout << "1 = " << tree->left->left->left->key << '\n';
    std::cout << "1 = " << tree->left->left->left->height << '\n';
    std::cout << "3 = " << tree->left->left->right->key << '\n';
    std::cout << "1 = " << tree->left->left->right->height << '\n';
    std::cout << "7 = " << tree->right->key << '\n';
    std::cout << "2 = " << tree->right->height << '\n';
    std::cout << "6 = " << tree->right->left->key << '\n';
    std::cout << "1 = " << tree->right->left->height << '\n';
    std::cout << "8 = " << tree->right->right->key << '\n';
    std::cout << "1 = " << tree->right->right->height << '\n';

    std::cout << "\nRemove test:\n";

    tree = tree->remove(5);

    std::cout << "3 = " << tree->left_nodes << '\n';
    std::cout << "3 = " << tree->right_nodes << '\n';
    std::cout << "4 = " << tree->key << '\n';
    std::cout << "3 = " << tree->height << '\n';
    std::cout << "2 = " << tree->left->key << '\n';
    std::cout << "2 = " << tree->left->height << '\n';
    std::cout << "1 = " << tree->left->left->key << '\n';
    std::cout << "1 = " << tree->left->left->key << '\n';
    std::cout << "3 = " << tree->left->right->key << '\n';
    std::cout << "1 = " << tree->left->right->key << '\n';
    std::cout << "7 = " << tree->right->key << '\n';
    std::cout << "6 = " << tree->right->left->key << '\n';
    std::cout << "1 = " << tree->right->left->height << '\n';
    std::cout << "8 = " << tree->right->right->key << '\n';
    std::cout << "1 = " << tree->right->right->height << '\n';

    tree->insert(5);
    tree = tree->remove(7);

    std::cout << "3 = " << tree->left_nodes << '\n';
    std::cout << "3 = " << tree->right_nodes << '\n';
    std::cout << "4 = " << tree->key << '\n';
    std::cout << "2 = " << tree->left->key << '\n';
    std::cout << "1 = " << tree->left->left->key << '\n';
    std::cout << "3 = " << tree->left->right->key << '\n';
    std::cout << "6 = " << tree->right->key << '\n';
    std::cout << "5 = " << tree->right->left->key << '\n';
    std::cout << "8 = " << tree->right->right->key << '\n';

    tree->insert(7);

    std::cout << "\nGet test:\n";

    std::cout << "1 = " << tree->get(1) << '\n';
    std::cout << "2 = " << tree->get(2) << '\n';
    std::cout << "3 = " << tree->get(3) << '\n';
    std::cout << "4 = " << tree->get(4) << '\n';
    std::cout << "5 = " << tree->get(5) << '\n';
    std::cout << "6 = " << tree->get(6) << '\n';
    std::cout << "7 = " << tree->get(7) << '\n';
    std::cout << "8 = " << tree->get(8) << '\n';

    std::cout << "\nTo string:\n";
    std::cout << tree->to_string() << '\n';

    tree->insert(-1);
    std::cout << tree->to_string() << '\n';

    std::cout << "\nPosition test:\n";

    std::cout << "1 = " << tree->position(-1) << "\n";
    std::cout << "2 = " << tree->position(1) << "\n";
    std::cout << "3 = " << tree->position(2) << "\n";
    std::cout << "4 = " << tree->position(3) << "\n";

    std::cout << "\nMedian test:\n";

    std::cout << "4 = " << tree->median() << '\n';

    return 0;
}
