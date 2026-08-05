Algoritmo "22"
// Autor(a)    : Samuel Souza
// Data atual  : 05/08/2026
// 22) Escreva um programa que leia o ano de nascimento de um rapaz e mostre a sua
//situação em relação ao alistamento militar.
// - Se estiver antes dos 18 anos, mostre em quantos anos faltam para o
//alistamento.
// - Se já tiver depois dos 18 anos, mostre quantos anos já se passaram do
//alistamento.

Var
   ano_nasc, ano_atual, idade, saldo, faltam: Inteiro


Inicio
 Escreva("Ano de nascimento: ")
 Leia(ano_nasc)
 Escreva("Ano atual: ")
 Leia(ano_atual)
 idade <- ano_atual - ano_nasc
 Escreval("Sua idade é: ", idade)
 Se (idade = 18) entao
    Escreva("Você deve se alistar imediatamente")
 senao
      Se (idade > 18) entao
         saldo <- idade - 18
         Escreva("Você deveria ter se alistado há ",saldo, " anos.")
      senao
           Se (idade < 18) entao
              faltam <- 18 - idade
              Escreva("Você ainda não completou 18 anos. Só daqui a", faltam," anos.")
           FimSe
      FimSe
 FimSe

Fimalgoritmo