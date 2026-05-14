Algoritmo "10"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 10) Faça um algoritmo que leia a largura e altura de uma parede, calcule e
// mostre a área a ser pintada e a quantidade de tinta necessária para o serviço,
// sabendo que cada litro de tinta pinta uma área de 2metros quadrados.

Var
   largura, altura, area, tinta: Real
   

Inicio
      Escreva("Largura: ")
      Leia(largura)
      Escreva("Altura: ")
      Leia(altura)
      area <- largura * altura
      Escreval("A área é: ",area)
      tinta <- area / 2
      Escreval("Você precisa de",tinta," litros de tinta para pintar essa área")


Fimalgoritmo