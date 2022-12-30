#pragma once

class IntegerArray {
private:
	int _array_length{};
	int* _array_data{};
public:
	IntegerArray() = default;
	IntegerArray(int length);	                    //конструктор
	~IntegerArray();		                        //деструктор
	void erase();                                   //стираем данные
	int& operator[](int index);			            //перегрузка[]
	int get_array_length() const;		            //вычисляем собственный размер (длину)
	void reallocate(int new_array_length);          //изменить размер со стиранием (быстро)
	void resize(int new_array_length);	            // изменить размер с сохранением данных (долго)
	IntegerArray(const IntegerArray& a);	        //конструктор копирования
	IntegerArray& operator=(const IntegerArray& a);	//перегрузка оператора присвоения
	void insertBefore(int value, int index);	    //вставка элемента
	void _remove(int index);	                    //удаление элемента
	void insertAtBeginning(int value);	            //вставка в начале
	void insertAtEnd(int value);	                //вставка в конце
	int found(int value);                           // поиск по значению
};
