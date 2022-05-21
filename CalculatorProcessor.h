// Calculator
// Kevin Moniz

#pragma once
#include <string>
#include <vector>


class CalculatorProcessor 
{

private:

	// The single instance of this class
	static CalculatorProcessor* instance;

	// Hidden Constructor
	CalculatorProcessor();

	// Hidden Destructor
	~CalculatorProcessor();

public:

	// Copy constructor (not cloneable)
	CalculatorProcessor(CalculatorProcessor& other) = delete;

	// Assignment operator (not assignable)
	void operator=(const CalculatorProcessor&) = delete;

	// Returns the singleton instance of the calculator processor.
	static CalculatorProcessor* Instance();

	// Process the given equation and return the result.
	static int Process(std::string equation);

	// Converts the given decimal number to binary.
	static std::string ConvertDecimalToBinary(std::string equation);

};
