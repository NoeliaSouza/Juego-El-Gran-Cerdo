#include <iostream>
#include <clocale> //Para que muestre los acentos  y la ñ
#include <string> //Para guardar texto
#include <string.h>//Contiene funcion para pasar a mayuscula.
#include <cstdlib> //Srand, rand
#include <ctime> //Time
#include "funciones.h" //Biblioteca propia
#include <windows.h>//Para cambiar de color el texto
#include "rlutil.h"
#define color SetConsoleTextAttribute//Para cambiar de color el texto

using namespace std;
int const historial=5;


int main(){
//setlocale(LC_ALL,"Spanish"); ////Para que muestre los acentos  y la ñ
srand(time(NULL)); //Para que muestre al azar
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);////Para cambiar de color el texto

ganador ganadores[historial];//struct de ganadores.
rellenar_struct(ganadores);

int indice=0;


char dados[5][37],opciones,continuar;
string jugador1, jugador2,jugador_actual,jugador_siguiente;
const int JUGADORES=2, RONDAS=5;
int bandera_salir_app=0;//PARA SALIR DEL JUEGO O APP
int acu_trufa_1=0, acu_trufa_2=0, trufa_ronda=0, cont_oink_1=0, cont_oink_2=0, max_lanzam_1=0, max_lanzam_2=0, cont_trufa1=0, cont_trufa2=0;
int lanzamientos1=0, lanzamientos2=0,trufa_lanzamiento;
int dado1,dado2,dado3,dado11,dado12,dado21,dado22,suma1,suma2,suma_dados;
bool bandera_empieza=0, bandera_seguir=0,bandera_hunde=0, bandera_eleccion=0, bandera_3dados1=0,bandera_3dados2=0;
int PDV_MAX_1,PDV_MAX_2,PDV_50_1,PDV_50_2,PDV_OINK_1,PDV_OINK_2,PDV_CODICIOSO_1,PDV_CODICIOSO_2,TOTAL1=0,TOTAL2=0,pdvganador;//DECLARO VARIABLES PARA MOSTRAR PDV
char palabra1[]= "OINK";
char palabra2[5];

mostrar_menu();
cin>>opciones;
cout<<endl;

