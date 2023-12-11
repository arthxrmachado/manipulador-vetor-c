/*
	Arthur Lourenço Machado 			1920478300009		Turma B
	João Vitor de Freitas de Castro		1920478300027		Turma B
*/

#include <stdio.h>

#define CAP tamanho

//buscar itens na lista
int buscarItens(int a[], int c, int b) {

    int i;

    for (i=0; i<c; i++) {

        if (a[i]==b) {

            return i; //termina, caso encontre um valor

        }
    }

    return -1;

}

//buscar posicao na lista
int buscarPosicao(int a[], int c, int b) {

    int i;

    for (i=0; i<c; i++) {
    	
        if (i==b) {

            return a[i]; //termina, caso encontre um valor

        }
    }

    return -1;

}

//exibir os itens da lista
void exibirItens(int a[], int c) {

    int i;

    printf("\nLista: ");

    for (i=0; i<c; i++) {

        printf("%d; ", a[i]);

    }
}

//exibir os itens pares
void exibirPares(int a[], int c) {

    int i;

    printf("\nLista de pares: ");

    for (i=0; i<c; i++) {
    
        if(a[i]%2==0){

            printf("%d; ", a[i]);
        }

    }
}

//exibir os itens ímpares
void exibirImpares(int a[], int c) {

    int i;

    printf("\nLista de impares: ");

    for (i=0; i<c; i++) {
    
        if(a[i]%2!=0){

            printf("%d; ", a[i]);
        }

    }
}

//inserir e ordenar os itens da lista
void inserirItens(int a[], int *c, int inserir, int *d) {

    int i, res;

    res=buscarItens(a, *c, inserir);

    if (res == -1) {

        if (*c==0) {

            a[0] = inserir;

        } else {

            for (i=*c; i>=*d; i--) {

                a[i+1]=a[i];

            }

            a[*d]=inserir;

        }

        ++*c;

        if (inserir%2==0) {

            ++*d;

        }
        
        printf("\nNumero inserido com sucesso.\n");

    } else {

        printf("\nO numero %d ja existe nesta lista", inserir);

    }
}

//remover itens da lista
void removerItens(int a[], int *c, int remover, int *d) {

    int i=0, j=0, res;

    res=buscarItens(a, *c, remover);

    if (res!=-1) {

        for (j=res; j<*c; j++) {

            a[j] = a[j+1];

        }
        --*c;

        if (remover%2==0) {

            --*d;
        }

        j++;
        
    	printf("\nNumero removido com sucesso.");

    } else {

        printf("\nO numero %d nao existe nesta lista", remover);

    }
}

//remover posicao da lista
void removerPosicao(int a[], int *c, int remover, int *d) {

    int i=0, j=0, res;

    res=buscarPosicao(a, *c, remover);
    
    res=buscarItens(a, *c, res);

    
    if (res!=-1) {

        for (j=res; j<*c; j++) {

            a[j] = a[j+1];

        }
        --*c;

        if (remover%2==0) {

            --*d;
        }

        j++;
        
        printf("\nNumero removido com sucesso.");

    } else {

        printf("\nA posicao %d nao existe nesta lista", remover);

    }
}

//substituir itens da lista
void alterarItens(int a[], int *c, int numeroAntigo, int numeroNovo, int *d) {

    int antigo, novo;

    novo=buscarItens(a, *c, numeroNovo);

    antigo=buscarItens(a, *c, numeroAntigo);

    if((novo==-1)&&(antigo!=-1)) {

        inserirItens(a, c, numeroNovo, d);

        removerItens(a, c, numeroAntigo, d);

    }else{

        printf("\nErro! Nao existe o valor inserido na lista. ");

    }
}

//principal

int main() {

    int opcao, num, old_num, res;

    int tamanho=0, pares=0;

    int lista[CAP];

    do {
    	
    	printf("======================\n\nManipulador de Vetores\n\n======================"); 

        printf("\n\n[1] Adicionar um numero\n");

        printf("[2] Remover um numero\n");

        printf("[3] Remover um numero de determinada posicao\n");
        
        printf("[4] Alterar um numero\n");

        printf("[5] Buscar um numero\n");

        printf("[6] Exibir a lista\n");

        printf("[7] Exibir a lista de pares\n");

        printf("[8] Exibir a lista de impares\n");
        
        printf("[9] Encerrar o Programa\n");
        
        printf("\nSelecione uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {

        case 1:

            printf("\nInsira um numero: ");

            scanf("%d", &num);

            inserirItens(lista, &tamanho, num, &pares);
            
            getch();
            
            system("cls");

            break;

        case 2:
        	
        	exibirItens(lista, tamanho);

            printf("\n\nRemova um numero: ");

            scanf("%d", &num);

            removerItens(lista, &tamanho, num, &pares);
            
            getch();
            
            system("cls");

            break;
        
        case 3:
        	
        	exibirItens(lista, tamanho);

            printf("\n\nInforme a posicao: ");

            scanf("%d", &num);

            removerPosicao(lista, &tamanho, num, &pares);
            
            getch();
            
            system("cls");

            break;

        case 4:
        	
        	exibirItens(lista, tamanho);

            printf("\n\nNumero que deseja substituir: ");

            scanf("%d", &old_num);

            printf("\nNovo numero: ");

            scanf("%d", &num);

            alterarItens(lista, &tamanho, old_num, num, &pares);
            
            getch();
            
            system("cls");

            break;

        case 5:
        	
        	exibirItens(lista, tamanho);

            printf("\n\nNumero que deseja buscar: ");

            scanf("%d", &num);

            res=buscarItens(lista, tamanho, num);

            if (res!=-1) {

                printf("\nO numero %d se encontra no indice %d.", num, res);

            } else {

                printf("\nNumero nao encontrado.");

            }
            
            getch();
            
            system("cls");

            break;

        case 6:

            exibirItens(lista, tamanho);
            
            getch();
            
            system("cls");

            break;
            
        case 7:

            exibirPares(lista, tamanho);
            
            getch();
            
            system("cls");

            break;
            
        case 8:

            exibirImpares(lista, tamanho);
            
            getch();
            
            system("cls");

            break;

        case 9:

            printf("\nFim de Programa!");

            break;

        default:

            printf("\nErro! Opcao invalida, tente novamente!");
            
            getch();
            
            system("cls");

        }
    } while (opcao!=9);
}
    
