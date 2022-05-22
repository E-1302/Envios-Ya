#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <functional>
using namespace std;

template<class Generico>
class NodoP {
private:
    Generico dato;
    NodoP<Generico>* siguiente;
    short pos;
public:
    NodoP(Generico v, NodoP<Generico>* sig = NULL) {
        dato = v;
        siguiente = sig;
        pos = 0;
    }
    ~NodoP() {}
    Generico getdato() { return dato; }
    void setdato(Generico dato) { this->dato = dato; }
    NodoP<Generico>* getsiguiente() { return siguiente; }

    void setpos(short c) { pos = c;}
    short getpos() { return pos; }
};

template<class Generico>
class Pila {
private:
    NodoP<Generico>* tope;
    short MAX;
    short cont;
public:
    Pila() {
        tope = NULL;
        MAX = 5; //solo se pueden hacer 5 envios por usuario
        cont = 0;
    };
    ~Pila() {}
    short getcont() { return cont; }
    NodoP<Generico>* gettope() { return tope; }

    void print(function<void(Generico)> imprime)
    {
        NodoP<Generico>* aux = tope; // apunta al inicio de la pila
        while (aux != NULL) {
            imprime(aux->getdato());
            aux = aux->getsiguiente();
        }
    }

    void push(Generico v) { //Añadir un elemento al final de la pila
        if (isEmpty()) {
            tope = new NodoP<Generico>(v);
        }
        else {
            tope = new NodoP<Generico>(v, tope);
        }
        cout << v.toString() << endl;
        cont++;
        tope->setpos(cont);
    }

    Generico pop() { // Leer y eliminar un elemento final de la pila
        if (isEmpty()) {
            return NULL;
        }
        else {
            Generico elemento = (Generico)(tope->getdato());
            tope = (NodoP<Generico>*) tope->getsiguiente();
            cont--;
            return elemento;
        }
    }

    bool isEmpty() {
        return (tope == NULL);
    }

    bool isFull() {
        return (cont == MAX);
    }

    Generico peek() {
        return tope->getdato();
    }

    void clear() {
        NodoP<Generico>* n;
        while (!isEmpty()) {
            n = tope;
            tope = tope->getsiguiente();
            delete n;
        }
    }

    void print_c(function<bool(NodoP<Generico>*)> condicion, function<void(Generico)> imprime) {
       NodoP<Generico>* aux = tope; 
       while (aux != NULL) {
           if (condicion(aux)) {
               imprime(aux->getdato());     
           }
           aux = aux->getsiguiente();
       }   
    }

    void BuscarNodoP(short d, function<void(Generico)> imprime) {
        NodoP<Generico>* aux = tope;
        bool encontrado = false;
        while (aux != NULL && encontrado != true) {
            if (aux->getpos() == d ) {
                imprime(aux->getdato());
                encontrado = true;
            }
            aux = aux->getsiguiente();
        }     
    }

    NodoP<Generico>* obtenernodopos(short d, function<void(Generico)> imprime) {
        NodoP<Generico>* aux = tope;
        bool encontrado = false;
        while (aux != NULL && encontrado != true) {
            if (aux->getpos() == d) {
                imprime(aux->getdato());
                encontrado = true;
                return aux;
            }
            aux = aux->getsiguiente();
        }
        if (encontrado == false) return 0;
    }

    void modificar( Generico e, NodoP<Generico>* p) {
       p->setdato(e);
    }

};