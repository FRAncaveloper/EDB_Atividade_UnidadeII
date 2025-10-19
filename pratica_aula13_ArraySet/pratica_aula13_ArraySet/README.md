# TAD Conjunto (ArraySet) — Relatório Simplificado

Repositório: https://github.com/FRAncaveloper/EDB_Atividade_UnidadeII

## 1. Descrição dos Métodos Implementados
- `add(std::string)`: insere elemento se não existir; expande capacidade quando enche. Busca duplicata via `contains`. Complexidade: O(n) pela busca.
- `remove(std::string)`: remove o elemento, substituindo pela última posição para remoção O(1) após localizar. Complexidade: O(n) para localizar, remoção O(1).
- `contains(std::string)`: busca linear por igualdade. Complexidade: O(n).
- `size()`: retorna a quantidade de elementos. Complexidade: O(1).
- `isEmpty()`: verifica se o conjunto está vazio. Complexidade: O(1).
- `clear()`: limpa o conjunto (zera contadores). Complexidade: O(1).
- Estrutura: array dinâmico de `std::string` com crescimento por duplicação. Capacidade inicial `CAPACITY_DEFAULT = 17`.

## 2. Como Compilar e Executar (Windows)
Executar na raiz do repositório: