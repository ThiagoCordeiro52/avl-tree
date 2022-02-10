#include "tree.h"
#include "utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "You need to pass exacty two paramenters\n";
        return 1;
    }
    
    std::string tree_file_name {argv[1]};
    std::ifstream tree_file {tree_file_name};

    if (tree_file.fail()) {
        std::cerr << "could not open file \"" + tree_file_name + "\"\n";
        return 1;
    }

    std::string line;
    if (not getline(tree_file >> std::ws, line)) {
        std::cerr << "file \"" + tree_file_name + "\" is empty\n";
        return 1;
    }

    tree_file >> std::ws;

    if (not tree_file.eof()) {
        std::cerr << "file \"" + tree_file_name + "\" should have only one line\n";
        return 1;
    }

    std::istringstream line_stream {line};

    Tree::Key key;
    line_stream >> key;
    Tree tree {key};

    while (not line_stream.eof()) {
        line_stream >> key;
        tree.insert(key);
    }

    // reading command file

    if (not read_file_and_execute(argv[2], &tree)) {
        std::cerr << "There was a problem reading or executing the file\n";
        return 1;
    }

    return 0;
}

