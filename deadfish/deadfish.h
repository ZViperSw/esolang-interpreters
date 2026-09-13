#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>

class DeadFish {
    public:
    int16_t current_cell = 0;
    
    void runcode(std::string_view code) {
    int i = 0;
    
    	while (i < code.length()) {
        
        if (code[i] == 'i') { current_cell += 1; }
        
        else if (code[i] == 'd') { current_cell -= 1; }
      
      else if (code[i] == 's') { current_cell *= current_cell;}
      
      else if (code[i] == 'o') { std::cout << static_cast<int>(current_cell);}
      
      else {std::cout << "\n"; }
      
       if (current_cell == 256 || current_cell == -1) { current_cell = 0; }
      
      
      
        i++;
    } // for loop end
    
    }
    };
    
  
