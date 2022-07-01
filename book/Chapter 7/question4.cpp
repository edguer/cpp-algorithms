#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int flip(int value)
{
    return ~value + 1;
}

int minus_operation(int value1, int value2)
{
    return value1 + flip(value2);
}

int abs_operation(int value)
{
    return value < 0 ? flip(value) : value;
}

int multiply_operation(int value, int multiplier)
{
    int result = 0;
    for (int i = 0; i < abs_operation(multiplier); i++)
    {
        result += value;
    }
    return multiplier < 0 ? flip(result) : result;
}

int divide_operation(int value, int divisor)
{
    if (divisor == 0)
        return 0;

    int result = 0;
    int temp_sum = 0;
    for (; result <= abs_operation(divisor); result++)
    {
        temp_sum += abs_operation(divisor);
        if (abs_operation(temp_sum) >= abs_operation(value))
        {
            result++;
            break;
        }
    }
    if (abs_operation(temp_sum) > abs_operation(value))
        result += flip(divisor);

    return divisor < 0 && value > 0 ? flip(result) : result;
}

int main()
{
    int a = 21, b = 0;
    cout << "Minus: " << minus_operation(a, b) << endl;
    cout << "Multiply: " << multiply_operation(a, b) << endl;
    cout << "Divide: " << divide_operation(a, b) << endl;
}