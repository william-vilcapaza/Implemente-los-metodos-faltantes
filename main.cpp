#include <iostream>
using namespace std;

class NodoDobleEnlace {
    //Atributos
    int dato; //char, float, string, objeto
    NodoDobleEnlace* anterior;// puntero al nodo anterior..
    NodoDobleEnlace* siguiente;//puntero al nodo siguiente..
public:
    //Constructor - inicializar los atributos
    NodoDobleEnlace(int dato)
    {
        this->dato = dato;
        anterior = NULL;//por que no apuntamos a ningun nodo
        siguiente = NULL;//por que no apuntamos a ningun nodo
    }
    //getter and setter
    int getDato()
    {
        return dato;
    }
    void setDato(int dato)
    {
        this->dato = dato;
    }
    NodoDobleEnlace* getAnterior()
    {
        return this->anterior;
    }
    void setAnterior(NodoDobleEnlace* enlace)
    {
        this->anterior = enlace;
    }
    NodoDobleEnlace* getSiguiente()
    {
        return this->siguiente;
    }
    void setSiguiente(NodoDobleEnlace* enlace)
    {
        this->siguiente = enlace;
    }

    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|Dato: " << dato << endl;
        cout << "|-------------------" << endl;
        cout << "|Anterior: " << anterior << "\tSiguiente: " << siguiente << endl;
        cout << "\\------------------/" << endl;
    }
};

class ListaDobleEnlace {
    NodoDobleEnlace* inicio;
    NodoDobleEnlace* fin;
public:
    Lista()
    {
        this->inicio = NULL;
        this->fin = NULL;
    }
    bool EstaVacia()
    {
        if (inicio == NULL && fin == NULL)
            return true;
        else
            return false;
    }
    void Imprimir()
    {
        int i = 1;
        NodoDobleEnlace* recorrido = inicio;
        cout << "Lista doblemente enlazada" << endl;
        while (recorrido != NULL)
        {
            cout << endl << "---> Nodo " << i++ << " -> DM: " << recorrido << endl;
            recorrido->imprimir();
            recorrido = recorrido->getSiguiente();
        }
        cout << endl;
    }


    void InsertarAlFinal(int dato)
    {
        NodoDobleEnlace* temp = new NodoDobleEnlace(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
            fin = temp;
        }
        else
        {
            fin->setSiguiente(temp);
            temp->setAnterior(fin);
            fin = temp;
        }
    }

