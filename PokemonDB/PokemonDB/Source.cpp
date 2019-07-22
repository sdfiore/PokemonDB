// Author:	Salvatore Di Fiore
// Date:	10/31/2018
// Updated	5/31/2019

#include "Source.h"
#include "PokemonDB.h"

// This function disables changes in the console's width, and height.
void DisableResize(HWND console)
{
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

// This function removes the console's scroll bar.
void RemoveScrollBar()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(console, &csbi);
	COORD scrollbar = {
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(console, scrollbar);
}

// Driver function.
int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	const string title = "PokemonDB";

	SetConsoleTitle(title.c_str());
	GetWindowRect(console, &r);							// Stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 450, 450, TRUE); // 450 width, 450 height.
	DisableResize(console);
	RemoveScrollBar();

	PokemonDB p;

	p.Menu();
}