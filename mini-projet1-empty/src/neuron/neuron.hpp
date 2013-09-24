#ifndef NEURON_H
#define NEURON_H

#include <isotream>
#include "rand_range.hpp"

using namespace std;

class Neuron: 
{
public:
	Neuron();
	~Neuron();
	void process();
protected:

private:
	impl::weights_t weight;
	bool activ;
};

#endif
