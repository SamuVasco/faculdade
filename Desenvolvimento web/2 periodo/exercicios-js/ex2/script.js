const nomeInput = document.getElementById('nome')
const sobrenomeInput = document.getElementById('sobrenome')

function mostrar() {
    const nome = nomeInput.value 
    const sobrenome = sobrenomeInput.value

    alert(`Olá ${nome} ${sobrenome}, seja bem vindo!`)
}