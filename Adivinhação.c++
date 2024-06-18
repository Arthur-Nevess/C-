#include <iostream>
using namespace std;

void abertura()
{
    cout<<"*********************"<<endl;
    cout<<"*Jogo de adivinhação*"<<endl;
    cout<<"*********************"<<endl; 
}

void inicia_bools(bool *ganhou,bool *invalida,bool *menor,bool *maior,int chute,int num_secreto)
{
    *ganhou = chute==num_secreto;
    *invalida = chute>=100||chute<0;
    *menor = chute<num_secreto;
    *maior = chute>num_secreto;
}

void analisa_chute(bool ganhou,int *tentativas,bool* acertou,bool invalida,int chute,int num_secreto,bool menor,bool maior,double *pontos)
{
       if(ganhou)
        {
            cout<<"Parabéns, você acertou"<<endl;
            *tentativas++;
            *acertou=1;
        }

        else if(invalida)
        {
            cout<<"Opção invalida"<<endl;chute>num_secreto;
            chute=0;
           
        }

        else if(menor)
        {
            cout<<"O número secreto é maior que "<<chute<<endl;
            *tentativas++;
        }

        else if(maior)
        {
            cout<<"O número secreto é menor que "<<chute<<endl;
            *tentativas++;
        }

        //Definindo pontuação
        double perde_pontos=abs(chute-num_secreto)/2.0;
        *pontos=*pontos-perde_pontos;
}

int main()
{
    //Espaço para variaveis
    int num_secreto=50;
    int chute=0;
    bool acertou=0;
    int tentativas=0;
    double pontos=1000.0;

    //Fazendo extrações das condicionais
    bool ganhou;
    bool invalida;
    bool menor;
    bool maior;

    abertura();

    while(!acertou)
    {
        //Pegando entrada
        cout<<"Digite seu palpite"<<endl;
        cin>>chute;
       
        inicia_bools(&ganhou,&invalida,&menor,&maior,chute,num_secreto);
        analisa_chute(ganhou,&tentativas,&acertou,invalida,chute,num_secreto,menor,maior,&pontos);
    }

    //Mensagem de fim de jogo
    cout<<"Fim de jogo, você finalizou com "<<tentativas<<" tentativas"<<endl;
    cout.precision(2);
    cout<<fixed;
    cout<<"Você fez "<<pontos<<" pontos"<<endl;

    
}