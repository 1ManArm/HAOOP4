#include <iostream>
#include <vector>
#include <string>

class Drob {
private:
    int chisl;
    int znamen;
    int NOD(int x, int y)
    {
        if (y == 0) return x;
        return NOD(y, x % y);
    }
public:
    void input(int c, int z)
    {
        chisl = c;
        znamen = z;
    }
    void mult(int x)
    {
        chisl *= x;
        std::cout << "Дробь: " << chisl << '/' << znamen << std::endl;
    }
    void div(int x)
    {
        znamen *= x;
        std::cout << "Дробь: " << chisl << '/' << znamen << std::endl;

    }

    void sum(int x)
    {
        chisl += (x * znamen);
        std::cout << "Дробь: " << chisl << '/' << znamen << std::endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        std::cout << "Дробь: " << chisl << '/' << znamen << std::endl;

    }
    void show()
    {
        std::cout << "Текущая дробь: " << chisl << '/' << znamen << std::endl;
    }
    int peredacha()
    {
        return NOD(chisl, znamen);
    }
    void reduct(int x)
    {
        chisl /= x;
        znamen /= x;
    }

};

class complex
{
private:
    double re, im;
public:
    complex() { re = 0; im = 0; }
    complex(double r, double i) { re = r; im = i; }
    complex(const complex& ob) { re = ob.re; im = ob.im; };
    complex& operator = (complex);
    complex operator + (complex);
    complex operator - (complex);
    complex operator * (complex&);
    complex operator / (complex&);
    complex& operator += (complex);
    complex& operator -= (complex);
    complex& operator *= (complex);
    complex& operator /=(complex);
    friend std::istream& operator >>(std::istream&, complex&);
    friend std::ostream& operator << (std::ostream&, const complex&);
    bool operator == (complex& com);
    bool operator != (complex& com);
    bool operator > (complex& com);
    bool operator < (complex& com);

};

bool complex:: operator > (complex& com)
{
    if (this->re > com.re)
        return 1;
    else if (this->re == com.re && this->im > com.im)
        return 1;
    else
        return 0;
}

bool complex ::operator < (complex& com)
{
    if (this->re < com.re)
        return 1;
    else if (this->re == com.re && this->im < com.im)
        return 1;
    else
        return 0;

}

bool complex::operator != (complex& com)
{
    if (this->re != com.re || this->im != com.im)
        return 1;
    else
        return 0;
}

bool complex::operator==(complex& com)
{
    if (this->re == com.re && this->im == com.im)
        return 1;
    else
        return 0;
}

complex complex::operator*(complex& com)
{
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    re = i;
    im = j;
    return *this;
}

complex complex::operator/(complex& com)
{
    double i, j, k;
    k = re * re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (com.re * im - re * com.im) / k;
    re = i;
    im = j;
    return *this;
}

complex& complex::operator =(complex com)
{
    this->re = com.re;
    this->im = com.im;
    return *this;
}

complex complex::operator+(complex com)
{
    this->re = this->re + com.re;
    this->im = this->im + com.im;
    return *this;
}

complex complex::operator-(complex com)
{
    this->re = this->re - com.re;
    this->im = this->im - com.im;
    return *this;
}


std::ostream& operator << (std::ostream& out, const complex& com)
{
    if (com.im < 0)
        out << com.re << "+i(" << com.im << ")\n";
    else
        out << com.re << "+i" << com.im << "\n";
    return out;
}

std::istream& operator >> (std::istream& in, complex& com)
{
    std::cout << "Введите действительную часть комплексного числа -> ";
    in >> com.re;
    std::cout << "Введите мнимую часть комплексного числа -> ";
    in >> com.im;
    return in;
}

complex& complex::operator+=(complex a)
{
    re += a.re;
    im += a.im;
    return *this;
}

complex& complex::operator-=(complex a)
{
    re -= a.re;
    im -= a.im;
    return *this;
}

complex& complex::operator*=(complex a)
{
    re *= a.re;
    im *= a.im;
    return *this;
}

complex& complex::operator/=(complex a)
{
    re /= a.re;
    im /= a.im;
    return *this;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //Задание 1
    int a, b, m;
    char c = 'y';
    std::cout << "Введите числитель: " << std::endl;
    std::cin >> a;
    std::cout << "Введите знаменатель: " << std::endl;
    std::cin >> b;
    Drob obj;
    obj.input(a, b);
    do {
        obj.reduct(obj.peredacha());
        obj.show();
        std::cout << "1. Прибавить к дроби число" << std::endl;
        std::cout << "2. Отнять от дроби число" << std::endl;
        std::cout << "3. Умножить дробь на число" << std::endl;
        std::cout << "4. Разделить дробь на число" << std::endl;
        std::cout << "Выберите действие -> " << '\n';
        std::cin >> m;
        switch (m)
        {
        case 1:
            std::cout << "Введите слагаемое " << std::endl;
            std::cin >> a;
            obj.sum(a);
            break;
        case 2:
            std::cout << "Введите вычитаемое " << std::endl;
            std::cin >> a;
            obj.sub(a);
            break;
        case 3:
            std::cout << "Введите множитель " << std::endl;
            std::cin >> a;
            obj.mult(a);
            break;
        case 4:
            std::cout << "Введите делитель " << std::endl;
            std::cin >> a;
            obj.div(a);
            break;
        default:
            std::cout << "Выбор некорректен " << std::endl;
        }
        std::cout << "Продолжить работу? (y/n)" << std::endl;
        std::cin >> c;
    } while (c != 'n');

    //Задание 2

    complex com;
    std::cin >> com;
    std::cout << com << std::endl;
    return 0;
}