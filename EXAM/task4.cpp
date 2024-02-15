/*
* Eksamensoppgave Høst 2023.
* Dette er oppgave 3a av til sammen 4 oppgaver, i en firetimers eksamen med medbrakte hjelpemidler tillatt.
* Merk at dette ikke er et fungerende program, men heller funksjoner som ble laget isolert i forbindelse med eksamen.
*
* Oppgavetekst:
* Tallet 2.6 ganget med 135 er 351.  Dvs. svaret er bare at det første sifferet er flyttet bakerst.
* Det samme gjelder for alle disse regnestykkene, om faktoren er 2.6 og tallet det ganges med er mindre eller lik 1 million:   2.6 * 270 = 702
* 
* 2.6 * 135135 = 351351
* 2.6 * 270270 = 702702
* 
* Skriv et fullverdig/komplett program som leser inn en faktor å gange med (f.eks. 2.6), og som for alle tall mindre eller lik 1 million, finner og skriver ut alle slike regnestykker som stemmer, ved at det første sifferet i tallet som faktoren ganges med flyttes bakerst, så får man svaret.
* Om ingen løsninger finnes, skal det komme en egen melding.
*/

#include <iostream>

int main() {
    // Variabel for å holde faktoren
    float faktor;
    // Variabler som holder tallene vi sammenligner
    int mod, dele;
    // Variabel som holder verdien vi moder og deler med
    int modOgDele = 10;
    // Variabel som holder midlertidig verdi når vi ganger med faktoren
    int temp;
    
    // Henter faktor fra brukeren
    std::cout << "Faktor: ";
    std::cin >> faktor;
    
    // En for loop som sjekker alle tall fra 10 til 1 000 000.
    // Vil ikke være mulig å flytte tall under 10
    for (int i = 10; i <= 1000000; i++) {
        
        // Når i har flere tall enn verdien vi moder og deler med, så må vi sette
        // denne verdien til 10x seg selv. Når i blir 100 så setter vi modOgDele fra 10 til 100
        if (i >= modOgDele * 10) {
            modOgDele * 10;
        }
        
        // Vi lagrer først unna verdien til i delt på modOgDele
        dele = i/modOgDele;
        // Deretter ganger vi i med faktoren og lagrer denne
        temp = i*faktor;
        // Så lagrer vi unna temp modet med modOgDele
        mod = temp % modOgDele;
        
        // Deretter sjekker vi om disse tallene er like. Om de er like vil tallet fremst
        // hos i ha blitt flyttet bakerst, og vi skriver ut verdien dette gjelder for.
        // Vi skriver ut både tallet før og etter det blir ganget
        if (dele == mod) {
            std::cout << i << " * " << faktor << " = " << temp << std::endl;
        }
    }
    
    return 0;
}