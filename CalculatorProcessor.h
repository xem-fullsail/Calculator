// Calculator
// Kevin Moniz

#pragma once
#include <string>


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
	static CalculatorProcessor* GetInstance();

};
