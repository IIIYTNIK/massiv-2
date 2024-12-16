//�����: ���������� �.�.

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
    //������� ��� ������ � ������ � ������ filename, ������� size
    template<typename T>
    void WrtMasTFile(size_t n, T* numbers, const string& filename) {
        ofstream outfile(filename); // ��������� ����

        if (!outfile.is_open()) {
            cerr << "Error`s open " << filename << endl;
            return;
        }
        outfile << n << " ";
        // ���������� �������� �������
        for (int i = 0; i < n; i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close();
    }

    //// ������� ��� �������� ������� �� ����� � ������ filename, ������� size 
    //template<typename T>
    //void loadArrayFromFile(size_t& size, T* numbers, const string& filename)
    //{
    //    ifstream infile(filename);
    //    if (infile.is_open())
    //    {
    //        infile >> size;
    //        //���� ������������ �������� �� ����� � ������
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
    // ������� ��� �������� ������� �� �����. ������� ���������� ������, ����� �������� ������.
    template <typename T>
    T* loadArrayFromFile(size_t& size, const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            throw runtime_error("������ �������� ����� ��� ������: " + filename);
        }

        infile >> size; // ��������� ������ �� ����� ������ �����

        T* arr = new T[size];
        for (size_t i = 0; i < size; ++i) {
            infile >> arr[i];
        }
        infile.close();
        return arr;
    }

    //������� ��������� ������� � ������
    template<typename T>
    void zapmas(size_t n, T* numbers) {
        double x;
        for (int i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] :";
            cin >> x;
            numbers[i] = x;
        }
    }

    //������� ���������� ������� ���������� �������
    template<typename T>
    void zapmasrand(size_t n, T* numbers) {
        for (int i = 0; i < n; i++)
        {
            numbers[i] = rand() % 100;
        }
        cout << " ";
    }

    //������� �������� ����� ������� ��������� ������� a1^2 + ... + an^2;
    template<typename T>
    T SumArray(size_t n, T& sum, const T* numbers) {
        for (int i = 0; i < n; i++)
        {
            sum += pow(numbers[i], 2);
        }
        return sum;
    }

    //������� ������ �������
    template<typename T>
    void PrintArray(size_t& n, T* numbers) {
        n = sizeof(numbers) / sizeof(numbers[0]);
        for (size_t i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << numbers[i] << "\n";
        }
    }

    //������� ��� ������ �����
    template<typename T>
    void PrintSum(T sum) {

        cout << "Sum = " << sum << "\n";

    }


    //������� ��� ��������� ������� �������
    template<typename T>
    void zapvect(size_t n, std::vector<T>& vect) {
        double x;
        for (int i = 0; i < n; i++) {
            cout << "Input mas[" << i << "] : ";
            cin >> x;
            vect[i] = x;
        }
    }

    //������� ��� ���������� ������� ���������� ����������
    template<typename T>
    void zapvectrand(size_t n, vector<T>& vect) {
        for (int i = 0; i < n; i++)
        {
            vect[i] = rand() % 100;
        }
        cout << " ";
    }

    //������� ��� ����� �������
    template<typename T>
    T SumVect(size_t n, T& sum, vector<T> vect) {
        for (int i = 0; i < n; i++)
        {
            sum += pow(vect[i], 2);
        }
        return sum;
    }

    //������� ��� ������ �������
    template<typename T>
    void PrintVect(size_t n, std::vector<T> vect) {
        for (int i = 0; i < n; i++) {
            cout << "mas[" << i << "] = " << vect[i] << "\n";
        }
    }

    //������� ��� ������ � ���� ���������
    template<typename T>
    void WrtVectTFile(size_t& n, std::vector<T>& vect, const string& filename) {
        ofstream outfile(filename); // ��������� ����

        if (!outfile.is_open()) {
            cerr << "Error`s open " << filename << endl;
            return;
        }
        outfile << n << " ";
        // ���������� �������� �������
        for (int i = 0; i < n; i++) {
            outfile << vect[i] << " ";
        }

        outfile.close();
    }

    // ������� ��� �������� ������� �� ����� � ������ filename, ������� size
    template<typename T>
    void loadVectFromFile(size_t& size, std::vector<T>& vect, const string& filename) {
        size = vect.size();
        ifstream infile(filename);
        if (infile.is_open())
        {
            infile >> size;
            //���� ������������ �������� �� ����� � ������
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


    // ���� ������� �������� ����� ��������� �������
    void testSumArray();

    // ���� ������� �������� ����� ��������� �������
    void testSumVect();

    // �������� ���������� � �������� �������
    void testSaveAndLoadVect();

    // ������� ������� ������
    void testall();
}
#endif