//CREAMOS UN SWITCH PARA QUE SE REPITAN LAS OPCIONES HASTA QUE EL USUARIO INGRESE UN CERO (SALIR)
while (bandera_salir_app!=1){//CIERRO EL  WHILE
switch (opciones){
    case'1':{
        cin.ignore ();
        cout<<"Ingrese el nombre del jugador N"<<char(167)<<"1: "<<endl;
        getline (cin,jugador1);
        cout<<endl;
        cout<<"Ingrese el nombre del jugador N"<<char(167)<<"2: "<<endl;
        getline (cin,jugador2);
        cout<<endl;
        pasar_pantalla();


        acu_trufa_1=0;//REINICIAMOS VARIABLES PARA VOLVER A JUGAR Y QUE EL PUNTAJE EMPIECE CON CERO.
        acu_trufa_2=0;
        cont_oink_1=0;
        cont_oink_2=0;
        max_lanzam_1=0;
        max_lanzam_2=0;
        lanzamientos1=0;
        lanzamientos2=0;
        bandera_empieza=0;
        bandera_3dados1=0;
        bandera_3dados2=0;
        bandera_hunde=0;



        //PRIMER TIRADA DE DADOS. QUIEN EMPIEZA?
        cambiar_violeta();
        cout<<"A JUGAR!!!"<<endl<<endl;
        cambiar_blanco();
        while (bandera_empieza==0){
        cout<<jugador1<<" presion"<<char(160)<<" una tecla para lanzar los dados... "<<endl;
        rlutil::anykey();cout<<endl;
        tirar_dados(dado11, dado12);
        suma1=dado11+dado12;
        cout<<jugador1<<" sac"<<char(162)<<" "<<suma1<<endl<<endl;
        dadosmat(dados,dado11,dado12);
        cout<<endl<<jugador2<<" presion"<<char(160)<<" una tecla para lanzar los dados... "<<endl;

        rlutil::anykey();cout<<endl;
        tirar_dados(dado21,dado22);
        suma2=dado21+dado22;
        cout<<jugador2<<" sac"<<char(162)<<" "<<suma2<<endl<<endl;
        dadosmat(dados,dado21,dado22);
        quien_empieza(jugador1, jugador2, jugador_actual, jugador_siguiente, suma1, suma2, bandera_empieza, dado11, dado12, dado21, dado22);
        }

        //COMIENZAN LAS RONDAS
        for (int i=0;i<RONDAS;i++){
        lanzamientos1=0;
        lanzamientos2=0;
        bandera_seguir=0;
        int turno=0;//PARA DISTINGUIR A QUE JUGADOR LE TOCA. TURNO 0►JUGADOR ACTUAL. TURNO 1►SIGUIENTE JUGADOR. HAY QUE VOLVERLA 0 UNA VEZ TERMINE LAS 2 VUELTAS DE JUGADORES PARA LA SIGUIENTE RONDA.
            for (int j=0;j<JUGADORES;j++){
            bandera_seguir=0;//reiniciar en cada vuelta de cada jugador la bandera para que el for de las 2 vueltas.
            trufa_ronda=0;//reinicia las trufas de ronda de cada uno.
            jugar(jugador_actual, jugador_siguiente, acu_trufa_1, acu_trufa_2, i, lanzamientos1, lanzamientos2, max_lanzam_1, max_lanzam_2, bandera_3dados1, bandera_3dados2, bandera_hunde, bandera_seguir, cont_oink_1, cont_oink_2, turno, dados);
            }
        }
        system("cls");//Pasa de pantalla
        cambiar_violeta();
        cout<<endl<<"EL JUEGO HA TERMINADO"<<endl;
        TOTAL1=0;
        TOTAL2=0;
        cambiar_blanco();
        calcular_puntaje(indice, ganadores, max_lanzam_1,  max_lanzam_2, jugador_actual, jugador_siguiente, acu_trufa_1, acu_trufa_2, cont_oink_1, cont_oink_2, PDV_MAX_1,PDV_MAX_2,PDV_50_1,PDV_50_2,PDV_OINK_1,PDV_OINK_2,PDV_CODICIOSO_1,PDV_CODICIOSO_2,TOTAL1,TOTAL2);
        mostrar_puntaje(indice, ganadores, max_lanzam_1,  max_lanzam_2, jugador_actual, jugador_siguiente, acu_trufa_1, acu_trufa_2, cont_oink_1, cont_oink_2,PDV_MAX_1,PDV_MAX_2,PDV_50_1,PDV_50_2,PDV_OINK_1,PDV_OINK_2,PDV_CODICIOSO_1,PDV_CODICIOSO_2,TOTAL1,TOTAL2);

        pasar_pantalla();
        mostrar_menu();
        cin>>opciones;
        indice++;//cambia el indice del struct a +1.
        }///CIERRA CASE 1
        break;

    case'2':{
        TOTAL1=0;
        TOTAL2=0;

        /*jugador_actual="POPO";
        jugador_siguiente="TRASERO";
        acu_trufa_1=20;//PARA PROBAR HITOS
        acu_trufa_2=500;
        cont_oink_1=3;
        cont_oink_2=4;
        max_lanzam_1=8;
        max_lanzam_2=10;
        lanzamientos1=8;
        lanzamientos2=10;*/
        if(acu_trufa_1==0 && acu_trufa_2==0){
        cout<<"Aun no se cargaron estadisticas en el juego."<<endl<<endl;
        }
        else{
        ordenar_estadisticas(ganadores);
        mostrar_estadisticas(ganadores);


        cout<<"INGRESE OINK PARA CONTINUAR: "<<endl<<endl;
        cin>>palabra2;
        int bandera_oink=0;
        //strupr(palabra2); // PASAR A MAYUSCULA
        while(bandera_oink==0){
        if(strcmp(palabra1, (strupr(palabra2)))==0){//FUNCION PARA COMAPRAR CADENAS
        bandera_oink=1;
        }
        else{
        cout<<endl<<"INGRESE OINK PARA CONTINUAR: "<<endl<<endl;
        cin>>palabra2;
        }
        }
        }
        system("pause");
        system("cls");//Pasa de pantalla
        mostrar_menu();
        cin>>opciones;
        }
        break;///CIERRA CASE 2


    case'3':{
        cout<<endl<<"** GRUPO LOS TRES CHANCHITOS **"<<endl<<endl;
        cambiar_violeta();
        cout<<" (> --- <)  (> --- <)  (> --- <)"<<endl;
        cout<<" (  'o'  )  (  'o'  )  (  'o'  )"<<endl;
        cout<<"-(,,)-(,,)--(,,)-(,,)--(,,)-(,,)-"<<endl<<endl;
        cambiar_blanco();
        cout<<"27082, Afonso de Souza Noelia"<<endl<<"26992, Questa Pablo"<<endl<<"25832, Callejo Facundo"<<endl<<endl;
        system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
        system("cls");//Pasa de pantalla
        mostrar_menu();
        cin>>opciones;
        }
        break;///CIERRA CASE 3



    case '4':{
        system ("cls");
        cambiar_verde();
        cout<<"                                    (> ---- <)  "<<endl;
        cout<<"                                    ( "<<char(167)<<"(oo)"<<char(167)<<" )"<<endl;
        cout<<endl;
        cambiar_violeta();
        cout<<"                         *** COMO JUGAR AL GRAN CERDO *** "<<endl<<endl;
        cambiar_blanco();


            ///cout<<endl;
           /// cambiar_verde();
            ///cout<<"EL GRAN CERDO"<<endl;
           /// cambiar_blanco();
            cout<<"+---------------------------------------------------------------------------------------+"<<endl;
            cout<<"| JUAN"<<": "<<0<<" trufas acumuladas"<<"                           "<<"JOSE"<<": "<<0<<" trufas acumuladas         |"<<endl;
            cout<<"+---------------------------------------------------------------------------------------+"<<endl;
            cout<<"| TURNO DE JUAN                                                                         |"<<endl;
            cout<<"| +------------------------------+                                                      |"<<endl;
            cout<<"| |RONDA #"<<1<<"                      |";cambiar_verde();cout<<" --> El juego esta compuesto por 5 rondas por jugador.";cambiar_blanco();cout<<"|"<<endl;
            cout<<"| |TRUFAS DE LA RONDA: ";
            if(trufa_ronda<10){
            cout.fill  ('0');//PARA MOSTRAR SOLO 2 DIGITOS-AGREGA CEROS
            cout.width ( 2 );//PARA MOSTRAR SOLO 2 DIGITOS-COMO MAXIMO MUESTRA 2 DIGITOS
            }
            cout<<trufa_ronda<<"        |";cambiar_verde();cout<<" --> Las trufas se transforman en puntos de victoria.";cambiar_blanco();cout<<" |"<<endl;
            cout<<"| |LANZAMIENTOS: "<<lanzamientos1<<"               |";cambiar_verde();cout<<" --> Cantidad de lanzamientos de la ronda actual.";cambiar_blanco();cout<<"     | "<<endl;
            cout<<"| +------------------------------+                                                      |"<<endl;

            lanzamientos1++;
            cout<<"| LANZAMIENTO: "<<lanzamientos1<<"                                                                        |"<<endl;
            cout<<"+---------------------------------------------------------------------------------------+"<<endl<<endl;



            cambiar_violeta();
            cout<<"CANTIDAD DE DADOS"<<endl<<endl;
            cambiar_blanco();
            cout<<"Se utilizan 2 DADOS por lanzamiento"<<endl;
            cout<<"Se utilizan 3 DADOS una vez que: "<<endl<<endl;
            cout<<"       "<<char (192);cout<<"> Ambos cerdos superen las 50 trufas."<<endl;
            cout<<"       "<<char (192);cout<<"> Alguno de ellos se 'HUNDA EN EL BARRO'."<<endl<<endl;


            cambiar_violeta();
            cout<<"COMO ACUMULAR TRUFAS "<<endl<<endl;
            cambiar_blanco();

           cambiar_violeta();
           cout<<char (4);
           cambiar_blanco();
           cout<<" CARAS DISTINTAS Y NO SON 'ASES' -->  Se acumulan trufas igual a la suma de las caras."<<endl;

           cambiar_verde();
           cout<<char (4);
           cambiar_blanco();
           cout<<" CARAS IGUALES Y NO SON 'ASES'   -->  'OINK'  acumula trufas por el doble de la suma de las caras."<<endl;

           cambiar_violeta();
           cout<<char (4);
           cambiar_blanco();
           cout<<" CARAS DISTINTAS Y HAY UN 'AS'   -->  Pierde todas las trufas de la ronda actual"<<endl;


           cambiar_verde();
           cout<<char (4);
           cambiar_blanco();
           cout<<" CARAS IGUALES Y SON 'ASES'      -->  El cerdo 'SE HUNDE EN EL BARRO' y pierde todas las trufas(*)"<<endl<<endl;
           cout<<"  (*) NOTA: (Si se juegan con 3 dados, los puntos pasan al otro cerdo)"<<endl<<endl;



           ///cout<<"Puntos de victoria e hitos"<<endl;
           cambiar_violeta();
           cout<<"QUIEN ACUMULE MAS PUNTOS DE VICTORIA GANA EL JUEGO"<<endl;
           cambiar_blanco();

           cout<<"+-------------------------------------------------------------+"<<endl;
           cout<<"|Hito                               Puntos de Victoria        |"<<endl;
           cout<<"+-------------------------------------------------------------+"<<endl;
           cout<<"|Mas trufas en total              | 5 PDV                     |"<<endl;
           cout<<"|Cada 50 trufas                   | 1 PDV                     |"<<endl;
           cout<<"|OINK                             | 2 PDV * cantidad de OINKS |"<<endl;
           cout<<"|Cerdo codicioso (**)             | 3 PDV                     |"<<endl;
           cout<<"+-------------------------------------------------------------+"<<endl<<endl;


           cout<<"(**) Cerdo codicioso : ronda con mayor cantidad de lanzamientos"<<endl<<endl;

        system ("pause");
        system ("cls");
        mostrar_menu();
        cin>>opciones;
    }
    break;

    case'0':{
        cout<<endl<<char(168)<<"Est"<<char(160)<<" seguro que desea salir?"<<endl;
        cout<<"Digite S para confirmar y N para volver al men"<<char(163)<<"."<<endl;
        cin>>opciones;
        cout<<endl;
        while(bandera_salir_app==0){
        opciones=toupper(opciones);
        switch(opciones){
        case'S':
        bandera_salir_app=1;///////////////////////////////
        break;
        case'N':
        system("cls");//Pasa de pantalla
        mostrar_menu();
        cin>>opciones;
        break;
        default:{
        bandera_salir_app=0;
        cout<<endl<<"Opci"<<char(162)<<"n incorrecta"<<endl<<"Digite S para salir del juego y N para volver al men"<<char(163)<<"."<<endl;
        cin>>opciones;
        break;
        }
            }
        }
        }
        break;///CIERRA CASE 0

    default:{
        cout<<endl<<"Opci"<<char(162)<<"n incorrecta, ingrese una opci"<<char(162)<<"n v"<<char(160)<<"lida (1,2,3,4,0)."<<endl;
        mostrar_menu();
        cin>>opciones;
        }
        break;///CIERRA CASE DEFAULT
        }//CIERRA SWTICH
        }//CIERRA WHILE PRINCIPAL

    return 0;
}

