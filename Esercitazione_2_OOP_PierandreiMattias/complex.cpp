//PIERANDREI MATTIAS
//complex.hpp TEST
//compilato con:      g++ -std=c++20 -o complex complex.cpp

#include "complex.hpp"
#include <iostream>
 

int main()
{
	using comp = complex<double>;
	comp c1(1,1);
	comp c2(2,-2);

	double k=3;
	
	std::cout << "\n---------------------"<< std::endl;
	
	std::cout << "c1 = "<< c1 << std::endl;
	std::cout << "c2 = "<< c2 << std::endl;
	std::cout << "k = "<< k << std::endl;
	
	std::cout << "---------------------\n"<< std::endl;
	
	std::cout << "Real part of c2 = "<< c2.getReal() << std::endl;
	std::cout << "Imaginary part of c2 = "<< c2.getImaginary() << std::endl;
	std::cout << "Conjugate of c2 = "<< c2.conjugate() << std::endl;

	std::cout << "Operator + between complex: c2+c1 = " << c2 + c1 << std::endl;
	std::cout << "Operator + between complex and T: c2+k = " << c2 + k << std::endl;
	std::cout << "Operator * between complex: c2*c1 = " << c2*c1 << std::endl;
	std::cout << "Operator * between complex and T: c2*k = " << c2*k << std::endl;
	
	std::cout << "Operator + between T and complex: k+c1 = " << k+c1 << std::endl;
	std::cout << "Operator * between T and complex: k*c2 = " << k*c2 << std::endl;
	
	comp c3(7,0);
	std::cout << "Stampa di un intero convertito: " << c3 << std::endl;

	return 0;
}