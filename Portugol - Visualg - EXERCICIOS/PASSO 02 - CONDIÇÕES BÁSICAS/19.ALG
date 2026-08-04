Algoritmo "19"
// Autor(a)    : Samuel Souza
// Data atual  : 04/08/2026
// 19) Crie um algoritmo que leia o nome e as duas notas de um aluno, calcule a sua
// média e mostre na tela. No final, analise a média e mostre se o aluno teve ou
// não um bom aproveitamento (se ficou acima da média 7.0).

Var
 Nome: Caractere
 nota1, nota2, media: Real


Inicio
 Escreva("Nome do aluno: ")
 Leia(Nome)
 Escreva("Nota 1: ")
 Leia(nota1)
 Escreva("Nota 2: ")
 Leia(nota2)
 media <- (nota1 + nota2) / 2
 Escreval("Media: ", media)
 Se (media >= 7) entao
    Escreva("Bom aproveitamento")
 senao
    Escreva("Aproveitamento abaixo de 7")
 FimSe


Fimalgoritmo