#include "Header.h"
using namespace std; 

int main() 
{
    setlocale(LC_ALL, "rus");
    Calculator evaluator;
    string ex;

    cout << "Введите выражение: ";
    cin >> ex;
    
    try 
    {
        int res = evaluator.Evaluate(ex);
        cout << "Результат: " << res << endl;
    }

    catch (const exception& e) 
    {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

