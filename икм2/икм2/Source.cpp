#include "Header.h"

//������� �������� �������� �� ������������
void Calculator::ValidateExpression(const string& ex) 
{
    for (char c:ex)
    {
        // ��������� ������ ������ �� ������������
        if (!isdigit(c)&&c!='m'&&c!='M'&&c!='('&&c!=')'&&c!=',') 
        {
            throw invalid_argument("������������ ������ � ���������.");
        }
    }
}
//������� ���������� ���������
int Calculator::Evaluate(const string& ex) 
{
    ValidateExpression(ex); 
    return EvaluateExpression(ex);
}
//��������� ����������� ���������
int Calculator::EvaluateExpression(const string& ex) 
{
    stack<int> v; // ���� ��� �������� ����� �����
    stack<char> ops;   // ���� ��� �������� ��������

    for (size_t i = 0; i < ex.length(); i++) 
    {
        char c = ex[i];

        if (isdigit(c)) {
            // ���� ������� ������ - �����, �������� �����
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
                throw invalid_argument("�������������� ������. �������� '(' ����� ��������.");
            }
            i++; // ���������� '('
        }
        else if (c == ')') 
        {
            // ��������� ��������� ��� ��������� ��������
            if (ops.empty()) {
                throw invalid_argument("�������������� ������. ��� �������� ��� ����������.");
            }

            char op = ops.top();
            ops.pop();

            // ���������, ��� � ����� ���������� ��������
            if (v.size() < 2)
            {
                throw invalid_argument("������������ ���������� ��� ��������.");
            }
            int b = v.top(); v.pop(); 
            int a = v.top(); v.pop(); 

            // ��������� �������
            if (op == 'm') 
            {
                v.push(min(a, b)); 
            }
            // ��������� ��������
            else if (op == 'M') 
            {
                v.push(max(a, b));
            }
        }
    }
    if (v.size() != 1) {
        throw logic_error("������ ��� ���������� ���������.");
    }

    return v.top(); 
}



