## Análise de complexidade

A análise de complexidade é extremamente importante nas decisões de projetos de estruturas de dados. Este documento tem como objetivo apresentar uma análise das operações implementadas na estrutura de dados fila.

### Operações e suas complexidades

Esta seção apresenta a complexidade das operações implementadas na fila.

> É importante lembrar que as complexidades listadas estão relacionadas a implementação feita na atividade

* `front()` Retorna o primeiro elemento da lista
  * Complexidade: O(1)

* `back()`: Retorna o último elemento da lista.
  * Complexidade: O(1)

* `push_front(v)`: Insere o valor v na cabeça da lista
  * Complexidade: O(1)

* `push_back(v)`: Insere o valor v no final da lista.
  * Complexidade: O(1)

* `pop_front()`: Remove o primeiro elemento da lista.
  * Complexidade: O(1)

* `pop_back()`: Remove o último elemento da lista.
  * Complexidade: O(1)

* `splice(L2)`: Funde os elementos da lista L2 ao final da lista operada.
  * Complexidade: O(2N)

* `reverse()`: Reverte os elementos da lista.
  * Complexidade: O(N)

* `merge(L2)`: Junta duas listas ordenadas de forma ascendente em uma só, também ordenada. A Lista L2 ficará vazia ao final.
  * Complexidade: O(2N * N²)
  * Sobre: Este exercício utiliza uma árvore binária para a realização do `sort`, assim, como a mesma não é balanceada seu pior caso é O(n²), fazendo com que O(2N) * O(N²) = O(2N * N²)
