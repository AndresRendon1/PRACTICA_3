#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;
//VARIABLES GLOBALES
fstream archivo_lectura,archivo_escritura;
int semilla;//valor en el que se va a dividir el binario para ser codificado
int numfilas;//numero de filas del archivo
int i;//variable que nos servira para capturar los caracteres del archivo
int opcion=1;
int numcaracteres;//variable que nos ayudara a identificar el numero de caracteres en el archivo
int ascii[3000]={};//arreglo para convertir las letras a ascii
int binario[3000]={};//arreglo para convertir los valores ascii a binario
string nombre,texto,contenido;
//PROTOTIPO DE FUNCIONES
void convertir_binario(int a, int b[]);//Funcion para convertir a binario
int contador_0s_1s(string a);//Funcion para contar la cantidad de 1s y 0s
string igual_cantidad_0s_1s(string a, string b);//Funcion en caso de que halla igual cantidad de 0s y unos
string mayor_cantidad1s(string a,string b);//Funcion en caso de que halla mayor cantidad de 1s
string mayor_cantidad0s(string a, string b);//Funcion en caso de que halla mayor cantidad de 0s
void metodo_codificacion1();//Funcion para codificar mediante el metodo 1
void decodificacion_metodo1();//Funcion para decodificar mediante el metodo 1
int valor_ascii(string a);//Funcion para convertir nuevamente a ascii
void convertir_a_caracter();//Funcion para convertir las letras
int main()
{
    while(opcion!=0){
        cout<<"     PRACTICA 3 "<<endl;
        cout<<"ANDRES FELIPE RENDON VILLADA"<<endl;
        cout<<"1035876760"<<endl;
        cout<<"grupo 2"<<endl<<endl;;
        cout<<"1. codificador"<<endl;
        cout<<"2. decodificador"<<endl;
        cout<<"0. para salir "<<endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>>opcion;
        switch (opcion) {
            case 1:
            cout<<"Bienvenido al codificador"<<endl<<endl;
            cout << "Ingresa el nombre del archivo que deseas abrir: ";
            cin>>nombre;
            archivo_lectura.open(nombre+".txt",ios::in);//Se abre el archivo en modo lectura
            if(archivo_lectura.is_open()){//Si el archivo se pudo abrir correctamente
                cout<<"El archivo se cargo sactisfactoriamente"<<endl<<endl;//imprimimos este mensaje
                cout<<"El contenido del archivo es: "<<endl<<endl;//imprimimos este mensaje
                while(!archivo_lectura.eof()){//mientras no se este en el final del archivo
                    getline(archivo_lectura,contenido);//leemos linea por linea el archivo
                    texto+=contenido+'\n';//concatemos las lineas leidas del archivo que se guardan en la variable contenido
                    numfilas++;//contador para saber el numero de filas que tiene el archivo
                }
               cout<<texto<<endl;//imprimimos el contenido del archivo txt
               cout<<endl<<"El archivo tiene "<<numfilas<<" filas"<<endl;//imprimimos el mensaje con el numero de filas del archivo
               archivo_lectura.close();//cerramos el archivo
               archivo_lectura.open(nombre+".txt",ios::in);//lo abrimos de nuevo
               while(!archivo_lectura.eof()){//mientras no se este en el final del archivo
                   ascii[i]=archivo_lectura.get();//leemos caracter por caracter y lo guardamos en el arreglo ascii
                   i++;//esta variable nos ayudara a capturar todos los caracteres del archivo txt
               }
                numcaracteres=--i;//variable para contar todos los caracteres del archivo excepto el caracter nulo
               cout<<endl<<"la cantidad de caracteres es: "<<numcaracteres<<endl<<endl;//imprimimos la cantidad de caracteres que tiene el archivo
               archivo_lectura.close();//cerramos el archivo lectura
               archivo_escritura.open("archivo_binario.txt",ios::out);//abrimos el archivo de escritura
               for(int j=0; j<numcaracteres;j++){//iteramos hasta el numero de caracteres del archivo
                   convertir_binario(ascii[j],binario);//llamos la funcion convertir binario para pasar el ascii a binario y se guarda en el arreglo binario
                   for(int i=0;i<8;i++){
                       archivo_escritura<<binario[i];//escrimos los 8 bits en el archivo lectura
                   }
               }
               archivo_escritura.close();//cerramos el archivo de escritura
               cout<<"->encriptando...."<<endl<<endl;
               metodo_codificacion1();//llamamos la funcion de codificacion
            }
            else if(!archivo_lectura.is_open()){//Si el archivo no se pudo abrir mostramos el siguiente mensaje
                cout<<"No se pudo cargar el archivo"<<endl;
            }
            break;
        case 2:{
            cout << "Bienvenido al decodificador" << endl;//imprimimos este mensaje
            cout<<"Ingrese el nombre del archivo codificado que desea abrir:  ";cin>>nombre;//solicitamos el nombre del archivo decodificado
            archivo_lectura.open(nombre+".txt",ios::in);//abrir en modo lectura
            if(archivo_lectura.is_open()){//si el archivo se puedo abrir
                cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl;//imprimimos el siguiente mensaje
                while (!archivo_lectura.eof()){//mientras no se este en el final del archivo
                   getline(archivo_lectura,texto);//leemos por lineas y almacenamos en la variable texto
                   cout<<"El contenido del archivo '"<<nombre<<".txt' es: "<<endl<<texto<<endl<<endl;//imprimimos el contenido del archivo por medio de la variable texto
                }
            }
                archivo_lectura.close();//ceramos el archivo de lectura
                cout<<"->Decodificando archivo"<<endl;
                decodificacion_metodo1();//llamamos la funcion de decodificacion
                cout<<"->Convirtiendo binario a caracteres"<<endl;
                convertir_a_caracter();//llamamos la funcion de convertir a caracter
            }
            break;
           default:
            cout<<"no se ingreso una opcion valida intente de nuevo"<<endl;
            break;
        }
    }
    return 0;
}

