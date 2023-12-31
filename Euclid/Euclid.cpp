#include <iostream>

int Euclid(int a, int b, int& x, int& y)
{
    // Variables for Extended Euclidean Algorithm
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    // Looping Calculation
    while (b != 0)
    {
        // Euclidean Algorithm
        int q = a / b;
        int r = a % b;
        std::cout << a << " = " << q << " * " << b << " + " << r << std::endl;
        int temp = b;
        b = r;
        a = temp;
        // Extended Euclidean Algorithm Calculation
        int tempX = x0;
        x0 = x1;
        x1 = tempX - q * x1;

        int tempY = y0;
        y0 = y1;
        y1 = tempY - q * y1;
    }
    x = x0;
    y = y0;

    return a;
}

int main()
{
    int num1, num2;
    std::cout << "MAT361 Fall 2023: Euclidean Algorithm Program in C++ - Sungmin Moon" << std::endl;
    std::cout << "This program is uploaded in https://github.com/Elphior/MAT361_A1.git" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int x, y;
    int result;
    if (num1 > num2)
        result = Euclid(num1, num2, x, y);
    else
        result = Euclid(num2, num1, y, x);
        
    std::cout << std::endl;
    std::cout << "gcd(" << num1 << ", " << num2 << "): " << result << std::endl;
    std::cout << x << " * " << num1 << " + " << y << " * " << num2 << " = " << x * num1 + y * num2 << std::endl;

    return 0;
}
