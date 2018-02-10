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

//	Class methods & functios prototypes are taken from
// http://distedu.ukma.edu.ua/course/view.php?id=11 (may be unavailable for unregistered users),
// which is a part of mandatory requirements

class TComplex;

class AComplex {
public:
	AComplex (double re=0, double im=0);
	AComplex (const TComplex&);
	AComplex (const AComplex&);
	~AComplex();

	AComplex& operator= (const AComplex&);

	double& re();
	double& im();

	double re() const;
	double im() const;

	double mod() const;
	double arg() const;

	const AComplex conj() const;
private:
	double _re, _im;
	static unsigned _freeId;
	unsigned _id;
};

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex  operator+ (const AComplex&, const AComplex&);
const AComplex  operator- (const AComplex&, const AComplex&);
const AComplex  power(const AComplex&, unsigned int);

bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);

std::ostream& operator<<(std::ostream &, const AComplex &);
std::istream& operator>>(std::istream &, AComplex&);


#endif //KMA_OOP_03LAB_ACOMPLEX_H
