#include "types.hpp"
#include "signal.hpp"
#include "neuron.hpp"

int rand_number_neurons = rand() % 50000;
int signal_number;

//randomly creates neurons
createNeurons(int number=10000)
{
	number=rand_number_neurons;
	for(int i(0); i<number; i++)
	{
		Neuron::Neuron();
	}
}

//creates signals
createSignals(int number=1000)
{
	for(int i(0); i<number; i++)
	{
		Signal::Signal();
	}
}


int main(int argc, char* argv[])
{
	createNeurons();
	createSignals();

	bestScore();

return 0;
}
