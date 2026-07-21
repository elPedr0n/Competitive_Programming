# Estrutura de Dados para programacao competitiva

Temos estuturas bem legais para resolver problemas. Algumas das mais simples nao precisam mt detalhes, como **vetores, listas encadeadas, pilhas, filas, deques, listas encadeadas**. 
> Depois posso meter um tutorial massa da stdc aq na real 

## Arvores
Usar encadeamento em PC eh bem arriscado, entao podemos usar outras estruturas para representar uma arvore, como vetores

Temos a seguinte arvore:
```
    -> 7
3 -
    -> 5 
```
Podemos armazenar em um vetor seguindo a seguinte regra: 
* se *i* for o nodo em questao, em um vetor 1-indexed, *2i* eh o filho da esquerda, *2i+1* eh o filho da direita
* A arvore acima seria [X, 3, 5, 7]
* A raiz estara no **i=1**
* Se quiser achar o pai de um nodo, fazemos floor(ind / 2);

## Heap
Eh uma arvore em que os nodos de um nivel i sao maiores ou iguais dos valores dos niveis abaixo.
* Em uma insercao de um heap, tem q cuidar com quem trocamos para cima, considerar o maior dos dois filhos do nodo para isso 