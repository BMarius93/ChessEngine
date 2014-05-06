#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

bool primaMutare = true;
class Board
{
public:
        /*  Am implementat tabla, folosind un vector de 120 de elemente, aceasta implementare
            ne ajuta sa ne dam seama daca o piesa va iesi din suprafata placii.
        */
    std::vector<piesa> *tabla;
    int pozitii[16];
    Board()
    {
        // Initializam pozitiile de pe tabla;
        tabla = new std::vector<piesa>(TABLE_SIZE);
        for(int i = 0; i < 16;i++){
            pozitii[i] = 60;
        }
        for(int i = 0; i < 21; i++)
        {
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }
        tabla->at(21) =  Rn;
        tabla->at(21).position = 21;
        tabla->at(22) =  Nn;
        tabla->at(22).position = 22;
        tabla->at(23) =  Bn;
        tabla->at(23).position = 23;
        tabla->at(24) =  Qn;
        tabla->at(24).position = 24;
        tabla->at(25) =  Kn;
        tabla->at(25).position = 25;
        tabla->at(26) =  Bn;
        tabla->at(26).position = 26;
        tabla->at(27) =  Nn;
        tabla->at(27).position = 27;
        tabla->at(28) =  Rn;
        tabla->at(28).position = 28;
        for(int i = 29; i < 31; i++)
        {
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }
        for(int i = 31; i < 39; i++)
        {
            tabla->at(i) = pn;
            tabla->at(i).position = i;
        }
        for(int i = 29; i < 31; i++)
        {
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }
        for(int i = 31; i < 39; i++)
        {
            tabla->at(i) = pn;
            tabla->at(i).position = i;
        }

        for(int i = 41; i < 79; i++)
        {
            tabla->at(i) = in;
            tabla->at(i).position = i;
        }
        for(int i = 40; i < 100; i+=10)
        {
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }
        for(int i = 39; i < 100; i+=10)
        {
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }
        for(int i = 81; i < 89; i++)
        {
            tabla->at(i) = pa;
            tabla->at(i).position = i;
        }
        tabla->at(91) =  Ra;
        tabla->at(91).position = 91;
        tabla->at(92) =  Na;
        tabla->at(92).position = 92;
        tabla->at(93) =  Ba;
        tabla->at(93).position = 93;
        tabla->at(94) =  Qa;
        tabla->at(94).position = 94;
        tabla->at(95) =  Ka;
        tabla->at(95).position = 95;
        tabla->at(96) =  Ba;
        tabla->at(96).position = 96;
        tabla->at(97) =  Na;
        tabla->at(97).position = 97;
        tabla->at(98) =  Ra;
        tabla->at(98).position = 98;
        for(int i = 100; i< 120; i++){
            tabla->at(i) = out;
            tabla->at(i).position = i;
        }

    }
    //Metoda care afiseaza tabla;
    void afisare()
    {
        for(int i = 0; i < TABLE_SIZE; i++)
        {
            if(i % 10 == 0)
            {
                std::cout<<std::endl;
            }
            std::cout<<tabla->at(i).tip<<tabla->at(i).culoare<<"  ";
        }
    }
    // Functie folosita pentru comenzile primite de la Winboard;
    void mutare(std::string mutare)
    {

        int posInit = pos(mutare.substr(0,2));
        int posFin = pos(mutare.substr(2,2));
        if(primaMutare)
        {
            if(posInit < 60)
            {
                for(int i = 0; i < 8; i++)
                    pozitii[i] = i + 81;
                pozitii[8] = 92;
                pozitii[9] = 97;
                pozitii[10] = 93;
                pozitii[11] = 96;
                pozitii[12] = 91;
                pozitii[13]= 98;
                pozitii[14] = 94;
                pozitii[15] = 95;
            }
            else
            {
                for(int i = 0; i < 8; i++)
                    pozitii[i] = i + 31;
                pozitii[8] = 22;
                pozitii[9] = 27;
                pozitii[10] = 23;
                pozitii[11] = 26;
                pozitii[12] = 21;
                pozitii[13] = 28;
                pozitii[14]= 24;
                pozitii[15] = 25;
            }
            if(pozitii[2] == 33)
                pozitii[2] = 43;
            else
                pozitii[5] = 76;
        }
        tabla->at(posFin) = tabla->at(posInit);
        tabla->at(posInit) = in;
        if(tabla->at(posFin).tip == 1)
        {
            if(posFin/10 == 9)
            {
                piesa p(5, "n");
                p.position = posFin;
                tabla->at(posFin) = p;
            }
            else if(posFin/10 == 2)
            {
                piesa p(5, "a");
                p.position = posFin;
                tabla->at(posFin) = p;
            }
        }
        primaMutare = false;
    }

    ~Board()
    {
        delete tabla;
    }
};
#endif // BOARD_H_INCLUDED
