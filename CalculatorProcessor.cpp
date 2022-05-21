// Calculator
// Kevin Moniz

#include "CalculatorProcessor.h"

// The singleton instance of this class.
CalculatorProcessor* CalculatorProcessor::instance = nullptr;

// Hidden Constructor
CalculatorProcessor::CalculatorProcessor() {
	//
}

// Hidden Destructor
CalculatorProcessor::~CalculatorProcessor() {
	delete instance;
}

// Returns the singleton instance of the calculator processor.
CalculatorProcessor* CalculatorProcessor::Instance() {
	if (instance == nullptr) instance = new CalculatorProcessor();
	return instance;
}

// Process the given equation and return the result.
int CalculatorProcessor::Process(std::string equation) {
	std::vector<int> numbers;
	std::vector<char> operations;
	std::string tempNum;

	// Parse the equation string into numbers and operations
	for (int i = 0; i < equation.length(); i++) {
		switch (equation[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '%': {
				// Add operations to the vector
				operations.push_back(equation[i]);

				// Operators signify the end of a number; add it to the vector
				if (!tempNum.empty()) {
					numbers.push_back(std::stoi(tempNum));
					tempNum = "";
				}
				
				break;
			}

			default: {
				// Append the number to the temp
				tempNum += equation[i];				
				break;
			}
		}
	}
	
	// Save the last number (no operator to end it)
	if (!tempNum.empty()) {
		numbers.push_back(std::stoi(tempNum));
		tempNum = "";
	}

	// If no numbers, return 0
	if (numbers.empty()) return 0;

	// If no operators, return the first (only) number
	if (operations.empty()) return numbers[0];

	// Execute the operations in order
	int result = numbers[0];
	for (int n = 1, op = 0; op < operations.size(); n++, op++) {
		switch (operations[op]) {
			case '+':
				result = result + numbers[n];
				break;
			case '-':
				result = result - numbers[n];
				break;
			case '*':
				result = result * numbers[n];
				break;
			case '/':
				result = result / numbers[n];
				break;
			case '%':
				result = result % numbers[n];
				break;
		}
	}

	return result;
}

// Converts the given decimal number to binary.
std::string CalculatorProcessor::ConvertDecimalToBinary(std::string equation) {	
	int number = std::stoi(equation);	// Convert the given equation to int
	char bits[32];						// Buffer to store bits
	bits[31] = '\0';					// Null terminator
	int index = 30;						// Array index (will be the pos/neg sign in the array)
	bool neg = number < 0;				// True if the given number is negative

	// Fill in the bits in reverse order
	while (index >= 0 && number >= 0) {
		bits[index] = number % 2;
		number = number / 2;
		index--;
	}

	// Set the pos/neg sign
	std::string result;
	result = neg ? "1" : "0";

	// Trim the excess 0s
	for (int i = index + 1; i < 31; i++)
		result += bits[i];
	
	return result;
}
