/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_to_suap.h"

/*
macro processo

objetivo: criar um programa que receba um volume variável de números inteiros \
(positivos e/ou negativos) e os ordene utilizando as instruções definidas \
pelo projeto.

entrada: quantidade variável de inteiros (positivos ou negativos).
saida:
erro\n se receber números duplicados.
erro\n se receber entrada diferente de número inteiro.
erro\n se receber número superior/inferior ao INT_MAX e/ou INT_MIN.
relação de instruções utilizados para ordenar (em ordem crescente) os \
inteiros recebidos.

é permitido a utilização de duas pilhas (A e B) na classificação.
-> A pilha A é iniciada com o preenchimento de todos os números a serem \ 
ordenados, sendo o 1° número recebido o primeiro da pilha (inserção na cauda).
-> A pilha B inicia vazia e deve terminar vazia.
-> Ao encerrar o programa, a pilha A deve conter os números já ordenados \
(em órdem crescente).
-> A inicialização da pilha A utiliza o método de inserção na cauda.
-> Ao fazer um push de A para B, o 1º número de A entra na 1ª posição de \
B e o 2º número passa a ser o primeiro da pilha A (utiliza o método PEPS [ \
Primeiro a Entrar é o Primeiro a Sair] e a inserção na cabeça de B).
-> Ao fazer um push de B para A, o 1º número de B entra na 1ª posição de \
A e o 2º número passa a ser o primeiro da pilha B (utiliza o método UEPS [ \
Último a Entrar é o Primeiro a Sair] e a inserção na cabeça B).

-> Instruções permitidas:
--> pa (push a): retira o 1º número de B e coloca na 1ª posição de A. \
---> Em A, o elemento recebido será colocado na cabeça da estrutura \
(1ª posição), empurrando os demais elementos para as posições seguintes.  
---> Em B, o elemento retirado será o elemento da cabeça da estrutura \
(1ª posição), puxando os demais elementos uma posição para cima.  
===> FAÇA NADA se B estiver vazia!!!
--> pb (push b): sequencia inversa de pa.  
===> FAÇA NADA se A estiver vazia!!!

--> sa (swap a): troca a ordem dos dois primeiros números de A. 
===> FAÇA NADA se A estiver vazia ou possuir apenas 1 elemento!!!
--> sb (swap b): troca a ordem dos dois primeiros números de B. 
===> FAÇA NADA se B estiver vazia ou possuir apenas 1 elemento!!!

--> ss (swap a e swap b): sa e sb ao mesmo tempo. 

--> ra (gira a (rotate a)): desloque todos os números de A em uma posição.
O 1º número se torna o último, o 2º o primeiro, o 3º o segundo e etc.
===> FAÇA NADA se A estiver vazia ou possuir apenas 1 elemento!!!

--> rb (gira a (rotate b)): desloque todos os números de B em uma posição.
O 1º número se torna o último, o 2º o primeiro, o 3º o segundo e etc.
===> FAÇA NADA se B estiver vazia ou possuir apenas 1 elemento!!!

--> rr (rotate a e rotate b): ra e rb ao mesmo tempo.

--> rra (reverso de gira a (rotate a reverso)): desloque todos os números \
de A em uma posição.
O último número se torna o 1º, o 2º o 3º, o penúltimo o último.
===> FAÇA NADA se A estiver vazia ou possuir apenas 1 elemento!!!

--> rrb (reverso de gira b (rotate a reverso)): desloque todos os números \
de B em uma posição.
O último número se torna o 1º, o 2º o 3º, o penúltimo o último.
===> FAÇA NADA se B estiver vazia ou possuir apenas 1 elemento!!!

--> rrr (rotate a e rotate b): rra e rrb ao mesmo tempo.

dicas: utilizar estruturas e listas encadeadas.
dicas: estudar algorítimos de ordenação.

-> Eficiência necessária do push_swap:
--> 003 valores, não mais que 03 ações. 
--> 005 valores, não mais que 12 ações. 
--> 100 valores, classificado de 1 a 5 pontos?
---> 5 pontos para até    700 ações;
---> 4 pontos para até    900 ações;
---> 3 pontos para até  1.100 ações;
---> 2 pontos para até  1.300 ações;
---> 1 pontos para até  1.500 ações;
--> 500 valores, classificado de 1 a 5 pontos?
---> 5 pontos para até  5.500 ações;
---> 4 pontos para até  7.000 ações;
---> 3 pontos para até  8.500 ações;
---> 2 pontos para até 10.000 ações;
---> 1 pontos para até 11.500 ações;

-> Para avançar de projeto, necessária nota igual ou superior a 80%.

carregar os parâmetros passados em uma lista encadeada pela cauda.

passos:
-> validar se recebemos mais de 1 parâmetro argc > 1. OK
--> caso negativo, sair do programa (NADA deve ser impresso no terminal).
--> caso positivo, seguir com o processo de validação.

-> Popular a lista
--> Criar uma lista para inserir os valores
--> Criar um loop para percorrer o argv.
---> Dentro do loop.
----> Verificar se o parâmetro possui caracter diferente de dígito, +/- ou espaço.
-----> Se passar por esta validação do caracter: Converter o parâmetro para long;
------> Verificar se o parâmetro é int.
-------> Se passar pela validação de int: criar o nó e inseri-lo na lista. Enquanto \
percorre acumule um contador para guardar o tamanho do array
-------> Se não passar pela validação de int: destruir os nós já criados, destruir a \
lista, escrever "erro"\n na tela e encerrar o programa.
-----> Se não passar por esta validação do caracter: destruir os nós já criados, destruir a lista, escrever "erro" na tela e encerrar o programa.

 
-> validar a entrada de dados (duplicidde e se a entrada já está ordenada): OK
--> realize uma cópia do array long long int;
--> crie uma flag para verificar se a entrada já está ordenada e \
inicialize-a com ZERO (exemplo).
--> na cópia, realize um swap simples para ordenar os números, mas \
se for necessário realizar alguma troca de posição, altere o valor da flag \
que valida se a entrada já estava ordenada para UM (exemplo).
--> após a ordenação, (ou durante o processo) verifique se algum número \
se repere:
---> Se for identificado alguma duplicidade:
----> libere os mallocs realizados;
----> escreva erro\n na tela; e
----> encerre o programa.
---> Se não for identificada duplicidade:
----> verifique o valor da flag é ZERO (já entrada já ordenada):
------> libere todos os mallocs;
------> encerre o programa.
----> libere o malloc da cópia;
----> popule a estrutura castando os números long long int para int.

-> algorítimo de ordenação
O algorítimo dependerá da quantidade de itens a serem ordenados.
--> Para 1 item:
OBS: Não deve chegar neste ponto, pois não haveria duplicidade e o programa \
terminaria antes de chegar aqui.
--> Para 2 itens:
---> Será necessário apenas UM sa.
--> Para 3 itens, temos 5 combinações diferentes (3 x 2 x 1, menos 1 já ordenada):
 1 2 3 => nada a fazer.
 1 3 2 -> rra -> 2 1 3 -> sa -> 1 2 3
 2 1 3 -> sa  -> 1 2 3
 2 3 1 -> rra -> 1 2 3 
 3 1 2 -> ra  -> 1 2 3
 3 2 1 -> ra  -> 2 1 3 -> sa -> 1 2 3

OBS: crie uma função para verificar se a estrutura está ordenada;


ARG=$(shuf -i 1-30 -n 10 | tr '\n' ' ') && ./push_swap $ARG


*/
