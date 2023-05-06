#include "Warlock.hpp"

Warlock::Warlock( std::string const &name, std::string const &title ) : _name(name), _title(title) {

	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
	
	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		delete (*it);
		it++;
	}
	this->_tab.clear();
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

	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	if (spell) {
		while (it != ite) {
			if ((*it)->getName() == spell->getName())
				return ;
			it++;
		}
		this->_tab.push_back(spell->clone());
	}
}

void	Warlock::forgetSpell( std::string const &spellName ) {

	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		if ((*it)->getName() == spellName) {
			delete (*it);
			this->_tab.erase(it);
			return ;
		}
		it++;
	}
}

void	Warlock::launchSpell( std::string const &spellName, ATarget const &target ) {

	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
			return ;
		}
		it++;
	}
}