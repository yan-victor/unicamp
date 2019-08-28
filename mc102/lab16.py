#Yan Victor Souza Guimarães ra245875
#lab16 mc102q
def pertence(conj, num):
    for i in conj:
        if num==i: return True
    return False
def contido(conj1, conj2):
    for i in conj1:
        if i not in conj2: return False
    return True
def adicao(conj, num):
    if num not in conj:
        conj.append(num)
        conj.sort()
    return

def subtracao(conj, num):
    if num in conj: conj.remove(num)
    return

# Funcoes: uniao, intersecao e diferenca
#
# Parametros:
#     conj1: vetor contendo o conjunto de entrada do primeiro operando
#     conj2: vetor contendo o conjunto de entrada do segundo operando
#
# Retorno:
#   Vetor contendo o conjunto de saida/resultado da operacao
#
def uniao(conj1, conj2):
    u=[]
    for i in conj1:
        u.append(i)
    for i in conj2:
        if i not in conj1: u.append(i)
    return u

def intersecao(conj1, conj2):
    u = []
    for i in conj1:
        if i in conj2:
            u.append(i)
    return u

def diferenca(conj1, conj2):
    u=[]
    for i in conj1:
        if i not in conj2:
            u.append(i)
    return u

def uniao_disjunta(conj1, conj2):
    return uniao(diferenca(conj1,conj2),diferenca(conj2,conj1))