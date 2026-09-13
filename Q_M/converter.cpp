#include <iostream>
#include <string>
#include <stdexcept>

class Q_M_Converter {
private:

    // Q_M instructions
    const std::string ADD =
        "_??????_";

    const std::string DEC =
        "_??_____";

    const std::string CHAR_OUTPUT =
        "_?_????_";

public:

    std::string convert_string(const std::string& text) {

        std::string output;

        int current_value = 0;

        for (unsigned char c : text) {

            int target = static_cast<int>(c);

            // Reset current value back to 0.
            for (int i = 0; i < current_value; i++) {
                output += DEC;
            }

            // Build the character from 0.
            for (int i = 0; i < target; i++) {
                output += ADD;
            }

            // Print the character duh
            output += CHAR_OUTPUT;

            current_value = target;
        }

        return output;
    }

    std::string convert(const std::string& cpp) {

        if (cpp.length() >= 2 &&
            cpp.front() == '"' &&
            cpp.back() == '"') {

            return convert_string(
                cpp.substr(1, cpp.length() - 2)
            );
        }

        // ----------------------------------------
        // C++:
        //
        // std::string cpp = "Hello, World!";
        // ----------------------------------------

        size_t first_quote = cpp.find('"');
        size_t last_quote = cpp.rfind('"');

        if (first_quote != std::string::npos &&
            last_quote != first_quote) {

            std::string text =
                cpp.substr(
                    first_quote + 1,
                    last_quote - first_quote - 1
                );

            return convert_string(text);
        }

        throw std::runtime_error(
            "No string literal found"
        );
    }
};


int main() {

    Q_M_Converter converter;

    // You can use either:
    std::string cpp = "\"Hello, World!\"";

    // Or:
    // std::string cpp =
    //     "std::string cpp = \"Hello, World!\"";

    try {

        std::string qm = converter.convert(cpp);

        std::cout << qm << '\n';

        std::cout << "\nInstructions: "
                  << qm.length() / 8
                  << '\n';

        std::cout << "Characters: "
                  << qm.length()
                  << '\n';

    }
    catch (const std::exception& e) {

        std::cerr << "Converter error: "
                  << e.what()
                  << '\n';

        return 1;
    }

    return 0;
}
