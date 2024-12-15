//Автор: Бородиенко Д.Т.
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include "unit136d.h"
using namespace std;
using namespace unit136d;


int main(void)
{
    srand(time(nullptr));
    int sum = 0;
    size_t n;
    cout << "Input n: ";
    cin >> n;
    vector<int> Vect(n, 0);
    double* numbers = new double[n];

    zapvect(n, Vect);
    //loadVectFromFile("text.txt", Vect, n);
    //loadArrayFromFile("text.txt", numbers, n);
    //zapmas(n, numbers);
    //zapmasrand(n, numbers);

    PrintVect(n, Vect);
    PrintSum(SumVect(n, sum, Vect));

    WrtVectTFile(n, Vect, "text.txt");


    return 0;
}