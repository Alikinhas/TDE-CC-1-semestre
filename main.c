#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // para tolower() ou toupper()
#include <math.h> // para usar infinity


#define MAX_ROWS 40
#define MAX_COLS 10

int main() {
    FILE *fp;
    char filename[] = "Dadoscsv2.csv";
    char line[1000];
    char *token = NULL;
    int x, y; 
    y = -1;
    x = -1;

    char matriz[MAX_ROWS][MAX_COLS][100];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        y++;
        x = -1;
        token = strtok(line, ";");
        while (token != NULL && x < MAX_COLS - 1) {
            x++;
//            printf("%s\t", token);
            strncpy(matriz[y][x], token, sizeof(matriz[0][0]));
            token = strtok(NULL, ";");
        }
//        printf("\n");
    }

    fclose(fp);

    // imprimir a matriz
//    printf("\nMatriz:\n\n\n");
    for (y = 0; y < MAX_ROWS - 4; y++) {
        for (x = 0; x < MAX_COLS; x++) {
//            printf("%s\t", matriz[y][x]);
            
        }
//        printf("\n");
    }
  int n;
  n = 0;

  while (n == 0){

    
  printf("Para pesquisa produto agrícola, digite:\n\n");
  printf("0 - Para exibir todos os produtos\n");
  printf("1 - Para pesquisar por área de cultivo\n");
  printf("2 - Para pesquisar por produção\n");
  printf("3 - Para pesquisar por inicial\n");
  printf("4 - Para sair\n");

  int num_lidos = scanf("%i", &n); //lendo e contando quantos numeros foram lidos
  while (num_lidos != 1 || (n < 0 || n > 4)) {
    printf("Entrada inválida. Tente novamente:\n");
    while (getchar() != '\n'); // Limpa o buffer do teclado
      num_lidos = scanf("%i", &n);
  }  

  if (n == 4){
    printf("Adeus!\n");
    return 0;
  }
  else if (n == 3){
    //inicial
    char letra[1];
    printf ("Digite a inicial do produto desejado:\n");
    scanf(" %c", &letra[0]);
    printf ("Temos esses produtos com a inicial %c:\n\n", letra[0]);
    x = 0;

    printf("Produtos agrícolas           | Área (ha)  |        | Produção (t)|\n");
    printf("                             | Total      |Partic %|Total        |Partic %\n");
    printf("TOTAL                        |76 097 204  |100     |299 651 793  |100\n\n");
    
    for (y = 7; y < 28; y++){
      if (matriz[y][0][0] == toupper(letra[0]) ){
        printf ("%-28s | %-10s | %-6s | %-11s | %-6s\n", matriz[y][0], matriz[y][1], matriz[y][2], matriz[y][3], matriz[y][4]);
        x = 1;
      }
    }
    if (x == 0){
      printf("Nenhum produto foi encontrado!\n");
    }
    printf ("\n");
    n = 0; 
  }
  else if (n == 2){
    // profução
    float prod;
    printf ("Digite a produção (t) que deseja pesquisar:\n");
    num_lidos = scanf ("%f", &prod);

    while (num_lidos != 1 || prod < 0 ) {
      printf("Entrada inválida. Tente novamente:\n");
      while (getchar() != '\n'); // Limpa o buffer do teclado
        num_lidos = scanf("%f", &prod);
    }  
    


    
    printf ("Os cinco produtos com produção mais próximos de %.1f são:\n\n", prod);

    printf("Produtos agrícolas           | Área (ha)  |        | Produção (t)|\n");
    printf("                             | Total      |Partic %|Total        |Partic %\n");
    printf("TOTAL                        |76 097 204  |100     |299 651 793  |100\n\n");

    float lista[22];
    float nprod;
    
    for (y = 7; y < 28; y++){

      nprod = atof(matriz [y][3]);
      lista [y-7] = abs(nprod - prod);
    }

    int index;
    float diff;
    
    for (x = 0; x < 5; x++) {
    diff = lista[0];
    index = 0;
    for (y = 1; y < 21; y++) {
        if (lista[y] < diff) {
            diff = lista[y];
            index = y;
        }
    }
    printf("%-28s | %-10s | %-6s | %-11s | %-6s\n", matriz[index+7][0], matriz[index+7][1], matriz[index+7][2], matriz[index+7][3], matriz[index+7][4]);
    lista[index] = INFINITY;
    }
   n = 0; 
  }
  else if (n == 1){
    //área
    float prod;
    printf ("Digite a área (ha) que deseja pesquisar:\n");
    num_lidos = scanf ("%f", &prod);

    while (num_lidos != 1 || prod < 0 ) {
      printf("Entrada inválida. Tente novamente:\n");
      while (getchar() != '\n'); // Limpa o buffer do teclado
        num_lidos = scanf("%f", &prod);
    }  
    
    printf ("Os cinco produtos com área de cultivo mais próximos de %.1f são:\n\n", prod);

    printf("Produtos agrícolas           | Área (ha)  |        | Produção (t)|\n");
    printf("                             | Total      |Partic %|Total        |Partic %\n");
    printf("TOTAL                        |76 097 204  |100     |299 651 793  |100\n\n");

    float lista[22];
    float nprod;
    
    for (y = 7; y < 28; y++){

      nprod = atof(matriz [y][1]);
      lista [y-7] = abs(nprod - prod);
    }

    int index;
    float diff;
    
    for (x = 0; x < 5; x++) {
    diff = lista[0];
    index = 0;
    for (y = 1; y < 21; y++) {
        if (lista[y] < diff) {
            diff = lista[y];
            index = y;
        }
    }
    printf("%-28s | %-10s | %-6s | %-11s | %-6s\n", matriz[index+7][0], matriz[index+7][1], matriz[index+7][2], matriz[index+7][3], matriz[index+7][4]);
    lista[index] = INFINITY;
    }
   n = 0; 
    
  }
  else if (n == 0){

    printf("Produtos agrícolas           | Área (ha)  |        | Produção (t)|\n");
    printf("                             | Total      |Partic %|Total        |Partic %\n");
    printf("TOTAL                        |76 097 204  |100     |299 651 793  |100\n\n");
    
    for (y = 7; y < 28; y++){
        printf ("%-s | %-10s | %-6s | %-11s | %-6s\n", matriz[y][0], matriz[y][1], matriz[y][2], matriz[y][3], matriz[y][4]);
       
      
    }
    printf ("\n");
    n = 0; 
    
  }
  
    
  else{
    printf("Discagem incorreta, tente novamente\n");
    n = 0;
  }

  }



















  
    return 0;
}