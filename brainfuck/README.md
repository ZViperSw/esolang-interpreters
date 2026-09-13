This is the classic bf intepreter in C++ to run it
Copy bf.h inside your project dir then in your main file

#include "bf.h"
...

int main() {
Bf bf;
bf.runcode(">>>>>.");
return 0;
}
