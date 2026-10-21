let msg = document.getElementById('msg')

let nome = prompt('Digite o seu nome: ').toLowerCase()
let sexo = prompt('Digite o seu sexo [m / f]: ').toLowerCase()

if (sexo == 'm') {
    msg.textContent = `Seja bem vindo, ${nome}`
}else if (sexo == 'f') {
    msg.textContent = `Seja bem vinda, ${nome}`
}else {
    msg.textContent = `Seja bem vindo(a), ${nome}`
}