const n1Input = document.getElementById('n1')
const n2Input = document.getElementById('n2')


function calcular() {  
    const n1 = Number(n1Input.value) 
    const n2 = Number(n2Input.value) 

    alert(`A SOMA entre ${n1} + ${n2} = ${n1 + n2}`)
    alert(`A SUBTRAÇÃO entre ${n1} - ${n2} = ${n1 - n2}`)
    alert(`A MULTIPLICAÇÃO entre ${n1} x ${n2} = ${n1 * n2}`)
    
    if(n2 != 0){
        alert(`A DIVISÃO entre ${n1} / ${n2} = ${n1 / n2}`)
        alert(`O RESTO da divisão entre ${n1} e ${n2} = ${n1 % n2}`)
    }
    
}