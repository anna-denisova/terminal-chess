
#ifdef _WIN32

#include <windows.h>
#include <cstdint>
#include <string>

bool init_term() {

    auto oh = ::GetStdHandle(STD_OUTPUT_HANDLE);
    if (oh == INVALID_HANDLE_VALUE){
        return false;
    }

    DWORD omode;
    if (!::GetConsoleMode(oh, &omode)){
        return false;
    }

    omode |= 0x0004;
    if (!::SetConsoleMode(oh, omode)){
        return false;
    }

    ::SetConsoleOutputCP(65001);
    ::SetConsoleCP(65001);

    return true;
}

// COLOR RELATED STUFF HERE 
/*
using index = uint8_t;

auto black = index{0};
auto white = index{15};

auto rgb(uint8_t r, uint8_t g, uint8_t b) -> index
{
    auto rr = (r * 3) >> 7;
    auto gg = (g * 3) >> 7;
    auto bb = (b * 3) >> 7;
    
    return rr * 36 + gg * 6 + bb + 16;
}

auto gray(uint8_t l) -> index
{
    auto v = (l * 26) >> 8;
    if (v == 0)
        return black;
    if (v == 25)
        return white;
    return v + 231;
}

//std::string set_fg(index c) { return std::string{"\x1b[38;5;"} + std::to_string(c) + "m"; },
//std::string set_bg(index c) { return std::string{"\x1b[48;5;"} + std::to_string(c) + "m"; },

// other sequences:
//
// sty_reset = "\x1b[0m",
// sty_bold = "\x1b[1m",
// sty_not_bold = "\x1b[22m",
// sty_italic = "\x1b[3m",
// sty_not_italic = "\x1b[23m",
// sty_underline = "\x1b[4m",
// sty_not_underline = "\x1b[24m",
// sty_strikethrough = "\x1b[9m",
// sty_not_strikethrough = "\x1b[9m",
*/

#endif