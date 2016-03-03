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

const ArvoreB & ArvoreB::operator =(const ArvoreB &treeAtrib)
{
    totalChaves = treeAtrib.totalChaves;
    totalFilhas = treeAtrib.totalFilhas;
    inseriuChave = treeAtrib.inseriuChave;
    chaveApontaNull = treeAtrib.chaveApontaNull;
    filhaApontaNull = treeAtrib.filhaApontaNull;
    
    delete [] chaves;
    chaves = new int[treeAtrib.totalChaves];
    for(int i=0;i<treeAtrib.totalChaves;i++) chaves[i] = treeAtrib.chaves[i];
    
    delete [] filha;
    filha = new ArvoreB[treeAtrib.totalFilhas];
    for(int i=0;i<treeAtrib.totalFilhas;i++) filha[i] = treeAtrib.filha[i];
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
        if(tree.getTotalChaves() < D-1)
        {
            tree.insereElemento(valor);
            tree.incTotalChaves();
            tree.setInseriuChave();
        }
        else
        {
            tree.setFilhaApontaNull();
            if(tree.getFilhaApontaNull())
            {
                tree.inicializaFilhas();
                ArvoreB newTree = tree.filha[tree.getTotalFilhas()];
                insereChave(valor,newTree);
                tree.incTotalFilhas();
            }
            else
            {
                ArvoreB newTree = tree.filha[tree.getTotalFilhas()];
                insereChave(valor,newTree);
                tree.incTotalFilhas();
            }
        }
    }
}

void ArvoreB::insereElemento(const int &Elem)
{
    int ind = 0;
    for(int i=0;i<totalChaves;i++) if(chaves[i] > Elem) ind = i;
    for(int j=totalChaves-2;j>ind;j--) chaves[j + 1] = chaves[j];
    chaves[ind] = Elem;
}

void ArvoreB::inicializaChaves()
{
    chaves = new int[D-1];
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

short int ArvoreB::getTotalChaves() const
{
    return this->totalChaves;
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

void ArvoreB::setFilhaApontaNull()
{
    if(this->filha == 0) filhaApontaNull = true;
    else filhaApontaNull = false;
}

bool ArvoreB::getFilhaApontaNull() const
{
    return this->filhaApontaNull;
}

void ArvoreB::inicializaFilhas()
{
     filha = new ArvoreB[D];
}

const void ArvoreB::imprimeArvore(const ArvoreB &tree)
{
    if(tree.filha != 0)
    {
        ArvoreB newTree = tree.filha[tree.getTotalFilhas()];
        for(int i=0;i<tree.getTotalFilhas();i++) imprimeArvore(newTree[i]);
        
    }
    else
    {
        
    }
}