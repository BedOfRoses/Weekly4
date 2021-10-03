#include <iostream>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <conio.h>

//Task 1 Calculator :: https://github.com/BedOfRoses/MyThirdCalculator

/*
* TASKS:
2. Make an empty 10x 10 char array  - a 1 or 2D array, or Vector. This is for example used in a chess board or Pacman.   2.1  use getch() or _getch() to get a key from user : for instance arrow keys or ( a - w- s -d ) keys to move around the table.   2.2   starting point can be either random or you can start from ( 0).   2.3  put  char '\\' and '/'  in the 2 different places on your board, and if you get to char / go one level down and if you get to \ go one level up and if get to char 'G' your program will terminate, otherwise you can freely move around.

3. Make a program that can hold names and phone numbers. (use struct)
The program should hold this info for max 10 persons. Use an array or vector.
Make functionality so user can input information, and print it to screen ( console).
*/

//FUNCTIONS

void printTable();
void player();
void playerMovement();
void gaming();
void menu();

//THE TABLE
int row = { 3 };
int col = { 3 };
bool isClearing = true;
bool isPlaying = true;


//Starting table with a 10x10 place
char  table[10][10] = {


	//  0	   1	2	 3	  4	   5    6    7    8    9
	  {'X', 'X', 'X', 'X' ,'X', 'X', 'X', 'X', 'X', 'X'},	//0
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//1
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//2
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//3
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//4
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//5
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//6
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//7
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//8
	  {'X', 'X', 'X', 'X' ,'X', 'X', 'X', 'X', 'X', 'X'},	//9


};

// Another table that removes the previous one in order to 
char  Default[10][10] = {


	//  0	   1	2	 3	  4	   5    6    7    8    9
	  {'X', 'X', 'X', 'X' ,'X', 'X', 'X', 'X', 'X', 'X'},	//0
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//1
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//2
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//3
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//4
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//5
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//6
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//7
	  {'X', ' ', ' ', ' ' ,' ', ' ', ' ', ' ', ' ', 'X'},	//8
	  {'X', 'X', 'X', 'X' ,'X', 'X', 'X', 'X', 'X', 'X'},	//9


};







int main() {


	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//// you can loop k higher to see more color choices
	//for (int k = 1; k < 255; k++)
	//{
	//	// pick the colorattribute k you want
	//	SetConsoleTextAttribute(hConsole, k);
	//	std::cout << k << " I want to be nice today!" << std::endl;
	//}

	//gaming();


	menu();

	return 0;
}

void printTable()
{
	//std::cout << "#####################";		// << '\n'; //BORDER
	for (int i{}; i < 10; i++) {


		for (int j{}; j < 10; j++) {

			if (j % 10 == 0) {
				std::cout << '\n';
			}
			/*system("color a");*/
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 233);

			std::cout << table[i][j];
		}

	}
	//std::cout<< "#####################" << '\n'; //BORDER

}

void player()
{

	table[col][row] = { 'A' };
}

void playerMovement()
{

	char userInput = _getch();
	/*std::cin >> userInput;*/

	switch (userInput)
	{
		//check if sentences for each move to make sure its not out of bounds ie. col, row > 10 or < 0
		//move player back into area.
	case 'a': case 'A':	//	MOVE LEFT		<----

		if (table[col][row] == 'X') {
			playerMovement();
		}
		else {
			row -= 1;
		}
		break;
	case 'w': case 'W':	//	MOVE UP			<----
		if (table[col][row] == 'X') {
			playerMovement();
		}
		else {
			col -= 1;
		}
		break;
	case 'd': case 'D':	//	MOVE RIGHT		<----
		if (table[col][row] == 'X') {
			playerMovement();
		}
		else {
			row += 1;
		}
		break;
	case 's': case 'S':	//	MOVE DOWN		<----
		if (table[col][row] == 'X') {
			playerMovement();
		}
		else {
			col += 1;
		}
		break;
	default:
		break;
	}

}

void copytable()
{
	for (int i{}; i < 10; i++)
	{
		for (int j{}; j < 10; j++)
		{
			/*system("color 2f");*/
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		//ADDS COLOR
			SetConsoleTextAttribute(hConsole, 233);					//ADDS COLOR
			table[i][j] = Default[i][j];
		}
	}
}

void winCondition()
{

	char WinnerDinner = { 'B' };
	table[7][8] = WinnerDinner;
}

void hindrance() {
	char blockade = { '/' };
	table[5][5] = blockade;

	table[6][8] = 'X';
	table[6][7] = 'X';
	table[7][7] = 'X';
	table[8][7] = 'X';
	table[8][8] = 'X';
}

void gaming()
{
	//intitialization of loop
	char playerr = { 'A' };
	table[row][col] = playerr;

	while (isClearing) {

		hindrance();
		winCondition();
		//gameplay loop 
		system("cls");			//CLEARS SCREEN
		printTable();			//PRINTS WHERE YOU ARE
		playerMovement();		//LETS USER CHOOSE DIRECTION OF PLAYER
		copytable();			//PRINTS THE DEFAULT TABLE WHICH REMOVES ALL THE PREVIOUS MOVES
		player();

		if (table[5][5] == 'A') {
			isClearing = false;

		}

	} 

		while (isPlaying) {
			winCondition();
			//gameplay loop 
			system("cls");			//CLEARS SCREEN
			printTable();			//PRINTS WHERE YOU ARE
			playerMovement();		//LETS USER CHOOSE DIRECTION OF PLAYER
			copytable();			//PRINTS THE DEFAULT TABLE WHICH REMOVES ALL THE PREVIOUS MOVES
			player();				//WHERE THE PLAYER IS

		//.... WIN CONDITION
			if (table[7][8] == 'A') {
				isPlaying = false;
				system("cls");
				system("color a");
				std::cout << "You are a GAMER";
				system("pause>0");
			}
		}

	}

void menu()
{
	char theChosenOne{};


	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 143);


	std::cout << "WEcLOmE tO GeMinG BOi!";
	
	
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 83);*/


	std::cout << "Choos gam: \n";
	std::cout << "1. Gamikn\n";
	std::cout << "2. gO homEe_\n";

	std::cin >> theChosenOne;

	switch (theChosenOne)
	{
	case '1':
		gaming();
		break;
	case '2':
		system("cls");
		std::cout << "Hahahahahaha.-.......\n MUAHAHAHAHAAHAH\n";
		Sleep(300);
		std::cout << "HAHAHAHAHAAHHAAHHAH\n";
		Sleep(500);
		std::cout << "HHAHAHAHAHAHAHAHAHAAHAH\n";
		Sleep(600);
		std::cout << "HHAHAHAHAHAHAHAHAHAAHAH\n";
		Sleep(650);
		std::cout << "HHAHAHAHAHAHAHAHAHAAAHHAEHAEHAEHAEHEHAH\n";
		Sleep(700);
		std::cout << "HHAHAHAHAHAHAHAHAHAAHAHAEHAEHAEHAH\n";
		Sleep(800);
		std::cout << "HHAHAHAHAHAHAHAHAHAAHAH\n";
		Sleep(900);
		Sleep(3000);
		std::cout << "HAH!";
		Sleep(150);
		
		system("cls");
		std::cout << "YOU THINK YOU CAN JUST LEAVE AFTER COMING HERE????";
		Sleep(3500);

		system("cls");
		std::cout << "SHOW ME WHAT YOU GOT!!!";
		Sleep(1000);
		system("cls");
		gaming();

	default:
		break;
	}
	




}

