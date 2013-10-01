#include "neuron.hpp"

Neuron::Neuron()
{
	for(int i(0); i < 20; ++i)
	{
		weight[i] = rand_range(-15.,15.);
	}
}

void Neuron::process(impl::signal_t s)
{
	if(std::inner_product(weight, weight + 20, s, 0) >= 0){
		activ == 1;
	}else{
		activ == 0;
	}
}

bool Neuron::activated(){
	return activ;
}
