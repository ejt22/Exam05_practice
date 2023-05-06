#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
	
	std::vector<ATarget *>::iterator	it = this->_tab.begin();
	std::vector<ATarget *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		delete (*it);
		it++;
	}
	this->_tab.clear();
}

void	TargetGenerator::learnTargetType( ATarget *target ) {

	std::vector<ATarget *>::iterator	it = this->_tab.begin();
	std::vector<ATarget *>::iterator	ite = this->_tab.end();

	if (target) {
		while (it != ite) {
			if ((*it)->getType() == target->getType())
				return ;
			it++;
		}
		this->_tab.push_back(target->clone());
	}
}

void	TargetGenerator::forgetTargetType( std::string const &targetType ) {

	std::vector<ATarget *>::iterator	it = this->_tab.begin();
	std::vector<ATarget *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		if ((*it)->getType() == targetType) {
			delete (*it);
			this->_tab.erase(it);
			return ;
		}
		it++;
	}
}

ATarget	*TargetGenerator::createTarget( std::string const &targetType ) {

	std::vector<ATarget *>::iterator	it = this->_tab.begin();
	std::vector<ATarget *>::iterator	ite = this->_tab.end();

	while (it != ite) {
		if ((*it)->getType() == targetType)
			return (*it);
		it++;
	}
	return (NULL);
}