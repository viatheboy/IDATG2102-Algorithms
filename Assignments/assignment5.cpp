#include <iostream>
using namespace std;


struct Node {
    int ID;             // Nodens ID
    Node* etterfolger;  // Peker til etterfølger/nullptr
    Node(const int id) { ID = id; etterfolger = nullptr; }
};

const int N = 5;        // Antall noder
Node* gGraf[N+1];       // Global array med alle noder i grafen


bool erRotrettetTre();

int main() {

}

/*
    FORKLARING:
    Algoritmen går over alle nodene i den globale arrayen og teller opp hvor mange noder som ikke har en etterfølger. 
    Er det ikke nøyaktig en, så har vi ikke med en rot i et tre å gjøre og vi returnerer false.
    Har vi med nøyaktig en å gjøre, så vil vi gå over alle andre noder i arrayen og se om deres forfedre eventuelt fører til roten.
    Dette gjennomføres ved å benytte oss av en midlertidig Node-peker som vil sette seg til sin egen etterfølger så lenge den ikke er blitt til roten.
    Vi teller også opp en variabel for å sørge for at vi ikke havner i en evig løkke om det skulle være en sykel i treet. 
    Om en node ikke har forfedre som til slutt peker på roten returnerer vi false. 

    Om alle disse sjekkene utføres suksessfult returnerer vi til slutt true. 
*/

/**
 * Sjekker om grafen er et rotrettet tre eller ikke.
 * 
 * @return Om grafen er rotrettet eller ikke.
 */
bool erRotrettetTre() {
    int utenEtterfolger = 0, indeksRot, j;
    Node* rot, *sjekk;

    // Finner først hvilken node som er roten (den uten etterfølger)
    for (int i = 0; i <= N; i++) {
        if (!gGraf[i]->etterfolger) {
            indeksRot = i;
            rot = gGraf[i];
            utenEtterfolger++;
        }
    }

    // Sjekker om det kun er en rot
    if (utenEtterfolger != 1)
        return false;
    
    // Sjekker om alle grenene til slutt peker på roten
    for (int i = 0; i <= N; i++) {
        if (i == indeksRot)
            continue;       // Hopper over den vi vet er roten
                    
        j = 0;
        sjekk = gGraf[i];
        
        // Sjekker om alle nodene har foreldre som til slutt ender opp hos roten
        // Benytter en J for å bryte evig løkke om vi har en sykel i grafen
        while (sjekk != rot && j < N) {
            if (sjekk->etterfolger)
                sjekk = sjekk->etterfolger;
            j++;
        }
        if (sjekk != rot)
            return false;
    }

    // Alle sjekker lykkes og vi kan returnere true
    return true;
}