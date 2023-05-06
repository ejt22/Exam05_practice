#include "SpellBook.hpp"

SpellBook::SpellBook() {
}

SpellBook::~SpellBook() {
	
	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		delete (*it);
		it++;
	}
	this->_tab.clear();
}

void	SpellBook::learnSpell( ASpell *spell ) {

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

void	SpellBook::forgetSpell( std::string const &spellName ) {

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

ASpell	*SpellBook::createSpell( std::string const &spellName ) {

	std::vector<ASpell *>::iterator	it = this->_tab.begin();
	std::vector<ASpell *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		if ((*it)->getName() == spellName)
			return (*it);
		it++;
	}
	return (NULL);
}