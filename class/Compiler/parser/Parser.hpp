#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <map>
using namespace std;

struct tree //Estructura del arbol
{
    char data[30]; //El tipo de token, digase: id, num, arith_op, etc
    struct tree *next; // Siguiente
    struct tree *child; // Hijos
    int pos; // La posicion dentro de la tabla de simbolos donde encontramos el valor de ese token
};

struct stack // Estructura del stack
{
    char data[30]; // Valor del stack
    struct stack *next;
};

struct node3 // Nodo del grafo
{
    int vertex;
    char weight[30]; // Valor que tiene
    char name[20]; // A quien pertenece, digamos class es de <program> o return es de <statement>
    struct node3* next; // Siguiente
    int option; // Este es para denotar si el valor es opcional u obligatorio, digamos el else es opcional por ende lleva un 1 como option, 0 obligatorio
};

tree * new_nodetree(string data, int pos) // Esta funcion simplemente reserva espacio en memoria para cada nodo nuevo creado del arbol y asigna su respectivo valor
{
    tree *new_node = (struct tree*)malloc(sizeof(struct tree));

    if ( new_node ) {
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->pos = pos;
        strcpy(new_node->data, data.c_str());
    }

    return new_node;
}

tree * add_sibling(tree * n, string data, int pos) // Funcion para crear un hermano dentro del arbol
{
    if ( n == NULL )
        return NULL;

    while (n->next) //Se ejecuta este while hasta que el siguiente sea nulo para no sobreescribir algun valor
        n = n->next;

    return (n->next = new_nodetree(data, pos));
}

tree * add_child(tree * n, string data, int pos) // Funcion para crear un hijo dentro del arbol
{
    if ( n == NULL )
        return NULL;

    if ( n->child && n->child->data[0] > 0) // Si tiene hijo simplemente se le añade un hermano a ese hijo
        return add_sibling(n->child, data, pos);
    else
        return (n->child = new_nodetree(data, pos)); // De lo contrario se crea un nuevo hijo
}

struct Graph3 // Estructura del grafo
{
    int numVertices; // Numero de vertices
    struct node3** adjLists; //Una adjlist para poder acceder a ese vertice dentro del grafo
};

