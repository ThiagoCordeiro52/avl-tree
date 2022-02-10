#include <iostream>
#include <queue>
#include <cmath>
#include <sstream>
#include "tree.h"

Tree::Tree(Key key, Tree* left, Tree* right) {
    this->key = key;
    this->left = left;
    this->right = right;
    this->left_nodes = 0;
    this->right_nodes = 0;
    this->height = 1;
}

Tree* Tree::search(Key key) {
    int f = 0;
    return this->search_aux(key, &f);
}

Tree* Tree::search_aux(Key key, int* f) {
    if (this->key == key) {
        *f = 1;
        return this;
    } else if (key < this->key) {
        if (this->left == nullptr) {
            *f = 2;
            return this;
        } else
            return this->left->search_aux(key, f);
    } else {
        if (this->right == nullptr) {
            *f = 3;
            return this;
        } else
            return this->right->search_aux(key, f);
    }
}

void Tree::recalculate() {
    this->left_nodes = 0;
    if (this->left != nullptr) {
        this->left->recalculate();
        this->left_nodes = this->left->size();
    }
    this->right_nodes = 0;
    if (this->right != nullptr) {
        this->right->recalculate();
        this->right_nodes = this->right->size();
    }
}

size_t Tree::size() const {
    if (this == nullptr) 
        return 0;
    else
        return this->right_nodes + 1 + this->left_nodes;
}

void Tree::insert(Key key) {
    // inserts the key in the left subtree
    if (key < this->key) {
        if (this->left == nullptr) {
            this->left = new Tree {key};
            this->left_nodes++;
            if (this->right == nullptr)
                this->height++;
        } else {
           this->left->insert(key);
           this->left_nodes = this->left->size();
           this->height = std::max(this->height, this->left->height + 1);
        }
    }
    // inserts the key in the right subtree
    else if (key > this->key) {
        if (this->right == nullptr) {
            this->right = new Tree {key};
            this->right_nodes++;
            if (this->left == nullptr)
                this->height++;
        } else {
           this->right->insert(key);
           this->right_nodes = this->right->size();
           this->height = std::max(this->height, this->right->height + 1);
        }
    }
}

Tree* Tree::remove(Key key) {
    if (this->key == key) {
        if (this->left == nullptr) {
            auto temp = this->right;
            delete this;
            return temp;
        } else if (this->right == nullptr) {
            auto temp = this->left;
            delete this;
            return temp;
        } else {
            auto greatest = this->left->get_greatest();
            this->left = this->left->remove(greatest);
            this->key = greatest;
            this->left_nodes--;
            auto left_height = this->left == nullptr ? 0 : this->left->height;
            auto right_height = this->right == nullptr ? 0 : this->right->height;
            this->height = std::max(left_height, right_height) + 1;
        }
    } else if (key < this->key) {
        if (this->left != nullptr) {
            this->left = this->left->remove(key);
            this->left_nodes = this->left->size();
            this->height = std::max(this->left->height, this->right->height) + 1;
        }
    } else {
        if (this->right != nullptr) {
            this->right = this->right->remove(key);
            this->right_nodes = this->right->size();
            auto left_height = this->left == nullptr ? 0 : this->left->height;
            auto right_height = this->right == nullptr ? 0 : this->right->height;
            this->height = std::max(left_height, right_height) + 1;
        }
    }
    return this;
}

Tree::Key Tree::get_greatest() const {
    if (this->right == nullptr)
        return this->key;
    else
        return this->right->get_greatest();
}

Tree::Key Tree::get(size_t index) const {
    if (this->left_nodes + 1 == index)
        return this->key;
    else if (this->left_nodes >= index) {
        if (this->left != nullptr)
            return this->left->get(index);
    }
    else {
        if (this->right != nullptr)
            return this->right->get(index - this->left_nodes - 1);
    }

    throw std::out_of_range("get(): index out of range");
}

bool Tree::is_full() const {
    return this->size() == pow(2, height) - 1;
}

bool Tree::is_complete_aux(int level) const {
    if(this->left != nullptr && this->right != nullptr) {
        return this->left->is_complete_aux(--level) && this->right->is_complete_aux(--level);
    }
    return level <= 2;
}
 
bool Tree::is_complete() const {
    return this->is_complete_aux(this->height);
}

std::string Tree::to_string() const {
    std::queue<Tree> q;
    q.push(*this);
    std::ostringstream oss;

    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        oss << t.key << " ";
        if (t.left != nullptr) {
            q.push(*t.left);
        }
        if (t.right != nullptr) {
            q.push(*t.right);
        }
    }

    oss << "\n";
    return oss.str();
}

Tree::Key Tree::median() const {
    auto qnt_nodes = this->size();
    if (qnt_nodes % 2 == 0) {
        return this->get(qnt_nodes / 2);
    } else {
        return this->get(qnt_nodes / 2 + 1);
    }
}

int Tree::position(Key key) const {
    if (key < this->key) {
        if(this->left != nullptr) {
            return this->left->position(key);
        }
    }
    else if (key > this->key) {
        if(this->right != nullptr) {
            return 1 + this->left_nodes + this->right->position(key);
        }
    }
    else
        return this->left_nodes + 1;
    
    throw std::out_of_range("position(): key not found");
}
