// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#include "MainWindow.h"
#include "wx/gbsizer.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_BUTTON(9001, OnButtonClicked)
	EVT_BUTTON(9002, OnButtonClicked)
	EVT_BUTTON(9003, OnButtonClicked)
wxEND_EVENT_TABLE()


MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "calculator.xem", wxPoint(400, 400)) {
	// Create the grid sizer
	wxGridBagSizer* grid = new wxGridBagSizer();
	//grid->SetRows(3);
	//grid->SetCols(3);
	
	// Create the buttons
	button1 = new wxButton(this, 9001, "1");
	button2 = new wxButton(this, 9002, "2");
	button3 = new wxButton(this, 9003, "3");

	// Add the buttons to the grid
	grid->Add(button1);
	grid->Add(button2);
	grid->Add(button3);

	/*grid->Add(button1, wxGBPosition(0, 0), wxGBSpan(1, 3));
	grid->Add(button2, wxGBPosition(1, 1), wxGBSpan(1, 2));
	grid->Add(button3, wxGBPosition(2, 2), wxGBSpan(1, 1));*/

	// Display the grid
	this->SetSizer(grid);
	//grid->Fit(this);
	grid->Layout();
	
	//buttons = new wxButton*[numButtons];
	//buttons.insert(std::pair<char, wxButton*>('0', new wxButton(this, 9000, "0")));
	//wxGridBagSizer* grid = new wxGridBagSizer();
	//wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	//button = new wxButton(this, 10001, "Button", wxPoint(10, 10), wxSize(150, 50));
	//text = new wxTextCtrl(this, wxID_ANY, "Text Control", wxPoint(10, 70), wxSize(300, 30));
	//list = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

MainWindow::~MainWindow() {
	//delete[] buttons;		// Free up dynamic memory
}

void MainWindow::OnButtonClicked(wxCommandEvent& eventName) {
	//
	eventName.Skip();
}
