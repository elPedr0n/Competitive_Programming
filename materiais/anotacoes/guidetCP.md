# Resumão da leitura de "A guide to Competitive Programming"

## Básico

A primeira parte introdutória do livro é o basicão do básico, mas tem algumas coisas que são interessantes de se anotar:
- Quando temos um problema que envolve pegar o módulo de um número ao final, `modulo 10⁹ + 7` por exemplo, essa operação pode ser realizada em todas as microoperações até o resultado final, cuidando para que não seja estourado o limite de representação da linguagem;
- Em problemas em que precisamos parar quando a entrada parar, famoso EOF, podemos simplesmente colocar o seguinte loop para ler a entrada:
```c 
// Para um único valor
ll x;
while (cin >> x) {
    // Insira o código aqui
}

// Para uma linha inteira
string line;
while (getline(cin, line)) {
    // Processamaento aqui
}
```
> Importante notar que C++ nativamente não tem os métodos de `strip()` que o Python tem, então ver na hora se não vale mais a pena ir para o Python para resolver isso
```py
import sys

for line in sys.stdin:
  linha = line.strip()
  if not linha:  
    continue
  # Seu código aqui


# Ou podemos também usar um try expect
while True:
  try:
    linha = input().strip()
    # Seu código aqui
  except EOFError:
    break
```
- Para a comparação de dois `floats` não usa-se o `==`, mas sim uma comparação com um epsilon 
```c
if (abs(a-b) < 1e9) {
    // Continua aq a lógica
}
```

## Geração de todos os subconjuntos recursivamente
Algo que pode ser interessante é a geração de todos os subconjuntos de um conjunto dado. 
> Vale lembrete que o número de subconjuntos de um conjunto de tamanho `N` eh `2^N`
```c

// Vetor global que acumula o estado atual do subconjunto
vector<int> subset;

void search(int k) {
    if (k == n + 1) {
        // Terminou aqui pois decidimos sobre o último elemento 
        // Processa o subconjunto
    } else {
        // Podemos incluir o número atual no subconjunto
        subset.push_back(k);
        search(k+1);
        // Terminou de processar com ele então tiramos ele 
        subset.pop_back();
        // Processamos também sem esse número na lista
        search(k+1);
    }
}
```

## Permutações de um set recursivamente
De uma forma semelhante a essa podemos calcular todas as permutações de um set recursivamente. 
> Dependendo da vida, valeria mais a pena usar a função do C++ `next_permutation(begin, end)` que retorna `true` se existir uma permutação lexicograficamente maior que a já existente, false caso contrário.

```c

vector<int> permutation;
bool chosen[n+1];

void search() {
    if (permutation.size() == n) {
        // Chegamos ao tamanho máximo então podemos processar 
    } else { 
        for (int i = 1 i <= n; i++) {
            // Se já usamos pulamos 
            if (choosen[i]) continue;

            // Podemos escolher esse elemento agora
            chosen[i] = true;
            permutation.push_back(i);
            search();

            // Ou pulamos e processaremos ele em outro momento
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

```

## Problema das N Rainhas
Um problema clássico envolve colocar N rainhas em um tabuleiro NxN de forma com que elas não se ataquem entre si. Temos uma abordagem força bruta que envolve testar todas as permutações de colunas e linhas entre as rainhas mas isso exige tempo afu. Podemos usar uma abordagem de recursão com backtracking:
```c
vector<bool> col(N, false);
vector<bool> diag1(2 * N, false), diag2(2 * N, false);
ll out = 0;

void solve(int y) {

    if (y == N) {
        out++;
        return;
    } else {
        for (int i = 0; i < N; i++) {
            int id1 = i + y;
            int id2 = i - y + (N-1);

            if (col[i] or diag1[id1] or diag2[id2]) continue;
            col[i] = true;
            diag1[id1] = true;
            diag2[id2] = true;

            solve(y+1);

            col[i] = false;
            diag1[id1] = false;
            diag2[id2] = false;

        }
    }
}
```

Meio confuso de primeira mão, mas para verificar os conflitos entre elas, podemos usar apenas vetores, não precisamos de `for` grandes para isso. `col` é trivial, temos N colunas, então cada vez que colocamos uma rainha na coluna, deixamos ela como false. Para `diag2` (\/) temos algo interessante. Se diminuirmos todas as coordenadas de um elemento da mesma diagonal temos o mesmo número. 

(0 + 3 == 1 + 2 == 2 + 1 == 3 + 0 == 3)

Então dessa forma temos um id único no vetor para cada diagonal. Já `diag1` (\\) temos coisas relacionadas a subtração. Se pegarmos e subtrairmos os elementos, cairemos em números iguais novamente, mas dessa vez, precisamos de um artifício, o (N-1). 

(0 - 3 == 1 - 4 == -3)

Essa subtração pode ser negativa, e como não temos índices negativos, precisamos positivar tudo entre 0 e N-1.


## Bit manipulation