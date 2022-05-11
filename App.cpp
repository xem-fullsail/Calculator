// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#include "App.h"


wxIMPLEMENT_APP(App);


App::~App() {
	//delete mainWindow;
}

bool App::OnInit() {
	mainWindow = new MainWindow();
	mainWindow->Show();
	return true;
}
