int _td = 0;
int _if = -1;
int _et = -1;
int _for = -1;
int delstack = 0;
int _move = 0;
bool _assigna = false;
bool noarith = false;
bool _main2 = false;
bool change = false;
string expr(string code, struct tree * root, int quantity, string str, bool b_o, bool _f);
string block(string code, struct tree * root);
string etiquetas[100];
string field_decl(string code, struct tree * root)
{
	while(root)
	{
		if(strcmp(root->data, "<id>") == 0)
		{
			code += "\n\t";
			code += vararray[root->pos].value;
			code += ": ";
			if(vararray[root->pos].matrix)
			{
				code += ".space ";
				code += to_string(vararray[root->pos].matrixq*4);
			}
			else
			{
				code += ".word 0";
			}
		}
		root = root->next;
	}
	return code;
}

string var_decl(string code, struct tree * root)
{
	while(root)
	{
		if(strcmp(root->data, "<id>") == 0)
		{
			code += "\n\taddi $sp, $sp, -4";
			delstack += 1;
		}
		root = root->next;
	}
	return code;
}
string location(string str, struct tree * root)
{
	if(strcmp(root->data, "<id>") == 0)
	{
		str += "\n\tlw $t2, ";
		if(vararray[root->pos].posstack != -1)
		{
			str += to_string(vararray[root->pos].posstack);
			str += "($sp)";
		}
		else
		{
			str += vararray[root->pos].value;
		}
	}
	else
	{
		root = root->child;
		//Aqui str ira expr

	}
	return str;
}
string method_call(string code, struct tree * root, bool r)
{
	int x = root->pos;
	int y = 0;
	int m = -1;
	bool move = true;
	string str;
	struct tree * ptr = root;
	ptr = ptr->next->next;
	root = root->next->next;
	_td = 0;
	while(root && root->data[0] != ')' && move)
	{
		m += 1;
		code += expr(code, root->child, 0, str, false, false);
		root = root->next->next;
		code += "\n\tmove $a";
		code += to_string(m);
		code += ", $t0";
		code += "\n\taddi $t0, $zero, 0";
	}
	code += "\n\tjal ";
	code += vararray[x].value;
	if(r)
	{
		code += "\n\tadd $t0, $zero, $v1";
	}
	return code;
}

string literal(string code, struct tree * root)
{
	if(strcmp(root->data, "<bool_literal>") == 0)
	{
		if(strcmp(root->child->data, "<true>") == 0)
		{
			code += "\n\tli $t2, 1";
		}
		else
		{
			code += "\n\tli $t2, 0";
		}
	}
	
	else if(strcmp(root->data, "<char_literal>") == 0)
	{

	}
	
	else if(strcmp(root->data, "<int_literal>") == 0)
	{
		code += "\n\tli $t2, ";
		code += vararray[root->pos].value;
	}
	return code;
}

string arith_op(string code, struct tree * root)
{
	switch(root->data[0])
	{
		case '+':
			code += "\n\tadd $t";
			code += to_string(_td);
			code += ", $t";
			code += to_string(_td);
			code += ", $t2";
			break;
		
		case '-':
			code += "\n\tsub $t";
			code += to_string(_td);
			code += ", $t";
			code += to_string(_td);
			code += ", $t2";
			break;
		
		case '*':
			code += "\n\tmul $t";
			code += to_string(_td);
			code += ", $t";
			code += to_string(_td);
			code += ", $t2";
			break;
		
		case '/':
			code += "\n\tdiv $t0, $t1";
			code += "\n\tmflo $t0";
			_td += 1;
			break;
		
		case '%':
			code += "\n\tdiv $t0, $t1";
			code += "\n\tmfhi $t0";
			_td += 1;
			break;
	}
	return code;
}

string rel_op(string code, struct tree * root, bool _f)
{
	noarith = true;
	_td = 1;
	if(strcmp(root->data, "<=") == 0)
	{
		if(change)
		{
			code += "\n\tbgt $t0, $t1, ";
		}
		else
		{
			code += "\n\tble $t0, $t1, ";
		}
	}
	else if(strcmp(root->data, ">=") == 0)
	{
		if(change)
		{
			code += "\n\tblt $t0, $t1, ";
		}
		else
		{
			code += "\n\tbge $t0, $t1, ";
		}		
	}
	else if(root->data[0] == '<')
	{
		if(change)
		{
			code += "\n\tbge $t0, $t1, ";
		}
		else
		{
			code += "\n\tblt $t0, $t1, ";	
		}
	}
	else if(root->data[0] == '>')
	{
		if(change)
		{
			code += "\n\tble $t0, $t1, ";
		}
		else
		{
			code += "\n\tbgt $t0, $t1, ";	
		}
	}
	if(_f)
	{
		code += "GO";
		code += to_string(_if);
	}
	else
	{
		code += "IF";
		code += to_string(_if+1);
	}
	return code;
}

