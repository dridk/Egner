/*
This file is part of reseau_genes_prj.

reseau_genes_prj is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

reseau_genes_prj is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with reseau_genes_prj.  If not, see <http://www.gnu.org/licenses/>.

Copyright 2015 Pierre VIGNET, Victor YTHIER
*/

#include "Individu.h"
// PS: matrices à l'ancienne en lib standard : http://www.commentcamarche.net/forum/affich-1907231-produit-matriciel-en-c
// Tableau de tableaux dynamiques: http://cpp.developpez.com/faq/cpp/?page=Gestion-dynamique-de-la-memoire
// Documentation Qvector : http://qt.developpez.com/doc/4.7/qvector/

// Constructeur de copie => on utilise la liste d'initialisation
Individu::Individu(const Individu &individu) : m_matrice(individu.m_matrice),
    m_phenotype(individu.m_phenotype),
    //m_listePhenotypes(individu.m_listePhenotypes),
    m_variance(individu.m_variance),
    m_nbGenes(individu.m_nbGenes),
    m_viable(individu.m_viable),
    m_jeVeuxDesInts(individu.m_jeVeuxDesInts),
    m_nbMutationsSubies(individu.m_nbMutationsSubies),
    m_nbKOSubis(individu.m_nbKOSubis){
}

Individu& Individu::operator=(const Individu &individu)
{
    // Vérification qu'il ne s'agit pas du même objet...
    if(this != &individu)
    {
        // Chance : nous n'avons pas de pointeurs...
        m_matrice           = individu.m_matrice;
        m_phenotype         = individu.m_phenotype;
        //m_listePhenotypes   = individu.m_listePhenotypes;
        m_variance          = individu.m_variance;
        m_nbGenes           = individu.m_nbGenes;
        m_viable            = individu.m_viable;
        m_jeVeuxDesInts     = individu.m_jeVeuxDesInts;
        m_nbMutationsSubies = individu.m_nbMutationsSubies;
        m_nbKOSubis         = individu.m_nbKOSubis;
    }
    // PS quand même: this est un pointeur qui pointe vers l'objet courant.
    return *this;
}

Individu::Individu(const qint16 variance, const qint16 nbGenes, const bool jeVeuxDesInts)
{

    qDebug() << "Individu :: Creation par def...";

    m_variance      = variance;
    m_nbGenes       = nbGenes;
    m_viable        = false;
    m_jeVeuxDesInts = jeVeuxDesInts;
    m_nbMutationsSubies = 0;
    m_nbKOSubis     = 0;
}

Individu::Individu(const QVector<QVector<float>> parent1,
                   const QVector<QVector<float>> parent2,
                   const qint16 variance, const qint16 nbGenes, const bool jeVeuxDesInts)
{
//    qDebug() << "Individu :: Reproduction en cours, ne pas deranger...";
//    // Copie du génotype du parent1 et le combine au génotype du parent2

    m_variance      = variance;
    m_nbGenes       = nbGenes;
    m_viable        = false;

    m_matrice       = parent1;          // Copie provisoire de tout le génotype du parent1
    m_jeVeuxDesInts = jeVeuxDesInts;
    m_nbMutationsSubies = 0;
    m_nbKOSubis     = 0;


    // Pour le tirage des gènes (lignes de genotype) on utilise un tirage au sort simple dans [0, 1]
    // On prend ou ne prend pas le gène du parent...
    std::uniform_int_distribution<int> distribution(0, 1);
    std::default_random_engine generator;
    // Si on ne prend pas le gène du parent1, on prend le gène du violeur
    // 0: prend pas parent1
    // 1: prend parent1
    for (int y=0; y<m_nbGenes; y++) {

        if (distribution(generator) == 0) { // On prend le gène du violeur
            for (int x=0; x<m_nbGenes; x++)
                m_matrice[x][y] = parent2.at(x).at(y);
        }
    }

//    #ifndef QT_NO_DEBUG_OUTPUT
//        qDebug() << "Individu :: Parent1";
//        affichageGenotype(parent1);
//        qDebug() << "Individu :: Parent2";
//        affichageGenotype(parent2);
//        qDebug() << "Individu :: Enfant";
//        affichageGenotype();
//        PAUSE()
//    #endif
}

