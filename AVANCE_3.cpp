#include <iostream>

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <conio.h> 
#include <stdio.h>
#include <cstring>
#include <fstream> 
#include <string>
#include <math.h>
#include <vector>
#include <array> 

using namespace std;

int *int_temp;
struct int_list {
	int *list;
	int count = 0;
	int index = 0;

	void add(int value) {
		int_temp = new int[count];

		for (int i = 0; i < count; i++) {
			int_temp[i] = list[i];
		}

		count++;

		list = new int[count];

		for (int i = 0; i < count - 1; i++) {
			list[i] = int_temp[i];
		}

		list[count - 1] = value;
	}
};

struct game_art {
	int Id = 0;
	char Tag[25] = "";
	char Name[100] = "";
	string Description = "";
	char Gender[25] = "";
	char Class[25] = "";
	char Console[25] = "";
	float Prize = 0.0;

	bool IsArchived;
};

int article_count = 0;
game_art *store;

vector<string> split_string(string _string, string _del) {
	vector<string> toReturn;
	string token = "";

	for (int i = 0; i < _string.size(); i++) {
		bool flag = true;

		for (int j = 0; j < _del.size(); j++) {
			if (_string[i + j] != _del[j]) flag = false;
		}
		
		if (flag) {
			if (token.size() > 0) {
				toReturn.push_back(token);
				token = "";
				i += _del.size() - 1;
			}
		} else {
			token += _string[i];
		}
	}
	toReturn.push_back(token);

	return toReturn;
}

void save_to_file() {
	ofstream to_save;

	to_save.open("C:/Users/Public/Documents/save.txt");

	for (int i = 0; i < article_count; i++) {
		game_art cur_art = store[i];

		to_save << cur_art.Name << "|";
		to_save << cur_art.Description << "|";
		to_save << cur_art.Tag << "|";
		to_save << cur_art.Gender << "|";
		to_save << cur_art.Class << "|";
		to_save << cur_art.Console << "|";
		to_save << cur_art.Prize << "|";
		to_save << cur_art.IsArchived;

		if (i != article_count - 1) {
			to_save << "" << endl;
		}
	}

	to_save.close();
}
void load_file() {
	ifstream to_load("C:/Users/Public/Documents/save.txt");
	if (!to_load.is_open()) {
		return;
	}

	string _line;
	while (getline(to_load, _line)) {
		game_art* temp_store = new game_art[article_count];
		for (int i = 0; i < article_count; i++) {
			temp_store[i] = store[i];
		}

		game_art new_art;
		new_art.Id = article_count;

		article_count++;

		int cur_prop = 0;
		for (string _prop : split_string(_line, "|")) {
			switch (cur_prop) {
				case 0: { strncpy_s(new_art.Name, _prop.c_str(), sizeof(new_art.Name) - 1); }
				case 1: { new_art.Description = _prop; }
				case 2: { strncpy_s(new_art.Tag, _prop.c_str(), sizeof(new_art.Tag) - 1); }
				case 3: { strncpy_s(new_art.Gender, _prop.c_str(), sizeof(new_art.Gender) - 1); }
				case 4: { strncpy_s(new_art.Class, _prop.c_str(), sizeof(new_art.Class) - 1); }
				case 5: { strncpy_s(new_art.Console, _prop.c_str(), sizeof(new_art.Console) - 1); }
				case 6: { new_art.Prize = strtof(_prop.c_str(), nullptr); }
				case 7: { new_art.IsArchived = (_prop == "1");}
			}
			
			cur_prop++;
		}

		store = new game_art[article_count];
		for (int i = 0; i < article_count - 1; i++) {
			store[i] = temp_store[i];
		}

		store[article_count - 1] = new_art;
	}
}

void show_header() {
	system("cls");
	printf("#============================================#\n");
	printf("|           []-< GAMES STORE >-[]            |\n");
	printf("#--------------------------------------------#\n");
}
void show_article(game_art _article) {
	printf(" - Id: %d\n", _article.Id);
	printf("\n");
	printf(" - Etiqueta: %s\n", _article.Tag);
	printf("\n");
	printf(" - Nombre: %s\n", _article.Name);
	printf(" - Descripcion: %s\n", _article.Description.c_str());
	printf(" - Genero: %s\n", _article.Gender);
	printf(" - Clase: %s\n", _article.Class);
	printf(" - Consola: %s\n", _article.Console);
	printf("\n");
	printf(" - Precio Unitario: %.2f$\n", _article.Prize);
	printf(" - Impuesto: %.2f$\n", _article.Prize * 0.16);
	printf("#--------------------------------------------#\n");
}


