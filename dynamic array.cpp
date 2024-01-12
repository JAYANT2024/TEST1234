#include<iostream>
using namespace std;

class DynamicArray
{
        int *array;
        int size;  // number of elements currently present
        int count; // size of array

    public :

        DynamicArray()
        {
            array = new int[1];
            size = 0;
            count = 1;
        }

        ~DynamicArray()
        {
            delete []array;
            size = 0;
            count = 0;
        }

        void insert(int a)
        {
            if(size == count) // array is full
                resize();

            array[size] = a;
            size++;
        }

        void resize()
        {
            int *temp = new int[2*size];

            for(int i = 0; i < size ; i++)
            {
                temp[i] = array[i];
            }

            count = 2*size;
            delete []array;
            array = temp;
        }

        int get(int index)
        {
            if(index >= size)
                cout<<"Index not present"<<endl;

            return array[index];
        }

        void print()
        {
            for(int i = 0; i < size; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }

        void insertAt(int index , int value)
        {
            if(size == count)
                resize();

            for(int i = size; i>= index ; i--)
            {
                array[i] = array[i-1];
            }
            array[index] = value;
            size++;
        }
};

int main()
{
    DynamicArray a;
    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(40);
    a.insert(50);
    a.insertAt(2,100);

    a.print();

    return 0;
}
