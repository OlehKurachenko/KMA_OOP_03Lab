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
#include "AComplex.h"

std::ostream& operator<<(std::ostream &ostr, const AComplex &aComplex) {
	ostr << aComplex.re();
	if (aComplex.im() > 0) ostr << '+';
	ostr << aComplex.im() << 'i';
	return ostr;
}

AComplex& operator+=(AComplex &aComplex, const AComplex &val) {
	aComplex.re() += val.re();
	aComplex.im() += val.im();
}

AComplex& operator-=(AComplex &aComplex, const AComplex &val) {
	aComplex.re() -= val.re();
	aComplex.im() -= val.im();
}

AComplex& operator*=(AComplex &aComplex, const AComplex &val) {
	double temp_im(aComplex.im() * val.re() + aComplex.re() * val.im());
	aComplex.re() = aComplex.re() * val.re() - aComplex.im() * val.im();
	aComplex.im() = temp_im;
}

AComplex& operator/=(AComplex &aComplex, const AComplex &val) {
	double val_mod(val.mod());
	double temp_im((aComplex.re() * val.re() + aComplex.im() * val.re()) / val_mod);
	aComplex.re() = (aComplex.im() * val.re() - aComplex.re() * val.im()) / val_mod;
	aComplex.im() = temp_im;
}

const AComplex operator+(const AComplex &one, const AComplex &another) {
	AComplex temp(one);
	return temp+=another;
}

const AComplex operator-(const AComplex &one, const AComplex &another) {
	AComplex temp(one);
	return temp-=another;
}
