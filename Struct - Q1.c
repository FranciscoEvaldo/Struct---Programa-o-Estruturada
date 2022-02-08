/*A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre salário, idade e número de filhos.
Faça um programa que leia esses dados de 20 pessoas, calcule e mostre: 
a) a média de salário da população;
b) a média do número de filhos;
c) o maior salário;
d) o percentual de mulheres com salário superior a R$1000,00.

Aluno: Francisco Evaldo Benevenuto Lima*/

#include <stdio.h>
#define Q_PESSOAS 20

typedef struct{
    float salario;
    int idade;
    int q_filhos;
    char sexo;
} pessoas;

void main(void)
{
   pessoas pessoa[Q_PESSOAS];
   float media_salario = 0, m_filhos = 0, maior_salario = 0;
   int cont_n_mulheres = 0;
   
   printf("Preencha os dados a seguir \n");
   
   for(int i = 0; i < Q_PESSOAS; i++){
       
       printf("\nHabitante %d\n", i+1);
       printf("\nSalário: ");
       scanf("%f", &pessoa[i].salario);
       printf("\nIdade: ");
       scanf("%d", &pessoa[i].idade);
       printf("\nNúmero de filhos: ");
       scanf("%d", &pessoa[i].q_filhos);
       printf("\nDigite M para (Masculino) ou F para (Feminino) ");
       printf("\nSexo: ");
       scanf("%s", &pessoa[i].sexo);
       printf("\n\n");
       
       if(pessoa[i].salario > maior_salario){
           maior_salario = pessoa[i].salario;
       }
       
       if(pessoa[i].sexo == 'F' && pessoa[i].salario > 1000){
           cont_n_mulheres = cont_n_mulheres + 1;
       }
       
       media_salario = media_salario + pessoa[i].salario;
       m_filhos = m_filhos + pessoa[i].q_filhos;
   }
   
   for(int i = 0; i < Q_PESSOAS; i++){
       printf("Seu salario: %0.2f reais\n", pessoa[i].salario);
       printf("Sua idade é: %d anos\n", pessoa[i].idade);
       printf("Você tem: %d filhos\n", pessoa[i].q_filhos);
       printf("Você é do sexo: %c\n", pessoa[i].sexo);
       printf("\n");
   }
   
   printf("A média salarial da população é de: R$ %0.2f reais\n", media_salario/Q_PESSOAS);
   printf("A média de filhos da população é de: %0.1f filhos\n", m_filhos/Q_PESSOAS);
   printf("O maior salário é: R$ %0.2f reais\n", maior_salario);
   printf("%d%% das mulheres tem o salário superior a R$ 1000,00 reais", (cont_n_mulheres*100)/Q_PESSOAS);
}