    void InsertarAlInicio(int dato)
    {
        NodoDobleEnlace* temp = new NodoDobleEnlace(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
            fin = temp;
        }
        else
        {
            temp->setSiguiente(inicio);
            inicio->setAnterior(temp);
            inicio = temp;
        }
    }
    void ImprimirEnLinea()
    {
        NodoDobleEnlace* recorrido = inicio;
        cout << "Lista enlazada" << endl;
        while (recorrido != NULL)
        {
            cout << recorrido->getDato() << "\t";
            recorrido = recorrido->getSiguiente();
        }
        cout  << endl;
    }
    //Implementar la eliminaci�n de un nodo final
    void EliminarElementoFinal()//funcion de eliminacion de un nodo al final
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getSiguiente() == NULL) // unico nodo
            {
                inicio = NULL;
                fin = NULL;
            }
            else
            {
                fin->getAnterior()->setSiguiente(NULL);
                fin = fin->getAnterior();
            }

        }

    }
    void EliminarElementoInicio()//funcion eleminar nodo al inicio
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getSiguiente() == NULL) // unico nodo
            {
                inicio = NULL;
                fin = NULL;
            }
            else
            {
                inicio->getSiguiente()->setAnterior(NULL);
                inicio = inicio->getSiguiente();
            }
        }
    }
    void Vaciar()//funcion vaciar
    {
        inicio = NULL;
        fin = NULL;
    }
    void busqueda_elemento(int dato_buscado){//funcion buscar implementada
        if (EstaVacia())
        {
            cout << "No hay elementos para  buscar " << endl;
        }
        else
        {
            NodoDobleEnlace* recorrido = inicio;
            bool encontrado=false;
            while(recorrido!= NULL){
                    {
                if (recorrido->getDato() == dato_buscado)
                {
                    cout << "Elemento encontrado : =>  "<<dato_buscado<<"] DM => "<< recorrido << endl;

                    encontrado = true;
                    break;
                }
                else
                {
                    recorrido = recorrido->getSiguiente();
                    }
                }


            }
            if (encontrado == false)
                {
                    cout << "El elemento buscado no fue encontrado." << endl;
                }

        }
    }

    /*void EliminarElementoEnPosicion(int posicion)
    {
        int contador = 0;
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (posicion == 0)
            {
                EliminarElementoInicio();
            }
            else
            {
                Nodo* recorrido = inicio;
                while (recorrido->getEnlace() != NULL)
                {
                    if (contador == posicion - 1)
                    {
                        recorrido->setEnlace(recorrido->getEnlace()->getEnlace());
                        break;
                    }
                    else
                    {
                        contador++;
                        recorrido = recorrido->getEnlace();
                    }
                }
            }
        }
    }
    //Implementar la eliminaci�n de un nodo inicio
    void InsertarDesendentemente(int dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            if (recorrido->getDato() < dato)
            {
                temp->setEnlace(this->inicio);
                this->inicio = temp;
            }
            else
            {
                while (recorrido->getEnlace() != NULL && recorrido->getEnlace()->getDato() > dato)
                {
                    recorrido = recorrido->getEnlace();
                }
                if (recorrido->getEnlace() == NULL)//insertarmos al final
                    recorrido->setEnlace(temp);
                else//inserta en el intermedio de dos nodos
                {
                    temp->setEnlace(recorrido->getEnlace());
                    recorrido->setEnlace(temp);
                }
            }
        }
    }
    //Implementar la busqueda de un elemento en la lista enlazada
    //Si la encuentra tiene que imprimir la direcci�n de memor�a
    //donde esta este elemento.
    void Buscar(int datoBuscado)
    {
        bool encontrado = false;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            if (recorrido->getDato() == datoBuscado)
            {
                cout << "Elemento encontrado en la direcci�n de memor�a: " << recorrido << endl;
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getEnlace();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }
    */
};

void MostrarMenu()
{
    cout << "1.- Ver el contenido de la lista enlazada" << endl;
    cout << "2.- Insertar un elemento al inicio" << endl;
    cout << "3.- Insertar un elemento al final" << endl;
    cout << "4.- Buscar un elemento" << endl;
    cout << "5.- Eliminar un elemento inicial" << endl;
    cout << "6.- Eliminar un elemento final" << endl;
    cout << "7.- Vaciar la lista" << endl;
    cout << "8.- Eliminar un elemento en la posici�n" << endl;
    cout << "9.- Insertar elementos ordenadamente (desendente)" << endl;
    cout << "10.- Buscar un elemento en  una lista doble " << endl;

    cout << "0.- Salir" << endl;
}
int main()
{
    ListaDobleEnlace lista = ListaDobleEnlace();
    int dato_b;
    for (int i = 0; i < 5; i++){
        lista.InsertarAlInicio(i + 1);

        lista.ImprimirEnLinea();

        //lista.EliminarElementoInicio();

        //lista.ImprimirEnLinea();

        //lista.EliminarElementoInicio();

        //lista.ImprimirEnLinea();
    }
        cout<<"Ingrese  el dato buscado "<<endl;
        cin>>dato_b;
        lista.busqueda_elemento(dato_b);




    /*cout<<"Nodos no enlazados"<<endl;
    NodoDobleEnlace* nodo = new NodoDobleEnlace(666);
    nodo->imprimir();
    NodoDobleEnlace* nodo2 = new NodoDobleEnlace(777);
    nodo2->imprimir();
    cout<<"Nodos enlazados"<<endl;
    nodo2->setAnterior(nodo);
    nodo->setSiguiente(nodo);
    nodo->imprimir();
    nodo2->imprimir();*/

}
