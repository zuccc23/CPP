#ifndef ARRAY_HPP

# define ARRAY_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

template <class T>
class Array {
	private:
		T* _array;
		int _size;

	public:
		//Constructors
		Array(){
			_array = NULL;
			_size = 0;
		}
		Array(unsigned int n){
			_array = new T[n]();
			_size = n;
		}
		Array(const Array& to_copy){
			_size = to_copy._size;
			_array = new T[_size]();
			for (int i = 0; i < _size; i++)
				_array[i] = to_copy._array[i];
		}

		//Destructor
		~Array(){
			
		}

		//Functions
		class OutOfBoundsException : public std::exception {
			const char* what() const throw() {
				return ("Index is out of bounds");
			}
		};

		int	size() const {
			return (_size);
		}

		T&	operator[](int index) {
			if (index >= _size || index < 0)
				throw OutOfBoundsException();
			return _array[index];
		}

		const T&	operator[](int index) const {
			if (index >= _size || index < 0)
				throw OutOfBoundsException();
			return _array[index];
		}
	
};

#endif