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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "a2.h"

int main() {
/*Variable initialization and memory allocation*/
    char * inputPtr;
    cmd * commandPtr;
    info * statePtr;
    statePtr = malloc(sizeof(info));
    inputPtr = malloc(sizeof(char) * 20);
    commandPtr = malloc(sizeof(cmd));
    commandPtr->wordOne = malloc(sizeof(char) * 5);
    commandPtr->wordTwo = malloc(sizeof(char) * 5);
/*Initializing ncurses and drawing interface*/	
    initscr();
    cbreak ();
    noecho ();
    drawInterface();
    refresh();
/*Setting initial conditions*/
    statePtr->y = 12;
    statePtr->x = 50;
    statePtr->dir = 1;
    statePtr->pen = 0;
/*Main functional loop*/
    while (strcmp(inputPtr, "quit") != 0) {
        resetInput();
        getInput(inputPtr);
        createCommand(inputPtr, commandPtr);
        resetMessage();
        printToMessage(inputPtr);
/*Checks first input and directs to proper function*/
        if (strcmp(commandPtr->wordOne, "fd") == 0) {
            fdCmd(statePtr, commandPtr);
        } else if (strcmp(commandPtr->wordOne, "bk") == 0) {
            bkCmd(statePtr, commandPtr);
        } else if (strcmp(commandPtr->wordOne, "rt") == 0) {
            rtCmd(statePtr);
        } else if (strcmp(commandPtr->wordOne, "lt") == 0) {
            ltCmd(statePtr);
        } else if (strcmp(commandPtr->wordOne, "pu") == 0) {
            statePtr->pen = 0;
        } else if (strcmp(commandPtr->wordOne, "pd") == 0) {
            statePtr->pen = 1;
        } else {
            printToMessage("invalid input");
        }
    }

/*Close ncurses*/
    refresh();
    endwin();
    free(inputPtr);
    free(commandPtr->wordOne);
    free(commandPtr->wordTwo);
    free(commandPtr);
    free(statePtr);
	return 0;
}

