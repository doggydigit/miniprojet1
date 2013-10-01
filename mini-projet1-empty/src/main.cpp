#include "neuron.hpp"
#include <sstream>

/*
int rand_number_neurons = rand() % 50000;
int signal_number;
*/
//randomly creates neurons
void createNeurons(vector<Neuron> &N, int number = 10000)
{
	//number=rand_number_neurons;
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
	int arg[3];
	for(int i(0); i < argc; ++i)
	{

		stringstream convert;
		convert << argv[i];
		convert >> arg[i];

	}
	vector<Neuron> Neurons;
	createNeurons(Neurons, arg[1]);
	vector<Signal> Signals;
	createSignals(Signals, arg[2]);
	
	if(arg[0] == 'b' or argc == 0)
	{
		int bestscore(0);
		int bestNeuron;
		for(unsigned int i(0); i < Neurons.size(); ++i)
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
	
	
	}else if(arg[0] == 'd'){
		
		//graphe etc...
		
	}else{
		cerr << "Sorry... ):" << endl;
		cerr << "False call to programm!" << endl;
		cerr << "Try with following order:" << endl;
		cerr << "./bin/stimulus -d [-s [val] -n [val]]" << endl;
	}
	
return 0;
}
