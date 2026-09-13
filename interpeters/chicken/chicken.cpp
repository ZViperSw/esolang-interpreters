#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
// I need to make an chicken intepeter I could use sstream and std::getline with std::find

class Chicken {
    public:
int current {};
int ip;
std::string program;

std::vector<int> stack {};
std::vector<std::string> lines {};

int chicken_count(std::string text) {
    std::stringstream sstream(text);

    int count = 0;
    std::string word;

    while (sstream >> word) {
        if (word == "chicken") {
            count++;
        }
    }

    return count;
}	

void init(std::string code) {
    program = code;
    }

void runcode() {
    std::stringstream sstream(program);
    std::string line;
    
    while (std::getline(sstream, line)) {
        lines.push_back(line);
    }
    
    while (ip < lines.size()) {
    
    int opcode = chicken_count(lines[ip]);
    
    
    switch (opcode) {
    
    // 1
    case 1:
    stack.push_back(1); break;
    
    // 2
    case 2: {
    int a = stack.back();
    stack.pop_back();

    int b = stack.back();
    stack.pop_back();

    stack.push_back(b + a);
    break;
}
    
    // 3
    case 3: {
    int a = stack.back();
    stack.pop_back();

    int b = stack.back();
    stack.pop_back();

    stack.push_back(b - a);
    break;
}
  
  // 4
case 4: {
    int a = stack.back();
    stack.pop_back();

    int b = stack.back();
    stack.pop_back();

    stack.push_back(b * a);
    break;
}

// 5
case 5: {
    int a = stack.back();
    stack.pop_back();

    int b = stack.back();
    stack.pop_back();

    stack.push_back(b == a);
    break;
}

   case 6: {
    int source = chicken_count(lines[ip + 1]);
    
    if (source == 0) {
    int index = stack.back();
    stack.push_back(stack[index]);
}
else if (source == 1) {
    std::string x;
    std::cin >> x;

    int index = stack.back();
    stack.push_back(x[index]);
}
  ip++;
  break;  
    }
    
    default:
    if (opcode >= 10) {
        stack.push_back(opcode - 10);
    }
    break;
    
       } // switch end
       
      ip++;
       
   } // loop end
       } // func end

}; // class end
