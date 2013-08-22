/********************************************************************
fracArray.h
------------
By: Jessica Pagan Sanchez		August 22, 2013

Implementations of a data members and functions for the classes 
Fraction and ArrayOfFractions.
********************************************************************/

#ifndef FRAC_H
#define FRAC_H

class Fraction {
	private:
		int num, denom;

	public:
		Fraction();
		Fraction(int n, int d);
		
		Fraction add(const Fraction& F) const;
		Fraction sub(const Fraction& F) const;
		Fraction mul(const Fraction& F) const;
		Fraction div(const Fraction& F) const;
		Fraction reduce() const;


		bool gt(const Fraction& F) const;		

		void setNum(int n);
		void setDenom(int d);
		void print();

		int getNum() const ;
		int getDenom() const ;
};


void sort(Fraction A[], int size);
int findGCD( int x , int y) ;
Fraction sumFrac(const Fraction A[], int size);

class ArrayOfFractions {
	private:
		Fraction A[10] ;

	public:
		ArrayOfFractions() ;

		void sortAscending() ;
		void print() ;
		Fraction min() const;
		Fraction max() const;
		Fraction sum() const;
};


#endif

