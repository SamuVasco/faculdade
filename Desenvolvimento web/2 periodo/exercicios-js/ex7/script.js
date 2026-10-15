const res = document.getElementById('res')
const r = Number(prompt('Raio em mm: '))
const a = Number(prompt('Altura em mm: '))

const raio = r / 10
const altura = a / 10

const volume = 3.1415 * Math.pow(raio, 2)  * altura

res.innerHTML = `${volume.toFixed(3)}cm³`