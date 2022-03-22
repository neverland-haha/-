#include<iostream>
#include<vector>
#include<CASSERT>
using namespace std;

template<typename T>class Stack
{
public:
    vector<T> value;
    T m_min;
public:
    const T& min();
    void pop();
    void push(const T &n);
    void printValue();
    bool isEmpty();

};

/**********��ȡ��С��ֵ********/
template<typename T>const T& Stack<T>::min()
{
    assert(!value.empty());
    return m_min;
}

/*********���� push ����*******/
template<typename T>void Stack<T>::push(const T&n)
{
    if(value.empty())
        m_min = n;
    // ����ǿ�
    T diff = n - m_min;
    value.push_back(diff);
    if(diff < 0)
        m_min = n;
}
/*********���� top ����********/
template<typename T>void Stack<T>::pop()
{
    assert(!value.empty());
    T top = value.back();
    if(top < 0)
        m_min -= top;
    value.pop_back();
}
/*********���ջ��ֵ********/
template<typename T>void Stack<T>::printValue()
{
    assert(!value.empty());
    T originalValue;
    T top = value.back();
    if(top < 0)
        originalValue = m_min;
    else
        originalValue = (top + m_min);
    cout <<  originalValue;
}
/*********�жϺ��� isempty ջ�Ƿ�Ϊ��********/
template<typename T>bool Stack<T>::isEmpty()
{
    if(value.empty())
    {
        return true;
    }else
    {
        return false;
    }
}

int main()
{
    Stack<int> stack;
    int b[] = {6,8,15,2,3,1,2};
    for(int i = 0;i < 7;i++)
    {
        cout << "��ջ��ֵ: " << b[i] << " ";
        stack.push(b[i]);
        cout << "��ǰջ����СֵΪ:  " << stack.min() << endl;
    }
    cout << "��ջ��� " << endl;
    while(!stack.isEmpty())
    {
        cout << "��ջֵ: " << " ";
        stack.printValue();
        cout << " ��ǰ��Сֵmin: " << stack.min() <<endl;
        stack.pop();
    }
    return 0;
}
