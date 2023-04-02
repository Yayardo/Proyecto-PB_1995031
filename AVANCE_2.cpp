#include <iostream>

#include <math.h>
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using namespace std;

struct article {
	int ID;
	char Name[100];
	string Desc;
	char Gen[25];
	char Clas[25];
	char Console[25];
	float Prize;
};

int cur_arts = 0;
article Articulos[5];

int MENU = -1;

int main() {
	system("cls");

	printf("| Articulos: %d/%d                             |\n", cur_arts, 5);
	printf("#============================================#\n");
	printf("|                    MENU                    |\n");
	printf("#--------------------------------------------#\n");
	printf("| [1] - Dar de Alta un Producto              |\n");
	printf("| [2] - Dar de Baja un Producto              |\n");
	printf("| [3] - Modificar un Producto                |\n");
	printf("| [4] - Lista de Productos                   |\n");
	printf("| [5] - Salir del Programa                   |\n");
	printf("#--------------------------------------------#\n");
	printf("| Presiona el Numero de la Opcion que Eligas |\n");
	printf("#============================================#\n");

	MENU = _getche();

	switch (MENU){
		default:{break;}
		case '1': {
			system("cls");

			printf("#============================================#\n");
			printf("|                    MENU                    |\n");
			printf("#--------------------------------------------#\n");
			printf("| Declare el ID del Producto.                |\n - ");
			scanf_s("%d", &Articulos[cur_arts].ID);
			printf("| Declare el Nombre del Producto.            |\n - ");
			cin.ignore(); gets_s(Articulos[cur_arts].Name);
			printf("| Declare la Descripcion del Producto.       |\n - ");
			getline(cin, Articulos[cur_arts].Desc);
			printf("| Declare el Genero del Producto.            |\n - ");
			gets_s(Articulos[cur_arts].Gen);
			printf("| Declare la Clasificacion del Producto.     |\n - ");
			gets_s(Articulos[cur_arts].Clas);
			printf("| Declare la Consola del Producto.           |\n - ");
			gets_s(Articulos[cur_arts].Console);
			printf("| Declare el Precio Unitario del Producto.   |\n - ");
			scanf_s("%f", &Articulos[cur_arts].Prize);
			printf("#--------------------------------------------#\n");

			cur_arts++;
			return main();
			break;
		}
		case '2': {
			system("cls");

			printf("#============================================#\n");
			printf("|                    MENU                    |\n");
			printf("#--------------------------------------------#\n");
			printf("| Introduzca el Indice del Articulo.         |\n - ");
			int cur_index = _getche();
			printf("#--------------------------------------------#\n");

			if (cur_index == 27) { return main(); }
			cur_index = cur_index - 49;
			if (cur_index < 0 || cur_index > 5) { return main(); }
			if (cur_index >= cur_arts) { return main(); }

			for (int i = cur_index; i < cur_arts; i++) {
				Articulos[i] = Articulos[i + 1];
			}

			cur_arts--;
			return main();
			break;
		}
		case '3': {
			system("cls");

			printf("#============================================#\n");
			printf("|                    MENU                    |\n");
			printf("#--------------------------------------------#\n");
			printf("| Introduzca el Indice del Articulo.         |\n - ");
			int cur_index = _getche();
			printf("\n#--------------------------------------------#\n");

			if (cur_index == 27) { return main(); }
			cur_index = cur_index - 49;
			if (cur_index < 0 || cur_index > 5) { return main(); }
			if (cur_index >= cur_arts) { return main(); }

			printf("| Declare el ID del Producto.                |\n - ");
			scanf_s("%d", &Articulos[cur_index].ID);
			printf("| Declare el Nombre del Producto.            |\n - ");
			cin.ignore(); gets_s(Articulos[cur_index].Name);
			printf("| Declare la Descripcion del Producto.       |\n - ");
			getline(cin, Articulos[cur_index].Desc);
			printf("| Declare el Genero del Producto.            |\n - ");
			gets_s(Articulos[cur_index].Gen);
			printf("| Declare la Clasificacion del Producto.     |\n - ");
			gets_s(Articulos[cur_index].Clas);
			printf("| Declare la Consola del Producto.           |\n - ");
			gets_s(Articulos[cur_index].Console);
			printf("| Declare el Precio Unitario del Producto.   |\n - ");
			scanf_s("%f", &Articulos[cur_index].Prize);
			printf("#--------------------------------------------#\n");

			return main();
			break;
		}
		case '4': {
			system("cls");

			printf("#============================================#\n");
			printf("|                    MENU                    |\n");
			printf("#--------------------------------------------#\n");
			printf("| Lista de Articulos.                        |\n");
			printf("#--------------------------------------------#\n\n");

			for (int i = 0; i < cur_arts; i++) {
				article i_art = Articulos[i];

				printf("#-| [%d] %s |-#\n", i_art.ID, i_art.Name);
				printf(" - Descripcion: %s\n", i_art.Desc.c_str());
				printf(" - Genero: %s\n", i_art.Gen);
				printf(" - Clasificacion: %s\n", i_art.Clas);
				printf(" - Consola: %s\n", i_art.Console);
				printf(" - Precio Unitario: %.2f\n", i_art.Prize);
				printf("#-| [%d] %s |-#\n\n", i_art.ID, i_art.Name);
			}

			system("pause");

			return main();
			break;
		}
	}

	return 0;
}