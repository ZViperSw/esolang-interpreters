#include <string>
#include <string_view>
#include "binary.h"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>

enum class token {
    ADD,
    DEC,
    OUTPUT,
    CHAR_OUTPUT,
    SQUARE,
    HALT
    };

class Q_M {
    public:
    int current = 0;
    int8_t current_value = 0;
    
    std::vector<std::string> cells {1200};
    
   std::unordered_map<std::string, token> commands = {
    {"01111110", token::ADD},
    {"01100000", token::DEC},
    {"00101110", token::OUTPUT},
    {"00100100", token::SQUARE},
    {"01011110", token::CHAR_OUTPUT},
    {"01011100", token::HALT}
};

std::unordered_map<char, int> logic = {
    {'?', 1},
    {'_', 0}
    };
    
     void runcode(const std::string& code) {
    
    while (current < code.length()) {
   
   std::string binary = code.substr(current, 8);
   
   std::string binr;
   for (char c : binary) {
    binr += std::to_string(logic[c]);
}
   
   token t = commands.at(binr);
   
   switch (t) {
   case token::ADD:
   
   current_value += 1; break;
   
   case token::DEC:
   current_value -= 1; break;
   
   case token::OUTPUT:
   std::cout << static_cast<int>(current_value); break;
   
   case token::CHAR_OUTPUT:
   std::cout << static_cast<char>(current_value); break;
   
   case token::SQUARE:
   current_value *= current_value; break;
   
   case token::HALT:
   exit(0);
   
   default:
   std::cout << "\n";
   
   }
   
   
   current+= 8;
   } 
    }
    };

int main() {
    Q_M q;
    q.runcode("_??????___?_???_");
    return 0;
}
