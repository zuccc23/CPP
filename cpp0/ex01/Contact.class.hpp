#ifndef CONTACT_HPP

# define CONTACT_HPP
# include <iostream>

class	Contact{
	public:

	Contact(void);
	~Contact(void);

	void 		displayName(std::string name);

	// SETTER - GETTER
	std::string	getFname(void);
	void 		setFname(std::string name);
	std::string	getLname(void);
	void 		setLname(std::string name);
	std::string	getNickname(void);
	void 		setNickname(std::string name);
	std::string	getSecret(void);
	void 		setSecret(std::string name);
	std::string	getNumber(void);
	void 		setNumber(std::string name);

	private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	secret;
};

#endif