#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

#include "InputHandler.h"
#include "Instruction.h"

int main() {
    string userInput;
    stack<double> programStack;

    unordered_map<string, Instruction> userDefinedInstructions;

    while(true) {
        cin >> userInput;

        if (userInput == "EXIT") {
            break;
        }

        handleInstruction(programStack, userInput, userDefinedInstructions);
    }

    printStack(programStack);

    return 0;
}
