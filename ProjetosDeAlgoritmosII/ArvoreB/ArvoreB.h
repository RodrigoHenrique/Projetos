#ifndef ARVOREB_H
#define ARVOREB_H

class ArvoreB
{
public:
    ArvoreB();
    ~ArvoreB();
    
    const static int D;
    
    void incTotalChaves();
    void decTotalChaves();
    static void insereChave(const int &,ArvoreB &);
    void insereElemento(const int &);
    void inicializaChaves();
    void insereFilha();
    void buscaChave(const int &);
    void removeChave(const int &);
    
    short int getTotalChaves() const;
    int getChave() const;
    
    short int getTotalFilhas() const;
    void incTotalFilhas();
    void decTotalFilhas();
    
    void setInseriuChave();
    void naoInseriuChave();
    bool getInseriuChave() const;
    
    void setChaveApontaNull();
    bool getChaveApontaNull() const;
    
private:
    short int totalChaves;
    short int totalFilhas;
    int *chaves;
    ArvoreB *filha;
    
    bool inseriuChave;
    
    bool chaveApontaNull;

};

#endif // ARVOREB_H
