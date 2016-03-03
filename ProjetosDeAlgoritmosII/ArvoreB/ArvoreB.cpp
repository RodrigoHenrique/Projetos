#include "ArvoreB.h"

const int ArvoreB::D = 3;

ArvoreB::ArvoreB()
{
    totalChaves = 0;
    chaves = 0;
    filha = 0;
    
    
}

ArvoreB::~ArvoreB()
{
    delete [] chaves;
    delete [] filha;
}

void ArvoreB::incTotalChaves()
{
    totalChaves++;
}

void ArvoreB::decTotalChaves()
{
    totalChaves--;
}

void ArvoreB::insereChave(const int &valor,ArvoreB &tree)
{
    tree.setChaveApontaNull();
    if(tree.getChaveApontaNull())
    {
        tree.inicializaChaves();
        tree.insereElemento(valor);
        tree.incTotalChaves();
        tree.setInseriuChave();
    }
    else
    {
        if(totalChaves < D-1)
        {
            chaves[this->totalChaves] = valor;
            incTotalChaves();
            inseriuChave();
        }
        else
        {
            if(filha == 0)
            {
                insereFilha();
            }
        }
    }
}

void ArvoreB::insereElemento(const int &Elem)
{
    chaves[totalChaves] = Elem;
}

void ArvoreB::inicializaChaves()
{
    chaves = new int[D-1];
}

void ArvoreB::insereFilha()
{
    filha = new ArvoreB[D];
    incTotalFilhas();
}

void ArvoreB::setInseriuChave()
{
    this->inseriuChave = true;
}

void ArvoreB::naoInseriuChave()
{
    this->inseriuChave = false;
}

bool ArvoreB::getInseriuChave() const
{
    return this->inseriuChave;
}

short int ArvoreB::getTotalFilhas() const
{
    return this->totalFilhas;
}

void ArvoreB::incTotalFilhas()
{
    totalFilhas++;
}

void ArvoreB::decTotalFilhas()
{
    totalFilhas--;
}

void ArvoreB::setChaveApontaNull()
{
    if(this->chaves == 0) chaveApontaNull = true;
    else chaveApontaNull = false;
}

bool ArvoreB::getChaveApontaNull() const
{
    return this->chaveApontaNull;
}