Individu::~Individu()
{
    // Destructeur
   // qDebug() << "Individu :: Destruction...";
}

Individu::Individu(const QString &seq)
{

    QStringList sp = seq.split(",");

    m_variance      = 1;
    m_nbGenes       = qSqrt(sp.size());
    m_viable        = false;

    m_jeVeuxDesInts = true;
    m_nbMutationsSubies = 0;
    m_nbKOSubis     = 0;
    m_phenotype         = QVector<float> (m_nbGenes);




    QVector<float> line;
    line.fill(0, m_nbGenes);
    m_matrice.fill(line,m_nbGenes);


    for (int i=0; i<sp.size(); ++i)
    {
        int y = i/m_nbGenes;
        int x = i%m_nbGenes;

        m_matrice[x][y] = sp[i].toFloat();
    }





}

void Individu::initialisationGenotype()
{
    // Génotype aléatoire...
    // suivant une loi normale, moyenne = 0, et d'écart type sqrt(variance = 1)
    std::normal_distribution<float> distribution(0.0,qSqrt(m_variance));
    std::default_random_engine generator;
    // Pour chaque nbGenes colonne on ajoute nbGenes lignes
    for (int i=0; i<m_nbGenes; i++) {
        QVector<float> colonne(m_nbGenes, 0);

        float *data = colonne.data();

        // Initialisation du génotype.. de chaque interaction

        // Si le paramètre jeVeuxDesInts a été spécifié, les matrices sont remplies par des entiers !
        if (m_jeVeuxDesInts == true) {
            for (int i = 0; i < m_nbGenes; i++)
                data[i] = qint8(distribution(generator));   // entiers
        } else {
            for (int i = 0; i < m_nbGenes; i++)
                data[i] = distribution(generator);          // float
        }

        m_matrice.append(colonne);
    }
}

void Individu::affichageGenotype() const
{
    // Affichage du genotype sous forme de matrice
    // On boucle sur y en premier car on affiche ligne par ligne à l'écran

    for (int y=0; y<m_nbGenes; y++) {
        QString ligne("[");
        for (int x=0; x<m_nbGenes; x++)
            ligne += QString::number(m_matrice.at(x).at(y)) + ",";

        ligne += "]";
        qDebug()<< ligne ;
    }
}

void Individu::affichageGenotype(const QVector<QVector<float>> &genotype) const
{
    // Affichage du genotype passé en paramètre sous forme de matrice
    // On boucle sur y en premier car on affiche ligne par ligne à l'écran

    for (int y=0; y<m_nbGenes; y++) {
        QString ligne("[");
        for (int x=0; x<m_nbGenes; x++) {
           ligne += QString::number(genotype.at(x).at(y)) + ",";
        }
        ligne += "]";
        std::cout << ligne.toStdString() << std::endl;
    }
}

void Individu::testViabilite()
{
    // Calcul de la viabilité
    // cad : même phénotype trouvé 2 fois d'affilée !
    // Si on a pas trouvé ce cas parmi les combinaisons possibles,
    //l'individu n'est pas considéré comme viable et son attribut m_viable est laissé à false

    //qDebug() << "Individu :: Test viabilite";

    // On réinitialise la liste des phénotypes par sécurité (sisi..)
    // Parceque si on redemande de calculer la viabilité une seconde fois, le chemin doit être vierge à nouveau
    m_listePhenotypes.clear();
    m_viable = false;

    m_phenotype = produitMatriciel(QVector<float>(m_nbGenes, 1));
    int numIteration = 0;

    do {

        m_listePhenotypes.append(m_phenotype);
        numIteration++;

        // Produit matriciel... & seuillage dans la foulée

        m_phenotype = produitMatriciel(m_phenotype);
        qDebug()<<"good:"<<m_phenotype;


        int positionPhenotype = m_listePhenotypes.indexOf(m_phenotype);



        // Viable car le dernier calculé équivaut au dernier dans la liste mémorisée
        if (positionPhenotype == (m_listePhenotypes.count()-1)) {

            // Changement de l'attribut
            m_viable = true;


            return;


        }// Pas viable
         // Détection d'une boucle
         // On sait déjà que le phénotype calculé n'est pas en dernière position
         // Mais le trouve t'on ailleurs ?
        else if ((positionPhenotype != -1) && (positionPhenotype < m_listePhenotypes.count())){

                //qDebug() << "Individu :: Phenotype trouve parmis les memorises, en position :" << numIteration;

                //m_viable = false; // pas utile c'est déjà initialisé au début de la fonction
                return;
        }

    } while (m_viable == false);
}

