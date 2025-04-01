// PIERANDREI MATTIAS

#pragma once
#include <iostream>
#include <concepts>


template <typename T> requires std::floating_point<T>

// A class modeling a COMPLEX number
class complex
{
    T real;
	T imaginary;
    
public:

    // Default constructor 
    complex()
        : real(0), imaginary(0)
    {}
	
    // User-defined constructor
    complex(T r , T i)
        : real(r), imaginary(i)
    {}
	
    // User-defined constructor for real numbers
    explicit complex(T r)
        : real(r), imaginary(0)
    {}
    
    // Return the real part
    T getReal(void) const {
        return real;
    }
    
    // Return the imaginary part
    T getImaginary(void) const {
        return imaginary;
    }
    
    // Return the conjugate
    complex conjugate(void) const {
		return complex(real, -imaginary); 
	}
    
    // Overload += between complex
    complex& operator+=(const complex& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
	}
	
	// Overload + between complex using +=
	complex operator+(const complex& other) const {
		complex C = *this;
		C += other;
        return C;
    }

	// Overload += between complex and T
	complex& operator+=(T num) {
        real += num;
        return *this;
	}
	
	// Overload + between complex and T using +=
	complex operator+(const T& other) const {
		complex C = *this;
		C += other ;
        return C;
    }
	
	// Overload *= between complex
    complex& operator*=(const complex& other) {
        T tempReal = real * other.real - imaginary * other.imaginary;
        T tempImag = real * other.imaginary + imaginary * other.real;
        real = tempReal;
        imaginary = tempImag;
        return *this;
    }
	
	// Overload * between complex using *=
    complex operator*(const complex& other) const {
		complex C = *this;
		C *= other;
        return C;
    }
	
	// Overload * between complex and T using *=
    complex operator*(const T& other) const {
		complex C = *this;
		C *= other;
        return C;
    }
	
	// Overload *= between complex and T
    complex& operator*=(T other) {
        real *= other;
        imaginary *= other;
        return *this;
    }


};


// Overload of <<, to make the complex printable
template <typename T>
std::ostream& operator<<(std::ostream& os, const complex<T>& c) {
    os << c.getReal();
    if (c.getImaginary() > 0){
		os << "+";
		os << c.getImaginary() << "i";
	}
		
	if (c.getImaginary() < 0) {os << c.getImaginary() << "i";}
		
    
	return os;
}

// Overload + with T on the left
template <typename T> 
complex<T> operator+(T num, const complex<T>& c) 
{
    return ( c + num );
}

// Overload * with T on the left
template <typename T> 
complex<T> operator*(T num, const complex<T>& c) {
    return ( c * num );
}

