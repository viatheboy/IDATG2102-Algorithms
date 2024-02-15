#include <iostream>
using namespace std;

struct Node {
    char ID;
    bool besokt;
    Node *left, *right;                
    Node(char id)  {  ID = id;  left = right = nullptr;   besokt = false;  }
};


int antallNoder(Node* node);
void antallNull(Node* node);
void antallFulle(Node* node);
void høyde(Node* node);
Node* byggTre();


int gAntallNull = 0;
int gAntallFulle = 0;
int gNivå = -1;
int gHøyeste = 0;

/**
 * Hovedprogram
 */
int main() {
    Node* root;

    root = byggTre();

    // Total antall noder
    cout << "\nAntall fulle noder: " << antallNoder(root) << endl;

    // Antall nullptr
    antallNull(root);
    cout << "\nAntall nullptr: " << gAntallNull << endl;

    // Antall fulle noder
    cout << "\nFulle noder: \n";
    antallFulle(root);
    cout << "\nAntall fulle noder: " << gAntallFulle << endl;

    // Høyeste nivå
    høyde(root);
    cout << "\nHøyeste nivå: " << gHøyeste << endl;

    return 0;
}

/**
 *  Teller opp 'gAntallFulleNoder' om 'node' har to interne barn/subnoder,
 *
 *  @param   node  -  Aktuell node � behandle
 */
void besok(const Node* node) {
    cout << node->ID << endl;       //  Skriver nodens ID/key/data.
}

/*   Bygger treet:                                     A
                                              /                 \
                                         B                          C
                                    /         \                  /
                                  D             E              F
                              /       \           \          /
                            G           H           I      J
                              \        / \         /        \
                               K      L   M       N          O
*/
Node* byggTre() {

    Node*  noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast <char> ('A' + i));

    noder[0]->left = noder[1];  noder[0]->right = noder[2];
    noder[1]->left = noder[3];  noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];  noder[3]->right = noder[7];
                                noder[4]->right = noder[8];
    noder[5]->left = noder[9];
                                noder[6]->right = noder[10];
    noder[7]->left = noder[11]; noder[7]->right = noder[12];
    noder[8]->left = noder[13];
                                noder[9]->right = noder[14];
    return noder[0];
}


/* 
* Oppgave 6a
* Lag en funksjon som teller antall noder i et tre
* Usikker på om denne er riktig. 
*/
int antallNoder(Node* node) {
    if (node) {
        return 1 + antallNoder(node->left) + antallNoder(node->right);
    } else {
        return 0;
    }
}

/*
 * Oppgave 6b
 * Lag en funksjon som teller opp antall nullptr.  
 */

void antallNull(Node* node) {
    if (node) {
        antallNull(node->left);
        antallNull(node->right);
    } else {
        gAntallNull++;
    }
}

/*
* Oppgave 6c
* Lag en funksjon som teller opp antall fulle noder.
*/
void antallFulle(Node* node) {
    if (node) {
        if (node->left && node->right) {
            gAntallFulle++;
            besok(node);
        }
        if (node->left || node->right) {
            antallFulle(node->left);
            antallFulle(node->right);
        }
    } 
}

/*
* Oppgave 6d
* Lage en funksjon som teller treets høyde
*/
void høyde(Node* node) {
    if (node) {
        gNivå++;
        if (gNivå > gHøyeste) {
            gHøyeste = gNivå;
        }
        høyde(node->left);
        høyde(node->right);
        gNivå--;
    }
}