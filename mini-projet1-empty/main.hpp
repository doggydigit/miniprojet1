#include "types.hpp"
#include "signal.hpp"
#include "neuron.hpp"
/*
int rand_number_neurons = rand() % 50000;
int signal_number;
*/
//randomly creates neurons
void createNeurons(vector<Neuron> &N, int number = 10000)
{
	number=rand_number_neurons;
	for(int i(0); i < number; i++)
	{
		N.push_back(Neuron());
	}
}

//creates signals
void createSignals(vector<Signal> &S, int number = 1000)
{
	for(int i(0); i < number; i++)
	{
		S.push_back(Signal(rand_range(0,1)));
	}
}


int main(int argc, char* argv[])
{
	vector<Neuron> Neurons;
	createNeurons(Neurons, argv[1]);
	vector<Signal> Signals;
	createSignals(Signals, argv[2]);
	
	if(argv[0] == 'b' or argc == 0)
	{
		int bestscore(0);
		int bestNeuron;
		for(int i(0); i < Neurons.size(); ++i)
		{
			int score(0);
			for(int j(0); j < Signals.size(); ++j)
			{	
				Neurons[i].process(Signals[j].getSignal());
				if(Neurons[i].activated() == Signals[j].presence())
				{
					++score;
				}
			}
			if(score > bestscore)
			{
				bestscore = score;
				bestNeuron = i;
			}
		}
	
	
	}else if(argv[0] == 'd'){
		
		//graphe etc...
		
	}else{
		cerr << "Sorry... ):" << endl;
		cerr << "False call to programm!" << endl;
		cerr << "Try with following order:" << endl;
		cerr << "./bin/stimulus -d [-s [val] -n [val]]" << endl;
	}
	
return 0;
}
