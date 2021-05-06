#include <iostream>
#include<fstream>
#include <cstdlib>
#include<math.h>
using namespace std;
ofstream Guardar,temp;
ifstream Leer;
int opcion=1;
int clave=0;
int cedula=0;
fstream archivo_escritura;
int semilla;//valor en el que se va a dividir el binario para ser codificado
int numfilas;//numero de filas del archivo
int i;//variable que nos servira para capturar los caracteres del archivo
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
    Guardar.open("SUDO.txt",ios::app);
    Leer.open("SUDO.txt");
    if(Leer.is_open()){//Si el archivo se pudo abrir correctamente
        cout<<"El archivo SUDO.txt se cargo sactisfactoriamente"<<endl<<endl;//imprimimos este mensaje
        //cout<<"El contenido del archivo es: "<<endl<<endl;//imprimimos este mensaje
        while(!Leer.eof()){//mientras no se este en el final del archivo
            getline(Leer,contenido);//leemos linea por linea el archivo
            texto+=contenido+'\n';//concatemos las lineas leidas del archivo que se guardan en la variable contenido
            numfilas++;//contador para saber el numero de filas que tiene el archivo
        }
       //cout<<texto<<endl;//imprimimos el contenido del archivo txt
       //cout<<endl<<"El archivo tiene "<<numfilas<<" filas"<<endl;//imprimimos el mensaje con el numero de filas del archivo
       Leer.close();//cerramos el archivo
       Leer.open("SUDO.txt",ios::in);//lo abrimos de nuevo
       while(!Leer.eof()){//mientras no se este en el final del archivo
           ascii[i]=Leer.get();//leemos caracter por caracter y lo guardamos en el arreglo ascii
           i++;//esta variable nos ayudara a capturar todos los caracteres del archivo txt
       }
        numcaracteres=--i;//variable para contar todos los caracteres del archivo excepto el caracter nulo
       //cout<<endl<<"la cantidad de caracteres es: "<<numcaracteres<<endl<<endl;//imprimimos la cantidad de caracteres que tiene el archivo
       Leer.close();//cerramos el archivo lectura
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
       system("CLS");
    while(opcion!=0){
    cout << "Bienvenido a la aplicacion cajero" << endl;
    cout<<"1. opcion administrador"<<endl;
    cout<<"2. opcion usuario"<<endl;
    cout<<"0. para salir"<<endl;
    cout<<"Ingrese la opcion que desea ejecutar: ";
    cin>>opcion;
    system("CLS");
    switch(opcion){
    case 1:{
        int password,clave_txt,saldo_txt,opcion_admin;
        Leer.open("SUDO.txt",ios::in);
        if(Leer.is_open())cout<<" ->El archivo SUDO.txt ha sido cargado correctamente."<<endl<<endl;//imprimimos el siguiente mensaje
        cout<<"Ingrese su clave: ";
        cin>>clave;
        while (!Leer.eof()){//mientras no se este en el final del archivo
           getline(Leer,texto);//leemos por lineas y almacenamos en la variable texto
           //cout<<"El contenido del archivo '"<<nombre<<".txt' es: "<<endl<<texto<<endl<<endl;//imprimimos el contenido del archivo por medio de la variable texto
        }
        Leer.close();//ceramos el archivo de lectura
        decodificacion_metodo1();//llamamos la funcion de decodificacion
        convertir_a_caracter();//llamamos la funcion de convertir a caracter
        system("CLS");
        Leer.open("SUDO.txt");
        while(!Leer.eof()){
            Leer>>password;
            Leer>>cedula;
            Leer>>clave_txt;
            Leer>>saldo_txt;
            if(clave!=password){
                cout<<"Clave incorrecta intente de nuevo"<<endl<<endl;
                break;
            }
            if(clave==password){
                cout<<"Bienvenido administrador"<<endl;
                cout<<"1. Registro de usuarios"<<endl;
                cout<<"2. Ver registro de usuarios"<<endl;
                cout<<"3. Modificar registro de usarios"<<endl;
                cout<<"4. Eliminar registro de usario"<<endl;
                cout<<"0. salir"<<endl;
                cout<<"Ingrese la opcion que desea ejecutar: ";
                cin>>opcion_admin;
                system("CLS");
                switch (opcion_admin) {
                case 1:{
                    int numero_cedula_nuevo_registro,clave_nuevo_registro,saldo_nuevo_registro;
                    cout<<"Bienvenido al registro de usuarios"<<endl;
                    cout<<"Ingrese el numero del documento del usuario a registrar: ";
                    cin>>numero_cedula_nuevo_registro;
                    cout<<"Ingrese la clave del usuario a registrar: ";
                    cin>>clave_nuevo_registro;
                    cout<<"Ingrese el saldo del usuario: ";
                    cin>>saldo_nuevo_registro;
                    Guardar<<numero_cedula_nuevo_registro<<" "<<clave_nuevo_registro<<" "<<saldo_nuevo_registro<<endl;
                    cout<<"Almacenando los datos..."<<endl;
                    Guardar.close();
                    break;}
                case 2:{
                    Leer.close();
                    cout<<"Estos son los registros disponibles: "<<endl<<endl;
                    string cedula_txt,rclave_txt,saldo_txt;
                    Leer.open("SUDO.txt");
                    Leer>>password;
                    Leer>>cedula_txt;
                    while(!Leer.eof()){
                        Leer>>clave_txt;
                        Leer>>saldo_txt;
                        cout<<cedula_txt<<endl;
                        cout<<clave_txt<<endl;
                        cout<<saldo_txt<<endl<<endl;
                        Leer>>cedula_txt;
                    }
                    Leer.close();
                    break;}
                case 3:{
                    Guardar.close();
                    Leer.close();
                    cout<<"Bienvenido al menu de modificacion de datos de los usuarios"<<endl<<endl;
                    cout<<"1. Cambiar numero de documento"<<endl;
                    cout<<"2. Cambiar clave"<<endl;
                    cout<<"3. Eliminar registro"<<endl;
                    cout<<"4. Modificar saldo"<<endl;
                    cout<<"0. para salir"<<endl;
                    cout<<"Ingrese la opcion que desea ejecutar: ";
                    cin>>opcion_admin;
                    switch (opcion_admin) {
                    case 1:{
                        int cedula,nuevo_doc,clave_txt,saldo_txt,cedula_txt;
                        Leer.open("SUDO.txt",ios::in);
                        temp.open("temp.txt");
                        Leer>>password;
                        Leer>>cedula_txt;
                        cout<<"Ingrese el numero de cedula del usuario que desea modificar: ";
                        cin>>cedula;
                        temp<<password<<endl;
                        while(!Leer.eof()){
                             Leer>>clave_txt>>saldo_txt;
                            if(cedula==cedula_txt){
                                cout<<"Ingrese el nuevo numero de documento: ";
                                cin>>nuevo_doc;
                                temp<<nuevo_doc<<" "<<clave_txt<<" "<<saldo_txt<<endl;
                            }
                            else{
                                temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                            }
                           Leer>>cedula_txt;
                        }
                        Leer.close();
                        temp.close();
                        remove("SUDO.txt");
                        rename("temp.txt","SUDO.txt");
                        break;}
                    case 2:{
                        int cedula,nueva_clave,clave_txt,saldo_txt,cedula_txt;
                        Leer.open("SUDO.txt",ios::in);
                        temp.open("temp.txt");
                        Leer>>password;
                        Leer>>cedula_txt;
                        cout<<"Ingrese el numero de cedula del usuario que desea modificar: ";
                        cin>>cedula;
                        temp<<password<<endl;
                        while(!Leer.eof()){
                             Leer>>clave_txt>>saldo_txt;
                            if(cedula==cedula_txt){
                                cout<<"Ingrese la nueva clave: ";
                                cin>>nueva_clave;
                                temp<<cedula_txt<<" "<<nueva_clave<<" "<<saldo_txt<<endl;
                            }
                            else{
                                temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                            }
                           Leer>>cedula_txt;
                        }
                        Leer.close();
                        temp.close();
                        remove("SUDO.txt");
                        rename("temp.txt","SUDO.txt");
                        break;}
                    case 3:{
                        int cedula,clave_txt,saldo_txt,cedula_txt;
                        Leer.open("SUDO.txt",ios::in);
                        temp.open("temp.txt");
                        Leer>>password;
                        Leer>>cedula_txt;
                        cout<<"Ingrese el numero de cedula del usuario que desea eliminar: ";
                        cin>>cedula;
                        temp<<password<<endl;
                        while(!Leer.eof()){
                             Leer>>clave_txt>>saldo_txt;
                            if(cedula==cedula_txt){
                                cout<<"Eliminando..."<<endl;
                            }
                            else{
                                temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                            }
                           Leer>>cedula_txt;
                        }
                        Leer.close();
                        temp.close();
                        remove("SUDO.txt");
                        rename("temp.txt","SUDO.txt");
                        break;}
                    case 4:{
                        int cedula,nuevo_saldo,clave_txt,saldo_txt,cedula_txt;
                        Leer.open("SUDO.txt",ios::in);
                        temp.open("temp.txt");
                        Leer>>password;
                        Leer>>cedula_txt;
                        cout<<"Ingrese el numero de cedula del usuario que desea modificar: ";
                        cin>>cedula;
                        temp<<password<<endl;
                        while(!Leer.eof()){
                             Leer>>clave_txt>>saldo_txt;
                            if(cedula==cedula_txt){
                                cout<<"Ingrese el nuevo saldo: ";
                                cin>>nuevo_saldo;
                                temp<<cedula_txt<<" "<<clave_txt<<" "<<nuevo_saldo<<endl;
                            }
                            else{
                                temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                            }
                           Leer>>cedula_txt;
                        }
                        Leer.close();
                        temp.close();
                        remove("SUDO.txt");
                        rename("temp.txt","SUDO.txt");
                        break;}
                    case 0:
                        cout<<"Hasta luego."<<endl;
                        break;
                    }
                    break;}
                }
            }
        }
        Leer.close();
        break;}
    case 2:{
        int cedula_user,clave_user,clave_txt,saldo_txt,opcion_user,password;
        string cedula_txt;
        cout<<"Bienvenido al menu de usuario"<<endl;
        cout<<"1. consultar saldo"<<endl;
        cout<<"2. retirar saldo"<<endl;
        cout<<"0. para salir"<<endl;
        cout<<"Ingrese la opcion que desea ejecutar: ";
        cin>>opcion_user;
        switch (opcion_user) {
        case 1:{
            Guardar.close();
            cout<<"Bienvenido al menu de consulta de saldo"<<endl;
            Leer.open("SUDO.txt",ios::in);
            temp.open("temp.txt");
            Leer>>password;
            Leer>>cedula_txt;
            cout<<"Ingrese el numero de documento: ";
            cin>>cedula_user;
            cout<<"Ingrese su clave: ";
            cin>>clave_user;
            temp<<password<<endl;
            while(!Leer.eof()){
                Leer>>clave_txt>>saldo_txt;
                if(cedula_user==atoi(cedula_txt.c_str())&&clave_user==clave_txt){
                    saldo_txt=saldo_txt-1000;
                    cout<<"Su saldo es: "<<saldo_txt<<endl;
                    temp<<cedula_txt<<" "<<clave_txt<<" "<<saldo_txt<<endl;
                }
                else{
                    temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                }

               Leer>>cedula_txt;
            }
            Leer.close();
            temp.close();
            remove("SUDO.txt");
            rename("temp.txt","SUDO.txt");
            break;}
        case 2:{
            Guardar.close();
            int monto_a_retirar,password;
            cout<<"Bienvenido al menu para retirar dinero"<<endl;
            Leer.open("SUDO.txt",ios::in);
            temp.open("temp.txt");
            Leer>>password;
             Leer>>cedula_txt;
            cout<<"Ingrese el numero de documento: ";
            cin>>cedula_user;
            cout<<"Ingrese su clave: ";
            cin>>clave_user;
            temp<<password<<endl;
            while(!Leer.eof()){
                Leer>>clave_txt>>saldo_txt;
                if(cedula_user==atoi(cedula_txt.c_str())&&clave_user==clave_txt){
                    saldo_txt=saldo_txt-1000;
                    cout<<"Su saldo es: "<<saldo_txt<<endl;
                    cout<<"Ingrese el monto a retirar: ";
                    cin>>monto_a_retirar;
                    saldo_txt=saldo_txt-monto_a_retirar;
                    temp<<cedula_txt<<" "<<clave_txt<<" "<<saldo_txt<<endl;
                }
                else{
                    temp<<cedula_txt<<" "<< clave_txt<<" "<<saldo_txt<<endl;
                }
                 Leer>>cedula_txt;
                }
                Leer.close();
                temp.close();
                remove("SUDO.txt");
                rename("temp.txt","SUDO.txt");
            break;}
        case 0:
            cout<<"Hasta luego."<<endl;
            break;
        default:
            cout<<"Ningun caso asociado intente de nuevo"<<endl;
            break;
        }

        break;}
    case 0:
        cout<<"Hasta Luego. "<<endl;
        break;
    default:
        cout<<"Ningun caso asociado intente de nuevo"<<endl;
        break;
    }
    }
    return 0;
}
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
    //cout<<"Ingrese el nombre del archivo codificado que desea decodificar: ";//se solicita el nombre del archivo que se desea abrir
    //cin>>nombre;

    Leer.open("encriptado.txt",ios::in);//se abre en modo lectura

    if(Leer.is_open()){//si se pudo abrir el archivo
        cout<<" ->El archivo encriptado.txt ha sido cargado correctamente."<<endl<<endl;
        while (!(Leer.eof())) {//mientras no se este en el final del archivo
            Leer>>cadena;
        }

        //cout<<"Ingrese nombre de salida para el archivo binario decodificado: ";cin>>nombre;//se pide el nombre para el archivo que contendra el binario desencriptado
        //cout<<"Ingrese el valor de la semilla: ";cin>> semilla;//se pide el valor de la semilla
        //cout<<endl;

        archivo_escritura.open("archivo_binario_decodificado.txt",ios::out);//se abre en modo escritura

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
        cout<<"Lo siento,el archivo archivo_binario_decodificado.txt no se pudo decodificar."<<endl;
    }
    archivo_escritura.close();
    Leer.close();
}

