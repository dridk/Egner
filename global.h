#ifndef GLOBAL
#define GLOBAL

#include <QCoreApplication>

// Lib standard
#include <random>

// Quelques définitions de variables et structures globales

// http://qt.developpez.com/doc/4.7/qtglobal/#q-os-win32
#ifdef Q_OS_WIN32
    #define PAUSE() system("pause");
#else
    #define PAUSE() std::cout << "Appuyez sur Entree pour continuer...\n" << std::endl; \
                    getchar();
#endif

// Enumération pour le paramètre de sélection du gène devant subir 1 KO
enum ModeSelectionKO {RANDOM, ACTIVATEUR, REPRESSEUR, SPECIFIE};

// Déclaration d'une structure contenant les options à caractère évolutif
struct OptionsEvolutives {
    qint16 tauxMutations;           // Proba de mutations par génotype pr chaque indiv
    qint16 tauxKO;                  // Proba de KO par population d'individus
    qint16 nbKnockOut;              // Nombre de KO par individu
    qint16 numGenerationDebutMut;   // Numéro de la génération où les mutations vont commencer (0 pour désactiver)
    qint16 numGenerationDebutKO;    // Numéro de la génération où les KO vont commencer (0 pour désactiver)
    qint16 numGenerationFinMut;     // Numéro de la génération où les mutations vont s'arrêter ( 0 toutes concernées)
    qint16 numGenerationFinKO;      // Numéro de la génération où les KO vont s'arrêter ( 0 toutes concernées)
    ModeSelectionKO selectKO;
};

// Déclaration d'une structure contenant les options génériques de maîtrise du programme
struct OptionsGeneriques {
    qint16 taillePopulation;
    qint16 nombreGenerations;
    qint16 nbGenes;
    qint16 varianceLoiNormale;
    bool jeVeuxDesInts;
    bool jeVeuxDesGenesEnClair;
    bool no_output;
};


#endif // GLOBAL

