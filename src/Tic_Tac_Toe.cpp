#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Functions.h"
using namespace std;

char p = 'R';

int main() {
    system("COLOR 3e");

start_menu:  // <== Your label here

    system("cls");
    char num1 = 177, num2 = 219;
    cout << "\n\n\n\n\n\t\t\t\t\t    -->|| Tic Tac Toe ||<--";
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   Loading......";
    cout << "\n\n\t\t\t\t\t";
    for (int k = 0; k < 30; k++) cout << num1;
    cout << "\r\t\t\t\t\t";
    for (int k = 0; k < 30; k++) {
        cout << num2;
        Sleep(100);
    }
    cout << "\n\t\t\t\t\t" << (char)1 << "!";
    system("pause");
    system("cls");

game_selection:  // <== You want to return here when 'M' is pressed
    bool running = true;
    while (running) {
        system("cls");
        int N;
        cout << "\n\n\n\t\t\t\to PLAY WITH FRIEND     (Press 1)\n\t\t\t\to PLAY WITH COMPUTER   (Press 2)\n\t\t\t\to EXIT                (Press 3)\n Enter Your Choice :  ";
        cin >> N;

        while (!(N == 1 || N == 2 || N == 3)) {
            cout << "\n Please Enter 1, 2 or 3 ... :) \n\n Your Choice : ";
            cin >> N;
        }

        if (N == 3) {
            running = false;
            continue;
        }

        char p = 'R';
        if (N == 1) {
            Two_Player_Game(p);
        }
        else if (N == 2) {
            int n;
            system("cls");
            cout << "\n\n\n\t\t\t\to HARD    (Press 1)\n\t\t\t\to MEDIUM  (Press 2)\n\t\t\t\to EASY    (Press 3)\n Enter Your Choice :  ";
            cin >> n;
            while (!(n == 1 || n == 2 || n == 3)) {
                cout << "\n Please Enter 1, 2 or 3 ... :) \n\n Your Choice : ";
                cin >> n;
            }

            if (n == 1) One_Player_Game_Hard(p);
            else if (n == 2) One_Player_Game_Medium(p);
            else if (n == 3) One_Player_Game_Easy(p);
        }

        if (p == 'E' || p == 'e') running = false;
    }

    return 0;
}