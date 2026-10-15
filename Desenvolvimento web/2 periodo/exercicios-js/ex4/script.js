const n1Input = document.getElementById('n1')
const n2Input = document.getElementById('n2')
const resInput = document.getElementById('res')

function somar() {
    const n1 = Number(n1Input.value)
    const n2 = Number(n2Input.value)

    const soma = n1 + n2

    resInput.value = soma
    
}