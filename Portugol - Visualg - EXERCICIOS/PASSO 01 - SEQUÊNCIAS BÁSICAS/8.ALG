Algoritmo "8"
// Autor(a)    : Samuel Souza
// Data atual  : 14/05/2026
// 8) Desenvolva um programa que leia uma distância em metros e mostre os valores
// relativos em outras medidas.
// Ex:
// Digite uma distância em metros: 185.72
// A distância de 85.7m corresponde a:
// 0.18572Km
// 1.8572Hm
// 18.572Dam
// 1857.2dm
// 18572.0cm
// 185720.0mm

Var
   distancia: Real

Inicio
      Escreva("Digite uma distância em metros: ")
      Leia(distancia)
      Escreval(distancia / 1000," Km")
      Escreval(distancia / 100," Hm")
      Escreval(distancia / 10," Dam")
      Escreval(distancia * 10," dm")
      Escreval(distancia * 100," cm")
      Escreval(distancia * 1000," mm")


Fimalgoritmo