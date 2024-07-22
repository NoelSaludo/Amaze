#include <iostream>
#include "global.h"
using namespace std;

void drawHorizontalLine(int width) {
    cout << "+";
    for (int i = 0; i < width - 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;
}

void drawMenuOption(string option) {
    cout << "| " << option;
    for (int i = option.length() + 3; i < 30; ++i) {
        cout << " ";
    }
    cout << "|" << endl;
}

void drawMenuHeader(string header) {
    int length = header.length() + 2;
    drawHorizontalLine(length);
    cout << "| " << header << " |" << endl;
    drawHorizontalLine(length);
}

void drawMenuFooter() {
    drawHorizontalLine(30);
}