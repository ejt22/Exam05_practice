#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include "SpellBook.hpp"
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock {

	private:
		
		std::string		_name;
		std::string		_title;
		SpellBook		_book;

		Warlock();
		Warlock( Warlock const &src );

		Warlock &operator=( Warlock const &src );

	public:
		
		Warlock( std::string const &name, std::string const &title );
		~Warlock();

		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void				setTitle( std::string const &title );

		void	introduce() const;

		void	learnSpell( ASpell *spell );
		void	forgetSpell( std::string const &spellName );
		void	launchSpell( std::string const &spellName, ATarget const &target );
};

#endif