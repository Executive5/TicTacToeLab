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
 ref class winChecker
{
	array<Button^, 2> ^grid = gcnew array<Button^, 2>(3, 3);
public:
	winChecker(array < Button^, 2> ^grid)
	{
		this->grid = grid;
	}
private:
	bool isDiagonal(String^ player)
	{
		
		if (grid[0, 0]->Text == player || grid[0, 2]->Text == player)
		{
		if (grid[1, 1]->Text == player)
		{
		if (grid[0, 0]->Text == player &&grid[2, 2]->Text == player)
		{
		return true;
		}
		else if (grid[0, 2]->Text == player &&grid[2, 0]->Text == player)
		{
		return true;
		}

		}
		}
		
		return false;

	}
	bool isHorizantal(String^ player)
	{
		for (int i = 0; i < 3; i++)
		{
			if (grid[0, i]->Text==player)
			{
				if (grid[1, i]->Text == player)
				{
					if (grid[2, i]->Text == player)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool isVertical(String^ player)
	{
		for (int i = 0; i < 3; i++)
		{
			if (grid[i, 0]->Text == player)
			{
				if (grid[i, 1]->Text == player)
				{
					if (grid[i, 2]->Text == player)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
public :
	bool isWinner(String^ player)
	{
		if (isDiagonal(player))
		{
			return true;
		}
		else if (isHorizantal(player))
		{
			return true;
		}
		else if (isVertical(player))
		{
			return true;
		}
		
		return false;
	}

	
	bool isDraw()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i, j]->Text == "")
				{
					return false;
				}
			}
		}
		return true;
	}
	
};