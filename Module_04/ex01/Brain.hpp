#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain {
	protected :
		std::string ideas[100];

	public :
		Brain &operator=(const Brain &rhs);

		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);
}

#endif