int search_id(bool isArchived) {
	printf("|    Que Medio quieres usar para Buscar?     |\n");
	printf("#--------------------------------------------#\n");
	printf("| [1] - ID                                   |\n");
	printf("| [2] - Etiqueta                             |\n");
	printf("| [3] - Genero                               |\n");
	printf("| [4] - Clasificacion                        |\n");
	printf("| [5] - Consola                              |\n");
	printf("|                                            |\n");
	printf("| [6] - Salir                                |\n");
	printf("#--------------------------------------------#\n");

	int _input = _getch() - 48;

	switch (_input) {
		default: {
			show_header();
			return search_id(isArchived);
		}
		case 1: {
			printf("|         Ingresa el ID del Articulo         |\n");
			printf("#--------------------------------------------#\n");

			int cur_id = -1;
			scanf_s("%d", &cur_id);
			printf("#--------------------------------------------#\n");

			if (cur_id < 0 || cur_id >= article_count) {
				system("cls");
				printf("#========================#\n");
				printf("|          ERROR         |\n");
				printf("#------------------------#\n");
				printf("| Articulo no Encontrado |\n");
				printf("#========================#\n");
				int _to_back = _getch();
				return -1;
			}

			if (!isArchived && store[cur_id].IsArchived) {
				printf("|    Este Articulo se encuentra Archivado    |\n");
				printf("#--------------------------------------------#\n");
				int _to_back = _getch();
				show_header();
				return search_id(isArchived);
			}

			show_header();
			printf("|            Articulo Encontrado             |\n");
			printf("#--------------------------------------------#\n");
			show_article(store[cur_id]);
			printf("| Elegir este Articulo?               (Si:1) |\n");
			printf("#--------------------------------------------#\n");

			if (_getch() == 49) {
				cin.ignore();
				return cur_id;
			}

			show_header();
			return search_id(isArchived);
		}
		case 2: {
			printf("|      Ingresa la Etiqueta del Articulo      |\n");
			printf("#--------------------------------------------#\n");

			char cur_tag[25] = "";
			gets_s(cur_tag);

			bool hasArt = false;
			for (int i = 0; i < article_count; i++) {
				game_art cur_art = store[i];

				if (strcmp(cur_art.Tag, cur_tag) != 0 || (!isArchived && cur_art.IsArchived)) {
					continue;
				}

				hasArt = true;

				show_header();
				printf("|           Busqueda por Etiqueta            |\n");
				printf("#--------------------------------------------#\n");
				printf("|            Articulo Encontrado             |\n");
				printf("#--------------------------------------------#\n");
				show_article(cur_art);
				printf("| Elegir este Articulo?               (Si:1) |\n");
				printf("#--------------------------------------------#\n");

				if (_getch() == 49) {
					cin.ignore();
					return i;
				}
			}

			show_header();
			if (hasArt) {
				printf("|  No elegiste ningun Articulo Disponible    |\n");
			}
			else {
				printf("|  No se encontro Articulo con esa Etiqueta  |\n");
			}
			printf("#--------------------------------------------#\n");
			
			int to_next = _getch();

			show_header();
			return search_id(isArchived);
		}
		case 3: {
			printf("|       Ingresa el Genero del Articulo       |\n");
			printf("#--------------------------------------------#\n");

			char cur_gen[25];
			gets_s(cur_gen);

			bool hasArt = false;
			for (int i = 0; i < article_count; i++) {
				game_art cur_art = store[i];

				if (strcmp(cur_art.Gender, cur_gen) != 0 || (!isArchived && cur_art.IsArchived)) {
					continue;
				}

				hasArt = true;

				show_header();
				printf("|            Busqueda por Genero             |\n");
				printf("#--------------------------------------------#\n");
				printf("|            Articulo Encontrado             |\n");
				printf("#--------------------------------------------#\n");
				show_article(cur_art);
				printf("| Elegir este Articulo?               (Si:1) |\n");
				printf("#--------------------------------------------#\n");

				if (_getch() == 49) {
					cin.ignore();
					return i;
				}
			}

			show_header();
			if (hasArt) {
				printf("|  No elegiste ningun Articulo Disponible    |\n");
			}
			else {
				printf("|  No se encontro Articulo con esa Etiqueta  |\n");
			}
			printf("#--------------------------------------------#\n");

			int to_next = _getch();

			show_header();
			return search_id(isArchived);
		}
		case 4: {
			printf("|   Ingresa la Clasificacion del Articulo    |\n");
			printf("#--------------------------------------------#\n");

			char cur_class[25];
			gets_s(cur_class);

			bool hasArt = false;
			for (int i = 0; i < article_count; i++) {
				game_art cur_art = store[i];

				if (strcmp(cur_art.Class, cur_class) != 0 || (!isArchived && cur_art.IsArchived)) {
					continue;
				}

				hasArt = true;

				show_header();
				printf("|         Busqueda por Clasificacion         |\n");
				printf("#--------------------------------------------#\n");
				printf("|            Articulo Encontrado             |\n");
				printf("#--------------------------------------------#\n");
				show_article(cur_art);
				printf("| Elegir este Articulo?               (Si:1) |\n");
				printf("#--------------------------------------------#\n");

				if (_getch() == 49) {
					cin.ignore();
					return i;
				}
			}

			show_header();
			if (hasArt) {
				printf("|  No elegiste ningun Articulo Disponible    |\n");
			}
			else {
				printf("|  No se encontro Articulo con esa Etiqueta  |\n");
			}
			printf("#--------------------------------------------#\n");

			int to_next = _getch();

			show_header();
			return search_id(isArchived);
		}
		case 5: {
			printf("|      Ingresa la Consola del Articulo       |\n");
			printf("#--------------------------------------------#\n");

			char cur_console[100];
			gets_s(cur_console);

			bool hasArt = false;
			for (int i = 0; i < article_count; i++) {
				game_art cur_art = store[i];

				if (strcmp(cur_art.Console, cur_console) != 0 || (!isArchived && cur_art.IsArchived)) {
					continue;
				}

				hasArt = true;

				show_header();
				printf("|            Busqueda por Consola            |\n");
				printf("#--------------------------------------------#\n");
				printf("|            Articulo Encontrado             |\n");
				printf("#--------------------------------------------#\n");
				show_article(cur_art);
				printf("| Elegir este Articulo?               (Si:1) |\n");
				printf("#--------------------------------------------#\n");

				if (_getch() == 49) {
					cin.ignore();
					return i;
				}
			}

			show_header();
			if (hasArt) {
				printf("|  No elegiste ningun Articulo Disponible    |\n");
			}
			else {
				printf("|  No se encontro Articulo con esa Etiqueta  |\n");
			}
			printf("#--------------------------------------------#\n");

			int to_next = _getch();

			show_header();
			return search_id(isArchived);
		}
		case 6: {
			return -1;
		}
	}
}

