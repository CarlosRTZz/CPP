#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
	private :
		T *_array;
		unsigned int _size;
	public :
		Array(void) : _size(0) , _array(NULL) {};
		~Array(void) {
			delete [] this->_array;
		}
		Array(unsigned int i) : _array(new T(i)), _size(i) {};
		Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size) {
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = copy._array[i];
			}
		}
		Array &operator=(const Array &rhs) {
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_size = rhs._size;
				this->_array = new T(this->size);
				for (unsigned int i = 0; i < this->_size; i++) {
					this->_array[i] = rhs._array[i];
				}
			}
			return (*this);
		}
		T &operator[](unsigned int nbr) {
			if (nbr >= this->_size)
				throw outOfBonds();
			return (this->_array[nbr]);
		}

		unsigned int size(void) const {
			return (this->_size);
		}

		class outOfBonds : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Index is out of bonds !");
				}
		};
};

#endif