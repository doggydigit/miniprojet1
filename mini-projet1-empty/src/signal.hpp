##ifndef SIGNAL_H
#define SIGNAL_H

#include "types.hpp"

using namespace std;

class Signal: 
{
   
public:

	Signal(bool presence);
	bool presence();
	
	// une méthode getSignal() qui retournera un référence constante sur le signal courant (*this).
	impl::signal_t getSignal();
	
protected:


private:

	//un booléen objectPresent permettant de connaître l'information initialement détenue par le signal (présence ou absence d'objet dans le champ visuel);
	bool objectPresent;

	//une séquence de vingt bits de type impl::signal_t modélisant le signal;
	impl::signal_t input_sequence;




};

#endif
