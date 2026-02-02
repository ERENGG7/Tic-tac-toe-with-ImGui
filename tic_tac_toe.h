#include "program.h"

#define ENABLE_GAME 1
using Flag = bool;
//Flags:
class Game : public Program {
private:
	//tictactoe flags:
	const char* buttons[9] = {
	" "," "," ",
	" "," "," ",
	" "," "," "
	};
public:
	Flag isRunning = false;
	Flag player = true;
	Flag showPopUp = false;
	Flag gameOver = false;
#if ENABLE_GAME
	bool checkWin(const char* symb);
	bool isFull();
	void reset();
	void DrawButtons(const bool& darkTheme)override;
	void popUpMenu();
	void drawUI(const bool& darkTheme) override;
#endif
};
#endif