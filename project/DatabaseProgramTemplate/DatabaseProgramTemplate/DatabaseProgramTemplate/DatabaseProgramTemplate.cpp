																				 #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <string>
#include "colors.h"
#include "auth.h"

using namespace std;

// Структура книги
struct Book {
    int id;
    char title[31];      // 30 символов + '\0'
    char author[31];
    int pages;
    char genre[31];
    char publisher[31];
    Book* next;          // указатель на следующую книгу
};

Book* head = nullptr;    // голова связного списка

// Функция добавления книги
void AddData() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tДобавление новой книги:\n\n";

    Book* newBook = new Book;
    cout << "\tВведите уникальный ID книги: ";
    cin >> newBook->id;
    cin.ignore();

    cout << "\tНазвание книги (до 30 символов): ";
    cin.getline(newBook->title, 31);

    cout << "\tФИО автора (до 30 символов): ";
    cin.getline(newBook->author, 31);

    cout << "\tКоличество страниц: ";
    cin >> newBook->pages;
    cin.ignore();

    cout << "\tЖанр (до 30 символов): ";
    cin.getline(newBook->genre, 31);

    cout << "\tИздательство (до 30 символов): ";
    cin.getline(newBook->publisher, 31);

    newBook->next = nullptr;

    if (head == nullptr) {
        head = newBook;
    }
    else {
        Book* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    setTextColor(GREEN);
    cout << "\n\tКнига успешно добавлена!\n";
    _getch();
}

