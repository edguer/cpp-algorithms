#include <bits/stdc++.h>
#include <string>
using namespace std;

const unsigned int NUM_CHARS = 54;
// time: O(n), space: O(n + k), k == possible characters
bool NotMemoryEfficient(string str)
{
    // If greater then the possible number of characters, it necessarily has duplicates
    if (str.length() > NUM_CHARS)
    {
        return false;
    }

    bool duplicated[NUM_CHARS] = {false};

    bool unique = true;
    for (unsigned short i = 0; i < str.length(); i++)
    {
        if (duplicated[str.at(i) - 'A'])
        {
            unique = false;
            break;
        }
        else
        {
            duplicated[str.at(i) - 'A'] = true;
        }
    }

    return unique;
}

bool MemoryEfficient(string *str)
{
    // If greater then the possible number of characters, it necessarily has duplicates
    // uses only ASCII small letters
    if (str->length() > 27)
    {
        return false;
    }

    // instead of a regular bool array, which takes 8 buts per value, we use a single 32 bit integer and control its bits
    // it starts with 0, so: 000000000000000000000000000000000
    int checker = 0;

    for (unsigned short i = 0; i < str->length(); i++)
    {
        int val = str->at(i) - 'a';
        // First, we shift 1 (000000000000000000000000000000001) to the left by the factor of the found charater.
        // Let's say our first character is 'b', so val will be 'b' - 'a', which is 1. So, we shift 1 by the factor of one:
        // 1 << 'b' -> 000000000000000000000000000000010. If it was 'c': 1 << 'b' -> 000000000000000000000000000000100.
        // See that the (1 << val) expression works as a bit array for the chracter position. 
        // Second, we execute e AND bit-wise operation between checker and our "bit array". Let's say the checker is 0 and our character is 'b':
        // checker & (1 << val) -> 000000000000000000000000000000000 & 000000000000000000000000000000010 -> 000000000000000000000000000000000
        // So the result is an integral 0, meaning that number was not capture before. Next thing you do is add that character to our checker, our bit array.
        // For that, we use the (1 << val) expression to find the right bit sequence corresponding to that character, let's say 'b' (000000000000000000000000000000100)
        // but we cannot simply do checker = 1 << val, because if would override any other bit already register in checker. So, we need to run a bit-wise OR operation over 
        // checker, so it keep the 1 bits already registered. checker |= 1 << val will give us, supposing a 'c' is already in checker:
        // checker:             000000000000000000000000000000100
        // 1 << val:            000000000000000000000000000000010
        // checker |= 1 << val: 000000000000000000000000000000110
        // That way, we use checker as our bit array, filling it with 1 bits for the chracters already visited.
        // This solution is limited to 32 bits operations for regular integrals and 64 for long, but it can be expanded by the use of arrays. 
        // this article explains that: http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-intro/bit-array.html
        if ((checker & (1 << val)) > 0)
        {
            return false;
        }
        else
        {
            checker |= 1 << val;
        }
    }

    return true;
}

/* *
 * String as unique characters?
 * Questions:
 * - Is it ASCII or unicode? Unicode requires more storage.
 * Optimizations:
 * - Return when the first duplicated is found, so no need to have counters - saves 7 bits of space per possible characters.
 * - Return right away if the number of characters is greater then the number of possible characters - varies if ASCII or Unicode
 * */
int main()
{
    cout << "Type a value: ";

    string str;
    cin >> str;

    cout << endl;

    if (MemoryEfficient(&str))
    {
        cout << "Characters are unique." << endl;
    }
    else
    {
        cout << "They are not unique." << endl;
    }
}