#include <cxxtest/TestSuite.h>
#include "Neighbors.hpp"
#include <stdexcept>

class TestNeighbors: public CxxTest::TestSuite {
    struct MockNeighbor {};
    Neighbors<MockNeighbor> neighbors;

    MockNeighbor expectedNeighbor;

public: 
    void test_detachEastWithoutSettingEast_nothingChanges() {
        neighbors.detach(expectedNeighbor);

        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_detachEastAfterSettingEast_eastIsNull() {
        neighbors.setEast(expectedNeighbor);
        neighbors.detach(expectedNeighbor);

        MockNeighbor * expected = nullptr;
        MockNeighbor * actual = neighbors.getEast();

        TS_ASSERT_EQUALS(expected, actual);
    }

    void test_setOneDirection_sizeOfAllNeighborsIsOne() {
        neighbors.setEast(expectedNeighbor);

        auto expectedSize = 1;
        auto actualSize = neighbors.all.size();

        TS_ASSERT_EQUALS(expectedSize, actualSize);
    }
    
    void test_doNotSetEast_eastIsNull() {
        MockNeighbor const * const actualNeighborAddress = neighbors.getEast();
        
        TS_ASSERT_EQUALS(nullptr, actualNeighborAddress);
    }

    void test_setEast_getEast() {
        neighbors.setEast(expectedNeighbor);
        MockNeighbor const * const actualNeighborAddress = neighbors.getEast();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actualNeighborAddress);
    }

    void test_setWest_getWest() {
        neighbors.setWest(expectedNeighbor);
        MockNeighbor const * const actualNeighborAddress = neighbors.getWest();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actualNeighborAddress);
    }

    void test_setNorth_getNorth() {
        neighbors.setNorth(expectedNeighbor);
        MockNeighbor const * const actualNeighborAddress = neighbors.getNorth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actualNeighborAddress);
    }

    void test_setSouth_getSouth() {
        neighbors.setSouth(expectedNeighbor);
        MockNeighbor const * const actualNeighborAddress = neighbors.getSouth();
        
        TS_ASSERT_EQUALS(&expectedNeighbor, actualNeighborAddress);
    }

    void tearDown() {
        neighbors = Neighbors<MockNeighbor>();
    }
};