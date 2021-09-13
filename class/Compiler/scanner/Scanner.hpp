#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
struct node {
  int vertex;
  char weight[100];
  struct node* next;};
struct node* createNode(int);
struct Graph {
  int numVertices;
  struct node** adjLists;};
struct node* createNode(int v) {
  struct node* newNode;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  strcpy(newNode->weight, "");
  return newNode;}
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;
  return graph;}
void addEdge(struct Graph* graph, int b, int d, const char* w) {
    std::string str("");
    str += w;
  struct node* newNode = createNode(d);
  newNode->next = graph->adjLists[b];
  strcat(newNode->weight, str.c_str());
  graph->adjLists[b] = newNode;}
void casos(struct Graph* graph , char regex[100], struct Graph* nfa);
int corchete(char regex[100], int rec, struct Graph* nfa, int ini, int dest);
void parentesis(int *ini, int *dest, struct Graph* nfa, char test[100], int rec, int *save);
void asterisco(int **ini, int **dest, struct Graph* nfa, int n, bool retornar);
void asterisco(int **ini, int **dest, struct Graph* nfa, int n, bool retornar);
void transform(struct Graph* nfa, struct Graph* dfa, struct Graph* mega);
int dividir(int rec, int ini, int dest, int save, string str, struct Graph* nfa, char regex[100]);
bool ramificar = false;
bool doble = false;
struct Graph* graph = createAGraph(14);
void scanner(){
char regex[100];
char token[100];
struct Graph* mega = createAGraph(15);
ifstream texto ("regex.txt");
addEdge(graph, 0, 1, "1");
addEdge(graph, 0, 1, "[");
addEdge(graph, 0, 1, "("); 
addEdge(graph, 1, 2, "1");
addEdge(graph, 1, 2, "[");
addEdge(graph, 1, 4, "·");
addEdge(graph, 1, 3, "|");
addEdge(graph, 2, 2, "1");
addEdge(graph, 2, 6, ")");
addEdge(graph, 2, 2, "[");
addEdge(graph, 2, 3, "|");
addEdge(graph, 3, 2, "1");
addEdge(graph, 3, 2, ")");
addEdge(graph, 3, 2, "[");
addEdge(graph, 3, 4, "·");
addEdge(graph, 3, 2, "(");
addEdge(graph, 2, 4, "·");
addEdge(graph, 4, 2, "1");
addEdge(graph, 4, 1, "(");
addEdge(graph, 4, 2, "[");
addEdge(graph, 5, 3, "(");
addEdge(graph, 5, 4, "·");
addEdge(graph, 5, 2, ")");
addEdge(graph, 6, 7, "+");
addEdge(graph, 6, 7, "*");
addEdge(graph, 6, 7, "?");
addEdge(graph, 6, 0, "·");
addEdge(graph, 6, 5, "|");
addEdge(graph, 7, 1, "|");
addEdge(graph, 7, 0, "·");
addEdge(graph, 7, 6, ")");
ofstream myfile ("grafos.txt");
texto >> token;
texto >> regex;
struct node* temp;
int recorrer = 0;
while(strcmp(token, "END") != 0){
  struct Graph* dfa = createAGraph(14);
struct Graph* nfa = createAGraph(14);
casos(graph, regex, nfa);
transform(nfa, dfa, mega);
myfile << token;
myfile << endl;
recorrer = 0;
temp = dfa->adjLists[0];
while(true){
while(temp){
        myfile << std::to_string(recorrer);
        myfile << std::to_string(temp->vertex);
        myfile << temp->weight;
        temp = temp->next;}
recorrer += 1;
if(recorrer == 14){break;}
temp = dfa->adjLists[recorrer];}
myfile << endl;
  texto >> token;
  texto >> regex;}
myfile << "END";
myfile.close();
texto.close(); printf("\nGrafos generados correctamente");}
void casos(struct Graph* graph , char regex[100], struct Graph* nfa){
int rec = 0;
std::string str("");
bool nonext = false;
int ini = -1;
int dest = 0;
int save = 0;
struct node* temp = graph->adjLists[0];
while(regex[rec] != '\0'){
str = "";
str = regex[rec];
if(strcmp(temp->weight, str.c_str()) == 0){
if(regex[rec] == '['){
rec = corchete(regex, rec, nfa, ini, dest);}
else if(regex[rec] == '('){
parentesis(&ini, &dest, nfa, regex, rec, &save);}
else if(regex[rec] == '|'){
str = "";
rec += 1;
if((regex[rec] == '(' && regex[rec+2] != ')')){
rec += 1;
if(regex[rec] != -50){str += regex[rec];
dest += 1;
ini = dest-1;
if(regex[rec] == 32){str = "|";}
addEdge(nfa, save, dest, str.c_str());}else{rec -= 1;}}
else{rec -= 1;}}
temp = graph->adjLists[temp->vertex];
nonext = true;}
else if((temp->vertex == 4 || temp->vertex == 0) && regex[rec] == -62){
if(regex[rec+2] != '('){ini += 1;dest += 1;rec += 1;}else{rec += 1;}
temp = graph->adjLists[temp->vertex];
nonext = true;}
else if(strcmp(temp->weight, "1") == 0){
if(ini == -1){ini += 1; dest += 1;}
if(regex[rec] == -50){
    addEdge(nfa, ini, dest, "#");
    rec += 1;}
else{if(regex[rec] == 36){str = "(";}
    if(regex[rec] == 35){str = ")";}
    if(regex[rec] == 38){str = "[";}
    if(regex[rec] == 94){str = "]";}
  addEdge(nfa, ini, dest, str.c_str());}
temp = graph->adjLists[temp->vertex];
nonext = true;}
if(!nonext){temp = temp->next;}
else{nonext = false;rec += 1;}}}
int corchete(char regex[100], int rec, struct Graph* nfa, int ini, int dest){
bool iterar = true;
bool buscar = false;
std::string str("");
int x = 1;
int y = 3;
while(iterar){
    if(regex[rec+x+1] == ']'){str = regex[rec+x];
    addEdge(nfa, ini, dest, str.c_str());rec = rec+x+1;break;}
    else{
    for(char i=regex[rec+x];i<=regex[rec+y];i++){
        str = i;
    addEdge(nfa, ini, dest, str.c_str());}if(regex[rec+y+1] == ']'){rec = rec+y+1;break;}else{x += 3; y+= 3;}}}
return rec;}
void parentesis(int *ini, int *dest, struct Graph* nfa, char test[100], int rec, int *save){
    int comp = 0;
    bool final = false;
    *ini += 1;
    *dest += 1;
    int n = 0;
    for(int e=1;test[rec+e] != '\0'; e++){
        if(test[rec+e] == ')'){
            comp -= 1;
            if(comp == -1){
                final = true;}}
        else if(test[rec+e] == '('){comp += 1;}
        else if(test[rec+e] == '*'){
            if(final){asterisco(&ini, &dest, nfa, n, true);ramificar=false;ini+=1;
            break;}
            else{n += 2;}}
        else if(test[rec+e] == '+'){
            if(final){addEdge(nfa, *dest, *ini, "#");ramificar=false;
            break;}
            else{n += 1;}}
        else if(test[rec+e] == '?'){
            if(final){asterisco(&ini, &dest, nfa, n, false);ramificar=false;ini+=1;
            break;}
            else{n += 2;}}
        else if(test[rec+e] == '|'){if(final){if(!ramificar){*save=*ini;ramificar=true;}break;}}
        else{if(comp == -1){break;}}}}  
