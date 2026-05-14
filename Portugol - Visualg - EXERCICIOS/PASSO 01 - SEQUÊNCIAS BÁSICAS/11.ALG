Algoritmo "11"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 11) Desenvolva uma lógica que leia os valores de A, B e C de uma equação do
// segundo grau e mostre o valor de Delta.

Var
   A , B , C: inteiro
   delta: real
   

Inicio
      Escreva("A: ")
      Leia(A)
      Escreva("B: ")
      Leia(B)
      Escreva("C: ")
      Leia(C)
      delta <- (B ^ 2) - 4 * A * C
      Escreva("Delta vale: ", delta)


Fimalgoritmo