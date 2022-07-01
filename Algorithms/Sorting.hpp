#include <string>
#include <bits/stdc++.h>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>

#ifndef SORTING
#define SORTING

using namespace std;

namespace Contoso
{
    namespace Sorting
    {
        void Print(int arr[], int len)
        {
            for (int i = 0; i < len; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }

        void Print(string *arr, int len)
        {
            for (int i = 0; i < len; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }

        void Swap(string *item1, string *item2)
        {
            string temp = *item1;
            *item1 = *item2;
            *item2 = temp;
        }

        //O(n2)
        void BubbleSort(int *arr, int size)
        {
            int i = 0;
            for (; i < size; i++)
            {
                bool any_sorting = false;
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        any_sorting = true;
                    }
                }

                // reduces time complexity in most of the cases
                if (!any_sorting)
                {
                    break;
                }
            }
        }

        int Compare(const string &s1, const string &s2)
        {
            const char *str_arr_s1 = s1.c_str();
            const char *str_arr_s2 = s2.c_str();

            char current_char_s1, current_char_s2;
            int char_count = 0;
            do
            {
                current_char_s1 = tolower(str_arr_s1[char_count]);
                current_char_s2 = tolower(str_arr_s2[char_count]);
                char_count++;
            } while (current_char_s1 == current_char_s2 && char_count < s1.length() && char_count < s2.length());

            return (int)current_char_s1 - (int)current_char_s2;
        }

        //O(N2)
        void BubbleSort(string *arr, int size)
        {
            for (int i = 0; i < size; i++)
            {
                bool any_sorting = false;
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (Contoso::Sorting::Compare(arr[j], arr[j + 1]) > 0)
                    {
                        string temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        any_sorting = true;
                    }
                }

                // reduces time complexity in most of the cases
                if (!any_sorting)
                {
                    break;
                }
            }
        }

        //O(N logN)
        void QuickSort(string *arr, int low, int high)
        {
            if (high > low)
            {
                // pick pivot
                string *pivot = &arr[high];
                int i = low - 1;
                for (int j = low; j <= high; j++)
                {
                    if (Compare(arr[j], *pivot) < 0)
                    {
                        Swap(&arr[++i], &arr[j]);
                    }
                }
                Swap(&arr[++i], pivot);

                QuickSort(arr, low, i - 1);
                QuickSort(arr, i + 1, high);
            }
        }

        //O(N logN)
        void Merge(string *arr, int high, int middle, int low)
        {
            // simply calculate the length of each array
            int arr1_length = middle - low + 1, arr2_length = high - middle;
            string arr1[arr1_length], arr2[arr2_length];

            // fill the arrays with the data from the original array
            for (int i = 0; i < arr1_length; i++)
            {
                arr1[i] = arr[low + i];
            }

            for (int i = 0; i < arr2_length; i++)
            {
                arr2[i] = arr[middle + i + 1];
            }

            // here is where the main logic is: we compare each element of both arrays with the same index (arr1[0] < arr2[0] ?)
            // then we add the lower value to the first position (starting at low) of the original array and move only the lower value index
            // we continue doing that until arr1 or arr2 is traversed
            int arr1_index = 0, arr2_index = 0, index = low;
            for (; arr1_index < arr1_length && arr2_index < arr2_length; index++)
            {
                if (Compare(arr1[arr1_index], arr2[arr2_index]) <= 0)
                {
                    arr[index] = arr1[arr1_index];
                    arr1_index++;
                }
                else
                {
                    arr[index] = arr2[arr2_index];
                    arr2_index++;
                }
            }

            // it may happen that not all items were traversed, so we dump the rest of the items into the original array
            for (; arr1_index < arr1_length; index++, arr1_index++)
            {
                arr[index] = arr1[arr1_index];
            }

            for (; arr2_index < arr2_length; index++, arr2_index++)
            {
                arr[index] = arr1[arr2_index];
            }
        }

