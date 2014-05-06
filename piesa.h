#ifndef PIESA_H_INCLUDED
#define PIESA_H_INCLUDED

//Functie de conversie din pozitia din coordanetele trimis de WinBoard, in pozitia din vectorul nostru;
int pos(std::string position)
{
    int pos;
    switch(position[0])
    {
        case 'a': pos = 1; break;
        case 'b': pos = 2; break;
        case 'c': pos = 3; break;
        case 'd': pos = 4; break;
        case 'e': pos = 5; break;
        case 'f': pos = 6; break;
        case 'g': pos = 7; break;
        case 'h': pos = 8; break;
    }

    switch(position[1])
    {
        case '1': pos = 90 + pos; break;
        case '2': pos = 80 + pos; break;
        case '3': pos = 70 + pos; break;
        case '4': pos = 60 + pos; break;
        case '5': pos = 50 + pos; break;
        case '6': pos = 40 + pos; break;
        case '7': pos = 30 + pos; break;
        case '8': pos = 20 + pos; break;
    }
    return pos;
}


class piesa
{
public:
    int tip;
    std::string culoare;
    int position;
    piesa()
    {}
    piesa(int tip, std::string culoare)
    {
        this->tip = tip;
        this->culoare = culoare;

    }
};

//Tipurile de piese;
    piesa pa(1, "a");
    piesa Na(2, "a");
    piesa Ba(3, "a");
    piesa Ra(4, "a");
    piesa Qa(5, "a");
    piesa Ka(6, "a");
    piesa pn(1, "n");
    piesa Nn(2, "n");
    piesa Bn(3, "n");
    piesa Rn(4, "n");
    piesa Qn(5, "n");
    piesa Kn(6, "n");
    piesa in(0, "i"); // piesa de interior;
    piesa out(7, "o"); // piesa de exterior;
#endif // PIESA_H_INCLUDED
