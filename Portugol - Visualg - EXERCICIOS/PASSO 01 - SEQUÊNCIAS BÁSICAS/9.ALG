Algoritmo "9"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 9) Faça um algoritmo que leia quanto dinheiro uma pessoa tem na carteira (em R$)
// e mostre quantos dólares ela pode comprar. Considere US$1,00 = R$3,45.

Var
   reais, dolar: Real
   

Inicio
      Escreva("Quanto têm na carteira? R$")
      Leia(reais)
      dolar <- 3.45
      Escreva("R$",reais," compra: $",reais / dolar)


Fimalgoritmo