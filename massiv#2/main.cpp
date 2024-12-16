//Автор: Бородиенко Д.Т.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "unit136d.h"
using namespace std;
using namespace unit136d;


int main(void)
{
    testall();// Вызов тестовых функций
    cout << "Input n: ";
    size_t n;
    std::cin >> n;
    char choise;// Переменная для выбора действия пользователя
    double* numbers = nullptr;


    //блок try, в котором будут обрабатываться возможные исключения.
    try {
        // Запрос пользователю выбрать работу с массивом или вектором
        cout << "Work this array(a) or work this vector(v)\n";
        std::cin >> choise;
        if (choise != 'a' and choise != 'v') {// Проверка на корректность ввода
            throw string("Incorrect Input");
        }
        else {
            switch (choise) {
            case 'a': {// Работа с массивом
                cout << "Load array from file(f) or manually fill(m)?\n"; // Запрос пользователю выбрать способ заполнения массива
                std::cin >> choise;
                if (choise != 'f' and choise != 'm') {// Проверка на корректность ввода
                    throw string("Incorrect Input");
                }
                switch (choise)
                {
                case 'f': {// Загрузка массива из файла
                    cout << "Input File name" << "\n";
                    string filename;
                    std::cin >> filename;

                    double sum = 0;
                    double* numbers = loadArrayFromFile<double>(n, filename);// Загружаем массив из файла
                    PrintArray(n, numbers);
                    PrintSum(SumArray(n, sum, numbers));
                    WrtMasTFile(n, numbers, filename);// Записываем массив обратно в файл
                    delete[] numbers; // Освобождаем память, выделенную под массив
                    numbers = nullptr; // Обнуляем указатель
                    break;
                }
                case 'm': { // Ручное заполнение массива
                    numbers = new double[n];
                    zapmas(n, numbers);
                    double sum = 0;
                    string filename = "text.txt";
                    PrintSum(SumArray(n, sum, numbers));
                    WrtMasTFile(n, numbers, filename);
                    delete[] numbers; // Освобождаем память, выделенную под массив
                    numbers = nullptr; // Обнуляем указатель
                    break;
                }
                }
                break;
            }

            case 'v': { // Работа с вектором
                cout << "Load vector from file (f) or manually fill (m)?\n";
                std::cin >> choise;
                if (choise != 'f' && choise != 'm') {
                    throw string("Incorrect input. Choose 'f' or 'm'.");
                }
                switch (choise) {
                case 'f': { // Загрузка вектора из файла
                    vector<double> Vect(n, 0);
                    string filename;
                    cout << "Input File name: \n";
                    std::cin >> filename;

                    double sum = 0;
                    loadVectFromFile(n, Vect, filename); // Загружаем вектор из файла
                    PrintVect(n, Vect); // Выводим вектор на экран
                    PrintSum(SumVect(n, sum, Vect)); // Выводим сумму элементов вектора
                    WrtVectTFile(n, Vect, filename); // Записываем вектор в файл
                    break;
                }
                case 'm': { // Ручное заполнение вектора
                    vector<double> Vect(n, 0);
                    zapvect(n, Vect); // Заполняем вектор
                    double sum = 0;
                    string filename = "text.txt";
                    PrintSum(SumVect(n, sum, Vect)); // Выводим сумму элементов вектора
                    WrtVectTFile(n, Vect, filename); // Записываем вектор в файл
                    break;
                }
                }
                break;
            }
            }
        }
    }
    catch (const exception& ex) {
        //Выводит сообщение об ошибке в стандартный поток ошибок, включая текст ошибки.
        cerr << "Error: " << ex.what() << endl;
        //Проверяет, был ли выделен массив arr
        if (numbers) {
            delete[] numbers;
        }
        return 1;
    }
    catch (const std::string& error_message) {
        cout << error_message << endl;
        return 1;
    }
    return 0;
}