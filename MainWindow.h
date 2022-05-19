// Calculator
// Kevin Moniz

#pragma once
#include <string>
#include "ButtonFactory.h"
#include "wx/gbsizer.h"
#include "wx/wx.h"


class MainWindow : public wxFrame
{

public:

	MainWindow();
	~MainWindow();
	
	// Executes logic when a button is clicked.
	void OnButtonClicked(wxCommandEvent& eventName);

private:

	std::string equation = "";				// The current equation being input
	std::string result = "0";				// The current result of the equation
	wxTextCtrl* equationCtrl = nullptr;		// The text field to display the equation
	wxTextCtrl* resultCtrl = nullptr;		// The text field to display the result
	wxGridBagSizer* grid = nullptr;			// The grid sizer that manages button placement
	ButtonFactory* bfactory = nullptr;		// The factory responsible for making buttons
	
	// Appends the given data to the end of the equation.
	std::string Append(std::string data);

};
