
#include "Header.h"
#include <map>

using namespace sf;
using namespace std;

int main()
{

    RenderWindow okno{ VideoMode{800,600},"Szachy" };
    okno.setFramerateLimit(60);
    grafika graf;
    plansza *plan=new plansza(graf);
    glowna *dane=new glowna();

    bool koniec = true;
    Event event;
    dane->czymozruch(*(dane->getlistafig()), *plan, bialy);



    while (koniec) {
        okno.clear(Color::White);
        okno.pollEvent(event);

        koniec = dane->eventy(event, &okno,*plan);
        if (koniec == false && event.type == Event::MouseButtonPressed) {
            delete(plan);
            plan = new plansza(graf);
            graf.setkordbia(540, 150);
            graf.setkordcz(540, 150);
            delete(dane);
            dane = new glowna();
            dane->czymozruch(*(dane->getlistafig()), *plan, bialy);
            koniec = true;
            
        }
        dane->wypisz(&okno, *plan,graf);
        okno.display();

    }
    delete(dane);
    delete(plan);
}
