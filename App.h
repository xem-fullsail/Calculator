// Lab 1.5 - Calculator Design UI
// Kevin Moniz

#pragma once
#include "wx/wx.h"

class MainWindow;

class App : public wxApp
{

private:
	MainWindow* mainWindow;

public:
	virtual bool OnInit();

};
