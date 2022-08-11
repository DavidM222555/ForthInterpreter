//
// Created by dpmar on 8/10/2022.
//

#include <stack>
using std::stack;

#include <iostream>
using std::cout;

// These functions aren't necessarily primitive but for this implementation
// of Forth they will be the basic starting instructions that a user can then
// build up with their own functions
void add(stack<double>& currentStack) {
    // TODO: Error functionality
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    currentStack.push(secondItem + firstItem);
}

void sub(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    currentStack.push(secondItem - firstItem);
}

void divide(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    currentStack.push(secondItem / firstItem);
}

void multiply(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    currentStack.push(secondItem * firstItem);
}

void duplicate(stack<double>& currentStack) {
    if (currentStack.empty()) {
        return;
    }

    auto topItem = currentStack.top();

    currentStack.push(topItem);
}

void swap(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    currentStack.push(secondItem);
    currentStack.push(firstItem);
}

void pop(stack<double>& currentStack) {
    currentStack.pop();
}

void push(stack<double>& currentStack, double valueToPush) {
    currentStack.push(valueToPush);
}

bool ifEvaluation(stack<double>& currentStack) {
    if (currentStack.top() >= 1) {
        return true;
    }

    return false;
}

void lessThan(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    if (secondItem < firstItem) {
        currentStack.push(1);
    }
    else {
        currentStack.push(0);
    }
}

void lessThanOrEqual(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    if (secondItem <= firstItem) {
        currentStack.push(1);
    }
    else {
        currentStack.push(0);
    }

}

void greaterThan(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    if (secondItem > firstItem) {
        currentStack.push(1);
    }
    else {
        currentStack.push(0);
    }
}

void greaterThanOrEqual(stack<double>& currentStack) {
    if (currentStack.size() < 2) {
        return;
    }

    auto firstItem = currentStack.top();
    currentStack.pop();
    auto secondItem = currentStack.top();
    currentStack.pop();

    if (secondItem >= firstItem) {
        currentStack.push(1);
    }
    else {
        currentStack.push(0);
    }
}

void printStack(stack<double> currentStack) {
    while (!currentStack.empty()) {
        cout << currentStack.top() << " ";
        currentStack.pop();
    }

    std::cout << "\n";
}