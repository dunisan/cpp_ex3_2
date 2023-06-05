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

    SUBCASE("Fractino to binary"){
        Fraction a(13,24);
        Fraction b(1,2); 

        CHECK(a>0.25); 
        CHECK(b>=0.5); 
        CHECK(a<0.75);
        CHECK(b<=0.5); 
    }

    SUBCASE("binary to fraction"){
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

    SUBCASE("Fraction to fraction"){
        Fraction a(2,2); 
        Fraction b(1,2);

        CHECK((a+b)==1.5); 
        CHECK((a-b)==0.5); 
        CHECK((a/b)==2); 
        CHECK((a*b)==0.5); 
    }

    SUBCASE("Fraction to binary"){
        Fraction c(10,2); 
        float num = 2.2;

        CHECK((c+num)==7.2); 
        CHECK((c-num)==2.8); 
    }   

    SUBCASE("binary to fraction"){
        Fraction d(7,8); 
        float num = 2.2;

        CHECK((num+d)==3.075); 

    }  
}



TEST_CASE("Increment & decrement"){
    SUBCASE("Increment"){
        Fraction a(10,2); 
    }

    SUBCASE("Decrement"){
        Fraction a(10,2); 

    
    }
}


TEST_CASE("I/O"){

    // SUBCASE("input"){

    //     Fraction a(1,10); 
    //     std::stringstream input("5,10\n");
    //     input >> a; 
    //     CHECK(a == 0.5); 
    // }

    // SUBCASE("Output"){

    //     Fraction a(1,10); 
    //     std::stringstream output; 
    //     output << a; 
    // }
}


