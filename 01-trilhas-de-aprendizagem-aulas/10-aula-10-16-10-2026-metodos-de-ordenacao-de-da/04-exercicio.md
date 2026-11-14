# Exercício

Tipo: Página

Os métodos de ordenação simples, como ** _bubblesort_** , **inserção direta** e **seleção direta** , são adequados para quantidade não muito grande de elementos. São métodos cujo funcionamento é fácil de lembrar, e sua implementação pode ser desenvolvida rapidamente.

As implementações desses métodos são geralmente realizadas considerando dados armazenados em vetores (arrays), pela sua rapidez de execução. Mas, como são métodos que trabalham com base na comparação/troca de elementos adjacentes (um ao lado do outro), é possível implementá-los utilizando listas encadeadas.

**1) Implemente um dos métodos de ordenação simples** (a sua escolha) **utilizando listas encadeadas** (simples ou dupla, o que for mais adequado ou necessário).

2) Implemente o mesmo método de ordenação simples, mas com a implementação clássica usando vetores.

3) Faça execuções de ordenação de dados para comparar as execuções dos dois métodos implementados:

  * os métodos vão ordenar os dados em ordem crescente de valores;
  * coloque contadores para o número de comparações e para o número de trocas realizadas, em cada método implementado;
  * execute cada método implementado para ordenar um conjunto de 1000 números, **em ordem aleatória** (use a função rand( ) ou similar para gerar os números aleatórios - use o mesmo conjunto de números para as duas execuções). Exiba os contadores de trocas e de comparações;
  * execute cada método implementado para ordenar um conjunto de 1000 números, **em ordem decrescente de valores** (use a função rand( ) ou similar para gerar os números aleatórios - use o mesmo conjunto de números para as duas execuções). Exiba os contadores de trocas e de comparações.
