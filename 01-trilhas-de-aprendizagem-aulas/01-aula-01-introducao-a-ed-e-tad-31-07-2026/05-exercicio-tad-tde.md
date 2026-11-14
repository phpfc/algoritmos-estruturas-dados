# Exercício: TAD (TDE)

Tipo: Tarefa com entrega · Prazo: 07/08/2026 23:30

**1)** **Definir um TAD** para manter (inserir, remover) e consultar uma escola de cursos online (pense nos diferentes tipos de consulta). A escola tem um conjunto de títulos de cursos de curta e longa duração, e para cada curso há também um resumo, link (ou links) do vídeo das aulas, duração (em horas) e quantidade de módulos.

É possível fazer um TAD único ou dois (escola, e curso), caso sejam considerados cada curso em particular e a escola como um todo (conjunto de cursos).

2) **Fazer upload** das suas definições (descreva no editor online).

## Minhas entregas

### Tentativa 1

Enviada em 01/08/2026 15:34 · Nota: 10

**Resposta enviada:**

TAD curso {  

Dados: titulo,  
resumo,  
links,  
duracao,  
modulos  

Operações:  
criarCurso(E: titulo, resumo, duracao, modulos)  
excluirCurso(E: titulo)  

incluirLink(E: titulo, link)  
removerLink(E: titulo, link)  

alterarResumo(E: titulo, resumo)  
alterarDuracao(E: titulo, duracao)  
alterarModulos(E: titulo, modulos)  

buscarResumo(E: titulo; S: resumo)  
buscarLinks(E: titulo; S: lista de link)  
buscarDuracao(E: titulo; S: duracao)  
buscarModulos(E: titulo; S: modulos)  
contarLinks(E: titulo; S: quantidade)  

ehCurtaDuracao(E: titulo; S: resposta)  
cargaPorModulo(E: titulo; S: media)  
mostrarCurso(E: titulo; S: dados do curso)  
}  

TAD escola {  

Dados: nome,  
lista de cursos  

Operações:  
criarEscola(E: nome)  
incluirCurso(E: titulo, resumo, duracao, modulos)  
removerCurso(E: titulo)  
esvaziarEscola()  

existeCurso(E: titulo; S: resposta)  
buscarCurso(E: titulo; S: curso)  
contarCursos(S: quantidade)  
escolaVazia(S: resposta)  

listarCursos(S: lista de curso)  
listarCurtaDuracao(S: lista de curso)  
listarLongaDuracao(S: lista de curso)  
listarPorFaixaDuracao(E: duracaominima, duracaomaxima; S: lista de curso)  
listarPorModulosMinimos(E: modulos; S: lista de curso)  
buscarPorPalavraChave(E: palavra; S: lista de curso)  
listarComVideo(S: lista de curso)  
listarSemVideo(S: lista de curso)  

ordenarPorTitulo(S: lista de curso)  
ordenarPorDuracao(S: lista de curso)  
ordenarPorModulos(S: lista de curso)  

calcularCargaTotal(S: cargatotal)  
calcularDuracaoMedia(S: media)  
contarPorTipo(E: tipo; S: quantidade)  
cursoMaisLongo(S: curso)  
cursoMaiscurto(S: curso)  
contarTotalVideos(S: quantidade)  
acimaMedia(S: lista de curso)  
}
