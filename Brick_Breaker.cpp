#include<iostream>
#include<conio.h>
#include"yourgraphics.h"     //Graphics Library 
#include<fstream>
using namespace std;
int main() {
restart:
	int R = 0, G = 0, B = 0, FR = 255, FG = 255, FB = 255, x1 = 0, y1 = 0, x2 = 0, y2 = 0, life = 3;
	char gameOver, gameSave;
	int height = 0; int width = 0;
	int cl1[3] = { 72,78,72 };
	int cl2[3] = { 72,78,72 };
	getWindowDimensions(height, width);
	showConsoleCursor(false);
	cout << "\n\n\n";
	cout << "\t\t\t\t\t              ----------------------";
	cout << "\n\n\t\t\t\t\t\t           BRICK BREAKER\n\n";
	cout << "\t\t\t\t\t              ----------------------\n\n\n";
	cout << "READ THE GAME INSTRUCTIONS CAREFULLY, TO PLAY GAME:::\n";
	cout << "Press ' N ' for New GAME\n";
	cout << "Press ' A ' for MOVE LEFT\n";
	cout << "Press ' D ' for MOVE RIGHT\n";
	cout << "Press ' P ' for PAUSE GAME\n";
	cout << "Press ' U ' for UNPAUSE GAME\n";
	cout << "Press ' S ' for SAVE GAME\n";
	cout << "Press ' L ' for LOAD GAME\n";
	cout << "Press ' Q ' for QUIT GAME\n";
	cout << "Press ' R ' for RESTRAT GAME\n";
	cout << "\n\n";
	cout << "CREATED BY :UZAIR AHMAD 23L-0594 && HASSAN ALI 23L-0859\n\n\n";
	cout << "\t\t\t\t\t           \tPRESS ENTER TO CONTINUE";
	cin.get();
	cls();
	//Menu Page
	gotoxy(0, 0);
	char choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t\t   ----------------------";
	cout << "\n\n\t\t\t\t\t\tNEW GAME\n\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n";
	cout << "\t\t\t\t\t   ----------------------";
	cout << "\n\n\t\t\t\t\t\tLOAD GAME\n\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	cout << "\n";
	cout << "\t\t\t\t\t   ----------------------";
	cout << "\n\n\t\t\t\t\t\tQUIT GAME\n\n";
	cout << "\t\t\t\t\t   ----------------------\n\n";
	// Array for GAME Saving  and Printing Black Bricks 
	bool save[6][13];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++)
		{
			save[i][j] = false;
		}
	}
	cout << ":::::::Enter Your Choice According to Instructions :::::: ";
	cin >> choice;
	while (1) {
		int e_size[4] = { 625,650,525,550 }, t[4] = { 0,0,5,5 }; bool flag = false; int time = 0; int score = 0;
		int count[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int limit[13] = { 370, 370,370,370,370,370,370,370,370,370,370,370,370 };
		int k = 0;
		if (choice == 'n' || choice == 'N' || choice == 'l' || choice == 'L') {
			cls();
			drawRectangle(x1 + 0, y1 + 0, x1 + 1500, y1 + 1000, 0, 0, 0, 0, 0, 0); // Printing Background 
			showConsoleCursor(false);
			gotoxy(0, 1);
			for (int i = 0; i < 6; i++) {
				x1 = 0;
				for (int j = 0; j < 13; j++) {
					if (j % 2 == 0) {
						if (i % 2 == 0) {
							FR = 219, FG = 48, FB = 39;
						}
						else {
							FR = 143, FG = 56, FB = 242;
						}
					}
					else {
						if (i % 2 == 0) {
							FR = 15, FG = 198, FB = 214;
						}
						else {
							FR = 10, FG = 143, FB = 48;
						}
					}
					if (i == 0) {
						drawRectangle(x1 + 10, y1 + 10, x1 + 100, y1 + 50, 0, 0, 0, 0, 0, 0);
					}
					drawRectangle(x1 + 10, y1 + 40, x1 + 100, y1 + 90, R, G, B, FR, FG, FB);     // Printing Coloured Bricks 
					x1 = x1 + 100;
				}
				y1 = y1 + 55;
			}
			x1 = 100, y1 = 100;
			int bar1 = 475, bar2 = 800, bar3 = 800, bar4 = 1500, bar5 = 0, bar6 = 475;
			drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
			drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
			drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
			drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], cl2[0], cl2[1], cl2[2], 72, 78, 72);
			if (choice == 'l' || choice == 'L') {     // Load GAME 
				drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], 0, 0, 0, 0, 0, 0);
				drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
				drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
				drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
				ifstream read;
				read.open("SavedGame.txt");
				read >> life;
				read >> score;
				read >> e_size[0] >> e_size[2] >> e_size[1] >> e_size[3];
				read >> bar1;
				read >> bar2;
				read >> bar3;
				read >> bar4;
				read >> bar5;
				read >> bar6;
				read >> t[0] >> t[2] >> t[1] >> t[3];
				for (int i = 0; i < 13; i++) {
					read >> limit[i];
				}
				for (int i = 0; i < 13; i++) {
					read >> count[i];
				}
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 13; j++) {
						read >> save[i][j];
					}
				}
			}
		jump:
			y1 = 0;
			for (int i = 0; i < 6; i++) {
				x1 = 0;
				for (int j = 0; j < 13; j++)
				{
					if (save[i][j]) {
						drawRectangle(x1 + 10, y1 + 40, x1 + 100, y1 + 90, 0, 0, 0, 0, 0, 0);
					}
					x1 = x1 + 100;
				}
				y1 = y1 + 55;
			}
			x1 = 100, y1 = 100;
			while (1) {
				gotoxy(0, 0);
				cout << "  LIFE : " << life;
				gotoxy(52, 0.5);
				cout << "BRICK BREAKER";
				gotoxy(105, 0);
				cout << "SCORE : " << score;
				char input = getKey();
				delay(10);
				drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], 0, 0, 0, 0, 0, 0);
				for (int i = 0; i < 4; i++) {
					e_size[i] += t[i];
				}
				drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], cl2[0], cl2[1], cl2[2], 72, 78, 72);
				if (e_size[0] <= 0) {
					t[0] *= -1, t[1] *= -1; // Left Boundary 
				}
				if (e_size[1] >= 1320) {
					t[0] *= -1; t[1] *= -1; // Right Boundary 
				}
				if (e_size[2] < 40) {
					t[0] *= -1;  t[1] *= -1; // Upper Boundary
				}
				if (e_size[3] >= 598) {
					if (e_size[0] <= bar2 && e_size[1] >= bar1) {
						t[2] *= -1; t[3] *= -1;
						if (e_size[0] > (bar1 + 110) && e_size[1] < (bar2 - 110)) {
							t[0] = 0; t[1] = 0; // If Center Move straight 
						}
						else if (e_size[1] > (bar2 - 110)) {
							if (t[0] == 0) {
								t[0] = 2; t[1] = 2;
							}
							else if (t[0] < 0) {
								t[0] *= -1; t[1] *= -1;
							}
						}
						else if (e_size[0] < (bar1 + 110)) {
							if (t[0] == 0) {
								t[0] = 2; t[1] = 2;
							}
							else if (t[0] > 0) {
								t[0] *= -1; t[1] *= -1;
							}
						}
					}
					else {
						life--;
						if (life > 0) {
							drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], 0, 0, 0, 0, 0, 0);
							bar1 = 475, bar2 = 800, bar3 = 800, bar4 = 1500, bar5 = 0, bar6 = 475;
							drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
							drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
							drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
							delay(1000);
							t[0] = 0; t[1] = 0; t[2] = 5; t[3] = 5;
							e_size[0] = 625, e_size[1] = 650, e_size[2] = 525, e_size[3] = 550;
						}
						else {   // When Balls Falls from the Bar
							cls();
							gotoxy(0, 7);
							cout << "::::::::SCORE IS:::::::" << score;
							gotoxy(0, 10);
							cout << "\n\n\n\t\t\t\t---------------------------";
							cout << "\n\n\t\t\t\t\t GAME OVER\n\n";
							cout << "\n\n\t\t\t\t    THANKS FOR PLAYING\n\n";
							cout << "\t\t\t\t--------------------------\n\n";
							cout << "\n";
							cout << "Press 'R' to restart or 'Q' to Quit : ";
							cin >> gameOver;
							if (gameOver == 'R' || gameOver == 'r') {
								goto restart;
							}
							else if (gameOver == 'Q' || gameOver == 'q') {
								cls();
								gotoxy(0, 10);
								cout << "\n\n\n\n\n\t\t\t\t\t--------------------------";
								cout << "\n\n\t\t\t\t\t\tGAME OVER\n\n";
								cout << "\n\n\t\t\tTHANKS FOR PLAYING\n\n";
								cout << "\t\t\t\t\t--------------------------\n\n";
								cout << "\n";
								return 0;
							}
						}
					}
				}
				if (e_size[3] > 750) {
					drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], 0, 0, 0, 0, 0, 0);
				}
				if (e_size[2] <= limit[0] && e_size[0] < 100)                   //Next 13 Conditions for Brick Breaking 
				{
					count[0]++;
					if (e_size[1] == 99)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						save[k][1] = true;
						drawRectangle(100, (k * 55) + 25, 200, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[0] >= 1 && count[0] <= 6)
					{
						save[(limit[0] / 50) - 1][k] = true;
						drawRectangle(k * 100, limit[0] - 55, ((k * 100) + 100), limit[0], 0, 0, 0, 0, 0, 0);
						if (limit[0] > 25)
						{
							limit[0] = limit[0] - 55;
							score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[1] && e_size[0] >= 100 && e_size[0] < 200)
				{
					count[1]++;
					if (e_size[0] == 100)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						save[k][0] = true;
						drawRectangle(0, (k * 55) + 25, 100, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
					if (e_size[1] == 199)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						save[k][2] = true;
						drawRectangle(200, (k * 55) + 25, 300, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[1] >= 1 && count[1] <= 6)
					{
						save[(limit[1] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[1] - 55, ((k * 100) + 100), limit[1], 0, 0, 0, 0, 0, 0);
						if (limit[1] > 25)
						{
							limit[1] = limit[1] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[2] && e_size[0] >= 200 && e_size[0] < 300)
				{
					count[2]++;
					if (e_size[0] == 200)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][1] = true;
							drawRectangle(100, (k * 55) + 25, 200, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 299)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][3] = true;
							drawRectangle(300, (k * 55) + 25, 400, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[2] >= 1 && count[2] <= 6)
					{
						save[(limit[2] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[2] - 55, ((k * 100) + 100), limit[2], 0, 0, 0, 0, 0, 0);
						if (limit[2] > 25)
						{
							limit[2] = limit[2] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[3] && e_size[0] >= 300 && e_size[0] < 400)
				{
					count[3]++;
					if (e_size[0] == 300)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						save[k][2] = true;
						drawRectangle(200, (k * 55) + 25, 300, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
						score = score + 50;
					}
					if (e_size[1] == 399)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][4] = true;
							drawRectangle(400, (k * 55) + 25, 500, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[3] >= 1 && count[3] <= 6)
					{
						save[(limit[3] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[3] - 55, ((k * 100) + 100), limit[3], 0, 0, 0, 0, 0, 0);
						if (limit[3] > 25)
						{
							limit[3] = limit[3] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[4] && e_size[0] >= 400 && e_size[0] < 500)
				{
					count[4]++;
					if (e_size[0] == 400)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][3] = true;
							drawRectangle(300, (k * 55) + 25, 400, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 499)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][5] = true;
							drawRectangle(500, (k * 55) + 25, 600, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[4] >= 1 && count[4] <= 6)
					{
						save[(limit[4] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[4] - 55, ((k * 100) + 100), limit[4], 0, 0, 0, 0, 0, 0);

						if (limit[4] > 25)
						{
							limit[4] = limit[4] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[5] && e_size[0] >= 500 && e_size[0] < 600)
				{
					count[5]++;
					if (e_size[0] == 500)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][4] = true;
							drawRectangle(400, (k * 55) + 25, 500, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 599)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][6] = true;
							drawRectangle(600, (k * 55) + 25, 700, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[5] >= 1 && count[5] <= 6)
					{
						save[(limit[5] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[5] - 55, ((k * 100) + 100), limit[5], 0, 0, 0, 0, 0, 0);

						if (limit[5] > 25)
						{
							limit[5] = limit[5] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[6] && e_size[0] >= 600 && e_size[0] < 700)
				{
					count[6]++;
					if (e_size[0] == 600)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][5] = true;
							drawRectangle(500, (k * 55) + 25, 600, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 699)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][7] = true;
							drawRectangle(700, (k * 55) + 25, 800, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[6] >= 1 && count[6] <= 6)
					{
						save[(limit[6] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[6] - 55, ((k * 100) + 100), limit[6], 0, 0, 0, 0, 0, 0);

						if (limit[6] > 25)
						{
							limit[6] = limit[6] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[7] && e_size[0] >= 700 && e_size[0] < 800)
				{
					count[7]++;
					if (e_size[0] == 700)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][6] = true;
							drawRectangle(600, (k * 55) + 25, 700, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 799)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][8] = true;
							drawRectangle(800, (k * 55) + 25, 900, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[7] >= 1 && count[7] <= 6)
					{
						save[(limit[7] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[7] - 55, ((k * 100) + 100), limit[7], 0, 0, 0, 0, 0, 0);
						if (limit[7] > 25)
						{
							limit[7] = limit[7] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[8] && e_size[0] >= 800 && e_size[0] < 900)
				{
					count[8]++;
					if (e_size[0] == 800)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][7] = true;
							drawRectangle(700, (k * 55) + 25, 800, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 899)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][9] = true;
							drawRectangle(900, (k * 55) + 25, 1000, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[8] >= 1 && count[8] <= 6)
					{
						save[(limit[8] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[8] - 55, ((k * 100) + 100), limit[8], 0, 0, 0, 0, 0, 0);

						if (limit[8] > 25)
						{
							limit[8] = limit[8] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[9] && e_size[0] >= 900 && e_size[0] < 1000)
				{
					count[9]++;
					if (e_size[0] == 900)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][8] = true;
							drawRectangle(800, (k * 55) + 25, 900, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 999)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][10] = true;
							drawRectangle(1000, (k * 55) + 25, 1100, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[9] >= 1 && count[9] <= 6)
					{
						save[(limit[9] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[9] - 55, ((k * 100) + 100), limit[9], 0, 0, 0, 0, 0, 0);

						if (limit[9] > 25)
						{
							limit[9] = limit[9] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[10] && e_size[0] >= 1000 && e_size[0] < 1100)
				{
					count[10]++;
					if (e_size[0] == 1000)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][9] = true;
							drawRectangle(900, (k * 55) + 25, 1000, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 1099)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][11] = true;
							drawRectangle(1100, (k * 55) + 25, 1200, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[10] >= 1 && count[10] <= 6)
					{
						save[(limit[10] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[10] - 55, ((k * 100) + 100), limit[10], 0, 0, 0, 0, 0, 0);
						if (limit[10] > 25)
						{
							limit[10] = limit[10] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[11] && e_size[0] >= 1100 && e_size[0] < 1200)
				{
					count[11]++;
					if (e_size[0] == 1100)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][10] = true;
							drawRectangle(1000, (k * 55) + 25, 1100, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 1199)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][12] = true;
							drawRectangle(1200, (k * 55) + 25, 1300, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[11] >= 1 && count[11] <= 6)
					{
						save[(limit[11] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[11] - 55, ((k * 100) + 100), limit[11], 0, 0, 0, 0, 0, 0);

						if (limit[11] > 25)
						{
							limit[11] = limit[11] - 55; score = score + 100;
						}
					}
				}
				if (e_size[2] <= limit[12] && e_size[0] >= 1200 && e_size[0] < 1300)
				{
					count[12]++;
					if (e_size[0] == 1200)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][11] = true;
							drawRectangle(1100, (k * 55) + 25, 1200, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					if (e_size[1] == 1299)
					{
						t[0] = t[0] * -1; t[1] = t[1] * -1;
						k = ((e_size[2] + 10) / 55) - 1;
						if (k < 0)
						{
							k = k + 1;
						}
						{
							save[k][13] = true;
							drawRectangle(1300, (k * 55) + 25, 1400, (k * 55) + 65, 0, 0, 0, 0, 0, 0);
							score = score + 50;
						}
					}
					t[2] = t[2] * -1;
					t[3] = t[3] * -1;
					k = e_size[0] / 100;
					if (count[12] >= 1 && count[12] <= 6)
					{
						save[(limit[12] / 55) - 1][k] = true;
						drawRectangle(k * 100, limit[12] - 55, ((k * 100) + 100), limit[12], 0, 0, 0, 0, 0, 0);

						if (limit[12] > 25)
						{
							limit[12] = limit[12] - 55; score = score + 100;
						}
					}
				}
				if (input == 'p' || input == 'P') {
					gotoxy(50, 0);
					cout << "Game Paused!! Press 'U' to UnPause";
					while (1) {
						int p = _getch();
						if (p == 'u' || p == 'U') {
							gotoxy(50, 0);
							cout << "                                           ";
							break;
						}
					}
				}
				// Condition For Game Saving 
				if (input == 's' || input == 'S') {
					gotoxy(52, 0.5);
					cout << "GAME SAVED";
					cout << "           ";
					delay(1000);
					gotoxy(50, 0);
					cout << "                                           ";
					ofstream write;
					write.open("SavedGame.txt");
					write << life << endl;
					write << score << endl;
					write << e_size[0] << endl;
					write << e_size[2] << endl;
					write << e_size[1] << endl;
					write << e_size[3] << endl;
					write << bar1 << endl;
					write << bar2 << endl;
					write << bar3 << endl;
					write << bar4 << endl;
					write << bar5 << endl;
					write << bar6 << endl;
					write << t[0] << endl;
					write << t[2] << endl;
					write << t[1] << endl;
					write << t[3] << endl;
					for (int i = 0; i < 13; i++) {
						write << limit[i] << endl;
					}
					for (int i = 0; i < 13; i++) {
						write << count[i] << endl;
					}
					for (int i = 0; i < 6; i++) {
						for (int j = 0; j < 13; j++) {
							write << save[i][j] << endl;
						}
					}
					cls();
					gotoxy(0, 10);
					cout << "\n\n\n\t\t\t\t\t   ----------------------";
					cout << "\n\n\t\t\t\t\t\t GAME SAVED\n\n";
					cout << "\t\t\t\t\t   ----------------------\n\n";
					cout << "\n";
					cout << "Press 'Q' to Quit : ";
					cin >> gameSave;
					if (gameSave == 'q' || gameSave == 'Q') {
						cls();
						gotoxy(0, 0);
						cout << "\n\n\n\n\n\t\t\t\t\t   ----------------------";
						cout << "\n\n\t\t\t\t\t\t\GAME OVER\n\n";
						cout << "\n\n\t\t\t\t\t\tTHANKS FOR PLAYNG\n\n";
						cout << "\t\t\t\t\t   ----------------------\n\n";
						cout << "\n";
						return 0;
					}
					break;
				}
				// Condition For Game Load During the New Game 
				if (input == 'l' || input == 'L') {
					gotoxy(52, 0.5);
					cout << "GAME LOADED";
					delay(1000);
					gotoxy(50, 0);
					cout << "                                           ";
					drawEllipse(e_size[0], e_size[2], e_size[1], e_size[3], 0, 0, 0, 0, 0, 0);
					drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
					drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
					drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
					ifstream read;
					read.open("SavedGame.txt");
					read >> life;
					read >> score;
					read >> e_size[0] >> e_size[2] >> e_size[1] >> e_size[3];
					read >> bar1;
					read >> bar2;
					read >> bar3;
					read >> bar4;
					read >> bar5;
					read >> bar6;
					read >> t[0] >> t[2] >> t[1] >> t[3];
					for (int i = 0; i < 13; i++) {
						read >> limit[i];
					}
					for (int i = 0; i < 13; i++) {
						read >> count[i];
					}
					for (int i = 0; i < 6; i++) {
						for (int j = 0; j < 13; j++) {
							read >> save[i][j];
						}
					}
					goto jump;
				}
				if (input == 'R' || input == 'r') {
					goto restart;
				}
				if (input == 'Q' || input == 'q') {
					cls();
					gotoxy(0, 7);
					cout << ":::::SCORE IS" << " :::" << score;
					gotoxy(0, 10);
					cout << "\n\n\n\n\n\t\t\t\t\t-------------------------";
					cout << "\n\n\t\t\t\t\tTHANKS FOR PLAYING\n\n";
					cout << "\t\t\t\t\t-------------------------\n\n";
					cout << "\n";
					return 0;
				}
				// Bar Movement (Left && Right)
				if (input == 'a' || input == 'A') {
					if (bar1 > 0) {
						bar1 = bar1 - 25, bar2 = bar2 - 25;
						drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
						bar3 = bar3 - 25;
						drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
						bar6 = bar6 - 25;
						drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
					}
				}
				if (input == 'd' || input == 'D') {
					if (bar2 < 1325) {
						bar1 = bar1 + 25, bar2 = bar2 + 25;
						drawRectangle(bar1, y1 + 500, bar2, y1 + 510, cl1[0], cl1[1], cl1[2], 72, 78, 72);
						bar3 = bar3 + 25;
						drawRectangle(bar3, y1 + 500, bar4, y1 + 510, 0, 0, 0, 0, 0, 0);
						bar6 = bar6 + 25;
						drawRectangle(bar5, y1 + 500, bar6, y1 + 510, 0, 0, 0, 0, 0, 0);
					}
				}
			}

		}
		if (score == 7150) {
			cls();
			gotoxy(0, 10);
			cout << "\n\n\n\n\n\t\t\t\t\t----------------------------";
			cout << "\n\n\t\t\t\t\tCongratulations You Have Won\n\n";
			cout << "\n\n\t\t\t\t\t\tTHANKS FOR PLAYING\n\n";
			cout << "\t\t\t\t\t----------------------------\n\n";
			cout << "\n";
			cout << "Press 'R' to restart or 'Q' to Quit : ";
			cin >> gameOver;
			if (gameOver == 'R' || gameOver == 'r') {
				goto restart;
			}
			else if (gameOver == 'Q' || gameOver == 'q') {
				cls();
				gotoxy(0, 0);
				cout << "\n\n\n\n\n\t\t\t\t\t   ----------------------";
				cout << "\n\n\t\t\t\t\t\t THANK YOU\n\n";
				cout << "\t\t\t\t\t   ----------------------\n\n";
				cout << "\n";
				return 0;
			}
			break;
		}
		delay(1000000000000000);
		break;
	}
	if (choice == 'q' || choice == 'Q') {
		cls();
		gotoxy(0, 0);
		cout << "\n\n\n\n\n\t\t\t\t\t   ----------------------";
		cout << "\n\n\t\t\t\t\t\t THANK YOU\n\n";
		cout << "\t\t\t\t\t   ----------------------\n\n";
		cout << "\n";
		return 0;
	}
	else {
		cout << "Invalid Input!!! Enter Again";
		cin >> choice;
	}
	return 0;
}
// Game End 
// Thank You