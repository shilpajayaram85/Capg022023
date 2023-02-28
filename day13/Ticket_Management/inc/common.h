#ifndef COMMON_H
#define COMMON_H
#include<stdio.h>
#include<string.h>
#include<persons.h>
#include<login.h>


int dispMain();

int signUP(PERSON *);
int signIN(PERSON * ,LOGIN *, int *);
int tktBkgMenu();
#endif
