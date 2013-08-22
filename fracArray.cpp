/********************************************************************
fracArray.cpp
------------
By: Jessica Pagan Sanchez       August 22, 2013

Definitions of the functions in the fracArray.h file
********************************************************************/

#include "fracArray.h"
#include <iostream>

using namespace std; 
//-------------------------------------------------------------------
// funtion Fraction
//  Default constructor that sets the the data memebers of the object
//  in 0 and 1.
//  Return/post-condition:
//   -- Data member num sets as 0
//   -- Data member denom sets as 1
//-------------------------------------------------------------------
Fraction::Fraction() {
    num = 0 ;
    denom = 1 ;
}

//-------------------------------------------------------------------
// funtion Fraction
//  Constructor that, given two integers, sets the the data memebers 
//  of the object.
//  Parameters:
//   -- n: integer for Data Member num
//   -- d: integer for Data Member denom
//  Return/post-condition:
//   -- Data Member num sets as the integer assigned
//   -- Data Member denom sets as the inteher assined
//-------------------------------------------------------------------
Fraction::Fraction(int n , int d) {
    num = n ;
    denom = d ;
}

//-------------------------------------------------------------------
// funtion setNum
//  Given an integer, will assign it to the Data Member num
//  Parameters:
//   -- n: integer for Data Member num
//  Return/post-condition:
//   -- Data Member num sets as the integer assigned
//-------------------------------------------------------------------
void Fraction::setNum(int n) {
    num = n ;
}

//-------------------------------------------------------------------
// funtion setDenom
//  Given an integer, will assign it to the Data Member denom
//  Parameters:
//   -- n: integer for Data Member denom
//  Return/post-condition:
//   -- Data Member denom sets as the integer assigned
//-------------------------------------------------------------------
void Fraction::setDenom(int d) {
    denom = d ;
}

//-------------------------------------------------------------------
// funtion getNum
//  It will return the value in the Data Member num, without change
//  its value.
//  Return/post-condition:
//   -- Value of the Data Member num
//-------------------------------------------------------------------
int Fraction::getNum() const {
    return num ;
}

//-------------------------------------------------------------------
// funtion getDenom
//  It will return the value in the Data Member denom, without change
//  its value.
//  Return/post-condition:
//   -- Value of the Data Member denom
//-------------------------------------------------------------------
int Fraction::getDenom() const {
    return denom ;
}

//-------------------------------------------------------------------
// funtion print
//  It will print on screen the value of the Data Members as a
//  fractional number.
//-------------------------------------------------------------------
void Fraction::print(){
    cout << num << "/" << denom << endl;
} 

//-------------------------------------------------------------------
// funtion add
//  Given an object of the class Fraction, it will add it to the
//  object passed by calling the function.
//  Parameters:
//   -- F: object use as addend
//  Return/post-condition:
//   -- An object with the sum of the addition.
//-------------------------------------------------------------------
Fraction Fraction::add(const Fraction& F) const{
    Fraction r; // result
    if(denom == F.denom) {
        r.num = num + F.num;
        r.denom = denom;    
     }
    else {
        r.num=(num * F.denom) + (F.num * denom);
        r.denom = denom * F.denom ;
  }
    return r ;
}

//-------------------------------------------------------------------
// funtion sub
//  Given an object of the class Fraction, it will subtract it to the
//  object passed by calling the function.
//  Parameters:
//   -- F: object use as subtrahend
//  Return/post-condition:
//   -- An object with the difference of the subtraction.
//-------------------------------------------------------------------
Fraction Fraction::sub(const Fraction& F) const{
    Fraction r;
    if(denom == F.denom) {
        r.num = num - F.num;
        r.denom = denom ;
    }
    else {
        r.num = (num * F.denom) - (F.num * denom);
        r.denom = denom * F.denom;
    }
    return r ;
}

//-------------------------------------------------------------------
// funtion mul
//  Given an object of the class Fraction, it will multiply it to the
//  object invoked the function.
//  Parameters:
//   -- F: object use as factor
//  Return/post-condition:
//   -- An object with the product of the multiplication.
//-------------------------------------------------------------------
Fraction Fraction::mul(const Fraction& F) const{
    Fraction r;
    r.num = num * F.num;
    r.denom = denom * F.denom;
    return r;
}

//-------------------------------------------------------------------
// funtion div
//  Given an object of the class Fraction, it will divide it to the
//  object passed by calling the function.
//  Parameters:
//   -- F: object use as divisor
//  Return/post-condition:
//   -- An Fraction object as the result of the division.
//-------------------------------------------------------------------
Fraction Fraction::div(const Fraction& F) const{
    Fraction r;
    r.num = num * F.denom;
    r.denom = denom * F.num;
    return r;
}