void alta() {
	game_art new_art;
	new_art.Id = article_count;
	new_art.IsArchived = false;

	game_art *temp_store = new game_art[article_count];
	for (int i = 0; i < article_count; i++) {
		temp_store[i] = store[i];
	}

	article_count++;

	show_header();
	printf("> Escribe el Nombre del Articulo: ");
	gets_s(new_art.Name);
	printf("> Escribe una Descripcion sobre el Articulo: ");
	getline(cin, new_art.Description);
	printf("> Escribe la Etiqueta del Articulo: ");
	gets_s(new_art.Tag);
	printf("> Escribe el Genero del Articulo: ");
	gets_s(new_art.Gender);
	printf("> Escribe la Clasificacion del Articulo: ");
	gets_s(new_art.Class);
	printf("> Escribe la Consola a la que se dirigide el Articulo: ");
	gets_s(new_art.Console);
	printf("> Escribe el Precio Unitario del Articulo: ");
	scanf_s("%f", &new_art.Prize);
	printf("#============================================#\n");

	system("pause");

	store = new game_art[article_count];
	for (int i = 0; i < article_count - 1; i++) {
		store[i] = temp_store[i];
	}

	store[article_count - 1] = new_art;

	cin.ignore();
}
void archivar() {
	show_header();
	int cur_id = search_id(true);
	if (cur_id < 0 || cur_id > article_count) {
		return;
	}

	if ( store[cur_id].IsArchived ) {
		printf("|  Este Articulo ya se Encuentra Archivado   |\n");
		printf("| Desea Desarchivar este Articulo?    (Si:1) |\n");
		printf("#--------------------------------------------#\n");
		int _to_check = _getch();
		if (_to_check == 49) {
			store[cur_id].IsArchived = false;

			show_header();
			printf("|       El Articulo a sido Desarchivado      |\n");
			printf("#--------------------------------------------#\n");
			int _to_next = _getch();
		}
	}
	else {
		printf("| Desea Archivar este Articulo?       (Si:1) |\n");
		printf("#--------------------------------------------#\n");
		int _to_check = _getch();
		if (_to_check == 49) {
			store[cur_id].IsArchived = true;

			show_header();
			printf("|        El Articulo a sido Archivado        |\n");
			printf("#--------------------------------------------#\n");
			int _to_next = _getch();
		}
	}
}
void modificar() {
	show_header();
	int cur_id = search_id(false);
	if (cur_id < 0 || cur_id > article_count) {
		return;
	}

	printf("| Desea Modificar este Articulo?      (Si:1) |\n");
	printf("#--------------------------------------------#\n");

	int _to_next = _getch();
	if (_to_next != 49) {
		return;
	}

	game_art mod_art = store[cur_id];

	int _to_mod = 0;
	while (_to_mod != -1) {
		show_header();
		printf("|         Modificacion de un Articulo        |\n");
		printf("#--------------------------------------------#\n");
		printf(" [1] - Nombre [%s] \n", mod_art.Name);
		printf(" [2] - Descripcion [%s] \n", mod_art.Description.c_str());
		printf(" [3] - Etiqueta [%s] \n", mod_art.Tag);
		printf(" [4] - Genero [%s] \n", mod_art.Gender);
		printf(" [5] - Clasificacion [%s] \n", mod_art.Class);
		printf(" [6] - Consola [%s] \n", mod_art.Console);
		printf(" [7] - Precio [%.2f] \n", mod_art.Prize);
		printf("\n");
		printf(" [8] - Guardar y Salir\n");
		printf(" [9] - Salir sin Guardar\n");
		printf("#============================================#\n");

		_to_mod = _getch();

		switch (_to_mod) {
			default: { break; }
			case 49: {
				printf("> Escribe el Nombre del Articulo: ");
				gets_s(mod_art.Name);
				break;
			}
			case 50: {
				printf("> Escribe una Descripcion sobre el Articulo: ");
				getline(cin, mod_art.Description);
				break;
			}
			case 51: {
				printf("> Escribe la Etiqueta del Articulo: ");
				gets_s(mod_art.Tag);
				break;
			}
			case 52: {
				printf("> Escribe el Genero del Articulo: ");
				gets_s(mod_art.Gender);
				break;
			}
			case 53: {
				printf("> Escribe la Clasificacion del Articulo: ");
				gets_s(mod_art.Class);
				break;
			}
			case 54: {
				printf("> Escribe la Consola a la que se dirigide el Articulo: ");
				gets_s(mod_art.Console);
				break;
			}
			case 55: {
				printf("> Escribe el Precio Unitario del Articulo: ");
				scanf_s("%f", &mod_art.Prize);
				break;
			}
			case 56: {
				store[cur_id] = mod_art;
				_to_mod = -1;
				break;
			}
			case 57: {
				printf("| Esta seguro de salir sin Guardar?   (Si:1) |\n");
				int _un_save = _getch();
				if (_un_save == 49) {
					_to_mod = -1;
				}
				break;
			}
		}
	}
}

struct list_filter {
	int cur_list = 0;
	char type_filter[100] = "Ninguno";
	char filter[100] = "";
} list_data;
void lista() {
	show_header();
	printf("|             Lista de Articulos             |\n");
	printf("#--------------------------------------------#\n");
	if (strcmp(list_data.type_filter, "Ninguno") != 0) {
		printf("> Tipo de Filtrado: %s\n", list_data.type_filter);
		printf("> Clave de Filtrado: %s\n", list_data.filter);
		printf("#--------------------------------------------#\n");
	}
	printf(" 0 - Filtrar Articulos\n\n");

	int_list total_list, cur_list;
	int index_list = 0;
	
	total_list.index = -1;
	while (total_list.index < article_count - 1) {
		total_list.index++;

		if (strcmp(list_data.type_filter, "Etiqueta") == 0 && strcmp(store[total_list.index].Tag, list_data.filter) != 0) { continue; }
		if (strcmp(list_data.type_filter, "Genero") == 0 && strcmp(store[total_list.index].Gender, list_data.filter) != 0) { continue; }
		if (strcmp(list_data.type_filter, "Clasificacion") == 0 && strcmp(store[total_list.index].Class, list_data.filter) != 0) { continue; }
		if (strcmp(list_data.type_filter, "Consola") == 0 && strcmp(store[total_list.index].Console, list_data.filter) != 0) { continue; }
		
		total_list.add(total_list.index);
	}

	cur_list.index = list_data.cur_list * 9;
	while (cur_list.count < 9){
		if (cur_list.index >= total_list.count) { break; }

		cur_list.add(total_list.list[cur_list.index]);
		
		cur_list.index++;
	}

	for (int i = 0; i < cur_list.count; i++) {
		game_art cur_art = store[cur_list.list[i]];

		if (cur_art.IsArchived) {
			printf(" %d - ARCHIVADO [%d]\n", (i + 1), cur_art.Id);
		} else {
			printf(" %d - %s [%d]\n", (i + 1), cur_art.Name, cur_art.Id);
		}
	}
	
	printf("#--------------------------------------------#\n");
	printf("|            [A] <- %d / %d -> [D]             |\n", (list_data.cur_list + 1), (int((total_list.count - 1) / 9)) + 1);
	printf("#============================================#\n");

	int _input = _getch();
	if (_input == 97) {
		if (list_data.cur_list > 0) {
			list_data.cur_list--;
		}
		lista();
	} 
	else if (_input == 100) {
		if (list_data.cur_list < (int((total_list.count - 1) / 9))) {
			list_data.cur_list++;
		}
		lista();
	}

	int cur_art_id = _input - 48;

	if (cur_art_id == 0) {
		show_header();
		printf("|          Elige el tipo de Filtro           |\n");
		printf("#--------------------------------------------#\n");
		printf("| [1] - Ninguno                              |\n");
		printf("| [2] - Etiqueta                             |\n");
		printf("| [3] - Genero                               |\n");
		printf("| [4] - Clasificacion                        |\n");
		printf("| [5] - Consola                              |\n");
		printf("|                                            |\n");
		printf("| [6] - Salir                                |\n");
		printf("#--------------------------------------------#\n");


		int to_filter = _getch() - 48;
		switch (to_filter) {
			case 1: {
				strncpy_s(list_data.type_filter, "Ninguno", 100);
				strncpy_s(list_data.filter, "", 100);
				lista();
				return;
				break;
			}
			case 2:{
				strncpy_s(list_data.type_filter, "Etiqueta", 100);
				break;
			}
			case 3: {
				strncpy_s(list_data.type_filter, "Genero", 100);
				break;
			}
			case 4: {
				strncpy_s(list_data.type_filter, "Clasificacion", 100);
				break;
			}
			case 5: {
				strncpy_s(list_data.type_filter, "Consola", 100);
				break;
			}
			case 6: {
				lista();
				return;
				break;
			}
		}
		printf("| Escribe una Palabra Clave para Filtrar     |\n");
		printf("#--------------------------------------------#\n");
		gets_s(list_data.filter);

		list_data.cur_list = 0;

		lista();
		return;

	} else if (cur_art_id > 0 && cur_art_id < cur_list.count + 1) {
		game_art cur_art = store[cur_list.list[cur_art_id - 1]];
		
		show_header();

		if (cur_art.IsArchived) {
			printf("|    Este Articulo se encuentra Archivado    |\n");
			printf("#--------------------------------------------#\n");
		}else {
			show_article(cur_art);
			printf("|                                            |\n");
			printf("#============================================#\n");
		}

		int _to_pass = _getch();
		lista();
	}
}

