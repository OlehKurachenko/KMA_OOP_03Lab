//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  on 2018-02-10T13:02:31Z as a part of KMA_OOP_03Lab
//  
//  copying code from GitHub doesn't make you smarter,
//  better ask me oleh.kurachenko@gmail.com , I'm ready to help
//  
//  checkout my GitHub https://github.com/OlehKurachenko
//  rate, CV & contacts http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//  
#ifndef KMA_OOP_03LAB_ACOMPLEX_H
#define KMA_OOP_03LAB_ACOMPLEX_H

#include <iostream>
#include <cmath>

//	Class methods & utills prototypes are taken from
// http://distedu.ukma.edu.ua/course/view.php?id=11 (may be unavailable for unregistered users),
// which is a part of mandatory requirements

class TComplex;

class AComplex;

std::ostream& operator<<(std::ostream &, const AComplex &);

class AComplex {
public:
	inline AComplex(double re = 0, double im = 0);
	// TODO implement
	//AComplex(const TComplex&);
	inline AComplex(const AComplex&);
	inline ~AComplex();

	inline AComplex& operator=(const AComplex&);

	inline double& re() { return this->_re; }
	inline double& im() { return this->_im; }

	inline double re() const { return this->_re; }
	inline double im() const { return this->_im; }

	inline double mod() const { return std::sqrt(re() * re() + im() * im()); }
	inline double arg() const;

	inline const AComplex conj() const;
private:
	double _re, _im;
	static unsigned _freeId;
	const unsigned _id;
};

inline AComplex& operator+=(AComplex&, const AComplex&);
inline AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

inline const AComplex operator+(const AComplex&, const AComplex&);
inline const AComplex operator-(const AComplex&, const AComplex&);
const AComplex power(const AComplex&, unsigned int);

inline bool operator==(const AComplex&, const AComplex&);
inline bool operator!=(const AComplex&, const AComplex&);

std::istream& operator>>(std::istream &, AComplex&);

// Definitions

inline AComplex::AComplex(double re, double im):
		_id(++_freeId),
		_re(re),
		_im(im)
{
#ifndef NDEBUG
	std::cout << "constructor AComplex(re=" << re << ", im=" << im << ") call, "
			  << *this << ", id=" << _id << " created" << std::endl;
#endif
}

inline AComplex::AComplex(const AComplex &that):
		_id(++_freeId),
		_re(that._re),
		_im(that._im)
{
#ifndef NDEBUG
	std::cout << "constructor AComplex(re=" << that << ") call, "
			  << *this << ", id=" << _id << " created" << std::endl;
#endif
}

inline AComplex::~AComplex() {
#ifndef NDEBUG
	std::cout << "destructor AComplex call, "
			  << *this << ", id=" << _id << " deleted" << std::endl;
#endif
}

inline AComplex &AComplex::operator=(const AComplex &that) {
	this->_re = that._re;
	this->_im = that._im;
	return *this;
}

inline double AComplex::arg() const {
	// Expression: https://en.wikipedia.org/wiki/Argument_(complex_analysis)#Computation
	if (_re == 0 && _im == 0)
		return 0.0/0.0; // return NAN
	if (_re < 0 && _im == 0)
		return M_PI;
	return 2 * std::atan(_im / (mod() + _re));
}

inline const AComplex AComplex::conj() const {
	return AComplex(this->_re, -(this->_im));
}

inline AComplex& operator+=(AComplex &aComplex, const AComplex &val) {
	aComplex.re() += val.re();
	aComplex.im() += val.im();
}

inline AComplex& operator-=(AComplex &aComplex, const AComplex &val) {
	aComplex.re() -= val.re();
	aComplex.im() -= val.im();
}

inline const AComplex operator+(const AComplex &one, const AComplex &another) {
	AComplex temp(one);
	return temp+=another;
}

inline const AComplex operator-(const AComplex &one, const AComplex &another) {
	AComplex temp(one);
	return temp-=another;
}

inline bool operator==(const AComplex &one, const AComplex &another) {
	return one.im() != another.im() && one.re() == another.re();
}

inline bool operator!=(const AComplex &one, const AComplex &anohter) {
	return !(one == anohter);
}

#endif //KMA_OOP_03LAB_ACOMPLEX_H
