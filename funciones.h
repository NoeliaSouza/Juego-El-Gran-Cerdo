#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;
struct ganador{
string nombre_ganador;
int puntaje_ganador;
};


///DECLARACIONES. DECLARAMOS LAS FUNCIONES

///MOSTRAR MENU
void mostrar_menu();

///PASAR PANTALLA
void pasar_pantalla();

///TIRAR 2 DADOS
void tirar_dados(int &num1, int &num2);

///CUAL DE LOS 2 JUGADORES EMPIEZA
void quien_empieza(string jugador1, string jugador2, string &jugador_actual, string &jugador_siguiente, int suma1, int suma2, bool &bandera_empieza,int dado11, int dado12, int dado21, int dado22);

///JUGADA CON 2 Y 3 DADOS
void jugar(string jugador_actual, string jugador_siguiente, int &acu_trufa_1, int &acu_trufa_2, int &i, int &lanzamientos1, int &lanzamientos2, int &max_lanzam_1, int &max_lanzam_2, bool &bandera_3dados1, bool &bandera_3dados2, bool &bandera_hunde, bool bandera_seguir, int &cont_oink_1, int &cont_oink_2, int &turno, char dados[5][37]);


///CALCULAR PUNTAJE
void calcular_puntaje(int indice, ganador finalistas[], int max_lanzam_1, int max_lanzam_2, string jugador_actual, string jugador_siguiente, int acu_trufa_1, int acu_trufa_2, int cont_oink_1, int cont_oink_2, int &PDV_MAX_1,int &PDV_MAX_2,int &PDV_50_1,int &PDV_50_2,int &PDV_OINK_1,int &PDV_OINK_2,int &PDV_CODICIOSO_1,int &PDV_CODICIOSO_2,int &TOTAL1,int &TOTAL2);

///MOSRTAR PUNTAJE DEL ULTIMO JUEGO
void mostrar_puntaje(int indice, ganador finalistas[], int max_lanzam_1, int max_lanzam_2,string jugador_actual, string jugador_siguiente, int acu_trufa_1, int acu_trufa_2, int cont_oink_1, int cont_oink_2,int &PDV_MAX_1,int &PDV_MAX_2,int &PDV_50_1,int &PDV_50_2,int &PDV_OINK_1,int &PDV_OINK_2,int &PDV_CODICIOSO_1,int &PDV_CODICIOSO_2,int &TOTAL1,int &TOTAL2);

///RELLENAR STRUCT
void rellenar_struct(ganador finalistas[]);

///ORDENAR ESTADISTICAS DE MAYOR A MENOR
void ordenar_estadisticas (ganador finalistas[]);

///MOSTRAR ESTADISTICAS
void mostrar_estadisticas (ganador finalistas[]);

///MOSTRAR 2 DADOS
void dadosmat(char mat[][37], int num1, int num2);

///MOSTRAR 3 DADOS
void dadosmat(char mat[][37], int num1, int num2,int num3);

///CAMBIAR A VIOLETA
void cambiar_violeta();

///CAMBIAR A VERDE
void cambiar_verde();

///CAMBIAR A BLANCO
void cambiar_blanco();

///LINEA
void linea();

///DADO UN INT, COMO MAXIMO MOSTRAR 2 DIGITOS, Y EN CASO DE QUE SEA MENOR A 10 RELLENARLO CON CEROS.
void ordenar2(int num);

///DADO UN INT, COMO MAXIMO MOSTRAR 3 DIGITOS, Y EN CASO DE QUE SEA MENOR A 100 RELLENARLO CON CEROS.
void ordenar3(int num);



#endif // FUNCIONES_H_INCLUDED
