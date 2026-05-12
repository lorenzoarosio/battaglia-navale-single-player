# ⚓ Battaglia Navale in C

![Battaglia Navale](immagine_capolavoro.png)

> Implementazione testuale del classico gioco **Battaglia Navale** in linguaggio C, con interfaccia a colori ANSI, posizionamento interattivo delle navi e intelligenza artificiale per il computer.

---

## 📋 Indice

- [Descrizione](#-descrizione)
- [Funzionalità](#-funzionalità)
- [Struttura del progetto](#-struttura-del-progetto)
- [Requisiti](#-requisiti)
- [Compilazione ed esecuzione](#-compilazione-ed-esecuzione)
- [Come si gioca](#-come-si-gioca)
- [Costanti configurabili](#-costanti-configurabili)
- [Intelligenza artificiale](#-intelligenza-artificiale)

---

## 📖 Descrizione

Il programma simula una partita di Battaglia Navale tra il giocatore e il computer su una griglia **10×10**. Il giocatore posiziona manualmente le proprie navi, mentre il computer le piazza in modo automatico distribuendole uniformemente sul campo. Il turno di gioco alterna colpi del giocatore e colpi del computer fino all'affondamento di tutte le navi di uno dei due.

---

## ✨ Funzionalità

- 🗺️ Griglia 10×10 con coordinate alfanumeriche (A–J, 0–9)
- 🚢 Due tipi di nave: **Fregata 1×3** e **Portaerei 2×2**
- 🎨 Interfaccia colorata con codici ANSI (blu, giallo, rosso, ciano)
- ✅ Validazione completa dell'input (bordi, sovrapposizioni, direzioni)
- 🤖 IA del computer con modalità **esplorazione** e **caccia**
- 💥 Rilevamento automatico delle navi affondate
- 🏆 Controllo della condizione di vittoria dopo ogni colpo

---

## 📁 Struttura del progetto

```
battaglia-navale/
│
├── battnav.c           # File principale, main() e ciclo di gioco
├── lib_battnav.h       # Logica di gioco (navi, colpi, IA)
└── lib.h               # Libreria generica di utilità
```

### Legenda della griglia

| Simbolo | Colore | Significato |
|---------|--------|-------------|
| `~` | 🔵 Blu | Acqua libera |
| `I` | 🟡 Giallo | Nave |
| `#` | 🔴 Rosso | Nave colpita |
| `X` | 🩵 Ciano | Colpo a vuoto |

---

## ⚙️ Requisiti

- Compilatore **GCC** (o compatibile C99+)
- Sistema operativo **Windows** (usa `windows.h` e `Sleep()`)
- Terminale con supporto ai **codici ANSI** (es. Windows Terminal, PowerShell)

---

## 🚀 Compilazione ed esecuzione

```bash
gcc battnav.c -o battnav -lm
./battnav
```

> Su Windows con MinGW:
> ```bash
> gcc battnav.c -o battnav.exe -lm
> battnav.exe
> ```

---

## 🎮 Come si gioca

1. **Avvio**: inserisci il numero di Fregate (1–5) e Portaerei (1–3) che vuoi usare
2. **Posizionamento navi**: per ogni nave indica:
   - Coordinata **X** (lettera A–J)
   - Coordinata **Y** (numero 0–9)
   - **Direzione** (N/S/E/O per le fregate, NE/NO/SE/SO per le portaerei)
3. **Turno giocatore**: inserisci le coordinate del colpo — se colpisci, puoi sparare ancora
4. **Turno computer**: il PC spara automaticamente con la sua strategia
5. **Fine partita**: vince chi affonda tutte le navi avversarie per primo

---

## 🔧 Costanti configurabili

Nel file `battnav.c` è possibile modificare i parametri di gioco:

```c
#define n          10   // Dimensione della griglia
#define r_nav       1   // Righe fregata
#define c_nav       3   // Colonne fregata (lunghezza)
#define n_nav       2   // Lato portaerei
#define max_nav_r   5   // Numero massimo di fregate
#define max_nav_q   3   // Numero massimo di portaerei
#define min_nav     1   // Numero minimo di navi per tipo
```

---

## 🤖 Intelligenza Artificiale

Il computer utilizza una strategia a due fasi:

- **Modalità esplorazione** — spara casualmente in quadranti alternati per massimizzare la copertura della griglia
- **Modalità caccia** — dopo un colpo a segno, tenta le celle adiacenti nelle quattro direzioni (N, S, E, O); se una direzione è bloccata, ruota alla successiva

Una volta affondata la nave, il computer torna automaticamente in modalità esplorazione.

---

## 👨‍💻 Autore

Progetto scolastico — Capolavoro di Informatica  
Anno scolastico 2024/2025
