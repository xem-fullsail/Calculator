// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#pragma once
#include <string>
#include "wx/wx.h"


class MainWindow : public wxFrame
{

public:
	MainWindow();										// Constructor
	~MainWindow();										// Destructor

private:
	std::string equation = "";							// The current equation being input
	std::string result = "0";							// The current result of the equation
	wxTextCtrl* equationCtrl = nullptr;					// The text field to display the equation
	wxTextCtrl* resultCtrl = nullptr;					// The text field to display the result
	wxButton* button0 = nullptr;						// Button '0'
	wxButton* button1 = nullptr;						// Button '1'
	wxButton* button2 = nullptr;						// Button '2'
	wxButton* button3 = nullptr;						// Button '3'
	wxButton* button4 = nullptr;						// Button '4'
	wxButton* button5 = nullptr;						// Button '5'
	wxButton* button6 = nullptr;						// Button '6'
	wxButton* button7 = nullptr;						// Button '7'
	wxButton* button8 = nullptr;						// Button '8'
	wxButton* button9 = nullptr;						// Button '9'
	wxButton* buttonEql = nullptr;						// Button '='
	wxButton* buttonAdd = nullptr;						// Button '+'
	wxButton* buttonSub = nullptr;						// Button '-'
	wxButton* buttonMul = nullptr;						// Button '*'
	wxButton* buttonDiv = nullptr;						// Button '/'
	wxButton* buttonMod = nullptr;						// Button '%'
	wxButton* buttonNeg = nullptr;						// Button '+/-'
	wxButton* buttonClr = nullptr;						// Button 'Clear'
	wxButton* buttonDec = nullptr;						// Button 'Decimal'
	wxButton* buttonBin = nullptr;						// Button 'Binary'
	wxButton* buttonHex = nullptr;						// Button 'Hexadecimal'

	void OnButtonClicked(wxCommandEvent& eventName);	// Executes logic when a button is clicked.
	std::string Input(std::string data);				// Appends the given data to the end of the equation.
	int CalculateResult();								// Calculates the result of the current equation.

	wxDECLARE_EVENT_TABLE();							// Creates an event table for this window.

};
