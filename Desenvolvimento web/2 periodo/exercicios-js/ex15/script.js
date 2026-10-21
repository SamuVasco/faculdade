let res = document.getElementById('res')
let user = Number(prompt('Digite um número: '))

let soma = 0

for (let i = 1; i <= user ; i++){
    soma += i
}

res.textContent = `A soma de todos os números INTEIROS entre 1 e ${user} é igual a ${soma}`