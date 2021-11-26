struct stack * tablevar = NULL;
struct vardata
{
	bool ismethod;
	char value[30];
	char typev[30];
	bool matrix;
	int matrixq;
	int varq;
	char vtypev[10][100];
	int posstack;
};
struct vardata vararray[200];
int varquantity = 0;
int vqa = -1;
int varquan[100];
int searchstack(struct stack *top, string val, int pos, int scope, bool noinsert, int *y)
{
	int scope2;
	if(top == NULL)
	{
		return -2;
	}
	else
	{
		struct stack *ptr = top;
		while(ptr)
		{
			scope2 = ptr->scope;
			if(strcmp(ptr->data, val.c_str()) == 0)
			{
				if(noinsert)
				{
					*y = ptr->pos;
					return ptr->scope;
				}
				if(scope == scope2)
				{
					cout << scope << " ";
					cout << "ERROR VARIABLE YA DECLARADA ANTERIORMENTE" << endl;
					return -1;
				}
			}
			ptr = ptr->next;
		}
	}
	return -2;
}
int vardecl[100] = {0};
int scopesstack[100] = {0};
int p = 0 ;
string tp;
int funcs = 0;
multimap<string, string> posib;
char posibtypes[11][10] = {"bool", "float", "int", "int", "float", "float", "float", "int", "int", "int", "int"};
string posibilities(string tp, char val[3][15])
{
	string str1 = val[0];
	string str2 = val[1];
	int i = 0;
	for(auto itr = posib.begin(); itr != posib.end(); ++itr)
	{
		if(strcmp(itr->first.c_str(), str1.c_str()) == 0 && strcmp(itr->second.c_str(), str2.c_str()) == 0)
		{
			tp = posibtypes[i];
			return tp;
		}
		else if(strcmp(itr->first.c_str(), str2.c_str()) == 0 && strcmp(itr->second.c_str(), str1.c_str()) == 0)
		{
			tp = posibtypes[i];
			return tp;
		}
		i += 1;
	}
	tp = "notype";
	return tp;
}
bool mainf = false;
bool Uniqueness(int scope, struct tree * root, bool method, map<int, string> variables, bool error, bool wait2, int p2)
{
	char val[3][15];
	char numeros[30];
	int p = 0;
	int valnext = 0;
	struct stack * iter;
	string str;
	string str2;
	string strtype;
	bool hold = false;
	bool first = false;
	bool wait = method;
	int pos = 0;
	bool insertmethod = false;
	int postoinsert;
	int insmethod = 0;
	bool ismatrix = false;
	int mq = 0;
	int m;
	while(root)
	{
		if(root->data[0] == '{')
		{
			if(!method)
			{
				p2 = 0;
				scope += 1;
				if(scopesstack[scope] == 0)
				{
					scopesstack[scope] = 0;
				}
			}
		}
		if(root->data[0] == '}')
		{
			for(int i=0;i<vardecl[scope];i++)
			{
				tablevar = pop(tablevar);
			}
			scopesstack[scope] = 0;
			vardecl[scope] = 0;
		}
		if(root->data[0] == '(' && method)
		{
			vqa += 1;
			funcs += 1;
			scope += 1;
			insertmethod = true;
		}
		if(strcmp(root->data, "<num>") == 0 || strcmp(root->data, "<hex_digit>") == 0)
		{
			str = wordkey(variables, root->pos);
			strcpy(numeros, str.c_str());
			strcpy(root->vtype, "int");
			for(int j=0; j<strlen(numeros); j++)
			{
				if(numeros[j] == '.')
				{	
					strcpy(root->vtype, "float");
					break;
				}
			}
			root->pos = varquantity;
			vararray[varquantity].matrixq = mq;
			vararray[varquantity].ismethod = false;
			tablevar = push(tablevar, str, scope, varquantity);
			strcpy(vararray[varquantity].typev, root->vtype);
			strcpy(vararray[varquantity].value, str.c_str());
			vararray[varquantity].matrix = false;
			vararray[varquantity].varq = 0;
			vardecl[scope] += 1;
			varquantity += 1;
		}
		if(strcmp(root->data, "<id>") == 0)
		{
			str = wordkey(variables, root->pos);
			if(hold)
			{
				if(strcmp(str.c_str(), "main") == 0 && method)
				{
					if(mainf)
					{
						error = true;
						cout << "FUNCION MAIN YA DECLARADA" << endl;
						return error;
					}
					else if(root->next->next->data[0] != ')')
					{
						error = true;
						cout << "LA FUNCION MAIN NO LLEVA ARGUMENTOS" << endl;
						return error;
					}
					mainf = true;
				}
				pos = searchstack(tablevar, str, pos, scope, false, &m);
				if(pos == -2)
				{
					if(root->next->data[0] == '[')
					{
						ismatrix = true;
						str2 = wordkey(variables, root->next->next->child->pos);
						strcpy(numeros, str2.c_str());
						for(int jj=0; jj<strlen(numeros); jj++)
						{
							if(numeros[jj] == '.')
							{	
								cout << endl << "ERROR NO PUEDES ASIGNARLE UN VALOR TIPO FLOAT AL ARRAY" << endl;
								error = true;
								return error;
							}
						}
						mq = stoi(str2);
					}
					root->pos = varquantity;
					vararray[varquantity].matrixq = mq;
					strcpy(root->vtype, strtype.c_str());
					vararray[varquantity].ismethod = wait;
					strcpy(vararray[varquantity].typev, strtype.c_str());
					strcpy(vararray[varquantity].value, str.c_str());
					vararray[varquantity].matrix = ismatrix;
					if(scope > 0)
					{
						vararray[varquantity].posstack = scopesstack[scope];
					}
					else
					{
						vararray[varquantity].posstack = -1;
					}
					scopesstack[scope] += 4;
					if(scope > 0)
					{
						varquan[vqa] += 1;
					}
					mq = 0;
					if(!insertmethod && method)
					{
						postoinsert = varquantity;
					}
					if(insertmethod)
					{
						vararray[postoinsert].varq += 1;
						strcpy(vararray[postoinsert].vtypev[insmethod], strtype.c_str());
						insmethod += 1;
					}
					else
					{
						vararray[varquantity].varq = 0;
					}
					tablevar = push(tablevar, str, scope, varquantity);
					vardecl[scope] += 1;
					varquantity += 1;
					ismatrix = false;
					wait = false;
				}
				else
				{
					error = true;
					return error;
				}
			}
			else
			{
				pos = searchstack(tablevar, str, pos, scope, true, &m);
				if(pos == -2)
				{
					cout << endl << "ERROR LA VARIABLE NO HA SIDO DECLARADA" << endl;
					error = true;
					return error;
				}
				root->pos = m;
				str = vararray[m].typev;
				strcpy(root->vtype, str.c_str());
			}
		}
		if(strcmp(root->data, "<type>") == 0 || strcmp(root->data, "<void>") == 0)
		{
			hold = true;
			strtype = wordkey(variables, root->pos);
		}
		if(root->child)
		{
			if(strcmp(root->data, "<method_decl>") == 0)
			{
				error = Uniqueness(scope, root->child, true, variables, error, false, p2);
			}
			else
			{
				if(strcmp(root->data, "<expr>") == 0)
				{
					if(root->child->next)
					{
						error = Uniqueness(scope, root->child, false, variables, error, true, p2);
						if(strcmp(tp.c_str(), "notype") == 0)
						{
							cout << endl << "NO PUEDES TRABAJAR CON VALORES DE TIPO 'VOID'" << endl;
							error = true;
						}
						if(wait2)
						{
							strcpy(val[p], tp.c_str());
							p += 1;
						}
						strcpy(root->vtype, tp.c_str());
					}
					else
					{
						if(strcmp(root->child->child->data, "<bool_literal>") == 0)
						{
							strcpy(root->vtype, "bool");
							strcpy(root->child->vtype, "bool");
							strcpy(root->child->child->vtype, "bool");
							if(wait2)
							{
								strcpy(val[p], "bool");
								p += 1;
							}
						}
						else
						{
							error = Uniqueness(scope, root->child, false, variables, error, false, p2);
							str = wordkey(variables, root->pos);
							pos = searchstack(tablevar, str, pos, scope, true, &m);
							if(pos != -2)
							{
								root->pos = m;
								str = vararray[m].typev;
								strcpy(root->vtype, str.c_str());
								if(wait2)
								{
									strcpy(val[p], str.c_str());
									p += 1;
								}
							}
						}
					}
				}
				else
				{
					if(method)
					{
						error = Uniqueness(scope-1, root->child, false, variables, error, false, p2);
					}
					else
					{
						error = Uniqueness(scope, root->child, false, variables, error, false, p2);
					}
					if(strcmp(root->data, "<location>") == 0 || strcmp(root->data, "<location2>") == 0 || strcmp(root->data, "<method_call>") == 0)
					{
						str = wordkey(variables, root->pos);
						pos = searchstack(tablevar, str, pos, scope, true, &m);
						root->pos = m;
						str = vararray[m].typev;
						if(strcmp(root->data, "<method_call>") == 0)
						{
							if(vararray[m].ismethod == false)
							{
								cout << endl << "ERROR LA VARIABLE NO ES UNA FUNCION" << endl;
								error = true;
							}
						}
						else if(strcmp(root->data, "<location2>") == 0)
						{
							if(vararray[root->pos].matrix == false)
							{
								cout << endl << "ERROR ESTA VARIABLE NO FUE DECLARADA COMO ARRAY" << endl;
								error = true;
							}
							else if(strcmp(root->child->next->next->vtype, "float") == 0)
							{
								cout << endl << "ERROR NO PUEDES BUSCAR EN UN ARRAY CON UN FLOAT" << endl;
								error = true;
							}
						}
						else if(strcmp(root->data, "<location>") == 0)
						{
							if(vararray[root->pos].ismethod == true)
							{
								cout << endl << "ERROR LA VARIABLE ES UNA FUNCION, DEBES LLAMARLA COMO TAL" << endl;
								error = true;
							}
						}
						strcpy(root->vtype, str.c_str());
					}
					else if(strcmp(root->data, "<literal>") == 0 || strcmp(root->data, "<int_literal>") == 0 || strcmp(root->data, "<char_literal>") == 0)
					{
						str = wordkey(variables, root->pos);
						pos = searchstack(tablevar, str, pos, scope, true, &m);
						root->pos = m;
						str = vararray[m].typev;
						strcpy(root->vtype, str.c_str());						
					}
				}
			}
			if(error)
			{
				return error;
			}
		}
		root = root->next;
	}
	if(wait2)
	{
		if(p == 2)
		{
			tp = posibilities(tp, val);
		}
		else
		{
			tp = val[0];
		}
	}
	return error;
}

