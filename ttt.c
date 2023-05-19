//Josh Gardner
//CPSC1070 Assignment 3
//9 March 2021
//

#include <stdio.h>
#include "ezdraw.h"
#include <stdbool.h>

//defining window length
#define WINDOWWIDTH	600
#define WINDOWHEIGHT	600

#define BACK	250, 250, 250

enum boolean {FALSE, TRUE};
int stop = 0;

//initializing variables
//which piece user chooses
char playerPiece;
//grid user picks
int grid = 0;
//if user is clicking
int click = 0;
//number of times update display has been run
int numOfRuns = 0;
//which turn it is
int turn = 2;
//if user picks first or second
int pick;
//tracker for reseting values
int tracker;
//keeps track of number of times the computer has gone
int cTurn = 1;
//if the user wants to play again
int playAgain = 1;
//if there is a winner
//ends program when equal to one
int winner = 0;
int clear = 0;
//score tracking variables
int cScore = 0;
int uScore = 0;
int dScore = 0;
//variables that keep track of if each box is taken
int t1 = 0;
int t2 = 0; 
int t3 = 0;
int t4 = 0;
int t5 = 0;
int t6 = 0;
int t7 = 0;
int t8 = 0;
int t9 = 0;

//variables that keep track of char value of each grid
char c1;
char c2;
char c3;
char c4;
char c5;
char c6;
char c7;
char c8;
char c9;

