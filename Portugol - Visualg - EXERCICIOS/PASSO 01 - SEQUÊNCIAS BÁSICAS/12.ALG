Algoritmo "12"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 12) Crie um programa que leia o preço de um produto, calcule e mostre o seu
// PREÇO PROMOCIONAL, com 5% de desconto.


Var
   preco, desconto: Real
   

Inicio
      Escreva("Preço do produto: R$")
      Leia(preco)
      desconto <- preco - (preco * 5 / 100)
      Escreva("Com 5% de desconto fica: ", desconto)


Fimalgoritmo