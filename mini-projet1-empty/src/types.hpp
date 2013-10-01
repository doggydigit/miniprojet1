#ifndef TYPE_H
#define TYPE_H

#include <array>
#include <iostream>
#include "rand_range.hpp"

namespace impl 
{
	typedef short bit_t;
	typedef std::array<bit_t,20> signal_t;
	typedef std::array<double,20> weights_t;
	bool bernoulli(double threshold)
	{
		// Retourne vrai si le générateur produit un nombre inférieur
		// à threshold et faux sinon
		return rand_range(0.0, 1.0) < threshold;
	}
}

#endif
