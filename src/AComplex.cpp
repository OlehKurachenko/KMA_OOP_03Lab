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

unsigned AComplex::_freeId(0);

std::ostream& operator<<(std::ostream &ostr, const AComplex &aComplex) {
	ostr << aComplex.re();
	if (aComplex.im() > 0) ostr << '+';
	ostr << aComplex.im() << 'i';
	return ostr;
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

const AComplex power(const AComplex &aComplex, unsigned power_val) {
	AComplex res(1);
	AComplex temp(aComplex);
	while (power_val) {
		if (power_val & 1)
			res *= temp;
		temp *= temp;
		power_val >>= 1;
	}
	return res;
}

std::istream& operator>>(std::istream &istr, AComplex &aComplex) {
	// TODO handle wrong input
	char temp;
	istr >> aComplex.re();
	istr >> aComplex.im();
	istr >> temp;
	if (temp != 'i')
		; // TODO ask what is that best way to handle it
	return istr;
}
