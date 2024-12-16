//Автор: Бородиенко Д.Т.

#ifndef UNIT136_H
#define UNIT136_H

#include <iostream>
#include <vector>
#include <ctime> // для rand()
#include <cmath> // для pow()
#include <fstream> // для работы с файлами
#include <string> // для работы со строками
#include <stdexcept> // для обработки исключений


namespace unit136d {
    using namespace std;

    // Функция для записи массива в файл. Передаётся размер массива size_t size, массив, с именем filename
    template<typename T>
    void WrtMasTFile(size_t n, T* numbers, const string& filename) {
        ofstream outfile(filename); // Создаем поток для записи в файл

        if (!outfile.is_open()) { // Проверка успешного открытия файла
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        outfile << n << " "; // Записываем размер массива

        // Записываем элементы массива в файл
        for (size_t i = 0; i < n; i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close(); // Закрываем файл
    }

    // Функция для загрузки массива из файла. Передаётся размер массива size_t size, с именем filename
    template <typename T>
    T* loadArrayFromFile(size_t& size, const string& filename) {
        ifstream infile(filename); // Создаем поток для чтения из файла

        if (!infile.is_open()) { // Проверка успешного открытия файла
            throw runtime_error("Error opening file for reading: " + filename);
        }

        infile >> size; // Считываем размер массива из файла

        T* arr = new T[size]; // Выделяем память для массива

        // Считываем элементы массива из файла
        for (size_t i = 0; i < size; ++i) {
            infile >> arr[i];
        }
        infile.close(); // Закрываем файл
        return arr;
    }

    /// Функция для ручного заполнения массива. Передаётся размер массива size_t n, массив
    template<typename T>
    void fillarray(size_t n, T* numbers) {
        double x;
        for (size_t i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] :";
            cin >> x;
            numbers[i] = x;
        }
    }

    /// Функция для заполнения массива случайными числами. Передаётся размер массива size_t n, массив
    template<typename T>
    void fillarrayrand(size_t n, T* numbers) {
        for (size_t i = 0; i < n; i++) {
            numbers[i] = rand() % 100; // Случайное число от 0 до 99
        }
        cout << " ";
    }

    /// Функция для вычисления суммы квадратов элементов массива. Передаётся размер массива size_t n, сумма sum, массив
    template<typename T>
    T SumArray(size_t n, const T* numbers) {
        double sum;
        sum = 0; // Инициализируем сумму
        for (size_t i = 0; i < n; i++) {
            sum += pow(numbers[i], 2); // Суммируем квадраты элементов
        }
        return sum;
    }

    /// Функция для вывода массива на экран. Передаётся размер массива size_t n, массив
    template<typename T>
    void PrintArray(size_t& n, T* numbers) {
        // n = sizeof(numbers) / sizeof(numbers[0]); // Эта строка НЕКОРРЕКТНА! sizeof(numbers) вернет размер указателя, а не размер массива.
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << numbers[i] << "\n";
        }
    }

    /// Функция для вывода суммы на экран. Передаётся сумма
    template<typename T>
    void PrintSum(T sum) {
        cout << "Sum = " << sum << "\n";
    }


    /// Функция для ручного заполнения вектора, передаётся размер вектора size_t n, вектор
    template<typename T>
    void fillvect(size_t n, std::vector<T>& vect) {
        double x;
        for (size_t i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] : ";
            cin >> x;
            vect[i] = x;
        }
    }

    /// Функция для заполнения вектора случайными числами. Передаётся размер size_t n и вектор 
    template<typename T>
    void fillvectrand(size_t n, vector<T>& vect) {
        for (size_t i = 0; i < n; i++) {
            vect[i] = rand() % 100; // Случайное число от 0 до 99
        }
        cout << " ";
    }

    /// Функция для вычисления суммы квадратов элементов вектора. передаётся размер вектора size_t n и вектор vect
    template<typename T>
    T SumVect(size_t n, vector<T> vect) {
        double sum;
        sum = 0; // Инициализируем сумму
        for (size_t i = 0; i < n; i++) {
            sum += pow(vect[i], 2); // Суммируем квадраты элементов
        }
        return sum;
    }
    
    /// Функция для вывода вектора на экран, передаётся размер n и вектор
    template<typename T>
    void PrintVect(size_t n, std::vector<T> vect) {
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << vect[i] << "\n";
        }
    }

    /// Функция для записи вектора в файл размером size_t n, с именем filename
    template<typename T>
    void WrtVectTFile(size_t& n, std::vector<T>& vect, const string& filename) {
        ofstream outfile(filename); // Создаем поток для записи в файл

        if (!outfile.is_open()) { // Проверка успешного открытия файла
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        outfile << n << " "; // Записываем размер вектора

        // Записываем элементы вектора в файл
        for (size_t i = 0; i < n; i++) {
            outfile << vect[i] << " ";
        }

        outfile.close(); // Закрываем файл
    }

    /// Функция для загрузки вектора из файла с именем filename, размера size_t size
    template<typename T>
    void loadVectFromFile(size_t& size, std::vector<T>& vect, const string& filename) {
        ifstream infile(filename); // Открываем файл для чтения

        if (infile.is_open()) { // Проверяем, успешно ли открыт файл
            infile >> size; // Считываем размер вектора из файла

            // Устанавливаем размер вектора, если он не соответствует размеру из файла (это может быть полезно, если вектор был предварительно создан, но его размер нужно изменить)
            vect.resize(size);

            // Цикл для считывания элементов вектора из файла
            for (size_t i = 0; i < size; ++i) {
                infile >> vect[i]; // Считываем i-й элемент вектора из файла
            }
            infile.close(); // Закрываем файл
        }
        else {
            throw runtime_error("Error opening file for reading: " + filename); // Выбрасываем исключение, если файл не удалось открыть
        }
    }


    /// Тест функции подсчёта суммы элементов массива
    void testSumArray();

    /// Тест функции подсчёта суммы элементов вектора
    void testSumVect();

    /// Проверка сохранения и загрузки вектора
    void testSaveAndLoadVect();

    /// Функция запуска тестов
    void testall();
}
#endif