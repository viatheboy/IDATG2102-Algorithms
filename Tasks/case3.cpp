#include <iostream>
using namespace std;


struct Node {
    char ID; // Nodens ID/key/navn (en bokstav).
    int nivaa; // Nodens nivå i treet ift. rotnoden.
    Node* left; // Peker til venstre subtre, evt nullptr.
    Node* right; // Peker til høyre subtre, evt nullptr.

    Node() { ID = '-'; nivaa = 0; left = right = nullptr; }
};


void  besok(Node* node);
void  bladTilRot(Node* node, Node* blad);
void  finnVerdier(Node* node, int & sumNivaa, int & antall);    //  OPPGAVE B
Node* generate(const int depth, const int probability);
void  settNivaa(Node* node);                                     //  OPPGAVE A
void  skrivForfedre(Node* node);                                 //  OPPGAVE C
void  traverse(Node* node); 

Node* gRoot = nullptr;      // Rot-peker
int gNumber = 65;


/**
 *  Hovedprogrammet:
 */
int main() {
    int sumNiva = 0, antall = 0;  //  Viktig at begge er nullstilt.
    char ch;

    srand(0);                     //   Brukes ifm. tilfeldighet/randomisering.

    cout << "\nNodene i starttreet:\n";
                                  //  Genererer et testtre (max. 6 niv�er,
    gRoot = generate(5, 80);      //      80% sjanse for � lage et subtre)
    traverse(gRoot);              //  Traverserer (og viser) treet.
    cin >> ch;

    cout << "\n\nTester oppgave A - Nodene etter at 'nivaa' er satt:\n";
    settNivaa(gRoot);             //  Setter ALLE nodenes niv�.
    traverse(gRoot);              //  Traverserer (og viser) treet.
    cin >> ch;
    
    cout << "\n\nTester oppgave B - Finner niv�er TOTALT og antall noder:\n";
    finnVerdier(gRoot, sumNiva, antall);   //  Finner summen av nodenes niv�
                                           //      og antall.
    cout << "Sum niv�:  " << sumNiva << "\tAntall: " << antall << '\n';

    cout << "Gjennomsnittsniv�et i treet:  "         //  Regner ut gj.snittlig
         << static_cast <float> (sumNiva) / antall;  //    niv�.
    cin >> ch;
    /*
    cout << "\n\nTester oppgave C - Alle bladnodenes forfedre:\n";
    skrivForfedre(gRoot);         //  Skriver forgjengere til ALLE bladnodene.
    cout << "\n\n";
    */

    return 0;
}


/**
 *  Bes�ker/visit/skriver ut en nodes innhold/data.
 *
 *  @param   node  -  Aktuell node � skrive ut
 */
void besok(Node* node) {       //  Viser innholdet i EN node.
    cout << ' ' << node->ID << ":  " << node->nivaa << '\n';
}


/**
 *  Rekursiv funksjon som (om mulig) genererer en node
 *  og KANSKJE dets venstre og/eller h�yre subtre.
 *
 *  @param    depth        -  Aktuell (dybde)niv� i treet
 *  @param    probability  -  Sannsynlighet for � lage subtre
 *  @return   Peker til det genererte (sub)treet
 */
Node* generate(const int depth, const int probability) {
    Node* rot = nullptr;                   //  Peker til det som returneres.
                                           //  NB: Initieres til 'nullptr'!
    if (depth > 0) {                       //  Kan fortsatt legge til et niv�:
        if (rand() % 100 < probability) {  //  Trukket tall i rett intervall:
            rot = new Node;                //  Lager en ny node.
            rot->left = generate(depth-1, probability); //Lager evt v.subtre.
            rot->ID = static_cast <char> (gNumber++);  //  Legger inn egen ID.
            rot->right = generate(depth-1, probability); //Lager evt h.subtre.
        }
    }
    return rot;                     //  Returnerer generert tre eller nullptr.
}

/**
 * @brief Oppgave a)
 * 
 * @param node 
 */

void settNivaa(Node* node) {
    
    if (node) {                 // Vi vet at node alltid er ulikt nullptr
        if (node->left) {
            node->left->nivaa = node->nivaa+1;
            settNivaa(node->left);
        }
        if (node->right) {
            node->right->nivaa = node->nivaa+1;
            settNivaa(node->right);
        }
    }

}


/**
 * @brief Oppgave b)
 * 
 */
void finnVerdier(Node* node, int & sumNivaa, int & antall) {
    
    if (node) {
        sumNivaa += node->nivaa;
        antall++;
        finnVerdier(node->left, sumNivaa, antall);
        finnVerdier(node->right, sumNivaa, antall);
    }

}


/**
 *  Traverserer/g�r gjennom et tre rekursivt p� en INORDER m�te.
 *
 *  @param   node  -  Aktuell node � behandle
 *  @see     besok(...)
 */
void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        besok(node);
        traverse(node->right);
    }
}


/**
 * @brief Oppgave c)
 * 
 * @param node 
 */
void  skrivForfedre(Node* node) {
    if (node) {
        if (!node->left && !node->right) {
            Node* start = gRoot;

            while (start) {
                cout << start->ID << " ";

                if (node->ID < start->ID) {
                    start = start->left;
                } else {
                    start = start->right;
                }
            }
        } else {
            skrivForfedre(node->left);
            skrivForfedre(node->right);
        }
    }
}