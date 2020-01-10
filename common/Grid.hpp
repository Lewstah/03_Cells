#ifndef GRID
#define GRID

#include <array>
#include <ostream>
#include <string>

template<typename Element, size_t columns, size_t rows>
class Grid {
    std::array<std::array<Element, columns>, rows> grid;
    
public:
    bool isWithinBounds(size_t x, size_t y) {
        return x < columns and x >= 0 and y < rows and y >= 0;
    }
    
    Element & at(size_t x, size_t y) {
        return grid[y][x];
    }
};

#endif