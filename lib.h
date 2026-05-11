#ifndef LIB_AROSIO_H
#define LIB_AROSIO_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//PULISCI SCHERMO
void clearScreen() {
    #ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
//LETTURA DI CORDINATE
void leggi_cord (int *x,int *y)
{
	printf("scrivi la cordinata x del punto: ");
	scanf("%d", x);
	printf("scrivi la cordinata y del punto: ");
	scanf("%d", y);
}
//RIEMPIMENTO RANDOM DI UN ARRAY
void random_a (int a[],int max,int min, int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%(max-min+1)+min;
	}
}
//RIEMPIMENTO RANDOM DI UNA MATRICE
void random_a_bi (int r,int c, int a[r][c],int max,int min)
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			a[i][z]=rand()%(max-min+1)+min;
		}
	}
}
//RIEMPIMENTO ORDINATO DI UN ARRAY partendo da 0
void riempi_a (int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
}
//RIEMPIMENTO ORDINATO DI UN ARRAY partendo da x
void riempi_a_x (int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		a[i]=i+x;
	}
}
//RIEMPIMENTO DA UTENTE DI UN ARRAY
void leggi_a (int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("scrivi un numero da inserire nell'array: ");
		scanf("%d",&a[i]);
	}
}
//RIEMPIMENTO DA UTENTE DI UNA MATRICE
void leggi_a_bi (int r,int c,int a[r][c])
{
	printf("il riempimento della matrice verra eseguito riga per riga,\n");
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			printf("scrivi un numero da inserire nella matrice:");
			scanf("%d",&a[i][z]);
		}
	}
}
//riempimento matrice con tavola pitagorica
void pitagorica (int r, int c, int a[r][c])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			a[i][z]=(i+1)*(z+1);
		}
	}
}
//RIEMPIMENTO MATRICE IDENTITA'
void matrice_identita (int r,int c,int a[r][c])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(i==z)
			{
				a[i][z]=1;
			}
			else
			{
				a[i][z]=0;
			}
			
		}
	}
}
//RIEMPIMENTO MATRICE IDENTITA' AL CONTRARIO
void matrice_identita_contr (int r,int c,int a[r][c])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(i+z==r-1)
			{
				a[i][z]=1;
			}
			else
			{
				a[i][z]=0;
			}
			
		}
	}
}
//RIEMPIMENTO QUADRATO MAGICO DISPARI
void q_magico(int n,int a[n][n])
{
	int r=0,c=n/2;
	int prev_r,prev_c;
	for(int i=0;i<n*n;i++)
	{
		a[r][c]=i+1;
		prev_r=r;
		prev_c=c;
		r=(r-1+n)%n;
		c=(c-1+n)%n;
		if(a[r][c]!=0)
		{
			r=(prev_r+1)%n;
			c=prev_c;
		}
	}
}
//RIEMPIMENTO AUTOMATICO DI UNA MATRICE CHAR CON LETTERA
void riempi_a_bi_char (int r, int c, char a[r][c], char lettera)
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			a[i][z]=lettera;
		}
	}
}
//RIEMPIMENTO DA UTENTE DI UN ARRAY CON CONTROLLO
void leggi_a_cont (int a[],int n,int max,int min)
{
	for(int i=0;i<n;i++)
	{
		printf("scrivi un numero da inserire nell'array: ");
		scanf("%d",&a[i]);
		while (a[i]>max||a[i]<min)
		{
			printf("riprova:");
			scanf("%d",&a[i]);
		}
	}
}
//STAMPA DI UN ARRAY
void stampa_a (int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
//STAMPA DI UN ARRAY BIDIMENSIONALE riga per riga
void stampa_a_bi (int r,int c,int a[r][c])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			printf("%d	",a[i][z]);
		}
		printf("\n");
	}
}
//STAMPA CONSECUTIVA DI UN ARRAY
void stampa_cons_a (int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
//CONTROLLO SE UN NUMERO E' PRIMO (0) SE NO (1)
int n_primi (int n)
{
	if (n<=1)
	{
		return 0;
	}
	else
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				return 0;
			}
		}
		return 1;
	}
}
//EQUAZIONE DI SECONDO GRADO
void eq_2_grado(double a,double b,double c)
{
    double delta=pow(b,2)-4*a*c;
    if(delta<0)
    {
        printf("Soluzioni non reali.\n");
    }
    else
    {
        double x1=(-b+sqrt(delta))/(2*a);
        double x2=(-b-sqrt(delta))/(2*a);
        printf("Soluzioni:\nx1=%.2lf\nx2=%.2lf",x1,x2);
    }
}
//CONTROLLO SE UN NUMERO è PRESENTE NELLA MATRICE
int pres_mat (int r,int c,int a[r][c],int n)
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(n==a[i][z])
			{
				return 1;
			}
		}
	}
	return 0;
	
}
//CONTROLLO QUANTE VOLTE UN NUMERO COMPARE NELLA MATRICE
int conta_a_bi (int r,int c,int a[r][c],int n)
{
	int conta=0;
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(n==a[i][z])
			{
				conta++;
			}
		}
	}
	return conta;
}
//MASSIMO DI UN ARRAY NEGATIVO, se presenta numeri pos non si considerano se sono solo n. pos ritorna 0
int max_neg(int a[],int n)
{
	int max=a[0];
	int cont=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<0)
		{
			max=fmax(a[i],max);
			cont++;
		}
	}
	if(cont==0)
	{
		return 0;
	}
	else
	{
		return max;
	}
}
//MASSIMO DI UN ARRAY
int max_a (int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		max=fmax(max,a[i]);
	}
	return max;
}
//MINIMO DI UN ARRAY
int min_a (int a[],int n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		min=fmin(min,a[i]);
	}
	return min;
}
//MASSIMO DI UNA MATRICE, con stampa indice
void max_a_bi (int r,int c,int a[r][c])
{
	int max=a[0][0];
	int i1=0,i2=0;
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(max<a[i][z])
			{
				max=a[i][z];
				i1=i;
				i2=z;
			}
		}
	}
	printf("il numero massimo \212 nella riga %d, colonna %d ed \212 %d",i1,i2,max);
}
//CALCOLA MEDIA DI OGNI SINGOLA RIGA DI UNA MATRICE
void med_r_bi (int r,int c,int a[r][c],float med[r])
{
	int somma=0;
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			somma+=a[i][z];
		}
		med[i]=(float)somma/c;
		somma=0;
	}
}
//CALCOLA MEDIA DI ARRAY
float med_a (int a[],int n)
{
	int somma=0;
	for(int i=0;i<n;i++)
	{
		somma+=a[i];
	}
	return (float)somma/n;
}
//SOMMA TRA DUE MATRICI DI GRANDEZZA UGUALE
void somma_bi_ug(int r,int c,int a1[r][c],int a2[r][c],int a3[r][c])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			a3[i][z]=a1[i][z]+a2[i][z];
		}
	}
}
//SOMMA DI ELEMENTI NELLA CORNICE DI UNA MATRICE
int somma_bi_corn (int r,int c,int a[r][c])
{
	int somma=0;
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			if(i==0||i==(r-1)||z==0||z==(c-1))
			{
				somma+=a[i][z];
			}
		}
	}
	return somma;
}
//CONTA DI QUANTO COMPATTI UN ARRAY DATO NUMERO
int cmp_n (int a[],int n, int v)
{
	int cont=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==v)
		{
			for(int z=i;z<n;z++)
			{
				a[z]=a[z+1];
			}
			cont++;
			i--;
		}
	}
	return n-cont;
}
//CONTA LETTERE DISTINTE DI UNA PAROLA (compatta stringa)
void distinti(char s[], char dist[]) 
{
    int k = 0;
    int trov;
 
    for (int i = 0; s[i] != '\0'; i++) {
        
        trov = 0;
        for (int j = 0; j < k; j++) {
            if (s[i] == dist[j]) {
                trov = 1;
                break;
            }
        }
 
        if (!trov) {
            dist[k++] = s[i];
        }
    }
    dist[k] = '\0';
}
//CONTA LETTERE ESCLUSIVE DI UNA PAROLA 
void esclusivi(char S1[], char S2[], char esc1[], char esc2[],int *tot) 
{
    int k = 0;
    int trov;
	*tot=0;
 
    for (int i = 0; S1[i] != '\0'; i++) {
        trov = 0;
        for (int j = 0; S2[j] != '\0'; j++) {
            if (S1[i] == S2[j]) {
                trov = 1;
                break;
            }
        }
        if (!trov) {
            esc1[k++] = S1[i];
        }
    }
    esc2[k] = '\0';
	*tot=*tot+k;
    k = 0;
    for (int i = 0; S2[i] != '\0'; i++) {
        trov = 0;
        for (int j = 0; S1[j] != '\0'; j++) {
            if (S2[i] == S1[j]) {
                trov = 1;
                break;
            }
        }
        if (!trov) {
            esc2[k++] = S2[i];
        }
    }
    esc2[k] = '\0';
	*tot=*tot+k;
}
//CONTA LETTERE COMUNI DI UNA PAROLA
void comuni(char S1[], char S2[], char com[], int *tot) 
{
    int k = 0;
    *tot = 0;

    for (int i = 0; S1[i] != '\0'; i++) 
    {
        for (int j = 0; S2[j] != '\0'; j++) 
        {
            if (S1[i] == S2[j]) 
            {
                int trovato = 0;

                for (int z = 0; z < k; z++)
                {
                    if (com[z] == S1[i])
                    {
                        trovato = 1;
                    }
                }

                if (!trovato)
                {
                    com[k++] = S1[i];
                }
            }
        }
    }

    com[k] = '\0';
    *tot = k;
}
//MATRICE TRASPOSTA
void mtrasp (int r,int c,int a[r][c],int at[c][r])
{
	for(int i=0;i<r;i++)
	{
		for(int z=0;z<c;z++)
		{
			at[z][i]=a[i][z];
		}
	}
}
//ORDINAMENTO BUBBLESORT IN UN ARRAY
void bubble_sort (int a[],int n)
{
	int bubble;
	for(int i=0;i<n;i++)
	{
		for(int z=i+1;z<n;z++)
		{
			if(a[i]>a[z])
			{
				bubble=a[i];
				a[i]=a[z];
				a[z]=bubble;
			}
		}
	}
}
//SHIFT ARRAY A DESTRA
void shift_dx (int a[],int n)
{
	int ultimo=a[n-1];
	for(int i=n-1;i>0;i--)
	{
		a[i]=a[i-1];
	}
	a[0]=ultimo;
}
//shift array togliendo un numero
void shift_togli_n (int a[],int *n,int num)
{
	for(int i=0;i<*n;i++)
	{
		if(a[i]==num)
		{
			for(int z=i;z<*n-1;z++)
			{
				a[z]=a[z+1];
			}
			i--;
			(*n)--;
			
		}
	}

}
//CAMBIA SEGNO IN UN ARRAY DA - A + O VICEVERSA
void cambio_segno (int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=a[i]*-1;
	}
}
//DA DECIMALE A BINARIO passa: valore, bit massimi,array finale
void dec_bin (int v,int r[])
{
	for(int i=9;i>=0;i--)
	{
		r[i]=v%2;
		v=v/2;
	}
}
//DA DECIMALE A BINARIO con array bidimensionale,passa: valore, bit massimi,array finale
void dec_bin_BI (int v[],int r[][10])
{
	for(int i=0;i<=9;i++)
	{
		int n=v[i];
		for(int z=9;z>=0;z--)
		{
			r[i][z]=n%2;
			n=n/2;
		}
	}
}
//DISTANZA TRA DUE PUNTI
double dist_2p (int x1,int y1,int x2,int y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
//DISTANZA TRA DUE DATE CON ANNO COMMERCIALE
int distanza_2_date_commerciale (int g1,int m1,int a1,int g2,int m2,int a2)
{
	int giorni1=(a1-1)*360+(m1-1)*30+g1;
	int giorni2=(a2-1)*360+(m2-1)*30+g2;
	return abs(giorni1-giorni2);
}
//se bisestile
int bisestile (int a)
{
	return (a%4==0&&a%100!=0)||a%400==0;
}
//giorni dall'inizio dell'anno
int giorni_da_inizio_anno (int g1,int m1,int a1,int g2,int m2,int a2)
{
	int n_mesi[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(bisestile(a1))
	{
		n_mesi[1]=29;
	}
	int giorni=0;
	for(int i=0;i<m1-1;i++)
	{
		giorni+=n_mesi[i];
	}
	giorni+=g1;
	return giorni;

}
//DISTANZA TRA DUE DATE CON ANNO SOLARE
int distanza_2_date_sol (int g1,int m1,int a1,int g2,int m2,int a2)
{
	int giorni1=giorni_da_inizio_anno(g1,m1,a1,g2,m2,a2);
	int giorni2=giorni_da_inizio_anno(g2,m2,a2,g1,m1,a1);

	int anni1=a1*365+(a1/4)-(a1/100)+(a1/400);
	int anni2=a2*365+(a2/4)-(a2/100)+(a2/400);

	return abs((anni1+giorni1)-(anni2+giorni2));
}
//AREA RETTANGOLO
float area_r (float b,float h)
{
	return b*h;
}
//MCD
int mcd (int m,int n)
{
    int r;
    do
    {
        r=m%n;
        m=n;
        n=r;

    } while (r!=0);
    return m;
    
}
//MCM
int mcm (int m,int n)
{
    return (m*n)/mcd(m,n);
}
//SOMMA DI DUE FRAZIONI
void somma_2_frazioni (int n1,int d1,int n2,int d2,int *n3,int *d3)
{
	*d3=mcm(d1,d2);
	n1=*d3/d1*n1;
	n2=*d3/d2*n2;
	*n3=n1+n2;

}
//SEMPLIFICAZIONE DI UNA FRAZIONE
int semplifica_frazione (int *n,int *d)
{
	int mcd_f=mcd(*n,*d);
	if(mcd_f>1)
	{
		*n=*n/mcd_f;
		*d=*d/mcd_f;
		return 1;
	}
	else
	{
		return 0;
	}
}
#endif