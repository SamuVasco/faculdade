const resultado = document.getElementById("resultado");


function sortear() {
    const numero = Math.floor(Math.random() * 6) + 1 

    resultado.textContent = numero
}