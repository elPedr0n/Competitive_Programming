# Grafos

Um grafo eh um conjunto G = (V, A) onde:
* V = Vertices
* A = Arestas

> Insira aq umd esenho mt foda de um grafo como exemplo

Grafos planares: grafos que podem ser desenhados sem arestas se cruzarem
> K3,3 K5 são exemplos dos menores grafos não planares

### Representacoes

* **Matriz de adjacencia (NxN)**: grande matriz preenchida com 0 onde não temos arestas, e um valor diferente valor de 0 caso tenhamos uma aresta
    * Uma matriz de um grafo não direcionado eh simetrica, sendo necessario armazenar somente metade dela dai
    * **Problema:** Grafos com muito vertices ocupam mt memoria
    * Linha -> Coluna (em caso de direcionamentos) (convencao base)
    * Usar vector do C++ pra facilitar a vida com inicializacao e assignment
* **Lista de Adjacencia:** usemos um vector com *push_back* para adicionar os vertices que estao ligados a um vertice
    * Temos uma vantagem clara em questao ao uso de memoria
    * **Mas** se temos um nodo com um grau muito alto, podemos demorar pra ver a questao de estar conectado a um especifico
        * Metemos uma lista ordenada pra fazer busca binaria
    ```c
    // Cria um array de vectors
    vector<int>[N] adj; 
    
    // Cria tb uma lista de adjacencia
    vector<vector<int>> adj(N, vector<int>(0, 0)); 
    ```  

> Novamente insira uma imagem mt massa de uma lista de adjacencia


Pode ser interessante formular um problema de grafo para uma das duas estruturas e depois aplicar o algoritmo
> De cabeca to lembrando mais de aplicar as coisas na matriz do que na lista, mas eh semelhante 

### Buscas

#### DFS (Busca em profundidade)
Usa de uma estrutura de **pilha** para realizar a bsuca
* Relevante a ordem em que sao dispostas as arestas no grafo

#### BFS (Busca em Largura)
Usa de uma **fila** para realizar a busca
* Possui uma completude maior de busca
* Usado em problemas que queremos uma profundidade controlada 
* Resolve a menor distancia para grafos com valor unitario nas arestas

#### Dijkstra
Algoritmo guloso para calcular os menores caminhos a partir de um vertice 

> Depois adicionar aq os codigos 

### Fluxo de Grafos

Os pesos nas arestas são capacidades (naipe quanto de algo consegue escoar de um nodo pra outro)
* A ideia desses problemas eh ter um Source e um Target, quer saber quanto consegue mandar. (Fluxo maximo)
* Tudo de peso 1 = **Corte minimo** para tirar o target
    * Se o problema for de cortar vertices, dobramos os vertices, mantendo as arestas originais com peso INF e o resto 1, resolvemos para corte e saberemos quantos cortar 

**Grafos Bipartidos**: Grafo em que temos dois grupos que nao possuem ligacoes internas entre si, apenas com o outro grupo. Não possui ciclos de tamanho impar
* Deteccao desse ciclo eh feito com um BFS com arestas de valor 1, se temos um ciclo em que a distancia total para voltar ao inicio eh par, dai eh ciclo par 
    * A -> B -> C -> A (impar)
    * A -> B -> C -> D -> A (par)
* Problema de emparelhamento podem ser resolvidos como problemas de fluxo 
    * Cria um source e um target, ligando em todos do grupo
    * Maximizamos o fluxo e eh us guri