string eq_op(string code, struct tree * root, bool _f)
{
	noarith = true;
	_td = 1;
	if(strcmp(root->data, "==") == 0)
	{
		if(change)
		{
			code += "\n\tbne $t0, $t1, ";
		}
		else
		{
			code += "\n\tbeq $t0, $t1, ";	
		}
	}
	else
	{
		if(change)
		{
			code += "\n\tbeq $t0, $t1, ";	
		}
		else
		{
			code += "\n\tbne $t0, $t1, ";	
		}
	}
	if(_f)
	{
		code += "GO";
		code += to_string(_if);
	}
	else
	{
		code += "IF";
		code += to_string(_if+1);
	}
	return code;
}

string bin_op(string code, struct tree * root, bool _f)
{
	if(strcmp(root->data, "<arith_op>") == 0)
	{
		code += arith_op(code, root->child);
	}
	
	else if(strcmp(root->data, "<rel_op>") == 0)
	{
		code += rel_op(code, root->child, _f);
	}
	
	else if(strcmp(root->data, "<eq_op>") == 0)
	{
		code += eq_op(code, root->child, _f);
	}
	
	else
	{

	}
	return code;
}

string expr(string code, struct tree * root, int quantity, string str, bool b_o, bool _f)
{
	string str2;
	string str3;
	string str5;
	string str4;
	while(root)
	{
		if(strcmp(root->data, "<location>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A LOCATION EN EXPR" << endl;
			cin.ignore();
			code = location(code, root->child);
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<method_call>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A METHOD_CALL EN EXPR" << endl;
			cin.ignore();
			code = method_call(code, root->child, true);
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<literal>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A LITERAL EN EXPR" << endl;
			cin.ignore();
			code = literal(code, root->child);
			str5 += code;
			code = "";
		}

		else if(root->data[0] == '-')
		{

		}

		else if(root->data[0] == '!')
		{

		}

		else if(root->data[0] == '(')
		{
			cout << "ESTOY A PUNTO DE ENTRAR A PARENTESIS EN EXPR" << endl;
			cin.ignore();
			code = expr(code, root->next->child, -1, str3, b_o, _f);
			str5 += code;
			code = "";
			root = root->next->next;
			str3 = "";
		}

		else if(strcmp(root->data, "<expr>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A EXPR EN EXPR " << quantity << endl;
			cin.ignore();
			code = expr(code, root->child, quantity+1, str, b_o, _f);
			str5 += code;
			code = "";
			if(b_o)
			{
				str5 += str;
				str = "";
				b_o = false;
			}
			cout << code << endl;
			if(root->next)
			{
				str = bin_op(str, root->next->child, _f);
				b_o = true;
			}
			code = expr(code, root->next->next->child, 2, str, b_o, _f);
			root = root->next->next;
			str5 += code;
			if(strcmp(root->child->data, "<expr>") != 0)
			{
				cout << "ENTRE A NULL AL FINAL EXPR" << endl;
				str5 += str;
				str = "";
			}
			quantity = 1;
			code = "";
		}
		root = root->next;
	}
	if(quantity == 0)
	{
		str5 += "\n\tadd $t";
		str5 += to_string(_td);
		str5 += ", $t";
		str5 += to_string(_td);
		str5 += ", $t2";
	}
	if(noarith)
	{
		str5 += "\n\tadd $t";
		str5 += to_string(_td);
		str5 += ", $t";
		str5 += to_string(_td);
		str5 += ", $t2";
		noarith = false;		
	}
	cout << "ESTOY SALIENDO DE EXPR" << endl;
	cin.ignore();
	return str5;
}


string assign_op(string code, tree * root, int x, char value[30])
{
	cout << "ESTOY A PUNTO DE ENTRAR A assign_op" << endl;
	cin.ignore();
	if(root->data[0] == '=')
	{
		code += "\n\t sw $t0, ";
		if(x != -1)
		{
			code += to_string(x);
			code += "($sp)";
		}
		else
		{
			code += value;
		}
	}
	
	else if(strcmp(root->data, "-=") == 0)
	{
		code += "\n\tlw $t5, ";
		if(x != -1)
		{
			code += to_string(x);
			code += "($sp)";
		}
		else
		{
			code += value;
		}
		code += "\n\tsub $t5, $t5, $t0";
		code += "\n\tsw $t5, ";
		if(x != -1)
		{
			code += to_string(x);
			code += "($sp)";
		}
		else
		{
			code += value;
		}
	}			
	
	else if(strcmp(root->data, "+=") == 0)
	{
		code += "\n\tlw $t5, ";
		if(x != -1)
		{
			code += to_string(x);
			code += "($sp)";
		}
		else
		{
			code += value;
		}
		code += "\n\tadd $t5, $t5, $t2";
		code += "\n\tsw $t5, ";
		if(x != -1)
		{
			code += to_string(x);
			code += "($sp)";
			code += "\n\tadd $t2, $zero, $t2";
		}
		else
		{
			code += value;
		}
	}
	return code;
}

string statement(string code, struct tree * root)
{
	int x = _et;
	int y = 0;
	int m = 0;
	int a = 0;
	int addr;
	string str;
	string str2;
	string str3;
	string str4;
	string str5;
	string str6;
	while(root)
	{
		if(strcmp(root->data, "<block>") == 0)
		{
			code = block(code, root->child);
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<location>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A LOCATION EN STATEMENT" << endl;
			cin.ignore();
			code = expr(code, root->next->next->child, -1, str, false, false);
			while(_td != -1)
			{
				str5 += "\n\taddi $t";
				str5 += to_string(_td);
				str5 += ", $zero, 0";
				_td -= 1;
			}
			_td = 0;
			cout << "LUEGO DE EXPR EN LOCATION" << code << endl << endl;
			str5 += code;
			code = "";
			code = assign_op(code, root->next->child, vararray[root->pos].posstack, vararray[root->pos].value);
			str5 += code;
			while(_td != -1)
			{
				str5 += "\n\taddi $t";
				str5 += to_string(_td);
				str5 += ", $zero, 0";
				_td -= 1;
			}
			_td = 0;
			code = "";
			if(vararray[root->pos].matrix)
			{
				code = location(code, root->child);
				str5 += code;
				code = "";
			}
			root = root->next->next->next;
		}
		
		else if(strcmp(root->data, "<method_call>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A METHOD_CALL EN STATEMENT" << endl;
			cin.ignore();
			code = method_call(code, root->child, false);
			str5 += code;
			code = "";
			root = root->next;
		}
		
		else if(strcmp(root->data, "<if>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A IF EN STATEMENT" << endl;
			cin.ignore();
			code = expr(code, root->next->next->child, -1, str, false, false);
			root = root->next->next->next->next;
			str5 += code;
			while(_td != -1)
			{
				str5 += "\n\taddi $t";
				str5 += to_string(_td);
				str5 += ", $zero, 0";
				_td -= 1;
			}
			_td = 0;
			code = "";
			x += 1;
			_if += 1;
			y = _if;
			str6 += "\nIF";
			str6 += to_string(y);
			str6 += ":";
			str3 = block(str3, root->child);
			str3 += "\nGO";
			str3 += to_string(y);
			str3 += ":";
			if(root->next && strcmp(root->next->data, "<else>") == 0)
			{
				root = root->next->next;
				str4 += block(str4, root->child);
				str4 += "\n\tj GO";
				str4 += to_string(y);
			}
			else
			{
				str4 += "\n\tj GO";
				str4 += to_string(y);
			}
			code += str4;
			code += str6;
			str6 = "";
			code += str3;
			str4 = "";
			str3 = "";
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<for>") == 0)
		{
			change = true;
			cout << "ESTOY A PUNTO DE ENTRAR A FOR EN STATEMENT" << endl;
			cin.ignore();
			root = root->next;
			addr = vararray[root->pos].posstack;
			root = root->next->next;
			code = expr(code, root->child, -1, str, false, true);
			str5 += code;
			code = "";
			code += "\n\tsw $t2, ";
			_if += 1;
			a = _if;
			code += to_string(addr);
			code += "($sp)";
			code += "\nFOR";
			code += to_string(a);
			code += ":";
			root = root->next->next;
			str5 += code;
			code = "";
			code = expr(code, root->child, -1, str, false, true);
			str5 += code;
			code = "";
			root = root->next;
			change = false;
			code = block(code, root->child);
			code += "\n\tj FOR";
			code += to_string(a);
			code += "\nGO";
			code += to_string(a);
			code += ":";
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<return>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A RETURN EN STATEMENT" << endl;
			cin.ignore();
			if(strcmp(root->next->data, "<expr>") == 0)
			{
				code = expr(code, root->next->child, 0, str, false, false);
				code += "\n\tadd $v1, $zero, $t";
				code += to_string(_td);
				root = root->next->next;
			}
			else
			{
				root = root->next;
			}
			code += "\n\taddi $sp, $sp, ";
			code += to_string(delstack*4);
			delstack = 0;
			if(_main2)
			{
				code += "\n\tli $v0, 10";
				code += "\n\tsyscall";
			}
			else
			{
				code += "\n\tjr $ra";
			}
			str5 += code;
			code = "";
		}
		
		else if(strcmp(root->data, "<break>") == 0)
		{
			_if += 1;
			code += "\n\tj GO";
			code += to_string(_if);
			str5 += code;
			code = "";
		}

		else if(strcmp(root->data, "<expr>") == 0)
		{
			cout << "ESTOY A PUNTO DE ENTRAR A EXPR EN STATEMENT" << endl;
			cin.ignore();
			code = expr(code, root->child, 0, str, false, false);
			str5 += code;
			code = "";
		}
		root = root->next;
	}
	cout << "ESTOY SALIENDO DE STATEMENT" << endl;
	cin.ignore();
	return str5;
}

string block(string code, struct tree * root)
{
	string str;
	int m = 0;
	while(root)
	{
		if(root->child)
		{
			if(strcmp(root->data, "<statement>") == 0)
			{
				if(_assigna)
				{
					while(m != _move)
					{
						str += "\n\tsw $a";
						str += to_string(m);
						str += ", ";
						str += to_string(m*4);
						str += "($sp)";
						m += 1;
					}
					_move = 0;
					_assigna = false;
				}
				cout << "ESTOY A PUNTO DE ENTRAR A statement" << endl;
				cin.ignore();
				code = statement(code, root->child);
				str += code;
				code = "";
			}
			else
			{
				cout << "ESTOY A PUNTO DE ENTRAR A VAR_DECL" << endl;
				cin.ignore();
				code = var_decl(code, root->child);
				str += code;
				code = "";
			}
		}
		root = root->next;
	}
	return str;
}
string method_decl(string code, struct tree * root)
{
	bool _name = false;
	string str;
	int x = 0;
	while(root)
	{
		if(strcmp(root->data, "<id>") == 0)
		{
			if(!_name)
			{
				cout << "ENTRE A !NAME" << endl;
				cin.ignore();
				code += "\n";
				code += vararray[root->pos].value;
				code += ":";
				if(strcmp(vararray[root->pos].value, "main") != 0)
				{
					code += "\n\taddi $sp, $sp, -4";
					delstack += 1;
				}
				else
				{
					_main2 = true;
				}
				str += code;
				code = "";
				_name = true;
			}
			else
			{
				code += "\n\taddi $sp, $sp, -4";
				delstack += 1;
				_assigna = true;
				_move += 1;
				str += code;
				code = "";
			}
		}
		if(root->child)
		{
			code = "";
			code += block(code, root->child);// Vamos a ir metiendolo en un array de strings para luego empezar del ultimo al primero
			str += code;
			code = "";
			cout << "ESTOY A PUNTO DE ENTRAR A BLOCK" << endl;
			cin.ignore();
		}
		root = root->next;
	}
	return str;
}

void IrtCreated(string code, struct tree * root)
{
	bool _text = false;
	string _code;
	string str;
	string str7;
	int x;
	str7 += ".data";
	string array[3];
	string str10;
	ofstream c("codegen/data/codegen.a");
	while(root)
	{
		if(root->child)
		{
			if(strcmp(root->data, "<method_decl>") == 0)
			{
				if(!_text)
				{
					str7 += "\n.text";
					_text = true;
				}
				_et += 1;
				x = _et;
				cout << "ESTOY A PUNTO DE ENTRAR A METHOD_DECL" << endl;
				cin.ignore();
				delstack = 0;
				str = method_decl(_code, root->child);	// Aqui va a ir el array de strings
				_code += str;
				cout << "EL CODIGO ACTUAL ES: \n" << _code << endl;
				cout << "ACA TERMINA XDXD " << endl;
				if(x == 1)
				{
					array[x] += str7;
					array[x] += _code;
				}
				else
				{
					array[x] = _code;
				}
				int u = x;
				while(u != -1 && _main2)
				{
					str10 += array[u];
					u -= 1;
				}
				c << str10;
				cout << x << endl;
				cout << " " << _et << endl;
				_code = "";
				str = "";
			}
			else if(strcmp(root->data, "<field_decl>") == 0)
			{
				code = field_decl(code, root->child);
				str7 += code;
				cout << "ESTOY A PUNTO DE ENTRAR A FIELD_DECL" << endl;
				cin.ignore();
			}
		}
		root = root->next;
	}
	c.close();
}

void Irt()
{
	string code;
	IrtCreated(code, root->child);
	cout << "PROGRAMA FINALIZADO CORRECTAMENTE";
}