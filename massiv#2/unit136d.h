//�����: ���������� �.�.

#ifndef UNIT136_H
#define UNIT136_H

#include <iostream>
#include <vector>
#include <ctime> // ��� rand()
#include <cmath> // ��� pow()
#include <fstream> // ��� ������ � �������
#include <string> // ��� ������ �� ��������
#include <stdexcept> // ��� ��������� ����������


namespace unit136d {
    using namespace std;

    // ������� ��� ������ ������� � ����. ��������� ������ ������� size_t size, ������, � ������ filename
    template<typename T>
    void WrtMasTFile(size_t n, T* numbers, const string& filename) {
        ofstream outfile(filename); // ������� ����� ��� ������ � ����

        if (!outfile.is_open()) { // �������� ��������� �������� �����
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        outfile << n << " "; // ���������� ������ �������

        // ���������� �������� ������� � ����
        for (size_t i = 0; i < n; i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close(); // ��������� ����
    }

    // ������� ��� �������� ������� �� �����. ��������� ������ ������� size_t size, � ������ filename
    template <typename T>
    T* loadArrayFromFile(size_t& size, const string& filename) {
        ifstream infile(filename); // ������� ����� ��� ������ �� �����

        if (!infile.is_open()) { // �������� ��������� �������� �����
            throw runtime_error("Error opening file for reading: " + filename);
        }

        infile >> size; // ��������� ������ ������� �� �����

        T* arr = new T[size]; // �������� ������ ��� �������

        // ��������� �������� ������� �� �����
        for (size_t i = 0; i < size; ++i) {
            infile >> arr[i];
        }
        infile.close(); // ��������� ����
        return arr;
    }

    /// ������� ��� ������� ���������� �������. ��������� ������ ������� size_t n, ������
    template<typename T>
    void fillarray(size_t n, T* numbers) {
        double x;
        for (size_t i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] :";
            cin >> x;
            numbers[i] = x;
        }
    }

    /// ������� ��� ���������� ������� ���������� �������. ��������� ������ ������� size_t n, ������
    template<typename T>
    void fillarrayrand(size_t n, T* numbers) {
        for (size_t i = 0; i < n; i++) {
            numbers[i] = rand() % 100; // ��������� ����� �� 0 �� 99
        }
        cout << " ";
    }

    /// ������� ��� ���������� ����� ��������� ��������� �������. ��������� ������ ������� size_t n, ����� sum, ������
    template<typename T>
    T SumArray(size_t n, const T* numbers) {
        double sum;
        sum = 0; // �������������� �����
        for (size_t i = 0; i < n; i++) {
            sum += pow(numbers[i], 2); // ��������� �������� ���������
        }
        return sum;
    }

    /// ������� ��� ������ ������� �� �����. ��������� ������ ������� size_t n, ������
    template<typename T>
    void PrintArray(size_t& n, T* numbers) {
        // n = sizeof(numbers) / sizeof(numbers[0]); // ��� ������ �����������! sizeof(numbers) ������ ������ ���������, � �� ������ �������.
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << numbers[i] << "\n";
        }
    }

    /// ������� ��� ������ ����� �� �����. ��������� �����
    template<typename T>
    void PrintSum(T sum) {
        cout << "Sum = " << sum << "\n";
    }


    /// ������� ��� ������� ���������� �������, ��������� ������ ������� size_t n, ������
    template<typename T>
    void fillvect(size_t n, std::vector<T>& vect) {
        double x;
        for (size_t i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] : ";
            cin >> x;
            vect[i] = x;
        }
    }

    /// ������� ��� ���������� ������� ���������� �������. ��������� ������ size_t n � ������ 
    template<typename T>
    void fillvectrand(size_t n, vector<T>& vect) {
        for (size_t i = 0; i < n; i++) {
            vect[i] = rand() % 100; // ��������� ����� �� 0 �� 99
        }
        cout << " ";
    }

    /// ������� ��� ���������� ����� ��������� ��������� �������. ��������� ������ ������� size_t n � ������ vect
    template<typename T>
    T SumVect(size_t n, vector<T> vect) {
        double sum;
        sum = 0; // �������������� �����
        for (size_t i = 0; i < n; i++) {
            sum += pow(vect[i], 2); // ��������� �������� ���������
        }
        return sum;
    }
    
    /// ������� ��� ������ ������� �� �����, ��������� ������ n � ������
    template<typename T>
    void PrintVect(size_t n, std::vector<T> vect) {
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << vect[i] << "\n";
        }
    }

    /// ������� ��� ������ ������� � ���� �������� size_t n, � ������ filename
    template<typename T>
    void WrtVectTFile(size_t& n, std::vector<T>& vect, const string& filename) {
        ofstream outfile(filename); // ������� ����� ��� ������ � ����

        if (!outfile.is_open()) { // �������� ��������� �������� �����
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        outfile << n << " "; // ���������� ������ �������

        // ���������� �������� ������� � ����
        for (size_t i = 0; i < n; i++) {
            outfile << vect[i] << " ";
        }

        outfile.close(); // ��������� ����
    }

    /// ������� ��� �������� ������� �� ����� � ������ filename, ������� size_t size
    template<typename T>
    void loadVectFromFile(size_t& size, std::vector<T>& vect, const string& filename) {
        ifstream infile(filename); // ��������� ���� ��� ������

        if (infile.is_open()) { // ���������, ������� �� ������ ����
            infile >> size; // ��������� ������ ������� �� �����

            // ������������� ������ �������, ���� �� �� ������������� ������� �� ����� (��� ����� ���� �������, ���� ������ ��� �������������� ������, �� ��� ������ ����� ��������)
            vect.resize(size);

            // ���� ��� ���������� ��������� ������� �� �����
            for (size_t i = 0; i < size; ++i) {
                infile >> vect[i]; // ��������� i-� ������� ������� �� �����
            }
            infile.close(); // ��������� ����
        }
        else {
            throw runtime_error("Error opening file for reading: " + filename); // ����������� ����������, ���� ���� �� ������� �������
        }
    }


    /// ���� ������� �������� ����� ��������� �������
    void testSumArray();

    /// ���� ������� �������� ����� ��������� �������
    void testSumVect();

    /// �������� ���������� � �������� �������
    void testSaveAndLoadVect();

    /// ������� ������� ������
    void testall();
}
#endif