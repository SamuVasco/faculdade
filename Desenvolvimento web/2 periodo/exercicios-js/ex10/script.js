const resultado = document.getElementById('resultado')

const usuario = prompt('Digite um número INTEIRO de 1 a 5: ')

const n = Math.floor(Math.random() * 5) + 1

if(usuario == n){
    resultado.textContent = `Parabéns, você acertou!`
}else{
    resultado.textContent = `Você errou, o número sorteado foi ${n}!`
}