void convertir_a_caracter(){

    string nombre, subcadena,cadena,final;//variables locales a la funcion
    int letras;

    //cout<<"Ingrese el nombre del archivo binario que desea abrir: ";cin>>nombre;//solicitamos el nombre del archivo

    Leer.open("archivo_binario_decodificado.txt",ios::in);//se abre en modo lectura

    if(Leer.is_open()){//si se pudo abrir el archivo
        cout<<" ->El archivo archivo_binario_decodificado.txt ha sido cargado correctamente."<<endl<<endl;

        //cout<<"Ingrese el nombre para el archivo de salida con el texto decodificado: ";cin>>nombre;//solicitamos el nombre para el archivo ya decodificado

        while (!(Leer.eof())) {//mientras no se este en el final del archivo
             Leer>>cadena;

        }
        archivo_escritura.open("desencriptado.txt",ios::out);//se abre el archivo en modo escritura
        int tam=cadena.length();//se obtiene la longitud del archivo
        for(int j=0; j<tam; j+=8){
            subcadena=cadena.substr(j,8);//se sustrae una cadena con los indices que sera la que se va a convertir nuevamente a letras
            letras=valor_ascii(subcadena);//convermimos a letras la subcadena
            archivo_escritura<<(char)letras;//escribimos las letras
        }cout<<"    ->EL archivo desencriptado.txt ha sido creado correctamente\n"<<endl;//imprimimos el mensaje

    }
    else{//en caso de que no se pueda abrir el archivo
        cout<<"Hubo un problema al cargar el archivo."<<endl;
    }
    Leer.close();
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
    //cout<<"Ingrese un nombre para el archivo codificado: ";cin>>nombre;//solicitamos el nombre del archivo
    cout<<"Ingrese el valor de la semilla: ";cin>> semilla;//pedimos la semilla
    Leer.open("archivo_binario.txt",ios::in);//se abre en modo lectura
    if(Leer.is_open()){//si se pudo abrir el archivo
        while (!(Leer.eof())) {//mientras no se este en el final del archivo
            Leer>>cadena;
        }
        archivo_escritura.open("encriptado.txt",ios::out);//se abre el archivo en modo escritura
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
        cout<<" ->El archivo encriptado.txt ha sido codificado correctamente."<<endl<<endl;
    }
    else{//en caso de que no se pueda abrir el archivo
        cout<<"Lo siento,el archivo encriptado.txt no se pudo codificar."<<endl;
    }
    archivo_escritura.close();//cerramos los archivos
    Leer.close();
}
