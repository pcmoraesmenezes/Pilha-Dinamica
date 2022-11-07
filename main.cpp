#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct no_
{
int valor;
int chave;
no_ * prox;
}no;
no* topo;
no* iniciaLista() // Criação de uma função que alocara os espaços na memoria
{
  topo = NULL;
  no * tmp = new(no);
  tmp->chave = 0;
  tmp->valor = 0;
  tmp->prox = NULL;
}
void encerraLista()
{
  no * ant;
  ant = topo;
  while(topo!=NULL)
    {
      free(ant);
      topo = topo->prox;
    }
}

void busca_enc(int chave,  no**ret) // o ponteiro ja leva o resultado entao a função pode ser do tipo void
{
  no * pont  = topo;
  *ret = NULL;
  
  while(pont!=NULL)
    {
      if(pont->chave < chave)
      {
        pont = pont->prox;
        
      }
      else
      {
        if(pont->chave == chave)
        {
          *ret = pont;
        }
        pont = NULL;
      }
   
     }
}
 int insere(int chave, int valor)
{
  no* ret;
  int retorno = -1;
  busca_enc(chave,&ret);
if(ret == NULL)
{
  no * ptr = new(no);
  ptr->chave = chave;
  ptr->valor = valor;
  ptr->prox = topo;
  topo = ptr;
  retorno =  0;
}
  return retorno;
  }

void imprime()
{
  no * ptr = topo;
  while(ptr!=NULL)
    {
      printf("Chave: %d| Valor : %d\n", ptr->chave, ptr->valor);
      ptr = ptr->prox;
    }
  printf("-------------------------\n");
}
no* remove()
{
  no * remove = NULL;
  if(topo !=NULL)
  {
    remove = topo;
    topo = topo->prox;
    
  }
  return remove;
}
int main(){
 iniciaLista();

  printf("valor retornado: %d\n", insere(1, 4));
  imprime();
  printf("valor retornado: %d\n", insere(2, 486));
  imprime();
  printf("valor retornado: %d\n", insere(3, 45));
  imprime();

  remove();
  imprime();
  encerraLista();
  }