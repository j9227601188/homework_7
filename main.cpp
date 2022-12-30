//Домашняя работа модуль 7 
//Группа С++ 27 27.12.2022
//Волков Е.М.
#include <iostream>
#include "IntegerArray.h"
#include "My_bad_length.h"
#include "My_bad_range.h"
using namespace std;

int main() {
    try {
        IntegerArray array_1(50);                               //создать контейнер
        for(int i = 0; i < array_1.get_array_length(); ++i) {   //наполнить контейнер
            array_1[i] = i;
        }
        cout << array_1[35] << endl;                             
        IntegerArray array_2(100);
        cout << array_2[75] << endl;   
        array_2 = array_1;                  //копировать контейнер
        cout << array_2[45] << endl;        //получить доступ к любому элементу контейнера по индексу
        array_2.resize(35);                 //изменить размер контейнера (с копированием)
        cout << array_2[25] << endl; 
        array_2.reallocate(150);            //изменить размер контейнера (со стиранием)
        cout << array_2[75] << endl; 
        cout << array_2.get_array_length() << endl; //узнаем текущий размер контейнера
        array_2.insertBefore(14,75);        //вставить элемент в контейнер
        cout << array_2[75] << endl; 
        array_2._remove(75);                //удалить элемент из контейнера
        cout << array_2[75] << endl; 
        array_2.insertAtBeginning(999);     //вставка элемента в начало контейнера
        cout << array_2[0] << endl; 
        array_2.insertAtEnd(777);           //вставка элемента в конец контейнера
        cout << array_2[array_2.get_array_length()-1] << endl;
        array_2._remove(0);                 //удалить элемент из контейнера
        cout << array_2[0] << endl;       
        cout << array_2.found(5) << endl;   // поиск по значению
        //IntegerArray bad_array(-5);       //exception bad_length
        //cout << array_2[9999] << endl;    //exception bad_range
        //array_2.insertBefore(55,9999);    //exception bad_range
        //array_2._remove(9999);            //exception bad_range
    }
    catch(exception& e) {
        cout << e.what();
    }
	return 0;
}
