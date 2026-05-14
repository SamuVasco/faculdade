Algoritmo "13"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 13) Faça um algoritmo que leia o salário de um funcionário, calcule e mostre o
// seu novo salário, com 15% de aumento.


Var
   salario, aumento: real
   

Inicio
      Escreva("Salário: R$")
      Leia(salario)
      aumento <- salario + (salario * 15 / 100)
      Escreva("Com 15% de aumento fica: R$", aumento)


Fimalgoritmo