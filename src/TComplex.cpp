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
#include "TComplex.h"
#include "AComplex.h"

unsigned TComplex::_freeId(0);

TComplex::TComplex(const AComplex &aComplex):
		_id(++_freeId),
		_ro(aComplex.mod()),
		_phi(aComplex.arg())
{
#ifndef NDEBUG
	std::cout << "constructor TComplex(" << aComplex << ") call, "
			  << *this << ", id=" << _id << " created" << std::endl;
#endif
}

std::ostream& operator<<(std::ostream &ostr, const TComplex &tComplex) {
	ostr << tComplex.mod() << "*(cos(" << tComplex.arg() << ")+i*sin(" << tComplex.arg() << "))";
}

std::istream& operator>>(std::istream &istr, TComplex &tComplex) {
	// TODO handle wrong input
	char temp_str[9];
	istr >> tComplex.mod();
	istr.read(temp_str, 6);
	istr >> tComplex.arg();
	istr.read(temp_str, 8);
	istr >> tComplex.arg();
	istr.read(temp_str, 2);
}