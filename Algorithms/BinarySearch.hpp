#include <map>
#include <vector>
#include <string>
#include <cctype>
#include "Sorting.hpp"

using namespace std;

namespace Contoso 
{
    namespace BinarySearch
    {
        inline map<int, string> GenerateMap(int size) {
            map<int, string> ret{};

            for (int i{1}; i <= size; i++) 
            {
                ret[i] = "Item " + to_string(i);
            }

            return ret;
        }

        inline vector<int> GenerateVector(int size)
        {
            vector<int> ret{};
            for (int i{0}; i < size; i++) 
            {
                ret.push_back(i + (2 * i));
            }

            return ret;
        } 

        //O(logN)
        int Search(int value, vector<int> const & vect, int start = 0, int finish = 0) 
        {
            if (finish == 0)
            {
                finish = vect.size();
            }
            else if (start == finish) 
            {
                return -1;
            }

            int middle_point = start + ((finish - start) / 2);
            
            if (vect[middle_point] == value) 
            {
                return middle_point;
            } 
            else if (vect[middle_point] > value) 
            {

                return Search(value, vect, start, middle_point);
            } 
            else 
            {
                return Search(value, vect, middle_point + 1, finish);
            }
        }

        int SearchNoRecursion(int value, int items[], int len) 
        {
            int start = 0, end = len - 1, result = -1;
            
            while (end - start >= 1) 
            {
                int diff = end - start;
                int needle = diff == 1 && end > 1 ? start + diff : start + ((end - start) / 2);
                cout << "start " << start << " needle " << needle << " end " << end << endl;
                if (items[needle] == value)
                {
                    result = needle;
                    break;
                } 
                else if (value > items[needle])
                {
                    start = needle;
                }
                else
                {
                    end = needle;
                }
            }

            return result;
        }

        int Search(string value, string *list, int length)
        {
            int start = 0, finish = length, needle = 0;
            int result{-1};
            while (finish - start > 1)
            {
                needle = start + ((finish - start) / 2);
                if (list[needle] == value)
                {
                    result = needle;
                    break;
                }
                else
                {
                    if (Contoso::Sorting::Compare(value, list[needle]) > 0)
                    {
                        start = needle;
                    }
                    else
                    {
                        finish = needle;
                    }
                }
            }

            return result;
        }
    }
}