//CUERPO DE LAS FUNCIONES

void convertir_binario(int a, int b[]){  //Funcion para convertir el contenido del texto a binario se retorna el arreglo con los 8 bits por cada iteracion
    int i=0;
    int binario[8]={0,0,0,0,0,0,0,0};
    while(a!=1){
        binario[i]=a%2;
        a=a/2;
        i++;
    }
    binario[i]=a;               // a siempre va a ser igual a 1
    for(int j=7,i=0;j>=0;j--,i++){
        b[i]=binario[j];
    }
}

int contador_0s_1s(string a){ //Funcion para  contar la cantidad de 1s y 0s
    int tam,cont1=0,cont0=0;
    tam=a.length();//obtenemos la longitud del archivo
    for(int i=0;i<tam;i++){//iteramos hasta el tamaño del archivo
        if(a[i]=='1'){//si el valor asociado a la i-esima posicion es un 1 aumentamos el contador de 1s
            cont1++;
        }
        else if(a[i]=='0'){//si el valor asociado a la i-esima posicion es un 0 aumentamos el contador de 0s
            cont0++;
        }
    }
    if(cont1>cont0){//si hay mas 1s que unos retornamos un 1
        return 1;
    }
    else if(cont0>cont1){//si hay mas 0s que unos retornamos 0
        return 0;
    }
    else {
        return 4;//si hay igual cantidad retornamos un 4
    }
}

string igual_cantidad_0s_1s(string a, string b){ //Funcion para modificar el binario en caso de que halla igual cantidad de 0s y 1s
    int tam=0;
    tam=a.length();//obtenemos la longitud del archivo
    for(int i=0;i<tam;i++){//iteramos hasta el tamaño del archivo
        if(a[i]=='1'){b[i]='0';}//se intercambian los valores en el arreglo b
        else if(a[i]=='0'){b[i]='1';}

    }
    return b;//retornamos el arreglo
}

string mayor_cantidad1s(string a, string b){ //Funcion para cambiar los numeros en caso de que halla mayor cantidad de 1s
    int tam=0;
    tam=a.length();
    for(int i=2;i<tam;i+=2){//se cambian cada 2
        if(a[i]=='0'){b[i]='1';}
        else{b[i]='0';}
    }

    return b;
}

string mayor_cantidad0s(string a, string b){ //Funcion para cambiar los valores en caso de que halla mas 0s
    int tam=0;
    tam=a.length();
    for(int i=1;i<tam;i+=2){
        if(a[i]=='0'){b[i]='1';}
        else{b[i]='0';}
    }
    return b;


}

