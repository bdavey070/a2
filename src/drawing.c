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

void drawInterface() {
    int i = 0;
    start_color();
    init_pair(2, 7, 7);
    attron(COLOR_PAIR (2));
    
    for (i=0; i<80; i++) {
        move(0, i);
        printw("*"); 
    }
    for (i=0; i<25; i++) {
        move(20, i);
        printw("*"); 
    }
    for (i=0; i<80; i++) {
        move(23, i);
        printw("*"); 
    }
    for (i=0; i<23; i++) {
        move(i, 0);
        printw("*"); 
    }
    for (i=0; i<23; i++) {
        move(i, 24);
        printw("*"); 
    }
    for (i=0; i<23; i++) {
        move(i, 79);
        printw("*"); 
    }
    start_color();
    init_pair(1, 7, 0);
    attron(COLOR_PAIR (1));
    move(12,50);
    printw("O");
}

void printPath(info * state, int yOrig, int xOrig, cmd * input, int type) {
    int i = 0;
    switch (state->dir) {
        case 1:
            move(yOrig, xOrig);
            for (i = 0; i < (input->magnitude - 1); i++) {
                if (type == 0) {
                    yOrig--;
                } else if (type == 1) {
                    yOrig++;
                }
                move(yOrig, xOrig);
                printw(".");
            }
            break;
        case 2:
            move(yOrig, xOrig);
            for (i = 0; i < (input->magnitude - 1); i++) {
                if (type == 0) {
                    xOrig++;
                } else if (type == 1) {
                    xOrig--;
                }
                move(yOrig, xOrig);
                printw(".");
            }
            break;
        case 3:
            move(yOrig, xOrig);
            for (i = 0; i < (input->magnitude - 1); i++) {
                if (type == 0) {
                    yOrig++;
                } else if (type == 1) {
                    yOrig--;
                }
                move(yOrig, xOrig);
                printw(".");
            }
            break;
        case 4:
            move(yOrig, xOrig);
            for (i = 0; i < (input->magnitude - 1); i++) {
                if (type == 0) {
                    xOrig--;
                } else if (type == 1) {
                    xOrig++;
                }
                move(yOrig, xOrig);
                printw(".");
            }
            break;
    }
    
}

