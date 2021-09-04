#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
struct node {
  int vertex;
  int weight;
  struct node* next;
};
struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
};
struct node* createNode(int v) {
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  newNode->weight = 0;
  return newNode;
}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}
void addEdge(struct Graph* graph, int b, int d, int w) {    
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[b];
  newNode->weight = w;
  graph->adjLists[b] = newNode;
} // El codigo de la linea 6 a la 39 es todo el tema de creacion y definicion de grafos
int n = 0; // Esta variable servira para movernos en los diferentes nodos segun venga la condicional digase: ?, *, +
char simbolos[10][10][56]; //Un grafo en matriz, esto para hacer mas facil guardar la informacion
bool nuevonodo = false; // Este servira para crear un nuevo nodo
int dest = 0; // El nodo destino
int ini = -1; // El nodo inicial
int rec = 0; // Ira recorriendo cada parte del test
void asterisco(); // Hace la funcion de * (notacion compiladores)
void interrogacion(); // Hace la funcion de ? (notacion compiladores)
void suma(); // Hace la funcion de + (notacion compiladores)
void parentesis(char test[]); //Da la senial de que vienen nuevas cosas y empieza a preparar los nodos
void almacenar(); // Almacena los caracteres
char test[] = "(t·r·u·e)|(f·a·l·s·e)"; // Input donde etson probara todo
bool guardando = true; // Este servira mas que todo para palabras para separarlas para que no suceda ejemplo: t-r-u-e-f-a-l-s-e sino que ponga true en una fila y false en otra (ejemplo)
bool ramificar = false; // Este activa la ramificacion para que se de lo que mencionaba en guardando
int guardar_x = 0; // Este sera el nodo inicial y podra ramificarse segun vengan las condiciones
void casos(char test[], struct Graph* graph); // Todos los casos dentro del grafo, vease *, ?, +, o si vienen varias juntas
struct Graph* graph = createAGraph(8); // Creamos un grafo con todas las instrucciones
int main(){
addEdge(graph, 1, 2, 1); // Del 2 al 3
addEdge(graph, 0, 1, 40); // Del 1 al 2
addEdge(graph, 2, 2, 1);
addEdge(graph, 2, 6, 41);
addEdge(graph, 2, 3, 124);
addEdge(graph, 2, 4, -62);
addEdge(graph, 3, 2, 1);
addEdge(graph, 4, 2, 1);
addEdge(graph, 4, 1, 40);
addEdge(graph, 5, 3, 40);
addEdge(graph, 6, 7, 0);
addEdge(graph, 6, 0, -62);
addEdge(graph, 6, 5, 124);
addEdge(graph, 7, 0, -62);
addEdge(graph, 7, 6, 41); // Este grafo representa las instrucciones para crear un nfa
printf("ENTRE A CASOS?");
casos(test, graph); //Por razones de complicaciones, se usara # en lugar de epsilon ya que C++ no lo detecta bien
}
void asterisco(){// Funcion que hace lo que hace *
strcat(simbolos[ini][dest], "#"); //Crea transicion por epsilon
if(ramificar){// Este es para ramificar en dado caso vinieran varios OR
  ini = dest;
  dest += 1;
}
else{
ini += 1;
dest += 1;}// Este es para avanzar luego de la transicion por epsilon
strcat(simbolos[ini][dest+n+1], "#"); // n representa los nodos que debe moverse en caso vengan mas condicionales, pone # para denotar salto por si no quiere entrar
strcat(simbolos[dest][ini], "#");// Denota epsilon de retorno por si quiere poner mas de uno
}
void interrogacion(){ // Igual a asterisco con la unica diferencia que no hay epsilon de retorno por lo que solo puede pasar 1 vez
strcat(simbolos[ini][dest], "#");
if(ramificar){
  ini = dest;
  dest += 1;
}
else{
ini += 1;
dest += 1;}
strcat(simbolos[ini][dest+1+n], "#");
}
void suma(){ // Crea epsilon de retorno para iterar n veces
strcat(simbolos[dest][ini], "#");
}
void parentesis(char test[]){
ini += 1;
dest += 1; // Suma en dest e ini para denotar nuevo nodo
if (guardando){
guardar_x = ini; // Este es para guardar nodo inicial en caso vinieran OR
}
else if (ramificar){
  ini = guardar_x;// Este ramifica si es el caso
}
n = 0;
int comp = 0; // Este es para orientar el parentesis de apertura y cierre
nuevonodo = false;
int e=1;// Este es para avanzar en caracteres
for(;test[rec+e] != '\0';e++){
  if(nuevonodo && test[rec+e] != 42 && test[rec+e] != 43 && test[rec+e] != 63 && test[rec+e] != 124){
    break; // Si en dado caso ya se recorrio todo lo del parentesis y vienen instrucciones especiales se las salta (no es el fin de esta funcion)
  }
if(test[rec+e] == -50){// Epsilon normalmente aparece como -50 2 veces y a veces como -75
  std::string str("");
  str += '#';
  test[rec+e] = '#';// Elimina el -75 y cambia epsilon por # para poder mostrarlo en terminal
  test[rec+1+e] = '#';
  for(int m=rec+e; test[m]!='\0';m++){
  test[m] = test[m+1];
    }
    printf("ENTRE A PARENTESIS");}
  if(test[rec+e] == -62){// Este es para el de concatenar, tampoco se puede imprimir y normalmente aparece como -62 2 veces
    std::string str("");
    str += '$';
    test[rec+e] = '$';// Se cambia por dolar para poder mostrarlo, se repite lo de epsilon
    test[rec+e+1] = '$';
    for(int m=rec+e; test[m]!='\0';m++){
    test[m] = test[m+1];
    }printf("ENTRE A LIMPIAR .");
  }
    if(test[rec+e] == ')'){ // Si encuentra el parentesis de cierre notifica
        comp -= 1;// Si comp es 0 es porque no encontro otro parentesis de apertura, sino va restando hasta encontrar el parentesis respectivo
        if(comp == -1){ // Si es -1 denota el parentesis de cierre por lo que lo notifica
            nuevonodo = true;
        }
    }
    else if(test[rec+e] == '('){// Si encuentra uno de apertura suma +1
        comp += 1;
    }
    else if(test[rec+e] == '*'){ // Este entra a asterisco si esta dentro del parentesis
        if(nuevonodo){// Si ya se encontro el parentesis de cierre entra a asterisco a cumplir su funcion (si viene asterisco)
          guardando = true;
            printf("ENTRE A ASTERISCO");
            asterisco();
            break;
        }
        else{
          n += 2;// Suma +2 por la transicion en epsilon y el nodo de condicion como tal
        }
    }
    else if(test[rec+e] == '?'){
        if(nuevonodo){// Repite lo de asterisco
          guardando = true;
        printf("ENTRE A INTERROGACION");
        interrogacion();
        break;
        }
        else{
          n += 2;
        }
    }
    else if(test[rec+e] == '+'){// El de suma igual
        if(nuevonodo){
          guardando = true;
          printf("ENTRE A SUMA");
            suma();
            break;
        }
        else{
          n += 1;// Unica diferencia es +1 porque solo es por el nodo condicion
        }
    }
    else if(test[rec+e] == '|'){// Si en dado caso viniera OR lo notifica
      if(nuevonodo){
      guardando = false;}
    }
}
nuevonodo = false;// Para evitar crear 1 nodo de mas
ramificar = false;// Para no ramificar inecesariamente
}
void almacenar(){// Almacenaremos todo en el grafo (matrix)
std::string str("");// Usamos un string para simplificarnos la vida
str += test[rec];// Guardamos el valor del char en el string
printf("Estado actual de nuevo nodo: %d\n", nuevonodo);
if (nuevonodo){// Si es necesario se crea nuevo nodo para no sobreescribir informacion
printf("ini %d dest %d\n", ini, dest);
  ini += 1;
  dest += 1;
}
strcat(simbolos[ini][dest], str.c_str());// Se escribe en el grafo en sus respectivos nodos
if(dest-ini >= 2 && test[rec+1] == 36){
  ini = dest-1;// Si en dado caso se hiciera un gran salto debido a OR, se resta -1 para mantener balanceado ini y dest que siempre tienen 1 de diferencia
}
printf("SALI DE ALMACENAR");
}
void casos(char test[], struct Graph* graph){// Todos los casos
  struct node* temp = graph->adjLists[0];// Empezamos del nodo 0
  int actual = 0;//Denotara nodo actual
  while(test[rec] != '\0'){// Iterara hasta que este vacio
    printf("ITERANDO EN CASOS\n");
    printf("actual: %d\n", actual);
  while(temp){// Iterara hasta que ya haya probado todos los vertices en el respectivo nodo
    printf("vertice: %d\n", temp->vertex);
    if(actual == 6 && (test[rec] == 43 || test[rec] == 42 || test[rec] == 63)){// Si en dado caso viniera alguna condiciona * + ?, se omiten y se pasa a 7 ya que las instrucciones arriba ya hicieron lo suyo
      printf("ITERANDO A 7");
      while(temp->vertex != 7){// Todo es hasta que sea 7
        printf("CAMBIANDO");
        temp = temp->next;
      }
      break;
    }
  if(actual == 1 || actual == 3 || (actual == 2 && temp->vertex == 2)){ // Este es para guardar cualquier caracter, para evitar estar comparando, se hizo esta condicional
    printf("ENTRE A ALMACENAR\n");
    almacenar();
    break;
  }
  if((temp->weight == test[rec]) || (test[rec] == 36)){// Esta ya es si esta el valor en el grafo o si es concatenar
    if(test[rec] == 40){// Si el valor es parentesis de apertura va a la funcion parentesis
      parentesis(test);
      printf("SALI DE PARENTESIS");
      break;
    }
    if(test[rec] == 124 && actual == 6){// Si en dado caso viene OR en el nodo 6 ramifica
      ramificar = true;
      break;
    }
    printf("ESTOY EN CASOS?");
    if(test[rec] == 124 || test[rec] == 45){//Este guarda el OR o - juntos (caso especial) para simplificarnos la vida
      almacenar();
      printf("SALI DE ALMACENAR |");
      break;
    }
    if(test[rec] == -62 || test[rec] == 36){// Si en dado caso viene concatenar
      if(test[rec] == -62){// Si concatenar aun esta con su signo indeterminado
      std::string str("");
      str += '$';// Se cambia a dolar
      test[rec] = '$';
      test[rec+1] = '$';
      for(int m=rec; test[m]!='\0';m++){
      test[m] = test[m+1];
      }printf("ENTRE A LIMPIAR . en casos");        
      }
      printf("ASIGNO NODO A 1");
      nuevonodo = true;// Avisamos que crearemos un nuevo nodo ya que concatenar normalmente es para separar letras por nodos
      printf("Nuevonodo: %d", nuevonodo);
      break;
    }
    break;
  }
  else if (actual == 4 && temp->weight == 1){// Si en dado caso estamos en 4 mandamos de una vez a almacenar caracteres, esto es para evitar for y comparadores de mas
    almacenar();
    printf("Nuevonodo en actual 4 weight 1: %d", nuevonodo);
    printf("SALI DE ALMACENAR 4 ACTUAL");
    break;
}
temp = temp->next;// Cambio de vertice para seguir comparando
}
rec += 1;// Media vez sale del while del grafo cambia de caracter y retorna al while de caracteres
if(test[rec] == '\0'){
  break;
}
else{
actual = temp->vertex;// Guardamos el vertice al que movemos para que sea ahora el actual
temp = graph->adjLists[temp->vertex];}// Cambiamos el temp al nuevo nodo para comparar nuevos vertices
}
strcpy(simbolos[ini+1][dest+1], "#");// Se agrega epsilon al final
printf("%s", simbolos[8][9]);
}
