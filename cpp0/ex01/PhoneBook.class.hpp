#ifndef PHONEBOOK_CLASS_HPP

# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

class PhoneBook{

	public:
	PhoneBook(void);
	~PhoneBook(void);
	void	search(void);
	void	add(void);

	private:
	Contact _contacts[8];
	void	display_contact_list(void);
	void	display_contact(int index);
	int		index;
};

# endif