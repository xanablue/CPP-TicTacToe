// Assignment 6 - Tic Tac Toe
// Xana Navoichick

#include <iostream>
#include <conio.h>
#include <string>
#include "TicTacToe.h"

// Constructor
TicTacToe::TicTacToe()
{
	m_currentPlayer = 0;
	for (int i = 0; i < 9; i++)
	{
		m_board[i] = ' ';
	}
};

// Methods
void TicTacToe::Display() const
{
	system("cls");
	std::cout << " " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << " \n";
	std::cout << "-----------\n";
	std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << " \n";
	std::cout << "-----------\n";
	std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << " \n\n";
}

bool TicTacToe::CheckWin(int currentPlayer) const
{
	char symbol;
	if (currentPlayer == 0) { symbol = 'X'; }
	else { symbol = 'O'; }
	
	if ((m_board[0] == symbol && m_board[1] == symbol && m_board[2] == symbol) ||
		(m_board[3] == symbol && m_board[4] == symbol && m_board[5] == symbol) ||
		(m_board[6] == symbol && m_board[7] == symbol && m_board[8] == symbol) ||
		(m_board[0] == symbol && m_board[3] == symbol && m_board[6] == symbol) ||
		(m_board[1] == symbol && m_board[4] == symbol && m_board[7] == symbol) ||
		(m_board[2] == symbol && m_board[5] == symbol && m_board[8] == symbol) ||
		(m_board[0] == symbol && m_board[4] == symbol && m_board[8] == symbol) ||
		(m_board[2] == symbol && m_board[4] == symbol && m_board[6] == symbol))
	{
		return true;
	}

	return false;
}

bool TicTacToe::CheckTie() const
{
	for (int i = 0; i < 9; i++)
	{
		if (m_board[i] == ' ') { return false; }
	}

	return true;
}

bool TicTacToe::ValidateMove(int chosenSpace) const
{
	if (chosenSpace > 0 && chosenSpace < 10 && m_board[chosenSpace - 1] == ' ')
	{
		return true;
	}

	return false;
}

void TicTacToe::TakeTurn()
{
	int chosenSpace;

	char symbol;
	if (m_currentPlayer == 0) { symbol = 'X'; }
	else { symbol = 'O'; }

	std::cout << "Player " << (m_currentPlayer + 1) << ", please choose your space.\n";
	std::cout << "Enter a number between 1 and 9: ";
	std::cin >> chosenSpace;
	std::cout << "\n";

	while (!ValidateMove(chosenSpace))
	{
		std::cout << "Invalid move.\n";
		std::cout << "Please choose a different space (1 - 9): ";
		std::cin >> chosenSpace;
	}
	
	m_board[chosenSpace - 1] = symbol;

	CheckWin(m_currentPlayer);
	CheckTie();
	if (IsGameOver()) { return; }
	SwitchPlayers();

}

bool TicTacToe::IsGameOver() const
{
	if (CheckWin(m_currentPlayer))
	{
		if (m_currentPlayer == 0) { std::cout << "Game Over!\nPlayer 1 wins!\n"; }
		else { std::cout << "Game Over!\nPlayer 2 wins!\n"; }
		return true;
	}
	else if (CheckTie())
	{
		std::cout << "Game Over!\nIt's a tie.\n";
		return true;
	}
	else { return false; }
}

void TicTacToe::SwitchPlayers()
{
	if (m_currentPlayer == 0) { m_currentPlayer = 1; }
	else { m_currentPlayer = 0; }
}
