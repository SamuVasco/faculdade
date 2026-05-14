Algoritmo "14"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 14) A locadora de carros precisa da sua ajuda para cobrar seus serviços. Escreva
// um programa que pergunte a quantidade de Km percorridos por um carro alugado e a
// quantidade de dias pelos quais ele foi alugado. Calcule o preço total a pagar,
// sabendo que o carro custa R$90 por dia e R$0,20 por Km rodado.

Var
   km, total: real
   dias: inteiro
   

Inicio
      Escreva("Quantidade de KMs percorridos: ")
      Leia(km)
      Escreva("Quantos dias alugados: ")
      Leia(dias)
      total <- (km * 0.2) + (dias * 90)
      Escreva("O total a pagar é: R$ ", total)
      


Fimalgoritmo