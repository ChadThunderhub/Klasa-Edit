#pragma once
#ifndef _EDIT_HPP_
#define _EDIT_HPP_

#include <string>

class Edit {
public:
    enum Color {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Yellow = 6,
        White = 7,
    };

    Edit();
    Edit(const Edit& other);
    ~Edit();

    void draw() const;

    void setPosition(int x, int y);
    void setLength(int length);
    void setText(const std::string& text);
    void setTextColor(Color textColor);
    void setBackgroundColor(Color backgroundColor);
    std::string getText() const;
    void userText();

private:
    int xPos;
    int yPos;
    int length;
    std::string text;
    Color textColor;
    Color backgroundColor;
};

#endif // _EDIT_HPP_