void asterisco(int **ini, int **dest, struct Graph* nfa, int n, bool retornar){
addEdge(nfa, **ini, **dest, "#");
**ini += 1;
**dest += 1;
addEdge(nfa, **ini, **dest+1+n, "#");
if(retornar){addEdge(nfa, **dest, **ini, "#");}}
int dividir(int rec, int ini, int dest, int save, string str, struct Graph* nfa, char regex[100]){
struct node* temp = nfa->adjLists[save];
bool asignar = true;
while(temp){
  if(strcmp(temp->weight, str.c_str()) == 0){
    rec += 3;
    str = regex[rec];
    addEdge(nfa, temp->vertex, dest, str.c_str());
    asignar = false;
    break;}
  temp = temp->next;}
if(asignar){addEdge(nfa, save, dest, str.c_str());}
return rec;}
void transform(struct Graph* nfa, struct Graph* dfa, struct Graph* mega){
struct node* temp = nfa->adjLists[0];
struct node* temp2;
int actual = 0;
int ini = 0;
int dest = 0;
int caracteres = 0;
int epsilon = 0;
bool retorno = false;
bool bifurcar = false;
while(true){
while(temp){
if(strcmp(temp->weight, "#") == 0){
epsilon += 1; 
if(temp->vertex == actual-1){retorno = true;}} //El primer caso es si epsilon apunta a un nodo anterior <- * o + 
// Ya no incluyo epsilon sino que lo que hago ahora es que cuando llegue a retorno va a hacer que los caracteres del siguiente nodo
// apunten al mismo nodo -> 2->1 hay epsilon, esto significa que los caracteres que esten en el 1->2 apunten a su mismo nodo
else{
  caracteres += 1;
  addEdge(dfa, actual-dest, temp->vertex-dest, temp->weight);
  if(caracteres > 0 && epsilon > 0){bifurcar = true;}} // Si puedo pasar via epsilon y a su vez hay un caracter apuntando al mismo nodo
  // Entonces puedo pasar via ese caracter o simplemente lo puedo ignorar y aun asi pasar
temp = temp->next;}
if(retorno || bifurcar){ // De ahi si viene epsilon y no cumple con ninguno de estos 2 casos, la ignoro y simplemete no la agrego
  if(retorno){
    temp = nfa->adjLists[actual-1];
    while(temp){
      if(strcmp(temp->weight, "#") != 0){addEdge(dfa, actual-dest, actual-dest, temp->weight);}
      temp = temp->next;}retorno = false;}
  if(bifurcar){
    temp = nfa->adjLists[actual+1];
    while(temp){
    if(strcmp(temp->weight, "#") != 0){addEdge(dfa, actual-dest, temp->vertex-dest, temp->weight);}
    temp = temp->next;}bifurcar = false;}}
actual += 1;
if(caracteres > 0){ini += 1;}else{if(epsilon > 0){dest += 1;}}
caracteres = 0;
epsilon = 0;
if(actual == 14){break;}
temp = nfa->adjLists[actual];}}