        void Merge(int *arr, int high, int middle, int low)
        {
            // simply calculate the length of each array
            int arr1_length = middle - low + 1, arr2_length = high - middle;
            int arr1[arr1_length], arr2[arr2_length];

            // fill the arrays with the data from the original array
            for (int i = 0; i < arr1_length; i++)
            {
                arr1[i] = arr[low + i];
            }

            for (int i = 0; i < arr2_length; i++)
            {
                arr2[i] = arr[middle + i + 1];
            }

            // here is where the main logic is: we compare each element of both arrays with the same index (arr1[0] < arr2[0] ?)
            // then we add the lower value to the first position (starting at low) of the original array and move only the lower value index
            // we continue doing that until arr1 or arr2 is traversed
            int arr1_index = 0, arr2_index = 0, index = low;
            for (; arr1_index < arr1_length && arr2_index < arr2_length; index++)
            {
                if (arr1[arr1_index] <= arr2[arr2_index])
                {
                    arr[index] = arr1[arr1_index];
                    arr1_index++;
                }
                else
                {
                    arr[index] = arr2[arr2_index];
                    arr2_index++;
                }
            }

            // it may happen that not all items were traversed, so we dump the rest of the items into the original array
            for (; arr1_index < arr1_length; index++, arr1_index++)
            {
                arr[index] = arr1[arr1_index];
            }

            for (; arr2_index < arr2_length; index++, arr2_index++)
            {
                arr[index] = arr2[arr2_index];
            }
        }

        //O(N LogN)
        void MergeSort(int *arr, int high, int low = 0)
        {
            // keep splitting up the array until its size is equals or greater than 1
            if (high > low)
            {
                int middle = low + (high - low) / 2;

                // recursive call = splitting
                MergeSort(arr, middle, low);
                MergeSort(arr, high, middle + 1);

                // then we merge: first merge will be between 2 arrays of size 1, then of size 2, than 4 and so on.
                // So the merge starts from bottom-up
                Merge(arr, high, middle, low);
            }
        }

        //O(N LogN)
        void MergeSort(string *arr, int high, int low = 0)
        {
            // keep splitting up the array until its size is equals or greater than 1
            if (high > low)
            {
                int middle = low + (high - low) / 2;

                // recursive call = splitting
                MergeSort(arr, middle, low);
                MergeSort(arr, high, middle + 1);

                // then we merge: first merge will be between 2 arrays of size 1, then of size 2, than 4 and so on.
                // So the merge starts from bottom-up
                Merge(arr, high, middle, low);
            }
        }

