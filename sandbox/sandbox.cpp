#include <iostream>
#include "cell/Grid.hpp"
#include "amaze/BinaryTree.hpp"
#include "amaze/AldousBroder.hpp"
#include "GridConverter.hpp"
#include "Rooms.hpp"

int main() {
    cell::Grid<15, 15> aldousGrid;
    auto rooms = Rooms::generateWithinArea(15, 15, 20);
    for (auto & room : rooms) {
        room.cut(aldousGrid);
        room.fill(aldousGrid);
    }
    
    AldousBroder::link(aldousGrid);
    std::cout << GridConverter::gridToString(aldousGrid);

    cell::Grid<10, 10> binaryGrid;
    BinaryTree::link(binaryGrid);
    std::cout << GridConverter::gridToString(binaryGrid);
    
    return 0;
}
