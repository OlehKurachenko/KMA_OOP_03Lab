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
	inline TComplex (double ro = 0, double phi = 0);
	inline TComplex (const TComplex&);
	TComplex (const AComplex&);
	inline ~TComplex();

	inline TComplex& operator=(const TComplex&);

	inline double& mod() { return this->_ro; }
	inline double& arg() { return this->_phi; }

	inline double mod() const { return this->_ro; }
	inline double arg() const { return this->_phi; }

	inline double re() const { return mod() * std::cos(arg()); }
	inline double im() const { return mod() * std::sin(arg()); }
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

// Definitions

inline TComplex::TComplex(double ro, double phi):
	_id(++_freeId),
	_ro(ro),
	_phi(phi)
{
#ifndef NDEBUG
	std::cout << "constructor TComplex(ro=" << ro << ", phi=" << phi << ") call, "
			  << *this << ", id=" << _id << " created" << std::endl;
#endif
}

inline TComplex::TComplex(const TComplex &that):
	_id(++_freeId),
	_ro(that._ro),
	_phi(that._phi)
{
#ifndef NDEBUG
	std::cout << "constructor TComplex(" << that << ") call, "
			  << *this << ", id=" << _id << " created" << std::endl;
#endif
}

inline TComplex::~TComplex() {
#ifndef NDEBUG
	std::cout << "destructor TComplex call, "
			  << *this << ", id=" << _id << " deleted" << std::endl;
#endif
}

inline TComplex& TComplex::operator=(const TComplex &that) {
	this->_ro = that._ro;
	this->_phi = that._phi;
}

#endif //KMA_OOP_03LAB_TCOMPLEX_H
