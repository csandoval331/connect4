#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "list.cpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Testing main functions of list", "[list]" ) {
    list myList;
    REQUIRE(myList.head == nullptr);
    REQUIRE(myList.tail == nullptr);
    REQUIRE(myList.count == -1);

    SECTION("inserting element"){
        myList.push(true);
        REQUIRE(myList[0] == true);

        myList.push(false);
        REQUIRE(myList[1] == false);

        REQUIRE_THROWS_AS(myList[3], std::out_of_range);
        REQUIRE_THROWS_AS(myList[2], std::out_of_range);

        myList.push(false);
        REQUIRE(myList[2] == false);

        myList.push(true);
        REQUIRE(myList[3] == true);

        REQUIRE_THROWS_AS(myList[4], std::out_of_range);
    }
}

TEST_CASE("Testing rotation of list","[list]"){
    list myList;
    SECTION("Check Rotation"){
        REQUIRE(myList.rotateChar() == false);

        myList.push(true);
        REQUIRE(myList.rotateChar() == true);

        myList.push(false);
        myList.push(false);
        myList.push(true);

        REQUIRE(myList[0] == true);
        REQUIRE(myList[1] == false);

        REQUIRE(myList.rotateChar() == true);

        REQUIRE(myList[0] == false);
        REQUIRE(myList[1] == false);

        REQUIRE(myList.length() == 4);
    }
}