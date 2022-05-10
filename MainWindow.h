// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#pragma once
//#include <unordered_map>
#include "wx/wx.h"


class MainWindow : public wxFrame
{

public:
	MainWindow();		// Constructor
	~MainWindow();		// Destructor

	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	wxButton* button3 = nullptr;
	//wxTextCtrl* text = nullptr;
	//wxListBox* list = nullptr;

	// Called when a button is clicked
	void OnButtonClicked(wxCommandEvent& eventName);

	// Creates an event table for this window
	wxDECLARE_EVENT_TABLE();

//private:
	//std::unordered_map<char, wxButton*> buttons;

	//const int numButtons = 22;	// The total number of buttons in the UI
	//unsigned int columns = 4;	// Number of columns in the button grid
	//unsigned int rows = 8;		// Number of rows in the button grid
	//wxButton** buttons;			// The array of button pointers

};
