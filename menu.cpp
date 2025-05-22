#include <iostream>
#include "menu.hpp"
#include "rwFunc.hpp"
#include <iomanip>


using namespace std;

int displayData(InfoAboutLand *land, int currentRecord) {
    if (!currentRecord)
    {
        cerr << "\tДанные не загружены в программу. Нечего записывать в файл." << endl;
        return 1;
    }

    cout << "\t******************************************************************************" << endl;
    cout << "\t|" << setiosflags(ios::left) << setw(6) << "№"
         << "|" << setiosflags(ios::left) << setw(29) << "Кадастровый №"
         << "|" << setiosflags(ios::left) << setw(16) << "Площадь"
         << "|" << setiosflags(ios::left) << setw(36) << "Категория земли"
         << "|" << setiosflags(ios::left) << setw(15) << "Кадастровая стоимость" << "|" << endl;

    // Данные
    for (int i = 0; i < currentRecord; i++) {
        cout << "\t|" << setiosflags(ios::left) << setw(4) << land[i].number
             << "|" << setiosflags(ios::left) << setw(16) << land[i].cadastralNumber
             << "|" << setiosflags(ios::left) << setw(9) << land[i].area
             << "|" << setiosflags(ios::left) << setw(22) << land[i].categoryLand
             << "|" << setiosflags(ios::left) << setw(21) << land[i].cadastralValue << "|" << endl;
    }

    cout << "\t******************************************************************************" << endl;
    return 0;
}

int menu(InfoAboutLand *land, string FILE)
{
    int input;
    int currentRecord = 0;

    cout << "Выберите действие:" << endl;
    cout << "\t(1) Загрузить данные в программу" << endl;
    cout << "\t(2) Сохранить данные в файл" << endl;
    cout << "\t(3) Распечатать данные" << endl;
    cout << "\t(4) Просмотреть информацию о программе" << endl;
    cout << "\t(5) Выход" << endl;
    do
    {
        cout << "Ввод: ";
        cin >> input;
        cin.ignore();
        switch (input) {
        case 1:
            currentRecord = readFile(land, FILE);
            if (currentRecord != 1)
            {
                cout << "\tДанные успешно загружены!" << endl;
            }
            break;
        case 2:
            if (!writeToFile(land, "output.txt", currentRecord))
            {
                cout << "\tДанные успешно записаны в файл!" << endl;
            }
            break;
        case 3:
            displayData(land, currentRecord);
            break;
        case 4:
            cout << "\tПрограмма подготовлена студентом:" << endl;
            cout << "\tГерасимовым Максимом Сергеевичем, ИЦТМС 2-5" << endl;
            cout << "\tДата компиляции: " << __DATE__ << endl;
            break;
        default:
            break;
        }
    } while (1 <= input  && input <= 4);

    return 0;
}
