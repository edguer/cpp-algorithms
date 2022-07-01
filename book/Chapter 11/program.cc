#include <bits/stdc++.h>
#include "bsort.hh"
#include "qsort.hh"
#include "msort.hh"
#include "bcsort.hh"
#include "csort.hh"

using namespace std;

int main()
{
    int arr[] = {6, 0, 7, 5, 7, 8, 7, 6, 7, 5, 4, 1, 1, 0, 2, 1, 0, 5, 8, 6, 4};
    unsigned int len = sizeof(arr) / sizeof(int);
    contoso::print(arr, len);
    // contoso::bsort(arr, len);
    // contoso::qsort(arr, len);
    // contoso::msort(arr, len);
    // contoso::bcsort(arr, len, 0, 1000);
    contoso::csort(arr, len, 0, 10);
    contoso::print(arr, len);
}