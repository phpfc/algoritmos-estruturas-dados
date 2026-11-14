# Como definir um TAD?

Tipo: Página

**TAD (tipo abstrato de dados):** importância, e como definir TADs:

"**Na ciência da computação, um tipo abstrato de dados é um modelo matemático para tipos de dados, definido por seu comportamento do ponto de vista de um usuário dos dados, especificamente em termos de valores possíveis, operações possíveis em dados deste tipo e o comportamento destas operações**." ( <https://pt.wikipedia.org/wiki/Python>)

Na disciplina de Algoritmos e Estruturas de Dados nosso foco vai ser representação e manipulação de dados em memória principal. Vamos conhecer as estruturas básicas (listas e árvores) e suas possibilidades de implementação, e a partir delas fazer adequações e composições para representar diferentes problemas.

Trabalhamos em aula sobre a importância de, quando analisamos um problema que vai ter que ser implementado, entender bem quais são os dados e as operações sobre eles. O conhecimento sobre as operações que vão ser executadas vai permitir uma melhor escolha sobre a representação desses dados (escolha das estruturas), para que sejam adequadas às operações implementadas. Uma implementação que tem muitas operações de inserção e quase não tem deleções pode requerer uma implementação bem diferente de outra cujas operações praticamente não fazem inserções e tem ordenações constantes.

Assim, para refletir sobre dados e operações de um problema, trabalhamos com uma forma bastante abstrata de representar os dados e as operações de cada problema, chamada de Tipo Abstrato de Dados (ou TAD). TADs permitem representar Estruturas de Dados.

Não existe uma linguagem específica nem regras muito rígidas para descrever uma TAD, há diferentes variações, umas mais abstratas, outras mais próximas de implementação. Vamos utilizar uma **linguagem mais abstrata** (que não descreve tipos de dados), que inicia a definição pela palavra **TAD **seguida do nome do problema, por exemplo "TAD pessoa". 

Na parte "dados" do TAD, descrevemos os dados (pelo nome), por exemplo: 

**TAD pessoa {**

**Dados: nome,**

**nota,**

**telefone**

Na parte "operações" do TAD descrevemos cada operação pelo seu nome, por exemplo cadastrarpessoa. O nome de uma operação é seguido por abre e fecha parênteses ( cadastrarpessoa( ) ).

Se para uma operação houver dados a serem informados, dentro do parênteses eles são precedidos pela letra E:

cadastrarpessoa(E: nome, telefone) 

Se a operação vai retornar algum valor, eles são informados dentro do parênteses após a letra S:

buscartelefone(E:nome; S:telefone)

**TAD pessoa {**

**Dados: nome,**

**nota,**

**telefone**

**Operações:**

**cadastrarpessoa(E: nome, telefone)**

**buscartelefone(E:nome; S:telefone)**

**modificarnota(E: nome, nota)**

**}**

É possível definir composições de TADs, para melhorar a organização da apresentação das estruturas. Por exemplo, uma turma pode ser definida como uma lista ou conjunto de pessoas:

TAD turma {

Dados: lista de pessoas

Operações:

incluirpessoa(E: nome, telefone)

removerpessoa(E: nome)

atribuirnota(E: nome, nota) 

ordenarpornome(S: lista de pessoa)

ordenarpornota(S: lista de pessoa)

calcularmedia(S: media)

acimamedia(E: nota; S: lista de pessoa)

}

\- Exemplo de TAD para um banco (TAD banco, e TAD conta, TAD cliente e TAD movimentação)
