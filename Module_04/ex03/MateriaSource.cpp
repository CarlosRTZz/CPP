#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++){
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	for (int i = 0; i < 4; ++i)
		{
			if (this->_materias[i] != NULL)
				this->_materias[i] = rhs._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}