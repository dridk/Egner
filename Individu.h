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

#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QtMath>
#include <QByteArray>
#include <QCryptographicHash>

// Sérialisation
#include <QDataStream>
#include <QVariant>

// Lib standard
#include <random>
#include <iostream>

#include "global.h"


// Générateur pseudo-aléatoire défini dans le main
extern std::default_random_engine generator;

class Individu
{

    public:
        //typedef QVector<QVector<float>> Matrice;

        // Constructeur de copie
        Individu(Individu const &individu);
        // Surcharge de l'opérateur d'affectation
        Individu& operator=(Individu const &individu);

        // Constructeur par défaut (oui il y a des paramètres mais ils sont facultatifs) - Conception naturelle aléatoire
        Individu(const qint16 variance = 1, const qint16 nbGenes = 5, const bool jeVeuxDesInts = true);
        // Constructeur sruchargé - Génotype calculé d'après ceux des parents
        Individu(const QVector<QVector<float>> parent1,
                 const QVector<QVector<float>> parent2,
                 const qint16 variance = 1, const qint16 nbGenes = 5, const bool jeVeuxDesInts = false);
        ~Individu();
        Individu(const QString& seq);


        void initialisationGenotype();
        void affichageGenotype() const;
        QVector<QVector<float>> getGenotype() const;

        bool isViable();
        QVector<float> getPhenotype() const;
        QList<QByteArray> getGenes(bool geneEnClair = false) const;
        QByteArray getGene(int index) const;
        qint16 getNbGenes() const;

        // Appliquer les mutations
        void mutationGenotype(const qint16 tauxMutations = 20);
        qint16 getNbMutations() const;
        // Appliquer les KO
        void knockOutGenotype(const qint16 tauxKO = 5, qint16 nbKO = 1, const ModeSelectionKO modeSelection = ModeSelectionKO::RANDOM, const int numero = 0);
        qint16 getNbKOs() const;


        // Indique à QVariant que les opérateurs de flux ont été définis
        // Finit de déclarer pour QVariant les opérateurs de flux
        // Fait échouer la compilation si Q_DECLARE_METATYPE échoue
        static void initIndividuSystem ();

    private slots:
        QVector<float> produitMatriciel(const QVector<float> &phenotype);
        void affichageGenotype(const QVector<QVector<float>> &genotype) const;
        void testViabilite();
        void seuillage(QVector<float> &phenotype);


    private:

        QVector<QVector<float>>     m_matrice;          // Génotype de l'individu
        QVector<float>              m_phenotype;        // Phénotype de l'individu
        QList<QVector<float>>       m_listePhenotypes;
        qint16                      m_variance;         // Variance utilisée pour générer les génotypes & mutations
        qint16                      m_nbGenes;          // Nombre de gènes (cad nombre de colonnes/lignes du génotype)
        bool                        m_viable;           // Viabilité de l'individu

        bool                        m_jeVeuxDesInts;    // Remplissage des génotypes avec des entiers ou des doubles
        qint16                      m_nbMutationsSubies;// Nombre de mutations subies par l'enfant selon le taux spécifié
        qint16                      m_nbKOSubis;        // Nombre de KO subis par l'enfant selon le taux spécifié


        // Opérateurs de flux (fonctions amies pour permettre l'accès à l'extérieur de la classe)
        friend QDataStream & operator << (QDataStream &, const Individu &);
        friend QDataStream & operator >> (QDataStream &, Individu &);
};


    /* PS : un objet sérialisable doit:
     * - posséder un constructeur public par défaut (ou alors tous ses arguments doivent avoir une valeur par défaut)
     * - posséder un constructeur de copie public ;
     * - posséder un destructeur public.
     **/
    Q_DECLARE_METATYPE(Individu) // Ne pas oublier d'inclure QVariant
    QDataStream & operator << (QDataStream &out, const Individu &element);
    QDataStream & operator >> (QDataStream &in, Individu &element);

#endif // INDIVIDU_H
