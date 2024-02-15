/*
* Eksamensoppgave Høst 2023.
* Dette er oppgave 3a av til sammen 4 oppgaver, i en firetimers eksamen med medbrakte hjelpemidler tillatt.
* Merk at dette ikke er et fungerende program, men heller funksjoner som ble laget isolert i forbindelse med eksamen. 
* 
* Oppgavetekst:
* Lag den ikke-rekursive funksjonen Node* finnNode(int p)
*
* Funksjonen starter å lete i rota. Den returnerer en peker til noden som har klassemedlemmet pos lik parameteren p. 
* Finner den ikke en slik node, returneres  nullptr/NULL.
* Forklar/redegjør klart for hvordan funksjonen din virker (dens tankegang/algoritme).
* 
* Hint:  Binærkoden for  p er vesentlig.
*/

struct Node  {
  char  ID;             //  Nodens ID/key/nøkkel/navn (ett tegn).
  int   pos;            //  Posisjon i treet.
  Node *left, *right;   //  Referanser til begge subtrærne, evt. nullptr/NULL
  Node (char id, int p)  //  Constructor:
            { ID = id;  pos = p;  left = right = nullptr; }
};

Node* gRoot = nullptr;     // Rot-peker  (har altså ikke at  head->right er rota).

Node* finnNode(int p) {
    // Vi oppretter en peker som representerer noden vi er på, vi begynner i root.
    Node* tempNode = gRoot;
    
    // Vi lager en intarray som representerer bitene i p
    int pBinary[] = {};
    // En variabel for å holde verdien til p som vi deler på 2
    int temp = p;
    // En i som vi teller opp
    int i = 0;
    
    /*
    Formålet med neste while loop er å gjøre om p til et binærtall. Vi satt først
    temp til å være lik p, som er tallet vi jobber med. Deretter tar vi temp % 2 og setter inn
    1 eller 0 i binary-arrayen. Binærtallet til p vil dermed settes inn i rekkefølge venstre
    mote høyre.
    Deretter deler vi temp på 2, og siden det er en int, så vil den bli til heltalls-
    versjonen av tallet. F.eks 12.5 blir til 12. Dermed kan vi dele temp helt til det blir 0, 
    hvor vi stopper loopen og vi skal da ha en int-array med binærtallet til p.
    */
    
    // En while loop som deler temp på 2 til den er 0 
    while(temp > 0) {
        pBinary[i++] = temp % 2;
        temp /= 2;
    }
    
    /* Vi må dermed finne dybden på treet, som vil avgjøre hvor mange av de bakerste bitene
       som er avgjørende når vi skal lete oss nedover treet. Vi kan finne dette ved å dele p på 2, dens forelder vil være int versjonen av p/2 også videre. 
       Vi gjorde dette i den forrige while loopen, så i vil faktisk holde denne verdien. Vi må dog trekke fra 1 fra i siden vi er på utkikk etter verdien fra 1 og nedover, mens i også delte 1 på 2 og telte opp.
       Derfor vil dybden til treet være i-1.
       */

    /* Vi oppretter en for loop som går i antall ganger, som vil være dybden på treet. 
       Vi sjekker så binary arrayen på plass array.size - i. Det er i antall bakerste bit som vil
       avgjøre hvor i treet vi beveger oss. Vi begynner på plass array.size - i og sjekker om denne
       er 0 eller 1, om den er 0 går vi til venstre, om den er 1 går vi til høyre. Vi teller opp
       hvor vi er i arrayen og leter videre. Finner vi verdien returnerer vi noden.
    */
    int indeks = pBinary.size() - i;
    for (int j = 0; j < i; j++) {
        if (pBinary[indeks] == 0) {
            tempNode = tempNode->left;
        } else if (pBinaryNode[indeks] == 1) {
            tempNode = tempNode->right;
        }
        
        // Teller opp indeks, turte ikke gjøre det inne i if statementene, 
        // i tilfelle jeg gjorde detto ganger
        indeks++;
        
        // Om vi har funnet noden vi er på utkikk etter, så returnerer vi noden
        if (tempNode->pos == p) {
            return tempNode;
        }
    }
    
    // Om vi ikke fant noden vi lette etter så returnerer vi nullptr
    return nullptr;
}