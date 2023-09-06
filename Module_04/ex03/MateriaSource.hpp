#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private :
		AMateria *_materias[4];

	public :
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(std::string const & type);

		MateriaSource &operator=(const MateriaSource &rhs);

		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource(void);
};

#endif