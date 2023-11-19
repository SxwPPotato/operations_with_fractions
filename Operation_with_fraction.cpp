#include <iostream>
#include <math.h>
#include <string>

class Fraction
{
private:
    int numerator_;
    int denominator_;
public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }


    Fraction operator+ (Fraction right) {
        if (denominator_ == right.denominator_) {
            int newnumerator = numerator_ + right.numerator_;

                return Fraction( newnumerator , denominator_);
        }
        else {
            int newnumerator = numerator_ * right.denominator_ + denominator_ * right.numerator_;
            int newdenominator = denominator_ * right.denominator_;

            while (newnumerator % 2 == 0 && newdenominator % 2 == 0) {
                newnumerator = newnumerator / 2;
                newdenominator = newdenominator / 2;
            }
            return Fraction (newnumerator , newdenominator);
        }
      
    }

    Fraction operator- (Fraction right) {
        if (denominator_ == right.denominator_) {
            int newnumerator = numerator_ - right.numerator_;

            return Fraction (newnumerator, denominator_);
        }
        else {
            int newnumerator = numerator_ * right.denominator_ - denominator_ * right.numerator_;
            int newdenominator = denominator_ * right.denominator_;

            while (newnumerator % 2 == 0 && newdenominator % 2 == 0) {
                newnumerator = newnumerator / 2;
                newdenominator = newdenominator / 2;
            }
            return Fraction (newnumerator, newdenominator);
        }

    }

    Fraction operator* (Fraction right) {
      
            int newnumerator = numerator_ * right.numerator_;
            int newdenominator = denominator_ * right.denominator_;

            while (newnumerator % 2 == 0 && newdenominator % 2 == 0) {
                newnumerator = newnumerator / 2;
                newdenominator = newdenominator / 2;
            }
            return Fraction(newnumerator, newdenominator);

    }

    Fraction operator/ (Fraction right) {

        int newnumerator = numerator_ * right.denominator_;
        int newdenominator = denominator_ * right.numerator_;

        while (newnumerator % 2 == 0 && newdenominator % 2 == 0) {
            newnumerator = newnumerator / 2;
            newdenominator = newdenominator / 2;
        }
        return Fraction(newnumerator, newdenominator);

    }

    Fraction& operator- () { 
        numerator_  = -numerator_;
        denominator_  = -denominator_;
        return *this; 
    }


    Fraction& operator++ () {
        numerator_ = numerator_ + denominator_;
        return *this;
    }

    Fraction operator++ (int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator-- () {
        numerator_ = numerator_ - denominator_;
        return *this;
    }

    Fraction operator-- (int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    void frac() {
        std::cout << numerator_ << "/" << denominator_ << "\n";
    }


    void Print(Fraction right, char oper) {
        std::cout << numerator_ << "/" << denominator_ << " " << oper << " " << right.numerator_ << "/" << right.denominator_ << " = ";
    }

    void PostfixPrint(Fraction right, char oper, std::string signs) {
        std::cout << numerator_  << "/" << denominator_ <<  signs << " " << oper << " " << right.numerator_ << "/" << right.denominator_ << " = ";

    }
    
    void PrefixPrint(Fraction right, char oper, std::string signs) {
        std::cout << signs << numerator_ << "/" << denominator_  << " " << oper << " " << right.numerator_ << "/" << right.denominator_ << " = ";

    }
};

int main()
{
    setlocale(LC_ALL, "russian");

    int numerator1;
    int denominator1;
    int numerator2;
    int denominator2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> numerator1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denominator1;

    Fraction f1(numerator1, denominator1);

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> numerator2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denominator2;
    Fraction f2(numerator2, denominator2);


    f1.Print(f2, '+');
    Fraction f3 = f1 + f2;
    f3.frac();

    f1.Print(f2, '-');
    Fraction f4 = f1 - f2;
    f4.frac();

    f1.Print(f2, '*');
    Fraction f5 = f1 * f2;
    f5.frac();

    f1.Print(f2, '/');
    Fraction f6 = f1 / f2;
    f6.frac();

   
    f1.PrefixPrint(f2, '*',"++");
    Fraction f7 = ++f1 * f2;
    f7.frac();

    std::cout << "Значение дроби 1 = ";
    f1.frac();
    std::cout << "\n";

   
    f1.PostfixPrint(f2, '*', "--");
    Fraction f8 = f1-- * f2;
    f8.frac();

    std::cout << "Значение дроби 1 = ";
    f1.frac();


    return 0;
}
