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

void bkCmd(info * state, cmd * input) {
    int tempNum = 0;
    int xOrig = 0;
    int yOrig = 0;
    int type = 1;
    xOrig = state->x;
    yOrig = state->y;
    tempNum = input->magnitude;
    move(state->y,state->x);
    printw(" ");
    switch (state->dir) {
        case 1:
            state->y = state->y + tempNum;
            break;
        case 2:
            state->x = state->x - tempNum;
            break;
        case 3:
            state->y = state->y - tempNum;
            break;
        case 4:
            state->x = state->x + tempNum;
            break;
    }
    move(state->y,state->x);
    printw("O");
    if (state->pen == 1) {
        printPath(state, yOrig, xOrig, input, type);
    }
    refresh();

}

void convertToNum(cmd * commandPtr) {
    commandPtr->magnitude = atol(commandPtr->wordTwo);
}

void createCommand(char * input, cmd * userCommandPtr) {
    char * token;
    token = strtok(input, " ");
    strcpy(userCommandPtr->wordOne, token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        return;
    }
    strcpy(userCommandPtr->wordTwo, token);
    convertToNum(userCommandPtr);
}

void fdCmd(info * state, cmd * input) {
    int tempNum = 0;
    int xOrig = 0;
    int yOrig = 0;
    int type = 0;
    xOrig = state->x;
    yOrig = state->y;
    tempNum = input->magnitude;
    tempNum = input->magnitude;
    move(state->y,state->x);
    printw(" ");
    switch (state->dir) {
        case 1:
            state->y = state->y - tempNum;
            break;
        case 2:
            state->x = state->x + tempNum;
            break;
        case 3:
            state->y = state->y + tempNum;
            break;
        case 4:
            state->x = state->x - tempNum;
            break;
    }
    move(state->y,state->x);
    printw("O");
    if (state->pen == 1) {
        printPath(state, yOrig, xOrig, input, type);
    }
    refresh();
}

void ltCmd(info * state) {
    switch (state->dir) {
        case 1:
            state->dir = 4;
            break;
        case 2:
            state->dir = 1;
            break;
        case 3:
            state->dir = 2;
            break;
        case 4:
            state->dir = 3;
            break;
    } 
}

void rtCmd(info * state) {
    switch (state->dir) {
        case 1:
            state->dir = 2;
            break;
        case 2:
            state->dir = 3;
            break;
        case 3:
            state->dir = 4;
            break;
        case 4:
            state->dir = 1;
            break;
    }
}