void decodificacion_metodo1(){
    string cadena,bin_modificado,bloque1,bloque2,nombre;//declaracion de variables locales a la funcion
    cout<<"Ingrese el nombre del archivo codificado que desea decodificar: ";//se solicita el nombre del archivo que se desea abrir
    cin>>nombre;

    archivo_lectura.open(nombre+".txt",ios::in);//se abre en modo lectura

    if(archivo_lectura.is_open()){//si se pudo abrir el archivo
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl;
        while (!(archivo_lectura.eof())) {//mientras no se este en el final del archivo
            archivo_lectura>>cadena;
        }

        cout<<"Ingrese nombre de salida para el archivo binario decodificado: ";cin>>nombre;//se pide el nombre para el archivo que contendra el binario desencriptado
        cout<<"Ingrese el valor de la semilla: ";cin>> semilla;//se pide el valor de la semilla
        cout<<endl;

        archivo_escritura.open(nombre+".txt",ios::out);//se abre en modo escritura

        int tam=cadena.length();//obtenemos el tamaño de la cadena

        bloque1=cadena.substr(0,semilla);//se extrae la cadena entre los 2 indices y se guarda en la variable bloque 1
        bin_modificado=igual_cantidad_0s_1s(bloque1,bloque1);//llamamos la funcion igual cantidad de 1s y se guarda el retorno en la variable bin modificado
        archivo_escritura<<bin_modificado;//se escribe el valor de la variable bin modificado


        for(int i=0;i<tam;i+=semilla){//condiciones para verifiacar si hay mayor cantidad de 1s o de 0s o igual cantidad
            if(contador_0s_1s(bin_modificado)==1){
                bloque2=cadena.substr((i+semilla),semilla);//sustraemos una cadena con los indices y la guardamos en la variable bloque 2
                bin_modificado=mayor_cantidad1s(bloque2,bloque2);//se llama la funcion mayor cantidad de 1s y se guarda el retorno en la variable bin modificado
                archivo_escritura<<bin_modificado;//escribimos el valor de bin modificado
                bloque1=bloque2;//igualamos las variables ya que se compara con el bloque anterior
            }
            else if(contador_0s_1s(bin_modificado)==0){//si hay mayor cantidad de 0s
                bloque2=cadena.substr((i+semilla),semilla);//sustraemos una cadena con los indices y la guardamos en la variable bloque 2
                bin_modificado=mayor_cantidad0s(bloque2,bloque2);//se llama la funcion mayor cantidad de 0s y se guarda el retorno en la variable bin modificado
                archivo_escritura<<bin_modificado;//escribimos el valor de bin modificado
                bloque1=bloque2;//igualamos las variables ya que se compara con el bloque anterior
            }
            else if(contador_0s_1s(bin_modificado)==4){
                bloque2=cadena.substr((i+semilla),semilla);//sustraemos una cadena con los indices y la guardamos en la variable bloque 2
                bin_modificado=igual_cantidad_0s_1s(bloque2,bloque2);//se llama la funcion igual cantidad de 1s y  0s y se guarda el retorno en la variable bin modificado
                archivo_escritura<<bin_modificado;//escribimos el valor de bin modificado
                bloque1=bloque2;//igualamos las variables ya que se compara con el bloque anterior
            }
    }

    }
    else{//en caso de que no se pueda abrir el archivo
        cout<<"Lo siento,el archivo '"<<nombre<<"' no se pudo decodificar."<<endl;
    }
    archivo_escritura.close();
    archivo_lectura.close();
}

