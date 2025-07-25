#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
using namespace std;

extern char arr[3][3];
extern char A[3][3];
extern int turns;
extern char player;
extern bool Flag;
extern int R;
extern char p;

void BuildArr();
void Choose();
char Check_Who_Win();
void computer_Turn_M();
void computer_Turn_H();
void computer_Turn_E();
void Two_Player_Game(char& p);
void One_Player_Game_Easy(char& p);
void One_Player_Game_Medium(char& p);
void One_Player_Game_Hard(char& p);

#endif