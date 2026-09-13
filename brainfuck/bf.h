#include <string>
#include <string_view>
#include <iostream>
#include <vector>


class Bf {
public:

    std::vector<unsigned char> cells = std::vector<unsigned char>(30000, 0);
   unsigned short int current_cell = 0;
    char byte;

    void runcode(std::string_view code) {
        int i = 0;

        while (i < code.length()) {

            if (code[i] == '>') {
                
                if (current_cell > cells.size() - 1) {
                    current_cell = 0;
                    }
                else {
                current_cell++;
                }
            }

            if (code[i] == '<') {
                if (current_cell < 1) { current_cell = 0; }
                else {
                current_cell--;
                }
            }

            if (code[i] == '+') {
                cells[current_cell]++;
            }

            if (code[i] == '-') {
                cells[current_cell]--;
            }

            if (code[i] == ',') {
                std::cin.get(byte);
                cells[current_cell] = byte;
            }

            if (code[i] == '.') {
                std::cout.put(cells[current_cell]);
            }

            // [
            if (code[i] == '[' && cells[current_cell] == 0) {

                int depth = 1;

                for (int j = i + 1; j < code.length(); j++) {

                    if (code[j] == '[') {
                        depth++;
                    }

                    if (code[j] == ']') {
                        depth--;
                    }

                    if (depth == 0) {
                        int matching = j;
                        i = matching;
                        break;
                    }
                }
            }

            // ]
            if (code[i] == ']' && cells[current_cell] != 0) {

                int depth = 1;

                for (int j = i - 1; j >= 0; j--) {

                    if (code[j] == ']') {
                        depth++;
                    }

                    if (code[j] == '[') {
                        depth--;
                    }

                    if (depth == 0) {
                        int matching = j;
                        i = matching;
                        break;
                    }
                }
            }

            i++;
        }
    }
};

