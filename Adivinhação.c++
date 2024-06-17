#include <iostream>
using namespace std;

int main()
{
    //Espaço para variaveis
    int num_secreto=23;
    int chute=0;

    //Capa do jogo
    cout<<"*********************"<<endl;
    cout<<"*Jogo de adivinhação*"<<endl;
    cout<<"*********************"<<endl; 

    //Pegando entrada do usuario
    cout<<"Digite um número entre 0 e 99: ";
    cin>>chute;

    //Verificação do chute
    if(chute==num_secreto)
    {
        cout<<"Parabéns, você acertou"<<endl;
    }

    else if(chute>100||chute<0)
    {
        cout<<"Opção invalida"<<endl;
    }

    else if(chute<num_secreto)
    {
        cout<<"O número secreto é maior que "<<chute<<endl;
    }

    else if(chute>num_secreto)
    {
        cout<<"O número secreto é menor que "<<chute<<endl;
    }

}