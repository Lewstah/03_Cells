#pragma once

#include <array>
#include <ostream>
#include "Cell.h"
#include <string>

// Forward Declarations (Necessary for friends of template class)
template<std::size_t COLS, std::size_t ROWS> class Grid;
template<std::size_t COLS, std::size_t ROWS> std::ostream& operator<<(std::ostream& output, const Grid<COLS, ROWS>& g);

// Class Definition
template<std::size_t COLS, std::size_t ROWS>
class Grid
{
	// overload for writing Grid to screen (Ignore Visual Studio's Warning)
	friend std::ostream& operator<< <>(std::ostream& output, const Grid<COLS, ROWS>& g);
	
	std::array<std::array<Cell, COLS>, ROWS> grid;
	std::array<std::array<Cell, COLS>, ROWS> prepareGrid(std::array<std::array<Cell, COLS>, ROWS>& g);

	// TODO make a function that returns correct grid character ('~' or '#') based on ship.show (bool)

public:
	Grid();
};


template<std::size_t COLS, std::size_t ROWS>
Grid<COLS, ROWS>::Grid()
{
	prepareGrid(grid);
}

template<std::size_t COLS, std::size_t ROWS>
std::array<std::array<Cell, COLS>, ROWS> Grid<COLS, ROWS>::prepareGrid(std::array<std::array<Cell, COLS>, ROWS>& g)
{
	for (auto i = g.begin(); i != g.end(); ++i)
		for (auto j = i->begin(); j != i->end(); ++j)
			*j = Cell();

	return g;
}

template<std::size_t COLS, std::size_t ROWS>
std::ostream& operator<<(std::ostream& output, const Grid<COLS, ROWS>& g)
{
	// write object to stream

	// top border
	output << "+";
	for (auto i = g.grid[0].begin(); i != g.grid[0].end(); ++i) output << "---+";
	output << "\n";

	for (int row = 0; row != g.grid.size(); ++row) {  // for each row...

		std::string mid = "|";
		std::string bottom = "+";

		for (int col = 0; col != g.grid[row].size(); ++col) {  // for each column in row...

			std::string body = "   ";

			std::string corner = "+";

			std::string east_boundary;

			bool isEast = (col != g.grid[row].size() - 1 && g.grid[row][col].isLinked(g.grid[row][col + 1]));

			east_boundary = (isEast ? " " : "|");


			// Concatenate body and east_boundary to the top
			mid += body + east_boundary;

			std::string south_boundary;

			bool isSouth = (row != g.grid.size() - 1 && g.grid[row][col].isLinked(g.grid[row + 1][col]));

			south_boundary = isSouth ? "   " : "---"; // three spaces "   " : "---"

													  // Concatenate south_boundary and corner to the bottom
			bottom += south_boundary + corner;

		}

		output << mid << "\n";
		output << bottom << "\n";
	}

	return output;
}

// TODO implement either index based loops in grid or implement neighbors