// Функция вывода всех книг
void PrintData() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tСписок всех книг:\n\n";

    if (head == nullptr) {
        cout << "\tБиблиотека пуста.\n";
    }
    else {
        Book* current = head;
        int count = 1;
        while (current != nullptr) {
            cout << "\t" << count << ". ID: " << current->id
                << " | Название: " << current->title
                << " | Автор: " << current->author
                << " | Страниц: " << current->pages
                << " | Жанр: " << current->genre
                << " | Издательство: " << current->publisher << endl;
            current = current->next;
            count++;
        }
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция поиска по автору
void SearchByAuthor() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tПоиск книг по фамилии автора:\n\n";
    char searchAuthor[31];
    cout << "\tВведите фамилию автора: ";
    cin.getline(searchAuthor, 31);

    bool found = false;
    Book* current = head;
    int count = 1;

    while (current != nullptr) {
        if (strstr(current->author, searchAuthor) != nullptr) {
            if (!found) {
                cout << "\n\tНайдены книги:\n";
                found = true;
            }
            cout << "\t" << count << ". ID: " << current->id
                << " | Название: " << current->title
                << " | Автор: " << current->author
                << " | Страниц: " << current->pages
                << " | Жанр: " << current->genre
                << " | Издательство: " << current->publisher << endl;
            count++;
        }
        current = current->next;
    }

    if (!found) {
        setTextColor(RED);
        cout << "\tКниги этого автора не найдены.\n";
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция поиска по названию
void SearchByTitle() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tПоиск книг по названию:\n\n";
    char searchTitle[31];
    cout << "\tВведите название книги: ";
    cin.getline(searchTitle, 31);

    bool found = false;
    Book* current = head;
    int count = 1;

    while (current != nullptr) {
        if (strstr(current->title, searchTitle) != nullptr) {
            if (!found) {
                cout << "\n\tНайдены книги:\n";
                found = true;
            }
            cout << "\t" << count << ". ID: " << current->id
                << " | Название: " << current->title
                << " | Автор: " << current->author
                << " | Страниц: " << current->pages
                << " | Жанр: " << current->genre
                << " | Издательство: " << current->publisher << endl;
            count++;
        }
        current = current->next;
    }

    if (!found) {
        setTextColor(RED);
        cout << "\tКниги с таким названием не найдены.\n";
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция поиска по жанру
void SearchByGenre() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tПоиск книг по жанру:\n\n";
    char searchGenre[31];
    cout << "\tВведите жанр: ";
    cin.getline(searchGenre, 31);

    bool found = false;
    Book* current = head;
    int count = 1;

    while (current != nullptr) {
        if (strstr(current->genre, searchGenre) != nullptr) {
            if (!found) {
                cout << "\n\tНайдены книги:\n";
                found = true;
            }
            cout << "\t" << count << ". ID: " << current->id
                << " | Название: " << current->title
                << " | Автор: " << current->author
                << " | Страниц: " << current->pages
                << " | Жанр: " << current->genre
                << " | Издательство: " << current->publisher << endl;
            count++;
        }
        current = current->next;
    }

    if (!found) {
        setTextColor(RED);
        cout << "\tКниги такого жанра не найдены.\n";
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция поиска по номеру (ID)
void SearchByID() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tПоиск книги по номеру (ID):\n\n";
    int searchID;
    cout << "\tВведите ID книги: ";
    cin >> searchID;

    Book* current = head;
    while (current != nullptr) {
        if (current->id == searchID) {
            cout << "\n\tНайдена книга:\n";
            cout << "\tID: " << current->id
                << " | Название: " << current->title
                << " | Автор: " << current->author
                << " | Страниц: " << current->pages
                << " | Жанр: " << current->genre
                << " | Издательство: " << current->publisher << endl;
            cout << "\n\tНажмите любую клавишу...";
            _getch();
            return;
        }
        current = current->next;
    }

    setTextColor(RED);
    cout << "\tКнига с таким ID не найдена.\n";
    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция удаления книги по ID
void DeleteData() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tУдаление книги по ID:\n\n";
    int idToDelete;
    cout << "\tВведите ID книги для удаления: ";
    cin >> idToDelete;

    Book* current = head;
    Book* prev = nullptr;

    while (current != nullptr && current->id != idToDelete) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        setTextColor(RED);
        cout << "\tКнига с таким ID не найдена.\n";
    }
    else {
        if (prev == nullptr) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }
        delete current;
        setTextColor(GREEN);
        cout << "\tКнига успешно удалена!\n";
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Функция редактирования
void EditData() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tРедактирование книги по ID:\n\n";
    int idToEdit;
    cout << "\tВведите ID книги для редактирования: ";
    cin >> idToEdit;
    cin.ignore();

    Book* current = head;
    while (current != nullptr && current->id != idToEdit) {
        current = current->next;
    }

    if (current == nullptr) {
        setTextColor(RED);
        cout << "\tКнига с таким ID не найдена.\n";
    }
    else {
        cout << "\n\tТекущие данные:\n";
        cout << "\tID: " << current->id << endl;
        cout << "\tНазвание: " << current->title << endl;
        cout << "\tАвтор: " << current->author << endl;
        cout << "\tСтраниц: " << current->pages << endl;
        cout << "\tЖанр: " << current->genre << endl;
        cout << "\tИздательство: " << current->publisher << endl;

        cout << "\n\tВведите новые данные (оставьте пустым, чтобы не менять):\n";

        char input[31];
        cout << "\tНовое название: ";
        cin.getline(input, 31);
        if (strlen(input) > 0) strcpy(current->title, input);

        cout << "\tНовый автор: ";
        cin.getline(input, 31);
        if (strlen(input) > 0) strcpy(current->author, input);

        cout << "\tНовое количество страниц: ";
        cin >> current->pages;
        cin.ignore();

        cout << "\tНовый жанр: ";
        cin.getline(input, 31);
        if (strlen(input) > 0) strcpy(current->genre, input);

        cout << "\tНовое издательство: ";
        cin.getline(input, 31);
        if (strlen(input) > 0) strcpy(current->publisher, input);

        setTextColor(GREEN);
        cout << "\n\tДанные обновлены!\n";
    }

    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Сохранение в текстовый файл
bool SaveData() {
    ofstream file("library.txt");
    if (!file.is_open()) {
        return false;
    }

    Book* current = head;
    while (current != nullptr) {
        file << current->id << ";"
            << current->title << ";"
            << current->author << ";"
            << current->pages << ";"
            << current->genre << ";"
            << current->publisher << endl;
        current = current->next;
    }

    file.close();
    return true;
}

// Загрузка из текстового файла
bool LoadData() {
    ifstream file("library.txt");
    if (!file.is_open()) {
        return true;
    }

    string line;
    while (getline(file, line)) {
        Book* newBook = new Book;
        char delimiter = ';';
        size_t pos = 0;
        string token;

        pos = line.find(delimiter);
        newBook->id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(delimiter);
        strncpy(newBook->title, line.substr(0, pos).c_str(), 30);
        newBook->title[30] = '\0';
        line.erase(0, pos + 1);

        pos = line.find(delimiter);
        strncpy(newBook->author, line.substr(0, pos).c_str(), 30);
        newBook->author[30] = '\0';
        line.erase(0, pos + 1);

        pos = line.find(delimiter);
        newBook->pages = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(delimiter);
        strncpy(newBook->genre, line.substr(0, pos).c_str(), 30);
        newBook->genre[30] = '\0';
        line.erase(0, pos + 1);

        strncpy(newBook->publisher, line.c_str(), 30);
        newBook->publisher[30] = '\0';

        newBook->next = nullptr;

        if (head == nullptr) {
            head = newBook;
        }
        else {
            Book* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }

    file.close();
    return true;
}

// Справка
void PrintHelp() {
    system("cls");
    setTextColor(LIGHT_BLUE);
    cout << "\n\n\t\tСПРАВКА ПО ПРОГРАММЕ\n\n";
    cout << "\tПрограмма предназначена для учёта книг в библиотеке УДГУ.\n";
    cout << "\tВы можете добавлять, редактировать, удалять и искать книги.\n";
    cout << "\tВсе изменения сохраняются в файле 'library.txt'.\n";
    cout << "\tПри первом запуске файл будет создан автоматически.\n\n";
    cout << "\tДля выхода выберите пункт 9 в меню.\n";
    cout << "\n\tНажмите любую клавишу...";
    _getch();
}

// Главное меню
char MainMenu() {
    while (true) {
        system("cls");
        
        int consoleWidth, consoleHeight;
        getConsoleSize(consoleWidth, consoleHeight);
        
        setTextColor(LIGHT_BLUE);
        
        cout << "\n\n";
        string title = "УЧЁТ КНИГ В БИБЛИОТЕКЕ УДГУ";
        cout << string((consoleWidth - title.length()) / 2, ' ') << title << "\n\n";
        
        string menuTitle = "МЕНЮ";
        cout << string((consoleWidth - menuTitle.length()) / 2, ' ') << menuTitle << "\n\n";
        
        string menu[] = {
            "1. Добавить книгу",
            "2. Вывод списка книг",
            "3. Поиск книги по номеру",
            "4. Поиск книги по фамилии автора",
            "5. Поиск книги по названию",
            "6. Поиск книг по жанру",
            "7. Удалить книгу по номеру",
            "8. Редактировать книгу",
            "9. Выход"
        };
        
        for (int i = 0; i < 9; i++) {
            cout << string((consoleWidth - 30) / 2, ' ');
            
            if (i == 8) {
                setTextColor(RED);
                cout << menu[i] << endl;
                setTextColor(LIGHT_BLUE);
            } else {
                cout << menu[i] << endl;
            }
        }
        
        cout << "\n" << string((consoleWidth - 40) / 2, ' ');
        cout << "Для выбора пункта меню нажмите клавишу\n";
        cout << string((consoleWidth - 40) / 2, ' ');
        cout << "с номером нужного действия\n\n";
        cout << string((consoleWidth - 20) / 2, ' ');
        cout << "Ваш выбор > ";

        char choice = _getch();
        if (choice < '1' || choice > '9') {
            setTextColor(RED);
            cout << "\n" << string((consoleWidth - 40) / 2, ' ');
            cout << "Такого варианта не существует!";
            _getch();
        }
        else {
            return choice;
        }
    }
}

// Обработка событий
void HandleEvents() {
    char choice = 0;
    while (choice != '9') {
        choice = MainMenu();
        switch (choice) {
        case '1': AddData(); break;
        case '2': PrintData(); break;
        case '3': SearchByID(); break;
        case '4': SearchByAuthor(); break;
        case '5': SearchByTitle(); break;
        case '6': SearchByGenre(); break;
        case '7': DeleteData(); break;
        case '8': EditData(); break;
        case '9': return;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    
    // Установка размера окна
    HWND console = GetConsoleWindow();
    MoveWindow(console, 200, 100, 800, 500, TRUE);
    
    // Авторизация
    if (!Authorize()) {
        setTextColor(RED);
        cout << "\n\n\tДоступ запрещён.\n";
        _getch();
        return 1;
    }
    
    // Загрузка данных
    if (!LoadData()) {
        setTextColor(RED);
        cout << "\n\tОшибка загрузки базы данных.\n";
        _getch();
        return 1;
    }
    
    // Главный цикл
    HandleEvents();
    
    // Сохранение при выходе
    SaveData();
    
    // Освобождение памяти
    Book* current = head;
    while (current != nullptr) {
        Book* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}