void menu() {
	show_header();
	printf("| [1] - Dar de Alta un Articulo              |\n");
	printf("|                                            |\n");
	printf("| [2] - Archivar un Articulo                 |\n");
	printf("| [3] - Modificar un Articulo                |\n");
	printf("|                                            |\n");
	printf("| [4] - Mostrar Lista de Articulos           |\n");
	printf("| [5] - Buscar un Articulo                   |\n");
	printf("|                                            |\n");
	printf("| [6] - Guardar Datos                        |\n");
	printf("|                                            |\n");
	printf("| [7] - Salir del Programa                   |\n");
	printf("#============================================#\n");

	int _input = _getch() - 48;
	switch (_input) {
	default: { menu(); break; }
		case 1: {
			alta();
			menu();
			break;
		}
		case 2: {
			archivar();
			menu();
			break;
		}
		case 3: {
			modificar();
			menu();
			break;
		}
		case 4: {
			lista();
			menu();
			break;
		}
		case 5: {
			show_header();
			int cur_id = search_id(false);
			menu();
			break;
		}
		case 6: { 
			save_to_file();
			show_header();
			printf("| Datos Guardados Correctamente              |\n");
			printf("#============================================#\n");
			int _to_pass = _getch();
			menu();
			break; 
		}
		case 7: {
			save_to_file();
			break;
		}
	}
}

int main() {
	load_file(); 
	menu();
	return 0; 
}