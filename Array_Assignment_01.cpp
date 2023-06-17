#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    bool isEmpty();
    void append(int);
    void insert(int, int);
    void del(int);
    void edit(int, int);
    bool isFull();
    int count();
    int get(int);
    int find(int);
    ~Array();
};
int Array::find(int data)
{
    int i;
    for (i = 0; i <= lastIndex; i++)
        if (ptr[i] == data)
            return i;
    return -1;
}

Array::~Array()
{
    delete[] ptr;
}
int Array::count()
{
    return (lastIndex + 1);
}
int Array::get(int index)
{
    if (index >= 0 && index < lastIndex + 1)
        return (ptr[index]);
    cout << endl<< "Invalid or Empty array";
    return -1;
}
bool Array::isFull()
{
    return (lastIndex == capacity - 1);
}
void Array::edit(int index, int data)
{
    if (index >= 0 && index <= lastIndex)
        ptr[index] = data;
}
void Array::del(int index)
{
    int i;
    for (i = index; i < lastIndex; i++)
        ptr[i] = ptr[i + 1];
    lastIndex--;
}

void Array::insert(int index, int data)
{
    int i;
    if (lastIndex == capacity - 1)
        cout << "Array is full";
    else if (index < 0 || index > lastIndex + 1)
        cout << "Invalid Index" << endl;
    else
    {
        for (i = lastIndex; i >= index; i--)
            ptr[i + 1] = ptr[i];
        ptr[index] = data;
        lastIndex++;
    }
}
void Array::append(int data)
{
    if (lastIndex == capacity + 1)
        cout << "Array is full";
    else
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
}
bool Array::isEmpty()
{
    return (lastIndex == -1);
}
Array::Array(int cap)
{
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}
int main()
{
    Array obj(5);
    if (obj.isEmpty())
        cout << "Array is Empty" << endl;
    obj.append(10);
    obj.append(20);
    obj.append(30);
    obj.append(40);
    for (int i = 0; i < obj.count(); i++)
    {
        cout << obj.get(i) << " ";
    }
    cout << endl<< "After Inserting value" << endl;
    obj.insert(1, 15);
    for (int i = 0; i < obj.count(); i++)
    {
        cout << obj.get(i) << " ";
    }
    cout << endl<< "After Deleting value" << endl;
    obj.del(0);
    for (int i = 0; i < obj.count(); i++)
    {
        cout << obj.get(i) << " ";
    }
    cout << endl<< "After Editing value" << endl;
    obj.edit(0, 16);
    for (int i = 0; i < obj.count(); i++)
    {
        cout << obj.get(i) << " ";
    }
    cout << endl;
    if (obj.isFull())
        cout << endl<< "Array is full" << endl;
    cout << "The index no is"<< " " << obj.find(30) << endl;
}
