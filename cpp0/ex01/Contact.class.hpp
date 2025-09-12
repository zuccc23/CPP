#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>

class	Contact{
	public:

	Contact(void);
	~Contact(void);
	std::string	getFname(void);
	void 		setFname(std::string name);

	private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	secret;
};

#endif