#include "iGraphics.h"
#include"time.h"
#include"bass.h"
#define ScreenWidth 1080
#define ScreenHeight 640
#define  btsx  450
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct menubutton
{
	int x;
	int y;
	int height;
	int width;
	bool selectingArea;

	menubutton(int menux, int menuy)
	{
		x = menux;
		y = menuy;
		height = 55;
		width = 222;
		selectingArea = false;    //if false then pic1, if true then pic2
	}
};
struct mapselect
{
	int x;
	int y;
	int height;
	int width;
	bool levelselectingArea;

	mapselect(int menux, int menuy)
	{
		x = menux;
		y = menuy;
		height = 55;
		width = 97;
		levelselectingArea = false;    //if false then pic1, if true then pic2
	}
};
mapselect level1(816,220);
mapselect level2(12, 12);
mapselect level3(12, 12);
menubutton playbutton(200, 460);
menubutton instructionsbutton(btsx, 360);
menubutton highscorebutton(btsx, 260);
menubutton creditsbutton(btsx, 160);
menubutton exitbutton(btsx, 60);

bool areaSelected(int mx, int my, menubutton obj)   //mouse er kahini chole
{
	if ((mx > obj.x && mx < obj.x + obj.width) && (my > obj.y && my < obj.y + obj.height))
		return true;
	else
	{
		return false;
	}
}
bool levelareaselected(int mx, int my, mapselect obj)
{
	if ((mx > obj.x && mx < obj.x + obj.width) && (my > obj.y && my < obj.y + obj.height))
		return true;
	else
	{
		return false;
	}
}
int GameState = 0;
bool click = false;
int a;
int menu[5][1];
int map[3][1];

bool menuSelectingArea(int mx, int my){
	bool truth = false;
	if (GameState == 0)    //for MENU SCREEN BUTTONS
	{
		if (areaSelected(mx, my, playbutton)==true) ///Selecting area conditions
		{
			playbutton.selectingArea = true;
			truth = true;
		}
		else if (areaSelected(mx, my, instructionsbutton) == true)
		{
			playbutton.selectingArea = true;
			truth = true;
		}
		else if (areaSelected(mx, my, highscorebutton) == true)
		{
			playbutton.selectingArea = true;
			truth = true;
		}
		else if (areaSelected(mx, my, creditsbutton) == true)
		{
			playbutton.selectingArea = true;
			truth = true;
		}
		else if (areaSelected(mx, my, exitbutton) == true)
		{
			playbutton.selectingArea = true;
			truth = true;
		}
	}
	if (GameState == 1)
	{
		if (levelareaselected(mx,my,level1) == true) 
		{
			level1.levelselectingArea = true;
			truth = true;
		}
		else if (levelareaselected(mx, my, level2) == true)
		{
			level2.levelselectingArea = true;
			truth = true;
		}
		else if (levelareaselected(mx, my, level3) == true)
		{
			level3.levelselectingArea = true;
			truth = true;
		}

	}
	return truth;
}
void GameState0()
{
	
	iShowImage(0, 0, ScreenWidth, ScreenHeight, a); //menu background pic dekhabe

	//:::::::::::::PLAY_BUTTON:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (playbutton.selectingArea == false)
	{
		iShowImage(playbutton.x, playbutton.y, playbutton.width, playbutton.height, menu[0][0]);
		iText(530,482,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (playbutton.selectingArea == true && click == true)
	{
		click = false;
		GameState = 1;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}
	//:::::::::::::Instructions_BUTTON:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (playbutton.selectingArea == false)
	{
		iShowImage(instructionsbutton.x, instructionsbutton.y, instructionsbutton.width, instructionsbutton.height, menu[1][0]);
		iText(470, 382, "INSTRUCTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (playbutton.selectingArea == true && click == true)
	{
		//BASS_ChannelPlay(ingamesound, true);
		click = false;
		GameState = 1;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);

	}
	//:::::::::::::High_Score_BUTTON:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (playbutton.selectingArea == false)
	{
		iShowImage(highscorebutton.x, highscorebutton.y, highscorebutton.width, highscorebutton.height, menu[2][0]);
		iText(487, 282, "HIGH SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (playbutton.selectingArea == true && click == true)
	{
	//BASS_ChannelPlay(ingamesound, true);
		click = false;
		GameState = 1;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}
	//:::::::::::::Credits_BUTTON:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (playbutton.selectingArea == false)
	{
		iShowImage(creditsbutton.x, creditsbutton.y, creditsbutton.width, creditsbutton.height, menu[3][0]);
		iText(505, 182, "CREDITS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (playbutton.selectingArea == true && click == true)
	{
	//BASS_ChannelPlay(ingamesound, true);
		click = false;
		GameState = 1;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}

	//:::::::::::::Exit_BUTTON:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (playbutton.selectingArea == false)
	{
		iShowImage(exitbutton.x, exitbutton.y, exitbutton.width, exitbutton.height, menu[4][0]);
		iText(528, 82, "EXIT", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if (playbutton.selectingArea == true && click == true)
	{
		//BASS_ChannelPlay(ingamesound, true);
		click = false;
		GameState = 1;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}
}
void GameState1()
{
	iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]); ////LEVEL MAP LEVEL 1 Dekhabe

	//:::::::::::::LEVEL 1:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (level1.levelselectingArea== false)
	{
		
	}
	else if (level1.levelselectingArea == true && click == true)
	{
		
		click = false;
		GameState = 2;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}
	//:::::::::::::Level 2:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (level2.levelselectingArea == false)
	{

	}
	else if (level2.levelselectingArea == true && click == true)
	{
		//BASS_ChannelPlay(ingamesound, true);
		click = false;
		GameState = 0;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);

	}
	//:::::::::::::Level 3:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	if (level3.levelselectingArea == false)
	{
	
	}
	else if (level3.levelselectingArea == true && click == true)
	{
		click = false;
		GameState = 2;
		iShowImage(0, 0, ScreenWidth, ScreenHeight, map[0][0]);
	}
}
void GameState2()
{
	iShowImage(0, 0, ScreenWidth, ScreenHeight, map[1][0]);
}
void GameState3(){

}
void GameState4(){

}

void iDraw()
{
	iClear();
	if (GameState == 0)
	{
		GameState0();
		//menubuttons();
	}
	else if (GameState == 1)
	{
		GameState1();        
	}
	else if (GameState == 2)
	{
		GameState2();
		
	}
	else if (GameState == 3)
	{
		GameState3();

	}
	else if (GameState == 4)
	{
		GameState4();

	}


}
/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d \t %d", mx, my);
		if (menuSelectingArea(mx, my) == true)
			click = true;
		else
			click = false;

		printf("Clicked\n");
		

	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}
void menucall()
{
	menu[0][0] = iLoadImage("./images/menubutton/Final.png");
	menu[1][0] = iLoadImage("./images/menubutton/test.png");
	menu[2][0] = iLoadImage("./images/menubutton/test.png");
	menu[3][0] = iLoadImage("./images/menubutton/test.png");
	menu[4][0] = iLoadImage("./images/menubutton/test.png");
	//map = iLoadImage("./images/map.jpg");
	map[0][0] = iLoadImage("./images/Map/1.png");
	map[1][0] = iLoadImage("./images/Map/2.png");
}

int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(ScreenWidth,ScreenHeight, "LALALA");
	///updated see the documentations
	a = iLoadImage("./images/menu.png");
	menucall();
	iStart();
	return 0;
}