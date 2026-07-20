# Divide and Conquer

Divisão em conquista tem algumas soluções clássicas, mas a maior parte eh ad-hoc. Funciona em cima de 3 etapas claras:
1. Dividir o problema em problemas menores até chegar a um trivial
2. Resolvemos esse problema trivial
3. Combinamos as soluções triviais para montar soluções maiores

Exemplos:
**Busca binária:**
```c
bs(a, b, v, arr) {
  if (a > b) return -1; // Não achou

  mid = (a + b) / 2;

  if (arr[mid] > v) return bs(a, mid - 1, v, arr);
  else if (arr[mid] < v) return bs(mid + 1, b, v, arr);
  else return mid;
}
```
**Merge sort**
> Inserir código aq depois para estudo
