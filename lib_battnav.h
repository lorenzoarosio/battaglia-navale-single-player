#ifndef LIB_BATTNAV_H
#define LIB_BATTNAV_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "lib.h"

//colori stili
#define NERO "\033[30m"
#define ROSSO "\033[31m"
#define BLU "\033[34m"
#define GRASSETTO "\033[1m"
#define GIALLO  "\033[33m"
#define CIANO   "\033[36m"
#define RESET "\033[0m"

#define ind_mare '~' //indice mare
#define ind_nave 'I' //indice presenza nave
#define ind_colpito '#' //indice nave colpita
#define ind_acqua 'X' //indice acqua colpita

//FUNZIONI PER BATTAGLIA NAVALE
//DA LETTERE A NUMERI
int mod_ind(char ind)
{
    if(ind=='A') return 0;
    if(ind=='B') return 1;
    if(ind=='C') return 2;
    if(ind=='D') return 3;
    if(ind=='E') return 4;
    if(ind=='F') return 5;
    if(ind=='G') return 6;
    if(ind=='H') return 7;
    if(ind=='I') return 8;
    if(ind=='J') return 9;
    return -1; // Valore di errore

}
//STAMPA LEGENDA
void stampa_legenda()
{
    printf("LEGENDA:\n");
    printf("~ = acqua\n");
    printf("I = nave\n");
    printf("# = nave colpita\n");
    printf("X = acqua colpita\n\n");
}
//STAMPA MARE CON COORDINATE 
void stampa_mare (int n,char a[n][n])
{
    printf("\t");
    for(char i='A';i<='J';i++)
    {
        printf(GRASSETTO "\t%c" RESET, i);
    }
    printf("\n\n\n");
    for(int i=0;i<n;i++)
	{
        printf(GRASSETTO "\t%d" RESET,i);
		for(int z=0;z<n;z++)
		{
            switch (a[i][z])
            {
                case ind_mare:
                    printf(BLU "\t%c" RESET, a[i][z]);
                    break;
                case ind_nave:
                    printf(GIALLO "\t%c" RESET, a[i][z]);
                    break;
                case ind_colpito:
                    printf(ROSSO "\t%c" RESET, a[i][z]);
                break;
                case ind_acqua:
                    printf(CIANO GRASSETTO"\t%c" RESET, a[i][z]);
                break;
                default:
                    break;
            }
			
		}
		printf("\n\n\n");
	}
}
//LEGGI POSIZIONE NAVE
void leggi_pos_nave_r (int *x,int *y,char *dir,int n,char a[n][n],int c_nav)
{
    printf("scrivi in che coordinata x vuoi posizionare l'estremita' della nave:");
    char ind;
    scanf(" %c", &ind);
    ind = toupper(ind);
    *x = mod_ind(ind);

    printf("scrivi in che y vuoi posizionare l'estremita' della nave:");
    scanf("%d", y);

    while (*x<0 || *x>=n || *y<0 || *y>=n)
    {
        printf("ERRORE! coordinate fuori dal mare,riprova:\n");
        printf("x:");
        char ind;
        scanf(" %c", &ind);
        ind = toupper(ind);
        *x = mod_ind(ind);
        printf("y:");
        scanf("%d", y);
    }
    //controllo se su una nave
    while(a[*y][*x]=='I')
    {
        printf("ERRORE! c'\212 gi\205 una nave in quella posizione,riprova:\n");
        printf("x:");
        char ind;
        scanf(" %c", &ind);
        ind = toupper(ind);
        *x = mod_ind(ind);
        printf("y:");
        scanf("%d", y);
        while (*x<0 || *x>=n || *y<0 || *y>=n)
        {
            printf("ERRORE! coordinate fuori dal mare,riprova:\n");
            printf("x:");
            char ind;
            scanf(" %c", &ind);
            ind = toupper(ind);
            *x = mod_ind(ind);
            printf("y:");
            scanf("%d", y);
        }
    }

    printf("scrivi direzione (N,S,E,O): ");
    scanf(" %c", dir);
    *dir = toupper(*dir);

    while(*dir!='N' && *dir!='S' && *dir!='E' && *dir!='O')
    {
        printf("ERRORE! direzione non valida, riprova: ");
        scanf(" %c", dir);
        *dir = toupper(*dir);
    }

    int cont;
    //controllo se su una nave o esce dai bordi
    do
    {
        cont = 0;
        switch (*dir)
        {
            case 'N':
                for(int i=0;i<c_nav;i++)
                {
                    if(a[*y-i][*x]=='I') cont++;
                    if(*y-i<0) cont++;
                }
                    
                break;
            case 'S':
                for(int i=0;i<c_nav;i++)
                {
                     if(a[*y+i][*x]=='I') cont++;
                    if(*y+i>=n) cont++;
                }
                break;
            case 'E':
                for(int i=0;i<c_nav;i++)
                {
                    if(a[*y][*x+i]=='I') cont++;
                    if(*x+i>=n) cont++;
                }
                break;
            case 'O':
                for(int i=0;i<c_nav;i++)
                {
                    if(a[*y][*x-i]=='I') cont++;
                    if(*x-i<0) cont++;
                }
                break;
        }
        if(cont>0)
        {
            printf("ERRORE! la nave non puo' essere posizionata in quella direzione,riprova:\n");
            printf("scrivi direzione (N,S,E,O): ");
            scanf(" %c", dir);
            *dir = toupper(*dir);
            while(*dir!='N' && *dir!='S' && *dir!='E' && *dir!='O')
            {
                printf("ERRORE! direzione non valida, riprova: ");
                scanf(" %c", dir);
                *dir = toupper(*dir);
            }
        }
    } while(cont>0);
}
//MODIFICA POS QUADRATA IN NUMERO
int mod_pos_q (char dir[])
{
    if(strcmp(dir,"NE")==0)
    {
        return 1;
    }
    else if(strcmp(dir,"NO")==0)
    {
        return 2;
    }
    else if(strcmp(dir,"SE")==0)
    {
        return 3;
    }
    else if(strcmp(dir,"SO")==0)
    {
        return 4;
    }

    return -1; // Valore di errore
}
//LEGGI POS NAVE QUADRATA
void leggi_pos_nave_q (int *x,int *y,char dir[],int n,char a[n][n],int n_nav)
{
    printf("scrivi in che coordinata x vuoi posizionare l'angolo della nave:");
    char ind;
    scanf(" %c", &ind);
    ind = toupper(ind);
    *x = mod_ind(ind);
    printf("scrivi in che coordinata y vuoi posizionare l'angolo della nave:");
    scanf("%d", y);

    while (*x<0 || *x>=n || *y<0 || *y>=n)
    {
        printf("ERRORE! coordinate fuori dal mare,riprova:\n");
        printf("x:");
        char ind;
        scanf(" %c", &ind);
        ind = toupper(ind);
        *x = mod_ind(ind);
        printf("y:");
        scanf("%d", y);
    }
    //controllo se su una nave
    while(a[*y][*x]=='I')
    {
        printf("ERRORE! c'\212 gi\205 una nave in quella posizione,riprova:\n");
        printf("x:");
        char ind;
        scanf(" %c", &ind);
        ind = toupper(ind);
        *x = mod_ind(ind);
        printf("y:");
        scanf("%d", y);
        while (*x<0 || *x>=n || *y<0 || *y>=n)
        {
            printf("ERRORE! coordinate fuori dal mare,riprova:\n");
            printf("x:");
            char ind;
            scanf(" %c", &ind);
            ind = toupper(ind);
            *x = mod_ind(ind);
            printf("y:");
            scanf("%d", y);
        }
    }
    //direzione nave
    printf("scrivi che angolo hai indicato  (NE,NO,SE,SO):");
    scanf("%2s",dir);
    for(int i=0;i<2;i++)
    {
        dir[i]= toupper(dir[i]);
    }
    while(strcmp(dir,"NE")!=0 && strcmp(dir,"NO")!=0 && strcmp(dir,"SE")!=0 && strcmp(dir,"SO")!=0)
    {
        printf("ERRORE! angolo non valido, riprova: ");
        scanf("%2s",dir);
        for(int i=0;i<2;i++)
        {
            dir[i]= toupper(dir[i]);
        }
    }
    int cont=0;
    do 
    {
        cont=0;
        switch (mod_pos_q(dir))
        {
            case 1:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        if(a[*y+i][*x-z]=='I') cont++;
                        if(*y+i<0 || *x-z<0) cont++;
                    }
                }
                break;
            case 2:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        if(a[*y+i][*x+z]=='I') cont++;
                        if(*y+i<0 || *x+z<0) cont++;
                    }
                }
                break;
            case 3:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        if(a[*y-i][*x-z]=='I') cont++;
                        if(*y-i<0 || *x-z<0) cont++;
                    }
                }
                break;
            case 4:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        if(a[*y-i][*x+z]=='I') cont++;
                        if(*y-i<0 || *x+z<0) cont++;
                    }
                }
                break;
        }
        if(cont>0)
        {
            printf("ERRORE! la nave non puo' essere posizionata in quella direzione,riprova:\n");
            printf("scrivi che angolo hai indicato  (NE,NO,SE,SO): ");
            scanf("%2s",dir);
            for(int i=0;i<2;i++)
            {
                dir[i]= toupper(dir[i]);
            }
            while(strcmp(dir,"NE")!=0 && strcmp(dir,"NO")!=0 && strcmp(dir,"SE")!=0 && strcmp(dir,"SO")!=0)
            {
                printf("ERRORE! angolo non valido, riprova: ");
                scanf("%2s",dir);
                for(int i=0;i<2;i++)
                {
                    dir[i]= toupper(dir[i]);
                }
            }
        }

    }while(cont>0);
}
//POSIZIONA NAVE RETTANGOLARE
void pos_nav_r (char dir,int x,int y,int n,char a[n][n], int r_nav, int c_nav)
{
    switch (dir)
    {
        case 'N':
        for (int i = 0; i < c_nav; i++)
        {
            a[y-i][x] = 'I';
        }
        break;
    case 'S':
        for (int i = 0; i < c_nav; i++)
        {
            a[y+i][x] = 'I';
        }
        break;
    case 'E':
        for (int i = 0; i < c_nav; i++)
        {
            a[y][x+i] = 'I';
        }
        break;
    case 'O':
        for (int i = 0; i < c_nav; i++)
        {
            a[y][x-i] = 'I';
        }
        break;
    }
    
}
//POSIZIONA NAVE QUADRATA
void pos_nave_q(char dir[],int x,int y,int n,char a[n][n],int n_nav)
{
    switch (mod_pos_q(dir))
        {
            case 1:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        a[y+i][x-z]='I';
                    }
                }
                break;
            case 2:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        a[y+i][x+z]='I';
                    }
                }
                break;
            case 3:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        a[y-i][x-z]='I';
                    }
                }
                break;
            case 4:
                for(int i=0;i<n_nav;i++)
                {
                    for(int z=0;z<n_nav;z++)
                    {
                        a[y-i][x+z]='I';
                    }
                }
                break;
        }
}
//CREA NAVI RETTANGOLARI COMPUTER
void pos_nav_r_pc (int n, char a[n][n], int r_nav, int c_nav, int n_nav)
{
    for(int i=1; i<=n_nav; i++)
    {
        int x, y, dir_num;
        char dir;
        int piazzamento_valido = 0;
        int offset_x=0, offset_y=0;
        if (i%4==1)      { offset_x=0;   offset_y=0;   }
        else if (i%4==2) { offset_x=n/2; offset_y=0;   }
        else if (i%4==3) { offset_x=0;   offset_y=n/2; }
        else if (i%4==0) { offset_x=n/2; offset_y=n/2; }

        do
        {
            int cont=0;
            x = rand()%(n/2)+offset_x;
            y = rand()%(n/2)+offset_y;
            dir_num = rand()%4; // 0:N, 1:S, 2:E, 3:O

            for(int c=0; c<c_nav; c++)
            {
                int ty, tx;
                if      (dir_num==0) { ty=y-c; tx=x; }  // N
                else if (dir_num==1) { ty=y+c; tx=x; }  // S
                else if (dir_num==2) { ty=y;   tx=x+c; }// E
                else                 { ty=y;   tx=x-c; }// O

                // Controllo bordi
                if(ty<0 || ty>=n || tx<0 || tx>=n) { cont++; continue; }

                // Collisione con altre navi
                if(a[ty][tx]=='I') { cont++; continue; }

                // Adiacenza laterale (con controllo bordi)
                if(dir_num<2) // N o S: controllo sinistra/destra
                {
                    if(tx-1>=0  && a[ty][tx-1]=='I') cont++;
                    if(tx+1<n   && a[ty][tx+1]=='I') cont++;
                }
                else // E o O: controllo sopra/sotto
                {
                    if(ty-1>=0  && a[ty-1][tx]=='I') cont++;
                    if(ty+1<n   && a[ty+1][tx]=='I') cont++;
                }
            }

            if(cont==0) piazzamento_valido=1;

        } while(!piazzamento_valido);

        switch(dir_num)
        {
            case 0: dir='N'; break;
            case 1: dir='S'; break;
            case 2: dir='E'; break;
            case 3: dir='O'; break;
        }

        pos_nav_r(dir,x,y,n,a,r_nav,c_nav);
    }
}
// CREA NAVI QUADRATE COMPUTER
void pos_nav_q_pc (int n, char a[n][n], int g_nav, int n_nav)
{
    for(int i=1; i<=n_nav; i++)
    {
        int x, y, dir_num;
        char dir[3];
        int piazzamento_valido = 0;
        
        // Determina l'offset del quadrante in base al numero della nave
        int offset_x= 0, offset_y= 0;
        if (i % 4 == 1) { offset_x = 0; offset_y = 0; }           // Q1
        else if (i % 4 == 2) { offset_x = n/2; offset_y = 0; }    // Q2
        else if (i % 4 == 3) { offset_x = 0; offset_y = n/2; }    // Q3
        else if (i % 4 == 0) { offset_x = n/2; offset_y = n/2; }  // Q4

        // Prova finché non trova una posizione valida (coord + direzione)
        do {
            int cont = 0;
            x = rand() % (n/2) + offset_x;
            y = rand() % (n/2) + offset_y;
            dir_num = rand() % 4; // 0:NE, 1:NO, 2:SE, 3:SO

            // Controlla collisioni per la dimensione effettiva g_nav
            for(int r=0; r<g_nav; r++) 
            {
                for(int c=0; c<g_nav; c++) 
                {
                    int ty, tx;
                    // Calcolo coordinate in base alla direzione scelta
                    if(dir_num == 0)      { ty = y+r; tx = x-c; } // NE
                    else if(dir_num == 1) { ty = y+r; tx = x+c; } // NO
                    else if(dir_num == 2) { ty = y-r; tx = x-c; } // SE
                    else if(dir_num == 3) { ty = y-r; tx = x+c; } // SO

                    // Controllo bordi e presenza altre navi
                    if(ty < 0 || ty >= n || tx < 0 || tx >= n || a[ty][tx] == 'I') {
                        cont++;
                    }
                }
            }

            if(cont == 0) piazzamento_valido = 1;

        } while(!piazzamento_valido);

        // Traduci dir_num in stringa per la funzione pos_nave_q
        switch (dir_num) {
            case 0: strcpy(dir, "NE"); break;
            case 1: strcpy(dir, "NO"); break;
            case 2: strcpy(dir, "SE"); break;
            case 3: strcpy(dir, "SO"); break;
        }

        pos_nave_q(dir, x, y, n, a, g_nav);
    }
}
// CONTROLLO NAVE AFFONDATA (per navi rettangolari 1x3 e quadrate 2x2)
int controlla_affondata(int n, char a[n][n], int x, int y) 
{
    //controllo nave rettangolare

    // 1. Controllo a DESTRA (2 punti consecutivi)
    if (x + 2 < n && a[y][x+1] == ind_colpito && a[y][x+2] == ind_colpito) {
        return 1; 
    }
    // 2. Controllo a SINISTRA (2 punti consecutivi)
    if (x - 2 >= 0 && a[y][x-1] == ind_colpito && a[y][x-2] == ind_colpito) {
        return 1; 
    }
    // 3. Controllo SOTTO (2 punti consecutivi)
    if (y + 2 < n && a[y+1][x] == ind_colpito && a[y+2][x] == ind_colpito) {
        return 1; 
    }
    // 4. Controllo SOPRA (2 punti consecutivi)
    if (y - 2 >= 0 && a[y-1][x] == ind_colpito && a[y-2][x] == ind_colpito) {
        return 1; 
    }
    // 5. Controllo CENTRO ORIZZONTALE (1 punto a sx e 1 punto a dx)
    if (x + 1 < n && x - 1 >= 0 && a[y][x+1] == ind_colpito && a[y][x-1] == ind_colpito) {
        return 1; 
    }
    // 6. Controllo CENTRO VERTICALE (1 punto sopra e 1 punto sotto)
    if (y + 1 < n && y - 1 >= 0 && a[y+1][x] == ind_colpito && a[y-1][x] == ind_colpito) {
        return 1; 
    }

    
    // CONTROLLI NAVE QUADRATA (2x2)

    // 7. (x, y) è in ALTO A SINISTRA rispetto al resto della nave
    if (x + 1 < n && y + 1 < n && 
        a[y][x+1] == ind_colpito && a[y+1][x] == ind_colpito && a[y+1][x+1] == ind_colpito) {
        return 1;
    }
    
    // 8. (x, y) è in ALTO A DESTRA rispetto al resto della nave
    if (x - 1 >= 0 && y + 1 < n && 
        a[y][x-1] == ind_colpito && a[y+1][x] == ind_colpito && a[y+1][x-1] == ind_colpito) {
        return 1;
    }

    // 9. (x, y) è in BASSO A SINISTRA rispetto al resto della nave
    if (x + 1 < n && y - 1 >= 0 && 
        a[y][x+1] == ind_colpito && a[y-1][x] == ind_colpito && a[y-1][x+1] == ind_colpito) {
        return 1;
    }

    // 10. (x, y) è in BASSO A DESTRA rispetto al resto della nave
    if (x - 1 >= 0 && y - 1 >= 0 && 
        a[y][x-1] == ind_colpito && a[y-1][x] == ind_colpito && a[y-1][x-1] == ind_colpito) {
        return 1;
    }

    return 0; 
}
//CONTROLLO SE TUTTE LE NAVI SONO COLPITE
int controllo_vittoria(int n, char a[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<n;z++)
        {
            if(a[i][z]==ind_nave)
            {
                return 0;
            }
        }
    }
    return 1;
}
//COLPI INSERITI DA UTENTE
void colpito_utente (int n,char a[n][n],char b[n][n])
{
    int colpito=1;
    int cont=0;
    do
    {
        if(cont>=1)
        {
            stampa_mare(n,b);
            printf("\n\n");
        }
        int x,y;
        printf("inserisci coordinate colpo:\n");
        printf("x:");
        char ind;
        scanf(" %c", &ind);
        ind = toupper(ind);
        x = mod_ind(ind);
        printf("y:");
        scanf("%d",&y);
        while (x<0 || x>=n || y<0 || y>=n||a[y][x]==ind_colpito||a[y][x]==ind_acqua) //controllo coordinate e se già colpito
        {
            printf("ERRORE! coordinate fuori dal mare o colpito in precedenza,riprova:\n");
            printf("x:");
            char ind;
            scanf(" %c", &ind);
            ind = toupper(ind);
            x = mod_ind(ind);
            printf("y:");
            scanf("%d",&y);
        }
        if(a[y][x]==ind_nave)
        {
            a[y][x]=ind_colpito;
            b[y][x]=ind_colpito;
            cont++;
            
            if(controlla_affondata(n,a,x,y))//controllo affondamento nave
            {
                printf("colpita e affondata!\n");
                if(controllo_vittoria(n,a))
                {
                    printf("Hai vinto!\n");
                    exit(0);
                }
                Sleep(3000);
                clearScreen();
            }
            else
            {
                printf("colpita!\n");
                Sleep(2000);
                clearScreen();
            }
        }
        else
        {
            printf("acqua!\n");
            a[y][x]=ind_acqua;
            b[y][x]=ind_acqua;
            colpito=0;
        }

    }while(colpito==1);
}
//COLPI INSERITI DA CPU
void colpo_pc(int n, char mare_utente[n][n], int *colpo_mira, int *x_primo, int *y_primo, int *x_ultimo, int *y_ultimo, int *direzione) 
{
    int x, y;
    int colpo_valido = 0;

    if (*colpo_mira == 0) {
        static int quadrante_attuale = 0; 
        do 
        {
            int offset_x = (quadrante_attuale % 2 == 1) ? n/2 : 0;
            int offset_y = (quadrante_attuale >= 2) ? n/2 : 0;
            x = rand() % (n/2) + offset_x;
            y = rand() % (n/2) + offset_y;

            if (mare_utente[y][x] != ind_colpito && mare_utente[y][x] != ind_acqua) 
            {
                colpo_valido = 1;
            }
            quadrante_attuale = (quadrante_attuale + 1) % 4;
        } while (!colpo_valido);
    } 
    else {
        int dx[] = {0, 0, 1, -1}; 
        int dy[] = {-1, 1, 0, 0};

        x = *x_ultimo + dx[*direzione];
        y = *y_ultimo + dy[*direzione];

        if (x < 0 || x >= n || y < 0 || y >= n || mare_utente[y][x] == ind_colpito || mare_utente[y][x] == ind_acqua) 
        {
            *direzione = (*direzione + 1) % 4;
            *x_ultimo = *x_primo;
            *y_ultimo = *y_primo;
            
            // Richiama se stessa passando i puntatori
            colpo_pc(n, mare_utente, colpo_mira, x_primo, y_primo, x_ultimo, y_ultimo, direzione);
            return;
        }
    }

    printf("Il PC spara in %d, %d: ", x, y);

    if (mare_utente[y][x] == ind_nave) {
        printf("COLPITO!\n");
        mare_utente[y][x] = ind_colpito;
        
        if (controlla_affondata(n, mare_utente, x, y)) // Se la nave è affondata, resetta la mira e i puntatori
        { 
            printf("Il PC ha AFFONDATO una tua nave!\n");
            if(controllo_vittoria(n, mare_utente))
            {
                printf("Il PC ha vinto!\n");
                exit(0);
            }
            *colpo_mira = 0; 
        } 
        else 
        {
            if (*colpo_mira == 0) 
            {
                *colpo_mira = 1;
                *x_primo = x;
                *y_primo = y;
            }
            *x_ultimo = x;
            *y_ultimo = y;
        }
        // Colpito: il PC continua
        colpo_pc(n, mare_utente, colpo_mira, x_primo, y_primo, x_ultimo, y_ultimo, direzione);
    } 
    else {
        printf("ACQUA.\n"); // Colpo mancato, reset mira se era in corso
        mare_utente[y][x] = ind_acqua;
        if (*colpo_mira == 1) 
        {
            *direzione = (*direzione + 1) % 4;
            *x_ultimo = *x_primo;
            *y_ultimo = *y_primo;
        }
    }
}



#endif