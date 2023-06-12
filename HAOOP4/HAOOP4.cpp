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
        std::cout << "�����: " << chisl << '/' << znamen << std::endl;
    }
    void div(int x)
    {
        znamen *= x;
        std::cout << "�����: " << chisl << '/' << znamen << std::endl;

    }

    void sum(int x)
    {
        chisl += (x * znamen);
        std::cout << "�����: " << chisl << '/' << znamen << std::endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        std::cout << "�����: " << chisl << '/' << znamen << std::endl;

    }
    void show()
    {
        std::cout << "������� �����: " << chisl << '/' << znamen << std::endl;
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
    std::cout << "������� �������������� ����� ������������ ����� -> ";
    in >> com.re;
    std::cout << "������� ������ ����� ������������ ����� -> ";
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

    //������� 1
    int a, b, m;
    char c = 'y';
    std::cout << "������� ���������: " << std::endl;
    std::cin >> a;
    std::cout << "������� �����������: " << std::endl;
    std::cin >> b;
    Drob obj;
    obj.input(a, b);
    do {
        obj.reduct(obj.peredacha());
        obj.show();
        std::cout << "1. ��������� � ����� �����" << std::endl;
        std::cout << "2. ������ �� ����� �����" << std::endl;
        std::cout << "3. �������� ����� �� �����" << std::endl;
        std::cout << "4. ��������� ����� �� �����" << std::endl;
        std::cout << "�������� �������� -> " << '\n';
        std::cin >> m;
        switch (m)
        {
        case 1:
            std::cout << "������� ��������� " << std::endl;
            std::cin >> a;
            obj.sum(a);
            break;
        case 2:
            std::cout << "������� ���������� " << std::endl;
            std::cin >> a;
            obj.sub(a);
            break;
        case 3:
            std::cout << "������� ��������� " << std::endl;
            std::cin >> a;
            obj.mult(a);
            break;
        case 4:
            std::cout << "������� �������� " << std::endl;
            std::cin >> a;
            obj.div(a);
            break;
        default:
            std::cout << "����� ����������� " << std::endl;
        }
        std::cout << "���������� ������? (y/n)" << std::endl;
        std::cin >> c;
    } while (c != 'n');

    //������� 2

    complex com;
    std::cin >> com;
    std::cout << com << std::endl;
    return 0;
}