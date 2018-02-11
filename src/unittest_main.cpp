//
//  Created by Oleh Kurachenko
//         aka soll_nevermind aka okurache
//  on 2018-02-11T22:57:07Z as a part of KMA_OOP_03Lab
//  
//  copying code from GitHub doesn't make you smarter,
//  better ask me oleh.kurachenko@gmail.com , I'm ready to help
//  
//  checkout my GitHub https://github.com/OlehKurachenko
//  rate, CV & contacts http://www.linkedin.com/in/oleh-kurachenko-6b025b111
//

#include <iostream>
#include <cassert>

#include "AComplex.h"
#include "TComplex.h"

int main() {
	AComplex a(4, 3);
	const AComplex b(a.conj());
	assert(a.re() == b.re() && a.im() == -b.im());
	TComplex c(5, 0);
	const TComplex d(c);
	assert(c == d);

	TComplex ac(a);
	assert(ac.mod() == a.mod());
	assert(ac.arg() == a.arg());
	AComplex tc(ac);
	assert(tc.re() == ac.re());
	assert(tc.im() == ac.im());
	//std::cout << a << ' ' << tc << std::endl;
	assert (tc == a);

	a = power(ac, 4);
	c = power(tc, 4);
	const AComplex f(c);
	assert(a == c);

	// Sunday, 11.45 PM...
}
