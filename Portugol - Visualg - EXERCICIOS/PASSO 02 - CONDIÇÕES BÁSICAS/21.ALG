Algoritmo "21"
// Autor(a)    : Samuel Souza
// Data atual  : 04/08/2026
// 21) Faça um algoritmo que leia um determinado ano e mostre se ele é ou não
// BISSEXTO

Var
   ano: Inteiro


Inicio
 Escreva("Ano: ")
 Leia(ano)
 Se (ano % 4 = 0) E (ano % 100 > 0) OU (ano % 400 = 0) entao
    Escreva("ano BISSEXTO")
 senao
    Escreva("NÃO BISSEXTO")
 FimSe


Fimalgoritmo