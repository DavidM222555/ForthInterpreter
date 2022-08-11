//
// Created by dpmar on 8/10/2022.
//

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <unordered_map>
using std::unordered_map;

#include "PrimitiveInstructions.h"
#include "Instruction.h"

void handleInstruction(stack<double>& programStack, const string& instructionString,
                       unordered_map<string, Instruction>& userDefinedFunctions);

void userDefiningFunction(unordered_map<string, Instruction>& userDefinedFunctions) {
    string userInput;
    auto count = 0;

    Instruction newInstruction;

    while (true) {
        cin >> userInput;

        if (userInput == ";") {
            break;
        }

        // The first string after ':' should be the function's name
        if (count == 0) {
            newInstruction.setInstrucionName(userInput);
        }
        // Otherwise we are adding instructions to the function
        else {
            newInstruction.addInstructionName(userInput);
        }

        count++;
    }

    userDefinedFunctions.insert({ newInstruction.getInstructionName(), newInstruction});
}

void handleIf(stack<double>& programStack, unordered_map<string, Instruction> userDefinedFunctions, bool ifResult) {
    string userInput;
    string keyWordToLookFor = ifResult ? "IF" : "ELSE";

    if (keyWordToLookFor == "IF") {
        while (true) {
            cin >> userInput;

            // If the word ELSE is encountered then we break out of this loop
            if (userInput == "ELSE") {
                break;
            }

            handleInstruction(programStack, userInput, userDefinedFunctions);
        }

        // Ignore input of ELSE until we reach THEN
        while (true) {
            cin >> userInput;

            if (userInput == "THEN") {
                break;
            }
        }
    }
    // Otherwise we look for ELSE
    else {
        // We consume all the input until else
        while (true) {
            cin >> userInput;

            if (userInput == "ELSE") {
                break;
            }
        }

        while (true) {
            cin >> userInput;

            if (userInput == "THEN") {
                break;
            }

            handleInstruction(programStack, userInput, userDefinedFunctions);
        }
    }


}


void handleInstruction(stack<double>& programStack, const string& instructionString,
                       unordered_map<string, Instruction>& userDefinedFunctions) {

    if (instructionString == "+") {
        add(programStack);
    }
    else if (instructionString == "-") {
        sub(programStack);
    }
    else if (instructionString == "/") {
        divide(programStack);
    }
    else if (instructionString == "*") {
        multiply(programStack);
    }
    else if (instructionString == "DUP") {
        duplicate(programStack);
    }
    else if (instructionString == "SWAP") {
        swap(programStack);
    }
    else if (instructionString == "POP") {
        pop(programStack);
    }
    else if (instructionString == "IF") {
        auto result = ifEvaluation(programStack);

        handleIf(programStack, userDefinedFunctions, result);
    }
    else if (instructionString == "<") {
        lessThan(programStack);
    }
    else if (instructionString == "<=") {
        lessThanOrEqual(programStack);
    }
    else if (instructionString == ">") {
        greaterThan(programStack);
    }
    else if (instructionString == ">=") {
        greaterThanOrEqual(programStack);
    }
    else if (instructionString == ":") {
        userDefiningFunction(userDefinedFunctions);
    }
    else if (userDefinedFunctions.count(instructionString)) {
        for (const auto& instruction : userDefinedFunctions.at(instructionString).getInstructions()) {
            handleInstruction(programStack, instruction, userDefinedFunctions);
        }
    }
    else {
        push(programStack, std::stof(instructionString));
    }
}
