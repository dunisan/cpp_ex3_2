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
        
        // find the gcd and devide the nume and deno with the gcd. 
        int gcd = _gcd(std::abs(this->numerator), std::abs(this->denominator));
        
        this->setNumerator(this->numerator /= gcd);  
        this->setDenominator(this->denominator /= gcd); 
        
        // if deno < 0 flip the both in order passing the tests. 
        if (this->denominator < 0)
        {
            this->numerator *= -1; 
            this->denominator *= -1; 
        }
        
    }

    //----------------------------------------
    // binary operators
    //----------------------------------------

    Fraction Fraction::operator+(const Fraction& frac){
    // use a 64 bit int inorder to check if there is an overflow on opeartion
    int64_t nume = int64_t(this->numerator) * frac.denominator + int64_t(this->denominator) * frac.numerator;
    int64_t deno = int64_t(this->denominator) * frac.denominator;
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in addition");
    }
    // create new fraction for the sum 
    Fraction sum(static_cast<int>(nume), static_cast<int>(deno)); 
    return sum;
    }

    Fraction Fraction::operator-(const Fraction& frac){
    // use a 64 bit int inorder to check if there is an overflow on opeartion
    int64_t nume = int64_t(this->numerator) * frac.denominator - int64_t(this->denominator) * frac.numerator;
    int64_t deno = int64_t(this->denominator) * frac.denominator;
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in subtraction");
    }
    // create new fraction 
    Fraction subtraction(static_cast<int>(nume), static_cast<int>(deno)); 
    return subtraction;
    }
    
    Fraction Fraction::operator/(const Fraction& frac){
    if(frac.numerator == 0 || this->denominator == 0){
        throw std::runtime_error("Division by zero"); 
    }
    // use a 64 bit int inorder to check if there is an overflow on opeartion
    int64_t nume = int64_t(this->numerator) * frac.denominator;
    int64_t deno = int64_t(this->denominator) * frac.numerator;
    
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in division");
    }

    // create new fraction and return it 
    Fraction division(static_cast<int>(nume), static_cast<int>(deno)); 
    return division;
    }

    Fraction Fraction::operator*(const Fraction& frac){
    
        // use a 64 bit int inorder to check if there is an overflow on opeartion

        int64_t nume = static_cast<int64_t>(this->numerator) * static_cast<int64_t>(frac.numerator);
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in numerator");
        }

        int64_t deno = static_cast<int64_t>(this->denominator) * static_cast<int64_t>(frac.denominator);
        if (deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in denominator");
        }
            
        int num = static_cast<int>(nume);
        int den = static_cast<int>(deno);
        
        //create new fraction and return it
        Fraction product(num, den);
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
        int64_t nume = int64_t(a.numerator) * frac.denominator + int64_t(a.denominator) * frac.numerator;
        int64_t deno = int64_t(a.denominator) * frac.denominator;
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
            deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow in addition");
        }
        // create new fraction for the sum 
        Fraction sum(static_cast<int>(nume), static_cast<int>(deno)); 
        return sum;
    }

    Fraction operator-(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num); 
        int64_t nume = int64_t(a.numerator) * frac.denominator - int64_t(a.denominator) * frac.numerator;
        int64_t deno = int64_t(a.denominator) * frac.denominator;
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
            deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow in subtraction");
        }
        // create new fraction 
        Fraction subtraction(static_cast<int>(nume), static_cast<int>(deno)); 
        return subtraction;
    }

    Fraction operator/(const float num, const Fraction& frac){
        if(frac == 0){
            throw std::runtime_error("divide in 0"); 
        }
        Fraction a = float_to_fraction(num); 
        // use a 64 bit int inorder to check if there is an overflow on opeartion
        int64_t nume = int64_t(a.numerator) * frac.denominator;
        int64_t deno = int64_t(a.denominator) * frac.numerator;
        
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
            deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Overflow in division");
        }

        // create new fraction and return it 
        Fraction division(static_cast<int>(nume), static_cast<int>(deno)); 
        return division;
    }

    Fraction operator*(const float num, const Fraction& frac){
        Fraction a = float_to_fraction(num);

        int64_t nume = static_cast<int64_t>(a.numerator) * static_cast<int64_t>(frac.numerator);
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in numerator");
        }

        int64_t deno = static_cast<int64_t>(a.denominator) * static_cast<int64_t>(frac.denominator);
        if (deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in denominator");
        }

        //create new fraction and return it
        Fraction product(static_cast<int>(nume), static_cast<int>(deno));
        return product;
    }
    
    
    //--------------------------------------
    // Increment 
    //--------------------------------------

    // prefix 
    Fraction& Fraction::operator++(){
        this->numerator+=this->denominator;  // add denominater for adding 1. 
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
        // create a cpy, add 1 and return the cpy. 
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
        if(frac1.numerator == 0 && frac2.numerator == 0){
            return true; 
        }
        // for equality - same exactly 
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

    // fraction to float -- call the float to fraction in reverse. 
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
    // input 
    std::istream& operator>>(std::istream& input , Fraction& frac){
        double new_nume = 0, new_deno = 0;

        // Read input
        if (input >> new_nume && input.peek() == ' ' && input.ignore() && input >> new_deno) {
            
            // deno != 0
            if(new_deno == 0){
                throw std::runtime_error("invalid denominator"); 
            }
            // input not int 
            if (std::floor(new_nume) != new_nume || std::floor(new_deno) != new_deno) {
                throw std::runtime_error("Invalid input: input must be an integer");
            }

            // save the nume negitive if needed. 
            if(new_deno < 0){ 
                new_nume *=  -1;
                new_deno *= -1;
            }
                      
            frac.numerator = new_nume; 
            frac.denominator = new_deno; 
        } else {
            throw std::runtime_error("invalid input!"); 
        }
        
        return input;
    }


    int _gcd(int first, int second) {
    while (second != 0) {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
    }

    Fraction float_to_fraction(float num) {
        
        // this part converts the float to a fraction. 
        // numerator = num * 1000
        // denominater = 1000 
        // reduct
        const float precision = 1000.0; // 3 digits after the decimal point
    
        // we use the sign and abs to save that the numerator will get the negitive value if there is. 
        int sign = num < 0 ? -1 : 1;
        num = std::abs(num);
        
        int nume = round(sign*num*precision);
        int deno = precision;  

        Fraction newfrac(nume, deno);
        return newfrac; 

    }


}