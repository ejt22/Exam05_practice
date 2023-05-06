#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <vector>
# include "ATarget.hpp"

class TargetGenerator {

	private:
		
		std::vector<ATarget *>	_tab;

		TargetGenerator( TargetGenerator const &src );

		TargetGenerator &operator=( TargetGenerator const &src );

	public:
		
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType( ATarget *target );
		void	forgetTargetType( std::string const &targetType );
		ATarget	*createTarget( std::string const &targetType );
};

#endif