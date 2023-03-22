#pragma once
#include<stdio.h>
#include "ClientesGestores.h"

/*!  \mainpage Introdução
 *  
 *   O âmbito deste projeto reside no desenvolvimento de uma solução de software na área da micromobilidade que permita agilizar a gestão(registo, partilha, utilização) de meios
 *  de mobilidade elétrica urbana, com objetivo, numa mobilidade mais económica, rápida e menos nociva ao ambiente.
 * 
 *   A implementação da solução para este projeto teve em consideração estruturas de dados dinânimcas (listas ligadas), armazenamento da informação em ficheiros e a manipulação
 *  destes dois.
 * 
 * 
 *   Autor: David Rodrigues
 */



/**
*  Inicio de sessão para o cliente
*/
int loginCliente(Cliente* inicio, int nif);


/**
*  Inicio de sessão para o gestor
*/
int loginGestores(Gestores* inicio);