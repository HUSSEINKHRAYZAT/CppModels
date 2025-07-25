
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		Cat &	operator=(Cat const &rSym);

		void			makeSound() const;
		virtual void	think() const;
	private:
		str		_type;
		Brain	*_brain;
};