#include "IntegerArray.h"
#include "My_bad_length.h"
#include "My_bad_range.h"

IntegerArray::IntegerArray(int length) : _array_length(length) {
	if (length <= 0) {                                  
        throw My_bad_length();                   //exception
	}
	if (length > 0) {
		_array_data = new int[length] {};
	}
};
IntegerArray::~IntegerArray() {
	delete[] _array_data;
};
void IntegerArray::erase() {
	delete[] _array_data;
	_array_data = nullptr;
	_array_length = 0;
};
int& IntegerArray::operator[](int index) {
	if(!(index >= 0 && index < _array_length)) {   //exception
	    throw My_bad_range();
	}        
	return _array_data[index];
};
int IntegerArray::get_array_length() const { 
	return _array_length;
};
void IntegerArray::reallocate(int new_array_length) { 
	erase();
	if (new_array_length <= 0)
		return;
	_array_data = new int[new_array_length]{0}; 
	_array_length = new_array_length;
};
void IntegerArray::resize(int new_array_length) {
	if (new_array_length == _array_length) {
		return;
	}
	if (new_array_length <= 0) {
		erase();
		return;
	}
	int* data = new int[new_array_length];
	if (_array_length > 0) {
		int elementsToCopy = (new_array_length > _array_length) ? _array_length : new_array_length;
		for (int index = 0; index < elementsToCopy; ++index) {
			data[index] = _array_data[index];
		}
	}
	delete[] _array_data;
	_array_data = data;
	_array_length = new_array_length;
};
IntegerArray::IntegerArray(const IntegerArray& a) {
	reallocate(a.get_array_length());
	for (int index = 0; index < _array_length; ++index) {
		_array_data[index] = a._array_data[index];
	}
};
IntegerArray& IntegerArray::operator=(const IntegerArray& a) {
	if (&a == this) {
		return *this;
	}
	reallocate(a.get_array_length());
	for (int index = 0; index < _array_length; ++index) {
		_array_data[index] = a._array_data[index];
	}
	return *this;
};
void IntegerArray::insertBefore(int value, int index) {
	if(index <= 0 && index > _array_length) {               //exception
	    throw My_bad_range();
	} 
	int* data = new int[_array_length + 1];
	for (int before = 0; before < index; ++before) {
		data[before] = _array_data[before];
	}
	data[index] = value;
	for (int after = index; after < _array_length; ++after) {
		data[after + 1] = _array_data[after];
	}
	delete[] _array_data;
	_array_data = data;
	++_array_length;
};
void IntegerArray::_remove(int index) {                        //exception
	if (index <=0 && index > _array_length) {
	    throw My_bad_range();
	};
	if (_array_length == 1) {
		erase();
		return;
	}
	int* data = new int[_array_length - 1];
	for (int before = 0; before < index; ++before) {
		data[before] = _array_data[before];
	}
	for (int after = index + 1; after < _array_length; ++after) {
		data[after - 1] = _array_data[after];
	}
	delete[] _array_data;
	_array_data = data;
	--_array_length;
}
void IntegerArray::insertAtBeginning(int value) { 
	insertBefore(value, 0); 
}
void IntegerArray::insertAtEnd(int value) { 
	insertBefore(value, _array_length); 
}
int IntegerArray::found(int value) {
    for (int index = 0; index < _array_length; ++index) {
        if (_array_data[index] == value) {
            return index;
        }
    }
    return 0;
}