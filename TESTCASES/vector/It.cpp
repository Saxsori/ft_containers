#include "../CONTAINERS/vector.hpp"
#include "./printSize.hpp"

void	prepost_incdec(ft::vector<TESTED_TYPE> &vct)
{
	std::cout << "##################FT#######################" << std::endl;
	ft::vector<TESTED_TYPE>::iterator it = vct.begin();
	ft::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	// std::cout << "###############################################" << std::endl;
}

void	prepost_incdec(std::vector<TESTED_TYPE> &vct)
{
	std::cout << "##################STD#######################" << std::endl;
	std::vector<TESTED_TYPE>::iterator it = vct.begin();
	std::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	// std::cout << "###############################################" << std::endl;
}

int main ()
{
	const int size = 5;
	ft::vector<TESTED_TYPE> vct(size);
	ft::vector<TESTED_TYPE>::iterator it = vct.begin();
	ft::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	std::vector<TESTED_TYPE> vct1(size);
	std::vector<TESTED_TYPE>::iterator it1 = vct1.begin();
	std::vector<TESTED_TYPE>::const_iterator ite1 = vct1.begin();
	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	
	for (int i = 0; i < size; ++i)
		it1[i] = (size - i) * 5;

	prepost_incdec(vct);
	prepost_incdec(vct1);


	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	it1 = it1 + 5;
	it1 = 1 + it1;
	it1 = it1 - 4;
	std::cout << *(it1 += 2) << std::endl;
	std::cout << *(it1 -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;
	*(it1 -= 2) = 42;
	*(it1 += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite +=: " << *(ite1 += 2) << std::endl;

	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite1 -= 2) << std::endl;


	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(it == const_it): " << (ite1 == it1) << std::endl;

	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(const_ite - it): " << (ite1 - it1) << std::endl;

	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite1 + 3 == it1) << std::endl;

	ft::printSize(vct, true);
	ft::printSize(vct1, true);
	return (0);
}