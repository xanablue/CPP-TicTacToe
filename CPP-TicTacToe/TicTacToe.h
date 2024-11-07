#pragma once
#include "Game.h"
#include <string>
#include <iostream>

class TicTacToe : public Game
{
private:
	// Fields
	char m_board[9];
	int m_currentPlayer = 0;
	
public:
	// Constructor
	TicTacToe();

	// Methods
	virtual bool IsGameOver() const;
	virtual void TakeTurn();
	virtual void Display() const;
	virtual void SwitchPlayers();
	virtual bool CheckWin(int currentPlayer) const;
	virtual bool CheckTie() const;
	virtual bool ValidateMove(int chosenSpace) const;
};