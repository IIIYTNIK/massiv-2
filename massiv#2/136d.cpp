//Автор: Бородиенко Д.Т.

#include <iostream>
#include <cassert>
#include <vector>
#include <time.h>
#include <cmath>
#include <fstream>
#include "unit136d.h"
using namespace std;


namespace unit136d {

    // Тест функции подсчёта суммы элементов массива
    void testSumArray() {
        int arr[] = { 1, 2, 3 };
        int result = SumArray(3, arr);
        assert(result == 1 * 1 + 2 * 2 + 3 * 3); // 1*1 + 2*2 + 3*3 = 14

        double arr2[] = { 1.1, 2.2, 3.3 };
        double result2 = SumArray(3, arr2);
        assert(fabs(result2 - (1.1 * 1.1 + 2.2 * 2.2 + 3.3 * 3.3)) < 1e-9); // Проверка с плавающей точкой
    }

    // Тест функции подсчёта суммы элементов вектора
    void testSumVect() {
        std::vector<int> vect = { 1, 2, 3 };
        int sum = 0;
        int result = SumVect(3, vect);
        assert(result == 14);

        std::vector<double> vect2 = { 1.1, 2.2, 3.3 };
        double sum2 = 0;
        double result2 = SumVect(3, vect2);
        assert(fabs(result2 - (1.1 * 1.1 + 2.2 * 2.2 + 3.3 * 3.3)) < 1e-9);
    }

    // Проверка сохранения и загрузки вектора
    void testSaveAndLoadVect() {
        vector<double> vec = { 1.0, 2.0, 3.0 };
        string filename = "test_output.txt";
        size_t n = 3;

        // Сохранение массива в текстовый файл и чтение из него
        WrtVectTFile(n, vec, "test_output.txt");
        vector<double> loadedVec(n, 0);
        loadVectFromFile(n, loadedVec, "test_output.txt");

        assert(vec == loadedVec); // Проверяем, что загруженные данные совпадают с сохраненными

        // Дополнительные проверки
        vector<double> vec2 = { 4.0, 5.0, 6.0 };
        size_t s = 3;
        string filename2 = "test_output2.txt";
        WrtVectTFile(s, vec2, "test_output2.txt");
        vector<double> loadedVec2(s, 0);
        loadVectFromFile(s, loadedVec2, "test_output2.txt");
        assert(vec2 == loadedVec2); // Проверяем, что загруженные данные совпадают с сохраненными

    }

    // Проверка сохранения и загрузки вектора
    void testSaveAndLoadArray() {
        size_t n = 3;
        double* numbers = new double[n] { 1.0, 2.0, 3.0 };
        string filename = "test_output.txt";
        

        // Сохранение массива в текстовый файл и чтение из него
        WrtMasTFile(n, numbers, "test_output.txt");
        double* loadedmas = loadArrayFromFile<double>(n, "test_output.txt");

        assert(numbers == loadedmas); // Проверяем, что загруженные данные совпадают с сохраненными

        // Дополнительные проверки
        size_t s = 3;
        double* mas2 = new double[s] { 4.0, 5.0, 6.0 };
        string filename2 = "test_output2.txt";
        WrtMasTFile(s, mas2, "test_output2.txt");
        double* loadedmas2 = loadArrayFromFile<double>(s, "test_output2.txt");
        assert(mas2 == loadedmas2); // Проверяем, что загруженные данные совпадают с сохраненными

    }


    // Функция запуска тестов
    void testall() {
        testSumArray();
        testSumVect();
        testSaveAndLoadVect();
    }
}