//-------------------------------------------------------------------
// funtion gt
//  Given an object of the class Fraction and the object passed by
//  calling the function, it will divide the Data Member num by the
//  Data Member denom in each object.
//  The compares who is the greatest number.
//  Parameters:
//   -- F: object use as fraction
//  Return/post-condition:
//   -- true: if object invoked is greatest
//   -- false: if object passed by argument is greatest
//-------------------------------------------------------------------
bool Fraction::gt(const Fraction& F) const{
    double r1, r2;
    r1 = static_cast<double>(num)/denom;
    r2 = static_cast<double>(F.num)/F.denom;

    if(r1 > r2)
        return true;
    else
        return false;
}

//-------------------------------------------------------------------
// funtion reduce
//  Using the function findGCD, it will use the return of it to
//  divide the Data Member num and Data Member denom of the object
//  passed by calling the function reduce.
//  Return/post-condition:
//   -- An object with the Data Members reduced.
//------------------------------------------------------------------- 
Fraction Fraction::reduce() const{
    Fraction r;
    int gcd;

    gcd = findGCD(num , denom);

    r.num = num / gcd ;
    r.denom = denom / gcd ;
    return r;
}

//-------------------------------------------------------------------
// funtion findGCD
//  Given the values of Data Members num and denom of an object, it 
//  will use the Euclidean algorithm to find the GCD.
//  Parameters:
//   -- x: the value of Data Member num
//   -- y: the value of Data Member denom
//  Return/post-condition:
//   -- an integer of object's Greatest Common Dividor
//-------------------------------------------------------------------
int findGCD(int x, int y) {
    if(y == 0)
        return x ;
    else
        return findGCD(y , x % y) ;
}

//-------------------------------------------------------------------
// funtion sum
//  Given an array of objects and it size, it will use the class
//  function "add" to calculate the summation of the objects.
//  Parameters:
//   -- A: the array
//   -- size: size of the array
//  Return/post-condition:
//   -- an object representing the sum as factor
//-------------------------------------------------------------------
Fraction sumFrac(const Fraction A[], int size) {
    Fraction r;

    for(int i = 0; i < size ; i++)
        r = r.add(A[i]) ;

    return r;
}

//-------------------------------------------------------------------
// funtion sort
//  Given an array of objects and it size, it will use the selection
//  sorting to organize the array in ascending order.
//  Parameters:
//   -- A: the array
//   -- size: size of the array
//  Return/post-condition:
//   -- Objects in the array will be organized in ascending order
//-------------------------------------------------------------------
void sort(Fraction A[], int size) {
    int tmp;

    for(int i = 0 ; i < size ; i++) {
        int smallest = i ;

        for(int j = i + 1; j < size; j++) 
            if(A[j].gt(A[smallest]) == false)
                smallest = j;

        tmp = A[i].getNum();
        A[i].setNum(A[smallest].getNum());
        A[smallest].setNum(tmp);

        tmp = A[i].getDenom();
        A[i].setDenom(A[smallest].getDenom());
        A[smallest].setDenom(tmp);
    }
}

ArrayOfFractions::ArrayOfFractions() {

    for(int i = 0 ; i < 10 ; i++) {
        A[i].setNum(rand() % 9 + 1) ;
        A[i].setDenom(rand() % 9 + 1) ;
    }
}

void ArrayOfFractions::sortAscending() {
    sort(A , 10) ; 
}

void ArrayOfFractions::print() {
    for(int i = 0; i < 10; i++)
        A[i].print() ;
}

Fraction ArrayOfFractions::min() const{
    Fraction minim = A[0] ;
    bool b ;
    for(int i = 1; i < 10; i++) {
        b = A[i].gt(minim) ;
        if(b == false) {
            minim.setNum(A[i].getNum());
            minim.setDenom(A[i].getDenom());
        }
    }

    return minim ;
}

Fraction ArrayOfFractions::max() const{
    Fraction maxim = A[0] ;
    bool b ;
    for(int i = 1; i < 10; i++) {
        b = A[i].gt(maxim) ;
        if(b == true) {
            maxim.setNum(A[i].getNum());
            maxim.setDenom(A[i].getDenom());
        }
    }

    return maxim ;
}

Fraction ArrayOfFractions::sum() const{
    Fraction r;

    r = sumFrac(A, 10) ;

    r = r.reduce() ;
    return r ;
}