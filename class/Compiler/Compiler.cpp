#include <iostream>
#include <string.h>
#include "scanner/Scanner.hpp"
#include "scanner/Lexer.hpp"
bool debuguear = false;
int main( int argc, char *argv[] ){
    std::string str("");
    bool jump = false;
    int comp = 0;
    bool todo = false;
    bool msj = false;
    bool cantidad = false;
    bool quitar = false;
    int rec = 0;
    int x = 0;
    char words[15][30];
    if(argv[1] == NULL){
       printf("\nHOLA HOLA!\n");
       printf("Necesitas Ayuda?\n");
       printf("Aqui estan nuestro comandos: \n");
       printf("-target <stage> -- Donde <stage> Es la fase del proyecto que quiero correr\n");
       printf("Si '-target' lo dejas sin definir <stage> correra todo el compilador!\n");
       printf("-debug <stage> -- Donde debugueamos, similar a -target con una diferencia enorme\n");
       printf("Puedes usar los ':' para ir separando fases EJ: Scanner:Lexer -> Ira a Scanner y luego a Lexer\n");
       printf("Si dejas '-debug' vacio, debugueara todo el compilador!\n");
       printf("El comando -opt <opt_stage> aun no esta disponible dado que aun no estamos en constant o algebraic :(\n");
       printf("Pero estara disponible para las proximas entregas :D\n");
       printf("Espero haberte sido de ayuda :D\n");
       return 0;
    } 
    else if(strcmp(argv[1], "-target") == 0){if(argc == 2){todo = true;}}
    else if(strcmp(argv[1], "-debug") == 0 && argc == 2){msj=true;todo = true;debuguear=true;}
    else{
        while(argv[2][rec] != '\0'){
            str += argv[2][rec];
            if(argv[2][rec+1] == ':' || argv[2][rec+1] == '\0'){
                strcpy(words[x], str.c_str());
                x += 1;
                str = "";
                if(argv[2][rec+1] != '\0'){rec += 1;}}
            rec  += 1;}
        cantidad = true;debuguear=true;}
    if(todo){
        if(msj){printf("\n\nDebugging: Scanner\n");}else{printf("\n\nStage: Scanning\n");}
        scanner();
        if(msj){printf("\n\nDebugging: Lexer\n");}else{printf("\n\nStage: Lexer\n");}
        lexer(debuguear);}
    else if(cantidad){
        while(x != comp){
            if(strcmp(words[comp], "Scanner") == 0){
                printf("\nDebugging: Scanner\n");
                scanner();
                comp += 1;
                quitar = false;}
            else if(strcmp(words[comp], "Lexer") == 0){
                printf("\nDebugging: Lexer\n");
                lexer(debuguear);
                comp += 1;
                quitar = false;}
            if(!quitar){quitar=true;}else{comp += 1;}}}
    else{
    if(strcmp(argv[2], "Scanner") == 0){
        if(msj){printf("\nDebugging: Scanner\n");}else{printf("\nStage: Scanning\n");}
        scanner();}
    if(strcmp(argv[2], "Lexer") == 0){
        if(msj){printf("\nDebugging: Lexer\n");}else{printf("\nStage: Lexer\n");}
        lexer(debuguear);}}}