void updateDisplay() {

	//clearing drawing on first run
	if(numOfRuns == 0) {
		EZ_ClearDrawing();
		numOfRuns++;
	}

	EZ_SetBackColor(BACK);

	//drawing box dividers
	EZ_DrawLine(200, 0, 200, 600);
	EZ_DrawLine(400, 0, 400, 600);
	EZ_DrawLine(0, 200, 600, 200);
	EZ_DrawLine(0, 400, 600, 400);

	
	//drawing first piece for computer
	if(pick == 2) {
		if(playerPiece == 'O') {
			EZ_DrawLine(200, 0, 0, 200);
			EZ_DrawLine(0, 0, 200, 200);
			EZ_DisplayDrawing();
			t1++;
			c1 = 'X';
		}
		if(playerPiece == 'X') {
			EZ_OutlineCircle(100, 100, 60);
			EZ_DisplayDrawing();
			t1++;
			c1 = 'O';
		}
	}
	//if user is clicking
	if(click == 1) {
	//if turn is even, it is users turn
	if(turn % 2 == 0) {
		//if player is x
		if(playerPiece == 'X') {
			//switch for which grid the user clicks on
			switch(grid) {
				case 1:
					if(t1 == 0) {
						EZ_DrawLine(200, 0, 0, 200);
						EZ_DrawLine(0, 0, 200, 200);
						EZ_DisplayDrawing();
						t1++;
						c1 = 'X';
						turn++;
					}
				break;
				case 2:
					if(t2 == 0) {
						EZ_DrawLine(200, 200, 0, 400);
						EZ_DrawLine(0, 200, 200, 400);
						EZ_DisplayDrawing();
						t2++;
						c2 = 'X';
						turn++;
					}
				break;
				case 3:
					if(t3 == 0) {
						EZ_DrawLine(200, 400, 0, 600);
						EZ_DrawLine(0, 400, 200, 600);
						EZ_DisplayDrawing();
						t3++;
						c3 = 'X';
						turn++;
					}
				break;
				case 4:
					if(t4 == 0) {
						EZ_DrawLine(400, 0, 200, 200);
						EZ_DrawLine(200, 0, 400, 200);
						EZ_DisplayDrawing();
						t4++;
						c4 = 'X';
						turn++;
					}
				break;
				case 5:
					if(t5 == 0) {
						EZ_DrawLine(400, 200, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'X';
						turn++;
					}
				break;
				case 6:
					if(t6 == 0) {
						EZ_DrawLine(400, 400, 200, 600);
						EZ_DrawLine(200, 400, 400, 600);
						EZ_DisplayDrawing();
						t6++;
						c6 = 'X';
						turn++;
					}
				break;
				case 7:
					if(t7 == 0) {
						EZ_DrawLine(600, 0, 400, 200);
						EZ_DrawLine(400, 0, 600, 200);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'X';
						turn++;
					}
				break;
				case 8:
					if(t8 == 0) {
						EZ_DrawLine(600, 200, 400, 400);
						EZ_DrawLine(400, 200, 600, 400);
						EZ_DisplayDrawing();
						t8++;
						c8 = 'X';
						turn++;
					}
				break;
				case 9:
					if(t9 == 0) {
						EZ_DrawLine(600, 400, 400, 600);
						EZ_DrawLine(400, 400, 600, 600);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'X';
						turn++;
					}
				break;
			}
		//user selects O
		} else if(playerPiece == 'O') {
			switch(grid) {
				case 1:
					if(t1 == 0) {
						EZ_OutlineCircle(100, 100, 60);
						EZ_DisplayDrawing();
						t1++;
						c1 = 'O';
						turn++;
					}
				break;
				case 2:
					if(t2 == 0) {
						EZ_OutlineCircle(100, 300, 60);
						EZ_DisplayDrawing();
						t2++;
						c2 = 'O';
						turn++;
					}
				break;
				case 3:
					if(t3 == 0) {
						EZ_OutlineCircle(100, 500, 60);
						EZ_DisplayDrawing();
						t3++;
						c3 = 'O';
						turn++;
					}
				break;
				case 4:
					if(t4 == 0) {
						EZ_OutlineCircle(300, 100, 60);
						EZ_DisplayDrawing();
						t4++;
						c4 = 'O';
						turn++;
					}
				break;
				case 5:
					if(t5 == 0) {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						turn++;
					}
				break;
				case 6:
					if(t6 == 0) {
						EZ_OutlineCircle(3000, 500, 60);
						EZ_DisplayDrawing();
						t6++;
						c6 = 'O';
						turn++;
					}
				break;
				case 7:
					if(t7 == 0) {
						EZ_OutlineCircle(500, 100, 60);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'O';
						turn++;
					}
				break;
				case 8:
					if(t8 == 0) {
						EZ_OutlineCircle(500, 300, 60);
						EZ_DisplayDrawing();
						t8++;
						c8 = 'O';
						turn++;
					}
				break;
				case 9: 
					if(t9 == 0) {
						EZ_OutlineCircle(500, 500, 60);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'O';
						turn++;
					}
				break;
				EZ_DisplayDrawing();
			}
			EZ_DisplayDrawing();
		}
		EZ_DisplayDrawing();
	//computers turn
	}
	if(turn % 2 != 0) {
		if(playerPiece == 'O') {
			//if user is going first
			if(pick == 2) {
			switch(cTurn) {
				case 1:
					if(t3 == 0 && t2 == 0 && t6 == 0) {
						EZ_DrawLine(200, 400, 0, 600);
						EZ_DrawLine(0, 400, 200, 600);
						EZ_DisplayDrawing();
						t3++;
						c3 = 'X';
						break;
					}
					if(t7 == 0 && t4 == 0 && t8 == 0 && c3 != 'X') {
						EZ_DrawLine(600, 0, 400, 200);
						EZ_DrawLine(400, 0, 600, 200);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'X';
						break;
					}
				break;
				case 2:
					if(c2 == c8 && c2 == 'O') {
						EZ_DrawLine(400, 200, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DrawLine(400, 200, 200, 400);
					        EZ_DisplayDrawing();
						t5++;
						c5 = 'X';	
						break;
					}
					if(t2 == 0 && c3 == 'X') {
						EZ_DrawLine(200, 200, 0, 400);
						EZ_DrawLine(0, 200, 200, 400);
						EZ_DisplayDrawing();
						t2++;
						c2 = 'X';
						break;
					} 
					if(t4 == 0 && c7 == 'X') {
						EZ_DrawLine(400, 0, 200, 200);
						EZ_DrawLine(200, 0, 400, 200);
						EZ_DisplayDrawing();
						t4++;
						c4 = 'X';
						break;
					}
					if(c6 == 'O' && c4 == 'O') {
						EZ_DrawLine(400, 400, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'X';
						break;
					}
					if(t9 == 0) {
						EZ_DrawLine(600, 400, 400, 600);
						EZ_DrawLine(400, 400, 600, 600);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'X';
						break;
					} 
					if(t7 == 0) {
						EZ_DrawLine(400, 0, 600, 200);
						EZ_DrawLine(600, 0, 400, 200);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'X';
						break;
					}
				break;
				case 3:
					if(c9 == c7) {
						if(t6 == 0) {
						EZ_DrawLine(600, 200, 400, 400);
						EZ_DrawLine(400, 200, 600, 400);
						EZ_DisplayDrawing();
						t8++;
						c8 = 'X';
						break;
						}
					}
					if(c1 == 'X' && c9 == 'X' && t5 == 0) {
						EZ_DrawLine(400, 200, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'X';
						break;
					}
					if(c1 == 'X' && c7 == 'X' && t4 == 0) {
						 EZ_DrawLine(400, 0, 200, 200);
						 EZ_DrawLine(200, 0, 400, 200);
						 EZ_DisplayDrawing();
						 t4++;
						 c4 = 'X';
						 break;
					}
					if(c7 == 'X' && c3 == 'X' && t5 == 0) {
						EZ_DrawLine(400, 200, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'X';
						break;
					}
					if(c1 == 'X' && c7 == 'X' && c5 == 'X') {
						if(t9 == 0) {
							EZ_DrawLine(600, 400, 400, 600);
							EZ_DrawLine(400, 400, 600, 600);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'X';
							break;
						} else if(t3 == 0) {
							EZ_DrawLine(200, 400, 0, 600);
							EZ_DrawLine(0, 400, 200, 600);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'X';
							break;
						}
					}
					if(c5 == 'O') {
						if(c4 == 'O') {
							EZ_DrawLine(400, 400, 200, 600);
							EZ_DrawLine(200, 400, 400, 600);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'X';
							break;
						} 
						if(c6 == 'O') {
							EZ_DrawLine(400, 0, 200, 200);
							EZ_DrawLine(200, 0, 400, 200);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'X';
							break;
						}
					}
					if(c8 == 'O' && c2 == 'O') {
						EZ_DrawLine(400, 200, 200, 400);
						EZ_DrawLine(200, 200, 400, 400);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'X';
						break;
					}
					if(c3 == 'X' && c9 == 'X') {
						if(c5 == 'O') {
							EZ_DrawLine(400, 400, 200, 600);
							EZ_DrawLine(200, 400, 400, 600);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'X';
							break;
						}
						if(c6 == 'O') {
							EZ_DrawLine(400, 200, 200, 400);
							EZ_DrawLine(200, 200, 400, 400);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'X';
							break;
						}
					}
					if(c7 == 'X' && c9 == 'X') {
						if(c5 == 'O') {
							EZ_DrawLine(600, 200, 400, 400);
							EZ_DrawLine(400, 200, 600, 400);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'X';
							break;
						}
						if(c8 == 'O') {
							EZ_DrawLine(400, 200, 200, 400);
							EZ_DrawLine(200, 200, 400, 400);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'X';
							break;
						}
					}
				break;
				case 4: 
					if(c6 == 'X' && t9 == 0) {
						EZ_DrawLine(600, 400, 400, 600);
						EZ_DrawLine(400, 600, 600, 600);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'X';
						break;
					} 
					if(c4 == 'X' && t7 == 0) {
						EZ_DrawLine(600, 0, 400, 200);
						EZ_DrawLine(400, 0, 600, 200);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'X';
						break;
					}
					if(t9 == 0) {
						EZ_DrawLine(600, 400, 400, 600);
						EZ_DrawLine(400, 600, 600, 600);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'X';
						break;
					}
					if(t7 == 0) {
						EZ_DrawLine(600, 0, 400, 200);
						EZ_DrawLine(400, 0, 600, 200);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'X';
						break;
					}
				break;
			}//end switch
			turn++;
			cTurn++;
			//user going first
			} else if(pick == 1) {
				switch(cTurn) {
					case 1:
						if(t1 == 0) {
							EZ_DrawLine(200, 0, 0, 200);
							EZ_DrawLine(0, 0, 200, 200);
							EZ_DisplayDrawing();
							t1++;
							c1 = 'X';
							break;
						}
						if(t3 == 0) {
							EZ_DrawLine(200, 400, 0, 600);
							EZ_DrawLine(0, 400, 200, 600);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'X';
							break;
						}
					break;
					case 2:
						if(c1 == 'X') {
							if(t3 == 0) {
							EZ_DrawLine(200, 400, 0, 600);
							EZ_DrawLine(0, 400, 200, 600);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'X';
							break;
							}
							if(t7 == 0) {
							EZ_DrawLine(600, 0, 400, 200);
							EZ_DrawLine(400, 0, 600, 200);
							EZ_DisplayDrawing();
							t7++;
							c7 = 'X';
							break;
							}
						}
						if(c3 == 'X') {
							if(c1 == 'O' && c4 == 'O') {
							EZ_DrawLine(600, 0, 400, 200);
							EZ_DrawLine(400, 0, 600, 200);
							EZ_DisplayDrawing();
							t7++;
							c7 = 'X';
							break;
							}
							if(t9 == 0) {
							EZ_DrawLine(400, 400, 600, 600);
							EZ_DrawLine(600, 400, 400, 600);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'X';
							break;
							}
						}
					break;
					case 3:
						if(c1 == 'X' && c3 == 'X' && t2 == 0) {
							EZ_DrawLine(200, 200, 0, 400);
							EZ_DrawLine(0, 200, 200, 400);
							EZ_DisplayDrawing();
							t2++;
							c2 = 'X';
							break;
						}
						if(c1 == 'X' && c7 == 'X' && t4 == 0) {
							EZ_DrawLine(400, 0, 200, 200);
							EZ_DrawLine(200, 0, 400, 200);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'X';
							break;
						}
						if(c7 == 'X' && c3 == 'X' && t5 == 0) {
							EZ_DrawLine(200, 200, 400, 400);
							EZ_DrawLine(400, 200, 200, 400);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'X';
							break;
						}
						if(t9 == 0) {
							EZ_DrawLine(400, 400, 600, 600);
							EZ_DrawLine(600, 400, 400, 600);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'X';
							break;
						}
						if(t5 == 0) {
							EZ_DrawLine(400, 200, 200, 400);
							EZ_DrawLine(200, 200, 400, 400);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'X';
							break;
						}
						if(t6 == 0) {
							EZ_DrawLine(400, 400, 200, 600);
							EZ_DrawLine(200, 400, 400, 600);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'X';
							break;
						}
						if(t8 == 0) {
							EZ_DrawLine(600, 200, 400, 400);
							EZ_DrawLine(400, 200, 600, 400);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'X';
							break;
						}
					break;
					case 4:
						if(c6 == 'X' && t9 == 0) {
							EZ_DrawLine(400, 400, 600, 600);
							EZ_DrawLine(600, 400, 400, 600);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'X';
							break;
						}
						if(c4 == 'X' && t7 == 0) {
							EZ_DrawLine(400, 0, 600, 200);
							EZ_DrawLine(600, 0, 400, 200);
							EZ_DisplayDrawing();
							t7++;
							c7 = 'X';
							break;
						}
						if(t2 == 0) {
							EZ_DrawLine(200, 200, 0, 400);
							EZ_DrawLine(0, 200, 200, 400);
							EZ_DisplayDrawing();
							t2++;
							c2 = 'X';
							break;
						}
						if(t8 == 0) {
							EZ_DrawLine(600, 200, 400, 400);
							EZ_DrawLine(400, 200, 600, 400);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'X';
							break;
						}
						if(t6 == 0) {
							EZ_DrawLine(400, 400, 200, 600);
							EZ_DrawLine(200, 400, 400, 600);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'X';
							break;
						}
						if(t4 == 0) {
							EZ_DrawLine(400, 0, 200, 200);
							EZ_DrawLine(200, 0, 400, 200);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'X';
							break;
						}				
					break;
				}//end switch
				turn++;
				cTurn++;
			}//end pick if				
		//computer O
		}
		if(playerPiece == 'X') {
			if(pick == 2) {
			switch(cTurn) {
				case 1:
					if(t3 == 0 && t2 == 0 && t6 == 0) {
						EZ_OutlineCircle(100, 500, 60);
						EZ_DisplayDrawing();
						t3++;
						c3 = 'O';
						break;
					}
					if(t7 == 0 && t4 == 0 && t8 == 0) {
						EZ_OutlineCircle(500, 100, 60);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'O';
						break;
					}
				break;
				case 2:
					if(c2 == c8 && c2 == 'X') {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						break;
					}
					if(t2 == 0 && c3 == 'O') {
						EZ_OutlineCircle(100, 300, 60);
						EZ_DisplayDrawing();
						t2++;
						c2 = 'O';
						break;
					}
					if(t4 == 0 && c7 == 'O') {
						EZ_OutlineCircle(300, 100, 60);
						EZ_DisplayDrawing();
						t4++;
						c4 = 'O';
						break;
					}
					if(c6 == 'X' && c4 == 'X') {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						break;
					}
					if(t9 == 0) {
						EZ_OutlineCircle(500, 500, 60);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'O';
						break;
					}
					if(t7 == 0) {
						EZ_OutlineCircle(500, 100, 60);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'O';
						break;
					}
				break;
				case 3:
					if(c9 == c7) {
						if(t6 == 0) {
						EZ_OutlineCircle(500, 300, 60);
						EZ_DisplayDrawing();
						t8++;
						c8 = 'O';
						break;
						}
					}
					if(c9 == 'O' && c3 == 'O' && t6 == 0) {
						EZ_OutlineCircle(300, 500, 60);
						EZ_DisplayDrawing();
						t6++;
						c6 = 'O';
						break;
					}
					if(c1 == 'O' && c9 == 'O' && t5 == 0) {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						break;
					}
					if(c1 == 'O' && c7 == 'O' && t4 == 0) {
						EZ_OutlineCircle(300, 100, 60);
						EZ_DisplayDrawing();
						t4++;
						c4 = 'O';
						break;
					}
					if(c7 == 'O' && c3 == 'O' && t5 == 0) {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						break;
					}
					if(c1 == 'O' && c7 == 'O' && c5 == 'O') {
						if(t9 == 0) {	
							EZ_OutlineCircle(500, 500, 60);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'O';
							break;
						}
						if(t3 == 0) {
							EZ_OutlineCircle(100, 500, 60);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'O';
							break;
						}
					}
					if(c5 == 'X') {
						if(c4 == 'X') {
							EZ_OutlineCircle(300, 500, 60);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'O';
							break;
						}
						if(c6 == 'X') {
							EZ_OutlineCircle(300, 100, 60);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'O';
							break;
						}
					}
					if(c8 == 'X' && c2 == 'X') {
						EZ_OutlineCircle(300, 300, 60);
						EZ_DisplayDrawing();
						t5++;
						c5 = 'O';
						break;
					}
					if(c3 == 'O' && c9 == 'O') {
						if(c5 == 'X') {
							EZ_OutlineCircle(300, 500, 60);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'O';
							break;
						}
						if(c6 == 'X') {
							EZ_OutlineCircle(300, 300, 60);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'O';
							break;
						}
					}
					if(c7 == 'O' && c9 == 'O') {
						if(c5 == 'X') {
							EZ_OutlineCircle(500, 300, 60);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'O';
							break;
						}
						if(c8 == 'X') {
							EZ_OutlineCircle(300, 300, 60);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'O';
							break;
						}
					}
				break;
				case 4:
					if(c6 == 'O' && t9 == 0) {
						EZ_OutlineCircle(500, 500, 60);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'O';
						break;
					}
					if(c4 == 'O' && t7 == 0) {
						EZ_OutlineCircle(500, 100, 60);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'O';
						break;
					}
					if(t9 == 0) {
						EZ_OutlineCircle(500, 500, 60);
						EZ_DisplayDrawing();
						t9++;
						c9 = 'O';
						break;
					}
					if(t7 == 0) {
						EZ_OutlineCircle(500, 100, 60);
						EZ_DisplayDrawing();
						t7++;
						c7 = 'O';
						break;
					}
					if(t6 == 0) {
						EZ_OutlineCircle(300, 500, 60);
						EZ_DisplayDrawing();
						t6++;
						c6 = 'O';
						break;
					}
				break;
			}//end switch
			turn++;
			cTurn++;
			//user going first
			} else if(pick == 1) {
				switch(cTurn) {
					case 1:
						if(t1 == 0) {
							EZ_OutlineCircle(100, 100, 60);
							EZ_DisplayDrawing();
							t1++;
							c1 = 'O';
							break;
						}
						if(t3== 0) {
							EZ_OutlineCircle(100, 500, 60);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'O';
							break;
						}
					break;
					case 2:
						if(c1 == 'O') {
							if(t3 == 0) {
							EZ_OutlineCircle(100, 500, 60);
							EZ_DisplayDrawing();
							t3++;
							c3 = 'O';
							break;
							} else if(t7 == 0) {
							EZ_OutlineCircle(500, 100, 60);
							EZ_DisplayDrawing();
							t7++;
							c7 = 'O';
							break;
							}
						}
						if(c3 == 'O') {
							if(c1 == 'X' && c4 == 'X') {
							EZ_OutlineCircle(500, 100, 60);
							EZ_DisplayDrawing();
							t7++;
							c7 = 'O';
							break;
							}
							if(t9 == 0) {
							EZ_OutlineCircle(500, 500, 60);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'O';
							break;
							}
						}
					break;
					case 3:
						if(c1 == 'O' && c3 == 'O' && t2 == 0) {
							EZ_OutlineCircle(100, 300, 60);
							EZ_DisplayDrawing();
							t2++;
							c2 = 'O';
							break;
						}
						if(c1 == 'O' && c7 == 'O' && t4 == 0) {
							EZ_OutlineCircle(300, 100, 60);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'O';
							break;
						}
						if(c7 == 'O' && c3 == 'O' && t5 == 0) {
							EZ_OutlineCircle(300, 300, 60);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'O';
							break;
						}
						if(t9 == 0) {
							EZ_OutlineCircle(500, 500, 60);
							EZ_DisplayDrawing();
							t9++;
							c9 = 'O';
							break;
						}
						if(t5 == 0) {
							EZ_OutlineCircle(300, 300, 60);
							EZ_DisplayDrawing();
							t5++;
							c5 = 'O';
							break;
						}
						if(t6 == 0) {
							EZ_OutlineCircle(300, 500, 60);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'O';
							break;
						}
						if(t8 == 0) {
							EZ_OutlineCircle(500, 300, 60);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'O';
							break;
						}
					break;
					case 4:
						if(t2 == 0) {
							EZ_OutlineCircle(100, 300, 60);
							EZ_DisplayDrawing();
							t2++;
							c2 = 'O';
							break;
						}
						if(t8 == 0) {
							EZ_OutlineCircle(500, 300, 60);
							EZ_DisplayDrawing();
							t8++;
							c8 = 'O';
							break;
						}
						if(t6 == 0) {
							EZ_OutlineCircle(300, 500, 60);
							EZ_DisplayDrawing();
							t6++;
							c6 = 'O';
							break;
						}
						if(t4 == 0) {
							EZ_OutlineCircle(300, 100, 60);
							EZ_DisplayDrawing();
							t4++;
							c4 = 'O';
							break;
						}
					break;				
				}//end switch
				turn++;
				cTurn++;
			}//end pick
		}//end computer as o
		EZ_DisplayDrawing();		
	}//end turn
	EZ_DisplayDrawing();
	//checking for winning combinations 
	if(t1 != 0){
		if(c1 == c4 && c4 == c7) {
			if(playerPiece == c1) {
				printf("Congrats!! You Won!\n");
				winner++;
				uScore++;
			} 
			if(playerPiece != c1) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
		if(c1 == c2 && c2 == c3) {
			if(playerPiece == c1) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			}
			if(playerPiece != c1) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
		if(c1 == c5 && c5 == c9) {
			if(playerPiece == c1) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			} 
			if(playerPiece != c1) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
	}//end if
	if(t5 != 0) {
		if(c2 == c5 && c5 == c8) {
			if(playerPiece == c2) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			} 
			if(playerPiece != c2) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
		if(c3 == c5 && c5 == c7) {
			if(playerPiece == c3) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			} 
			if(playerPiece != c3) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
	}//end if
	if(t6 != 0) {
		if(c3 == c6 && c6 == c9) {
			if(playerPiece == c3) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			}
			if(playerPiece != c3) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
		if(c4 == c5 && c5 == c6) {
			if(playerPiece == c4) {
				winner++;
				uScore++;
				printf("Congrats!! You Won!\n");
			}
			if(playerPiece != c4) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
	}//end if
	if(t9 != 0) {
		if(c7 == c8 && c8 == c9) {
			if(playerPiece == c7) {
				winner++;
				printf("Congrats!! You Won!\n");
				uScore++;
			} 
		        if(playerPiece != c7) {
				winner++;
				cScore++;
				printf("Sorry, you lost :(\nBetter luck next time!");
			}
		}//end if
	}//end if
	//checking for draw
	if(t1 == t2 && t2 == t3 && t4 == t5 && t5 == t6) {
		if(t6 == t7 && t7 == t8 && t8 == t9) {
			winner++;
			dScore++;
			printf("\nThe match was a draw. \nThere was no winner.");
		}
	}
		
	//printing score
	if(winner == 1) {
		printf("\n\t\tScore");
		printf("\n\tUser: %d", uScore);
		printf("\n\tComputer: %d", cScore);
		printf("\n\tDraws: %d", dScore);
	}
	}
	EZ_DisplayDrawing();
}

void handleButton(int clicking, int x, int y) {
	if(clicking == 1) {
		//if statements for what grid is selected
		if(x < 200) {
			if(y < 200) {
				click = 1;
				grid = 1;
			}
			if(y > 200 && y < 400) {
				click = 1;
				grid = 2;
			}
			if(y > 400) {
				click = 1;
				grid = 3;
			}
		}
		if(x > 200 && x < 400) { 
			if(y < 200) {
				click = 1;
				grid = 4;
			}
			if(y > 200 && y < 400) {
				click = 1;
				grid = 5;
			}
			if(y > 400) {
				click = 1;
				grid = 6;
			}
		}
		if(x > 400) {
			if(y < 200) {
				click = 1;
				grid = 7;
			}
			if(y > 200 && y < 400) {
				click = 1;
				grid = 8;
			}
			if(y > 400) {
				click = 1;
				grid = 9;
			}
		}
		
	} else {
		grid = 0;
		click = 0;
	}

}

int main() {

	//keeps playing while user does not say 0
	while(playAgain == 1) {
		//asking user what piece they would like to be
		printf("\nWould you like to be 'X' or 'O': ");
		scanf("%c", &playerPiece);
		while(playerPiece != 'X' && playerPiece != 'O') {
			printf("\nError, Please enter a valid option...");
			printf("\nWould you like to be 'X' or 'O': ");
			scanf("%c", &playerPiece);
		}

		//asking user if they would like to go first or second
		printf("\nWould you like to go first (1),\n");
		printf("or would you like the computer to go first (2): ");
		scanf("%d", &pick);
		while(pick != 1 && pick != 2) {
			printf("\nError, please enter a valid option...");
			printf("\nWould you like to go first (1),\n");
			printf("or would you like the computer to go first (2): ");
			scanf("%d", &pick);
		}

		//executing updateDisplay and handleButton functions
		int quit = FALSE;
		EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "ttt");
		while(!quit) {
			quit = EZ_HandleEvents(updateDisplay, NULL, handleButton, NULL);
			if(winner == 1) {
				winner--;
				quit = TRUE;
				tracker++;
			}
		}
		EZ_Quit();
		printf("\nWould you like to play again?");
		printf("\nYes (1) or No (0): ");
		scanf("%d", &playAgain);
	
		while(playAgain != 1 && playAgain != 0) {
			printf("Error, please enter a valid value");
			printf("\nWould you like to play again?");
			printf("\nYes (1) or No (0): ");
			scanf("%d", &playAgain);
		}
	
		if(playAgain == 1) {
			winner = 0;
			quit = FALSE;
		}
		if(playAgain == 0) {
			printf("\n\t\tThank you for playing!!");
			printf("\n\t\tThe final score was: ");
			printf("\n\tUser: %d", uScore);
		        printf("\n\tComputer: %d", cScore);
			printf("\n\tPlay again soon!!\n");	
			
		}
		//reseting values
		if(tracker == 1) {
			t1 = 0;
			t2 = 0;
			t3 = 0;
			t4 = 0;
			t5 = 0;
			t6 = 0;
			t7 = 0;
			t8 = 0;
			t9 = 0;
			c1 = 'N';
			c2 = 'N';
			c3 = 'N';
			c4 = 'N';
			c5 = 'N';
			c6 = 'N';
			c7 = 'N';
			c8 = 'N';
			c9 = 'N';
			cTurn = 1;
			turn = 2;
			tracker--;
			numOfRuns--;
			pick = 0;
			playerPiece = 'N';
			EZ_ClearDrawing();
		}

	}//end while

	EZ_Quit();
	return 0;
}
