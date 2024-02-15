/**
 *   Hovedrisset til oblig nr 2.
 *
 *   For programmets funksjonalitet se:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>
using namespace std;


/**
 *  Node (med ID/key/data og venstre/høyre pekere til nodens barn).
 */
struct Node {
  int ID;                      //  Nodens ID/key/nøkkel/navn (et tall).
  Node *left, *right;          //  Peker til begge subtrærne (evt. 'nullptr').
  Node(int id) { ID = id;  left = right = nullptr; }
};


void byggTre();


Node* gRoot = nullptr;          ///<  Peker til treet rot.


/**
 *  OPPGAVE A: Skriver ut ALLE noder med ID i intervallet 'min'-'max'.
 *
 *  @param   node   -  Noden som skal besøkes/undersøkes
 *  @param   min    -  minste verdi for en utskrevet node sin ID
 *  @param   max    -  største verdi for en utskrevet node sin ID
 */
void skrivIntervall(const Node* node, const int min, const int max) {
  if (node) {
    if ((node->ID >= min) && (node->ID <= max)) {
      cout << node->ID << " ";
    }
    skrivIntervall(node->left, min, max);
    skrivIntervall(node->right, min, max);
  }
}


/**
 *  OPPGAVE B: Skriver alle VENSTRE BLADNODER i treet.
 *
 *   @param   node  -  Noden som skal besøkes.
 */
void skrivVenstreBladnode(const Node* node) {
  if (node) {

    if (node->left) {
      node = node->left;

      if (!node->left && !node->right) {
        cout << node->ID << " ";
      } else {
        skrivVenstreBladnode(node);
      }

    } 
    
    if (node->right) {
      skrivVenstreBladnode(node->right);
    }
  }
}


/**
 *  Hovedprogrammet:
 */
int main() {

  byggTre();

  cout << "\n\nOppgave A:";
  cout << "\n\tNoder i intervallet 5 - 11: ";//  Skriver alle verdiene 5-11 i
  skrivIntervall(gRoot, 5, 11);             //    en eller annen rekkefølge.

  cout << "\n\tNoder i intervallet -3 - 4: ";//  Skriver alle verdiene 1-4 i
  skrivIntervall(gRoot, -3, 4);             //    en eller annen rekkefølge.

  cout << "\n\tNoder i intervallet 15 - 23: ";//  Skriver alle verdiene 15-19 i
  skrivIntervall(gRoot, 15, 23);             //    en eller annen rekkefølge.

  cout << "\n\tNoder i intervallet 20 - 25: ";//  Skriver ingen verdier/IDer.
  skrivIntervall(gRoot, 20, 25);


  cout << "\n\nOppgave B -  Venstre BLADnoder i treet har ID'ene:\n";
  skrivVenstreBladnode(gRoot);           //  Skriver 8, 14 og 18
                                         //    i en eller annen rekkefølge.
  return 0;
}


/**
 *  Bygger et tre for å kunne teste de ulike funksjonene.
 */
void byggTre() {
    Node* p[19];
    for (int i = 0;  i < 19;  i++)  p[i] = new Node(i+1);
    gRoot = p[0];                              //  Bygger treet:          //
    p[0]->left   = p[1];  p[0]->right = p[2];  //           1             //
    p[1]->left   = p[3];  p[1]->right = p[4];  //       /       \         //
    p[2]->left   = p[5];  p[2]->right = p[6];  //      2         3        //
    p[3]->left   = p[7];  p[3]->right = p[8];  //    /   \     /   \      //
    p[4]->left   = p[9];                       //   4     5    6    7     //
    p[5]->right  = p[10];                      //  / \    /     \   / \   //
    p[6]->left   = p[11]; p[6]->right = p[12]; // 8   9  10     11 12 13  //
    p[9]->left   = p[13]; p[9]->right = p[14]; //       / \     /   \     //
    p[10]->left  = p[15];                      //      14 15   16   17    //
    p[11]->right = p[16];                      //         /     \         //
    p[14]->left  = p[17];                      //        18     19        //
    p[15]->right = p[18];
}
