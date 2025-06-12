#include "Header.h"

//функция проверки символов на допустимость
void Calculator::ValidateExpression(const string& ex) 
{
    for (char c:ex)
    {
        // Проверяем каждый символ на допустимость
        if (!isdigit(c)&&c!='m'&&c!='M'&&c!='('&&c!=')'&&c!=',') 
        {
            throw invalid_argument("Недопустимый символ в выражении.");
        }
    }
}
//функция вычисления выражения
int Calculator::Evaluate(const string& ex) 
{
    ValidateExpression(ex); 
    return EvaluateExpression(ex);
}
//реализует вычислитель выражения
int Calculator::EvaluateExpression(const string& ex) 
{
    stack<int> v; // Стек для хранения целых чисел
    stack<char> ops;   // Стек для хранения операций

    for (size_t i = 0; i < ex.length(); i++) 
    {
        char c = ex[i];

        if (isdigit(c)) {
            // Если текущий символ - цифра, собираем число
            int n = 0;
            while (i<ex.length()&&isdigit(ex[i])) 
            {
                n=n * 10 + (ex[i] - '0');
                i++;
            }
            v.push(n);
            i--; 
        }
       
        else if (c == 'm' || c == 'M') 
        {   
            ops.push(c); 
            if (ex[i + 1] != '(') 
            {
                throw invalid_argument("Синтаксическая ошибка. Ожидался '(' после операции.");
            }
            i++; // Пропускаем '('
        }
        else if (c == ')') 
        {
            // Вычисляем результат для последней операции
            if (ops.empty()) {
                throw invalid_argument("Синтаксическая ошибка. Нет операции для выполнения.");
            }

            char op = ops.top();
            ops.pop();

            // Проверяем, что в стеке достаточно значений
            if (v.size() < 2)
            {
                throw invalid_argument("Недостаточно аргументов для операции.");
            }
            int b = v.top(); v.pop(); 
            int a = v.top(); v.pop(); 

            // Вычисляем минимум
            if (op == 'm') 
            {
                v.push(min(a, b)); 
            }
            // Вычисляем максимум
            else if (op == 'M') 
            {
                v.push(max(a, b));
            }
        }
    }
    if (v.size() != 1) {
        throw logic_error("Ошибка при вычислении выражения.");
    }

    return v.top(); 
}



