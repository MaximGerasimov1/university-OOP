#include "rwFunc.hpp"
#include <iostream>
#include <vector>
#include <sstream> // для stringstream
#include <fstream> // для ifstream, ofstream

using namespace std;

int readFile(InfoAboutLand *land, string file) {
    string line;
    int currentRecord = 0;

    ifstream inputFile;
    inputFile.open(file);

    if (!inputFile.is_open()) {
        cerr << "Ошибка при открытии файла" << endl;
        return 1;
    }

    // Получаем строчку из файла с данными
    while(getline(inputFile, line)) {
        //  Конвертируем строку line в поток, создаём динамический массив fields
        vector<string> fields;
        stringstream line_flow(line);
        string field;

        // Извлекаем из текущей строки данные поочередёно, добавляя их в динамический массив fields
        while (getline(line_flow, field, ';')) {
            if (!field.empty()) {
                fields.push_back(field);
            }
        }

        if (fields.size() == 5) {
            land[currentRecord].number = stoi(fields[0]); // stoi(string to integer) - перевод переменной из строкового типа в целочисленный
            land[currentRecord].cadastralNumber = fields[1];
            land[currentRecord].area = stod(fields[2]); // stod(string to double) - перевод переменной из строкового типа в тип с плавающей запятой
            land[currentRecord].categoryLand = fields[3];
            land[currentRecord].cadastralValue = stod(fields[4]); // stod(string to double) - перевод переменной из строкового типа в тип с плавающей запятой
            currentRecord++;
        }
    }

    inputFile.close();
    return currentRecord;
}

int writeToFile(InfoAboutLand *land, string file, int currentRecord) {
    if (!currentRecord) {
        cerr << "\tДанные не загружены в программу. Нечего записывать в файл." << endl;
        return 1;
    }

    ofstream outputFile;
    outputFile.open(file);

    if (!outputFile.is_open()) {
        cerr << "Ошибка при открытии файла" << endl;
        return 1;
    }

    if (!currentRecord)
    {
        cerr << "\tДанные не загружены в программу. Нечего записывать в файл." << endl;
        return 1;
    }

    for (int i = 0; i < currentRecord; i++) {
        outputFile << land[i].number << ";"
             << land[i].cadastralNumber << ";"
             << land[i].area << ";"
             << land[i].categoryLand << ";"
             << land[i].cadastralValue << ";\n";
    }

    outputFile.close();
    return 0;
}
