#define TABLE_SIZE 120
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
#include "piesa.h"
#include "Board.h"

using namespace std;
int posFinal;
bool turn;

// functia de generare a nr random funciton;
int randomPos(int maxPos) {
	return rand()%maxPos;
}

//Functie de conversie din pozitia din vectorul tabla, in coordonatele acceptate de WinBoard(ex: a1);
std::string posString(int move)
{
    std::string moveString;
    switch(move%10)
    {
        case 1: moveString = "a"; break;
        case 2: moveString = "b"; break;
        case 3: moveString = "c"; break;
        case 4: moveString = "d"; break;
        case 5: moveString = "e"; break;
        case 6: moveString = "f"; break;
        case 7: moveString = "g"; break;
        case 8: moveString = "h"; break;
    }

    switch(move/10)
    {
        case 2: moveString.append("8"); break;
        case 3: moveString.append("7"); break;
        case 4: moveString.append("6"); break;
        case 5: moveString.append("5"); break;
        case 6: moveString.append("4"); break;
        case 7: moveString.append("3"); break;
        case 8: moveString.append("2"); break;
        case 9: moveString.append("1"); break;
    }
    return moveString;
}

//Functie care verifica daca formatul stringului a este de tipul(ex: a2a3), ce reprezinta o mutare;
bool format(std::string a)
{
    char t[1024];
    strcpy(t, a.c_str());
    if(((isdigit(t[0]) == 0)) &&
       ((isdigit(t[1]) == 1)) &&
       ((isdigit(t[2]) == 0)) &&
       ((isdigit(t[3]) == 1)))
        return true;
    else
        return false;
}

