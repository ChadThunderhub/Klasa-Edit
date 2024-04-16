#include "edit.hpp"
#include <iostream>
#include <conio.h>
#include <Windows.h>

Edit::Edit() : xPos(0), yPos(0), length(0), text(""), textColor(Black), backgroundColor(White) {}

Edit::Edit(const Edit& other) : xPos(other.xPos), yPos(other.yPos), length(other.length), text(other.text), textColor(other.textColor), backgroundColor(other.backgroundColor) {}

Edit::~Edit() {}

void Edit::setPosition(int x, int y) {
    xPos = x;
    yPos = y;
}

void Edit::setLength(int length) {
    this->length = length;
}

void Edit::setText(const std::string& text) {
    this->text = text;
}

void Edit::setTextColor(Color textColor) {
    this->textColor = textColor;
}

void Edit::setBackgroundColor(Color backgroundColor) {
    this->backgroundColor = backgroundColor;
}

std::string Edit::getText() const {
    return text;
}

void Edit::userText() {
    char ch;
    while (true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') // Enter key
                break;
            else if (ch == '\b') { // Backspace key
                if (!text.empty()) {
                    text.pop_back();
                    std::cout << "\b \b"; // Clear last character on console
                }
            }
            else {
                text += ch;
                std::cout << ch;
            }
        }
    }
}

void setConsoleCursorPosition(int x, int y) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos;
    cursorPos.X = x;
    cursorPos.Y = y;
    SetConsoleCursorPosition(console, cursorPos);
}

void setConsoleTextAttribute(int textColor, int backgroundColor) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = textColor + backgroundColor * 16;
    SetConsoleTextAttribute(console, color);
}

void Edit::draw() const {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(console, &consoleInfo);
    WORD originalColor = consoleInfo.wAttributes;

    COORD cursorPos;
    cursorPos.X = xPos;
    cursorPos.Y = yPos;
    SetConsoleCursorPosition(console, cursorPos);

    SetConsoleTextAttribute(console, textColor | (backgroundColor << 4));

    std::cout << text;
}