#ifndef PROGRAM_H
#define PROGRAM_H
#include "action.h"
#include "program_flags.h"

class Program {
public:
	virtual void DrawButtons(const bool& darkTheme) = 0;
	virtual void drawUI(const bool& darkTheme) = 0;
	virtual ~Program() = default;
};
#endif 
