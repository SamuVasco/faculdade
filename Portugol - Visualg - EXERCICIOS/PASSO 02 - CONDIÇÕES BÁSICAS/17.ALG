Algoritmo "17"
// Autor(a)    : Samuel Souza
// Data atual  : 23/05/2026
// 17) Escreva um programa que pergunte a velocidade de um carro. Caso ultrapasse
// 80Km/h, exiba uma mensagem dizendo que o usuário foi multado. Nesse caso, exiba
// o valor da multa, cobrando R$5 por cada Km acima da velocidade permitida
Var
   velocidade: Inteiro
   multa: Real


Inicio
   Escreva("Velocidade (Km): ")
   Leia(velocidade)

   Se(velocidade > 80) entao
      Escreval("MULTADO! Ultrapassou o limite de 80km/h")
      multa <-  (velocidade - 80) * 5
      Escreva("Sua multa é de: R$", multa)
   FimSe

Fimalgoritmo