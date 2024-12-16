//Автор: Бородиенко Д.Т.

#ifndef UNIT136_H
#define UNIT136_H
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <fstream>
#include <string>

namespace unit136d {
    using namespace std;
    //функция для записи в массив с именем filename, размера size
    template<typename T>
    void WrtMasTFile(size_t n, T* numbers, const string& filename) {
        ofstream outfile(filename); // Открываем файл

        if (!outfile.is_open()) {
            cerr << "Error`s open " << filename << endl;
            return;
        }
        outfile << n << " ";
        // Записываем элементы массива
        for (int i = 0; i < n; i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close();
    }

    //// Функция для загрузки массива из файла с именем filename, размера size 
    //template<typename T>
    //void loadArrayFromFile(size_t& size, T* numbers, const string& filename)
    //{
    //    ifstream infile(filename);
    //    if (infile.is_open())
    //    {
    //        infile >> size;
    //        //цикл переписывает значения из файла в массив
    //        for (size_t i = 0; i < size; ++i)
    //        {
    //            infile >> numbers[i];
    //        }
    //        infile.close();
    //    }
    //    else
    //    {
    //        throw runtime_error("Error`s open file for reading: " + filename);
    //    }
    //}
    // Функция для загрузки массива из файла. Сначала определяем размер, потом выделяем память.
    template <typename T>
    T* loadArrayFromFile(size_t& size, const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            throw runtime_error("Ошибка открытия файла для чтения: " + filename);
        }

        infile >> size; // Считываем размер из файла ПЕРВЫМ делом

        T* arr = new T[size];
        for (size_t i = 0; i < size; ++i) {
            infile >> arr[i];
        }
        infile.close();
        return arr;
    }

    //функция заполения массива в ручную
    template<typename T>
    void zapmas(size_t n, T* numbers) {
        double x;
        for (int i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] :";
            cin >> x;
            numbers[i] = x;
        }
    }

    //функция заполнения массива случайными числами
    template<typename T>
    void zapmasrand(size_t n, T* numbers) {
        for (int i = 0; i < n; i++)
        {
            numbers[i] = rand() % 100;
        }
        cout << " ";
    }

    //формула подсчёта суммы массива использую формулу a1^2 + ... + an^2;
    template<typename T>
    T SumArray(size_t n, T& sum, const T* numbers) {
        for (int i = 0; i < n; i++)
        {
            sum += pow(numbers[i], 2);
        }
        return sum;
    }

    //функция вывода массива
    template<typename T>
    void PrintArray(size_t& n, T* numbers) {
        n = sizeof(numbers) / sizeof(numbers[0]);
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << numbers[i] << "\n";
        }
    }

    //функция для вывода суммы
    template<typename T>
    void PrintSum(T sum) {

        cout << "Sum = " << sum << "\n";

    }


    //функция для заполения вектора вручную
    template<typename T>
    void zapvect(size_t n, std::vector<T>& vect) {
        double x;
        for (int i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] : ";
            cin >> x;
            vect[i] = x;
        }
    }

    //функция для заполнения вектора случайными значениями
    template<typename T>
    void zapvectrand(size_t n, vector<T>& vect) {
        for (int i = 0; i < n; i++)
        {
            vect[i] = rand() % 100;
        }
        cout << " ";
    }

    //функция для суммы вектора
    template<typename T>
    T SumVect(size_t n, T& sum, vector<T> vect) {
        for (int i = 0; i < n; i++)
        {
            sum += pow(vect[i], 2);
        }
        return sum;
    }

    //функция для вывода вектора
    template<typename T>
    void PrintVect(size_t n, std::vector<T> vect) {
        for (int i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << vect[i] << "\n";
        }
    }

    //функция для записи в файл извектора
    template<typename T>
    void WrtVectTFile(size_t& n, std::vector<T>& vect, const string& filename) {
        ofstream outfile(filename); // Открываем файл

        if (!outfile.is_open()) {
            cerr << "Error`s open " << filename << endl;
            return;
        }
        outfile << n << " ";
        // Записываем элементы массива
        for (int i = 0; i < n; i++) {
            outfile << vect[i] << " ";
        }

        outfile.close();
    }

    // Функция для загрузки вектора из файла с именем filename, размера size
    template<typename T>
    void loadVectFromFile(size_t& size, std::vector<T>& vect, const string& filename) {
        size = vect.size();
        ifstream infile(filename);
        if (infile.is_open())
        {
            infile >> size;
            //цикл переписывает значения зи файла в массив
            for (size_t i = 0; i < size; ++i)
            {

                infile >> vect[i];
            }
            infile.close();
        }
        else
        {
            throw runtime_error("Error`s open file for reading: " + filename);
        }
    }


    // Тест функции подсчёта суммы элементов массива
    void testSumArray();

    // Тест функции подсчёта суммы элементов вектора
    void testSumVect();

    // Проверка сохранения и загрузки вектора
    void testSaveAndLoadVect();

    // Функция запуска тестов
    void testall();
}
#endif