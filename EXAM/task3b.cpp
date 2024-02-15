/*
* Eksamensoppgave Høst 2023.
* Dette er oppgave 3a av til sammen 4 oppgaver, i en firetimers eksamen med medbrakte hjelpemidler tillatt.
* Merk at dette ikke er et fungerende program, men heller funksjoner som ble laget isolert i forbindelse med eksamen. 
*
* Oppgavetekst:
* Lag den rekursive funksjonen void speilvend(Node* n, int p)
* Funksjonen skal alene utføre det samme som begge funksjonene ovenfor til sammen utfører. 
* Kalles fra main med: speilvend(gRoot, 1);
*/


struct Node  {
  char  ID;             //  Nodens ID/key/nøkkel/navn (ett tegn).
  int   pos;            //  Posisjon i treet.
  Node *left, *right;   //  Referanser til begge subtrærne, evt. nullptr/NULL
  Node (char id, int p)  //  Constructor:
            { ID = id;  pos = p;  left = right = nullptr; }
};

Node* gRoot = nullptr;     // Rot-peker  (har altså ikke at  head->right er rota).

/**
 * Rekursiv funksjon som setter sin posisjon lik den tilsendte posisjonen, deretter
 * speilvender den sine barn, og sender funksjonen videre til sine barn med deres nye
 * posisjon
 * 
 * @param n - noden som får sine barn speilet
 * @param p - den nye posisjonen til noden
 */
 void speilvend(Node *n, int p) {
     
     // Sjekker om noden eksisterer
     if (n) {
         // Setter sin posisjon til å være den medsendte posisjonen
         n->pos = p;
         
         // Sjekker så om den har to barn, da må den bruke en midlertidig Node variabel
         if (n->left && n->right) {
             // Vi lagrer unna den venstre noden, så bytter vi plass på nodene
             Node* temp = nullptr;
             temp = n->left;
             n->left = n->right;
             n->right = temp;
         }
         
         /* Vi må igjen håndtere situasjoner der noden kun har et barn,
            hvor vi passer på at vi ikke setter det eksisterende barnet lik
            nullptr før vi har fått flyttet det over*/
        if (n->left && !n->right) {
            n->right = n->left;
            n->left = nullptr;
        } else if (n->right && !n->left) {
            n->left = n->right;
            n->right = nullptr;
        }
        
        // Om ingen av if betingelsene oppfylles er noden en bladnode
        // Etter nodens barn er blitt speilet, sender vi funksjonen videre, med deres nye verdier
        speilvend(n->left, (p*2));
        speilvend(n->right, (p*2)+1);
     }
 }