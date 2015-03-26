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

void getInput(char * input) {
    move(21,1);
    start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
    echo();
    getstr(input);
}

void printToMessage(char *message) {
    int yOrig = 0;
    int xOrig = 0;
    int y = 1;
    int x = 1;  
    start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
    getyx(stdscr, yOrig, xOrig);
    mvwprintw (stdscr, y, x, message);
    move(yOrig,xOrig);
    refresh();
}

void resetInput() {
    mvwprintw(stdscr, 21, 1,"                       ");
}

void resetMessage() {
    mvwprintw(stdscr, 1, 1,"                       ");
}

