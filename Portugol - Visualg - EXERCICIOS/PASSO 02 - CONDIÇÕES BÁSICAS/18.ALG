Algoritmo "18"
// Autor(a)    : Samuel Souza
// Data atual  : 23/05/2026
// 18) Faça um programa que leia o ano de nascimento de uma pessoa, calcule a idade
// dela e depois mostre se ela pode ou não votar.
Var
   ano_atual, ano_nasc, idade: Inteiro


Inicio
   Escreva("Ano atual: ")
   Leia(ano_atual)
   Escreva("Ano de nascimento: ")
   Leia(ano_nasc)
   idade <- ano_atual - ano_nasc
   Escreval("Sua idade é:", idade)

   Se(idade >= 18) entao
      Escreva("Você pode votar")
   Senao
      Escreva("Você NÃO pode votar")
   FimSe
   
Fimalgoritmo