#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
public:
    List();
    ~List();

    int Get_Size() const { return size; } 
    void push_back(const T& data);
    void push_front(const T& data);
    void pop_front();
    void Insert(const T& value, const int index);
    void clear();
    T& operator [](const int index);

private:
    template <typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr) 
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node <T>* head;
    int size; 
};

template <typename T>
List <T>::List()
{
    size = 0;
    head = nullptr;
}
template <typename T>
List <T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(const T& data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}

template<typename T>
void List<T>::push_front(const T& data)
{
    head = new  Node<T>(data,head); 
    size++;
}

template<typename T>
void List<T>::pop_front()
{
    Node <T> *temp = head;
    head=head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::Insert(const T &value, const int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node <T>* temp = head;
        int counter = 0;
        while (counter != index - 1)
        {
            temp = temp->pNext;
            counter++;
        }
        temp->pNext = new Node <T>(value, temp->pNext);
    }
    size++;
}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    Node <T> *current = this->head;
    int counter=0;
    while (current!=nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        counter++;
        current=current->pNext;
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    List <int> lst;
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_front(4);
    lst.push_front(3);
    lst.push_front(2);
    lst.Insert(10, 0);
    for (int i = 0; i < lst.Get_Size(); i++)
        cout << lst[i] << " ";
    
    return 0;
}
