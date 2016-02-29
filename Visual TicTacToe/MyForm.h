#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WinConditions.h"
#include "OPlayer.h"

namespace Visual_TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	

	public ref class MyForm : public System::Windows::Forms::Form
	{
		

		
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		array<Button^, 2> ^grid = gcnew array<Button^, 2>(3, 3);//An array of Buttons
		winChecker^ win= gcnew winChecker(grid);// A class that checks if a player has won or if there is a draw
	private: System::Windows::Forms::Timer^  timer1;

	public:
		OPlayer^ op = gcnew OPlayer(grid);// the class for the AI player

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Void Clicked(System::Object^  sender, System::EventArgs^  e) 
	{//The method that is preformed when any button in grid is pressed
		Button^ button = dynamic_cast<Button^>(sender);
		if (button->Text != "X" && button->Text != "O")
		{
			button->Text = "X";
			
		
			timer1->Enabled = true;// enables the timer for the AI move
			
		}
		if (win->isWinner("X"))//checks if X is the winner
		{
			MessageBox::Show("The winner is X");
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					grid[i, j]->Enabled = false;
				}
			}
			Application::Restart();//restarts the program if the player X wins
		}
		 
		else if (win->isDraw())// checks if it is a draw 
		{
			MessageBox::Show("Draw");
			Application::Restart();// restarts the program if there is a draw
		}
	}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 503);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		int x = 100;
		int y = 100;
		
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{//Initilizes all of the buttons 
				grid[i, j] = gcnew Button;
				grid[i, j]->Location = Point(x, y);
				grid[i, j]->Parent = this;
				grid[i, j]->Size::set(Drawing::Size(100, 100));
				grid[i, j]->Text = "";
				grid[i, j]->Click += gcnew System::EventHandler(this, &MyForm::Clicked);
				this->Controls->Add(grid[i, j]);
				grid[i,j]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				
			
				x += 150;
			}
				x = 100; 
			y += 150;
		}
		
	
	}
	
			 
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{// The AI move
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//disables all the button while the computer is making its move
				grid[i, j]->Enabled = false;
			}
		}

		if (!win->isDraw()&&!win->isWinner("X"))
		{
			//the computers move
			op->computerMove();
		}
		if (win->isWinner("O"))
		{
			//declares if the computer has won
			timer1->Enabled = false;
			MessageBox::Show("The winner is O");
			Application::Restart();
			
		}
		else
		{
			//renables the buttons if the computer has not won
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					grid[i, j]->Enabled = true;
				}
			}

			timer1->Enabled = false;
		}
		

	}
};
}

