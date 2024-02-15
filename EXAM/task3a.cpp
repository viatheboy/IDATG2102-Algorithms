/*
* Eksamensoppgave Høst 2023.
* Dette er oppgave 3a av til sammen 4 oppgaver, i en firetimers eksamen med medbrakte hjelpemidler tillatt.
* Merk at dette ikke er et fungerende program, men heller funksjoner som ble laget isolert i forbindelse med eksamen. 
*
* Oppgavetekst:
* Lag de torekursive funksjonene void speilvend(Node* n) og void settPosisjoner(Node* n, int p)
*
* Den første funksjonen skal speilvende noden n og alle dens subtrær/barn. Dvs. bytte om på sine venstre og høyre subtrær/barn, 
* og at dette skjer rekursivt videre nedover. Kalles fra  main  med:  speilvend(gRoot); 
* Når dette har skjedd vil ikke pos lengre være korrekt i nodene. 
* Den andre funksjonen skal derfor rekursivt gå gjennom noden med alle dets subtrær/barn,
* og sette rett verdi for pos i alle nodene igjen. Kalles fra main med:  settPosisjoner(gRoot, 1);
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
 * Rekursiv funksjon som speilvender en nodes barn
 * 
 * @param n - Noden som får sine barn speilvendt
 */
void speilvend(Node* n) {
    
    // Først sjekker vi om t i det hele tatt eksisterer
    if (n) {
        // Vi oppretter en node-peker for å lagre unna en node, så vi ikke sletter den ved et uhell
        Node* temp = nullptr;
        
        // Om noden har to barn må vi lagre den ene i temp,
        if (n->left && ->right) {
            temp = n->left; // Vi velger venstre
            
            // Vi setter så nodes høyrebarn inn til å være nodens venstre barn
            n->left = n->right;
            // Og setter noden vi lagret unna til å være nodens høyre barn
            n->right = temp;
        }
        
        // Om noden kun har et eller ingen barn trenger vi ikke bruke temp
        /* Om noden kun har ett barn må vi passe på at vi ikke setter
           det ene barnet lik nullptr før vi har fått flyttet det eksisterende over.
           Derfor trenger vi logikk som håndterer dette. */
       if (n->left && !n->right) {
           n->right = n->left;
           n->left = nullptr;   // Høyre var tomt så vi setter lik nullptr (kunne satt = n->right)
       } else if (n->right && !n->left) {
           n->left = n->right;
           n->right = nullptr;
       }
       /* Om ingen av if-betingelsene er oppfylt så er noden en bladnode, 
          og den trenger ikke å speilvende sine barn */
          
      // Vi sender funksjonen til nodens barn, om noden er en bladnode så sender if-
      // betingelsen i starten av funksjonen noden rett tilbake
      speilvend(n->left);
      speilvend(n->right);
    }
}

/**
 * Rekursiv funksjon som retter opp posisjon, den setter sin posisjon til  være med den 
 * medsendte posisjonen, og sender funksjonen videre til sine barn med rett posisjon
 * 
 * @param n - noden som får sin posisjon rettet
 * @param p - posisjonen som er riktig ut fra nodens posisjon i treet
 */
void settPosisjoner(Node* n, int p) {
    
    // Sjekker først om noden eksisterer
    if (n) {
        // Setter nodens posisjon til å være lik den posisjonen den har fått tilsendt
        n->pos = p;
        
        // Sender så funksjonen til sine barn
        // p*2 for venstrebarnet, (p*2)+1 for høyrebarnet
        settPosisjoner(n->left, (p*2));
        settPosisjoner(n->right, (p*2)+1);
    }
    
}