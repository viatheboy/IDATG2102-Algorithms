#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Map {

    private:
        T1* key;
        T2* value;
        int kapasitet, antall;
    
    public:
        Map(const int Lengde = 200) {
            key = new T1[Lengde];
            value = new T2[Lengde];
            kapasitet = Lengde;
            antall = 0;
        }

        int size() const {
            return antall;
        }

        void display() const {
            for (int i = 0; i < antall; i++) {
                cout << key[i] << ": " << value[i] << endl;
            }
            cout << "Antall: " << antall << endl;
        }

        void insert(const T1 k, const T2 v) {
            int i = 0;
            // Sjekker om det er plass
            if (antall < kapasitet) {
                if (!find(k)) {
                    // Så lenge i er mindre enn antall og 
                    // nåværende nøkkel er mindre enn ny nøkkel teller vi opp i
                    while (i < antall && key[i] < k) {
                        i++;
                    }
                    // Begynner bakerst og flytter alle frem en plass til vi kommer til der ny key skal inn
                    for (int j = antall; j >= i; j--) {
                        key[j+1] = key[j];
                        value[j+1] = value[j];
                    }
                    // Deretter setter vi inn nøkkelen og verdien
                    key[i] = k;
                    value[i] = v;
                    antall++;
                } else {
                    cout << "Key already exists\n";
                }
            } else {
                cout << "Capasity breached.\n";
            }
        }

        bool find(const T1 k) { 
            for (int i = 0; i < antall; i++) {
                if (key[i] == k) {
                    return true;
                }
            }
            return false;
        }

        T2 findValue(const T1 k) {
            if (find(k)) {
                for (int i = 0; i < antall; i++) {
                    if (key[i] == k) {
                        cout << "Funnet: " << value[i] << endl; // Debugging
                        return value[i];
                    }
                }
            } else {
                cout << "Key not found.\n";
            }
            return T2();    // Ingen som har sagt at dette går
        }

        void changeValue(const T1 k, const T2 newValue) {
            if (find(k)) {
                for (int i = 0; i < antall; i++) {
                    if (key[i] == k) {
                        value[i] = newValue;
                        break;
                    }
                }
            } else {
                cout << "Key not found.\n";
            }
        }

        void deletePair(const T1 k) {
            int plass;

            if (find(k)) {
                // Finner matchende nøkkel, lagrer denne plassen
                for (int i = 0; i < antall; i++) {
                    if (key[i] == k) {
                        plass = i;
                        antall--;   // Reduserer antall med 1.
                        break;
                    }
                }
                // Overskriver nøkkelen og flytter alle ned en plass. 
                for (int i = plass; i < antall; i++) {
                    key[i] = key[i+1];
                    value[i] = value[i+1];
                }
            } else {
                cout << "Key not found.\n";
            }
        }
};

int main(void) {

    Map <char, int> nyMap;

    nyMap.insert('K', 12);
    nyMap.insert('B', 1109);
    nyMap.insert('H', 1);
    nyMap.insert('R', 1230);
    nyMap.insert('F', 880);
    nyMap.insert('G', 190);
    nyMap.insert('A', 10);
    nyMap.insert('Z', 2030);
    
    cout << nyMap.find('K') << endl;
    nyMap.display();
    cout << endl << endl;

    nyMap.changeValue('B', 209);
    nyMap.deletePair('G');

    nyMap.display();

    return 0;
}