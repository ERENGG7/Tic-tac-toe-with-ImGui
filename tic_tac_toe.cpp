//first project Gui - game.

#include <iostream>
#include <cstring>
//imgui:
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"
#include "tictactoe.h"
#include "program.h"

#if ENABLE_GAME
bool Game::checkWin(const char* symb) {
	// редове
	for (int i = 0; i < 3; i++) {
		int start = i * 3;
		if (strcmp(buttons[start], symb) == 0 &&
			strcmp(buttons[start + 1], symb) == 0 &&
			strcmp(buttons[start + 2], symb) == 0) {
			return true;
		}
	}
	// колони
	for (int i = 0; i < 3; i++) {
		if (strcmp(buttons[i], symb) == 0 &&
			strcmp(buttons[i + 3], symb) == 0 &&
			strcmp(buttons[i + 6], symb) == 0) {
			return true;
		}
	}
	// диагонали
	if (strcmp(buttons[0], symb) == 0 &&
		strcmp(buttons[4], symb) == 0 &&
		strcmp(buttons[8], symb) == 0) {
		return true;
	}
	if (strcmp(buttons[2], symb) == 0 &&
		strcmp(buttons[4], symb) == 0 &&
		strcmp(buttons[6], symb) == 0) {
		return true;
	}
	return false;
}
#endif // ENABLE_GAME
#if ENABLE_GAME
//checkWin:
bool Game::isFull() {
	for (int i = 0; i < 9; i++) { 
		if (strcmp(buttons[i], " ") == 0) { return false; }
	}
	return true;
}
#endif // ENABLE_GAME
#if ENABLE_GAME
void Game::reset() {
	for (int i = 0; i < 9; i++) { buttons[i] = " "; }
}
#endif // ENABLE_GAME
#if ENABLE_GAME
void Game::DrawButtons(const bool& darkTheme) {
	ImGui::SetWindowFontScale(1.8f);
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
	/*ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);*/
	//push frame for buttons if theme is light and black color for frame:
	if (!darkTheme) {
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.3f);
		ImGui::PushStyleColor(ImGuiCol_Border,
			ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
	}
	for (int i = 0; i < 9; i++) {
		ImGui::PushID(i);
		if (ImGui::Button(buttons[i], ImVec2(70, 75)) && !gameOver) {
			if (player) {
				if (strcmp(buttons[i], " ") == 0) {
					buttons[i] = "X";
					player = !player;
				}
			}
			else {
				if (strcmp(buttons[i], " ") == 0) {
					buttons[i] = "O";
					player = !player;
				}
			}
		}
		ImGui::PopID();
		if ((i + 1) % 3 != 0) { ImGui::SameLine(); }
	}
	//pop colors form dark theme:
	if (!darkTheme) {
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
	}
	ImGui::SetWindowFontScale(1.0f);
	ImGui::PopStyleColor();
}
#endif // ENABLE_GAME
#if ENABLE_GAME
void Game::popUpMenu() {
	ImGui::PushID(100);
	if (showPopUp) {
		ImGui::OpenPopup("Options");
	}
	if (ImGui::BeginPopup("Options")) {
		if (ImGui::Selectable("New Game")) {
			reset();
			gameOver = false;
			player = true;
			showPopUp = false;
		}
		if (ImGui::Selectable("Quit")) {
			isRunning = false;
			showPopUp = false;
		}
		ImGui::EndPopup();
	}
	ImGui::PopID();
}
#endif
#if ENABLE_GAME
void  Game::drawUI(const bool& darkTheme) {
	ImGui::SetNextWindowBgAlpha(0.6f);
	ImGui::SetNextWindowSize(ImVec2(250, 308), ImGuiCond_Always);
	ImGui::Begin("Tic-tac-toe", &isRunning,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse);
	DrawButtons(darkTheme);
	if (checkWin("X")) {
		ImGui::Text("Player X wins!");
		gameOver = true;
	}
	else if (checkWin("O")) {
		ImGui::Text("Player O wins!");
		gameOver = true;
	}
	else if (isFull()) {
		ImGui::Text("Equality");
		gameOver = true;
	}
	if (gameOver) {
		ImGui::SameLine();
		ImGui::SetWindowFontScale(0.7f);
		if (ImGui::Button("Options", ImVec2(65, 20))) {
			showPopUp = true;
		}
		ImGui::SetWindowFontScale(1.0f);
		popUpMenu();
	}
	ImGui::End();
	//reset flags:
	if (!isRunning) {
		reset();
		gameOver = false;
		player = true;
	}
}
#endif
