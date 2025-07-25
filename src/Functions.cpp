#include<iostream>
#include "functions.h"
using namespace std;

char arr[3][3] = { '1','2','3','4','5','6','7','8','9' };
char A[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
int turns = 0;
char player = 'X';
bool Flag = false;
int R = 0;

void BuildArr() {
    system("cls");
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  " << arr[i][j];
            if (j == 0 || j == 1) cout << "  |";
        }
        if (i == 0 || i == 1) {

            cout << endl;
            cout << " ____|_____|____" << endl << "     |     |";
        }
        cout << endl;
    } cout << "\n";


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "  " << A[i][j];
            if (j == 0 || j == 1) cout << "  |";
        }
        if (i == 0 || i == 1) {
            cout << endl;
            cout << " ____|_____|____" << endl << "     |     |";
        }
        cout << endl;
    }


}
void Choose() {
    int postion_2; //posion in board
    cout << "\n *  Choose your position (( player " << player << " )) :  ";
    cin >> postion_2;
    while (!(postion_2 >= 1 && postion_2 <= 9)) {
        cout << "\n\t\t It is an invaild position\n\n\tPlease Enter A Vaild Position ---> "; cin >> postion_2;
    }
    char Postion = postion_2 + 48;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((A[i][j] == 'X' || A[i][j] == 'O') && arr[i][j] == Postion) Flag = 1;
            else if (arr[i][j] == Postion) A[i][j] = player;
        }
    }
    if (player == 'X') player = 'O';
    else player = 'X';

}
char Check_Who_Win() {
    // Checking The Horizontal Rows .
    int Xc = 0, Oc = 0;
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[i][j] == ' ') counter++;
            if (A[i][j] == 'X') Xc++;
            else if (A[i][j] == 'O') Oc++;

            if (Xc == 3) return 'X';
            else if (Oc == 3) return 'O';
        }
        Xc = 0;  Oc = 0;
    }

    // Checking The Vertical Columns .
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (A[j][i] == 'X') Xc++;
            else if (A[j][i] == 'O') Oc++;
            if (Xc == 3) return 'X';
            else if (Oc == 3) return 'O';
        }
        Xc = 0;  Oc = 0;
    }
    // Checking The Main Diagonal .
    for (int i = 0; i < 3; i++) {
        if (A[i][i] == 'X') Xc++;
        else if (A[i][i] == 'O') Oc++;
    }
    if (Xc == 3) return 'X';
    else if (Oc == 3) return 'O';
    Xc = 0;  Oc = 0;

    // Checking The Secondary Diagonal .
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i + j == 2) {
                if (A[i][j] == 'X') Xc++;
                else if (A[i][j] == 'O') Oc++;
            }
        }
        if (Xc == 3) return 'X';
        else if (Oc == 3) return 'O';
    }
    if (counter == 0) return ('E');//   ..Then No One Win..
    return('P'); // ..Still Playing..
}
void computer_Turn_M() { //medium turn
    char choice;
    if (turns % 2 == 0) { cout << "\n   Choose your position (( player X )) :  "; cin >> R; while ((!(R >= 1 && R <= 9))) { cout << "\n\tPlease Enter a valid Position : "; cin >> R; } }
    else {

        // Checking The Horizontal Rows .
        if (A[0][1] == 'X' && A[0][2] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[0][2] == 'X' && A[0][1] == ' ') R = 2;
        else if (A[0][0] == 'X' && A[0][1] == 'X' && A[0][2] == ' ') R = 3;
        else if (A[1][1] == 'X' && A[1][2] == 'X' && A[1][0] == ' ') R = 4;
        else if (A[1][0] == 'X' && A[1][2] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[1][0] == 'X' && A[1][1] == 'X' && A[1][2] == ' ') R = 6;
        else if (A[2][1] == 'X' && A[2][2] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[2][0] == 'X' && A[2][2] == 'X' && A[2][1] == ' ') R = 8;
        else if (A[2][0] == 'X' && A[2][1] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Vertical columns .
        else if (A[1][0] == 'X' && A[2][0] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[2][0] == 'X' && A[1][0] == ' ') R = 4;
        else if (A[0][0] == 'X' && A[1][0] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[1][1] == 'X' && A[2][1] == 'X' && A[0][1] == ' ') R = 2;
        else if (A[0][1] == 'X' && A[2][1] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[0][1] == 'X' && A[1][1] == 'X' && A[2][1] == ' ') R = 8;
        else if (A[1][2] == 'X' && A[2][2] == 'X' && A[0][2] == ' ') R = 3;
        else if (A[0][2] == 'X' && A[2][2] == 'X' && A[1][2] == ' ') R = 6;
        else if (A[0][2] == 'X' && A[1][2] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Main Diagonal .
        else if (A[1][1] == 'X' && A[2][2] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[2][2] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[0][0] == 'X' && A[1][1] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Secondary Diagonal .
        else if (A[0][2] == 'X' && A[1][1] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[0][2] == 'X' && A[2][0] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[2][0] == 'X' && A[1][1] == 'X' && A[0][2] == ' ') R = 3;
        else R = rand() % (9) + 1;
    }// to prevent that it will be zero
    choice = R + 48;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((A[i][j] == 'X' || A[i][j] == 'O') && arr[i][j] == choice) Flag = 1;
            else if (arr[i][j] == choice) A[i][j] = player;
        }
    }
    if (player == 'X') player = 'O';
    else player = 'X';
}
void computer_Turn_H() {
    char choice;
    if (turns % 2 == 0) { cout << "\n   Choose your position (( player X )) :  "; cin >> R; while ((!(R >= 1 && R <= 9))) { cout << "\n\tPlease Enter a valid Position : "; cin >> R; } }
    else
    {
        // In Order To Win
       // Checking The Horizontal Rows .
        if (A[0][1] == 'O' && A[0][2] == 'O' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'O' && A[0][2] == 'O' && A[0][1] == ' ') R = 2;
        else if (A[0][0] == 'O' && A[0][1] == 'O' && A[0][2] == ' ') R = 3;
        else if (A[1][1] == 'O' && A[1][2] == 'O' && A[1][0] == ' ') R = 4;
        else if (A[1][0] == 'O' && A[1][2] == 'O' && A[1][1] == ' ') R = 5;
        else if (A[1][0] == 'O' && A[1][1] == 'O' && A[1][2] == ' ') R = 6;
        else if (A[2][1] == 'O' && A[2][2] == 'O' && A[2][0] == ' ') R = 7;
        else if (A[2][0] == 'O' && A[2][2] == 'O' && A[2][1] == ' ') R = 8;
        else if (A[2][0] == 'O' && A[2][1] == 'O' && A[2][2] == ' ') R = 9;
        // Checking The Vertical columns .
        else if (A[1][0] == 'O' && A[2][0] == 'O' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'O' && A[2][0] == 'O' && A[1][0] == ' ') R = 4;
        else if (A[0][0] == 'O' && A[1][0] == 'O' && A[2][0] == ' ') R = 7;
        else if (A[1][1] == 'O' && A[2][1] == 'O' && A[0][1] == ' ') R = 2;
        else if (A[0][1] == 'O' && A[2][1] == 'O' && A[1][1] == ' ') R = 5;
        else if (A[0][1] == 'O' && A[1][1] == 'O' && A[2][1] == ' ') R = 8;
        else if (A[1][2] == 'O' && A[2][2] == 'O' && A[0][2] == ' ') R = 3;
        else if (A[0][2] == 'O' && A[2][2] == 'O' && A[1][2] == ' ') R = 6;
        else if (A[0][2] == 'O' && A[1][2] == 'O' && A[2][2] == ' ') R = 9;
        // Checking The Main Diagonal .
        else if (A[1][1] == 'O' && A[2][2] == 'O' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'O' && A[2][2] == 'O' && A[1][1] == ' ') R = 5;
        else if (A[0][0] == 'O' && A[1][1] == 'O' && A[2][2] == ' ') R = 9;
        // Checking The Secondary Diagonal .
        else if (A[0][2] == 'O' && A[1][1] == 'O' && A[2][0] == ' ') R = 7;
        else if (A[0][2] == 'O' && A[2][0] == 'O' && A[1][1] == ' ') R = 5;
        else if (A[2][0] == 'O' && A[1][1] == 'O' && A[0][2] == ' ') R = 3;

        // In Order To Block Him
        // Checking The Horizontal Rows .
        else if (A[0][1] == 'X' && A[0][2] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[0][2] == 'X' && A[0][1] == ' ') R = 2;
        else if (A[0][0] == 'X' && A[0][1] == 'X' && A[0][2] == ' ') R = 3;
        else if (A[1][1] == 'X' && A[1][2] == 'X' && A[1][0] == ' ') R = 4;
        else if (A[1][0] == 'X' && A[1][2] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[1][0] == 'X' && A[1][1] == 'X' && A[1][2] == ' ') R = 6;
        else if (A[2][1] == 'X' && A[2][2] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[2][0] == 'X' && A[2][2] == 'X' && A[2][1] == ' ') R = 8;
        else if (A[2][0] == 'X' && A[2][1] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Vertical columns .
        else if (A[1][0] == 'X' && A[2][0] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[2][0] == 'X' && A[1][0] == ' ') R = 4;
        else if (A[0][0] == 'X' && A[1][0] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[1][1] == 'X' && A[2][1] == 'X' && A[0][1] == ' ') R = 2;
        else if (A[0][1] == 'X' && A[2][1] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[0][1] == 'X' && A[1][1] == 'X' && A[2][1] == ' ') R = 8;
        else if (A[1][2] == 'X' && A[2][2] == 'X' && A[0][2] == ' ') R = 3;
        else if (A[0][2] == 'X' && A[2][2] == 'X' && A[1][2] == ' ') R = 6;
        else if (A[0][2] == 'X' && A[1][2] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Main Diagonal .
        else if (A[1][1] == 'X' && A[2][2] == 'X' && A[0][0] == ' ') R = 1;
        else if (A[0][0] == 'X' && A[2][2] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[0][0] == 'X' && A[1][1] == 'X' && A[2][2] == ' ') R = 9;
        // Checking The Secondary Diagonal .
        else if (A[0][2] == 'X' && A[1][1] == 'X' && A[2][0] == ' ') R = 7;
        else if (A[0][2] == 'X' && A[2][0] == 'X' && A[1][1] == ' ') R = 5;
        else if (A[2][0] == 'X' && A[1][1] == 'X' && A[0][2] == ' ') R = 3;
        else R = rand() % (9) + 1;
    }
    choice = R + 48;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((A[i][j] == 'X' || A[i][j] == 'O') && arr[i][j] == choice) Flag = 1;
            else if (arr[i][j] == choice) A[i][j] = player;
        }
    }
    if (player == 'X') player = 'O';
    else player = 'X';
}
void computer_Turn_E() {
    char choice;
    if (turns % 2 == 0) { cout << "\n *  Choose your position (( player X )) :  "; cin >> R; while ((!(R >= 1 && R <= 9))) { cout << "\n\tPlease Enter a valid Position : "; cin >> R; } }
    else R = (rand() % (9) + 1);// to prevent that it will be zero
    choice = R + 48;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((A[i][j] == 'X' || A[i][j] == 'O') && arr[i][j] == choice) Flag = 1;
            else if (arr[i][j] == choice) A[i][j] = player;
        }
    }
    if (player == 'X') player = 'O';
    else player = 'X';
}
void Two_Player_Game(char& p) { ///
    bool i = 1;
    while (p == 'R' || p == 'r') {
        if (i == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    A[i][j] = ' ';
                }
            }
            player = 'X';
        }
        i = 0;
        BuildArr();         ///
        while (Check_Who_Win() == 'P') {
            Choose(); //funtion of playing
            if (Flag) {
                cout << "\n\t\t\t (Invalid Position) Please Select Another Position...\n"; if (player == 'X') player = 'O';
                else player = 'X'; Flag = 0; continue;
            }
            else  BuildArr();/////
        }
        BuildArr();// To clear The Screen And See The Last Matrix
        switch (Check_Who_Win()) {

        case 'X': {
            cout << "\n\t\t... *** Player X Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songw.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'O': {
            cout << "\n\t\t... *** Player O Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songw.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'E': {
            cout << "\n\t\t... !! NO ONE HAS WIN !! ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            cin >> p; i = 1;
        }break;
        }
        // if(p=='r'||p=='R')
            //PlaySound(TEXT("background.wav"),NULL,SND_ASYNC);
    }
    if (p == 'E' || p == 'e') exit(0);
    if (p == 'M' || p == 'm') return;
}
void One_Player_Game_Easy(char& p) {
    bool i = 1;
    while (p == 'R' || p == 'r') {
        if (i == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    A[i][j] = ' ';
                }
            }
            player = 'X'; turns = 0;
        }
        i = 0;
        BuildArr();
        while (Check_Who_Win() == 'P') {
            computer_Turn_E();
            turns++;
            if (Flag) {
                cout << "\n\t\t\t (Invalid Position) Please Select Another Position...\n"; if (player == 'X') player = 'O';
                else player = 'X'; Flag = 0; turns--; continue;
            }
            else  BuildArr();
        }
        BuildArr();// To clear The Screen And See The Last Matrix
        switch (Check_Who_Win()) {

        case 'X': {
            cout << "\n\t\t... *** Player X Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songw.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'O': {
            cout << "\n\t\t... *** The Computer Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songL.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'E': {
            cout << "\n\t\t... !! NO ONE HAS WIN !! ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            cin >> p; i = 1;
        }break;
        }
        //  if(p=='r'||p=='R')
         //	PlaySound(TEXT("background.wav"),NULL,SND_ASYNC);
    }
    if (p == 'E' || p == 'e') exit(0);
    if (p == 'M' || p == 'm') return;
}
void One_Player_Game_Medium(char& p) {
    bool i = 1;
    while (p == 'R' || p == 'r') {
        if (i == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    A[i][j] = ' ';
                }
            }
            player = 'X'; turns = 0;
        }
        i = 0;
        BuildArr();
        while (Check_Who_Win() == 'P') {
            computer_Turn_M();
            turns++;
            if (Flag) {
                cout << "\n\t\t\t (Invalid Position) Please Select Another Position...\n"; if (player == 'X') player = 'O';
                else  player = 'X'; Flag = 0; turns--; continue;
            }
            else  BuildArr();
        }
        BuildArr();// To clear The Screen And See The Last Matrix
        switch (Check_Who_Win()) {

        case 'X': {
            cout << "\n\t\t... *** Player X Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songw.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'O': {
            cout << "\n\t\t... *** The Computer Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songL.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'E': {
            cout << "\n\t\t... !! NO ONE HAS WIN !! ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            cin >> p; i = 1;
        }break;
        }
        //  if(p=='r'||p=='R')
          //	PlaySound(TEXT("background.wav"),NULL,SND_ASYNC);
    }
    if (p == 'E' || p == 'e') exit(0);
    if (p == 'M' || p == 'm') return;
}
void One_Player_Game_Hard(char& p) {
    bool i = 1;
    while (p == 'R' || p == 'r') {
        if (i == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    A[i][j] = ' ';
                }
            }
            player = 'X'; turns = 0;
        }
        i = 0;
        BuildArr();
        while (Check_Who_Win() == 'P') {
            computer_Turn_H();
            turns++;
            if (Flag) {
                cout << "\n\t\t\t (Invalid Position) Please Select Another Position...\n"; if (player == 'X') player = 'O';
                else player = 'X'; Flag = 0; turns--; continue;
            }
            else  BuildArr();
        }
        BuildArr();// To clear The Screen And See The Last Matrix
        switch (Check_Who_Win()) {

        case 'X': {
            cout << "\n\t\t... *** Player X Is The Winner *** ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songw.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'O': {
            cout << "\n\t\t... *** The Computer Is The Winner ***...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            //PlaySound(TEXT("songL.wav"),NULL,SND_ASYNC);
            cin >> p; i = 1;
        }break;

        case 'E': {
            cout << "\n\t\t... !! NO ONE HAS WIN !! ...\n\a\n\t IF YOU WANT TO RESTART (Press R)\n\t IF YOU WANT TO ENDGAME (Press E) \n\t IF YOU WANT TO GOBACK TO MAIN (Press M) \n\t ";
            cin >> p; i = 1;
        } break;
        }
        /// if(p=='r'||p=='R')
            //PlaySound(TEXT("background.wav"),NULL,SND_ASYNC);
    }
    if (p == 'E' || p == 'e') exit(0);
    if (p == 'M' || p == 'm') return;
}

