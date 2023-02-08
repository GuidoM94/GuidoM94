#pragma once

#include <iostream>

class Bureaucrat
{
	friend	std::ostream &operator<<( std::ostream &os, const Bureaucrat &rhs );
	private:
		std::string const	_name;
		int					_grade;

		struct	GradeTooHighException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};

		struct	GradeTooLowException : public std::exception {
			const char *what( void ) const _NOEXCEPT;
		};
	public:
		Bureaucrat( void );
		Bureaucrat( std::string const name, int grade );
		Bureaucrat( const Bureaucrat &src );
		~Bureaucrat( void );

		Bureaucrat	&operator=( const Bureaucrat &rhs );

		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		decrementGrade( int decrement );
		void		incrementGrade( int increment );
};
