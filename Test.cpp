#include <iostream>
#include <stdexcept>
#include <string>
#include "doctest.h"
#include <sstream>

#include "sources/Fraction.hpp"

using namespace ariel;



TEST_CASE("initialization"){
    CHECK_THROWS(Fraction(10,0)); 
    CHECK_NOTHROW(Fraction(1,2)); 

    SUBCASE("reduction"){
        Fraction a(10,15); 
        Fraction b(3,5); 

        CHECK(a.getNumerator() == 2);
        CHECK(a.getDenominator() == 3); 
        CHECK(b.getNumerator() == 3);
        CHECK(b.getDenominator() == 5); 
    }
}

TEST_CASE("constructers"){

    SUBCASE("Default constructor") {
        Fraction a;
        
        CHECK(a.getNumerator() == 1);
        CHECK(a.getDenominator() == 1);
    }

    SUBCASE("Floating-point constructor") {
    Fraction a(0.75);
    
    CHECK(a.getNumerator() == 3);
    CHECK(a.getDenominator() == 4);
}

    SUBCASE("Copy constructor") {
        Fraction a(7, 9);
        Fraction b(a);
        
        CHECK(b.getNumerator() == 7);
        CHECK(b.getDenominator() == 9);
        CHECK(b == a);
    }

    SUBCASE("Assignment constructor") {
        Fraction a(5, 6);
        Fraction b = a;
        
        CHECK(b.getNumerator() == 5);
        CHECK(b.getDenominator() == 6);
        CHECK(b == a);
    }
}


TEST_CASE("Camprison operation"){

    SUBCASE("Fractoion to fraction"){
        Fraction a(13,14);
        Fraction b(14,15); 
        Fraction c(15,30);
        Fraction d(1,2); 

        CHECK(b>a); 
        CHECK(c>=d); 
        CHECK(a<b);
        CHECK(d<=b); 
        CHECK(c==d); 
    }

    SUBCASE("Fractino to float"){
        Fraction a(13,24);
        Fraction b(1,2); 

        CHECK(a>0.25); 
        CHECK(b>=0.5); 
        CHECK(a<0.75);
        CHECK(b<=0.5); 
    }

    SUBCASE("float to fraction"){
        Fraction a(10,100);
        Fraction b(1,1); 
        
        CHECK(0.2>a); 
        CHECK(1>=b); 
        CHECK(0.01<a);
        CHECK(0.1<=a); 
        CHECK(1==b);

    }
}

TEST_CASE("Arithmetic operations"){

    SUBCASE("Fraction to fraction") {
        Fraction a(2, 2);
        Fraction b(1, 2);

        CHECK((a + b) == Fraction(3, 2));
        CHECK((a - b) == Fraction(1, 2));
        CHECK((a / b) == Fraction(2, 1));
        CHECK((a * b) == Fraction(1, 2));
    }

    SUBCASE("Fraction to binary") {
        Fraction c(10, 2);
        float num = 2.2;

        CHECK((c + num) == Fraction(36, 5));
        CHECK((c - num) == Fraction(14, 5));
        CHECK((c / num) == Fraction(25, 11));
        CHECK((c * num) == Fraction(11, 1));
    }

    SUBCASE("Binary to fraction") {
        Fraction d(7, 8);
        float num = 2.2;

        CHECK((num + d) == Fraction(123, 40));
        CHECK((num - d) == Fraction(53, 40));
        CHECK((num / d) == Fraction(88, 35));
        CHECK((num * d) == Fraction(77, 40));
    }

}


TEST_CASE("Increment & decrement"){
    SUBCASE("Increment") {
        Fraction a(10, 2);
        CHECK(++a == Fraction(6, 1)); // Pre-increment
        CHECK(a++ == Fraction(6, 1)); // Post-increment 
        CHECK(a == Fraction(7, 1));   // After post-increment
    }

    SUBCASE("Decrement") {
        Fraction a(10, 2);

        CHECK(--a == Fraction(4, 1)); // Pre-decrement
        CHECK(a-- == Fraction(4, 1)); // Post-decrement (value before decrement)
        CHECK(a == Fraction(3, 1));   // After post-decrement
    }
}


TEST_CASE("I/O"){
    SUBCASE("Output") {
        Fraction a(3, 4);
        std::stringstream output;
        output << a;
        CHECK(output.str() == "3/4");
    }

    SUBCASE("Input") {
        Fraction a;
        std::stringstream input("5 10");
        input >> a;
        CHECK_EQ(a, Fraction(1,2));

        Fraction b;
        std::stringstream input1("5 0");
        CHECK_THROWS( input1 >> b);

        Fraction c;
        std::stringstream input2("0 1");
        CHECK_NOTHROW( input2 >> c);

    }
}