QVector<float> Individu::produitMatriciel(const QVector<float> &phenotype)
{
    // Récupère une référence : évite la copie en mémoire => plus rapide
    float totalLigne = 0.0;
    QVector<float> resultat;

    // On lit la matrice ligne par ligne
    for (int y=0; y<m_nbGenes; y++) {

        // Multiplication du premier item à gauche avec le premier item en haut du vecteur
        //puis addition du second item avec le (NON: premier) avec le DEUXIEME BORDEL... etc.
        // Jusqu'à multiplication du premier item à gauche de la 2ieme ligne avec le 2ieme item du vecteur etc.
        totalLigne = 0.0;
        for (int x=0; x<m_nbGenes; x++) {
            totalLigne += m_matrice.at(x).at(y) * phenotype.at(x);
        }
        resultat.append(totalLigne);
    }

//    qDebug() << "Individu :: Phenotype avant seuillage:" << resultat;
    seuillage(resultat);
//    qDebug() << "Individu :: Phenotype apres seuillage:" << resultat;
    return resultat;
}

void Individu::seuillage(QVector<float> &phenotype)
{
    // Référence => évite la copie en mémoire

    // La fonction de seuillage est différente selon le contenu: Entiers/Float

    if (m_jeVeuxDesInts == true) {
        // On conserve les zeros !
        for (int i=0; i<m_nbGenes; i++) {
            if (phenotype.at(i) < 0)
                phenotype[i] = -1;
            else if (phenotype.at(i) == 0)
                phenotype[i] = 0;
            else
                phenotype[i] = 1;
        }
    } else {
        // Si un chiffre est < 0 : -1, autrement: 1
        for (int i=0; i<m_nbGenes; i++) {
            if (phenotype.at(i) < 0)
                phenotype[i] = -1;
            else
                phenotype[i] = 1;
        }
    }
}

bool Individu::isViable()
{
    this->testViabilite();

    // Retourne l'attribut
    return m_viable;
}

QVector<float> Individu::getPhenotype() const
{
    // Retourne le phénotype de l'individu
    return m_phenotype;
}

QVector<QVector<float>> Individu::getGenotype() const
{
    // Retourne le génotype
    return m_matrice;
}

void Individu::mutationGenotype(const qint16 tauxMutations)
{
    // Mutations aléatoires sur le génotype selon le taux de mutations précisé
    //std::cout << "Individu :: Activation des mutations..." << std::endl;
    #ifndef QT_NO_DEBUG_OUTPUT
        qDebug() << "Individu :: Genotype AVANT Tchernobyl:";
        affichageGenotype();
    #endif

    m_nbMutationsSubies = 0;

    // Tirage déterminant si oui ou non la case lue doit muter
    std::uniform_real_distribution<float> distributionMutation(0, 100);
std::default_random_engine generator;
    // Valeur de la mutation (loi normale etc..)
    std::normal_distribution<float> distributionValMutation(0.0, qSqrt(m_variance));

    float seuil = (float)(tauxMutations) / (m_nbGenes*m_nbGenes);

    // Pour chaque nbGenes colonne on ajoute nbGenes lignes
    QVector<float> *dataMatrice = m_matrice.data();
    for (int x=0; x<m_nbGenes; x++) {

        float *dataColonne = dataMatrice[x].data();
        for (int y=0; y<m_nbGenes; y++) {

            // Si le tirage est < au seuil fixé : on applique une mutation sur la case concernée
            if (distributionMutation(generator) < seuil) {
                // Si le paramètre jeVeuxDesInts a été spécifié, les matrices sont remplies par des entiers !
                if (m_jeVeuxDesInts == true) {
                    dataColonne[y] = qint8(distributionValMutation(generator)); // cast en int;
                } else {
                    dataColonne[y] = distributionValMutation(generator);
                }
                // On incrémente le compteur de mutations
                m_nbMutationsSubies++;
                qDebug() << "Individu :: 1 mutation pour un %:" << tauxMutations;
            }
        }
    }

    #ifndef QT_NO_DEBUG_OUTPUT
        qDebug() << "Individu :: Genotype APRES Tchernobyl:";
        affichageGenotype();
        PAUSE()
    #endif
}

