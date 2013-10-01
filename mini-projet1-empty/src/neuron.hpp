#ifndef NEURON_H
#define NEURON_H

#include "types.hpp"

using namespace std;

class Neuron: 
{
public:
	Neuron();
	~Neuron();
	void process(impl::signal_t s);
	bool activated();
	
protected:

private:
	impl::weights_t weight;
	bool activ;
};

#endif
