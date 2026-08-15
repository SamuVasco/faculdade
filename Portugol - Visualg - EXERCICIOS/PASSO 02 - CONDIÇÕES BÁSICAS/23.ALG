Algoritmo "23"
// Autor(a)    : Samuel
// Data atual  : 15/08/2026
// 23) Numa promoção exclusiva para o Dia da Mulher, uma loja quer dar descontos
// para todos, mas especialmente para mulheres. Faça um programa que leia nome,
// sexo e o valor das compras do cliente e calcule o preço com desconto. Sabendo
// que:
// - Homens ganham 5% de desconto
// - Mulheres ganham 13% de desconto
Var
   nome, sexo: Caractere
   valor, desconto: Real

Inicio
      Escreva("Nome: ")
      Leia(nome)
      Escreva("Sexo [m/f]: ")
      Leia(sexo)
      Escreva("Valor total das compras: R$ ")
      Leia(valor)
      
      Se (sexo = "m") entao
         desconto <- valor - (valor * 5 / 100)
      senao
         desconto <- valor - (valor * 15 / 100)
      FimSe
      
      Escreva("Total: R$", desconto)

Fimalgoritmo