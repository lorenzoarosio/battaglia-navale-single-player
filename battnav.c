#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "lib.h"
#include "lib_battnav.h"

//BATTAGLIA NAVALE


#define n 10 //grandezza mare
#define r_nav 1 //righe nave rettangolare
#define c_nav 3 //colonne nave rettangolare
#define n_nav 2 //ordine nave quadrata
#define max_nav_r 5 //numero massimo di navi rettangolari
#define max_nav_q 3 //numero massimo di navi quadrate
#define min_nav 1 //numero minimo di navi

//colori stili
#define NERO "\033[30m"
#define ROSSO "\033[31m"
#define BLU "\033[34m"
#define GRASSETTO "\033[1m"
#define GIALLO  "\033[33m"
#define CIANO   "\033[36m"
#define RESET "\033[0m"




int main ()
{
    srand(time(NULL));
    char mare[n][n];
    char mare_pc[n][n];
    char mare_pc_bis[n][n];//mare da far vedere senza navi al giocatore
    int num_nav_r,num_nav_q;
    int x,y;
    int mira = 0, x_p = 0, y_p = 0, x_u = 0, y_u = 0, dir = 0; //variabili per colpo_pc
    //RICHIESTA NUMERO NAVI
    printf("Benvenuto in battaglia navale!\n");
    printf("inserisci il numero di fregate(1x3) che vuoi inserire (minimo %d, massimo %d): ",min_nav,max_nav_r);
    scanf("%d",&num_nav_r);
    while (num_nav_r<min_nav||num_nav_r>max_nav_r)
    {
        printf("ERRORE!\nla quantit\205 deve essere maggiore di %d e minore di %d,riprova: ",min_nav,max_nav_r);
        scanf("%d",&num_nav_r);
    }
    printf("inserisci il numero di navi portaere(2x2) che vuoi inserire (minimo %d, massimo %d): ",min_nav,max_nav_q);
    scanf("%d",&num_nav_q);
    while (num_nav_q<min_nav||num_nav_q>max_nav_q)
    {
        printf("ERRORE!\nla quantit\205 deve essere maggiore di %d e minore di %d,riprova: ",min_nav,max_nav_q);
        scanf("%d",&num_nav_q);
    }
    clearScreen();
    //INDICIZZAZIONE MARE
    riempi_a_bi_char(n,n,mare,ind_mare);
    riempi_a_bi_char(n,n,mare_pc,ind_mare);
    riempi_a_bi_char(n,n,mare_pc_bis,ind_mare);
    
    //POSIZIONAMENTO NAVI RETTANGOLARI utente
    for(int i=1;i<=num_nav_r;i++)
    {
        char dir;
        stampa_mare(n,mare);
        printf("fregata numero:%d\n\n",i);
        leggi_pos_nave_r(&x,&y,&dir,n,mare,c_nav);
        pos_nav_r(dir,x,y,n,mare,r_nav,c_nav);
        clearScreen();
    }
    //POSIZIONAMENTO NAVI QUADRATE utente
    for(int i=1;i<=num_nav_q;i++)
    {
        stampa_mare(n,mare);
        printf("nave portaerea numero:%d\n\n",i);
        char dir[3];
        leggi_pos_nave_q(&x,&y,dir,n,mare,n_nav);
        pos_nave_q(dir,x,y,n,mare,n_nav);
        clearScreen();
    }
    stampa_mare(n,mare);
    Sleep(3000);
    clearScreen();

    //POSIZIONAMENTO NAVI QUADRATE COMPUTER
    pos_nav_q_pc(n,mare_pc,n_nav,num_nav_q);
    //stampa_mare(n,mare_pc);
    
    //POSIZIONAMENTO NAVI RETTANGOLARI COMPUTER
    pos_nav_r_pc(n,mare_pc,r_nav,c_nav,num_nav_r);
    stampa_mare(n,mare_pc);

    
    int condizione=0;
    do
    {
        //COLPI DA UTENTE
        stampa_legenda();
        stampa_mare(n,mare_pc_bis);
        printf("\n\n");
        colpito_utente(n,mare_pc,mare_pc_bis);
        Sleep(3000);
        clearScreen();

        
        //COLPI DA CPU
        stampa_legenda();
        stampa_mare(n,mare);
        printf("\n\n");
        colpo_pc(n,mare,&mira,&x_p,&y_p,&x_u,&y_u,&dir);
        Sleep(5000);
        clearScreen();
        

    } while (!condizione);
    
}