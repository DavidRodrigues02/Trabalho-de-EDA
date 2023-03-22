#pragma once
#include<stdio.h>
#include "ClientesGestores.h"

/*!  \mainpage Introdu��o
 *  
 *   O �mbito deste projeto reside no desenvolvimento de uma solu��o de software na �rea da micromobilidade que permita agilizar a gest�o(registo, partilha, utiliza��o) de meios
 *  de mobilidade el�trica urbana, com objetivo, numa mobilidade mais econ�mica, r�pida e menos nociva ao ambiente.
 * 
 *   A implementa��o da solu��o para este projeto teve em considera��o estruturas de dados din�nimcas (listas ligadas), armazenamento da informa��o em ficheiros e a manipula��o
 *  destes dois.
 * 
 * 
 *   Autor: David Rodrigues
 */



/**
*  Inicio de sess�o para o cliente
*/
int loginCliente(Cliente* inicio, int nif);


/**
*  Inicio de sess�o para o gestor
*/
int loginGestores(Gestores* inicio);