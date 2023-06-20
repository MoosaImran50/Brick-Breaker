#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include <conio.h>
#include <fstream>
#include <time.h>
#include <string>;
#include <sstream> 
#include <Windows.h>
using namespace std;

void SetCursorPosition(int x, int y) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(output, pos);
}

void bb(int x1, int y1, int x2, int y2) {
	COLORREF white = RGB(255, 255, 255);
	COLORREF pink = RGB(255, 182, 192);
	myRect(x1, y1, x2, y2, white, pink);
}

void tb(int x1, int y1, int x2, int y2, int tx1, int ty1) {
	COLORREF white = RGB(255, 255, 255);
	COLORREF pink = RGB(255, 182, 192);
	myRect(x1, y1, x2, y2, white, pink);
	COLORREF red = RGB(255, 0, 0);
	int size = 8;
	for (int i = -size; i < size; i++) {
		myLine(tx1, ty1, tx1 + i, ty1 - 10, red);
	}
}

void cb(int x1, int y1, int x2, int y2, int cx1, int cy1, int cx2, int cy2) {
	COLORREF white = RGB(255, 255, 255);
	COLORREF pink = RGB(255, 182, 192);
	myRect(x1, y1, x2, y2, white, pink);
	COLORREF green = RGB(0, 169, 0);
	myEllipse(cx1, cy1, cx2, cy2, green, green);
}

void pb(int x1, int y1, int x2, int y2, int px1, int py1, int px2, int py2) {
	COLORREF white = RGB(255, 255, 255);
	COLORREF pink = RGB(255, 182, 192);
	COLORREF yellow = RGB(255, 255, 0);
	myRect(x1, y1, x2, y2, white, pink);
	myLine(px1, py1, px2, py2, yellow);
	myLine(px1 + 2, py1, px2 + 2, py2, yellow);
	myLine(px1 + 4, py1, px2 + 4, py2, yellow);
	myLine(px1 + 6, py1, px2 + 6, py2, yellow);
	myLine(px1 + 8, py1, px2 + 8, py2, yellow);
	myLine(px1 + 10, py1, px2 + 10, py2, yellow);
	myLine(px1 + 12, py1, px2 + 12, py2, yellow);
}

void rb(int x1, int y1, int x2, int y2, int rx1, int ry1, int rx2, int ry2) {
	COLORREF white = RGB(255, 255, 255);
	COLORREF pink = RGB(255, 182, 192);
	COLORREF grey = RGB(105, 105, 105);
	myRect(x1, y1, x2, y2, white, pink);
	myRect(rx1, ry1, rx2, ry2, grey, grey);
}

void blackconsole() {
	//making console BLACK
	COLORREF black = RGB(12, 12, 12);
	myRect(50, 10, 1300, 460, black, black);
}

void BlackBrick(int x1, int y1, int x2, int y2) {
	COLORREF black = RGB(12, 12, 12);
	myRect(x1, y1, x2, y2, black, black);
}

void InitialiseBoxForNewGame(int x1, int& y1, int x2, int& y2, int& rows, int n, int& brickcounter, int(&brtype)[7][18], int(&brcoord)[7][18][4]) {

	blackconsole();

	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(255, 0, 0);

	myLine(50, 10, 1140, 10, white);
	myLine(50, 460, 1140, 460, white);
	myLine(50, 10, 50, 460, white);
	myLine(1140, 10, 1140, 460, white);
	myLine(1140, 10, 1300, 10, white);
	myLine(1140, 460, 1300, 460, white);
	myLine(1300, 10, 1300, 460, white);

	char instruct1[] = "PRESS  'S'  TO SAVE";
	char instruct2[] = "PRESS  'A'  AND  'D'  TO MOVE BAT";
	char instruct3[] = "PRESS  'SPACEBAR'  TO PAUSE AND TO RESUME";
	myDrawTextWithFont(500, 500, 35, instruct1, white, red);
	myDrawTextWithFont(450, 540, 35, instruct2, white, red);
	myDrawTextWithFont(400, 580, 35, instruct3, white, red);

	//tx1 is 25 added to rectangle x1
	//ty1 is 12 added to rectangle y1
	int tx1 = x1 + 25;
	int ty1 = y1 + 12;
	int size = 8;

	//cx1 is 20 added to rectangle x1
	//cx2 is 30 added to rectangle x1
	//cy1 is 2 added to rectangle y1
	//cy2 is 13 added to rectangle y1
	int cx1 = x1 + 20;
	int cx2 = x1 + 30;
	int cy1 = y1 + 2;
	int cy2 = y1 + 13;

	//px1 is 17 added to rectangle x1
	//px2 is 20 added to rectangle x1
	//py1 is 11 added to rectangle y1
	//py2 is 2 added to rectangle y1
	//after printing every line, add 2 in x1 and x2
	int px1 = x1 + 17;
	int px2 = x1 + 20;
	int py1 = y1 + 11;
	int py2 = y1 + 2;

	//rx1 is 10 added to rectangle x1
	//rx2 is 40 added to rectangle x1
	//ry1 is 3 added to rectangle y1
	//ry2 is 12 added to rectangle y1
	int rx1 = x1 + 10;
	int rx2 = x1 + 40;
	int ry1 = y1 + 3;
	int ry2 = y1 + 12;

	srand(time(0));

	for (int j = 0; j < rows; j++)
	{
		x1 = 60;
		x2 = 110;

		tx1 = x1 + 25;
		size = 8;

		cx1 = x1 + 20;
		cx2 = x1 + 30;

		px1 = x1 + 17;
		px2 = x1 + 20;

		rx1 = x1 + 10;
		rx2 = x1 + 40;

		for (int i = 0; i < 18; i++)
		{
			n = rand() % 11;
			if (n == 0)
			{
				tb(x1, y1, x2, y2, tx1, ty1);
				//triangle brick is type 0
				brtype[j][i] = 0;
			}
			else if (n == 1)
			{
				cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
				//circle brick is type 1
				brtype[j][i] = 1;
			}
			else if (n == 2)
			{
				pb(x1, y1, x2, y2, px1, py1, px2, py2);
				//parallelogram brick is type 2
				brtype[j][i] = 2;
			}
			else if (n == 3)
			{
				rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
				//rectangle brick is type 3
				brtype[j][i] = 3;
			}
			else
			{
				bb(x1, y1, x2, y2);
				//basic brick is type 4
				brtype[j][i] = 4;
			}

			//storing coordinates of each brick
			brcoord[j][i][0] = x1;
			brcoord[j][i][1] = y1;
			brcoord[j][i][2] = x2;
			brcoord[j][i][3] = y2;

			//incrementing brick counter
			brickcounter++;

			//setting x coordinates for next brick
			x1 = x1 + 60;
			x2 = x2 + 60;
			tx1 = tx1 + 60;
			cx1 = cx1 + 60;
			cx2 = cx2 + 60;
			px1 = px1 + 60;
			px2 = px2 + 60;
			rx1 = rx1 + 60;
			rx2 = rx2 + 60;
		}

		//setting y coordinates for next brick
		y1 = y1 + 25;
		y2 = y2 + 25;
		ty1 = ty1 + 25;
		cy1 = cy1 + 25;
		cy2 = cy2 + 25;
		py1 = py1 + 25;
		py2 = py2 + 25;
		ry1 = ry1 + 25;
		ry2 = ry2 + 25;
	}
}

