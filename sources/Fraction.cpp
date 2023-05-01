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

    Fraction Fraction::operator+(const Fraction& frac){
    int64_t nume = int64_t(this->numerator) * frac.denominator + int64_t(this->denominator) * frac.numerator;
    int64_t deno = int64_t(this->denominator) * frac.denominator;
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in addition");
    }
    Fraction sum(static_cast<int>(nume), static_cast<int>(deno)); 
    sum.reduct_frac();  
    return sum;
    }

    Fraction Fraction::operator-(const Fraction& frac){
    int64_t nume = int64_t(this->numerator) * frac.denominator - int64_t(this->denominator) * frac.numerator;
    int64_t deno = int64_t(this->denominator) * frac.denominator;
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in subtraction");
    }
    Fraction subtraction(static_cast<int>(nume), static_cast<int>(deno)); 
    subtraction.reduct_frac();  
    return subtraction;
}

    Fraction Fraction::operator/(const Fraction& frac){
    if(frac.numerator == 0){
        throw std::runtime_error("Division by zero"); 
    }
    int64_t nume = int64_t(this->numerator) * frac.denominator;
    int64_t deno = int64_t(this->denominator) * frac.numerator;
    if (deno == 0) {
        throw std::overflow_error("Overflow in division");
    }
    if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min() ||
        deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in division");
    }
    Fraction division(static_cast<int>(nume), static_cast<int>(deno)); 
    division.reduct_frac();
    return division;
    }


    Fraction Fraction::operator*(const Fraction& frac){
    
        // check for overflow in numerator
        int64_t nume = static_cast<int64_t>(this->numerator) * static_cast<int64_t>(frac.numerator);
        if (nume > std::numeric_limits<int>::max() || nume < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in numerator");
        }

        // check for overflow in denominator
        int64_t deno = static_cast<int64_t>(this->denominator) * static_cast<int64_t>(frac.denominator);
        if (deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()) {
            throw std::overflow_error("multiplication overflow in denominator");
        }
            
        int num = static_cast<int>(nume);
        int den = static_cast<int>(deno);
        Fraction product(num, den);
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
        if(frac1.numerator == 0 && frac2.numerator == 0){
            return true; 
        }
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
        double new_re = 0, new_im = 0;

        // remember place for rewinding
        std::ios::pos_type startPosition = input.tellg();

        // Read input
        if (input >> new_re && input.peek() == ' ' && input.ignore() && input >> new_im) {
            if(new_im == 0){
                throw std::runtime_error("invalid denominator"); 
            }

            if (std::floor(new_re) != new_re || std::floor(new_im) != new_im) {
                throw std::runtime_error("Invalid input: input must be an integer");
            }


            if(new_im < 0){ 
                new_re *=  -1;
                new_im *= -1;
            }
                      
            frac.numerator = new_re; 
            frac.denominator = new_im; 

            

        } else {
            // rewind on error
            auto errorState = input.rdstate(); // remember error state
            input.clear(); // clear error so seekg will work
            input.seekg(startPosition); // rewind
            input.clear(errorState); // set back the error flag
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