void Individu::knockOutGenotype(const qint16 tauxKO, qint16 nbKO, const ModeSelectionKO modeSelection, const int numero)
{
    //std::cout << "Individu :: Activation des KO..." << std::endl;

    #ifndef QT_NO_DEBUG_OUTPUT
        qWarning() << "Individu :: Genotype AVANT KO:";
        affichageGenotype();
    #endif

    m_nbKOSubis = 0;

    // Tirage déterminant si oui ou non l'individu doit subir un KO
    std::uniform_real_distribution<float> distributionKO(0, 100);
std::default_random_engine generator;
    // On réalise 1 tirage par nb de KO censé être appliqué à un individu
    if (distributionKO(generator) < tauxKO) {
        while (nbKO > 0) {

            // Sélection du gène:
            int numeroGeneKO = 0;


            if (modeSelection == ModeSelectionKO::ACTIVATEUR) {
                // qDebug() << "ACTIVATEUR !";

                // Sélection du gène ayant le plus d'influences sur les autres (activateur)
                float somme = 0;
                for (int x=0; x<m_nbGenes; x++) {
                    float sommeTemp = 0;
                    for (int y=0; y<m_nbGenes; y++)
                        sommeTemp += m_matrice.at(x).at(y);

                    if (sommeTemp>somme) {
                        somme = sommeTemp;
                        numeroGeneKO = x;
                    }
                }
            }
            else if (modeSelection == ModeSelectionKO::REPRESSEUR) {
                // qDebug() << "REPRESSEUR !";

                // Sélection du gène ayant le moins d'influences sur les autres (répresseur)
                // Initialisation de la somme...
                float somme = 0;
                for (int y=0; y<m_nbGenes; y++) {
                    somme += m_matrice.at(0).at(y); // peut générer exception si matrice vide
                }

                for (int x=0; x<m_nbGenes; x++) {
                    float sommeTemp = 0;
                    for (int y=0; y<m_nbGenes; y++)
                        sommeTemp += m_matrice.at(x).at(y);

                    if ((sommeTemp<somme) && (sommeTemp != 0)) { // On évite les genes déjà sous KO
                        somme = sommeTemp;
                        numeroGeneKO = x;
                    }
                }
            }
            else if (modeSelection == ModeSelectionKO::SPECIFIE) {
                // On utilise le paramètre de la fonction
                numeroGeneKO = numero;
            }
            else {
                // qDebug() << "RANDOM !";

                // Choix aléatoire du gene subissant 1 KO
                std::uniform_int_distribution<int> distributionNumGene(0, m_nbGenes-1);
                numeroGeneKO = distributionNumGene(generator);
            }
            
            qDebug() << "Individu :: KO sur le gene:" << numeroGeneKO;

            // On supprime la ligne et la colonne concernées (0 à chaque position)
            for (int i=0; i<m_nbGenes; i++) {

                // Suppression de la colonne x
                m_matrice[numeroGeneKO][i] = 0;

                // Suppression de la ligne y
                m_matrice[i][numeroGeneKO] = 0;
            }
            
            // On incrémente le compteur de KO
            m_nbKOSubis++;
            nbKO--;
        }
    }

    #ifndef QT_NO_DEBUG_OUTPUT
        qDebug() << "Individu :: Genotype APRES KO:";
        affichageGenotype();
        PAUSE()
    #endif
}

qint16 Individu::getNbMutations() const
{
    return this->m_nbMutationsSubies;
}

qint16 Individu::getNbKOs() const
{
    return this->m_nbKOSubis;
}

