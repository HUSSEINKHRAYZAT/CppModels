#include "easyfind.tpp"
#include <iostream>
#include <list>

int	main() {
	std::list<int>	lst;
	bool			exe = true;
    int				fi;
	

	for(int i = 1;i<10;i++)
    {
        lst.push_back(i*2*23);
    }
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << "\n";
    }
	try {
		fi = easyfind(lst,276);
		exe = false;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	if (!exe)
		std::cout << "Value found : " << fi << "." << std::endl;

	return 0;
}