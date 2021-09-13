#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
struct nodelink{
  char data[20];
  char t[20];
  struct nodelink *next;
};
struct nodelink *Insertar(struct nodelink *tok, string info, string token){
struct nodelink *ptr, *new_node;
new_node = (struct nodelink*)malloc(sizeof(struct nodelink));
strcpy(new_node->data, info.c_str());
strcpy(new_node->t, token.c_str());
new_node->next = NULL;
if(tok==NULL){tok=new_node;tok->next = NULL;}
else{
  ptr = tok;
  while(ptr->next!=NULL){ptr = ptr->next;}
    ptr->next = new_node;
    new_node->next = NULL;}
return tok;}
struct node2 {
  int vertex;
  char weight[2];
  char name[20];
  struct node2* next;};
struct node2* createNodes(int);
struct Graph2 {
  int numVertices;
  struct node2** adjLists;};
struct node2* createNodes(int v) {
  struct node2* newNode;
  newNode = (struct node2*)malloc(sizeof(struct node2));
  newNode->vertex = v;
  newNode->next = NULL;
  strcpy(newNode->weight, "");
  strcpy(newNode->name, "");
  return newNode;}
struct Graph2* createAGraphs(int vertices) {
  struct Graph2* graph = (struct Graph2*)malloc(sizeof(struct Graph2));
  graph->numVertices = vertices;
  graph->adjLists = (struct node2**)malloc(vertices * sizeof(struct node2*));
  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;
  return graph;}
void addEdge(struct Graph2* graph, int b, int d, const char* w, const char* t) {
    std::string str("");
    str += w;
  struct node2* newNode = createNodes(d);
  newNode->next = graph->adjLists[b];
  strcat(newNode->weight, str.c_str());
  str = ""; str += t;
  strcat(newNode->name, str.c_str());
  graph->adjLists[b] = newNode;}
void crear(struct Graph2* grafo, char token[20], char dfa[1000]);
bool punteros(struct Graph2* supergrafo, char code[100], int rec, int continuar, bool *tomar, int *bueno, bool fin, char tokens[6][20]);
struct nodelink *tok = NULL;
void lexer(bool debuguear){
char code[100];
ifstream grafos("grafos.txt");
struct Graph2* supergrafo = createAGraphs(15);
char token[20];
int rec = 0;
char dfa[1000];
grafos >> token;
grafos >> dfa;
while(strcmp(token, "END") != 0){
crear(supergrafo, token, dfa);
grafos >> token;
grafos >> dfa;}
grafos.close();
ifstream codigo("codigo.txt");
bool tomar = false;
int continuar = 0;
int bueno = 0;
int comparar = 0;
bool saltar = false;
bool fin = false;
string agregar("");
string copiar;
string agregart("");
int palabra = 0;
int linea = 1;
char tokens[3][20] = {0};
while(!codigo.eof()){
  getline(codigo, copiar);
  strcpy(code, copiar.c_str());
  while(code[rec] != '\0'){
    continuar += 1;
    fin = punteros(supergrafo, code, rec, continuar, &tomar, &bueno, fin, tokens);
    if(tomar){
      continuar = 0;
      tomar = false;
       while(code[rec] != '\0' && code[rec] != ' '){
           agregar += code[rec];
           rec += 1;}
           agregart = tokens[bueno-1];
           if(debuguear){cout << "Analizando palabra: " << agregar << endl;}
           tok = Insertar(tok, agregar, agregart);
         bueno = 0; if(code[rec] != '\0'){rec += 1;}
        strcpy(tokens[0], ""); strcpy(tokens[1], "");
        if(strcmp(agregar.c_str(), "//") == 0){agregar="";agregart="";break;}
           agregar = "";  agregart = "";palabra += 1;}
    if(fin){
      continuar = 0;
      fin = false;
      if(bueno > 0){
         while(code[rec] != '\0' && code[rec] != ' '){
           agregar += code[rec];
           rec += 1;}
           agregart = tokens[bueno-1];
           if(debuguear){cout << "Analizando palabra: " << agregar << endl;}
           tok = Insertar(tok, agregar, agregart);
           strcpy(tokens[0], ""); strcpy(tokens[1], "");
           bueno = 0;
           if(strcmp(agregar.c_str(), "//") == 0){agregar="";agregart="";break;}
           agregar = ""; agregart = "";
          if(code[rec] != '\0'){rec += 1;}palabra += 1;}
          else{
            printf("\n");
            while(code[rec] != '\0' && code[rec] != ' '){agregar += code[rec];rec += 1;} bueno = 0; if(code[rec] != '\0'){rec += 1;}
            palabra += 1; if(debuguear){cout << "Analizando palabra: " << agregar << endl;}
            cout << "Error en palabra: " << agregar << " -> Linea " << linea << " Palabra #: " << palabra << endl;agregar = "";}}}
palabra = 0;
continuar = 0;
rec = 0;
linea += 1;}
codigo.close();
struct nodelink* mostrar;
mostrar = tok;
printf("\n");
while(mostrar != NULL){
  printf("%s->", mostrar->data);
  mostrar = mostrar->next;}
mostrar = tok;
printf("\n");
while(mostrar != NULL){
  printf("%s->", mostrar->t);
  mostrar = mostrar->next;}}
void crear(struct Graph2* grafo, char token[20], char dfa[1000]){
int rec = 0;
string a(""); string b(""); string c(""); string d("");
while(dfa[rec] != '\0'){
a = dfa[rec]; b = dfa[rec+1]; c = dfa[rec+2]; d = token;
addEdge(grafo, stoi(a), stoi(b), c.c_str(), d.c_str());
rec += 3;}}
bool punteros(struct Graph2* supergrafo, char code[100], int rec, int continuar, bool *tomar, int *bueno, bool fin, char tokens[6][20]){
  struct node2* pointer = supergrafo->adjLists[0];
  int avanzar = 0;
  int actual = 0;
  bool revisar = false;
  bool cambiar = false;
  bool token = true;
  bool jump = false;
  string peso("");
  string s("");
  string x("");
  s = code[rec];
  x = code[rec];
  while(pointer){
    if((strcmp(pointer->weight, s.c_str()) == 0) && (token || strcmp(peso.c_str(), pointer->name) == 0)){
      avanzar += 1;
      if(code[rec] == 34){jump = !jump;}
      if(token && avanzar == continuar){
        peso = pointer->name;
        token = false;}
      if(avanzar == continuar || revisar){
        revisar = true;
        cambiar = true;
        rec += 1;
        s = code[rec];
        if(strcmp(s.c_str(), "") == 0 || (strcmp(s.c_str(), " ")) == 0){
          if(actual == pointer->vertex){
            strcpy(tokens[*bueno], peso.c_str());
            *bueno += 1;
            return fin;}
          else{
            pointer = supergrafo->adjLists[pointer->vertex];
            while(pointer){
              if(pointer->name == peso){strcpy(tokens[*bueno], pointer->name);*bueno += 1;return fin;}
              pointer = pointer->next;}
            strcpy(tokens[*bueno], peso.c_str());
            *tomar = true;
            *bueno += 1;}
          return fin;}}}
if(cambiar){actual=pointer->vertex;pointer = supergrafo->adjLists[pointer->vertex];cambiar=false;}
else{pointer = pointer->next;}}
if(actual == 0){fin = true;}
return fin;}