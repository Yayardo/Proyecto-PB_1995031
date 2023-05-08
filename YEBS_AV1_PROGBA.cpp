#include <iostream>

using namespace std;

int prod_count = 0;
int max_prod = 3;

int MENU_INPUT = -1;

float per_impuesto = 16;

int _articulo_identificacion_1 = -1;
char art_name_1[20] = "PlaceHolder";
char art_des_1[100] = "PlaceHolder";
char art_gene_1[20] = "PlaceHolder";
char art_clas_1[20] = "PlaceHolder";
char art_cons_1[20] = "PlaceHolder";
float artic_precio_unitario_1 = 0.0;

int _articulo_identificacion_2 = -1;
char art_name_2[20] = "PlaceHolder";
char art_des_2[100] = "PlaceHolder";
char art_gene_2[20] = "PlaceHolder";
char art_clas_2[20] = "PlaceHolder";
char art_cons_2[20] = "PlaceHolder";
float artic_precio_unitario_2 = 0.0;

int _articulo_identificacion_3 = -1;
char art_name_3[20] = "PlaceHolder";
char art_des_3[100] = "PlaceHolder";
char art_gene_3[20] = "PlaceHolder";
char art_clas_3[20] = "PlaceHolder";
char art_cons_3[20] = "PlaceHolder";
float artic_precio_unitario_3 = 0.0;

int main() {
	cout << "#============================================#" << endl;
	cout << "| Productos: " << prod_count << "/" << max_prod << "                             |" << endl;
	cout << "#============================================#" << endl;
	cout << "|                    MENU                    |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "| [1] - Dar de Alta un Producto              |" << endl;
	cout << "| [2] - Modificar un Producto                |" << endl;
	cout << "| [3] - Dar de Baja un Producto              |" << endl;
	cout << "| [4] - Lista de Productos                   |" << endl;
	cout << "| [5] - Salir del Programa                   |" << endl;
	cout << "#--------------------------------------------#" << endl;
	cout << "| Presiona el Numero de la Opcion que Eligas |" << endl;
	cout << "#============================================#" << endl;

	cin >> MENU_INPUT;

	switch(MENU_INPUT){
		default:{
			cout << "La Opcion que elegiste no se encuentra en el menu." << endl << "Elige una del menu por favor." << endl;
			return main();

			break;
		}
		case 1: {
			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga un ID para su producto.              |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> _articulo_identificacion_1; }
			else if (prod_count == 1) { cin >> _articulo_identificacion_2; }
			else { cin >> _articulo_identificacion_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga un Nombre para su producto.          |" << endl;
			cout << "#============================================#" << endl;

			if(prod_count == 0){ cin >> art_name_1; }
			else if(prod_count == 1) { cin >> art_name_2; }
			else { cin >> art_name_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga una Descripcion para su producto.    |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> art_des_1; }
			else if (prod_count == 1) { cin >> art_des_2; }
			else { cin >> art_des_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga un Genero para su producto.          |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> art_gene_1; }
			else if (prod_count == 1) { cin >> art_gene_2; }
			else { cin >> art_gene_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga una Clasificacion para su producto.  |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> art_clas_1; }
			else if (prod_count == 1) { cin >> art_clas_2; }
			else { cin >> art_clas_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga la Consola a la que se dirige su     |" << endl;
			cout << "| Producto.                                  |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> art_cons_1; }
			else if (prod_count == 1) { cin >> art_cons_2; }
			else { cin >> art_cons_3; }

			system("cls");

			cout << "#============================================#" << endl;
			cout << "|                    MENU                    |" << endl;
			cout << "#--------------------------------------------#" << endl;
			cout << "| Eliga el Precio Unitario de su Producto.   |" << endl;
			cout << "#============================================#" << endl;

			if (prod_count == 0) { cin >> artic_precio_unitario_1; }
			else if (prod_count == 1) { cin >> artic_precio_unitario_2; }
			else { cin >> artic_precio_unitario_3; }

			prod_count++;

			break;
		}
		case 2: {}
		case 3: {}
		case 4: {
			system("cls");

			cout << "#============================================#" << endl;
			cout << "| Aviso: Opcion no Disponible por el Momento.|" << endl;
			cout << "#============================================#" << endl;

			system("pause");
			
			break;
		}
		case 5: {
			system("cls");
				
			cout << "#============================================#" << endl;
			cout << "| Aviso: Saliendo del Programa               |" << endl;
			cout << "#============================================#" << endl;

			exit(1);
			break;
		}
	}

	system("cls");
	return main();
}