string mostrararbol(struct tree * root, int level, string str, char style[6][20])
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
        if(root->data[0] == '<' && strlen(root->data) > 2)
        {
            str2.erase(str2.begin()+strlen(root->data)-1);
            str2.erase(str2.begin());
        }
        str += " 'name': '"; str+= str2; str+= "', ";
        str += " 'title': '"; str+= root->vtype; str += "'";
        if(level != 0)
        {
            str += ", 'className': '";
            str += style[level-1];
            str += "'";
        }
        cout << "Node: " << root->vtype << endl;
        if(root->child)
        {
            str += ",\n'children' : [";
            for(int d = 0; d<level ; d++)
            {
                cout << "\t";
            }
            cout << "Children:" << endl;
			cout << root->data << endl;
            str = mostrararbol(root->child, level+1, str, style);
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
bool value = false;
string valoretorno = "notype";
bool retorno = false;
bool typecheck(struct tree * root, bool check, bool error, bool expr)
{
	string str1;
	string str2;
	int pos;
	int pos2;
	while(root)
	{
		if(strcmp(root->data, "<type>") == 0 && check)
		{
			retorno = true;
			value = true;
		}
		if(strcmp(root->data, "<id>") == 0)
		{
			if(check)
			{
				valoretorno = root->vtype;
				check = false;
			}
		}
		if(strcmp(root->data, "<for>") == 0)
		{
			str1= root->next->vtype;
			str2 = root->next->next->next->vtype;
			if(strcmp(str1.c_str(), "void") == 0 || strcmp(str2.c_str(), "void") == 0)
			{
				cout << endl << "ERROR EL VALOR ES TIPO 'VOID'" << endl;
				error = true;
				return error;
			}
			else if(strcmp(str1.c_str(), str2.c_str()) != 0)
			{
				cout << endl << "ERROR LAS VARIABLES NO SON DEL MISMO TIPO" << endl;
				error = true;
				return error;
			}
		}
		if(strcmp(root->data, "<location>") == 0 && !expr)
		{
			if(strcmp(root->child->data, "<location2>") == 0)
			{
				if(strcmp(root->child->child->next->next->vtype, "float") == 0)
				{
					cout << endl << "NO PUEDES USAR FLOAT DENTRO DE UN ARRAY PARA BUSCAR" << endl;
					error = true;
					return error;
				}
				else if(vararray[root->pos].matrix == false)
				{
					cout << endl << "ERROR ESTA VARIABLE NO FUE DECLARADA COMO ARRAY" << endl;
					error = true;
					return error;
				}
			}
			else
			{
				str1 = root->vtype;
				str2 = root->next->next->vtype;
				if(strcmp(str1.c_str(), "void") == 0 || strcmp(str2.c_str(), "void") == 0)
				{
					cout << endl << "ERROR EL VALOR ES TIPO 'VOID'" << endl;
					error = true;
					return error;
				}
				else if(strcmp(str1.c_str(), str2.c_str()) != 0)
				{
					cout << endl << "ERROR LAS VARIABLES NO SON DEL MISMO TIPO" << endl;
					error = true;
					return error;
				}
			}
		}
		if(strcmp(root->data, "<method_call>") == 0)
		{
			bool open = true;
			struct tree * ptr = root->child->next->next;
			pos = root->child->pos;
			pos2 = vararray[pos].varq;
			int move = 0;
			while(ptr)
			{
				if(ptr->data[0] == ',')
				{
					if(pos2 == 0)
					{
						error = true;
						cout << endl << "YA SE SUPERO LA CANTIDAD DE VALORES QUE PEDIA LA FUNCION" << endl;
						return error;
					}
				}
				else if(pos2 > 0 && ptr->data[0] != ')')
				{
					if(strcmp(ptr->vtype, vararray[pos].vtypev[move]) == 0)
					{
						move += 1;
						pos2 -= 1;
					}
					else
					{
						cout << endl << "AL MOMENTO DE LLAMAR LA FUNCION SE ESPERABA UN VALOR EN LA POSICION: " << move+1 << " el tipo de dato: " << vararray[pos].vtypev[move];
						error = true;
						return error;
					}
				}
				else if(ptr->data[0] == ')')
				{
					if(pos2 != 0)
					{
						cout << pos2 << endl;
						cout << endl << "LA LLAMADA A LA FUNCION ESTA INCOMPLETA, FALTAN MAS VALORES DENTRO DEL PARENTESIS" << endl;
						error = true;
						return error;
					}
					else
					{
						break;
					}
				}
				ptr = ptr->next;
			}
		}
		if(strcmp(root->data, "<return>") == 0)
		{
			retorno = false;
			if(root->next->data[0] == ';' && value)
			{
				cout << endl << "ERROR NO HAY VALOR DE RETORNO PARA LA FUNCION" << endl;
				error = true;
				return error;
			}
			else if(value)
			{
				str1 = root->next->vtype;
				if(strcmp(str1.c_str(), valoretorno.c_str()) != 0)
				{
					cout << endl << "ERROR SE ESPERABA UN VALOR DE RETORNO DE TIPO: " << valoretorno << endl;
					error = true;
					return error;
				}
			}
			else if(root->next->data[0] != ';' && !value)
			{
				cout << endl << "ERROR NO PUEDES RETORNAR UN VALOR EN UNA FUNCION TIPO 'VOID'" << endl;
				error = true;
				return error;
			}
		}
		if(root->child)
		{
			if(strcmp(root->data, "<method_decl>") == 0)
			{
				retorno = false;
				error = typecheck(root->child, true, error, false);
				if(error)
				{
					retorno = false;
				}
				if(retorno)
				{
					cout << endl << "ERROR NO HAY NINGUN 'RETURN'" << endl;
					error = true;
					return error;
				}
				value = false;
			}
			else if(strcmp(root->data, "<block>") == 0 || strcmp(root->data, "<statement>") == 0)
			{
				error = typecheck(root->child, false, error, false);
			}
			else if(strcmp(root->data, "<expr>") == 0)
			{
				error = typecheck(root->child, false, error, true);
			}
			else if(strcmp(root->data, "<program>") == 0)
			{
				error = typecheck(root->child, false, error, false);
			}
		}
		if(error)
		{
			return error;
		}
		root = root->next;
	}
	return error;
}

bool semantic(bool error)
{
	int x = 0 ;
	map<int, string> variables;
	int scope = -1;
	int tp;
	while(tok)
	{
		variables[x] = tok->data;
		tok = tok->next;
		x += 1;
	}
	string show;
	char style[6][20] = {"middle-level", "product-dept", "pipeline1", "rd-dept", "frontend1"};
	posib.insert(pair<string, string>("int", "float"));
	posib.insert(pair<string, string>("int", "bool"));
	posib.insert(pair<string, string>("int", "int"));
	posib.insert(pair<string, string>("int", "char"));
	posib.insert(pair<string, string>("float", "float"));
	posib.insert(pair<string, string>("char", "char"));
	posib.insert(pair<string, string>("bool", "bool"));
	posib.insert(pair<string, string>("bool", "float"));
	posib.insert(pair<string, string>("bool", "char"));
	posib.insert(pair<string, string>("float", "char"));
	if(!error)
	{
		error = Uniqueness(scope, root, false, variables, error, false , 0);
		if(!mainf)
		{
			error = true;
			cout << "ERROR FUNCION MAIN NUNCA FUE DECLARADA" << endl;
		}
		if(!error)
		{
			error = typecheck(root, false, error, false);
			if(!error)
			{
				cout << endl << endl << "TODO BIEN SEMANTICAMENTE";
				show = "'use strict';\n";
				show += "(function($){\n";
				show += "$(function() {\n";
				show += "var datascource = ";
				show = mostrararbol(root, 0, show, style);
				cout << endl << "SALI DEL ARBOL" << endl;
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
		}
	}
	cout << endl;
	return error;
}