QList<QByteArray> Individu::getGenes(bool geneEnClair) const
{
    // Renvoie une liste des genes de l'individu
    // 1 Gene = 1 ligne
    // Problèmes:
    // Il n'y a pas de méthode qHash() pour le type QVector. Cf liste : http://doc.qt.io/qt-5/qhash.html#qHashx
    //=> difficile de mettre des QVector en clés dans un QHash
    // Idem pour une classe custom n'ayant pas cette fonction implémentée...
    // Voir : http://www.qtcentre.org/threads/15280-How-to-store-custom-class-in-QHash
    // "QObjects can't be copied and QHash requires the key class to be mutable and have the qHash() function defined.
    //From what I see you violated both requirements"

    // Solution:
    // Il est inutile et couteux de recopier les QVector dans le QHash.
    // Ici on ne cherche pas à les récupérer sous une autre forme que du texte..
    // Or QByteArray a la méthode qHash() implémentée..
    //=> Stockons des QByteArray !


    // Doc: http://doc.qt.io/qt-5/qhash.html
    // Aide: http://openclassrooms.com/courses/qt-quelques-fonctionnalites-non-gui/hacher-avec-qt-1

    QList<QByteArray> listeGenes;
    //QString colonne;
    QByteArray ligne;

    for (int j=0; j<m_nbGenes; j++) {
        //colonne.clear();
        ligne.clear();

        for (int i=0; i<m_nbGenes; i++) {
            // PS: Pourquoi QString::number() ?
            // Valgrind nous montre que QByteArray::number() passe par QString pour la conversion..
            //=> 2 étapes de plus pour un objet censé être de plus bas niveau...

            // Récupération de la colonne x
            //colonne += QString::number(m_matrice.at(j).at(i)) + ",";

            // Recupération de la ligne y
            ligne += QString::number(m_matrice.at(i).at(j)).toLatin1() + ",";
        }

        // On stocke soit les gènes en clair soit leur hash md5...
        if (geneEnClair == true)
            //listeGenes.append(QString("[" + colonne + "],[" + ligne + "]").toLatin1());
            //listeGenes.append("[" + ligne + "]");
            listeGenes.append(ligne); // sans crochets: pas de mise en forme
        else
            //listeGenes.append(QCryptographicHash::hash(QString(colonne + ligne).toUtf8(), QCryptographicHash::Md5));
            listeGenes.append(QCryptographicHash::hash(ligne, QCryptographicHash::Md5));
        /*
        qDebug() << "Individu :: gene:col:" << colonne;
        qDebug() << "Individu :: gene:lig:" << ligne;
        */
    }
    #ifndef QT_NO_DEBUG_OUTPUT
        qDebug() << "Individu :: listegenes:";
        qDebug() << listeGenes << "\n";
        PAUSE()
    #endif
    return listeGenes;
}

QByteArray Individu::getGene(int index) const
{
    QByteArray gene;

    for (int i=0; i<m_nbGenes; i++) {
        // PS: Pourquoi QString::number() ?
        // Valgrind nous montre que QByteArray::number() passe par QString pour la conversion..
        //=> 2 étapes de plus pour un objet censé être de plus bas niveau...

        // Récupération de la colonne x
        //colonne += QString::number(m_matrice.at(j).at(i)) + ",";

        // Recupération de la ligne y
        gene += QString::number(m_matrice.at(i).at(index)).toLatin1() + ",";
    }

    return gene.remove(gene.length()-1, 1); // Supression virgule...
}

qint16 Individu::getNbGenes() const
{
    return m_nbGenes;
}

QDataStream & operator << (QDataStream &out, const Individu &element)
{
    out << element.m_matrice;
    out << element.m_phenotype; // Sauvegarde aussi du phénotype commun

    return out;
}

QDataStream & operator >> (QDataStream &in, Individu &element)
{
    in >> element.m_matrice;
    in >> element.m_phenotype; // Sauvegarde aussi du phénotype commun

    return in;
}

void Individu::initIndividuSystem()
{
    // Indique à QVariant que les opérateurs de flux ont été définis

    // Finit de déclarer pour QVariant les opérateurs de flux
    qRegisterMetaTypeStreamOperators<Individu>("Individu");

    // Fait échouer la compilation si Q_DECLARE_METATYPE échoue
    // Teste la validité de la classe Individu
    qMetaTypeId<Individu>();
}
