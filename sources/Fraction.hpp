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
            Fraction(int numerator, int denominator):numerator(numerator), denominator(denominator){

                if(denominator == 0){
                    throw std::invalid_argument("invalid dinominator!");         
                }

                this->reduct_frac(); 
            }


            Fraction(float num){
                if(num==0){
                        throw std::invalid_argument("invalid number!");         
                }

                const float precision = 1000.0; // 3 digits after the decimal point
                float sign = num < 0 ? -1.0 : 1.0;
                num = std::abs(num);

                int tmp = static_cast<int>(std::round(num * precision * sign));
                this->numerator = tmp; 
                this->denominator = static_cast<int>(precision);  

                this->reduct_frac();                 
            }  

            Fraction(): numerator(1), denominator(1){}

            Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator){}

            ~Fraction() {}


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
            
            // Fraction to float 
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