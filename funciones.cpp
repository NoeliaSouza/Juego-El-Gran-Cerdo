#include <iostream>
#include <clocale> //Para que muestre los acentos  y la ñ
#include <string> //Para guardar texto
#include <string.h>//Contiene funcion para pasar a mayuscula.
#include <cstdlib> //Srand, rand
#include <ctime> //Time
#include "funciones.h" //Biblioteca propia
#include <windows.h>//Para cambiar de color el texto
#define color SetConsoleTextAttribute//Para cambiar de color el texto
using namespace std;
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);////Para cambiar de color el texto



///DEFINICIONES. QUE HACE CADA FUNCION
///MOSTRAR MENU
void mostrar_menu(){
cout<<endl;
cambiar_violeta();
cout<<"    (> ---- <)  "<<endl;
cout<<"    ( "<<char(167)<<"(oo)"<<char(167)<<" )"<<endl;
cout<<endl;


cambiar_verde();
cout<<"  EL GRAN CERDO"<<endl;
cambiar_blanco();
cout<<"------------------"<<endl;
cout<<" 1-JUGAR"<<endl;
cout<<" 2-ESTADISTICAS"<<endl;
cout<<" 3-CERDITOS"<<endl;
cout<<" 4-INSTRUCCIONES"<<endl;
cout<<"------------------"<<endl;
cout<<" 0-SALIR"<<endl;
cout<<endl<<"Ingrese una opci"<<char(162)<<"n"<<endl;

}

///PASAR PANTALLA
void pasar_pantalla(){
system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
system("cls");//Pasa de pantalla
}


///TIRAR 2 DADOS
void tirar_dados(int &num1, int &num2){
 num1=(rand()%6)+1;
 num2=(rand()%6)+1;
}

///TIRAR 3 DADOS
void tirar_datres(int &num1, int &num2, int &num3){
 num1=(rand()%6)+1;
 num2=(rand()%6)+1;
 num3=(rand()%6)+1;
}

//CUAL DE LOS 2 JUGADORES EMPIEZA
void quien_empieza(string jugador1, string jugador2,string &jugador_actual, string &jugador_siguiente, int suma1, int suma2, bool &bandera_empieza, int dado11, int dado12, int dado21, int dado22){
if (suma1>suma2){
    cambiar_verde();
    cout<<endl<<"Comienza tirando los dados "<<jugador1<<endl<<endl;
    cambiar_blanco();
    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
    system("cls");//Pasa de pantalla
    jugador_actual=jugador1;
    jugador_siguiente=jugador2;
    bandera_empieza=1;
    return;
}
else{
    if(suma2>suma1){
    cambiar_verde();
    cout<<endl<<"Comienza tirando los dados "<<jugador2<<endl<<endl;
    cambiar_blanco();
    pasar_pantalla();
    jugador_actual=jugador2;
    jugador_siguiente=jugador1;
    bandera_empieza=1;
    }
    else{
        if(suma1==suma2){
            if((dado11>dado21 && dado11>dado22) || (dado12>dado21 && dado12>dado22)){
                cambiar_verde();
                cout<<endl<<"Comienza tirando los dados "<<jugador1<<endl<<endl;
                cambiar_blanco();
                pasar_pantalla();
                jugador_actual=jugador1;
                jugador_siguiente=jugador2;
                bandera_empieza=1;
            }
            else{
                if((dado21>dado11 && dado21>dado12) || (dado22>dado11 && dado22>dado12)){
                cambiar_verde();
                cout<<endl<<"Comienza tirando los dados "<<jugador2<<endl<<endl;
                cambiar_blanco();
                pasar_pantalla();
                jugador_actual=jugador2;
                jugador_siguiente=jugador1;
                bandera_empieza=1;
                }

                else{
                    if(((dado11==dado21 || dado11==dado22) && (dado12==dado21 || dado12==dado22)) || ((dado21==dado11 ||dado21==dado12)&&(dado22==dado11 || dado22==dado12))){
                        cambiar_verde();
                        cout<<endl<<"Empate. Se lanzan los dados una vez mas."<<endl<<endl;
                        cambiar_blanco();
                        pasar_pantalla();
                        bandera_empieza=0;

                    }
                }

            }

        }
    }
}
return;
}

///CAMBIAR A VIOLETA
void cambiar_violeta(){
color (hConsole,5);////Para cambiar de color el texto
}

///CAMBIAR A VERDE
void cambiar_verde(){
color (hConsole,3);////Para cambiar de color el texto
}

///CAMBIAR A BLANCO
void cambiar_blanco(){
color (hConsole,7);////Para cambiar de color el texto
}

///LINEA
void linea(){
cout<<"-----------------------------------------------------------------------------"<<endl;
}

