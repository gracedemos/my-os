#include <kernel/terminal.h>

Terminal::Terminal() {
    VGA_WIDTH = 80;
    VGA_HEIGHT = 25;
    initialize();
}

inline uint8_t Terminal::vgaEntryColor(VGAColor fg, VGAColor bg) {
    return fg | bg << 4;
}

inline uint16_t Terminal::vgaEntry(uint8_t character, uint8_t color) {
    return (uint16_t)character | (uint16_t)color << 8;
}

void Terminal::putEntryAt(char c, uint8_t color, size_t x, size_t y) {
    size_t index = y * VGA_WIDTH + x;
    terminalBuffer[index] = vgaEntry(c, color);
}

void Terminal::writeString(const char* str) {
    for(size_t i = 0; i < strlen(str); i++) {
        if(str[i] == '\n') {
            terminalRow++;
            terminalColumn = 0;
        }else {
            putEntryAt(str[i], terminalColor, terminalColumn, terminalRow);
            if(terminalColumn + 1 == VGA_WIDTH) {
                terminalColumn = 0;
                terminalRow++;
            }else {
                terminalColumn++;
            }
        }
    }
}

void Terminal::initialize() {
    terminalRow = 0;
    terminalColumn = 0;
    terminalColor = vgaEntryColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    terminalBuffer = (uint16_t*)0xB8000;
    clear();
}

void Terminal::clear() {
    for(size_t i = 0; i < VGA_HEIGHT; i++) {
        for(size_t j = 0; j < VGA_WIDTH; j++) {
            size_t index = i * VGA_WIDTH + j;
            terminalBuffer[index] = vgaEntry(' ', terminalColor);
        }
    }
}