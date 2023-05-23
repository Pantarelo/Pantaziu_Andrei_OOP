#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact
{
    public:
        string nume;
};

class Prieten : public Contact
{
    public:
        string type = "Prieten";
        string date_de_nastere;
        string numar_telefon;
        string adresa;
};

class Cunoscut : public Contact
{
    public:
        string type = "Cunoscut";
        string numar_de_telefon;
};

class Coleg : public Contact 
{
    public:
        string type = "Coleg";
        string numar_de_telefon;
        string firma;
        string adresa;
};

class Agenda
{
    private:
        vector<Contact*> contacte;
    public:
        Contact* cautaContact(string nume) {
            for (auto contact : contacte)
                if (contact -> nume == nume)
                    return contact;
            return NULL;
        }

        void stergeContact(string nume) {
            for (auto i = contacte.begin(); i != contacte.end(); i++)
                if ((*i) -> nume == nume) {
                    contacte.erase(i);
                    break;
                }
        }

        void adaugareContacte(Contact* contact) {
            contacte.push_back(contact);
        }

        vector<Prieten*> getPrieten() {
            vector<Prieten*> prieteni;
            for (auto contact : contacte) {
                Prieten prieten;
                if (prieten.type == "Prieten")
                    prieteni.push_back(contact);
            }
            return prieteni;
        }
};

int main()
{
    Agenda agenda;

    Prieten prieten1;
    prieten1.nume = "Nicu";
    prieten1.date_de_nastere = "10.02.1990";
    prieten1.numar_telefon = "0712345689";
    prieten1.adresa = "la marginea pamantului";
    agenda.adaugareContacte(&prieten1);

    Cunoscut cunoscut1;
    cunoscut1.nume = "Ana";
    cunoscut1.numar_de_telefon = "0752967295";
    agenda.adaugareContacte(&cunoscut1);

    Coleg coleg1;
    coleg1.nume = "Mihai";
    coleg1.numar_de_telefon = "0793205843";
    coleg1.firma = "Somer";
    agenda.adaugareContacte(&coleg1);

     // Cautare contact
    string nume_cautat = "Nicu";
    Contact* contact_gasit = agenda.cautaContact(nume_cautat);
    if (contact_gasit)
        cout << nume_cautat << " a fost gasit" << '\n';
    else
        cout << nume_cautat << " nu a fost gasit";

    // Sterge contact
    nume_cautat = "Ana";
    agenda.stergeContact(nume_cautat);
     
    // Obtine Prieteni
    vector<Prieten*> prieteni = agenda.getPrieten();
    cout << "Lista prietenilor:" << '\n';
    for (auto& prieten : prieteni) 
        cout << "Nume: " << prieten -> nume << ", Data nastere: " << prieten -> date_de_nastere
                  << ", Numar telefon: " << prieten -> numar_telefon << ", Adress: " << prieten -> adresa << "\n";

    return 0;
}
