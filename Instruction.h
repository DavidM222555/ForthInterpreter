//
// Created by dpmar on 8/10/2022.
//

#ifndef FORTHINTERPRETER_INSTRUCTION_H
#define FORTHINTERPRETER_INSTRUCTION_H

#include <string>
using std::string;

#include <vector>
using std::vector;

class Instruction {
private:
    string instructionName;

    // The strings that make up a given instruction
    // For example, : FLOOR5 (n -- n') DUP 6 < IF DROP 5 ELSE 1 - THEN ;
    // Consists of each space separated string in the above
    vector<string> instructionStrings;

public:
    inline string getInstructionName() { return instructionName; }
    inline void setInstrucionName(string instrName) { instructionName = instrName; }

    inline vector<string> getInstructions() { return instructionStrings; };
    inline void addInstructionName(string instrToAdd) { instructionStrings.push_back(instrToAdd);}
};


#endif //FORTHINTERPRETER_INSTRUCTION_H
