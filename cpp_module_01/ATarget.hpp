#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget {

	private:

		std::string	_type;
	
	public:
		
		ATarget();
		ATarget( std::string const &type );
		ATarget( ATarget const &src );
		virtual ~ATarget();

		ATarget &operator=( ATarget const &src );

		std::string const	&getType() const;

		virtual ATarget	*clone() const = 0;

		void	getHitBySpell( ASpell const &spell ) const;
};

#endif