void savegame(int brtype[7][18], int brickcounter, int rows, float life, int score) {
	ofstream save;
	save.open("save.txt");
	save << score << ",";
	save << life << ",";
	save << brickcounter << ",";
	save << rows << ",";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 18; j++) {
			save << brtype[i][j] << ",";
		}
	}
	save.close();
}

void InitialiseBoxForLoadGame(int x1, int& y1, int x2, int& y2, int rows, int& brickcounter, int brtype[7][18], int(&brcoord)[7][18][4]) {
	blackconsole();

	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(255, 0, 0);

	myLine(50, 10, 1140, 10, white);
	myLine(50, 460, 1140, 460, white);
	myLine(50, 10, 50, 460, white);
	myLine(1140, 10, 1140, 460, white);
	myLine(1140, 10, 1300, 10, white);
	myLine(1140, 460, 1300, 460, white);
	myLine(1300, 10, 1300, 460, white);

	char instruct1[] = "PRESS  'S'  TO SAVE";
	char instruct2[] = "PRESS  'A'  AND  'D'  TO MOVE BAT";
	char instruct3[] = "PRESS  'SPACEBAR'  TO PAUSE AND TO RESUME";
	myDrawTextWithFont(500, 500, 35, instruct1, white, red);
	myDrawTextWithFont(450, 540, 35, instruct2, white, red);
	myDrawTextWithFont(400, 580, 35, instruct3, white, red);

	//tx1 is 25 added to rectangle x1
	//ty1 is 12 added to rectangle y1
	int tx1 = x1 + 25;
	int ty1 = y1 + 12;
	int size = 8;

	//cx1 is 20 added to rectangle x1
	//cx2 is 30 added to rectangle x1
	//cy1 is 2 added to rectangle y1
	//cy2 is 13 added to rectangle y1
	int cx1 = x1 + 20;
	int cx2 = x1 + 30;
	int cy1 = y1 + 2;
	int cy2 = y1 + 13;

	//px1 is 17 added to rectangle x1
	//px2 is 20 added to rectangle x1
	//py1 is 11 added to rectangle y1
	//py2 is 2 added to rectangle y1
	//after printing every line, add 2 in x1 and x2
	int px1 = x1 + 17;
	int px2 = x1 + 20;
	int py1 = y1 + 11;
	int py2 = y1 + 2;

	//rx1 is 10 added to rectangle x1
	//rx2 is 40 added to rectangle x1
	//ry1 is 3 added to rectangle y1
	//ry2 is 12 added to rectangle y1
	int rx1 = x1 + 10;
	int rx2 = x1 + 40;
	int ry1 = y1 + 3;
	int ry2 = y1 + 12;

	for (int j = 0; j < rows; j++)
	{
		x1 = 60;
		x2 = 110;

		tx1 = x1 + 25;
		size = 8;

		cx1 = x1 + 20;
		cx2 = x1 + 30;

		px1 = x1 + 17;
		px2 = x1 + 20;

		rx1 = x1 + 10;
		rx2 = x1 + 40;

		for (int i = 0; i < 18; i++)
		{

			if (brtype[j][i] == 0)
			{
				tb(x1, y1, x2, y2, tx1, ty1);
			}
			else if (brtype[j][i] == 1)
			{
				cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
				//circle brick is type 1
			}
			else if (brtype[j][i] == 2)
			{
				pb(x1, y1, x2, y2, px1, py1, px2, py2);
				//parallelogram brick is type 2
			}
			else if (brtype[j][i] == 3)
			{
				rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
				//rectangle brick is type 3
			}
			else if (brtype[j][i] == 4)
			{
				bb(x1, y1, x2, y2);
				//basic brick is type 4
			}
			else if (brtype[j][i] == -1)
			{
				BlackBrick(x1, y1, x2, y2);
				//black brick is type -1
			}

			//storing coordinates of each brick
			brcoord[j][i][0] = x1;
			brcoord[j][i][1] = y1;
			brcoord[j][i][2] = x2;
			brcoord[j][i][3] = y2;

			//setting x coordinates for next brick
			x1 = x1 + 60;
			x2 = x2 + 60;
			tx1 = tx1 + 60;
			cx1 = cx1 + 60;
			cx2 = cx2 + 60;
			px1 = px1 + 60;
			px2 = px2 + 60;
			rx1 = rx1 + 60;
			rx2 = rx2 + 60;
		}

		//setting y coordinates for next brick
		y1 = y1 + 25;
		y2 = y2 + 25;
		ty1 = ty1 + 25;
		cy1 = cy1 + 25;
		cy2 = cy2 + 25;
		py1 = py1 + 25;
		py2 = py2 + 25;
		ry1 = ry1 + 25;
		ry2 = ry2 + 25;
	}
}

void deletelife(float& life) {
	life = life - 1;
}

void BlackOriginalLifeText(char l[]) {
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	char s[] = "Lives: ";
	myDrawTextWithFont(1150, 20, 35, s, black, black);
	myDrawTextWithFont(1150, 50, 30, l, black, black);
}

void DisplayLife(char l[]) {
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	char liv[] = "Lives: ";
	myDrawTextWithFont(1150, 20, 35, liv, black, lightred);
	myDrawTextWithFont(1150, 50, 30, l, black, lightred);
}

void DisplayScore(int score) {
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	COLORREF white = RGB(255, 255, 255);
	char s[] = "Score: ";
	char a[] = "0";
	myDrawTextWithFont(1150, 115, 35, s, black, lightred);
	if (score == 0) {
		myDrawTextWithFont(1160, 159, 18, a, white, black);
	}
	else {
		myDrawTextWithFont(1160, 159, 18, a, black, black);
	}
}

void bat(int batx1, int batx2) {
	COLORREF lightblue = RGB(0, 204, 255);
	COLORREF lemonyellow = RGB(255, 244, 79);
	COLORREF darkpink = RGB(255, 0, 128);
	COLORREF orange = RGB(255, 140, 0);
	COLORREF lightred = RGB(255, 40, 0);
	myRect(batx1, 443, batx2, 455, lightblue, lightblue);
	myRect(batx1 + 30, 443, batx2 + 30, 455, lemonyellow, lemonyellow);
	myRect(batx1 + 60, 443, batx2 + 60, 455, darkpink, darkpink);
	myRect(batx1 + 90, 443, batx2 + 90, 455, orange, orange);
	myRect(batx1 + 120, 443, batx2 + 120, 455, lightred, lightred);
}

