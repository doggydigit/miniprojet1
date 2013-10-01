/*
 * Mini-projet 1:  stimulus
 * G'en'erateur de nombres pseudo-al'eatoires
 * dans un intervalle donn'e
 *
 * Etienne Wodey -- 2010-08
 * Marco Antognini -- 2011-08 (C++11)
 * Marco Antognini -- 2012-09 (C++11 etÂ suppression de boost)
 */

#ifndef _RAND_RANGE_
#define _RAND_RANGE_

#include <random>
#include <type_traits> //Â pour std::conditional et std::is_integral

// C++11 : <random>
// ---------------------------------------------------------------------
// A la place de srand/drand/... ou des outils de boost,
// la nouvelle norme met Ã  disposition
// des outils plus complet de gÃ©nÃ©ration de nombre alÃ©atoire.
// Un exemple est donnÃ© Ã  l'adresse suivante.
// http://en.wikipedia.org/wiki/C%2B%2B0x#Extensible_random_number_facility

template <typename T>
T rand_range(T min, T max)
{
    //Â Utilisation de "static" ici pour n'avoir qu'un seul gÃ©nÃ©rateur
    //Â de nombre alÃ©atoire et non pas un nouveau Ã  chaque fois que la
    //Â fonction est appelÃ©e. Sinon la distribution serait faussÃ©e.
    
    // Il existe de nombreux algorithme pour gÃ©nÃ©rer des nombres
    //Â alÃ©atoire. On aurait pu utiliser Mersenne Twister, aka
    //Â std::mt19937, ou autre, mais on va utiliser l'algorithme
    //Â par dÃ©faut.
    static std::default_random_engine algo;
    
    // Il faut aussi donner une "graine" Ã  l'algo pour avoir des
    // nombre alÃ©atoire diffÃ©rent entre deux lancement de l'application.
    // Mais comme avec srand, il faut le faire une seule fois.
    static bool initialise = true;
    if (initialise) {
        initialise = false;
        std::random_device rd;
        algo.seed(rd());
    }
    
    //Â On veut une distribution uniforme sur [min, max] mais en fonction
    //Â de T on veut gÃ©nÃ©rer des entiers ou des rÃ©els. On dÃ©finit donc
    //Â distribution_type, un alias en fonction de T.
    typedef typename std::is_integral<T> condition; //Â si TÂ est une sorte d'entier alors
    typedef typename std::uniform_int_distribution<T> integer_dist; //Â on veut ce type-ci
    typedef typename std::uniform_real_distribution<T> real_dist; //Â sinon ce type-lÃ 
    
    typedef typename std::conditional<condition::value, integer_dist, real_dist>::type distribution_type;
    
    //Â On dÃ©clare une distribution uniforme de nombres entiers/rÃ©els.
    distribution_type dist(min, max);
    
    //Â Et on gÃ©nÃ¨re un nombre avec notre algo sur notre distribution.
    return dist(algo);
}

#endif // _RAND_RANGE_
