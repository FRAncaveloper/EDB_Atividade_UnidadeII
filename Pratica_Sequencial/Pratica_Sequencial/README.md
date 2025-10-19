# TAD Sequência (Lista Encadeada)

Este projeto implementa o TAD Sequência usando uma lista simplesmente encadeada (`Node<std::string>`). A classe principal é `Sequence`, que fornece operações de inserção, remoção, acesso e consulta de quantidade.

## Estrutura de Dados

- `Node<T>`: nó da lista com dois campos:
  - `value`: armazena o valor do tipo `T`.
  - `next`: ponteiro para o próximo nó.
- `Sequence`:
  - `first`: ponteiro para o primeiro nó.
  - `quantity`: inteiro com a quantidade de elementos na sequência.

## Métodos da Classe Sequence

- `Sequence::Sequence()`
  - Inicializa a sequência vazia (`first = NULL`, `quantity = 0`).

- `Sequence::~Sequence()`
  - Percorre a lista e desaloca todos os nós.

- `std::string get(int i)`
  - Retorna o elemento na posição `i` (indexação 1).
  - Percorre da cabeça até o `i`-ésimo nó e retorna seu `value`.
  - Observação: não há validação robusta de índice; assume `1 <= i <= quantity`.

- `void insert(int i, std::string element)`
  - Insere `element` na posição `i` (indexação 1).
  - Casos tratados:
    - `i <= 1` → insere no início (`insertBegin`).
    - `i > quantity` → insere no fim (`insertEnd`).
    - Caso geral → insere entre nós mantendo a ordem.
  - Atualiza `quantity`.

- `void insertBegin(std::string element)`
  - Insere `element` no início da sequência.
  - Ajusta `first` e incrementa `quantity`.
  - Complexidade O(1).

- `void insertEnd(std::string element)`
  - Insere `element` no final da sequência.
  - Percorre até o último nó, conecta o novo nó e incrementa `quantity`.
  - Complexidade O(n).

- `std::string remove(int i)`
  - Remove e retorna o elemento na posição `i` (indexação 1).
  - Casos tratados:
    - Lista vazia → retorna `""`.
    - `i <= 1` → remove início (`removeBegin`).
    - Posição além do fim → remove o último (`removeEnd`).
    - Caso geral → desconecta o `i`-ésimo nó, retorna seu valor e decrementa `quantity`.

- `std::string removeBegin()`
  - Remove o primeiro elemento e retorna seu valor.
  - Ajusta `first` para o próximo nó e decrementa `quantity`.
  - Complexidade O(1).

- `std::string removeEnd()`
  - Remove o último elemento e retorna seu valor.
  - Lista vazia → retorna `""`.
  - Se houver apenas um nó → delega para `removeBegin()`.
  - Caso geral → percorre mantendo `prev/curr`, desconecta o último, decrementa `quantity`.
  - Complexidade O(n).

- `bool isEmpty()`
  - Retorna `true` se `quantity == 0`.

- `int getQuantity()`
  - Retorna a quantidade de elementos na sequência.

- `Node<std::string>* getFirst()`
  - Retorna o ponteiro para o primeiro nó (útil para depuração).

- `void print()`
  - Imprime todos os elementos em ordem separados por espaço.

## Métodos da Classe Node<T>

- Construtores:
  - `Node()` → inicializa `next = NULL`.
  - `Node(T val)` → inicializa `value = val`, `next = NULL`.
  - `Node(T val, Node* n)` → inicializa `value = val`, `next = n`.
- Acessores:
  - `T getValue()` / `void setValue(T val)`
  - `Node* getNext()` / `void setNext(Node* n)`

## Complexidade (Resumo)

- Acesso por índice (`get(i)`) → O(i)
- Inserção no início (`insertBegin`) → O(1)
- Inserção no fim (`insertEnd`) → O(n)
- Inserção por índice (`insert(i)`) → O(i)
- Remoção no início (`removeBegin`) → O(1)
- Remoção no fim (`removeEnd`) → O(n)
- Remoção por índice (`remove(i)`) → O(i)

## Exemplo de Uso

```cpp
#include "Sequence.h"
#include <iostream>

int main() {
    Sequence seq;
    seq.insertBegin("b");
    seq.insertEnd("c");
    seq.insert(1, "a"); // sequência: a, b, c

    std::cout << seq.get(2) << std::endl; // imprime "b"
    std::cout << seq.removeEnd() << std::endl; // imprime "c"
    std::cout << seq.getQuantity() << std::endl; // imprime 2
}
```

## Compilação e Execução (Windows)

- Pré-requisito: `g++` (MinGW/MSYS2) disponível no PATH.

Compilar:
```bash
g++ -std=c++17 -O2 -Wall .\ListSequence.cpp .\TestSequence.cpp -o .\SequenceTests.exe
```

Executar:
```bash
.\SequenceTests.exe
```

## Testes

- O arquivo `TestSequence.cpp` contém testes para:
  - `insertBegin`, `insertEnd`
  - `removeBegin`, `removeEnd`
  - `insert(i)`, `remove(i)`
  - Cenário geral (`testAll`)
- Saída esperada no terminal: