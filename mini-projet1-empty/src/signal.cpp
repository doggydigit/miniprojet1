#include "signal.hpp"

//constructor
Signal::Signal(bool presence): objectPresent(presence)
{
	if (objectPresent)
	{
		input_sequence = {{1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0}};
	}else{
		input_sequence = {{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1}};
	}
	for(int i(0); i < 20; ++i)
	{
		if(impl::bernoulli(0.1) == true)
		{
			if(input_sequence[i] == 1)
			{
				input_sequence[i] = 0;
			}else{
				input_sequence[i] = 1;
			}
		}
	}
}

Signal::~Signal(){}

bool Signal::presence()
{
	return objectPresent;
}

impl::signal_t Signal::getSignal()
{
	return input_sequence;
}