struct node3* createNodesp(int v) // Create un nuevo nodo para el grafo y reserva espacio en memoria para el mismo
{
    struct node3* newNode;
    newNode = (struct node3*)malloc(sizeof(struct node3));
    newNode->vertex = v;
    newNode->next = NULL;
    newNode->option = 0;
    strcpy(newNode->weight, "");
    strcpy(newNode->name, "");
    return newNode;
}
struct Graph3* createAGraphsp(int vertices) //Este crea los vertices para el grafo
{
    struct Graph3* graph = (struct Graph3*)malloc(sizeof(struct Graph3));
    graph->numVertices = vertices;
    graph->adjLists = (struct node3**)malloc(vertices * sizeof(struct node3*));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
void addEdge(struct Graph3* graph, int b, int d, const char* w, const char* t, int o) //Esta funcion añade nodos a su respectivo vertice
{
    std::string str("");
    str = w;
    struct node3* newNode = createNodesp(d);
    newNode->next = graph->adjLists[b];
    strcpy(newNode->weight, str.c_str());
    str = t;
    strcpy(newNode->name, str.c_str());
    newNode->option = o;
    graph->adjLists[b] = newNode;
}
bool other = false;
int option = 0;
struct stack *tokens = NULL;
struct stack *push(struct stack *top, string str) //Funcion del stack para hacer push
{
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    strcpy(ptr->data, str.c_str());
    if(top == NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    else
    {
        ptr -> next = top;
        top = ptr;
    }
    return top;
}
struct Graph3* words2[18];
struct stack *pop(struct stack *top) //Funcion del stack para borrar al ultimo que entro
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
    {
        cout << endl << "STACK UNDERFLOW";
    }
    else
    {
        top = top -> next;
        cout << endl << "The value being deleted is: " << ptr->data << endl;
        free(ptr);
    }
    return top;
}

const char* peek(struct stack *top) //Funcion que retorna el valor que esta en el top del stack
{
    if(top==NULL)
    {
        return 0;
    }
    else
    {
        return top->data;
    }
}
bool insertdouble = false;
int actual[6];
int dest[6];
int mapping[12] = {0};
int i = 0;
int searching = 0;
int x = 0;
bool changealternate = false;
map<string, int> check(map<string, int> locations, string father, bool create) //Se uso map como hash table para poder buscar los no terminales o meter nuevos a la hash table
{ //El objetivo de esto es optimizar el searching dentro del parser
    map<string, int>::iterator itr;
    itr = locations.find(father);
    if(itr != locations.end()) //Si encontro valor retorna la posicion en la que esta
    {
        i = itr->second;
    }
    else
    {
        if(create) //Si no crea uno si se le especifica crear, de lo contrario no creara nada, siempre retorna -1 si no encuentra valor
        {
            locations[father] = x;
            x += 1;
        }
        i = -1;
    }
    return locations;
}
bool search(char decaf[50], bool error, char simbolos[10]) //Sirve para ir recorriendo el no terminal o terminal de derecha a izquierda osea desde el ultimo caracter hasta el ultimo
{ //Esto se hace con el objetivo de ver que simbolos estan afectando ese no terminal o terminal, digase +, *, [], {}, etc, a su vez se revisa si el usuario escribio bien el <> para denotar terminal o no terminak
    int x = strlen(decaf)-1;
    string str;
    char transition[10];
    while(x != -1) //Lo recorre todo
    {
        if(decaf[x] == '>')
        {
            error = false;
            break;
        }
        else
        {
            if(decaf[x] == 125 || decaf[x] == 43 || decaf[x] == 42 || decaf[x] == 44 || decaf[x] == 93 || decaf[x] == 124) //Si es +, *, [], {}, etc lo guarda en un string y lo quita del token
            {
                str = decaf[x];
                strcat(transition, str.c_str());
                str = decaf;
                str.erase(str.begin()+x);
                strcpy(decaf, str.c_str());
            }
            else
            {
                break; //Si no tiene ninguno de esos es error y probablemente el usuario ingreso un simbolo que no existe
            }
            x -= 1;
        }
    }
    x = 0;
    for(int u=strlen(transition)-1;u>=0;u--)
    {
        str = transition[u]; //Una vez recolectados los simbolos se pasa a guardarlos en un array, si quieres saber que simbolos son permitidos, revisa la hoja de decaf
        strcat(simbolos, str.c_str());
        x += 1;
    }
    return error;
}

bool search2(char decaf[50], bool error, char simbolos[10]) //Lo mismo que el de arriba pero analiza de izquierda a derecha osea del primer al ultimo caracter
{ //Se hace con el objetivo de ver que esta afectando en la apertura, digase [], {}, etc, repite el mismo proceso
    int i = 0;
    string str;
    int large = strlen(decaf);
    while(i != large)
    {
        if(decaf[0] == '<')
        {
            error = false;
            return error;
        }
        else
        {
            if(decaf[0] == 91 || decaf[0] == 123 || decaf[0] == 44)
            {
                str = decaf[0];
                strcat(simbolos, str.c_str());
                str = decaf;
                str.erase(str.begin());
                strcpy(decaf, str.c_str());
            }
            else
            {
                return error;
            }
            i += 1;
        }
    }
    return error;
}
void sum(char decaf[50], bool nosum, char simbolos[10], int pos, string father) //Si el simbolo que afecta ese token es + o *
{
    if(nosum) //Si es nosum true significa que el simbolo que afecta ese token es *
    {
        string str = decaf;
        addEdge(words2[i], actual[option], actual[option], str.c_str(), father.c_str(), 0);
    }
    else
    {
        if(insertdouble) //Digamos salimos de un [] (que denota opcional), se inserta doble para avanzar ya sea por la opcion obligatoria u opcional
        {
            for(int h=0;h<=option;h++)
            {
                addEdge(words2[i], actual[h], actual[h]-mapping[h], ",", father.c_str(), 0);
                mapping[h] = 0;
            }
        }
        else if(other) // Si simplemente es un OR, se inserta la , para denotar un retorno a donde inicio el or, digamos con id | id[int] la , denota retorno para poner denuevo un id o un id[int]
        {
            addEdge(words2[i], actual[option], actual[option-1], ",", father.c_str(), 0);
        }
        else
        {
            addEdge(words2[i], actual[option], dest[option]-2, ",", father.c_str(), 0); // Si no hay ningun OR y simplemente el + afecta a un token, se le anade una coma para retornar al token que es afectado por +
        } //Ejemplo: <type> <id>+,   ---> Al ser solo uno afectado por , entonces al ponerla seria para poner un nuevo id
    }
}
int braces(char decaf[50], bool nobraces, char bracesstore[4][20], int pos, string father) // Funcion por si el valo es llavecita
{
    string str;
    str = decaf;
    if(strlen(decaf) > 0) //Si dentro de la llavecita hay algun valor de decaf
    {
        strcpy(bracesstore[pos], str.c_str()); // Se guarda dentro de la llavecita
        pos += 1;
    }
    if(nobraces) // Este denota cierre de llavecita, las llavecitas sirven para agrupar, si se cierra la llavecita se guarda lo que esta agrupado en el grafo de estados
    {
        for(int l=0;l<pos;l++)
        {
            if(strcmp(bracesstore[l], "|") == 0) // Si hay un OR dentro de la llavecita se aplica su respectivo branch
            {
                other = true;
                option += 1;
                actual[option] = actual[option-1]-1;
                dest[option] = dest[option-1]-1;
            }
            else
            {
                str = bracesstore[l];
                addEdge(words2[i], actual[option], dest[option], str.c_str(), father.c_str(), 0); // De lo contrario simplemente se va guardando la data
                actual[option] += 1;
                dest[option] += 1;
                mapping[option] += 1;
            }
            strcpy(bracesstore[l], ""); //Se va borrando la data del array
        }
        pos = 0;
    }
    return pos;
}
void simbology(char simbolos[10], char decaf[50], string father) // El corazon de los simbolos
{
    static int posnow = 0;
    static int posbraces = 0;
    int position = 0;
    bool act = false;
    string str;
    char complement[50];
    static char bracesstore[6][20];
    static bool nobraces = true;
    static bool nosum = false;
    bool create = true;
    if(strlen(decaf) > 0) // Si viene algun token de decaf se activa act
    {
        act = true;
    }
    int limite = strlen(simbolos);
    while(position != limite && limite > 0) // Este es para entrar a un while si existen simbolos y el while dura hasta que recorra todos los simbolos
    {
        act = false;
        switch(simbolos[position])
        {
            case '[': //Case si viene un [ que denota apertura, todo lo que entre ahi es opcional
                other = true;
                option += 1;
                actual[option] = actual[option-1];
                dest[option] = dest[option-1];
                act = true;
                if(simbolos[position+1] == ',') //Hay casos donde una , acompana al [, se le anade al grafo de estados
                {
                    strcpy(complement, ",");
                    other = false;
                    posbraces = braces(complement, nobraces, bracesstore, posbraces, father);
                    act = false;
                    position += 1;
                }
                break;
            case ']': //Denota cierre de opciona, obviamente al ser cierre de opciona lo siguiente que venga deberia ser insertado doble, y si aun no se ha metido lo de decaf al grafo se avisa haciendo act como true
                if(strlen(decaf) > 0 && other)
                {
                    act = true;
                }
                insertdouble = true;
                break;
            case '+': // Denota una o mas producciones
                nosum = false;
                if(strlen(decaf) > 0) // Si hay data primero se inserta para luego afectarla
                {
                   posbraces = braces(decaf, nobraces, bracesstore, posbraces, father);
                }
                if(position == 0 && other) // Si hay un OR y el + es lo primero que viene, se cierra ya que las producciones en el if anterior fueron afectadas
                {
                    other = false;
                }
                sum(decaf, nosum, simbolos, position, father); // Se entra a su respectivo funcion y se quita el other (OR) osea se pone como false
                position += 1;
                other = false;
                strcpy(decaf, "");
                act = false;
                break;
            case '*': // En dado caso viniera asterisco
                nosum = true;
                sum(decaf, nosum, simbolos, position, father);
                strcpy(decaf, "");
                act = false;
                break;
            case '{': // Viene llavecita denota apertura y si hay data en decaf se guarda en el array del brace
                nobraces = false;
                posbraces = braces(decaf, nobraces, bracesstore, posbraces, father);
                strcpy(decaf, "");
                act = false;
                break;
            case '}': // Si viene llavecita de cierre se denota
                nobraces = true;
                posbraces = braces(decaf, nobraces, bracesstore, posbraces, father);
                strcpy(decaf, "");
                if((((position+3) == limite) || (position+1) == limite) && other) // Si en dado caso hay algun other y ya se inserto la data se quita
                {
                    other = false;
                    insertdouble = true;
                }
                break;
            case '|': //Denota OR
                other = true;
                option += 1;
                actual[option] = actual[option-1]-1;
                dest[option] = dest[option-1]-1;
                if(!nobraces) // Si en dado caso el OR esta dentro de las llavecitas se quita y se guarda en las llavecitas ya que una vez dentro de las mismas se activara
                {
                    strcpy(complement, "|");
                    option -= 1;
                    posbraces = braces(complement, nobraces, bracesstore, posbraces, father);
                    other = false;
                }
                break;
        }
        position += 1; // Se avanza dentro de simbolos
    }
    if(act) // Si en dado caso no se ha insertado la data de decaf
    {
        if(!nobraces) //Este es si las llavecitas aun siguen abiertas
        {
            posbraces = braces(decaf, nobraces, bracesstore, posbraces, father);
            create = false;
        }
        if(other) //Si hay algun OR activado
        {
            if(changealternate) //Este es para denotar un valor como OPCIONAL
            {
                searching += 1;
            }
            if(simbolos[strlen(simbolos)-1] == ']') // Si el ultimo simbolo es ] se desactiva el other osea el OR
            {
                other = false;
            }
            str = decaf;
            addEdge(words2[i], actual[option], dest[option], str.c_str(), father.c_str(), searching);
            actual[option] += 1;
            dest[option] += 1;
            create = false;
        }
        if(create) //Create es true si no entro a ninguno de los if anteriores osea aun no se inserto la data de decaf
        {
            if(insertdouble) // Si venimos de cerrar algun OR lo siguiente que venga se debe insertar dentro del OR y dentro de la otra alternativa
            {
                int end = dest[option];
                str = decaf;
                for(int y=0;y<=option;y++)
                {
                    addEdge(words2[i], actual[y], end, str.c_str(), father.c_str(), 0);
                    actual[y] = end;
                    dest[y] = end+1;
                }
                insertdouble = false;
                option = 0;
            }
            else // Si no hay OR simplemente se inserta normal
            {
                str = decaf;
                addEdge(words2[i], actual[option], dest[option], str.c_str(), father.c_str(), 0);
                if(dest[option]-actual[option] >= 2) // Casos donde separamos la data, si vamos a seguir insertado retornamos la distancia a solo 1
                {
                    actual[option] = dest[option]-1;
                }
                actual[option] += 1; //Es para avanzar dentro de la gramatica
                dest[option] += 1;
            }
        }
    }
}

void ToDo(char decaf[50], string father, map<string, int> locations) //Funcion para ir separando simbolos de tokens
{
    bool error = true;
    char simbolos[10];
    strcpy(simbolos, "");
    string str;
    if(i == -1) //Si no hay un noterminal definido se busca o se crea uno
    {
        locations = check(locations, father, true);
    }

    if(decaf[0] == 93 || decaf[0] == 125 || decaf[0] == 124) //Si viene algun simbolo antes de las letras
    {
        error = search(decaf, error, simbolos);
        error = false;
    }

    if(decaf[0] == 91 || decaf[0] == 123) // Lo mismo pero con otros simbolo
    {
        error = search2(decaf, error, simbolos);
    }
    if(decaf[0] == '<') //Si no hay simbolos de apertura se busca al final solo para verificar
    {
        error = search(decaf, error, simbolos);
        if(error)
        {
            return;
        }
    }
    if(decaf[0] == 39) //Si viene alguna comilla para denotar que el simbolo que venga debe ser insertado
    {
        if((decaf[1] == 91 || decaf[1] == 123 || decaf[1] == 93 || decaf[1] == 125) && decaf[2] == 39 && strlen(decaf) == 3) //Se realizan sus verificiaciones correspondientes
        { //Revisar hoja de decaf en la parte de simbologia para entender un poco mas esto
            str = decaf;
            str.erase(str.begin());
            str.erase(str.begin()+1);
            strcpy(decaf, str.c_str());
        }
        else
        {
            error = true;
            return;
        }
    }
    simbology(simbolos, decaf, father); //Una vez ya se separo y limpio toda la data ya se entra al simbology con sus respectivos switch cases
}
int m = 0;
bool doit = false;
tree *root;
struct stack * store = NULL;
string wordkey(map<int, string> key, int pos) //Es una hash table para los tokens y poder tener un buen searching
{
    string str;
    map<int, string>::iterator itr;
    itr = key.find(pos);
    if(itr != key.end()) //Si existe retorna el string con ese valor sino lo retorna vacio
    {
        str = itr->second;
    }
    return str;
}

void read(struct nodelink *store, struct tree * root, map<string, int> locations, bool search, int o, string w) //Para crear el arbol con su respectivo shift y reduce
{
    string words;
    string str;
    int x;
    int u;
    if(!store)
    {
        return;
    }
    if(search)
    {
        while(root->next)
        {
            root = root->next;
        }
        words = store->data;
        store = store->next;
        x = stoi(store->data);
        store = store->next;
        while(true)
        {          
            if(strcmp(words.c_str(), "reduce") == 0)
            {
                words = store->data;
                store = store->next;
                if(x == o && strcmp(words.c_str(), w.c_str()) == 0)
                {
                    break;
                }
            }
            words = store->data;
            store = store->next;
            x = stoi(store->data);
            store = store->next;  
        }
    }
    while(store)
    {
        i = -1;
        words = store->data;
        if(strcmp(words.c_str(), "reduce") == 0)
        {
            break;
        }
        store = store->next;
        x = stoi(store->data);
        store = store->next;
        add_child(root, words, x);
        check(locations, words, false);
        if(i != -1)
        {
            read(store, root->child, locations, true, x, words);
        }
    }
}

bool action(map<string, int> locations, int pos, bool fail, int n, int ini, map<int, string> keywords)
{ //Aqui es donde empieza la recursion, se comparan todos los tokens con todos los noterminales y sus items respectivos
    string value;
    bool move = false;
    int compare = 0;
    int advance = 0;
    int advance2 = 0;
    bool prove = false;
    bool before = false;
    bool hold = false;
    const char* oki;
    int words = 0;
    int current = m;
    bool cont = false;
    string name;
    struct node3* tempv;
    struct node3* temp = words2[pos]->adjLists[0];
    struct node3* temp2;
    value = wordkey(keywords, m);
    while(temp)
    {
        if(strcmp(temp->weight, value.c_str()) == 0) // Si hace match se activa move que denota shift
        {
            move = true;
            cont = false;
            hold = false;
        }
        else if(temp->weight[0] == '<') //Si es un no terminal o terminal se entra aca
        {
            if(advance != advance2) //Si ese noterminal dio fail como output advance valdra mas de 1 y se sumara para denotar que no entre ahi
            {
                advance2 += 1;
            }
            else
            {
                locations = check(locations, temp->weight, false);
                if(strcmp(temp->weight, temp->name) == 0 && compare == 0) //Esta funciona es para evitar la recursion infinita
                {
                    if(doit)
                    {
                        i = -1;
                        doit = false;
                        ini -= 1;
                    }
                    else
                    {
                        doit = true;
                        cont = true;
                        tempv = temp->next;
                    }
                }
                if(i != -1) //Si el valor es un noterminal la i no sera -1
                {
                    fail = action(locations, i, fail, 0, ini+1, keywords); //Entrara a las producciones de ese no terminal y repetira el proceso
                    value = wordkey(keywords, m);
                    while(temp->vertex == compare && !fail) //Si ese no terminal esta denotado por * o + y si hizo match una vez, se vuelve a revisar no sea que haya aun mas tokens para hacer nuevos match
                    {
                        words += 1;
                        locations = check(locations, temp->weight, false);
                        fail = action(locations, i, fail, 0, ini+1, keywords);
                        value = wordkey(keywords, m);
                        if(fail) //Si falla se sale de ese no terminal, se reinicia en ese vertice y se le suma 1 al advance para denotar que ya no vuelva a entrar a ese noterminal
                        {
                            before = true;
                            temp = words2[pos]->adjLists[compare];
                            advance += 1;
                            advance2 = 0;
                            hold = true;
                            break;
                        }
                    }
                    if(!fail)
                    { // Si no falla se suma 1 a words y se regresa al while para volver a comparar
                        words += 1;
                        hold = true;
                        move = true;
                    }
                }
            }
        }
        if(move)
        {
            if(!hold) //Hay veces donde no se mete al stack ya que dentro de la recursion a veces ya guardo los tokens no tiene sentido guardarlos 2 veces
            {
                tokens = push(tokens, value);
                tokens = push(tokens, to_string(m));
                m += 1;
                words += 1;
            }
            hold = false;
            move = false;
            name = temp->name;
            if(m != totalnodes) //Mientras aun existan valores dentro de la linkedlist se buscara en su hash table para seguir avanzando
            {
                value = wordkey(keywords, m);
            }
            int k = temp->option;
            compare = temp->vertex;
            temp2 = words2[pos]->adjLists[temp->vertex];
            temp = words2[pos]->adjLists[temp->vertex];
            while(temp2) //Este solo es para ver si aun existen valores dentro de esa produccion
            {
                if(temp2->option == 0 || strcmp(temp2->weight, value.c_str()) == 0 || k == 1)
                {
                    prove = false;
                    break;
                }
                prove = true;
                temp2 = temp2->next;
            }
            if(!temp || prove) //Si ya no existen simplemente se hace el reduce
            {
                int y = 0;
                int y2;
                string st;
                cout << endl;
                cout << "DELETING FOR INSERTING: " << ini << " " << words+n << endl;
                for(int f=0;f<words+n;f++)
                {
                    st = peek(tokens);
                    y = stoi(st);
                    store = push(store, st); //Se guarda el historial en otro stack para crear el arbol luego
                    tokens = pop(tokens); //Se borra los tokens en el stack de tokens
                    st = peek(tokens);
                    tokens = pop(tokens);
                    store = push(store, st);
                }
                cout << "INSERTING: " << name << endl;
                tokens = push(tokens, name);
                tokens = push(tokens, to_string(y)); //Se inserta el nuevo noterminal por el que hizo match
                store = push(store, name);
                st = to_string(y);
                store = push(store, st);
                store = push(store, "reduce");
                fail = false;
                return fail;
            }
        }
        else
        {
            if(!before) //Si en dado caso no hizo match en alguna produccion y hay mas, se retorna al inicio y se avanza para seguir comparando con las demas
            {
                temp = temp->next;
                if(compare > 0 && cont)
                {
                    temp = tempv;
                    cont = false;
                    m -= 1;
                    tokens = pop(tokens); //Se borran sus datos del stack de tokens
                    tokens = pop(tokens);
                    store = pop(store); //Se borra la data del stack de historial
                    store = pop(store);
                    store = pop(store);
                    store = pop(store);
                    store = pop(store);
                    words -= 1;
                    value = wordkey(keywords, m);
                }
            }
            before = false;
        }
    }
    m = current;
    fail = true;
    for(int b=0;b<words;b++)
    {
        tokens = pop(tokens);
        tokens = pop(tokens);
    }
    return fail;
}

string printtree(struct tree * root, int level, string str, char style[6][20]) //Funcion para mostrar arbol en la terminal e insertarlo en el html
{
    string str2;
    if(level == 0)
    {
        str += "\n{\n";
    }
    while(root)
    {
        if(level == 6)
        {
            level = 1;
        }
        if(level != 0)
        {
            str += "\n{\n";
        }
        for(int i = 0; i<level ; i++)
        {
            cout << "\t";
        }
        str2 = root->data;
        if(root->data[0] == '<')
        {
            str2.erase(str2.begin()+strlen(root->data)-1);
            str2.erase(str2.begin());
        }
        str += " 'name': '"; str+= str2; str+= "', ";
        str += " 'title': '" + to_string(root->pos) + "'";
        if(level != 0)
        {
            str += ", 'className': '";
            str += style[level-1];
            str += "'";
        }
        cout << "Node: " << root->data << endl;
        if(root->child)
        {
            str += ",\n'children' : [";
            for(int d = 0; d<level ; d++)
            {
                cout << "\t";
            }
            cout << "Children:" << endl;
            str = printtree(root->child, level+1, str, style);
            str += "\n]";
            str += "\n}";
            if(root->next)
            {
                str += ",";
            }
        }
        else if(level != 0)
        {
            str += "},\n";
        }
        root = root->next;
    }
    return str;
}

void parser() //Funcion del parser
{
    for(int t=0;t<18;t++) //Se crea la coleccion de grafos
    {
        words2[t] = createAGraphsp(19);
        if(t == 5)
        {
            words2[t] = createAGraphsp(30);
        }
    }
    ifstream structure("parser/data/Estructura.txt");
    char decaf[30];
    string father("");
    char grammar[300];
    map<string, int> locations;
    string current;
    bool starting = false;
    char *ptr;
    bool fail = true;
    while(!structure.eof()) //Estara en este while hasta que haya leido toda la gramatica de decaf
    {
        other = false;
        starting = true;
        insertdouble = false;
        getline(structure, current);
        strcpy(grammar, current.c_str());
        ptr = strtok(grammar, " ");
        searching = 0;
        while(ptr != NULL) //Va separando cada linea por palabras para poder analizar mas facilmente
        {
            strcpy(decaf, (const char*)ptr);
            if(starting)
            {
                if(decaf[0] == '<' && decaf[strlen(decaf)-1] == '>') //Si es un noterminal se entra aca
                {
                    option = 0;
                    changealternate = false;
                    mapping[0] = 0;
                    actual[option] = 0;
                    dest[option] = 1;
                    father = decaf;
                    starting = false;
                    locations = check(locations, father, true);
                }
                else if(decaf[0] == '|') //Si viene de primero un OR se entra aca para preparar al compilador para eso
                {
                    actual[0] = 0;
                    dest[0] = dest[option];
                    option = 0;
                    changealternate = true;
                    starting = false;
                }
            }
            else if(strcmp(decaf, "->") != 0) //Se omite ->
            {
                ToDo(decaf, father, locations);
            }
            ptr = strtok(NULL, " "); //Se separan las palabras por espacios
        }
    }
    structure.close(); //Se cierra el .txt una vez terminamos
    string s;
    struct nodelink* p = tok;
    s = p->t;
    map<int, string> keywords;
    keywords[0] = s;
    p = p->next;
    char style[6][20] = {"middle-level", "product-dept", "pipeline1", "rd-dept", "frontend1"};
    while(p) //Se guardan los valores de la linkedlist en una hash table
    {
        s = p->t;
        if(strcmp(p->t, "Comment") != 0)
        {
            keywords[totalnodes] = s;
            totalnodes += 1;
        }
        p = p->next;
    }
    fail = action(locations, 0, fail, 0, 0, keywords); //Para entrar a la parte donde una vez tenemos el grafo de estados se empieza a hacer recursion y a revisar
    int x = 0;
    cout << endl;
    string str;
    string str2;
    if(!fail) //Si al final hizo match al 100% con la gramatica entra aca donde simplemente se crea el arbol y el html
    {
        struct nodelink* tok2 = NULL;
        int g = 0;
        while(store)
        {
            tok2 = Insertar(tok2, store->data, "");
            store = store->next;
        }
        root = new_nodetree("<program>", 0);
        tok2 = tok2->next;
        tok2 = tok2->next;
        tok2 = tok2->next;
        cout << endl;
        cout << endl;
        read(tok2, root, locations, false, 0, "");
        string show = "'use strict';\n";
        show += "(function($){\n";
        show += "$(function() {\n";
        show += "var datascource = ";
        show = printtree(root, 0, show, style);
        show += ";\n";
        show += "var oc = $('#chart-container').orgchart({\n";
        show += "'data' : datascource,\n";
        show += "'nodeContent': 'title'\n";
        show += "});\n";
        show += "});\n";
        show += "})(jQuery);\n";
        ofstream script("parser/src/script.js");
        script << show;
        script.close();
    }
    else //Si en dado caso hay algun error en la gramatica tira error en la terminal
    {
        printf("\nERROR SINTACTICO, REVISA TU CODIGO EN SUS RESPECTIVAS LINEAS PARA PODER CORREGIR TUS ERRORES :)");
    }
}