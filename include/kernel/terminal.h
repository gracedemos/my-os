#ifndef LIBCPP
    #include <libcpp/libcpp.h>
#endif

enum VGAColor {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GREY,
    VGA_COLOR_DARK_GREY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_LIGHT_BROWN,
    VGA_COLOR_WHITE
};

class Terminal {
    public:
    Terminal();
    void writeString(const char* str);
    void clear();

    private:
    size_t VGA_WIDTH;
    size_t VGA_HEIGHT;

    size_t terminalRow;
    size_t terminalColumn;
    uint8_t terminalColor;
    uint16_t* terminalBuffer;

    void initialize();
    inline uint8_t vgaEntryColor(VGAColor fg, VGAColor bg);
    inline uint16_t vgaEntry(uint8_t character, uint8_t color);
    void putEntryAt(char c, uint8_t color, size_t x, size_t y);
};