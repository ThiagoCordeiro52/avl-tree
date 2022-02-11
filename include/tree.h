#ifndef tree_h
#define tree_h

#include <string>

class Tree {
    public:
        using Key = int;

        Tree(Key key, Tree* left = nullptr, Tree* right = nullptr, int bal = 0, bool = true);

        Tree* search(Key key);

        void insert(Key key);

        Tree* remove(Key key);

        Key get(size_t index) const;

        int position(Key key) const;

        std::string to_string() const;


    
        Tree* search_aux(Key key, int* f);
        Key get_greatest() const;
        std::string get_nodes_by_level(int level) const;
        void recalculate();
        size_t size() const;
        bool is_complete_aux(int level) const;
        void caso1(Tree* pt, bool h);
        void caso2(Tree* pt, bool h);

        Tree* left;
        int bal;
        Key key;
        Tree* right;
        size_t left_nodes;
        size_t right_nodes;
        size_t height;
        bool h;
};

#endif
