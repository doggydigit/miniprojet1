#include "neuron.hpp"

Neuron::Neuron()
{
	for(int i(0); i < 20; ++i)
	{
		weight[i] = rand_range(-15.,15.);
	}
}

void Neuron::process()
{
	if(!activ)
	{
		activ = 1;
	}
}