        //O(N2)
        void InsertionSort(string *arr, int length)
        {
            for (int i = 1; i < length; i++)
            {
                string key = arr[i];
                int j = i - 1;
                for (; j >= 0 && arr[j] > key; j--)
                {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
            }
        }

        //O(N2)
        void SelectionSort(string *arr, int length)
        {
            int last_lowest_index = -1;
            int search_index = -1;
            do
            {
                string lowest_value{};
                for (int i = last_lowest_index + 1; i < length; i++)
                {
                    if (lowest_value.empty() || Compare(arr[i], lowest_value) < 0)
                    {
                        lowest_value = arr[i];
                        search_index = i;
                    }
                }

                Swap(&arr[++last_lowest_index], &arr[search_index]);
            } while (search_index != -1 && last_lowest_index < length - 1);
        }

        void MaxHeap(string *arr, int length)
        {
            for (int j = 0; j < (length / 2) + 1; j++)
            {
                for (int i = 0; i < length; i++)
                {
                    int left_child_index = 2 * i + 1;
                    int right_child_index = 2 * i + 2;

                    if (left_child_index < length && Compare(arr[left_child_index], arr[i]) > 0)
                    {
                        Swap(&arr[left_child_index], &arr[i]);
                    }

                    if (right_child_index < length && Compare(arr[right_child_index], arr[i]) > 0)
                    {
                        Swap(&arr[right_child_index], &arr[i]);
                    }
                }
            }
        }

        //O(N logN) even for the best case, since we will always have to heapify
        void HeapSort(string *arr, int length)
        {
            MaxHeap(arr, length);
            for (int i = length - 1; i >= 0; i--)
            {
                Swap(&arr[0], &arr[i]);
                MaxHeap(arr, i);
            }
        }

        //O(n2)
        void BucketSort(string *arr, int length)
        {
            short int init_char = 0;
            short int end_char = 256;
            short int buckets_number = end_char - init_char;

            string **buckets;
            buckets = (string **)malloc(buckets_number * sizeof(string *));
            short int bucket_indexes[buckets_number];

            // initialize buckets
            for (int i = 0; i < buckets_number; i++)
            {
                buckets[i] = NULL;
                bucket_indexes[i] = 0;
            }

            // fill buckets
            for (int i = 0; i < length; i++)
            {
                short int bucket_index = (short int)arr[i].c_str()[0] - init_char;
                if (buckets[bucket_index] == NULL)
                {
                    buckets[bucket_index] = new string[100];
                }

                buckets[bucket_index][bucket_indexes[bucket_index]++] = arr[i];
            }

            // order each bucket, using quick sort, and add each item to original array
            int count = 0;
            for (int i = 0; i < buckets_number; i++)
            {
                if (buckets[i] != NULL)
                {
                    if (bucket_indexes[i] > 0)
                    {
                        QuickSort(buckets[i], 0, bucket_indexes[i]);
                    }

                    for (int j = 1; j <= bucket_indexes[i]; j++, count++)
                    {
                        cout << " adding " << buckets[i][j] << " to " << count << " j " << j << endl;
                        arr[count] = buckets[i][j];
                    }
                }
            }
        }

        //O(n+k), where n = number of items, and k = number of possible items
        // This means it is only fast when you have a limited set of items in relation to n.
        // Example: suppose you are working with 8-bits unsigned integers, they will span form 0 to 256, but you
        // you are expecting n to be much larger than 256, let's say 10,000. So big-O will be:
        // O(10,000 + 246), considerably smaller than O(N logN), for example
        // Now, if it is the other way around, the O(245 + 10,000), it would not be worthwhile: O(N logN) would be much faster.
        void CountSort(unsigned int arr[], unsigned int length)
        {
            int output[length];
            unsigned int count[255];

            // set count values to 0
            memset(count, 0, 255);

            for (unsigned int i = 0; i < length; i++)
            {
                count[arr[i]]++;
            }

            for (unsigned int i = 1; i < length; i++)
            {
                count[i] += count[i - 1];
            }

            for (unsigned int i = 0; i < length; i++)
            {
                output[count[arr[i]]-- - 1] = arr[i];
            }

            for (int i = 0; i < length; i++)
            {
                arr[i] = output[i];
            }
        }

        int Pow(int value, int exponent)
        {
            if (exponent == 0)
                return 1;

            for (int i = 1; i < exponent; i++)
            {
                value *= value;
            }

            return value;
        }

        void CountSort(int arr[], unsigned int length, int radix, int digit)
        {
            int output[length];
            int count_limit = radix + 1;
            int count[count_limit];

            for (int i = 0; i < count_limit; i++)
            {
                count[i] = 0;
            }

            for (unsigned int i = 0; i < length; i++)
            {
                count[((arr[i] / digit) % radix)]++;
            }

            for (unsigned int i = 1; i < count_limit; i++)
            {
                count[i] += count[i - 1];
            }

            for (int i = length - 1; i >= 0; i--)
            {
                output[count[(arr[i] / digit) % radix]-- - 1] = arr[i];
            }

            for (int i = 0; i < length; i++)
            {
                arr[i] = output[i];
            }
        }

        int GetMaxValue(int arr[], unsigned int len)
        {
            int max = arr[0];
            for (int i = 1; i < len; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }

            return max;
        }

        unsigned int GetDigits(int value, int radix)
        {
            unsigned int count = 0;
            while (value != 0)
            {
                value /= radix;
                count++;
            }

            return count;
        }

        // avg O(d*(n+k)), where d = max digits, n = number of items, k = number of possible numbers
        // It tends to be more efficient than other sorting algorithms, but it is not general purpose - it only works with numbers -
        // and does not use processor cache as efficiently as the others.
        void RadixSort(int arr[], unsigned int len, int radix = 10)
        {
            unsigned int max = GetMaxValue(arr, len);

            for (int i = 1; max / i > 0; i *= radix)
            {
                CountSort(arr, len, radix, i);
            }
        }

        // OK - Quick Sort
        // OK - Bubble Sort
        // OK - Merge Sort
        // OK - Insertion Sort
        // OK - Selection Sort
        // OK - Heap Sort
        // OK - Count Sort
        // Radix Sort
        // OK - Bucket Sort
    } // namespace Sorting
} // namespace Contoso
#endif