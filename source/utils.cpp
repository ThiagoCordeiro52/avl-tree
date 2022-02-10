#include "utils.h"

bool read_file_and_execute(std::string filename, Tree *tree) {
    std::ifstream file{filename};

    if (file.fail()) {
        std::cerr << "could not open file \"" + filename + "\"\n";
        return false;
    }

    while (not file.eof()) {
        std::string line;
        if (not getline(file >> std::ws, line)) {
            std::cerr << "file \"" + filename + "\" is empty\n";
            return false;
        }

        file >> std::ws;

        std::istringstream line_stream{line};

        while (not line_stream.eof()) {
            std::string str, value;
            int int_value;

            if (not getline(line_stream >> std::ws, str, ' ')) {
                std::cerr << "could not read the command from file \"" + filename + "\" \n";
                return false;
            }

            std::for_each(str.begin(), str.end(), [](char &c)
                    { c = ::toupper(c); });

            if (str == "IMPRIMA") {
                std::cout << "The tree:\n";
                std::cout << "------------------\n";
                std::cout << tree->to_string();
                std::cout << "------------------\n";
            }
            else if (str == "MEDIANA") {
                std::cout << "The median of the tree is: " << tree->median() << '\n';
            }
            else if (str == "ENESIMO") {
                getline(line_stream >> std::ws, value);

                try {
                    int_value = static_cast<int>(std::stoi(value));
                }
                catch (const std::invalid_argument &e) {
                    std::cerr << "the number of the value is not an integer \n";
                    return false;
                }

                std::cout << "The element in position " << int_value << " is " << tree->get(int_value) << '\n';
            }
            else if (str == "CHEIA") {
                if (tree->is_full()) {
                    std::cout << "The tree is full!\n";
                }
                else {
                    std::cout << "The tree is not full!\n";
                }
            }
            else if (str == "COMPLETA") {
                if (tree->is_complete()) {
                    std::cout << "The tree is complete!\n";
                }
                else {
                    std::cout << "The tree is not complete!\n";
                }
            }
            else if (str == "INSIRA") {
                getline(line_stream >> std::ws, value);

                try {
                    int_value = static_cast<int>(std::stoi(value));
                }
                catch (const std::invalid_argument &e) {
                    std::cerr << "the number of the value is not an integer \n";
                    return false;
                }

                tree->insert(int_value);
                std::cout << "Element " << int_value << " was inserted!\n";
            }
            else if (str == "REMOVA") {
                getline(line_stream >> std::ws, value);

                try {
                    int_value = static_cast<int>(std::stoi(value));
                }
                catch (const std::invalid_argument &e) {
                    std::cerr << "the number of the value is not an integer \n";
                    return false;
                }

                tree = tree->remove(int_value);
                std::cout << "Element " << int_value << " was removed!\n";
            }
            else if (str == "POSICAO") {
                getline(line_stream >> std::ws, value);

                try {
                    int_value = static_cast<int>(std::stoi(value));
                }
                catch (const std::invalid_argument &e) {
                    std::cerr << "the number of the value is not an integer \n";
                    return false;
                }

                std::cout << "The position of element " << value << " is " << tree->position(int_value) << "th\n";
            }
        }
    }

    return true;
}
