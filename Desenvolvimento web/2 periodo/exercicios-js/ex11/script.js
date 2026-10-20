function ordenar() {
    let v1 = document.getElementById('v1')
    let v2 = document.getElementById('v2')
    
    let valor1 = Number(v1.value)
    let valor2 = Number(v2.value)
    let temp

    if(valor2 < valor1){
        temp = valor1
        v1.value = valor2
        v2.value = temp
    }
}