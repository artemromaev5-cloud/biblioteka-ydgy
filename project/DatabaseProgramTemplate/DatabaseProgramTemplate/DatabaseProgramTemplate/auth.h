#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <cstring>
#include "colors.h"

using namespace std;

bool Authorize() {
    system("cls");

    int consoleWidth, consoleHeight;
    getConsoleSize(consoleWidth, consoleHeight);

    int startX = (consoleWidth - 40) / 2;
    int startY = (consoleHeight - 8) / 2;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Очистка области
    for (int i = 0; i < 12; i++) {
        gotoxy(0, startY + i);
        cout << string(consoleWidth, ' ');
    }

    setTextColor(LIGHT_BLUE);

    // Верхняя рамка
    gotoxy(startX, startY);
    cout << "+";
    for (int i = 0; i < 38; i++) cout << "-";
    cout << "+";

    // Заголовок
    gotoxy(startX + 13, startY + 1);
    cout << "АВТОРИЗАЦИЯ";

    char login[20], password[20];

    // Логин
    gotoxy(startX + 5, startY + 3);
    cout << "Логин: ";
    gotoxy(startX + 13, startY + 3);
    cin.getline(login, 20);

    // Пароль
    gotoxy(startX + 5, startY + 5);
    cout << "Пароль: ";
    gotoxy(startX + 13, startY + 5);
    cin.getline(password, 20);

    // Нижняя рамка
    gotoxy(startX, startY + 7);
    cout << "+";
    for (int i = 0; i < 38; i++) cout << "-";
    cout << "+";

    // Простейшая проверка
    if (strcmp(login, "admin") == 0 && strcmp(password, "1234") == 0) {
        setTextColor(GREEN);
        gotoxy(startX + 12, startY + 6);
        cout << "Вход выполнен";
        Sleep(1500);
        return true;
    }
    else {
        setTextColor(RED);
        gotoxy(startX + 12, startY + 6);
        cout << "Неверный вход";
        Sleep(1500);
        return false;
    }
}

#endif