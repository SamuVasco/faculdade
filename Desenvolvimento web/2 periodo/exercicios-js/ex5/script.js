const v1Input = document.getElementById('v1')
const v2Input = document.getElementById('v2')

function trocar() {
    const temp = v1Input.value

    v1Input.value = v2Input.value 

    v2Input.value = temp
}