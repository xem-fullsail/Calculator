// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#pragma once
#include <string>
#include <unordered_map>
#include "wx/wx.h"

// Button Pair: std::pair<char, wxButton*>
using bpair = std::pair<char, wxButton*>;


class MainWindow : public wxFrame
{

public:
	MainWindow();												// Constructor
	~MainWindow();												// Destructor

private:
	std::string equation = "";									// The current equation being input
	std::string result = "0";									// The current result of the equation
	wxTextCtrl* equationCtrl = nullptr;							// The text field to display the equation
	wxTextCtrl* resultCtrl = nullptr;							// The text field to display the result
	std::unordered_map<char, wxButton*> buttons;				// The collection of buttons indexed by their label
	
	wxButton* CreateButton(char index, std::string label = "");	// Creates and returns a button.
	std::string Append(std::string data);						// Appends the given data to the end of the equation.
	void OnButtonClicked(wxCommandEvent& eventName);			// Executes logic when a button is clicked.

};
