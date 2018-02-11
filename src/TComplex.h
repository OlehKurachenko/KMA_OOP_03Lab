//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  on 2018-02-11T12:39:15Z as a part of KMA_OOP_03Lab
//  
//  copying code from GitHub doesn't make you smarter,
//  better ask me oleh.kurachenko@gmail.com , I'm ready to help
//  
//  checkout my GitHub https://github.com/OlehKurachenko
//  rate, CV & contacts http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//  
#ifndef KMA_OOP_03LAB_TCOMPLEX_H
#define KMA_OOP_03LAB_TCOMPLEX_H

#include <iostream>
#include <cmath>

//	Class methods & utills prototypes are taken from
// http://distedu.ukma.edu.ua/course/view.php?id=11 (may be unavailable for unregistered users),
// which is a part of mandatory requirements

class AComplex;

class TComplex;

std::ostream& operator<<(std::ostream &, const TComplex&);

class TComplex
{
public:
	TComplex (double ro=0, double phi=0);
	TComplex (const TComplex&);
	TComplex (const AComplex&);
	~TComplex();

	TComplex& operator= (const TComplex&);

	double& mod();
	double& arg();

	double mod() const;
	double arg() const;

	double re() const;
	double im() const;
private:
	double _ro, _phi;
	static unsigned _freeId;
	const unsigned _id;
};

TComplex& operator+=(TComplex& a, const TComplex& b);
TComplex& operator-=(TComplex& a, const TComplex& b);
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);

const TComplex  operator* (const TComplex&, const TComplex&);
const TComplex  operator/ (const TComplex&, const TComplex&);
const TComplex  power(const TComplex&, unsigned int);

std::istream& operator>>(std::istream &, TComplex&);

#endif //KMA_OOP_03LAB_TCOMPLEX_H