bool sah(Board &b){
    int rege = b.pozitii[15];
    if(!turn){
        if(((b.tabla->at(rege - 21).tip == 2) && ((b.tabla->at(rege - 21).culoare) == "n")) ||
           ((b.tabla->at(rege- 19).tip == 2) && ((b.tabla->at(rege - 19).culoare) == "n")) ||
           ((b.tabla->at(rege - 8).tip == 2) && ((b.tabla->at(rege - 8).culoare) == "n")) ||
           ((b.tabla->at(rege - 12).tip == 2) && ((b.tabla->at(rege - 12).culoare) == "n")) ||
           ((b.tabla->at(rege + 21).tip == 2) && ((b.tabla->at(rege + 21).culoare) == "n")) ||
           ((b.tabla->at(rege + 19).tip == 2) && ((b.tabla->at(rege + 19).culoare) == "n")) ||
           ((b.tabla->at(rege + 8).tip == 2) && ((b.tabla->at(rege + 8).culoare) == "n")) ||
           ((b.tabla->at(rege + 12).tip == 2) && ((b.tabla->at(rege + 12).culoare) == "n"))){
                return true;
           }


            int i = 1;
            while(b.tabla->at(rege + i*10).culoare == "i" || b.tabla->at(rege + i*10).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*10).culoare == "n"){
                if((b.tabla->at(rege + i*10).tip == 4) ||
                   (b.tabla->at(rege + i*10).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege - i*10).culoare == "i" || b.tabla->at(rege - i*10).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*10).culoare == "n"){
                if((b.tabla->at(rege - i*10).tip == 4) ||
                   (b.tabla->at(rege - i*10).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege + i).culoare == "i" || b.tabla->at(rege + i).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i).culoare == "n"){
                if((b.tabla->at(rege + i).tip == 4) ||
                   (b.tabla->at(rege + i).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege - i).culoare == "i" || b.tabla->at(rege - i).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i).culoare == "n"){
                if((b.tabla->at(rege - i).tip == 4) ||
                   (b.tabla->at(rege - i).tip == 5)){
                       return true;
                   }
            }

            i = 1;
            while(b.tabla->at(rege + i*11).culoare == "i" || b.tabla->at(rege + i*11).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*11).culoare == "n"){
                if((b.tabla->at(rege + i*11).tip == 3) ||
                   (b.tabla->at(rege + i*11).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege + i*9).culoare == "i" || b.tabla->at(rege + i*9).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*9).culoare == "n"){
                if((b.tabla->at(rege + i*9).tip == 3) ||
                   (b.tabla->at(rege + i*9).tip == 5)){
                       return true;
                   }
            }

             i = 1;
            while(b.tabla->at(rege - i*9).culoare == "i" || b.tabla->at(rege - i*9).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*9).culoare == "n"){
                if((b.tabla->at(rege - i*9).tip == 3) ||
                   (b.tabla->at(rege - i*9).tip == 5)){
                       return true;
                   }
            }

            i = 1;
            while(b.tabla->at(rege - i*11).culoare == "i" || b.tabla->at(rege - i*11).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*11).culoare == "n"){
                if((b.tabla->at(rege - i*11).tip == 3) ||
                   (b.tabla->at(rege - i*11).tip == 5)){
                       return true;
                   }
            }

            if((b.tabla->at(rege - 9).culoare == "n") &&  (b.tabla->at(rege - 9).tip == 1)){
                return true;
            }
            if((b.tabla->at(rege - 11).culoare == "n") &&  (b.tabla->at(rege - 11).tip == 1)){
                return true;
            }

            return false;
        //PENTRU CULOARE NEGRU:
    }else{
        if(((b.tabla->at(rege - 21).tip == 2) && ((b.tabla->at(rege - 21).culoare) == "a")) ||
           ((b.tabla->at(rege- 19).tip == 2) && ((b.tabla->at(rege - 19).culoare) == "a")) ||
           ((b.tabla->at(rege - 8).tip == 2) && ((b.tabla->at(rege - 8).culoare) == "a")) ||
           ((b.tabla->at(rege - 12).tip == 2) && ((b.tabla->at(rege - 12).culoare) == "a")) ||
           ((b.tabla->at(rege + 21).tip == 2) && ((b.tabla->at(rege + 21).culoare) == "a")) ||
           ((b.tabla->at(rege + 19).tip == 2) && ((b.tabla->at(rege + 19).culoare) == "a")) ||
           ((b.tabla->at(rege + 8).tip == 2) && ((b.tabla->at(rege + 8).culoare) == "a")) ||
           ((b.tabla->at(rege + 12).tip == 2) && ((b.tabla->at(rege + 12).culoare) == "a"))){
                return true;
           }


            int i = 1;
            while(b.tabla->at(rege + i*10).culoare == "i" || b.tabla->at(rege + i*10).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*10).culoare == "a"){
                if((b.tabla->at(rege + i*10).tip == 4) ||
                   (b.tabla->at(rege + i*10).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege - i*10).culoare == "i" || b.tabla->at(rege - i*10).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*10).culoare == "a"){
                if((b.tabla->at(rege - i*10).tip == 4) ||
                   (b.tabla->at(rege - i*10).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege + i).culoare == "i" || b.tabla->at(rege + i).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i).culoare == "a"){
                if((b.tabla->at(rege + i).tip == 4) ||
                   (b.tabla->at(rege + i).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege - i).culoare == "i" || b.tabla->at(rege - i).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i).culoare == "a"){
                if((b.tabla->at(rege - i).tip == 4) ||
                   (b.tabla->at(rege - i).tip == 5)){
                       return true;
                   }
            }

            i = 1;
            while(b.tabla->at(rege + i*11).culoare == "i" || b.tabla->at(rege + i*11).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*11).culoare == "a"){
                if((b.tabla->at(rege + i*11).tip == 3) ||
                   (b.tabla->at(rege + i*11).tip == 5)){
                       return true;
                   }
            }


            i = 1;
            while(b.tabla->at(rege + i*9).culoare == "i" || b.tabla->at(rege + i*9).tip == 6){
                i++;
            }
            if(b.tabla->at(rege + i*9).culoare == "a"){
                if((b.tabla->at(rege + i*9).tip == 3) ||
                   (b.tabla->at(rege + i*9).tip == 5)){
                       return true;
                   }
            }

             i = 1;
            while(b.tabla->at(rege - i*9).culoare == "i" || b.tabla->at(rege - i*9).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*9).culoare == "a"){
                if((b.tabla->at(rege - i*9).tip == 3) ||
                   (b.tabla->at(rege - i*9).tip == 5)){
                       return true;
                   }
            }

            i = 1;
            while(b.tabla->at(rege - i*11).culoare == "i" || b.tabla->at(rege - i*11).tip == 6){
                i++;
            }
            if(b.tabla->at(rege - i*11).culoare == "a"){
                if((b.tabla->at(rege - i*11).tip == 3) ||
                   (b.tabla->at(rege - i*11).tip == 5)){
                       return true;
                   }
            }

            if((b.tabla->at(rege + 9).culoare == "a") &&  (b.tabla->at(rege + 9).tip == 1)){
                return true;
            }
            if((b.tabla->at(rege + 11).culoare == "a") &&  (b.tabla->at(rege + 11).tip == 1)){
                return true;
            }

            return false;
    }
}
//Functie care face mutarea pe tabla noastra, primeste ca
//parametrii piesa ce urmeaza a fi mutata si tabla, si
//si returneaza piesa cu pozitia pe tabla updatata.
piesa move(piesa p, Board &b)
{
    std::string mut;

    // Cazul in care piesa este de tip pion
    if(p.tip == 1){

        // Cand pionul este alb
        if(p.culoare == "a")
        {

            // Verifica daca poate sa mute inainte
            if(b.tabla->at(p.position - 10).culoare == "i")
            {
                b.tabla->at(p.position - 10) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 10;
                    }

                    mut = posString(p.position).append(posString(p.position-10));
                    p.position-=10;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 2)
                    {
                        int poz = p.position;
                        p = Qa;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position - 10) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //Daca in stanga lui se afla o piesa neagra, acesta o mananca;
            else if(b.tabla->at(p.position - 9).culoare == "n")
            {
                b.tabla->at(p.position - 9) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 9;
                    }
                    mut = posString(p.position).append(posString(p.position-9));
                    p.position -= 9;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 2)
                    {
                        int poz = p.position;
                        p = Qa;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position - 9) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //Daca in dreapta lui se afla o piesa neagra, acesta o mananca;
            else if(b.tabla->at(p.position - 11).culoare == "n")
            {
                b.tabla->at(p.position - 11) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 11;
                    }
                    mut = posString(p.position).append(posString(p.position-11));
                    p.position -= 11;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 2)
                    {
                        int poz = p.position;
                        p = Qa;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position - 11) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            else
            {
                return in;
            }
        }
        //Cand pionul este negru;
        else if(p.culoare == "n")
        {
        //Verifica daca poate sa mute inainte
            if(b.tabla->at(p.position + 10).culoare == "i")
            {
                b.tabla->at(p.position + 10) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 10;
                    }
                    mut = posString(p.position).append(posString(p.position+10));
                    p.position+=10;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 9)
                    {
                        int poz = p.position;
                        p = Qn;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position + 10) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //Daca in stanga lui se afla o piesa alba, acesta o mananca;
            else if(b.tabla->at(p.position + 9).culoare == "a")
            {
                if(!sah(b)){
                    b.tabla->at(p.position + 9) = p;
                    b.tabla->at(p.position) = in;
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 9;
                    }
                    mut = posString(p.position).append(posString(p.position+9));
                    p.position += 9;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 9)
                    {
                        int poz = p.position;
                        p = Qn;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position + 9) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //Daca in dreapta lui se afla o piesa alba, acesta o mananca;
            else if(b.tabla->at(p.position + 11).culoare == "a")
            {
                b.tabla->at(p.position + 11) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 11;
                    }
                    mut = posString(p.position).append(posString(p.position+11));
                    p.position += 11;
                    std::cout<<"move "<<mut<<"\n";
                    if((p.position / 10) == 9)
                    {
                        int poz = p.position;
                        p = Qn;
                        p.position = poz;
                    }
                    return p;
                }else{
                    b.tabla->at(p.position + 11) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            else
            {
                return in;
            }
        }
    }
    // Cazul in care piesa este de tip cal
    else if(p.tip == 2){

        //Cazul in care calul este alb
        if(p.culoare == "a"){
            //pozitia 1
            if((b.tabla->at(p.position - 21).culoare == "i")||(b.tabla->at(p.position - 21).culoare == "n"))
            {
                b.tabla->at(p.position - 21) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 21;
                    }

                    mut = posString(p.position).append(posString(p.position-21));
                    p.position-=21;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 21) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 2
            else if((b.tabla->at(p.position - 19).culoare == "n")||(b.tabla->at(p.position - 19).culoare == "i"))
            {
                b.tabla->at(p.position - 19) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 19;
                    }
                    mut = posString(p.position).append(posString(p.position-19));
                    p.position -= 19;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 19) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 3
            else if((b.tabla->at(p.position - 8).culoare == "n")||(b.tabla->at(p.position - 8).culoare == "i"))
            {
                b.tabla->at(p.position - 8) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 8;
                    }
                    mut = posString(p.position).append(posString(p.position-8));
                    p.position -= 8;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 8) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 4
            else if((b.tabla->at(p.position +12).culoare == "n")||(b.tabla->at(p.position +12).culoare == "i"))
            {
                b.tabla->at(p.position + 12) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 12;
                    }
                    mut = posString(p.position).append(posString(p.position+12));
                    p.position += 12;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                     b.tabla->at(p.position + 12) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 5
            else if((b.tabla->at(p.position +21).culoare == "n")||(b.tabla->at(p.position +21).culoare == "i"))
            {
                b.tabla->at(p.position +21) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position +21;
                    }
                    mut = posString(p.position).append(posString(p.position+21));
                    p.position += 21;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position +21) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 6
            else if((b.tabla->at(p.position +19 ).culoare == "n")||(b.tabla->at(p.position +19 ).culoare == "i"))
            {
                b.tabla->at(p.position +19 ) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position +19;
                    }
                    mut = posString(p.position).append(posString(p.position+19));
                    p.position += 19;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position +19 ) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 7
            else if((b.tabla->at(p.position + 8).culoare == "n")||(b.tabla->at(p.position + 8).culoare == "i"))
            {
                b.tabla->at(p.position + 8) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 8;
                    }
                    mut = posString(p.position).append(posString(p.position+8));
                    p.position += 8;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position + 8) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 8
            else if((b.tabla->at(p.position - 12).culoare == "n")||(b.tabla->at(p.position - 12).culoare == "i"))
            {
                b.tabla->at(p.position - 12) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 12;
                    }
                    mut = posString(p.position).append(posString(p.position-12));
                    p.position -= 12;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                     b.tabla->at(p.position - 12) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            else
            {
                return in;
            }


        }
        // Cazul in care calul este negru
        else if(p.culoare == "n"){
            //pozitia 1
            if((b.tabla->at(p.position - 21).culoare == "i")||(b.tabla->at(p.position - 21).culoare == "a"))
            {
                b.tabla->at(p.position - 21) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 21;
                    }

                    mut = posString(p.position).append(posString(p.position-21));
                    p.position-=21;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 21) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 2
            else if((b.tabla->at(p.position - 19).culoare == "i")||(b.tabla->at(p.position - 19).culoare == "a"))
            {
                b.tabla->at(p.position - 19) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 19;
                    }
                    mut = posString(p.position).append(posString(p.position-19));
                    p.position -= 19;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 19) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 3
            else if((b.tabla->at(p.position - 8).culoare == "a")||(b.tabla->at(p.position - 8).culoare == "i"))
            {
                b.tabla->at(p.position - 8) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 8;
                    }
                    mut = posString(p.position).append(posString(p.position-8));
                    p.position -= 8;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                     b.tabla->at(p.position - 8) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 4
            else if((b.tabla->at(p.position +12).culoare == "a")||(b.tabla->at(p.position +12).culoare == "i"))
            {
                b.tabla->at(p.position + 12) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 12;
                    }
                    mut = posString(p.position).append(posString(p.position+12));
                    p.position += 12;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                     b.tabla->at(p.position + 12) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 5
            else if((b.tabla->at(p.position +21).culoare == "a")||(b.tabla->at(p.position +21).culoare == "i"))
            {
                b.tabla->at(p.position +21) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position +21;
                    }
                    mut = posString(p.position).append(posString(p.position+21));
                    p.position += 21;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position +21) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 6
            else if((b.tabla->at(p.position +19 ).culoare == "i")||(b.tabla->at(p.position +19 ).culoare == "a"))
            {
                b.tabla->at(p.position +19 ) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position +19;
                    }
                    mut = posString(p.position).append(posString(p.position+19));
                    p.position += 19;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position +19 ) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 7
            else if((b.tabla->at(p.position + 8).culoare == "a")||(b.tabla->at(p.position + 8).culoare == "i"))
            {
                b.tabla->at(p.position + 8) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position + 8;
                    }
                    mut = posString(p.position).append(posString(p.position+8));
                    p.position += 8;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position + 8) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            //pozitia 8
            else if((b.tabla->at(p.position - 12).culoare == "i")||(b.tabla->at(p.position - 12).culoare == "a"))
            {
                b.tabla->at(p.position - 12) = p;
                b.tabla->at(p.position) = in;
                if(!sah(b)){
                    for(int i = 0; i < 16; i++)
                    {
                        if(b.pozitii[i] == p.position)
                            b.pozitii[i] = p.position - 12;
                    }
                    mut = posString(p.position).append(posString(p.position-12));
                    p.position -= 12;
                    std::cout<<"move "<<mut<<"\n";
                    return p;
                }else{
                    b.tabla->at(p.position - 12) = in;
                    b.tabla->at(p.position) = p;
                    return in;
                }
            }
            else
            {
                return in;
            }
        }
    }

    //cazul in care piesa este de tip nebun
    else if(p.tip == 3){

        //Cazul in care piesa este alba
        if(p.culoare == "a") {
            // directia 1
            if((b.tabla->at(p.position - 9).culoare == "i") || (b.tabla->at(p.position - 9).culoare == "n")) {
                        b.tabla->at(p.position - 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                        for(int i = 0; i < 16; i++)
                        {
                            if(b.pozitii[i] == p.position)
                                b.pozitii[i] = p.position - 9;
                        }

                        mut = posString(p.position).append(posString(p.position - 9));
                        p.position -= 9;
                        std::cout<<"move "<<mut<<"\n";
                        return p;
                        }else{
                             b.tabla->at(p.position - 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }

            }

            //directia 2
            else if((b.tabla->at(p.position - 11).culoare == "i") || (b.tabla->at(p.position - 11).culoare == "n")) {
                        b.tabla->at(p.position - 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 11;
                            }

                            mut = posString(p.position).append(posString(p.position - 11));
                            p.position -= 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position - 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 3
            else if((b.tabla->at(p.position + 9).culoare == "i") || (b.tabla->at(p.position + 9).culoare == "n")) {
                        b.tabla->at(p.position + 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 9;
                            }

                            mut = posString(p.position).append(posString(p.position + 9));
                            p.position += 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position + 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 4
            else if((b.tabla->at(p.position + 11).culoare == "i") || (b.tabla->at(p.position + 11).culoare == "n")) {
                        b.tabla->at(p.position + 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 11;
                            }

                            mut = posString(p.position).append(posString(p.position + 11));
                            p.position += 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position + 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
        }

        //Cazul in care pesa este neagra
        else if(p.culoare == "n"){

                    //directia 1
                    if((b.tabla->at(p.position + 9).culoare == "i") || (b.tabla->at(p.position + 9).culoare == "a")) {
                        b.tabla->at(p.position + 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 9;
                            }

                        mut = posString(p.position).append(posString(p.position + 9));
                        p.position += 9;
                        std::cout<<"move "<<mut<<"\n";
                        return p;
                        }else{
                            b.tabla->at(p.position + 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
                    }

            //directia 2
            else if((b.tabla->at(p.position + 11).culoare == "i") || (b.tabla->at(p.position + 11).culoare == "a")) {
                        b.tabla->at(p.position + 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 11;
                            }

                            mut = posString(p.position).append(posString(p.position + 11));
                            p.position += 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 3
            else if((b.tabla->at(p.position - 9).culoare == "i") || (b.tabla->at(p.position - 9).culoare == "a")) {
                        b.tabla->at(p.position - 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){


                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 9;
                            }

                            mut = posString(p.position).append(posString(p.position - 9));
                            p.position -= 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position - 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 4
            else if((b.tabla->at(p.position - 11).culoare == "i") || (b.tabla->at(p.position - 11).culoare == "a")) {
                        b.tabla->at(p.position - 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 11;
                            }

                            mut = posString(p.position).append(posString(p.position - 11));
                            p.position -= 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position - 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
			else
            {
                return in;
            }
        }
    }

    //Cazul in care piesa este de tip tura
    else if(p.tip == 4){

        //Cazul in care piesa este alba
        if(p.culoare == "a"){
            //directia 1
            if((b.tabla->at(p.position - 10).culoare == "i") || (b.tabla->at(p.position - 10).culoare == "n")) {
                        b.tabla->at(p.position - 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 10;
                            }

                            mut = posString(p.position).append(posString(p.position - 10));
                            p.position -= 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position - 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 2
            else if((b.tabla->at(p.position + 1).culoare == "i") || (b.tabla->at(p.position + 1).culoare == "n")) {
                        b.tabla->at(p.position + 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 1;
                            }

                            mut = posString(p.position).append(posString(p.position + 1));
                            p.position += 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 3
            else if((b.tabla->at(p.position - 1).culoare == "i") || (b.tabla->at(p.position - 1).culoare == "n")) {
                        b.tabla->at(p.position - 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 1;
                            }

                            mut = posString(p.position).append(posString(p.position - 1));
                            p.position -= 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }

            //directia 4
            else if((b.tabla->at(p.position + 10).culoare == "i") || (b.tabla->at(p.position + 10).culoare == "n")) {
                        b.tabla->at(p.position + 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 10;
                            }

                            mut = posString(p.position).append(posString(p.position + 10));
                            p.position += 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
        }

        //Cazul in care piesa este neagra
        else if(p.culoare == "n"){
            //directia 1
            if((b.tabla->at(p.position + 10).culoare == "i") || (b.tabla->at(p.position + 10).culoare == "a")) {
                        b.tabla->at(p.position + 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 10;
                            }

                            mut = posString(p.position).append(posString(p.position + 10));
                            p.position += 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //directia 2
            else if((b.tabla->at(p.position + 1).culoare == "i") || (b.tabla->at(p.position + 1).culoare == "a")) {
                        b.tabla->at(p.position + 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 1;
                            }

                            mut = posString(p.position).append(posString(p.position + 1));
                            p.position += 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //directia 3
            else if((b.tabla->at(p.position - 1).culoare == "i") || (b.tabla->at(p.position - 1).culoare == "a")) {
                        b.tabla->at(p.position - 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 1;
                            }

                            mut = posString(p.position).append(posString(p.position - 1));
                            p.position -= 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                             b.tabla->at(p.position - 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //directia 4
            else if((b.tabla->at(p.position - 10).culoare == "i") || (b.tabla->at(p.position - 10).culoare == "a")) {
                        b.tabla->at(p.position - 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 10;
                            }

                            mut = posString(p.position).append(posString(p.position - 10));
                            p.position -= 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
			else
            {
                return in;
            }
        }
    }

    //Cazul in care piesa este de tip REGINA REGINELOR:
    else if(p.tip == 5){

        //Cazul in care piesa este alba
        if(p.culoare == "a"){
            //Verifica daca poate muta inainte
            if((b.tabla->at(p.position - 10).culoare == "i") || (b.tabla->at(p.position - 10).culoare == "n")) {
                        b.tabla->at(p.position - 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 10;
                            }

                            mut = posString(p.position).append(posString(p.position - 10));
                            p.position -= 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifaca daca poate muta pe diaganala in dreaptainainte
            else if((b.tabla->at(p.position - 9).culoare == "i") || (b.tabla->at(p.position - 9).culoare == "n")) {
                        b.tabla->at(p.position - 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 9;
                            }

                            mut = posString(p.position).append(posString(p.position - 9));
                            p.position -= 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta pe diagonala in stanga inainte
            else if((b.tabla->at(p.position - 11).culoare == "i") || (b.tabla->at(p.position - 11).culoare == "n")) {
                        b.tabla->at(p.position - 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 11;
                            }

                            mut = posString(p.position).append(posString(p.position - 11));
                            p.position -= 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta in dreapta
            else if((b.tabla->at(p.position + 1).culoare == "i") || (b.tabla->at(p.position + 1).culoare == "n")) {
                        b.tabla->at(p.position + 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 1;
                            }

                            mut = posString(p.position).append(posString(p.position + 1));
                            p.position += 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta in stanga
             else if((b.tabla->at(p.position - 1).culoare == "i") || (b.tabla->at(p.position - 1).culoare == "n")) {
                        b.tabla->at(p.position - 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 1;
                            }

                            mut = posString(p.position).append(posString(p.position - 1));
                            p.position -= 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta pe diagonala drapta inapoi
            else if((b.tabla->at(p.position + 11).culoare == "i") || (b.tabla->at(p.position + 11).culoare == "n")) {
                        b.tabla->at(p.position + 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 11;
                            }

                            mut = posString(p.position).append(posString(p.position + 11));
                            p.position += 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifica daca poate muta in diagonala stanga inapoi
            else if((b.tabla->at(p.position + 9).culoare == "i") || (b.tabla->at(p.position + 9).culoare == "n")) {
                        b.tabla->at(p.position + 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 9;
                            }

                            mut = posString(p.position).append(posString(p.position + 9));
                            p.position += 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta inapoi
            else if((b.tabla->at(p.position + 10).culoare == "i") || (b.tabla->at(p.position + 10).culoare == "n")) {
                        b.tabla->at(p.position + 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 10;
                            }

                            mut = posString(p.position).append(posString(p.position + 10));
                            p.position += 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
        }
        //Cazul in care piesa este neagra
        else if(p.culoare == "n"){
            //Verifica daca poate muta inainte
            if((b.tabla->at(p.position + 10).culoare == "i") || (b.tabla->at(p.position + 10).culoare == "a")) {
                        b.tabla->at(p.position + 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 10;
                            }

                            mut = posString(p.position).append(posString(p.position + 10));
                            p.position += 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 10) = in;
                            b.tabla->at(p.position) = p;

                            return in;

                        }
            }
            //Verifica daca poate muta pe diagonala stanga inainte
            else if((b.tabla->at(p.position + 9).culoare == "i") || (b.tabla->at(p.position + 9).culoare == "a")) {
                        b.tabla->at(p.position + 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 9;
                            }

                            mut = posString(p.position).append(posString(p.position + 9));
                            p.position += 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifica daca poate muta pe diagonala dreapta inainte
            else if((b.tabla->at(p.position + 11).culoare == "i") || (b.tabla->at(p.position + 11).culoare == "a")) {
                        b.tabla->at(p.position + 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 11;
                            }

                            mut = posString(p.position).append(posString(p.position + 11));
                            p.position += 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifica daca poate muta in dreapta
            else if((b.tabla->at(p.position + 1).culoare == "i") || (b.tabla->at(p.position + 1).culoare == "a")) {
                        b.tabla->at(p.position + 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position + 1;
                            }

                            mut = posString(p.position).append(posString(p.position + 1));
                            p.position += 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position + 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifica daca poate muta in stanga
             else if((b.tabla->at(p.position - 1).culoare == "i") || (b.tabla->at(p.position - 1).culoare == "a")) {
                        b.tabla->at(p.position - 1) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 1;
                            }

                            mut = posString(p.position).append(posString(p.position - 1));
                            p.position -= 1;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 1) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta pe diagonala dreapta inapoi
            else if((b.tabla->at(p.position - 9).culoare == "i") || (b.tabla->at(p.position - 9).culoare == "a")) {
                        b.tabla->at(p.position - 9) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 9;
                            }

                            mut = posString(p.position).append(posString(p.position - 9));
                            p.position -= 9;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 9) = in;
                            b.tabla->at(p.position) = p;
                            return in;
                        }
            }
            //Verifica daca poate muta pe diagonala stanga inapoi
            else if((b.tabla->at(p.position - 11).culoare == "i") || (b.tabla->at(p.position - 11).culoare == "a")) {
                        b.tabla->at(p.position - 11) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 11;
                            }

                            mut = posString(p.position).append(posString(p.position - 11));
                            p.position -= 11;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 11) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
            //Verifica daca poate muta inapoi
            else if((b.tabla->at(p.position - 10).culoare == "i") || (b.tabla->at(p.position - 10).culoare == "a")) {
                        b.tabla->at(p.position - 10) = p;
                        b.tabla->at(p.position) = in;
                        if(!sah(b)){
                            for(int i = 0; i < 16; i++)
                            {
                                if(b.pozitii[i] == p.position)
                                    b.pozitii[i] = p.position - 10;
                            }

                            mut = posString(p.position).append(posString(p.position - 10));
                            p.position -= 10;
                            std::cout<<"move "<<mut<<"\n";
                            return p;
                        }else{
                            b.tabla->at(p.position - 10) = in;
                            b.tabla->at(p.position) = p;
                            return in;

                        }
            }
			else
            {
                return in;
            }
        }
    }

    return in;
}

int main()
{
    //cout<<pos("a6")<<endl;
    bool primaMutare = true;
    std::string s;
    piesa p;
    srand(time(NULL));
    //Creeam placa noastra;
    Board *test;
    for (;;) {
        std::cin>>s;
        if (!s.compare("xboard"))
        {
            std::cout << "\n";
            continue;
        }
        if (!s.compare("new"))
        {
            turn = true;
            test = new Board();
            p = test->tabla->at(33);
            continue;
        }
        if (!s.compare("go"))
        {
            p = in;
            if(primaMutare == true)
            {
                if(turn == true)
                    p = test->tabla->at(33);
                else
                    p = test->tabla->at(86);
                primaMutare = false;
                p = move(p, *test);
            }
           while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }
        if (!s.compare("force"))
        {
            while(1)
            {
                std::string a;
                std::cin>>a;
                if (!a.compare("new"))
                {
                    turn = true;
                    test = new Board();
                    p = test->tabla->at(33);
                    break;
                }
                if(format(a))
                {

					posFinal = pos(a.substr(2,2));
					for(int i = 0; i < 16; i++)
						if(test->pozitii[i] == posFinal)
                        {
                            test->pozitii[i] = -1;
                        }
                    test->mutare(a);


                }
                if(!a.compare("go"))
                {
                    p = in;
                    if(primaMutare == true)
                    {
                        if(turn == true)
                            p = test->tabla->at(33);
                        else
                            p = test->tabla->at(86);
                        primaMutare = false;
                        p = move(p, *test);
                    }
                   while(p.culoare == in.culoare)
					{
						int i = randomPos(15);
						if(test->pozitii[i] != -1)
                        {
							p = test->tabla->at(test->pozitii[i]);
							p.position = test->pozitii[i];
							p = move(p, *test);
						}
					}
                    break;
				 }
                 if (!a.compare("white"))
                 {
                    turn = false;
                    p = test->tabla->at(86);
                    continue;
                 }
                 if (!a.compare("black"))
                 {
                    turn = true;
                    continue;
                 }

            continue;
            }
        }
        if (!s.compare("protover"))
        {
            std::cout<<"done=1\n";
            continue;
        }
        if (!s.compare("white"))
        {
            turn = false;
            continue;
        }
        if (!s.compare("black"))
        {
            turn = true;
            continue;
        }

        if (!s.compare("quit"))
        {
            return 0;
            break;
        }
        //DE AICI E ROCADA
        if((!s.compare("e1g1")) && (test->tabla->at(95).tip == 6))
        {
            string movetura = "h1f1";
            test->mutare(s);
            test->mutare(movetura);
            p = in;
            while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }
        if(!s.compare("e1c1") && (test->tabla->at(95).tip == 6))
        {
            string movetura = "a1d1";
            test->mutare(s);
            test->mutare(movetura);
            p = in;
            while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }
        if(!s.compare("e8g8") && (test->tabla->at(25).tip == 6))
        {
            string movetura = "h8f8";
            test->mutare(s);
            test->mutare(movetura);
            p = in;
            while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }
        if(!s.compare("e8c8") && (test->tabla->at(25).tip == 6))
        {
            string movetura = "a8d8";
            test->mutare(s);
            test->mutare(movetura);
            p = in;
            while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }

//AICI SE TERMINA ROCADA

        if(format(s))
        {
			posFinal = pos(s.substr(2,2));
			for(int i = 0; i < 16; i++)

				if(test->pozitii[i] == posFinal)
                {
					test->pozitii[i] = -1;
                }
            test->mutare(s);
            if(sah(*test)){
                int rege = test->pozitii[15];
                int cercRege[8];
                int i = 0;
                cercRege[0] =  rege + 1;
                cercRege[1] =  rege - 1;
                cercRege[2] =  rege + 9;
                cercRege[3] =  rege - 9;
                cercRege[4] =  rege + 10;
                cercRege[5] =  rege - 10;
                cercRege[6] =  rege + 11;
                cercRege[7] =  rege - 11;
                piesa aux;
                int auxPos;
                while(i < 8)
                {
                    if(test->tabla->at(cercRege[i]).culoare == "o")
                    {
                        i++;
                        continue;
                    }
                    else if(turn == true && test->tabla->at(cercRege[i]).culoare == "n")
                    {
                        i++;
                        continue;
                    }
                    else if(turn == false && test->tabla->at(cercRege[i]).culoare == "a")
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        //Salvez piesa care se afla pe pozitia cercRege[i];
                        aux = test->tabla->at(cercRege[i]);
                        auxPos = test->tabla->at(cercRege[i]).position;
                        //Mut Regele
                        test->tabla->at(cercRege[i]) = test->tabla->at(rege);
                        test->tabla->at(rege) = in;
                        test->pozitii[15] = cercRege[i];
                    }
                    if(!sah(*test))
                    {
                        break;
                    }
                    //Refac Tabla;
                    test->pozitii[15] = rege;
                    test->tabla->at(rege) = Kn;
                    test->tabla->at(rege).position = rege;
                    test->tabla->at(i) = aux;
                    test->tabla->at(i).position = auxPos;
                    i++;
                }

                string mut = posString(rege).append(posString(cercRege[i]));
                test->pozitii[15] = cercRege[i];
                rege = cercRege[i];
                cout<<"move "<<mut<<endl;
                continue;
            }
            if(primaMutare == true)
            {
                if(turn == true)
                    p = test->tabla->at(33);
                else
                    p = test->tabla->at(86);
                primaMutare = false;
                p = move(p, *test);
                continue;
            }
            p = in;
			while(p.culoare == in.culoare)
            {
                int i = randomPos(15);
                if(test->pozitii[i] != -1)
                {
                    p = test->tabla->at(test->pozitii[i]);
                    p.position = test->pozitii[i];
                    p = move(p, *test);
                }
            }
            continue;
        }
    }
    delete test;
    return 0;
}
