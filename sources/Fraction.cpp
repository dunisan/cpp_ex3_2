#include "Fraction.hpp"

namespace ariel{

  



    //----------------------------------------
    // get's and set's
    //----------------------------------------
    int Fraction::getNumerator(){
        return this->numerator;
    }            
            
    int Fraction::getDenominator(){
        return this->denominator;
    }

    void Fraction::setNumerator(int num){
        this->numerator = num; 
    }

    void Fraction::setDenominator(int num){
        this->denominator = num; 

    }



    //----------------------------------------
    // reduction of fraction 
    //----------------------------------------

    void Fraction::reduct_frac(){
        
        int gcd = _gcd(std::abs(this->numerator), std::abs(this->denominator));
        
        this->setNumerator(this->numerator /= gcd);  
        this->setDenominator(this->denominator /= gcd); 

        if (this->denominator < 0)
        {
            this->numerator *= -1; 
            this->denominator *= -1; 
        }
        
    }

    //----------------------------------------
    // binary operators
    //----------------------------------------

    // Fraction to fraction 
    Fraction Fraction::operator+(const Fraction& frac){
        int nume = (this->numerator * frac.denominator) + (this->denominator * frac.numerator);
        int deno = this->denominator * frac.denominator;
        Fraction sum(nume, deno); 
        sum.reduct_frac();  
        return sum;
    } 

    Fraction Fraction::operator-(const Fraction& frac){
        int nume = (this->numerator * frac.denominator) - (this->denominator * frac.numerator);
        int deno = this->denominator * frac.denominator;
        Fraction subtraction(nume, deno); 
        subtraction.reduct_frac();  
        return subtraction;
    }

    Fraction Fraction::operator/(const Fraction& frac){
        if(frac == 0){
            throw std::runtime_error("divide in 0"); 
        }
        int nume = (this->numerator * frac.denominator);
        int deno = (this->denominator * frac.numerator);
        Fraction division(nume,deno); 
        division.reduct_frac();
        return division;
    }

    Fraction Fraction::operator*(const Fraction& frac){
        int nume = (this->numerator * frac.numerator); 
        int deno = (this->denominator * frac.denominator);
        Fraction product(nume,deno);
        product.reduct_frac(); 
        return product;
    }
    
    // Fraction to float 
    Fraction Fraction::operator+(const float num){
        Fraction a = float_to_fraction(num);
        return *this + a;
    }
    
    Fraction Fraction::operator-(const float num){
        Fraction a = float_to_fraction(num); 
        return *this - a;
    }

    Fraction Fraction::operator/(const float num){
        if(num == 0){
            throw std::runtime_error("divide in 0"); 
        }
        Fraction a = float_to_fraction(num); 
        return *this / a;
    }

    Fraction Fraction::operator*(const float num){
        Fraction a = float_to_fraction(num); 
        return *this * a;
    }


    // float to fraction 
    Fraction operator+(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        int nume = (a.numerator * frac.denominator) + (a.denominator * frac.numerator);
        int deno = a.denominator * frac.denominator;
        Fraction sum(nume, deno); 
        sum.reduct_frac();  
        return sum; 
    }

    Fraction operator-(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        int nume = (a.numerator * frac.denominator) - (a.denominator * frac.numerator);
        int deno = a.denominator * frac.denominator;
        Fraction subtraction(nume, deno); 
        subtraction.reduct_frac();  
        return subtraction;
    
    }
    Fraction operator/(const float num, const Fraction& frac){
        if(frac == 0){
            throw std::runtime_error("divide in 0"); 
        }
        Fraction a = float_to_fraction(num); 
        int nume = (a.numerator * frac.denominator);
        int deno = (a.denominator * frac.numerator);
        Fraction division(nume,deno); 
        division.reduct_frac();
        return division;
    }
    Fraction operator*(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num);

