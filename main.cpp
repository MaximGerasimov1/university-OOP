#include "rwFunc.hpp"
#include "menu.hpp"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);  // Вывод
    SetConsoleCP(65001);        // Ввод
    setlocale(LC_ALL, "ru_RU.UTF-8");  // Дополнительно
    const int MAX_COUNT = 10;
    InfoAboutLand land[MAX_COUNT];
    const string FILE = "C:\\Users\\User\\Desktop\\Cadastral_registration_of_land\\earth_en.db";

    menu(land, FILE);

    return 0;
}
