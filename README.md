# Informações Gerais
Este projeto integra o terceiro ciclo de projetos da [42Rio](https://42.rio/). Nele, somos desafiados a cria um algoritmo de ordenação de números utilizando a **linguagem C**. Parte do desafio inclui uma restrição adicional no que tange a restrição de movimentos possíveis, pois apenas nos são permitidos a movimentar o primeiro número entre duas estruturas (A e B). As instruções gerais deste projeto encontram-se no [en.subject.pdf](./en.subject.pdf) disponibilizado.

Este projeto tem semelhança com a [Torre de Hanoi](https://pt.wikipedia.org/wiki/Torre_de_Han%C3%B3i), porém, com a restrição adicional de possuir apenas duas torres para movimento.

Para alcançar o objetivo deste projeto, foi necessária a separação do código nos seguintes grupos de responsabilidades:

<ul>
    <li>
        Validar os parâmetros de entrada.
    </li>
    <li>
        Selecionar qual algoritmo deve ser usado baseado na quantidade de números inserido para ordenação.
    </li>
    <li>
        Ordenar a relação de números inseridos no programa.
    </li>
    <li>
        Retornar os movimentos necessários para ordenação dos números ou retornar mensagem de erro no terminal.
    </li>
    <li>
        Liberar a memória utilizada durante a execução do programa. 
    </li>
</ul>

Para realização deste projeto utilizei diferentes algoritmos de ordenação segundo as seguintes estratégias.
<ul>
    <li>
        Algoritmo de ordenação utilizando força bruta para ordenar até 5 números.
    </li>
    <li>
        Algoritmo de ordenação utilizando merger sort para ordenar até 100 números.
    </li>
    <li>
        Algoritmo de ordenação utilizando radix para ordenar qualquer quantidade acima de 100 números.
    </li>
    <li>
        Algoritmo de ordenação bubble sort para rotinas de suporte.
    </li>
</ul>
</br>


# Conhecimentos desenvolvidos durante este projeto
<ul>
    <li>
        Lógica de programação.
    </li>
    <li>
        Linguagem C.
    </li>
    <li>
        Algoritmos de ordenação.
    </li>
</ul>

# Como clonar o repositório...
Utilize um sistema operacional baseado no Unix (Linux ou MacOs), clone o [projeto](https://github.com/wyllbrayner/42Rio-push_swap) do **github**.
</br>
</br>

# Como compilar...
### Como compilar a push_swap.
Após clonar o repositório do [projeto](https://github.com/wyllbrayner/42Rio-push_swap), entre na pasta do projeto e realize o comando **make** no terminal.
Após a mensagem de sucesso aparecer no terminal, um novo arquivo, de nome push_swap, estará disponível no repositório.
</br>
</br>

# Como utilizar...
### A push_swap.
Coloque ./push_swap [relacao_de_numeros_a_serem_ordenados] no terminal.
ou
Coloque export ARG=$(shuf -i 0-10 -n5) no terminal para que o shuf gere 5 números aleatórios entre 0 e 10 (exemplo) e crie uma variável de ambiente de nome ARG contendo estes números. Após, coloque ./push_swap $ARG 

### O Tester disponibilizado pela 42.
Para verificar se o programa apresentado está realizando a ordenação correta, a 42 disponibiliza dois testes (um para o ambiente linux e outro para o Mac) que também disponibilizei na pasta 42tester neste repositório.
Coloque ./push_swap [relacao_de_numeros_a_serem_ordenados] | ./checker_linux [relacao_de_numeros_a_serem_ordenados] no terminal. Caso o programa apresente a relação correta de comandos para ordenas os números, o checker apresentará OK no terminal ou KO em caso contrário.
</br>
</br>
