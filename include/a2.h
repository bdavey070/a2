/********************************************************************************************
Student Name: Benjamin Davey    Student Number: 0885413 
Date: Friday, March 26, 2015    Course Name: CIS2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
**********************************************************************************************/

typedef struct command
{
	char * wordOne;
	char * wordTwo;
	int magnitude;
}cmd;


typedef struct info
{
	int x;
	int y;
	int dir;  /*1 is north, 2 is east, 3 is south, 4 is west*/
	int pen;  /*0 is pen up, 1 is pen down*/
}info;

/*************************************Command functions*************************************/
/*********************
Function: bkCmd
Purpose: To move the cursor back a user defined number of spaces.
Pre: Takes in a pointer to a struct containing the current state and a struct containing info about user input.
Post: Moves to the new location and prints the cursor.  If pen is down calls printPath.
*********************/
void bkCmd(info * state, cmd * input);

/*********************
Function: converToNum
Purpose: To convert the second part of user input  from string to number.
Pre: Takes in a pointer to a struct containing info about user input.
Post: Sets the magnitude of the struct to the number that is contained in the wordTwo string.
*********************/
void convertToNum(cmd * commandPtr);

/*********************
Function: createCommand
Purpose: To turn the input string into a command struct.
Pre: Takes in a pointer to a string of the user input and a pointer the the command struct.
Post: Assigns strings to wordOne and wordTwo and a value to magnitude based on the user input string.
*********************/
void createCommand(char * input, cmd * userCommandPtr);

/*********************
Function: fdCmd
Purpose: To move the cursor forward a user defined number of spaces.
Pre: Takes in a pointer to a struct containing the current state and a struct containing info about user input.
Post: Moves to the new location and prints the cursor.  If pen is down calls printPath.
*********************/
void fdCmd(info * state, cmd * input);

/*********************
Function: ltCmd
Purpose: To change the orientation of the cursor by changing the value of direction in the state struct.
Pre: Takes in a pointer to a struct containing the current state.
Post: Changes value of direction in pointer.
*********************/
void ltCmd(info * state);

/*********************
Function: rtCmd
Purpose: To change the orientation of the cursor by changing the value of direction in the state struct.
Pre: Takes in a pointer to a struct containing the current state.
Post: Changes value of direction in pointer.
*********************/
void rtCmd(info * state);

/*************************************Drawing functions*************************************/
/*********************
Function: drawInterface
Purpose: To draw the environment in ncurses.
Pre: Takes in nothing.
Post: Interface is printed to screen.
*********************/
void drawInterface();

/*********************
Function: printPath
Purpose: To print the path of the cursor when the pen is down.
Pre: Takes in a pointer to a struct containing the current state, a pointer to the command struct containing the 
     user command, integers representing the original location of the cursor and an integer representing whether it 
     is called from fdCmd or bkCmd.
Post: Prints the path followed by the cursor.
*********************/
void printPath(info * state, int yOrig, int xOrig, cmd * input, int type);

/*************************************IO functions*************************************/
/*********************
Function: getInput
Purpose: To get input from the user and echo it in the input box.
Pre: Takes in a pointer to a string where the user input is to be stored.
Post: Echos typing in the input box and changes string to the input provided by the user.
*********************/
void getInput(char * input);

/*********************
Function: printToMessage
Purpose: To print to the message box feedback for the user.
Pre: Takes in a pointer to a string of the message to be printed.
Post: Prints the message to the message box.
*********************/
void printToMessage(char *message);

/*********************
Function: resetInput
Purpose: To to clear the text in the input box.
Pre: Takes in nothing.
Post: Prints spaces in input box to remove former content.
*********************/
void resetInput();

/*********************
Function: resetMessage
Purpose: To to clear the text in the message box.
Pre: Takes in nothing.
Post: Prints spaces in message box to remove former content.
*********************/
void resetMessage();