void deletebat(int batx1, int batx2) {
	COLORREF black = RGB(12, 12, 12);
	myRect(batx1, 443, batx2 + 120, 455, black, black);
}

void ball(int bx1, int by1, int bx2, int by2) {
	COLORREF silver = RGB(208, 210, 209);
	myEllipse(bx1, by1, bx2, by2, silver, silver);
}

void deleteball(int bx1, int by1, int bx2, int by2) {
	COLORREF black = RGB(12, 12, 12);
	myEllipse(bx1, by1, bx2, by2, black, black);
}

void deletebrick(int x1, int y1, int x2, int y2, int type, float& life, int& score, bool& lifeflag, int rows, char l[]) {
	COLORREF black = RGB(12, 12, 12);
	myRect(x1, y1, x2, y2, black, black);
	//triangle brick is type 0
	if (type == 0)
	{
		life = life - 0.5;
		lifeflag = true;
	}
	//circle brick is type 1
	else if (type == 1)
	{
		if (life <= 4)
		{
			life = life + 1;
			lifeflag = true;
		}
		else
		{
			score = score + 10;
		}

	}
	//parallelogram brick is type 2
	else if (type == 2)
	{
		//have to add adjacent brick remover here
		score = score + 10;
	}
	//rectangle brick is type 3
	else if (type == 3)
	{
		if (rows == 7) {
			score = score - 5;
		}
	}
	//basic brick is type 4
	else if (type == 4)
	{
		score = score + 2;
	}
	SetCursorPosition(145, 10);
	DisplayScore(score);
	cout << score;
	DisplayLife(l);
	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(255, 0, 0);

	myLine(50, 10, 1140, 10, white);
	myLine(50, 460, 1140, 460, white);
	myLine(50, 10, 50, 460, white);
	myLine(1140, 10, 1140, 460, white);
	myLine(1140, 10, 1300, 10, white);
	myLine(1140, 460, 1300, 460, white);
	myLine(1300, 10, 1300, 460, white);
}

void reflectoffbrick(bool flagx, bool& flagy, bool doubletouchbelow, bool doubletouchabove) {

	if (doubletouchbelow == true)
	{
		flagy = true;
	}
	else if (doubletouchabove == true)
	{
		flagy = false;
	}
	else if (flagy == true)
	{
		flagy = false;
	}
	else if (flagy == false) {
		flagy = true;
	}

}

void reprintingbricks(int brtype[7][18], int brcoord[7][18][4], int rows) {
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < 18; i++)
		{
			//50x15 is area of one brick
			int x1 = brcoord[j][i][0];
			int y1 = brcoord[j][i][1];
			int x2 = brcoord[j][i][2];
			int y2 = brcoord[j][i][3];

			//tx1 is 25 added to rectangle x1
			//ty1 is 12 added to rectangle y1
			int tx1 = x1 + 25;
			int ty1 = y1 + 12;
			int size = 8;

			//cx1 is 20 added to rectangle x1
			//cx2 is 30 added to rectangle x1
			//cy1 is 2 added to rectangle y1
			//cy2 is 13 added to rectangle y1
			int cx1 = x1 + 20;
			int cx2 = x1 + 30;
			int cy1 = y1 + 2;
			int cy2 = y1 + 13;

			//px1 is 17 added to rectangle x1
			//px2 is 20 added to rectangle x1
			//py1 is 11 added to rectangle y1
			//py2 is 2 added to rectangle y1
			//after printing every line, add 2 in x1 and x2
			int px1 = x1 + 17;
			int px2 = x1 + 20;
			int py1 = y1 + 11;
			int py2 = y1 + 2;

			//rx1 is 10 added to rectangle x1
			//rx2 is 40 added to rectangle x1
			//ry1 is 3 added to rectangle y1
			//ry2 is 12 added to rectangle y1
			int rx1 = x1 + 10;
			int rx2 = x1 + 40;
			int ry1 = y1 + 3;
			int ry2 = y1 + 12;

			if (brtype[j][i] == 0)
			{
				tb(x1, y1, x2, y2, tx1, ty1);
			}
			else if (brtype[j][i] == 1)
			{
				cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
				//circle brick is type 1
			}
			else if (brtype[j][i] == 2)
			{
				pb(x1, y1, x2, y2, px1, py1, px2, py2);
				//parallelogram brick is type 2
			}
			else if (brtype[j][i] == 3)
			{
				rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
				//rectangle brick is type 3
			}
			else if (brtype[j][i] == 4)
			{
				bb(x1, y1, x2, y2);
				//basic brick is type 4
			}
			else if (brtype[j][i] == -1)
			{
				BlackBrick(x1, y1, x2, y2);
				//black brick is type -1
			}
			//setting x coordinates for next brick
			x1 = x1 + 60;
			x2 = x2 + 60;
			tx1 = tx1 + 60;
			cx1 = cx1 + 60;
			cx2 = cx2 + 60;
			px1 = px1 + 60;
			px2 = px2 + 60;
			rx1 = rx1 + 60;
			rx2 = rx2 + 60;
		}
	}
}

void lost() {
	ClearScreen();
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	char s[] = "YOU LOSE";
	myDrawTextWithFont(50, 50, 50, s, black, lightred);
}

void win() {
	ClearScreen();
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	char s[] = "YOU WIN";
	myDrawTextWithFont(50, 50, 50, s, black, lightred);
}

void save() {
	ClearScreen();
	COLORREF black = RGB(0, 0, 0);
	COLORREF lightred = RGB(255, 40, 0);
	char s[] = "GAME HAS BEEN SAVED";
	myDrawTextWithFont(50, 50, 50, s, black, lightred);
}

void savescore(int score) {
	ofstream MyFile;
	MyFile.open("highscores.txt", ios::app);
	char name[25];
	cout << "Enter Your Name: " << endl;
	cin.getline(name, 20);
	MyFile << score << ":" << name << endl;
	MyFile.close();
}

