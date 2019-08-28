#!/usr/bin/env python3

import math

# Laboratorio 17 - Banco de Dados Geografico
# Nome: Yan Victor Souza Guimarães
# RA: 245875

class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Cidade:
    def __init__(self, coordenadas, inicioCEP, fimCEP, numHabitantes):
        self.coordenadas = coordenadas
        self.inicioCEP = inicioCEP
        self.fimCEP = fimCEP
        self.numHabitantes = numHabitantes

def distancia(c1, c2):
    return int(100 * math.sqrt((c1.x - c2.x)**2 + (c1.y - c2.y)**2)) / 100.0

def consulta_cidade_por_cep(cidades, cep):
    for i in range(len(cidades)):
        if cidades[i].inicioCEP <= cep and cidades[i].fimCEP>=cep:
            return i
    return None

# Funcao: consulta_cidades_por_raio
#
# Parametros:
#            cidades: lista de cidades (base de dados) 
#   cidades[cidadeReferencia]: indice da cidade referencia (centro da circunferencia)
#               raio: raio da busca
#
# Retorno:
#   Lista dos indices das cidades que estao contidas no raio de busca (incluindo
#   a cidade referencia) *ordenados pelas respectivas distancias da cidade referencia*.
#
def comp(cidades,x,y,cidadeReferencia):
    if distancia(cidades[x].coordenadas,cidades[cidadeReferencia].coordenadas)<distancia(cidades[y].coordenadas,cidades[cidadeReferencia].coordenadas):
        return True
    return False
def ordena(cidades,v,cidadeReferencia):
    for i in range(len(v)):
        for j in range(i+1,len(v)):
            if(comp(cidades,v[j],v[i],cidadeReferencia)):
                v[i],v[j] = v[j],v[i]
    #return u
def consulta_cidades_por_raio(cidades, cidadeReferencia, raio):
    u = []
    for i in range(len(cidades)):
        if distancia(cidades[cidadeReferencia].coordenadas,cidades[i].coordenadas)<=raio:
            u.append(i)
    ordena(cidades,u,cidadeReferencia)
    return u

# Funcao: populacao_total
#
# Parametros:
#            cidades: lista de cidades (base de dados) 
#   cidades[cidadeReferencia]: indice da cidade referencia (centro da circunferencia)
#               raio: raio da busca
#          
# Retorno:
#   O numero de habitantes das cidades que estao contidas no raio de busca
#
def populacao_total(cidades, cidadeReferencia, raio):
    ans=0
    for i in cidades:
        if distancia(cidades[cidadeReferencia].coordenadas,i.coordenadas)<=raio:
            ans+=i.numHabitantes
    return ans

def mediana_da_populacao(cidades, cidadeReferencia, raio):
    u = []
    for i in cidades:
        if distancia(cidades[cidadeReferencia].coordenadas,i.coordenadas)<=raio:
            u.append(i.numHabitantes)
    u.sort()
    if (len(u))%2==0:
        return (u[len(u)//2]+u[(len(u)-2)//2])/2
    return u[len(u)//2] 