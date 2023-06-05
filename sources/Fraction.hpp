#pragma once 

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <limits>


namespace ariel{
    class Fraction{

        private:
            int numerator; 
            int denominator; 
            
        public:
            
                    
            //----------------------------------------
            // constructors
            //----------------------------------------
            Fraction(int numerator, const int denominator):numerator(numerator), denominator(denominator){
                
                // check denominater != 0 
                if(denominator == 0){
                    throw std::invalid_argument("invalid dinominator!");         
                }

                // reduct the fraction 
                this->reduct_frac(); 
            }
    

            Fraction(float num){

                // check num != 0 
                if(num==0){
                    throw std::invalid_argument("invalid number!");         
                }

                // this part converts the float to a fraction. 
                // numerator = num * 1000
                // denominater = 1000 
                // reduct
                const float precision = 1000.0; // 3 digits after the decimal point
                // we use the sign and abs to save that the numerator will get the negitive value if there is. 
                float sign = num < 0 ? -1.0 : 1.0;
                num = std::abs(num);
                // cast to int. 
                this->numerator = static_cast<int>(std::round(num * precision * sign));
                this->denominator = static_cast<int>(precision);  

                this->reduct_frac();                 
            }  
            // defalt constructor. 
            Fraction(): numerator(1), denominator(1){}


            // copy constructor
            Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

            // assignment constructor
            Fraction& operator=(const Fraction& other) {
                if (this != &other) {
                    numerator = other.numerator;
                    denominator = other.denominator;
                }
                return *this;
            }


            //----------------------------------------
            // get's and set's
            //----------------------------------------
            int getNumerator();
            int getDenominator();
            void setNumerator(int); 
            void setDenominator(int); 


            //----------------------------------------
            // reduction of fraction 
            //----------------------------------------

            void reduct_frac();


            //----------------------------------------
            // binary operators
            //----------------------------------------

            // Fraction to fraction 
            Fraction operator+(const Fraction&); 
            Fraction operator-(const Fraction&); 
            Fraction operator/(const Fraction&);
            Fraction operator*(const Fraction&); 
            
            // Fraction to float  (const in difinsion (due to tidy))
            Fraction operator+(float);
            Fraction operator-(float); 
            Fraction operator/(float);
            Fraction operator*(float);


            // float to fraction 
            friend Fraction operator+(float, const Fraction&);
            friend Fraction operator-(float, const Fraction&);
            friend Fraction operator/(float, const Fraction&);
            friend Fraction operator*(float, const Fraction&);
            
         

            //--------------------------------------
            // Increment 
            //--------------------------------------

            // prefix 
            Fraction& operator++(); 
            Fraction& operator--(); 


            // postfix
            Fraction operator++(int); 
            Fraction operator--(int); 


            //----------------------------------------
            // Comparison operators
            //----------------------------------------
            
            // fraction to fraction 
            friend bool operator==(const Fraction&, const Fraction&);
            friend bool operator>(const Fraction&, const Fraction&);
            friend bool operator>=(const Fraction&, const Fraction&);
            friend bool operator<(const Fraction&, const Fraction&);
            friend bool operator<=(const Fraction&, const Fraction&);

            // float to fraction
            friend bool operator==(float, const Fraction&);
            friend bool operator>(float, const Fraction&);
            friend bool operator>=(float, const Fraction&);
            friend bool operator<(float, const Fraction&);
            friend bool operator<=(float, const Fraction&);

            // fraction to float 
            friend bool operator==(const Fraction&, float);
            friend bool operator>(const Fraction&, float);
            friend bool operator>=(const Fraction&, float);
            friend bool operator<(const Fraction&, float);
            friend bool operator<=(const Fraction&, float);


            
            //----------------------------------
            // IO operators
            //----------------------------------

            // output  
            friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);

            // input 
            friend std::istream& operator>> (std::istream&, Fraction&);
            //-------------------------------------

    

    };
    
    int _gcd(int, int); 
    Fraction float_to_fraction(float);

}