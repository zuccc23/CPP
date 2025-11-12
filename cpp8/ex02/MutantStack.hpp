#ifndef MUTANTSTACK_HPP

# define MUTANTSTACK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		//typedefs to use the proper data from stack class etc...
		typedef typename std::stack<T>::container_type container_type; // to access the protected container inside stack class
		typedef typename container_type::iterator iterator; //create an alias (like a typedef) associated to the iterator of the stack class
	//-lets compiler kno ur defining a type -from ur container types's iterator -named iterator
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;


		//inherit constructors from stack class
		MutantStack() : std::stack<T>() {
		}
		MutantStack(const MutantStack& to_copy) : std::stack<T>(to_copy) {
		}
		MutantStack& operator=(const MutantStack& to_copy) {
			std::stack<T>::operator=(to_copy);
			return *this;
		}
		~MutantStack(){
		}

		//ITERATOR FUNCTIONS
		//regular iterators, to modify and read the data at the pointed address
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
		//const interators, access the data on read only
		const_iterator begin() const {
			return this->c.begin();
		}
		const_iterator end() const {
			return this->c.end();
		}
		//same but in reverse, starting from the last iterator
		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}
		const_reverse_iterator rend() const {
			return this->c.rend();
		}
};


#endif