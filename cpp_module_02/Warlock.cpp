#include "Warlock.hpp"

Warlock::Warlock( std::string const &name, std::string const &title ) : _name(name), _title(title) {

	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
	
	std::cout << this->_name << ": My job here is done!\n";
}

std::string const	&Warlock::getName() const {

	return (this->_name);
}

std::string const	&Warlock::getTitle() const {

	return (this->_title);
}

void	Warlock::setTitle( std::string const &title ) {

	this->_title = title;
}

void	Warlock::introduce() const {

	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}

void	Warlock::learnSpell( ASpell *spell ) {

	this->_book.learnSpell(spell);
}

void	Warlock::forgetSpell( std::string const &spellName ) {

	this->_book.forgetSpell(spellName);
}

void	Warlock::launchSpell( std::string const &spellName, ATarget const &target ) {

	ASpell	*spell = this->_book.createSpell(spellName);

	if (spell)
		spell->launch(target);
}