#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class OPlayer
{//The class for the computer
	array<Button^, 2> ^grid = gcnew array<Button^, 2>(3, 3);

	bool canSmartMove()
	{
		if (diagonalStopPlayerMove())
		{//checks if the player is about to win
			return true;
		}
		else if (diagonalSmartMove())
		{//checks if it can win diagonally
			return true;
		}
		for (int i = 0; i < 3; i++)
		{
			if (horizantalStopPlayerMove(i))
			{//checks if the player is about to win horizantaly
				return true;
			}
			else if (verticalStopPlayerMove(i))
			{//checks if the player is about to win vertically
				return true;
			}
			else if (horizantalSmartMove(i))
			{//checks if it can win horizantally
				return true;
			}
			else if (verticalSmartMove(i))
			{//checks if it can win vertically
				return true;
			}
		}
		return false;

	}
	bool diagonalSmartMove()
	{
		if (grid[0, 0]->Text == "O" || grid[0, 2]->Text == "O"||grid[2,2]->Text=="O"||grid[0,2]->Text=="O")
		{
			if (grid[1, 1]->Text == "O")
			{
				if (grid[0, 0]->Text == "O" &&grid[2, 2]->Text == "")
				{
					//Places an O in position 2,2 to finish a diagonal
					grid[2, 2]->Text = "O";
					return true;
				}
				else if (grid[0, 2]->Text == "O" &&grid[2, 0]->Text == "")
				{
					//Places an O in position 2,0 to finish a diagonal
					grid[2, 0]->Text = "O";
					return true;
				}
				else if (grid[0, 0]->Text == "" &&grid[2, 2]->Text == "O")
				{
					//Places an O in position 0,0 to finish a diagonal
					grid[0,0]->Text = "O";
					return true;
				}
				else if (grid[0, 2]->Text == "" &&grid[2, 0]->Text == "O")
				{
					//Places a O in position 0,2 to complete a diagonal
					grid[0, 2]->Text = "O";
					return true;
				}

			}
		}
		return false;
	}
	bool horizantalSmartMove(int i)
	{
		if (grid[i, 0]->Text == "O"&&grid[i, 1]->Text == "O")
		{
			if (grid[i, 2]->Text == "")
			{
				//places an O at the final postion of a colum
				grid[i, 2]->Text = "O";
				return true;
			}
		}
		if (grid[i, 1]->Text == "O"&&grid[i, 2]->Text == "O")
		{
			if (grid[i, 0]->Text == "")
			{
				//places an O at the first positon of a colum
				grid[i, 0]->Text = "O";
				return true;
			}
		}
		if (grid[i, 0]->Text == "O"&&grid[i, 2]->Text == "O")
		{
			if (grid[i, 1]->Text == "")
			{
				//places a O at the middle position of a colum
				grid[i, 1]->Text = "O";
				return true;
			}
		}
		
		return false;
	}
	bool verticalSmartMove(int i)
	{
		if (grid[0, i]->Text == "O"&&grid[1, i]->Text == "O")
		{
			if (grid[2, i]->Text == "")
			{
				//places an O at the last position of a row 
				grid[2, i]->Text = "O";
				return true;
			}
		}
		if (grid[1, i]->Text == "O"&&grid[2, i]->Text == "O")
		{
			if (grid[0, i]->Text == "")
			{
				//places a O at the first position of a row
				grid[0, i]->Text = "O";
				return true;
			}
		}
		if (grid[0, i]->Text == "O"&&grid[2, i]->Text == "O")
		{
			if (grid[1, i]->Text == "")
			{
				//places a O at the middle position of a row
				grid[1, i]->Text = "O";
				return true;
			}
		}

		return false;
	}
	bool diagonalStopPlayerMove()
	{
		if (grid[0, 0]->Text == "X" || grid[0, 2]->Text == "X" || grid[2, 2]->Text == "X" || grid[0, 2]->Text == "X")
		{
			if (grid[1, 1]->Text == "X")
			{
				if (grid[0, 0]->Text == "X" &&grid[2, 2]->Text == "")
				{
					//places an O at position 2,2 if the player is about to win
					grid[2, 2]->Text = "O";
					return true;
				}
				else if (grid[0, 2]->Text == "X" &&grid[2, 0]->Text == "")
				{
					//places an O at position 2,0 if the player is about to win
					grid[2, 0]->Text = "O";
					return true;
				}
				else if (grid[0, 0]->Text == "" &&grid[2, 2]->Text == "X")
				{
					//places an O at position 0,0 if the player is about to win
					grid[0, 0]->Text = "O";
					return true;
				}
				else if (grid[0, 2]->Text == "" &&grid[2, 0]->Text == "X")
				{
					//places an O at position 0,2 if the player is about to win
					grid[0, 2]->Text = "O";
					return true;
				}

			}
		}
		return false;
	}
	bool horizantalStopPlayerMove(int i)
	{
		if (grid[i, 0]->Text == "X"&&grid[i, 1]->Text == "X")
		{
			if (grid[i, 2]->Text == "")
			{
				//places an O at the last position of a colum if the player is about to win
				grid[i, 2]->Text = "O";
				return true;
			}
		}
		if (grid[i, 1]->Text == "X"&&grid[i, 2]->Text == "X")
		{
			if (grid[i, 0]->Text == "")
			{
				//places an O at the first position of a colum if the player is about to win
				grid[i, 0]->Text = "O";
				return true;
			}
		}
		if (grid[i, 0]->Text == "X"&&grid[i, 2]->Text == "X")
		{
			if (grid[i, 1]->Text == "")
			{
				//places an O at the middle position of a colum if the player is about to win
				grid[i, 1]->Text = "O";
				return true;
			}
		}

		return false;
	}
	bool verticalStopPlayerMove(int i)
	{
		if (grid[0, i]->Text == "X"&&grid[1, i]->Text == "X")
		{
			if (grid[2, i]->Text == "")
			{
				//places an O at the last position of a row if the player is about to win
				grid[2, i]->Text = "O";
				return true;
			}
		}
		if (grid[1, i]->Text == "X"&&grid[2, i]->Text == "X")
		{
			if (grid[0, i]->Text == "")
			{
				//places an O at the first position of a row if the player is about to win
				grid[0, i]->Text = "O";
				return true;
			}
		}
		if (grid[0, i]->Text == "X"&&grid[2, i]->Text == "X")
		{
			if (grid[1, i]->Text == "")
			{
				//places an O at the middle position of a row if the player is about to win
				grid[1, i]->Text = "O";
				return true;
			}
		}

		return false;
	}
public:
	OPlayer(array < Button^, 2> ^grid)
	{
		this->grid = grid;
	}

	void computerMove()
	{
		//takes the middle position if it is availiable 
		if (grid[1, 1]->Text == "")
		{
			grid[1, 1]->Text = "O";
		}
		else if (canSmartMove())
		{

		}
		else
		{
			srand(time(0));
			int x = (rand() % 3);
			int y = (rand() % 3);
			while (grid[x, y]->Text != "")//checks to make sure the random location is empty
			{
				x = (rand() % 3);
				y = (rand() % 3);
			}

			grid[x, y]->Text = "O";
		}
	}

};