        int nume = (a.numerator * frac.numerator); 
        int deno = (a.denominator * frac.denominator);
        Fraction product(nume,deno);
        product.reduct_frac(); 
        return product;
    }
    
    

    //--------------------------------------
    // Increment 
    //--------------------------------------

    // prefix 
    Fraction& Fraction::operator++(){
        this->numerator+=this->denominator; 
        this->reduct_frac(); 
        return *this;
    }

    Fraction& Fraction::operator--(){
        this->numerator-=this->denominator; 
        this->reduct_frac(); 
        return *this;
    } 


    // postfix
    Fraction Fraction::operator++(int){
        Fraction cpy(*this); 
        this->numerator += this->denominator; 
        this->reduct_frac(); 
        return cpy;
    } 
    Fraction Fraction::operator--(int){
        Fraction cpy(*this); 
        this->numerator -= this->denominator; 
        this->reduct_frac(); 
        return cpy;
    }


    //----------------------------------------
    // Comparison operators
    //----------------------------------------
    
    // fraction to fraction 
    bool operator==(const Fraction& frac1, const Fraction& frac2){
        if(frac1.numerator != frac2.numerator || frac1.denominator != frac2.denominator)
            return false; 
        return true;
    }
    bool operator>(const Fraction& frac1, const Fraction& frac2){
        int common_num1 = frac1.numerator * frac2.denominator; 
        int common_num2 = frac2.numerator * frac1.denominator; 

        if(common_num1 > common_num2){
            return true; 
        }        
        return false; 
    }
    bool operator>=(const Fraction& frac1, const Fraction& frac2){
        int common_num1 = frac1.numerator * frac2.denominator; 
        int common_num2 = frac2.numerator * frac1.denominator; 

        if(common_num1 >= common_num2){
            return true; 
        }        
        return false; 
    }
    bool operator<(const Fraction& frac1, const Fraction& frac2){
        int common_num1 = frac1.numerator * frac2.denominator; 
        int common_num2 = frac2.numerator * frac1.denominator; 

        if(common_num1 < common_num2){
            return true; 
        }        
        return false; 
    }
    bool operator<=(const Fraction& frac1, const Fraction& frac2){
        int common_num1 = frac1.numerator * frac2.denominator; 
        int common_num2 = frac2.numerator * frac1.denominator; 

        if(common_num1 <= common_num2){
            return true; 
        }        
        return false; 
    }

    // float to fraction
    bool operator==(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        return a==frac; 
    }

    bool operator>(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        return a>frac; 
    }
    bool operator>=(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        return a>=frac; 
    }
    bool operator<(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        return a<frac; 
    }
    bool operator<=(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        return a<=frac;  
    }

    // fraction to float 
    bool operator==(const Fraction& frac, const float num){
        return num==frac; 
    }
    bool operator>(const Fraction& frac, const float num){
        return num<frac; 
    }
    bool operator>=(const Fraction& frac, const float num){
        return num<=frac; 
    }
    bool operator<(const Fraction& frac, const float num){
        return num>frac; 
    }
    bool operator<=(const Fraction& frac, const float num){
        return num>=frac; 
    }


    
    //----------------------------------
    // IO operators
    //----------------------------------

    // IO to fraction 
    std::ostream& operator<<(std::ostream& output, const Fraction& frac){
        output << frac.numerator << "/" << frac.denominator;
        return output; 
    }
    std::istream& operator>>(std::istream& input , Fraction& frac){
        int num1, num2;
        char space;

        // Read input
        if (std::cin >> num1 >> space && space == ' ' && std::cin >> num2) {
            // Input is valid
            std::cout << "Input is valid: " << num1 << " " << num2 << std::endl;
        } else {
            // Input is invalid
            std::cout << "Input is invalid." << std::endl;
            throw std::invalid_argument(""); 
        }

        
        return input;
    }





    int _gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }

    /*This function is taken from chatGPT for now. hope to build my own*/
    Fraction float_to_fraction(float num) {
    
    const int precision = 1000; // 3 digits after the decimal point
    int sign = num < 0 ? -1 : 1;
    num = std::abs(num);

    int nume = round(sign*num*precision);
    int deno = precision;  
    int divisor = _gcd(std::abs(nume), std::abs(deno));


    nume /= divisor;
    deno /= divisor; 

    Fraction newfrac(nume, deno);
    // newfrac.reduct_frac(); 
    return newfrac; 

}


}