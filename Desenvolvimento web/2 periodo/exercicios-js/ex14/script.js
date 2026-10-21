let resultado = document.getElementById('res')

function sortear() {
    let num = Math.floor(Math.random() * 6)  

    switch(num) {
        case 0:
            resultado.textContent = `${num} = Zero`
            break
        case 1:
            resultado.textContent = `${num} = Um`
            break
        case 2:
            resultado.textContent = `${num} = Dois`
            break
        case 3:
            resultado.textContent = `${num} = Três`
            break
        case 4:
            resultado.textContent = `${num} = Quatro`
            break
        case 5:
            resultado.textContent = `${num} = Cinco`
            break
        default:
            resultado.textContent = `[ERRO] Nenhum valor sorteado`
            break
    }
}