void displayhighscores() {

	ClearScreen();

	string arr[100];
	string t;
	string s1;
	string s2;

	ifstream file("highscores.txt", ios::in);

	int counter = 0;
	while (getline(file, t)) {
		arr[counter] = t;
		counter++;
	}

	file.close();

	int score1;
	int score2;
	if ((counter > 1))
	{
		for (int i = 0; i < counter; i++)
		{
			for (int j = i + 1; j < counter; j++)
			{
				s1 = arr[i];
				s2 = arr[j];

				int k = 0;
				int l = 0;

				t = "";

				while (s1[k] != ':')
				{
					t = t + s1[k];
					k = k + 1;
				}
				stringstream geek1(t);
				geek1 >> score1;

				t = "";

				while (s2[l] != ':')
				{
					t = t + s2[l];
					l = l + 1;
				}
				stringstream geek2(t);
				geek2 >> score2;

				t = "";

				if (score1 < score2)
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}
		if (counter < 10)
		{
			cout << "HIGHSCORES: " << endl << endl;
			for (int i = 0; i < counter; i++) {
				cout << arr[i] << endl;
			}
			cout << endl;
		}
		if (counter >= 10)
		{
			cout << "HIGHSCORES: " << endl << endl;
			for (int i = 0; i < 10; i++) {
				cout << arr[i] << endl;
			}
			cout << endl;
		}
	}
	else if (counter == 1)
	{
		cout << arr[0] << endl;
	}
	else
	{
		cout << "THERE IS NOTHING IN FILE" << endl;
	}
}

void game(char option) {

	//clearing menu and drawing the line everything will be inside
	ClearScreen();

	srand(time(0));

	//flag to terminate and save the game
	bool saveflag = false;

	//brick types and coordinates to be stored using 2d and 3d array
	int brtype[7][18];
	int brcoord[7][18][4];
	int brickcounter = 0;

	//50x15 is area of one brick
	int x1 = 60;
	int x2 = 110;
	int y1 = 20;
	int y2 = 35;

	//tx1 is 25 added to rectangle x1
	//ty1 is 12 added to rectangle y1
	int tx1 = x1 + 25;
	int ty1 = y1 + 12;
	int size = 8;

	//cx1 is 20 added to rectangle x1
	//cx2 is 30 added to rectangle x1
	//cy1 is 2 added to rectangle y1
	//cy2 is 13 added to rectangle y1
	int cx1 = x1 + 20;
	int cx2 = x1 + 30;
	int cy1 = y1 + 2;
	int cy2 = y1 + 13;

	//px1 is 17 added to rectangle x1
	//px2 is 20 added to rectangle x1
	//py1 is 11 added to rectangle y1
	//py2 is 2 added to rectangle y1
	//after printing every line, add 2 in x1 and x2
	int px1 = x1 + 17;
	int px2 = x1 + 20;
	int py1 = y1 + 11;
	int py2 = y1 + 2;

	//rx1 is 10 added to rectangle x1
	//rx2 is 40 added to rectangle x1
	//ry1 is 3 added to rectangle y1
	//ry2 is 12 added to rectangle y1
	int rx1 = x1 + 10;
	int rx2 = x1 + 40;
	int ry1 = y1 + 3;
	int ry2 = y1 + 12;

	int n = 0;
	int rows = 5;

	//life declaration
	float life = 3.0;
	char l[] = "3.0";
	bool lifeflag = false;

	//score declaration
	int score = 0;

	//loading variables from file
	if ((option == 'l') || (option == 'L'))
	{
		string rawinput;
		string t;

		ifstream file("save.txt");
		getline(file, rawinput);

		file.close();

		int k = 0;
		int arrayofbrtype[130];
		for (int i = 0; i < 4; i++)
		{
			t = "";
			while (rawinput[k] != ',')
			{
				t = t + rawinput[k];
				k = k + 1;
			}
			k = k + 1;
			if (i == 0)
			{
				stringstream geek1(t);
				geek1 >> score;
			}
			if (i == 1)
			{
				stringstream geek1(t);
				geek1 >> life;
			}
			if (i == 3)
			{
				stringstream geek1(t);
				geek1 >> rows;
			}
			if (i == 2)
			{
				stringstream geek1(t);
				geek1 >> brickcounter;
			}
		}

		for (int i = 0; i < rows * 18; i++)
		{
			t = "";
			while (rawinput[k] != ',')
			{
				t = t + rawinput[k];
				k = k + 1;
			}
			k = k + 1;
			stringstream geek1(t);
			geek1 >> arrayofbrtype[i];
		}

		int counter = 0;
		for (int j = 0; j < rows; j++)
		{
			for (int i = 0; i < 18; i++)
			{
				brtype[j][i] = arrayofbrtype[counter];
				counter++;
			}
		}

		InitialiseBoxForLoadGame(x1, y1, x2, y2, rows, brickcounter, brtype, brcoord);
		reprintingbricks(brtype, brcoord, rows);
	}
	//starting new game
	else
	{
		InitialiseBoxForNewGame(x1, y1, x2, y2, rows, n, brickcounter, brtype, brcoord);
	}

	DisplayLife(l);
	DisplayScore(score);

	while ((life > 0) && (brickcounter != 0))
	{
		//bat coordinates
		int batx1 = 520;
		int batx2 = 549;

		//initialising bat
		bat(batx1, batx2);

		//ball coordinates
		int bx1 = 585; //left of ball
		int by1 = 260; //top of ball
		int bx2 = 605; //right of ball
		int by2 = 280; //bottom of ball

		//initialising ball
		ball(bx1, by1, bx2, by2);

		//ball center
		int bc;
		//flagy true means ball going down and vice versa
		bool flagy = true;
		//flagx true means ball going right and vice versa
		bool flagx = true;
		int angle = 90;
		bool start = true;

		//bat movement
		char m = '0';
		while ((m != '\0') && (brickcounter != 0))
		{
			//setting lifeflag back to false
			lifeflag = false;
			//calculating center of ball
			bc = (bx1 + bx2) / 2;
			deleteball(bx1, by1, bx2, by2);

			if ((bc + 6 >= batx1) && (bc - 6 <= (batx2 + 120)) && (by2 >= 442)) {
				flagy = false;
				start = false;
				if ((bc + 6 >= batx1) && (bc <= batx2)) {
					flagx = false;
					angle = 30;
				}
				else if ((bc >= batx1 + 30) && (bc <= batx2 + 30)) {
					flagx = false;
					angle = 60;
				}
				else if ((bc >= batx1 + 60) && (bc <= batx2 + 60)) {
					angle = 90;
				}
				else if ((bc >= batx1 + 90) && (bc <= batx2 + 90)) {
					flagx = true;
					angle = 120;
				}
				else if ((bc >= batx1 + 120) && (bc - 6 <= batx2 + 120)) {
					flagx = true;
					angle = 150;
				}
			}
			//ball starts to move down once it touches top of box going up
			if (by1 <= 12) {
				flagy = true;
			}
			//ball starts to move right once it touches left side of box
			if (bx1 <= 52) {
				flagx = true;
			}
			//ball starts to move left once it touches right side of box
			if (bx2 >= 1138) {
				flagx = false;
			}

			//right side angles of ball
			if (flagy == true && start == false && angle != 90) {
				if (angle == 120 && flagx == true) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 + 1;
					bx2 = bx2 + 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 120 && flagx == false) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 - 1;
					bx2 = bx2 - 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 150 && flagx == true) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 + 2;
					bx2 = bx2 + 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 150 && flagx == false) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 - 2;
					bx2 = bx2 - 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
			}
			else if (flagy == false && start == false && angle != 90) {
				if (angle == 120 && flagx == true) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 + 1;
					bx2 = bx2 + 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 120 && flagx == false) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 - 1;
					bx2 = bx2 - 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 150 && flagx == true) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 + 2;
					bx2 = bx2 + 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 150 && flagx == false) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 - 2;
					bx2 = bx2 - 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
			}

			//left side angles of ball
			if (flagy == true && start == false && angle != 90) {
				if (angle == 30 && flagx == true) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 + 2;
					bx2 = bx2 + 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 30 && flagx == false) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 - 2;
					bx2 = bx2 - 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 60 && flagx == true) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 + 1;
					bx2 = bx2 + 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 60 && flagx == false) {
					by1 = by1 + 1;
					by2 = by2 + 1;
					bx1 = bx1 - 1;
					bx2 = bx2 - 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
			}
			else if (flagy == false && start == false && angle != 90) {
				if (angle == 30 && flagx == true) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 + 2;
					bx2 = bx2 + 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 30 && flagx == false) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 - 2;
					bx2 = bx2 - 2;
					ball(bx1, by1, bx2, by2);
					Sleep(6);
				}
				else if (angle == 60 && flagx == true) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 + 1;
					bx2 = bx2 + 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
				else if (angle == 60 && flagx == false) {
					by1 = by1 - 1;
					by2 = by2 - 1;
					bx1 = bx1 - 1;
					bx2 = bx2 - 1;
					ball(bx1, by1, bx2, by2);
					Sleep(4);
				}
			}

			//sending ball straight up from center of bat
			else if (flagy == true && angle == 90) {
				by1 = by1 + 1;
				by2 = by2 + 1;
				ball(bx1, by1, bx2, by2);
				Sleep(3);
			}
			else if (flagy == false && angle == 90) {
				by1 = by1 - 1;
				by2 = by2 - 1;
				ball(bx1, by1, bx2, by2);
				Sleep(3);
			}
			else if (start == true && angle == 90) {
				deleteball(bx1, by1, bx2, by2);
				by1 = by1 + 1;
				by2 = by2 + 1;
				ball(bx1, by1, bx2, by2);
				Sleep(3);
			}

			//updating number of rows
			for (int j = rows - 1; j > rows - 2; j--) {
				bool deleterow = true;
				for (int i = 0; i < 18 && deleterow == true; i++) {
					if (brtype[j][i] != -1) {
						deleterow = false;
					}
				}
				if (deleterow == true) {
					rows = rows - 1;
					y1 = y1 - 25;
					y2 = y2 - 25;
					ty1 = ty1 - 25;
					cy1 = cy1 - 25;
					cy2 = cy2 - 25;
					py1 = py1 - 25;
					py2 = py2 - 25;
					ry1 = ry1 - 25;
					ry2 = ry2 - 25;
				}
			}

			//ball interaction with bricks
			for (int j = 0; j < rows; j++)
			{
				for (int i = 0; i < 18; i++)
				{
					if (brtype[j][i] != -1)
					{
						bool doubletouchabove = false;
						bool doubletouchbelow = false;
						//ball touches bricks from above
						if ((by1 >= brcoord[j][i][1]) && (by1 <= brcoord[j][i][3]))
						{
							if (((bx1 >= brcoord[j][i][0]) && (bx1 <= brcoord[j][i][2])) && ((bx2 >= brcoord[j][i + 1][0]) && (bx2 <= brcoord[j][i + 1][2])) && (brtype[j][i + 1] != -1))
							{
								doubletouchabove = true;
								int tempx1, tempy1, tempx2, tempy2;
								tempx1 = brcoord[j][i][0];
								tempy1 = brcoord[j][i][1];
								tempx2 = brcoord[j][i][2];
								tempy2 = brcoord[j][i][3];
								int type = brtype[j][i];
								deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
								brickcounter = brickcounter - 1;
								reflectoffbrick(flagx, flagy, doubletouchbelow, doubletouchabove);
								//type 2 is parallelogram
								if (type == 2) {
									if (brtype[j - 1][i] != -1 && (j - 1) >= 0 && (j - 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j - 1][i][0];
										tempy1 = brcoord[j - 1][i][1];
										tempx2 = brcoord[j - 1][i][2];
										tempy2 = brcoord[j - 1][i][3];
										brtype[j - 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j + 1][i] != -1 && (j + 1) >= 0 && (j + 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j + 1][i][0];
										tempy1 = brcoord[j + 1][i][1];
										tempx2 = brcoord[j + 1][i][2];
										tempy2 = brcoord[j + 1][i][3];
										brtype[j + 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i - 1] != -1 && j >= 0 && j < rows && (i - 1) < 18 && (i - 1) >= 0) {
										tempx1 = brcoord[j][i - 1][0];
										tempy1 = brcoord[j][i - 1][1];
										tempx2 = brcoord[j][i - 1][2];
										tempy2 = brcoord[j][i - 1][3];
										brtype[j][i - 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i + 1] != -1 && j >= 0 && j < rows && (i + 1) < 18 && (i + 1) >= 0) {
										tempx1 = brcoord[j][i + 1][0];
										tempy1 = brcoord[j][i + 1][1];
										tempx2 = brcoord[j][i + 1][2];
										tempy2 = brcoord[j][i + 1][3];
										brtype[j][i + 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
								}
								//type 3 is rectangle brick
								if ((type == 3) && (rows + 1 <= 7)) {
									for (int j = rows; j < (rows + 1) && (rows + 1) <= 7; j++)
									{
										x1 = 60;
										x2 = 110;

										tx1 = x1 + 25;
										size = 8;

										cx1 = x1 + 20;
										cx2 = x1 + 30;

										px1 = x1 + 17;
										px2 = x1 + 20;

										rx1 = x1 + 10;
										rx2 = x1 + 40;

										for (int i = 0; i < 18; i++)
										{
											n = rand() % 11;
											if (n == 0)
											{
												tb(x1, y1, x2, y2, tx1, ty1);
												//triangle brick is type 0
												brtype[j][i] = 0;
											}
											else if (n == 1)
											{
												cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
												//circle brick is type 1
												brtype[j][i] = 1;
											}
											else if (n == 2)
											{
												pb(x1, y1, x2, y2, px1, py1, px2, py2);
												//parallelogram brick is type 2
												brtype[j][i] = 2;
											}
											else if (n == 3)
											{
												rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
												//rectangle brick is type 3
												brtype[j][i] = 3;
											}
											else
											{
												bb(x1, y1, x2, y2);
												//basic brick is type 4
												brtype[j][i] = 4;
											}

											//storing coordinates of each brick
											brcoord[j][i][0] = x1;
											brcoord[j][i][1] = y1;
											brcoord[j][i][2] = x2;
											brcoord[j][i][3] = y2;

											//incrementing brick counter
											brickcounter++;

											//setting x coordinates for next brick
											x1 = x1 + 60;
											x2 = x2 + 60;
											tx1 = tx1 + 60;
											cx1 = cx1 + 60;
											cx2 = cx2 + 60;
											px1 = px1 + 60;
											px2 = px2 + 60;
											rx1 = rx1 + 60;
											rx2 = rx2 + 60;
										}

										//setting y coordinates for next brick
										y1 = y1 + 25;
										y2 = y2 + 25;
										ty1 = ty1 + 25;
										cy1 = cy1 + 25;
										cy2 = cy2 + 25;
										py1 = py1 + 25;
										py2 = py2 + 25;
										ry1 = ry1 + 25;
										ry2 = ry2 + 25;
									}
									rows = rows + 1;
								}
								//
								brtype[j][i] = -1;
								deleteball(bx1, by1, bx2, by2);
								//reprinting bricks this time with black bricks replacing those ball has bounce on and to prevent black ball from covering edges of bricks
								reprintingbricks(brtype, brcoord, n);
							}
							else if (((bx1 >= brcoord[j][i][0]) && (bx1 <= brcoord[j][i][2])) || ((bx2 >= brcoord[j][i][0]) && (bx2 <= brcoord[j][i][2])))
							{
								int tempx1, tempy1, tempx2, tempy2;
								tempx1 = brcoord[j][i][0];
								tempy1 = brcoord[j][i][1];
								tempx2 = brcoord[j][i][2];
								tempy2 = brcoord[j][i][3];
								int type = brtype[j][i];
								deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
								brickcounter = brickcounter - 1;
								reflectoffbrick(flagx, flagy, doubletouchbelow, doubletouchabove);
								//
								if (type == 2) {
									if (brtype[j - 1][i] != -1 && (j - 1) >= 0 && (j - 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j - 1][i][0];
										tempy1 = brcoord[j - 1][i][1];
										tempx2 = brcoord[j - 1][i][2];
										tempy2 = brcoord[j - 1][i][3];
										brtype[j - 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j + 1][i] != -1 && (j + 1) >= 0 && (j + 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j + 1][i][0];
										tempy1 = brcoord[j + 1][i][1];
										tempx2 = brcoord[j + 1][i][2];
										tempy2 = brcoord[j + 1][i][3];
										brtype[j + 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i - 1] != -1 && j >= 0 && j < rows && (i - 1) < 18 && (i - 1) >= 0) {
										tempx1 = brcoord[j][i - 1][0];
										tempy1 = brcoord[j][i - 1][1];
										tempx2 = brcoord[j][i - 1][2];
										tempy2 = brcoord[j][i - 1][3];
										brtype[j][i - 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i + 1] != -1 && j >= 0 && j < rows && (i + 1) < 18 && (i + 1) >= 0) {
										tempx1 = brcoord[j][i + 1][0];
										tempy1 = brcoord[j][i + 1][1];
										tempx2 = brcoord[j][i + 1][2];
										tempy2 = brcoord[j][i + 1][3];
										brtype[j][i + 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
								}
								if ((type == 3) && (rows + 1 <= 7)) {
									for (int j = rows; j < (rows + 1) && (rows + 1) <= 7; j++)
									{
										x1 = 60;
										x2 = 110;

										tx1 = x1 + 25;
										size = 8;

										cx1 = x1 + 20;
										cx2 = x1 + 30;

										px1 = x1 + 17;
										px2 = x1 + 20;

										rx1 = x1 + 10;
										rx2 = x1 + 40;

										for (int i = 0; i < 18; i++)
										{
											n = rand() % 11;
											if (n == 0)
											{
												tb(x1, y1, x2, y2, tx1, ty1);
												//triangle brick is type 0
												brtype[j][i] = 0;
											}
											else if (n == 1)
											{
												cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
												//circle brick is type 1
												brtype[j][i] = 1;
											}
											else if (n == 2)
											{
												pb(x1, y1, x2, y2, px1, py1, px2, py2);
												//parallelogram brick is type 2
												brtype[j][i] = 2;
											}
											else if (n == 3)
											{
												rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
												//rectangle brick is type 3
												brtype[j][i] = 3;
											}
											else
											{
												bb(x1, y1, x2, y2);
												//basic brick is type 4
												brtype[j][i] = 4;
											}

											//storing coordinates of each brick
											brcoord[j][i][0] = x1;
											brcoord[j][i][1] = y1;
											brcoord[j][i][2] = x2;
											brcoord[j][i][3] = y2;

											//incrementing brick counter
											brickcounter++;

											//setting x coordinates for next brick
											x1 = x1 + 60;
											x2 = x2 + 60;
											tx1 = tx1 + 60;
											cx1 = cx1 + 60;
											cx2 = cx2 + 60;
											px1 = px1 + 60;
											px2 = px2 + 60;
											rx1 = rx1 + 60;
											rx2 = rx2 + 60;
										}

										//setting y coordinates for next brick
										y1 = y1 + 25;
										y2 = y2 + 25;
										ty1 = ty1 + 25;
										cy1 = cy1 + 25;
										cy2 = cy2 + 25;
										py1 = py1 + 25;
										py2 = py2 + 25;
										ry1 = ry1 + 25;
										ry2 = ry2 + 25;
									}
									rows = rows + 1;
								}
								//
								brtype[j][i] = -1;
								deleteball(bx1, by1, bx2, by2);
								//reprinting bricks this time with black bricks replacing those ball has bounce on and to prevent black ball from covering edges of bricks
								reprintingbricks(brtype, brcoord, rows);
							}
						}
						//ball touches bricks from below
						else if ((by2 >= brcoord[j][i][1]) && (by2 <= brcoord[j][i][3]))
						{
							if (((bx1 >= brcoord[j][i][0]) && (bx1 <= brcoord[j][i][2])) && ((bx2 >= brcoord[j][i + 1][0]) && (bx2 <= brcoord[j][i + 1][2])) && (brtype[j][i + 1] != -1))
							{
								doubletouchbelow = true;
								int tempx1, tempy1, tempx2, tempy2;
								tempx1 = brcoord[j][i][0];
								tempy1 = brcoord[j][i][1];
								tempx2 = brcoord[j][i][2];
								tempy2 = brcoord[j][i][3];
								int type = brtype[j][i];
								deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
								brickcounter = brickcounter - 1;
								reflectoffbrick(flagx, flagy, doubletouchbelow, doubletouchabove);
								//
								if (type == 2) {
									if (brtype[j - 1][i] != -1 && (j - 1) >= 0 && (j - 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j - 1][i][0];
										tempy1 = brcoord[j - 1][i][1];
										tempx2 = brcoord[j - 1][i][2];
										tempy2 = brcoord[j - 1][i][3];
										brtype[j - 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j + 1][i] != -1 && (j + 1) >= 0 && (j + 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j + 1][i][0];
										tempy1 = brcoord[j + 1][i][1];
										tempx2 = brcoord[j + 1][i][2];
										tempy2 = brcoord[j + 1][i][3];
										brtype[j + 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i - 1] != -1 && j >= 0 && j < rows && (i - 1) < 18 && (i - 1) >= 0) {
										tempx1 = brcoord[j][i - 1][0];
										tempy1 = brcoord[j][i - 1][1];
										tempx2 = brcoord[j][i - 1][2];
										tempy2 = brcoord[j][i - 1][3];
										brtype[j][i - 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i + 1] != -1 && j >= 0 && j < rows && (i + 1) < 18 && (i + 1) >= 0) {
										tempx1 = brcoord[j][i + 1][0];
										tempy1 = brcoord[j][i + 1][1];
										tempx2 = brcoord[j][i + 1][2];
										tempy2 = brcoord[j][i + 1][3];
										brtype[j][i + 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
								}
								if ((type == 3) && (rows + 1 <= 7)) {
									for (int j = rows; j < (rows + 1) && (rows + 1) <= 7; j++)
									{
										x1 = 60;
										x2 = 110;

										tx1 = x1 + 25;
										size = 8;

										cx1 = x1 + 20;
										cx2 = x1 + 30;

										px1 = x1 + 17;
										px2 = x1 + 20;

										rx1 = x1 + 10;
										rx2 = x1 + 40;

										for (int i = 0; i < 18; i++)
										{
											n = rand() % 11;
											if (n == 0)
											{
												tb(x1, y1, x2, y2, tx1, ty1);
												//triangle brick is type 0
												brtype[j][i] = 0;
											}
											else if (n == 1)
											{
												cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
												//circle brick is type 1
												brtype[j][i] = 1;
											}
											else if (n == 2)
											{
												pb(x1, y1, x2, y2, px1, py1, px2, py2);
												//parallelogram brick is type 2
												brtype[j][i] = 2;
											}
											else if (n == 3)
											{
												rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
												//rectangle brick is type 3
												brtype[j][i] = 3;
											}
											else
											{
												bb(x1, y1, x2, y2);
												//basic brick is type 4
												brtype[j][i] = 4;
											}

											//storing coordinates of each brick
											brcoord[j][i][0] = x1;
											brcoord[j][i][1] = y1;
											brcoord[j][i][2] = x2;
											brcoord[j][i][3] = y2;

											//incrementing brick counter
											brickcounter++;

											//setting x coordinates for next brick
											x1 = x1 + 60;
											x2 = x2 + 60;
											tx1 = tx1 + 60;
											cx1 = cx1 + 60;
											cx2 = cx2 + 60;
											px1 = px1 + 60;
											px2 = px2 + 60;
											rx1 = rx1 + 60;
											rx2 = rx2 + 60;
										}

										//setting y coordinates for next brick
										y1 = y1 + 25;
										y2 = y2 + 25;
										ty1 = ty1 + 25;
										cy1 = cy1 + 25;
										cy2 = cy2 + 25;
										py1 = py1 + 25;
										py2 = py2 + 25;
										ry1 = ry1 + 25;
										ry2 = ry2 + 25;
									}
									rows = rows + 1;
								}
								//
								brtype[j][i] = -1;
								deleteball(bx1, by1, bx2, by2);
								//reprinting bricks this time with black bricks replacing those ball has bounce on and to prevent black ball from covering edges of bricks
								reprintingbricks(brtype, brcoord, rows);
							}
							else if (((bx1 >= brcoord[j][i][0]) && (bx1 <= brcoord[j][i][2])) || ((bx2 >= brcoord[j][i][0]) && (bx2 <= brcoord[j][i][2])))
							{
								int tempx1, tempy1, tempx2, tempy2;
								tempx1 = brcoord[j][i][0];
								tempy1 = brcoord[j][i][1];
								tempx2 = brcoord[j][i][2];
								tempy2 = brcoord[j][i][3];
								int type = brtype[j][i];
								deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
								brickcounter = brickcounter - 1;
								reflectoffbrick(flagx, flagy, doubletouchbelow, doubletouchabove);
								//
								if (type == 2) {
									if (brtype[j - 1][i] != -1 && (j - 1) >= 0 && (j - 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j - 1][i][0];
										tempy1 = brcoord[j - 1][i][1];
										tempx2 = brcoord[j - 1][i][2];
										tempy2 = brcoord[j - 1][i][3];
										brtype[j - 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j + 1][i] != -1 && (j + 1) >= 0 && (j + 1) < rows && i < 18 && i >= 0) {
										tempx1 = brcoord[j + 1][i][0];
										tempy1 = brcoord[j + 1][i][1];
										tempx2 = brcoord[j + 1][i][2];
										tempy2 = brcoord[j + 1][i][3];
										brtype[j + 1][i] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i - 1] != -1 && j >= 0 && j < rows && (i - 1) < 18 && (i - 1) >= 0) {
										tempx1 = brcoord[j][i - 1][0];
										tempy1 = brcoord[j][i - 1][1];
										tempx2 = brcoord[j][i - 1][2];
										tempy2 = brcoord[j][i - 1][3];
										brtype[j][i - 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
									if (brtype[j][i + 1] != -1 && j >= 0 && j < rows && (i + 1) < 18 && (i + 1) >= 0) {
										tempx1 = brcoord[j][i + 1][0];
										tempy1 = brcoord[j][i + 1][1];
										tempx2 = brcoord[j][i + 1][2];
										tempy2 = brcoord[j][i + 1][3];
										brtype[j][i + 1] = -1;
										type = -1;
										deletebrick(tempx1, tempy1, tempx2, tempy2, type, life, score, lifeflag, rows, l);
										brickcounter = brickcounter - 1;
									}
								}
								if ((type == 3) && (rows + 1 <= 7)) {
									for (int j = rows; j < (rows + 1) && (rows + 1) <= 7; j++)
									{
										x1 = 60;
										x2 = 110;

										tx1 = x1 + 25;
										size = 8;

										cx1 = x1 + 20;
										cx2 = x1 + 30;

										px1 = x1 + 17;
										px2 = x1 + 20;

										rx1 = x1 + 10;
										rx2 = x1 + 40;

										for (int i = 0; i < 18; i++)
										{
											n = rand() % 11;
											if (n == 0)
											{
												tb(x1, y1, x2, y2, tx1, ty1);
												//triangle brick is type 0
												brtype[j][i] = 0;
											}
											else if (n == 1)
											{
												cb(x1, y1, x2, y2, cx1, cy1, cx2, cy2);
												//circle brick is type 1
												brtype[j][i] = 1;
											}
											else if (n == 2)
											{
												pb(x1, y1, x2, y2, px1, py1, px2, py2);
												//parallelogram brick is type 2
												brtype[j][i] = 2;
											}
											else if (n == 3)
											{
												rb(x1, y1, x2, y2, rx1, ry1, rx2, ry2);
												//rectangle brick is type 3
												brtype[j][i] = 3;
											}
											else
											{
												bb(x1, y1, x2, y2);
												//basic brick is type 4
												brtype[j][i] = 4;
											}

											//storing coordinates of each brick
											brcoord[j][i][0] = x1;
											brcoord[j][i][1] = y1;
											brcoord[j][i][2] = x2;
											brcoord[j][i][3] = y2;

											//incrementing brick counter
											brickcounter++;

											//setting x coordinates for next brick
											x1 = x1 + 60;
											x2 = x2 + 60;
											tx1 = tx1 + 60;
											cx1 = cx1 + 60;
											cx2 = cx2 + 60;
											px1 = px1 + 60;
											px2 = px2 + 60;
											rx1 = rx1 + 60;
											rx2 = rx2 + 60;
										}

										//setting y coordinates for next brick
										y1 = y1 + 25;
										y2 = y2 + 25;
										ty1 = ty1 + 25;
										cy1 = cy1 + 25;
										cy2 = cy2 + 25;
										py1 = py1 + 25;
										py2 = py2 + 25;
										ry1 = ry1 + 25;
										ry2 = ry2 + 25;
									}
									rows = rows + 1;
								}
								//
								brtype[j][i] = -1;
								deleteball(bx1, by1, bx2, by2);
								//reprinting bricks this time with black bricks replacing those ball has bounce on and to prevent black ball from covering edges of bricks
								reprintingbricks(brtype, brcoord, rows);
							}
						}

					}
				}
			}

			//bat movement based on character input from keyboard
			if (_kbhit() == true) {
				m = _getch();
				if (m == 's' || m == 'S') {
					savegame(brtype, brickcounter, rows, life, score);
					m = '\0';
					life = 0;
					brickcounter = 0;
					lifeflag = true;
					saveflag = true;
				}
				if (m == ' ') {
					COLORREF silver = RGB(210, 210, 210);
					COLORREF black = RGB(12, 12, 12);
					char str[] = "PAUSED";
					myDrawTextWithFont(550, 300, 30, str, silver, black);
					bool pauseflag = true;
					char p = _getch();
					while (pauseflag == true)
					{
						if (p == ' ') {
							myDrawTextWithFont(550, 300, 30, str, black, black);
							pauseflag = false;
						}
						else
						{
							p = _getch();
						}
					}
					pauseflag = true;
				}
				if ((batx1 > 60) && (batx2 + 120 < 1129))
				{
					if (m == 'a')
					{
						deletebat(batx1, batx2);
						batx1 = batx1 - 10;
						batx2 = batx2 - 10;
						bat(batx1, batx2);
					}
					if (m == 'd')
					{
						deletebat(batx1, batx2);
						batx1 = batx1 + 10;
						batx2 = batx2 + 10;
						bat(batx1, batx2);
					}
				}
				if (batx1 == 60)
				{
					if (m == 'd')
					{
						deletebat(batx1, batx2);
						batx1 = batx1 + 10;
						batx2 = batx2 + 10;
						bat(batx1, batx2);
					}
				}
				if (batx2 + 120 == 1129)
				{
					if (m == 'a')
					{
						deletebat(batx1, batx2);
						batx1 = batx1 - 10;
						batx2 = batx2 - 10;
						bat(batx1, batx2);
					}
				}
			}
			//life gets decremented if ball touches bottom of game
			if (by2 >= 443) {
				lifeflag = true;
				deletelife(life);
				deleteball(bx1, by1, bx2, by2);
				deletebat(batx1, batx2);
				m = '\0';
			}
			//displaying new lives text and overwriting previous one
			if (lifeflag == true)
			{
				BlackOriginalLifeText(l);

				if (life == 5.0)
				{
					char l2[] = "5.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 4.5)
				{
					char l2[] = "4.5";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 4.0)
				{
					char l2[] = "4.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 3.5)
				{
					char l2[] = "3.5";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 3.0)
				{
					char l2[] = "3.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 2.5)
				{
					char l2[] = "2.5";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 2.0)
				{
					char l2[] = "2.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 1.5)
				{
					char l2[] = "1.5";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 1.0)
				{
					char l2[] = "1.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 0.5)
				{
					char l2[] = "0.5";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
				}
				else if (life == 0.0) {
					char l2[] = "0.0";
					strcpy_s(l, l2);
					BlackOriginalLifeText(l);
					m = '\0';
				}
				DisplayLife(l);
			}
		}
	}

	SetCursorPosition(0, 0);

	if (saveflag == true) {
		save();
		Sleep(1000);
		ClearScreen();
	}
	else if (life <= 0)
	{
		lost();
		Sleep(1000);
		ClearScreen();
		savescore(score);
	}
	else if (brickcounter == 0)
	{
		win();
		Sleep(1000);
		ClearScreen();
		savescore(score);
	}
	ClearScreen();
}

void menu() {
	COLORREF silver = RGB(210, 210, 210);
	COLORREF lightblue = RGB(0, 205, 255);

	char b1[] = "BRICK  BREAKER";

	myDrawTextWithFont(350, 300, 150, b1, silver, lightblue);

	int x = 0;
	for (int i = 0; i <= 35; i++)
	{
		COLORREF silver = RGB(210 - x/2, 210 - x/2, 210 - x/2);
		COLORREF lightblue = RGB(0, 205 - x, 255 - x);
		myDrawTextWithFont(350, 300, 150, b1, silver, lightblue);
		x = x + 5;
		Sleep(50);
	}
	ClearScreen();

	COLORREF black = RGB(0, 0, 0);
	COLORREF darkpink = RGB(255, 0, 128);

	char m[] = "MENU";
	char o1[] = "PRESS N FOR NEW GAME";
	char o2[] = "PRESS L TO LOAD GAME ";
	char o3[] = "PRESS S TO VIEW SCORES";
	char o4[] = "PRESS X TO EXIT";


	char option;
	bool flag = false;

	while (flag == false)
	{
		SetCursorPosition(0,0);
		ClearScreen();

		myDrawTextWithFont(550, 150, 100, m, black, darkpink);
		myDrawTextWithFont(300, 350, 40, o1, black, darkpink);
		myDrawTextWithFont(650, 350, 40, o2, black, darkpink);
		myDrawTextWithFont(300, 450, 40, o3, black, darkpink);
		myDrawTextWithFont(650, 450, 40, o4, black, darkpink);

		option = _getch();
		if ((option == 'n') || (option == 'N'))
		{
			game(option);
		}
		else if ((option == 'l') || (option == 'L'))
		{
			string t = "";

			ifstream file("save.txt");
			getline(file, t);

			file.close();
			if (t == "")
			{
				ClearScreen();
				cout << "THERE IS NO LOAD FILE CURRENTLY";
				Sleep(2000);
				ClearScreen();
			}
			else
			{
				game(option);
			}
		}
		else if ((option == 'x') || (option == 'X'))
		{
			ClearScreen();
			cout << "Good Bye" << endl;
			flag = true;
		}
		else if ((option == 's') || (option == 'S'))
		{
			ClearScreen();
			displayhighscores();
			Sleep(200);
			cout << "PRESS ANY KEY TO GO BACK TO MENU" << endl;
			_getch();
		}
		else
		{
			ClearScreen();
			cout << "EITHER YOU SELECTED WRONG OPTION OR THIS SECTION IS STILL UNDER DEVELOPMENT" << endl;
			Sleep(2000);
		}
	}
}

int main() {
	menu();
	system("pause");
	return 0;
}