///JUAGADA CON 2 Y 3 DADOS
void jugar (string jugador_actual, string jugador_siguiente, int &acu_trufa_1, int &acu_trufa_2, int &i, int &lanzamientos1, int &lanzamientos2, int &max_lanzam_1, int &max_lanzam_2, bool &bandera_3dados1, bool &bandera_3dados2, bool &bandera_hunde, bool bandera_seguir, int &cont_oink_1, int &cont_oink_2, int &turno, char dados[5][37]){
int trufa_ronda=0;
const int DADOS=2, DATRES=3;
int suma_dados, trufa_lanzamiento, vec_dados[DADOS],vec_datres[DATRES];
bool bandera_eleccion=0;
char continuar;
if (turno==0){
//PRIMER JUGADOR
while (bandera_seguir==0){
            cout<<endl;
            cambiar_verde();
            cout<<"EL GRAN CERDO"<<endl;
            cambiar_blanco();
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<jugador_actual<<": "<<acu_trufa_1<<" trufas acumuladas"<<"              "<<jugador_siguiente<<": "<<acu_trufa_2<<" trufas acumuladas"<<endl<<endl;
            cout<<"TURNO DE "<<jugador_actual<<endl;
            cout<<"+------------------------------+"<<endl;
            cout<<"|RONDA #"<<i+1<<"                      |"<<endl;
            cout<<"|TRUFAS DE LA RONDA: ";
            if(trufa_ronda<10){
            cout.fill  ('0');//PARA MOSTRAR SOLO 2 DIGITOS-AGREGA CEROS
            cout.width ( 2 );//PARA MOSTRAR SOLO 2 DIGITOS-COMO MAXIMO MUESTRA 2 DIGITOS
            }
            cout<<trufa_ronda<<"        |"<<endl;
            cout<<"|LANZAMIENTOS: "<<lanzamientos1<<"               |"<<endl;
            cout<<"+------------------------------+"<<endl;

            lanzamientos1++;
            cout<<"LANZAMIENTO: "<<lanzamientos1<<endl;

            if(lanzamientos1>max_lanzam_1){
                max_lanzam_1=lanzamientos1;
            }

            if ((bandera_3dados1==0 && bandera_3dados2==1 && bandera_hunde==0) || (bandera_3dados1==1 && bandera_3dados2==0 && bandera_hunde==0) || (bandera_3dados1==0 && bandera_3dados2==0 && bandera_hunde==0)){
            //====================1ER JUGADOR. SE TIRAN 2 DADOS =========================

                tirar_dados(vec_dados[0], vec_dados[1]);
                dadosmat(dados,vec_dados[0],vec_dados[1]);//MOSTRAR DADOS

            //1ERA CONDICION CARAS DISTINTAS Y NO SON 1►SE SUMAN LOS DADOS. DEBE ELEGIR SI CONTINUAR O NO
                if (vec_dados[0]!=vec_dados[1]&&vec_dados[0]!=1 &&vec_dados[1]!=1){
                    suma_dados=vec_dados[0]+vec_dados[1];
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_1+=suma_dados;
                    if(acu_trufa_1>=50){
                    bandera_3dados1=1;//PARA LA BANDERA DE 3 DADOS
                    }
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Pod"<<char(130)<<"s tirar los dados una vez m"<<char(160)<<"s."<<endl;
                    cout<<char(168)<<"Continuar? (S/N)"<<endl;
                    while (bandera_eleccion==0){
                    cin>>continuar;
                    continuar=toupper(continuar);
                    switch (continuar){
                    case 'S':
                    bandera_eleccion=1;
                    break;
                    case 'N':
                    bandera_seguir=1;
                    bandera_eleccion=1;
                    turno=1;
                    break;
                    default:
                    cout<<"Por favor digite una opci"<<char(162)<<"n v"<<char(160)<<"lida."<<endl;
                    cout<<char(168)<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s? (S/N)."<<endl;
                    bandera_eleccion=0;
                    break;
                    }
                    }
                    bandera_eleccion=0;//SE VUELVE A PONER EN CERO PARA LA SIGUIENTE VUELTA.
                    }

            //2DA CONDICION CARAS IGUALES Y NO HAY ASES►OINK►SE DOBLA LA SUMA DE LOS DADOS. DEBE LANZAR UNA VEZ MAS.
                if(vec_dados[0]==vec_dados[1]&&vec_dados[0]!=1 &&vec_dados[1]!=1){
                    cout<<char(173)<<"LOGRASTE UN OINK!"<<endl;
                    cont_oink_1++;
                    suma_dados=((vec_dados[0]+vec_dados[1])*2);
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_1+=suma_dados;
                    if(acu_trufa_1>=50){
                    bandera_3dados1=1;
                    }
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s."<<endl;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    }

            //3ERA CONDICION CARAS DISTINTAS Y HAY UN AS.►PIERDE TODAS LAS TRUFAS DE LA RONDA ACTUAL. CEDE EL TURNO
                if(vec_dados[0]!=vec_dados[1]&&(vec_dados[0]==1||vec_dados[1]==1)){
                    cout<<jugador_actual<<" pierde "<<trufa_ronda<<" trufas de la ronda actual y cede el turno a "<<jugador_siguiente<<"."<<endl;
                    acu_trufa_1-=trufa_ronda;
                    trufa_ronda=0;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador.
                    turno=1;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


            //4TA CONDICION 2 CARAS IGUALES Y SON ASES ►SE HUNDE EN EL BARRO Y PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES. CEDE EL TURNO
                if (vec_dados[0]==vec_dados[1] && vec_dados[0]==1){
                    cout<<jugador_actual<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_1<<" trufas de rondas anteriores, incluida la actual."<<endl<<"Cede el turno a "<<jugador_siguiente<<endl;
                    acu_trufa_1=0;
                    bandera_hunde=1;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=1;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


        }
        else{
            //============================1ER JUGADOR. SE TIRAN 3 DADOS=======================================================

            tirar_datres(vec_datres[0], vec_datres[1], vec_datres[2]);
            dadosmat(dados,vec_datres[0],vec_datres[1],vec_datres[2]);//MOSTRAR DADOS


            //1ERA CONDICION 3 CARAS DISTINTAS Y NO SON 1// 2 CARAS DISTINTAS Y NINGUNA DE LAS 3 SON 1►SE SUMAN LOS DADOS. DEBE ELEGIR SI CONTINUAR O NO
                if (((vec_datres[0]!=vec_datres[1] && vec_datres[1]!=vec_datres[2] &&vec_datres[0]!=vec_datres[2]) &&(vec_datres[0]!=1 &&vec_datres[1]!=1 &&vec_datres[2]!=1)) ||  ((vec_datres[0]!=vec_datres[1] || vec_datres[1]!=vec_datres[2] ||vec_datres[0]!=vec_datres[2]) &&(vec_datres[0]!=1 &&vec_datres[1]!=1 &&vec_datres[2]!=1))) {
                    suma_dados=vec_datres[0]+vec_datres[1]+vec_datres[2];
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_1+=trufa_ronda;
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Pod"<<char(130)<<"s tirar los dados una vez m"<<char(160)<<"s."<<endl;
                    cout<<char(168)<<"Continuar? (S/N)"<<endl;
                    while (bandera_eleccion==0){
                    cin>>continuar;
                    continuar=toupper(continuar);
                    switch (continuar){
                    case 'S':
                    bandera_eleccion=1;
                    break;
                    case'N':
                    bandera_seguir=1;
                    bandera_eleccion=1;
                    turno=1;//Para que pase a otro jugador.
                    break;
                    default:
                    cout<<"Por favor digite una opci"<<char(162)<<"n v"<<char(160)<<"lida."<<endl;
                    cout<<char(168)<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s? (S/N)."<<endl;
                    break;
                    }
                    }
                    //bandera_eleccion=0;//SE VUELVE A PONER EN CERO PARA LA SIGUIENTE VUELTA.
                    }



        //2DA CONDICION 3 CARAS IGUALES Y NO HAY ASES ►OINK►SE DOBLA LA SUMA DE LOS DADOS. DEBE LANZAR UNA VEZ MAS.
                if(vec_datres[0]==vec_datres[1] &&vec_datres[1]==vec_datres[2] &&vec_datres[0]!=1)  {//CON QUE UN SOLO DADO NO SEA UNO YA SE CUMPLE. YA QUE TODOS SON IGUALES.
                    cout<<char(173)<<"LOGRASTE UN OINK!"<<endl;
                    cont_oink_1++;
                    suma_dados=((vec_datres[0]+vec_datres[1]+vec_datres[2])*2);
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_1+=suma_dados;
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s."<<endl;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    //LANZA LOS DADOS UNA VEZ MAS..SE DEBE REPETIR TODO. COPIAR TODO A PARTIR DE LA 1ERA CONDICION EN ADELANTE...
                    }

        //3ERA CONDICION 3 CARAS DISTINTAS Y HAY UN AS// 2 CARAS DISTINTAS Y HAY UN AS ►PIERDE TODAS LAS TRUFAS DE LA RONDA ACTUAL. CEDE EL TURNO
                    if((vec_datres[0]!=vec_datres[1] &&vec_datres[1]!=vec_datres[2] &&vec_datres[0]!=vec_datres[2] &&(vec_datres[0]==1 ||vec_datres[1]==1 ||vec_datres[2]==1)) || (vec_datres[0]!=1 && vec_datres[1]!=1 && vec_datres[2]==1)||(vec_datres[1]!=1 && vec_datres[2]!=1 && vec_datres[0]==1)||(vec_datres[2]!=1 && vec_datres[0]!=1 && vec_datres[1]==1)){
                    cout<<jugador_actual<<" pierde "<<trufa_ronda<<" trufas de la ronda actual y cede el turno a "<<jugador_siguiente<<endl;
                    acu_trufa_1-=trufa_ronda;
                    trufa_ronda=0;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador.
                    turno++;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


        //4TA CONDICION 2 CARAS IGUALES Y SON ASES ►SE HUNDE EN EL BARRO Y PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES. CEDE EL TURNO
                if ((vec_datres[0]==vec_datres[1]&&vec_datres[0]==1)  || (vec_datres[1]==vec_datres[2]&&vec_datres[1]==1)   || (vec_datres[0]==vec_datres[2]&&vec_datres[0]==1)){
                    cout<<jugador_actual<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_1<<" trufas de rondas anteriores, incluida la actual."<<endl<<"Cede el turno a "<<jugador_siguiente<<endl;
                    acu_trufa_1=0;
                    bandera_hunde=1;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=1;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }



        //5TA CONDICION 3 CARAS IGUALES Y SON ASES►SE HUNDE EN EL BARRO, PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES,SE LAS SUMA AL ENEMIGO Y CEDE EL TURNO.
                if (vec_datres[0]==vec_datres[1] &&vec_datres[1]==vec_datres[2] &&vec_datres[0]==1){//CON QUE UN SOLO DADO SEA UNO YA SE CUMPLE. YA QUE TODOS SON IGUALES.
                    cout<<jugador_actual<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_1<<" trufas de rondas anteriores, incluida la actual, y se las cede a " <<jugador_siguiente<<endl<<"Cede el turno."<<endl;
                    acu_trufa_2+=acu_trufa_1;//PARA SUMAR EL PUNTAJE A LAS TRUFAS DEL ENEMIGO.
                    acu_trufa_1=0;//PONE LAS TRUFAS DEL  J1 EN CERO.
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=1;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }
        }

    }
}
else{


 //SEGUNDO JUGADOR
bandera_seguir=0;
bandera_eleccion=0;
trufa_ronda=0;//reiniciamos las trufas de la ronda del anterior jugador.
while (bandera_seguir==0){

            cout<<endl;
            cambiar_verde();
            cout<<"EL GRAN CERDO"<<endl;
            cambiar_blanco();
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<jugador_actual<<": "<<acu_trufa_1<<" trufas acumuladas"<<"              "<<jugador_siguiente<<": "<<acu_trufa_2<<" trufas acumuladas"<<endl<<endl;
            cout<<"TURNO DE "<<jugador_siguiente<<endl;
            cout<<"+------------------------------+"<<endl;
            cout<<"|RONDA #"<<i+1<<"                      |"<<endl;
            cout<<"|TRUFAS DE LA RONDA: ";
            if(trufa_ronda<10){
            cout.fill  ('0');//PARA MOSTRAR SOLO 2 DIGITOS-AGREGA CEROS
            cout.width ( 2 );//PARA MOSTRAR SOLO 2 DIGITOS-COMO MAXIMO MUESTRA 2 DIGITOS
            }
            cout<<trufa_ronda<<"        |"<<endl;
            cout<<"|LANZAMIENTOS: "<<lanzamientos2<<"               |"<<endl;
            cout<<"+------------------------------+"<<endl;
            lanzamientos2++;
            cout<<"LANZAMIENTO: "<<lanzamientos2<<endl;
            if(lanzamientos2>max_lanzam_2){
                max_lanzam_2=lanzamientos2;
            }

            if ((bandera_3dados1==0 && bandera_3dados2==1 && bandera_hunde==0) || (bandera_3dados1==1 && bandera_3dados2==0 && bandera_hunde==0) || (bandera_3dados1==0 && bandera_3dados2==0 && bandera_hunde==0)) {
            //========================2DO JUGADOR. SE TIRAN 2 DADOS=========================
                tirar_dados(vec_dados[0], vec_dados[1]);
                dadosmat(dados,vec_dados[0],vec_dados[1]);


            //1ERA CONDICION CARAS DISTINTAS Y NO SON 1►SE SUMAN LOS DADOS. DEBE ELEGIR SI CONTINUAR O NO
                if (vec_dados[0]!=vec_dados[1]&&vec_dados[0]!=1 &&vec_dados[1]!=1){
                    suma_dados=vec_dados[0]+vec_dados[1];
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_2+=suma_dados;
                    if(acu_trufa_2>=50){
                    bandera_3dados2=1;
                    }
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Pod"<<char(130)<<"s tirar los dados una vez m"<<char(160)<<"s."<<endl;
                    cout<<char(168)<<"Continuar? (S/N)"<<endl;
                    while (bandera_eleccion==0){
                    cin>>continuar;
                    continuar=toupper(continuar);
                    switch (continuar){
                    case 'S':
                    bandera_eleccion=1;
                    break;
                    case 'N':
                    bandera_seguir=1;
                    bandera_eleccion=1;
                    turno=0;
                    break;
                    default:
                    cout<<"Por favor digite una opci"<<char(162)<<"n v"<<char(160)<<"lida."<<endl;
                    cout<<char(168)<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s? (S/N)."<<endl;
                    break;
                    }
                    }
                    bandera_eleccion=0;//SE VUELVE A PONER EN CERO PARA LA SIGUIENTE VUELTA.
                    }

            //2DA CONDICION CARAS IGUALES Y NO HAY ASES►OINK►SE DOBLA LA SUMA DE LOS DADOS. DEBE LANZAR UNA VEZ MAS.
                if(vec_dados[0]==vec_dados[1]&&vec_dados[0]!=1 &&vec_dados[1]!=1){
                    cout<<char(173)<<"LOGRASTE UN OINK!"<<endl;
                    cont_oink_2++;
                    suma_dados=((vec_dados[0]+vec_dados[1])*2);
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_2+=suma_dados;
                    if(acu_trufa_2>=50){
                    bandera_3dados2=1;
                    }
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s."<<endl;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    }

            //3ERA CONDICION CARAS DISTINTAS Y HAY UN AS.►PIERDE TODAS LAS TRUFAS DE LA RONDA ACTUAL. CEDE EL TURNO
                if(vec_dados[0]!=vec_dados[1]&&(vec_dados[0]==1||vec_dados[1]==1)){
                    cout<<jugador_siguiente<<" pierde "<<trufa_ronda<<" trufas de la ronda actual y cede el turno."<<endl;
                    acu_trufa_2-=trufa_ronda;
                    trufa_ronda=0;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador.
                    turno=0;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


            //4TA CONDICION 2 CARAS IGUALES Y SON ASES ►SE HUNDE EN EL BARRO Y PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES. CEDE EL TURNO
                if (vec_dados[0]==vec_dados[1] && vec_dados[0]==1){
                    cout<<jugador_siguiente<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_2<<" trufas de rondas anteriores, incluida la actual."<<endl<<"Cede el turno a "<<jugador_actual<<endl;
                    acu_trufa_2=0;
                    bandera_hunde=1;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=0;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


        }
        else{

            //===========================2DO JUGADOR. SE TIRAN 3 DADOS=====================================

             tirar_datres(vec_datres[0], vec_datres[1], vec_datres[2]);
             dadosmat(dados,vec_datres[0],vec_datres[1],vec_datres[2]);


             //1ERA CONDICION 3 CARAS DISTINTAS Y NO SON 1// 2 CARAS DISTINTAS Y NINGUNA DE LAS 3 SON 1►SE SUMAN LOS DADOS. DEBE ELEGIR SI CONTINUAR O NO
                if (((vec_datres[0]!=vec_datres[1] && vec_datres[1]!=vec_datres[2] &&vec_datres[0]!=vec_datres[2]) &&(vec_datres[0]!=1 &&vec_datres[1]!=1 &&vec_datres[2]!=1)) ||  ((vec_datres[0]!=vec_datres[1] || vec_datres[1]!=vec_datres[2] ||vec_datres[0]!=vec_datres[2]) &&(vec_datres[0]!=1 &&vec_datres[1]!=1 &&vec_datres[2]!=1))) {
                    suma_dados=vec_datres[0]+vec_datres[1]+vec_datres[2];
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_2+=suma_dados;
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Pod"<<char(130)<<"s tirar los dados una vez m"<<char(160)<<"s."<<endl;
                    cout<<char(168)<<"Continuar? (S/N)"<<endl;
                    while (bandera_eleccion==0){
                    cin>>continuar;
                    continuar=toupper(continuar);
                    switch (continuar){
                    case 'S':
                    bandera_eleccion=1;
                    break;
                    case'N':
                    bandera_seguir=1;
                    bandera_eleccion=1;
                    turno=0;
                    break;
                    default:
                    cout<<"Por favor digite una opci"<<char(162)<<"n v"<<char(160)<<"lida."<<endl;
                    cout<<char(168)<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s? (S/N)."<<endl;
                    break;
                    }
                    }
                    bandera_eleccion=0;//SE VUELVE A PONER EN CERO PARA LA SIGUIENTE VUELTA.
                    }



        //2DA CONDICION 3 CARAS IGUALES Y NO HAY ASES►OINK►SE DOBLA LA SUMA DE LOS DADOS. DEBE LANZAR UNA VEZ MAS.
                if(vec_datres[0]==vec_datres[1] &&vec_datres[1]==vec_datres[2] &&vec_datres[0]!=1){//CON QUE UN SOLO DADO NO SEA UNO YA SE CUMPLE. YA QUE TODOS SON IGUALES.
                    cout<<char(173)<<"LOGRASTE UN OINK!"<<endl;
                    cont_oink_2++;
                    suma_dados=((vec_datres[0]+vec_datres[1]+vec_datres[2])*2);
                    trufa_ronda+=suma_dados;
                    trufa_lanzamiento=suma_dados;
                    acu_trufa_2+=suma_dados;
                    cout<<char(173)<<"Sumaste "<<trufa_lanzamiento<<" trufas!"<<endl;
                    cout<<"Lanz"<<char(160)<<"s los dados una vez m"<<char(160)<<"s."<<endl;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    }


        //3ERA CONDICION 3 CARAS DISTINTAS Y HAY UN AS// 2 CARAS DISTINTAS Y HAY UN AS ►PIERDE TODAS LAS TRUFAS DE LA RONDA ACTUAL. CEDE EL TURNO
                    if((vec_datres[0]!=vec_datres[1] &&vec_datres[1]!=vec_datres[2] &&vec_datres[0]!=vec_datres[2] &&(vec_datres[0]==1 ||vec_datres[1]==1 ||vec_datres[2]==1)) || (vec_datres[0]!=1 && vec_datres[1]!=1 && vec_datres[2]==1)||(vec_datres[1]!=1 && vec_datres[2]!=1 && vec_datres[0]==1)||(vec_datres[2]!=1 && vec_datres[0]!=1 && vec_datres[1]==1)){
                    cout<<jugador_siguiente<<" pierde "<<trufa_ronda<<" trufas de la ronda actual y cede el turno a "<<jugador_actual<<endl;
                    acu_trufa_2-=trufa_ronda;
                    trufa_ronda=0;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador.
                    turno=0;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


        //4TA CONDICION 2 CARAS IGUALES Y SON ASES ►SE HUNDE EN EL BARRO Y PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES. CEDE EL TURNO
                if ((vec_datres[0]==vec_datres[1]&&vec_datres[0]==1)  || (vec_datres[1]==vec_datres[2]&&vec_datres[1]==1)   || (vec_datres[0]==vec_datres[2]&&vec_datres[0]==1)){
                    cout<<jugador_siguiente<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_2<<" trufas de rondas anteriores, incluida la actual."<<endl<<"Cede el turno a "<<jugador_actual<<endl;
                    acu_trufa_2=0;
                    bandera_hunde=1;
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=0;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }


        //5TA CONDICION 3 CARAS IGUALES Y SON ASES►SE HUNDE EN EL BARRO, PIERDE LAS TRUFAS DE LAS RONDAS ANTERIORES,SE LAS SUMA AL ENEMIGO Y CEDE EL TURNO.
                if (vec_datres[0]==vec_datres[1] &&vec_datres[1]==vec_datres[2] &&vec_datres[0]==1){//CON QUE UN SOLO DADO SEA UNO YA SE CUMPLE. YA QUE TODOS SON IGUALES.
                    cout<<jugador_siguiente<<" se hunde en el barro."<<endl<<"Pierde "<<acu_trufa_2<<" trufas de rondas anteriores, incluida la actual, y se las cede a " <<jugador_actual<<endl<<"Cede el turno."<<endl;
                    acu_trufa_1+=acu_trufa_2;//PARA SUMAR EL PUNTAJE A LAS TRUFAS DEL ENEMIGO.
                    acu_trufa_2=0;//PONE LAS TRUFAS DEL  J1 EN CERO.
                    system("pause");//Alternativa para que pare antes de pasar a la otra pantalla. Pide solamente digitar una tecla
                    system("cls");//Pasa de pantalla
                    bandera_seguir=1;//para que salga del while del primer jugador y termine la vuelta del jugador 1.
                    turno=0;//Cambio el turno de 0 a 1 y por lo tanto en la siguiente vuelta del for le toca al jugador 2.
                    }
        }//cierra if

    }

    }

}





///DADO UN INT, COMO MAXIMO MOSTRAR 2 DIGITOS, Y EN CASO DE QUE SEA MENOR A 10 RELLENARLO CON CEROS.
void ordenar2(int num){
if(num<10){
            cout.fill  ('0');//PARA MOSTRAR SOLO 2 DIGITOS-AGREGA CEROS
            cout.width ( 2 );//PARA MOSTRAR SOLO 2 DIGITOS-COMO MAXIMO MUESTRA 2 DIGITOS
            }
            cout<<num;
}


///DADO UN INT, COMO MAXIMO MOSTRAR 3 DIGITOS, Y EN CASO DE QUE SEA MENOR A 100 RELLENARLO CON CEROS.
void ordenar3(int num){
if(num<100){
            cout.fill  ('0');//PARA MOSTRAR SOLO 2 DIGITOS-AGREGA CEROS
            cout.width ( 3 );//PARA MOSTRAR SOLO 2 DIGITOS-COMO MAXIMO MUESTRA 2 DIGITOS
            }
            cout<<num;
}



///CALCULAR PUNTAJE
void calcular_puntaje(int indice, ganador finalistas[], int max_lanzam_1, int max_lanzam_2, string jugador_actual, string jugador_siguiente, int acu_trufa_1, int acu_trufa_2, int cont_oink_1, int cont_oink_2, int &PDV_MAX_1,int &PDV_MAX_2,int &PDV_50_1,int &PDV_50_2,int &PDV_OINK_1,int &PDV_OINK_2,int &PDV_CODICIOSO_1,int &PDV_CODICIOSO_2,int &TOTAL1,int &TOTAL2){
//5 PDV AL QUE TENGA MAS TRUFAS EN TOTAL. SI EMPATAN LE SUMA 5 A AMBOS.
if (acu_trufa_1>acu_trufa_2){
    PDV_MAX_1=5;
    PDV_MAX_2=0;
    TOTAL1+=PDV_MAX_1;
    TOTAL2+=PDV_MAX_2;
}
else{
    if(acu_trufa_1<acu_trufa_2){
    PDV_MAX_1=0;
    PDV_MAX_2=5;
    TOTAL1+=PDV_MAX_1;
    TOTAL2+=PDV_MAX_2;

    }
    else{
    PDV_MAX_1=5;
    PDV_MAX_2=5;
    TOTAL1+=PDV_MAX_1;
    TOTAL2+=PDV_MAX_2;
    }
}
//1 PDV CADA 50 TRUFAS
PDV_50_1=acu_trufa_1 / 50;
PDV_50_2=acu_trufa_2 / 50;
TOTAL1+=PDV_50_1;
TOTAL2+=PDV_50_2;
//2 PDV POR CANT. OINKS
PDV_OINK_1=cont_oink_1*2;
PDV_OINK_2=cont_oink_2*2;
TOTAL1+=PDV_OINK_1;
TOTAL2+=PDV_OINK_2;
//3 PDV PARA EL QUE HAYA HECHO LA RONDA CON MAYOR CANTIDAD DE LANZAMIENTOS
if(max_lanzam_1>max_lanzam_2){
PDV_CODICIOSO_1=3;
PDV_CODICIOSO_2=0;
TOTAL1+=PDV_CODICIOSO_1;
TOTAL2+=PDV_CODICIOSO_2;
}
else{
    if(max_lanzam_2>max_lanzam_1){
PDV_CODICIOSO_1=0;
PDV_CODICIOSO_2=3;
TOTAL1+=PDV_CODICIOSO_1;
TOTAL2+=PDV_CODICIOSO_2;
    }
    else{
    if(max_lanzam_1==max_lanzam_2){
PDV_CODICIOSO_1=3;
PDV_CODICIOSO_2=3;
TOTAL1+=PDV_CODICIOSO_1;
TOTAL2+=PDV_CODICIOSO_2;
    }
    }
}
//CALCULAMOS GANADOR
if(TOTAL1>TOTAL2){
   finalistas[indice].nombre_ganador=jugador_actual;
   finalistas[indice].puntaje_ganador=TOTAL1;
}
else{
    if(TOTAL2>TOTAL1){
    finalistas[indice].nombre_ganador= jugador_siguiente;
    finalistas[indice].puntaje_ganador=TOTAL2;
    }

    }
}




///MOSTRAR PUNTAJE DEL ULTIMO JUEGO
void mostrar_puntaje(int indice, ganador finalistas[], int max_lanzam_1, int max_lanzam_2,string jugador_actual, string jugador_siguiente, int acu_trufa_1, int acu_trufa_2, int cont_oink_1, int cont_oink_2,int &PDV_MAX_1,int &PDV_MAX_2,int &PDV_50_1,int &PDV_50_2,int &PDV_OINK_1,int &PDV_OINK_2,int &PDV_CODICIOSO_1,int &PDV_CODICIOSO_2,int &TOTAL1,int &TOTAL2){
string texto_ordenado, puntos;
int resto1,resto2;
resto1=acu_trufa_1 % 50;
resto2=acu_trufa_2 % 50;
cout<<endl;
cambiar_verde();
cout<<"EL GRAN CERDO"<<endl;
cambiar_blanco();
linea();
printf("%-23s %-27s %s\n","HITO",jugador_actual.c_str(),jugador_siguiente.c_str());
linea();
cout<<"M"<<char(160)<<"s trufas en total     ";ordenar2(PDV_MAX_1);cout<<"  PDV "<<"(";ordenar3(acu_trufa_1);cout<<" trufas)"<<"        ";ordenar2(PDV_MAX_2);cout<<" PDV "<<"(";ordenar3(acu_trufa_2);cout<<" trufas)"<<endl;
cout<<"Cada 50 trufas          ";ordenar2(PDV_50_1);cout<<"  PDV "<<"(";ordenar3(acu_trufa_1-resto1);cout<<" trufas)"<<"        ";ordenar2(PDV_50_2);cout<<" PDV "<<"(";ordenar3(acu_trufa_2-resto2);cout<<" trufas)"<<endl;
cout<<"OINKS                   ";ordenar2(PDV_OINK_1);cout<<"  PDV "<<"(";ordenar3(cont_oink_1);cout<<" Oinks)"<<"         ";ordenar2(PDV_OINK_2);cout<<" PDV "<<"(";ordenar3(cont_oink_2);cout<<" Oinks)"<<endl;
cout<<"CERDO CODICIOSO         ";ordenar2(PDV_CODICIOSO_1);cout<<"  PDV "<<"(";ordenar3(max_lanzam_1);cout<<" lanzamientos)"<<"  ";ordenar2(PDV_CODICIOSO_2);cout<<" PDV "<<"(";ordenar3(max_lanzam_2);cout<<" lanzamientos)"<<endl;
linea();
cout<<"TOTAL                   ";ordenar2(TOTAL1);cout<<"  PDV"<<"                     ";ordenar2(TOTAL2);cout<<" PDV"<<endl;
cout<<endl<<endl;
if(finalistas[indice].nombre_ganador==jugador_actual || finalistas[indice].nombre_ganador==jugador_siguiente){
cout<<"GANADOR: "<<finalistas[indice].nombre_ganador<<" con "<<finalistas[indice].puntaje_ganador<<" puntos de victoria."<<endl<<endl;
}
else{
    cambiar_violeta();
    cout<<"Hubo empate de puntaje con "<<TOTAL1<<" puntos cada uno."<<endl;
    cambiar_blanco();
}
}

///RELLENAR STRUCT
void rellenar_struct(ganador finalistas[]){
for (int x=0; x<5; x++){
    finalistas[x].nombre_ganador="VACIO";
    finalistas[x].puntaje_ganador=0;
}
}

///ORDENAR ESTADISTICAS DE MAYOR A MENOR
void ordenar_estadisticas (ganador finalistas[]){
int aux1;
string aux2;
for (int y=0;y<5;y++){
    for (int x=0;x<4;x++){
        if (finalistas[x].puntaje_ganador<finalistas[x+1].puntaje_ganador){
        aux1=finalistas[x+1].puntaje_ganador;
        finalistas[x+1].puntaje_ganador=finalistas[x].puntaje_ganador;
        finalistas[x].puntaje_ganador=aux1;

        aux2=finalistas[x+1].nombre_ganador;
        finalistas[x+1].nombre_ganador=finalistas[x].nombre_ganador;
        finalistas[x].nombre_ganador=aux2;
        }
    }
}
return;
}

///MOSTRAR ESTADISTICAS
void mostrar_estadisticas(ganador finalistas[]){
cambiar_violeta();
cout<<endl<<"*** LISTADO DE GANADORES ***"<<endl<<endl;
cambiar_blanco();
for (int x=0; x<5; x++){
    cout<<x+1<<"# LUGAR "<<finalistas[x].nombre_ganador<<" CON "<<finalistas[x].puntaje_ganador<<" PDV."<<endl<<endl;

}


}


///MOSTRAR 2 DADOS
void dadosmat(char mat[][37], int num1, int num2){
for (int j=0;j<5;j++){
        for (int i=0;i<37;i++){
                mat[j][i]=' ';

        }
    }


    for (int j=0;j<5;j++){
        for (int i=0;i<37;i++){
            if(j==0 ||j== 4 ||i==0||i==10 ||i==13 ||i==23){
                mat[j][i]='*';
            }
        }
    }



    //PARA PONER ESPACIO ENTRE LOS DADOS.
    mat[0][11]=' ';
    mat[1][11]=' ';
    mat[2][11]=' ';
    mat[3][11]=' ';
    mat[4][11]=' ';
    mat[0][12]=' ';
    mat[1][12]=' ';
    mat[2][12]=' ';
    mat[3][12]=' ';
    mat[4][12]=' ';


    mat[0][24]=' ';
    mat[1][24]=' ';
    mat[2][24]=' ';
    mat[3][24]=' ';
    mat[4][24]=' ';
    mat[0][25]=' ';
    mat[1][25]=' ';
    mat[2][25]=' ';
    mat[3][25]=' ';
    mat[4][25]=' ';

    //DADO 1
    if(num1==1){
    mat[2][5]=char(4);

    }

    if(num1==2){
    mat[2][4]=char(4);
    mat[2][6]=char(4);
    }

    if(num1==3){
    mat[1][2]=char(4);
    mat[2][5]=char(4);
    mat[3][8]=char(4);
    }

    if(num1==4){
    mat[1][3]=char(4);
    mat[3][3]=char(4);
    mat[1][7]=char(4);
    mat[3][7]=char(4);
    }

    if(num1==5){
    mat[1][2]=char(4);
    mat[3][2]=char(4);
    mat[1][8]=char(4);
    mat[3][8]=char(4);
    mat[2][5]=char(4);
    }

    if(num1==6){
    mat[1][3]=char(4);
    mat[3][3]=char(4);
    mat[1][5]=char(4);
    mat[3][5]=char(4);
    mat[1][7]=char(4);
    mat[3][7]=char(4);
    }

    //DADO 2
    if(num2==1){
    mat[2][18]=char(4);
    }


    if(num2==2){
    mat[1][18]=char(4);
    mat[2][18]=char(4);
    }

    if(num2==3){
    mat[1][15]=char(4);
    mat[2][18]=char(4);
    mat[3][21]=char(4);
    }


    if(num2==4){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);
    }


    if(num2==5){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);
    mat[2][18]=char(4);

    }

    if(num2==6){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][18]=char(4);
    mat[3][18]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);

    }



   for (int j=0;j<5;j++){
        for (int i=0;i<25;i++){
            cout<<mat[j][i];
        }
    cout<<"\n";
   }
}





///MOSTRAR 3 DADOS
void dadosmat(char mat[][37],int num1,int num2,int num3){
 for (int j=0;j<5;j++){
        for (int i=0;i<37;i++){
                mat[j][i]=' ';

        }
    }


    for (int j=0;j<5;j++){
        for (int i=0;i<37;i++){
            if(j==0 ||j== 4 ||i==0||i==10 ||i==13 ||i==23 || i==26 || i==36){
                mat[j][i]='*';
            }
        }
    }




    //PARA PONER ESPACIO ENTRE LOS DADOS.
    mat[0][11]=' ';
    mat[1][11]=' ';
    mat[2][11]=' ';
    mat[3][11]=' ';
    mat[4][11]=' ';
    mat[0][12]=' ';
    mat[1][12]=' ';
    mat[2][12]=' ';
    mat[3][12]=' ';
    mat[4][12]=' ';


    mat[0][24]=' ';
    mat[1][24]=' ';
    mat[2][24]=' ';
    mat[3][24]=' ';
    mat[4][24]=' ';
    mat[0][25]=' ';
    mat[1][25]=' ';
    mat[2][25]=' ';
    mat[3][25]=' ';
    mat[4][25]=' ';

    //DADO 1
    if(num1==1){
    mat[2][5]=char(4);

    }

    if(num1==2){
    mat[2][4]=char(4);
    mat[2][6]=char(4);
    }

    if(num1==3){
    mat[1][2]=char(4);
    mat[2][5]=char(4);
    mat[3][8]=char(4);
    }

    if(num1==4){
    mat[1][3]=char(4);
    mat[3][3]=char(4);
    mat[1][7]=char(4);
    mat[3][7]=char(4);
    }

    if(num1==5){
    mat[1][2]=char(4);
    mat[3][2]=char(4);
    mat[1][8]=char(4);
    mat[3][8]=char(4);
    mat[2][5]=char(4);
    }

    if(num1==6){
    mat[1][3]=char(4);
    mat[3][3]=char(4);
    mat[1][5]=char(4);
    mat[3][5]=char(4);
    mat[1][7]=char(4);
    mat[3][7]=char(4);
    }

    //DADO 2
    if(num2==1){
    mat[2][18]=char(4);
    }


    if(num2==2){
    mat[1][18]=char(4);
    mat[2][18]=char(4);
    }

    if(num2==3){
    mat[1][15]=char(4);
    mat[2][18]=char(4);
    mat[3][21]=char(4);
    }


    if(num2==4){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);
    }


    if(num2==5){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);
    mat[2][18]=char(4);

    }

    if(num2==6){
    mat[1][16]=char(4);
    mat[3][16]=char(4);
    mat[1][18]=char(4);
    mat[3][18]=char(4);
    mat[1][20]=char(4);
    mat[3][20]=char(4);

    }


    //DADO 3
    if(num3==1){
    mat[2][31]=char(4);
    }

    if(num3==2){
    mat[1][31]=char(4);
    mat[2][31]=char(4);
    }


    if(num3==3){
    mat[1][28]=char(4);
    mat[2][31]=char(4);
    mat[3][34]=char(4);

    }

    if(num3==4){
    mat[1][29]=char(4);
    mat[3][29]=char(4);
    mat[1][33]=char(4);
    mat[3][33]=char(4);
    }

    if(num3==5){
    mat[1][29]=char(4);
    mat[3][29]=char(4);
    mat[1][33]=char(4);
    mat[3][33]=char(4);
    mat[2][31]=char(4);
    }

    if(num3==6){
    mat[1][29]=char(4);
    mat[3][29]=char(4);
    mat[1][31]=char(4);
    mat[3][31]=char(4);
    mat[1][33]=char(4);
    mat[3][33]=char(4);
    }

   for (int j=0;j<5;j++){
        for (int i=0;i<37;i++){
            cout<<mat[j][i];
        }
    cout<<"\n";
   }
}