void convertir_a_caracter(){

    string nombre, subcadena,cadena,final;//variables locales a la funcion
    int letras;

    cout<<"Ingrese el nombre del archivo binario decodificado que desea abrir: ";cin>>nombre;//solicitamos el nombre del archivo

    archivo_lectura.open(nombre+".txt",ios::in);//se abre en modo lectura

    if(archivo_lectura.is_open()){//si se pudo abrir el archivo
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido cargado correctamente."<<endl<<endl;

        cout<<"Ingrese el nombre para el archivo de salida con el texto decodificado: ";cin>>nombre;//solicitamos el nombre para el archivo ya decodificado

        while (!(archivo_lectura.eof())) {//mientras no se este en el final del archivo
            archivo_lectura>>cadena;

        }
        archivo_escritura.open(nombre+".txt",ios::out);//se abre el archivo en modo escritura
        int tam=cadena.length();//se obtiene la longitud del archivo
        for(int j=0; j<tam; j+=8){
            subcadena=cadena.substr(j,8);//se sustrae una cadena con los indices que sera la que se va a convertir nuevamente a letras
            letras=valor_ascii(subcadena);//convermimos a letras la subcadena
            archivo_escritura<<(char)letras;//escribimos las letras
        }cout<<"    ->EL archivo '"<<nombre<<"' ha sido creado correctamente\n"<<endl;//imprimimos el mensaje

    }
    else{//en caso de que no se pueda abrir el archivo
        cout<<"Hubo un problema al cargar el archivo."<<endl;
    }
    archivo_lectura.close();
    archivo_escritura.close();

}

int valor_ascii (string a){//Funcion para convertir los binarios a letras nuevamente
    int ascii=0;
    for (int i=0,j=7; i<8; i++, j--){
        ascii+=(((int)a[i])-48)*(pow(2,j));
    }
    return ascii;
}

void metodo_codificacion1(){
    string cadena,bin_modificado,bloque1,bloque2,nombre;//variables locales a la funcion
    int n;
    cout<<"Ingrese un nombre para el archivo codificado: ";cin>>nombre;//solicitamos el nombre del archivo
    cout<<"Ingrese el valor de la semilla: ";cin>> semilla;//pedimos la semilla
    archivo_lectura.open("archivo_binario.txt",ios::in);//se abre en modo lectura
    if(archivo_lectura.is_open()){//si se pudo abrir el archivo
        while (!(archivo_lectura.eof())) {//mientras no se este en el final del archivo
            archivo_lectura>>cadena;
        }
        archivo_escritura.open(nombre+".txt",ios::out);//se abre el archivo en modo lectura
        n=cadena.length();//obtenemos la longitud de archivo
        bloque1=cadena.substr(0,semilla);//sustreameos una cadena con los indicies y la guardamos en la variable bloque 1
        bin_modificado=igual_cantidad_0s_1s(bloque1,bloque1);//se llama la funcion igual cantidad de 1s y 0s y se guarda el retorno en bin modificado
        archivo_escritura<<bin_modificado;//escribimos el resultado
        for(int i=0;i<n;i+=semilla){
            if(contador_0s_1s(bloque1)==1){//si hay mas cantidad de 1s
                bloque2=cadena.substr((i+semilla),semilla);//se substrae una nueva cadena con los indices
                bin_modificado=mayor_cantidad1s(bloque2,bloque2);//se llama la funcion para hacer el cambio de los valores
                archivo_escritura<<bin_modificado;
                bloque1=bloque2;//se igualan los bloques ya que se compara con el anterior
            }
            else if(contador_0s_1s(bloque1)==0){//si hay mas cantidad de 0s
                bloque2=cadena.substr((i+semilla),semilla);//se substrae una nueva cadena con los indices
                bin_modificado=mayor_cantidad0s(bloque2,bloque2);//se llama la funcion para hacer el cambio de los valores
                archivo_escritura<<bin_modificado;//se escribe el resultado
                bloque1=bloque2;//se igualan los bloques ya que se compara con el anterior
            }
            else if(contador_0s_1s(bloque1)==4){//si hay igual cantidad
                bloque2=cadena.substr((i+semilla),semilla);//se substrae una nueva cadena con los indices
                bin_modificado=igual_cantidad_0s_1s(bloque2,bloque2);//se llama la funcion para hacer el cambio de los valores
                archivo_escritura<<bin_modificado;//se escribe el resultado
                bloque1=bloque2;//se igualan los bloques ya que se compara con el anterior
            }

         }
        cout<<" ->El archivo '"<<nombre<<".txt' ha sido codificado correctamente."<<endl<<endl;
    }
    else{//en caso de que no se pueda abrir el archivo
        cout<<"Lo siento,el archivo '"<<nombre<<"' no se pudo codificar."<<endl;
    }
    archivo_escritura.close();//cerramos los archivos
    archivo_lectura.close();
}
