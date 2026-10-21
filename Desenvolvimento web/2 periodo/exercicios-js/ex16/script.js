let res = document.getElementById('res')
let exec = 1
let resp

do {
    resp = confirm(`Execução ${exec}`)

    if (resp){
        exec++
    }
}while(resp)

res.textContent = `${exec}`